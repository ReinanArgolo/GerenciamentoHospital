#include <stdio.h>
#include <stdlib.h>
#include "src/paciente/paciente.h"
#include "src/medico/medico.h"
#include "src/especialidades/especialidades.h"

// Função para exibir o menu principal
void exibirMenuPrincipal() {
    printf("\n===== SISTEMA DE GERENCIAMENTO HOSPITALAR =====\n");
    printf("1. Gerenciar Especialidades\n");
    printf("2. Cadastrar Médico\n");
    printf("3. Cadastrar Paciente\n");
    printf("4. Consultar Paciente (exemplo)\n");
    printf("5. Listar Médicos\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

// Função simplificada para cadastrar paciente
void cadastrarPaciente() {
    Paciente novoPaciente;
    int id;
    char nome[100];
    int idade;
    char condicao[200];
    
    printf("\n=== Cadastro de Paciente ===\n");
    
    printf("ID: ");
    scanf("%d", &id);
    getchar(); // Limpar buffer
    
    printf("Nome: ");
    scanf(" %[^\n]", nome);
    
    printf("Idade: ");
    scanf("%d", &idade);
    getchar(); // Limpar buffer
    
    printf("Condição Médica: ");
    scanf(" %[^\n]", condicao);
    
    inicializarPaciente(&novoPaciente, id, nome, idade, condicao);
    
    printf("\nPaciente cadastrado com sucesso!\n");
    printf("\nDados do paciente cadastrado:\n");
    exibirPaciente(&novoPaciente);
}

// Função para demonstração com um paciente de exemplo
void exibirExemploPaciente() {
    Paciente paciente1;
    
    inicializarPaciente(&paciente1, 1, "João Silva", 45, "Hipertensão");
    
    printf("\nInformações do Paciente (Exemplo):\n");
    exibirPaciente(&paciente1);
}

// Função para exibir informações de um médico
void exibirMedico(const Medico* m) {
    printf("ID: %d\n", m->id);
    printf("Nome: %s\n", m->nome);
    printf("CRM: %d\n", m->crm);
    
    // Buscar e exibir o nome da especialidade ao invés do código
    CadastroEspecialidade cadastroEsp;
    inicializarCadastroEspecialidade(&cadastroEsp, "data/especialidades.dat");
    carregarEspecialidades(&cadastroEsp);
    
    Especialidade* esp = buscarEspecialidade(&cadastroEsp, m->especialidade);
    if (esp != NULL) {
        printf("Especialidade: %s (Código: %d)\n", esp->nome, esp->codigo);
    } else {
        printf("Especialidade: %d (Não encontrada)\n", m->especialidade);
    }
}

int main() {
    int opcao;
    CadastroEspecialidade cadastroEsp;
    CadastroMedico cadastroMed;
    
    // Criar diretório data se não existir
    system("mkdir -p data");
    
    // Inicializa o cadastro de especialidades
    inicializarCadastroEspecialidade(&cadastroEsp, "data/especialidades.dat");
    
    // Inicializa o cadastro de médicos
    inicializarCadastroMedico(&cadastroMed, "data/medicos.dat");
    
    // Carregar especialidades do arquivo
    if (!carregarEspecialidades(&cadastroEsp)) {
        printf("Nenhuma especialidade encontrada. Cadastrando especialidades padrão...\n");
        cadastrarEspecialidadesPadrao(&cadastroEsp);
    }
    
    // Carregar médicos do arquivo
    carregarMedicos(&cadastroMed);
    
    do {
        exibirMenuPrincipal();
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer
        
        switch (opcao) {
            case 1:
                // Menu de especialidades
                menuEspecialidades();
                break;
                
            case 2:
                // Cadastrar médico com integração com especialidades
                cadastrarMedico(&cadastroMed, &cadastroEsp);
                break;
                
            case 3:
                // Cadastrar paciente
                cadastrarPaciente();
                break;
                
            case 4:
                // Exibir paciente exemplo
                exibirExemploPaciente();
                break;
                
            case 5:
                // Listar médicos cadastrados
                listarMedicos(&cadastroMed, &cadastroEsp);
                break;
                
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
                
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}