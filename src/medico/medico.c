#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medico.h"

Medico cadastar_medico() {
    Medico medico;
    
    printf("\n=== Cadastro de Médico ===\n");
    
    printf("Nome: ");
    scanf(" %[^\n]", medico.nome);
    
    printf("CRM: ");
    scanf(" %[^\n]", medico.crm);
    
    printf("Especialidade: ");
    scanf(" %[^\n]", medico.especialidade);
    
    printf("\nMédico cadastrado com sucesso!\n");
    
    return medico;
}


