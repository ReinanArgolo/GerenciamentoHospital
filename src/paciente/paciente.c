#include <stdio.h>
#include <string.h>
#include "paciente.h"

void inicializarPaciente(Paciente* p, int id, const char* nome, int idade, const char* condicao) {
    p->id = id;
    strcpy(p->nome, nome);
    p->idade = idade;
    strcpy(p->condicao, condicao);
}

void exibirPaciente(const Paciente* p) {
    printf("ID do Paciente: %d\n", p->id);
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Condição Médica: %s\n", p->condicao);
}