#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "../especialidades/especialidades.h"
#include "../medico/medico.h"
#include "../paciente/paciente.h"

// Menu principal
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

// Menus de especialidades
void menuEspecialidades() {
    CadastroEspecialidade cadastro;
    inicializarCadastroEspecialidade(&cadastro, "data/especialidades.dat");
    carregarEspecialidades(&cadastro);
    
    int opcao;
    
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
                cadastrarNovaEspecialidadeMenu(&cadastro);
                break;
            case 2:
                listarEspecialidadesMenu(&cadastro);
                break;
            case 3:
                buscarEspecialidadePorCodigoMenu(&cadastro);
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

void cadastrarNovaEspecialidadeMenu(CadastroEspecialidade* cadastro) {
    char nome[MAX_NOME];
    printf("\nCadastro de nova especialidade\n");
    printf("Nome da especialidade: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = 0; // Remover quebra de linha
    
    if (cadastrarEspecialidade(cadastro, nome)) {
        printf("Especialidade cadastrada com sucesso!\n");
        printf("Código gerado: %d\n", cadastro->lista[cadastro->quantidade-1].codigo);
    } else {
        printf("Erro ao cadastrar especialidade!\n");
    }
}

void listarEspecialidadesMenu(CadastroEspecialidade* cadastro) {
    printf("\n=== ESPECIALIDADES CADASTRADAS ===\n");
    if (cadastro->quantidade == 0) {
        printf("Nenhuma especialidade cadastrada.\n");
    } else {
        for (int i = 0; i < cadastro->quantidade; i++) {
            printf("Código: %d - %s\n", cadastro->lista[i].codigo, cadastro->lista[i].nome);
        }
    }
}

void buscarEspecialidadePorCodigoMenu(CadastroEspecialidade* cadastro) {
    int codigo;
    printf("\nBuscar especialidade\n");
    printf("Informe o código: ");
    scanf("%d", &codigo);
    getchar(); // Limpar o buffer
    
    Especialidade* esp = buscarEspecialidade(cadastro, codigo);
    if (esp != NULL) {
        printf("Especialidade encontrada: %d - %s\n", esp->codigo, esp->nome);
    } else {
        printf("Especialidade não encontrada!\n");
    }
}

// Menus de médicos
void cadastrarMedicoMenu(CadastroMedico* cadastro, CadastroEspecialidade* cadastroEsp) {
    // Chamar a função de cadastro de médico
    cadastrarMedico(cadastro, cadastroEsp);
}

void listarMedicosMenu(CadastroMedico* cadastro, CadastroEspecialidade* cadastroEsp) {
    listarMedicos(cadastro, cadastroEsp);
}

// Menus de pacientes
void cadastrarPacienteMenu() {
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

void exibirPacienteExemploMenu() {
    Paciente paciente1;
    
    inicializarPaciente(&paciente1, 1, "João Silva", 45, "Hipertensão");
    
    printf("\nInformações do Paciente (Exemplo):\n");
    exibirPaciente(&paciente1);
}

// Utilitários de interface
void exibirMedicoDetalhes(const Medico* m, CadastroEspecialidade* cadastroEsp) {
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
}