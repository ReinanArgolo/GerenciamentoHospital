#include "especialidades.h"
#include <string.h>

void inicializarCadastroEspecialidade(CadastroEspecialidade* cadastro, const char* nomeArquivo) {
    cadastro->quantidade = 0;
    strncpy(cadastro->arquivo, nomeArquivo, 99);
    cadastro->arquivo[99] = '\0';
}

int carregarEspecialidades(CadastroEspecialidade* cadastro) {
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
        lidos = fread(cadastro->lista, sizeof(Especialidade), cadastro->quantidade, arquivo);
        if (lidos != cadastro->quantidade) {
            fclose(arquivo);
            return 0;
        }
    }
    
    fclose(arquivo);
    return 1;
}

int salvarEspecialidades(CadastroEspecialidade* cadastro) {
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
        escritos = fwrite(cadastro->lista, sizeof(Especialidade), cadastro->quantidade, arquivo);
        if (escritos != cadastro->quantidade) {
            fclose(arquivo);
            return 0;
        }
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

// Função para gerenciar o cadastro de especialidades (atualizada)
void menuEspecialidades() {
    CadastroEspecialidade cadastro;
    inicializarCadastroEspecialidade(&cadastro, "especialidades.dat");
    carregarEspecialidades(&cadastro);
    
    int opcao, codigo;
    char nome[MAX_NOME];
    
    do {
        printf("\n=== CADASTRO DE ESPECIALIDADES ===\n");
        printf("1 - Cadastrar nova especialidade\n");
        printf("2 - Listar especialidades\n");
        printf("3 - Buscar especialidade\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer
        
        switch(opcao) {
            case 1:
                printf("\nCadastro de nova especialidade\n");
                printf("Nome da especialidade: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = 0; // Remover quebra de linha
                
                if (cadastrarEspecialidade(&cadastro, nome)) {
                    printf("Especialidade cadastrada com sucesso!\n");
                    printf("Código gerado: %d\n", cadastro.quantidade); // Mostra o código gerado
                } else {
                    printf("Erro ao cadastrar especialidade!\n");
                }
                break;
                
            case 2:
                printf("\n=== ESPECIALIDADES CADASTRADAS ===\n");
                if (cadastro.quantidade == 0) {
                    printf("Nenhuma especialidade cadastrada.\n");
                } else {
                    for (int i = 0; i < cadastro.quantidade; i++) {
                        printf("Código: %d - %s\n", cadastro.lista[i].codigo, cadastro.lista[i].nome);
                    }
                }
                break;
                
            case 3:
                printf("\nBuscar especialidade\n");
                printf("Informe o código: ");
                scanf("%d", &codigo);
                
                Especialidade* esp = buscarEspecialidade(&cadastro, codigo);
                if (esp != NULL) {
                    printf("Especialidade encontrada: %d - %s\n", esp->codigo, esp->nome);
                } else {
                    printf("Especialidade não encontrada!\n");
                }
                break;
                
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

// Função atualizada para pré-cadastrar especialidades comuns
void cadastrarEspecialidadesPadrao(CadastroEspecialidade* cadastro) {
    cadastrarEspecialidade(cadastro, "Clínico Geral");
    cadastrarEspecialidade(cadastro, "Cardiologia");
    cadastrarEspecialidade(cadastro, "Ortopedia");
    cadastrarEspecialidade(cadastro, "Pediatria");
    cadastrarEspecialidade(cadastro, "Ginecologia");
    cadastrarEspecialidade(cadastro, "Dermatologia");
    cadastrarEspecialidade(cadastro, "Neurologia");
    cadastrarEspecialidade(cadastro, "Psiquiatria");
    cadastrarEspecialidade(cadastro, "Oftalmologia");
    cadastrarEspecialidade(cadastro, "Otorrinolaringologia");
}