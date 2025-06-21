#ifndef MEDICO_H
#define MEDICO_H

#include "../especialidades/especialidades.h"

#define MAX_MEDICOS 100

typedef struct medico {
    int id;
    char nome[100];
    int especialidade;
    int crm;
} Medico;

typedef struct cadastroMedico {
    Medico lista[MAX_MEDICOS];
    int quantidade;
    char arquivo[100];
} CadastroMedico;

// Inicializa a estrutura de cadastro
void inicializarCadastroMedico(CadastroMedico* cadastro, const char* nomeArquivo);

// Funções para persistência de dados
int carregarMedicos(CadastroMedico* cadastro);
int salvarMedicos(CadastroMedico* cadastro);

// Cadastra um novo médico e retorna se foi bem sucedido
int cadastrarMedico(CadastroMedico* cadastro, CadastroEspecialidade* cadastroEsp);

// Lista todos os médicos cadastrados
void listarMedicos(CadastroMedico* cadastro, CadastroEspecialidade* cadastroEsp);

// Busca um médico pelo ID
Medico* buscarMedicoPorId(CadastroMedico* cadastro, int id);

#endif