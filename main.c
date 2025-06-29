#include <stdio.h>
#include <stdlib.h>
#include "src/paciente/paciente.h"
#include "src/medico/medico.h"
#include "src/especialidades/especialidades.h"
#include "src/interfaces/menu.h"  // Nova inclusão para o módulo de interfaces

int main() {
    int opcao;
    CadastroEspecialidade cadastroEsp;
    CadastroMedico cadastroMed;

    
    // Criar diretório data se não existir
    system("mkdir -p data");
    
    // Inicializa o cadastro de especialidades
    inicializarCadastroEspecialidade(&cadastroEsp, "data/especialidades.csv");
    
    // Inicializa o cadastro de médicos
    inicializarCadastroMedico(&cadastroMed, "data/medicos.csv");
    
    // Carregar especialidades do arquivo
    if (!carregarEspecialidades(&cadastroEsp)) {
        printf("Nenhuma especialidade encontrada. Cadastrando especialidades padrão...\n");
        cadastrarEspecialidadesPadrao(&cadastroEsp);
    }
    
    // Carregar médicos do arquivo
    carregarMedicos(&cadastroMed);
    
    do {
        exibirMenuPrincipal();
        scanf("%d", &opcao);
        getchar(); 
        
        switch (opcao) {
            case 1:
                menuEspecialidades();
                break;
                
            case 2:
                cadastrarMedicoMenu(&cadastroMed, &cadastroEsp);
                break;
                
            case 3:
                cadastrarPacienteMenu();
                break;
                
            case 4:
                exibirPacienteExemploMenu();
                break;
                
            case 5:
                listarMedicosMenu(&cadastroMed, &cadastroEsp);
                break;
                
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
                
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}