#include <stdio.h>
#include "src/paciente/paciente.h"

int main() {
    Paciente paciente1;
    
    inicializarPaciente(&paciente1, 1, "João Silva", 45, "Hipertensão");
    
    printf("===== SISTEMA DE GERENCIAMENTO HOSPITALAR =====\n\n");
    
    printf("Informações do Paciente:\n");
    exibirPaciente(&paciente1);
    
    
    return 0;
}