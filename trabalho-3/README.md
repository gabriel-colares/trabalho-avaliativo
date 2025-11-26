# Sistema de Atendimento de Saúde (Trabalho 3)

Aplicação de console em C para cadastro, edição, exclusão, consultas e relatórios de Profissão, Profissional, Cliente e Atendimento.

## Visão Geral
- Foco em fluxo claro com etapas numeradas nas telas de entrada
- Navegação simples via teclado, com títulos de contexto (ex.: `CADASTROS > Cadastro de Profissional`)
- Dados mantidos em memória (arrays); sem dependência de arquivos ou banco
- Layout sem acentos/ç para evitar incompatibilidades em consoles

## Funcionalidades
- Cadastros
  - Profissão: `codigo`, `nome`, `sigla`
  - Profissional: `matricula`, `cpf`, `nome`, `prof_codigo`, `numRP`, `tipo`, `dataNasc`, `email`, `fone`
  - Cliente: `codigo`, `nome`, `dataNasc`, `idade`, `email`, `fone`, `celular`, `endereco {logradouro, numero, bairro, cidade, estado, cep}`
  - Atendimento: `numero`, `prof_matricula`, `cliente_codigo`, `data`, `descricao`
- Edição/Exclusão com validações
  - Impede excluir profissão em uso por profissionais
  - Impede excluir profissional/cliente com atendimentos
- Listagens
  - Profissões, Profissionais, Clientes, Atendimentos (com nomes resolvidos)
- Relatórios
  - Aniversariantes da instituição (Profissionais)
  - Aniversariantes dos Clientes (com fone, email, celular)
  - Atendimentos por período (cliente, profissional, data)
  - Atendimentos por mês em determinado ano (estatística por mês)
  - Estatística de atendimentos por profissional em período
- Dados de exemplo
  - Conjunto mínimo pré-preenchido para facilitar testes (profissionais, clientes e atendimentos)

## Compilação
- Pré-requisito: GCC (MinGW) ou compatível
- Dentro da pasta `trabalho-3`:
  - `gcc -Wall -O2 main.c -o sistema.exe`

## Execução
- `./sistema.exe`
- Use as opções do menu principal para navegar entre cadastros, listagens e relatórios

## Uso das Telas
- Entradas numéricas validadas; solicita nova tentativa quando inválidas
- Etapas numeradas deixam claro o progresso do preenchimento (ex.: `[Etapa 3/9]`)
- Títulos indicam o contexto atual (menu, cadastro, relatório)

## Limitações
- Dados vivem apenas durante a execução (sem persistência)
- Interface de texto (console); sem UI gráfica

## Estrutura
- `main.c`: estruturas, utilitários de entrada, menus, cadastros, listagens e relatórios

## Dicas
- Em Windows, a limpeza de tela pode usar `cls`; em ambientes POSIX, substitua por `clear` se necessário
- Mantenha o terminal com fonte monoespaçada para melhor leitura
