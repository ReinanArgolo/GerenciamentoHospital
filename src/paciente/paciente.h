#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    int id;
    char nome[100];
    int idade;
    char condicao[200];
} Paciente;

// Protótipos de funções
void inicializarPaciente(Paciente* p, int id, const char* nome, int idade, const char* condicao);
void exibirPaciente(const Paciente* p);


#endif // PACIENTE_H