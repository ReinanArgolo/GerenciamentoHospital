#include "especialidades.h"
#include <string.h>
#include <stdio.h>

void inicializarCadastroEspecialidade(CadastroEspecialidade* cadastro, const char* nomeArquivo) {
    cadastro->quantidade = 0;
    strncpy(cadastro->arquivo, nomeArquivo, 99);
    cadastro->arquivo[99] = '\0';
}

int carregarEspecialidades(CadastroEspecialidade* cadastro) {
    FILE* arquivo = fopen(cadastro->arquivo, "r");
    if (arquivo == NULL) {
        return 0; // Arquivo não existe, não é um erro
    }
    
    cadastro->quantidade = 0;
    char linha[256];
    
    // Ler linha por linha
    while (fgets(linha, sizeof(linha), arquivo) && cadastro->quantidade < MAX_ESPECIALIDADES) {
        int codigo;
        char nome[MAX_NOME];
        
        // Formato CSV: codigo,nome
        if (sscanf(linha, "%d,%99[^\n]", &codigo, nome) == 2) {
            cadastro->lista[cadastro->quantidade].codigo = codigo;
            strncpy(cadastro->lista[cadastro->quantidade].nome, nome, MAX_NOME - 1);
            cadastro->lista[cadastro->quantidade].nome[MAX_NOME - 1] = '\0';
            cadastro->quantidade++;
        }
    }
    
    fclose(arquivo);
    return 1;
}

int salvarEspecialidades(CadastroEspecialidade* cadastro) {
    FILE* arquivo = fopen(cadastro->arquivo, "w");
    if (arquivo == NULL) {
        return 0;
    }
    
    // Escrever cada especialidade em formato CSV
    for (int i = 0; i < cadastro->quantidade; i++) {
        fprintf(arquivo, "%d,%s\n", 
                cadastro->lista[i].codigo, 
                cadastro->lista[i].nome);
    }
    
    fclose(arquivo);
    return 1;
}

int existeEspecialidade(CadastroEspecialidade* cadastro, int codigo) {
    for (int i = 0; i < cadastro->quantidade; i++) {
        if (cadastro->lista[i].codigo == codigo) {
            return 1;
        }
    }
    return 0;
}

Especialidade* buscarEspecialidade(CadastroEspecialidade* cadastro, int codigo) {
    for (int i = 0; i < cadastro->quantidade; i++) {
        if (cadastro->lista[i].codigo == codigo) {
            return &cadastro->lista[i];
        }
    }
    return NULL;
}

// Função atualizada para gerar código automaticamente
int cadastrarEspecialidade(CadastroEspecialidade* cadastro, const char* nome) {
    // Verificar se atingiu o limite
    if (cadastro->quantidade >= MAX_ESPECIALIDADES) {
        return 0; // Limite atingido
    }
    
    // Gerar código automaticamente (próximo código será quantidade + 1)
    int codigo = cadastro->quantidade + 1;
    
    // Garantir que o código é único (caso haja exclusões, buracos, etc.)
    while (existeEspecialidade(cadastro, codigo)) {
        codigo++;
        if (codigo > MAX_ESPECIALIDADES) {
            return 0; // Não há códigos disponíveis
        }
    }
    
    cadastro->lista[cadastro->quantidade].codigo = codigo;
    strncpy(cadastro->lista[cadastro->quantidade].nome, nome, MAX_NOME - 1);
    cadastro->lista[cadastro->quantidade].nome[MAX_NOME - 1] = '\0';
    
    cadastro->quantidade++;
    
    // Salvar após cada cadastro
    return salvarEspecialidades(cadastro);
}

// Função atualizada para pré-cadastrar especialidades comuns
void cadastrarEspecialidadesPadrao(CadastroEspecialidade* cadastro) {
    cadastrarEspecialidade(cadastro, "Clínico Geral");
    cadastrarEspecialidade(cadastro, "Cardiologia");
    cadastrarEspecialidade(cadastro, "Dermatologia");
    cadastrarEspecialidade(cadastro, "Ortopedia");
    cadastrarEspecialidade(cadastro, "Pediatria");
    cadastrarEspecialidade(cadastro, "Oftalmologia");
}

// Função não interativa para listar especialidades (usada por outros módulos)
void listarEspecialidades(CadastroEspecialidade* cadastro) {
    if (cadastro->quantidade == 0) {
        printf("Nenhuma especialidade cadastrada.\n");
    } else {
        for (int i = 0; i < cadastro->quantidade; i++) {
            printf("Código: %d - %s\n", cadastro->lista[i].codigo, cadastro->lista[i].nome);
        }
    }
}