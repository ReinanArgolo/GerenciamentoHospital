#ifndef CADASTRAR_ESPECIALIDADE_H
#define CADASTRAR_ESPECIALIDADE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME 100
#define MAX_ESPECIALIDADES 100

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

// Cadastra uma nova especialidade
int cadastrarEspecialidade(CadastroEspecialidade* cadastro, int codigo, const char* nome);

// Verifica se já existe especialidade com o mesmo código
int existeEspecialidade(CadastroEspecialidade* cadastro, int codigo);

// Busca especialidade por código
Especialidade* buscarEspecialidade(CadastroEspecialidade* cadastro, int codigo);

#endif // CADASTRAR_ESPECIALIDADE_H