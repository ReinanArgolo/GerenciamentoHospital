
# Sistema de Gerenciamento de Clínica

## Visão Geral
O Sistema de Gerenciamento de Clínica é uma aplicação baseada em console desenvolvida em C, que facilita a administração de médicos, pacientes e filas de atendimento em uma clínica médica. O sistema permite o cadastro de médicos e pacientes, a gestão de filas de atendimento por especialidade e a geração de relatórios sobre os atendimentos realizados.

## Funcionalidades
### Funcionalidades Principais
- **Gerenciamento de Médicos**: Cadastrar e gerenciar médicos com seus dados, incluindo nome, CRM e especialidade.
- **Gerenciamento de Pacientes**: Cadastrar e gerenciar pacientes com informações como nome, CPF e data de nascimento.
- **Gestão de Filas de Atendimento**: Gerenciar as consultas dos pacientes organizadas por especialidade médica.
- **Registro de Atendimentos**: Registrar os atendimentos com os médicos e pacientes associados, incluindo data e hora.
- **Geração de Relatórios**: Gerar relatórios de atendimentos realizados em períodos específicos.
- **Persistência de Dados**: Salvar e carregar dados de médicos, pacientes e atendimentos usando arquivos.

### Funcionalidades Secundárias
- **Busca de Pacientes**: Buscar pacientes por nome ou CPF.
- **Ordenação de Filas**: Ordenar as filas de atendimento por prioridade ou horário de chegada.
- **Interface de Texto Interativa**: Menus interativos para navegação do usuário.

## Requisitos
### Requisitos Funcionais
- O sistema deve permitir o cadastro de médicos e pacientes.
- O sistema deve gerenciar filas de atendimento e registrar os atendimentos.
- O sistema deve gerar relatórios com base nos atendimentos realizados.
- O sistema deve persistir os dados utilizando arquivos.

### Requisitos Não Funcionais
- Desenvolvido em C.
- Utiliza estruturas de dados dinâmicas.
- Projeto modular com arquivos separados para cada funcionalidade.
- Inclui funções recursivas quando aplicável.
- Interface de usuário baseada em texto com menus interativos.

## Estrutura do Projeto
```
clinic-management-system
├── src
│   ├── main.c
│   ├── doctor.c
│   ├── doctor.h
│   ├── patient.c
│   ├── patient.h
│   ├── queue.c
│   ├── queue.h
│   ├── appointment.c
│   ├── appointment.h
│   ├── report.c
│   ├── report.h
│   ├── file_handler.c
│   ├── file_handler.h
│   ├── utils.c
│   └── utils.h
├── data
│   ├── doctors.csv
│   ├── patients.csv
│   └── appointments.csv
├── docs
│   └── requirements.txt
├── Makefile
└── README.md
```

## Instruções de Instalação
1. Clone o repositório para sua máquina local.
2. Navegue até o diretório do projeto.
3. Use o Makefile fornecido para compilar o projeto:
   \`\`\`
   make
   \`\`\`
4. Execute o arquivo compilado:
   \`\`\`
   ./output/hospital
   \`\`\`

## Uso
Siga as instruções exibidas na tela para navegar pelos menus de gerenciamento de médicos, pacientes e atendimentos. Utilize as opções interativas para realizar as diversas funcionalidades de acordo com suas necessidades.

## Licença
Este projeto está licenciado sob a Licença MIT. Consulte o arquivo LICENSE para mais detalhes.