#ifndef MENU_H
#define MENU_H

#include "../especialidades/especialidades.h"
#include "../medico/medico.h"
#include "../paciente/paciente.h"

// Menu principal
void exibirMenuPrincipal();

// Menus de especialidades
void menuEspecialidades();
void cadastrarNovaEspecialidadeMenu(CadastroEspecialidade* cadastro);
void listarEspecialidadesMenu(CadastroEspecialidade* cadastro);
void buscarEspecialidadePorCodigoMenu(CadastroEspecialidade* cadastro);

// Menus de médicos
void cadastrarMedicoMenu(CadastroMedico* cadastro, CadastroEspecialidade* cadastroEsp);
void listarMedicosMenu(CadastroMedico* cadastro, CadastroEspecialidade* cadastroEsp);

// Menus de pacientes
void cadastrarPacienteMenu();
void exibirPacienteExemploMenu();

// Utilitários de interface
void exibirMedicoDetalhes(const Medico* m, CadastroEspecialidade* cadastroEsp);

#endif