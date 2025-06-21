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

// Definindo o tipo para ponteiros de função do menu
typedef void (*FuncaoMenu)(CadastroEspecialidade*);

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

// Funções de menu
void cadastrarNovaEspecialidade(CadastroEspecialidade* cadastro);
void listarEspecialidades(CadastroEspecialidade* cadastro);
void buscarEspecialidadePorCodigo(CadastroEspecialidade* cadastro);
void voltarAoMenuPrincipal(CadastroEspecialidade* cadastro);
void opcaoInvalida(CadastroEspecialidade* cadastro);

// Função principal para o menu de especialidades
void menuEspecialidades();

// Função para pré-cadastrar especialidades comuns
void cadastrarEspecialidadesPadrao(CadastroEspecialidade* cadastro);

#endif // CADASTRAR_ESPECIALIDADE_H