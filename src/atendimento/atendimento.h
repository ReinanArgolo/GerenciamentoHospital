#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#define MAX_ATENDIMENTO = 100;

#include <time.h>
#include "src/medico/medico.h"
#include "src/paciente/paciente.h"


typedef struct atendimento{
    int id;
    int id_atendimento;
    int id_medico;
    time_t data = time(NULL);
} Atendimento;

typedef struct cadastroAtendimento {
    Atendimento lista[MAX_ATENDIMENTO];
    int quantidade;
    char arquivo[100];
} CadastroAtendimento;

// Inicializa a estrutura de cadastro
void inicializarCadastroAtendimento(CadastroAtendimento* cadastro, const char* nomeArquivo);

// Funções para persistência de dados
int carregarAtendimento(CadastroAtendimento* cadastro);
int salvarAtendimento(CadastroAtendimento* cadastro);

// Cadastra um novo médico e retorna se foi bem sucedido
int cadastrarAtendimento(CadastroAtedendimento* cadastro);

// Lista todos os médicos cadastrados
void listarAtendimento(CadastroAtendimento* cadastro);

// Busca um médico pelo ID
Atendimento* buscarAtendimentoPorId(CadastroAtendimento* cadastro, int id);

#endif