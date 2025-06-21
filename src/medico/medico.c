#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medico.h"
#include "../especialidades/especialidades.h"

void inicializarCadastroMedico(CadastroMedico* cadastro, const char* nomeArquivo) {
    cadastro->quantidade = 0;
    strncpy(cadastro->arquivo, nomeArquivo, 99);
    cadastro->arquivo[99] = '\0';
}

int carregarMedicos(CadastroMedico* cadastro) {
    FILE* arquivo = fopen(cadastro->arquivo, "rb");
    if (arquivo == NULL) {
        return 0; // Arquivo não existe, não é um erro
    }
    
    size_t lidos = fread(&cadastro->quantidade, sizeof(int), 1, arquivo);
    if (lidos != 1) {
        fclose(arquivo);
        return 0;
    }
    
    if (cadastro->quantidade > 0) {
        lidos = fread(cadastro->lista, sizeof(Medico), cadastro->quantidade, arquivo);
        if (lidos != cadastro->quantidade) {
            fclose(arquivo);
            return 0;
        }
    }
    
    fclose(arquivo);
    return 1;
}

int salvarMedicos(CadastroMedico* cadastro) {
    FILE* arquivo = fopen(cadastro->arquivo, "wb");
    if (arquivo == NULL) {
        return 0;
    }
    
    size_t escritos = fwrite(&cadastro->quantidade, sizeof(int), 1, arquivo);
    if (escritos != 1) {
        fclose(arquivo);
        return 0;
    }
    
    if (cadastro->quantidade > 0) {
        escritos = fwrite(cadastro->lista, sizeof(Medico), cadastro->quantidade, arquivo);
        if (escritos != cadastro->quantidade) {
            fclose(arquivo);
            return 0;
        }
    }
    
    fclose(arquivo);
    return 1;
}

int existeMedico(CadastroMedico* cadastro, int id) {
    for (int i = 0; i < cadastro->quantidade; i++) {
        if (cadastro->lista[i].id == id) {
            return 1;
        }
    }
    return 0;
}

Medico* buscarMedicoPorId(CadastroMedico* cadastro, int id) {
    for (int i = 0; i < cadastro->quantidade; i++) {
        if (cadastro->lista[i].id == id) {
            return &cadastro->lista[i];
        }
    }
    return NULL;
}

int cadastrarMedico(CadastroMedico* cadastro, CadastroEspecialidade* cadastroEsp) {
    // Verificar se atingiu o limite
    if (cadastro->quantidade >= MAX_MEDICOS) {
        printf("Limite de médicos atingido!\n");
        return 0;
    }
    
    // Alocar novo médico
    Medico* novoMedico = &cadastro->lista[cadastro->quantidade];
    
    printf("\n=== Cadastro de Médico ===\n");
    
    // Gerar ID sequencial
    int id = cadastro->quantidade + 1;
    // Garantir que o ID é único
    while (existeMedico(cadastro, id)) {
        id++;
    }
    novoMedico->id = id;
    
    printf("Nome: ");
    scanf(" %[^\n]", novoMedico->nome);
    
    printf("CRM: ");
    scanf("%d", &novoMedico->crm);
    getchar(); // Limpar buffer
    
    // Mostrar especialidades disponíveis
    printf("\nEspecialidades disponíveis:\n");
    listarEspecialidades(cadastroEsp);
    
    printf("\nEspecialidade (código): ");
    scanf("%d", &novoMedico->especialidade);
    getchar(); // Limpar buffer
    
    // Verificar se a especialidade existe
    if (buscarEspecialidade(cadastroEsp, novoMedico->especialidade) == NULL) {
        printf("Especialidade não encontrada! Cadastro cancelado.\n");
        return 0;
    }
    
    cadastro->quantidade++;
    
    // Salvar após cada cadastro
    int resultado = salvarMedicos(cadastro);
    if (resultado) {
        printf("\nMédico cadastrado com sucesso!\n");
    } else {
        printf("\nErro ao salvar o cadastro do médico!\n");
    }
    
    return resultado;
}

void listarMedicos(CadastroMedico* cadastro, CadastroEspecialidade* cadastroEsp) {
    printf("\n=== MÉDICOS CADASTRADOS ===\n");
    
    if (cadastro->quantidade == 0) {
        printf("Nenhum médico cadastrado.\n");
        return;
    }
    
    for (int i = 0; i < cadastro->quantidade; i++) {
        Medico* m = &cadastro->lista[i];
        printf("ID: %d\n", m->id);
        printf("Nome: %s\n", m->nome);
        printf("CRM: %d\n", m->crm);
        
        // Buscar e exibir o nome da especialidade ao invés do código
        Especialidade* esp = buscarEspecialidade(cadastroEsp, m->especialidade);
        if (esp != NULL) {
            printf("Especialidade: %s (Código: %d)\n", esp->nome, esp->codigo);
        } else {
            printf("Especialidade: %d (Não encontrada)\n", m->especialidade);
        }
        
        printf("--------------------------\n");
    }
}


