#ifndef ESPECIALIDADES_H
#define ESPECIALIDADES_H

#include <stdio.h>

#define MAX_ESPECIALIDADES 100
#define MAX_NOME 100

typedef struct {
    int codigo;
    char nome[MAX_NOME];
} Especialidade;

typedef struct {
    Especialidade lista[MAX_ESPECIALIDADES];
    int quantidade;
    char arquivo[100];
} CadastroEspecialidade;

// Inicializa o cadastro de especialidades
void inicializarCadastroEspecialidade(CadastroEspecialidade* cadastro, const char* nomeArquivo);

// Carrega especialidades do arquivo
int carregarEspecialidades(CadastroEspecialidade* cadastro);

// Salva especialidades no arquivo
int salvarEspecialidades(CadastroEspecialidade* cadastro);

// Cadastra uma nova especialidade (agora sem o parâmetro código)
int cadastrarEspecialidade(CadastroEspecialidade* cadastro, const char* nome);

// Verifica se já existe especialidade com o mesmo código
int existeEspecialidade(CadastroEspecialidade* cadastro, int codigo);

// Busca especialidade por código
Especialidade* buscarEspecialidade(CadastroEspecialidade* cadastro, int codigo);

// Função para pré-cadastrar especialidades comuns
void cadastrarEspecialidadesPadrao(CadastroEspecialidade* cadastro);

// Função para listar especialidades (usada por outros módulos)
void listarEspecialidades(CadastroEspecialidade* cadastro);

#endif