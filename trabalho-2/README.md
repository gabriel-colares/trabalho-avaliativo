# Sistema de Saúde (Trabalho 2)

Aplicação de console em C para gerenciar informações de profissionais de saúde, clientes e atendimentos, com cadastros, edições, exclusões, listagens e relatórios.

## Descrição

- Fluxo de uso guiado por prompts claros e etapas numeradas
- Dados mantidos apenas em memória (arrays); sem persistência em arquivo
- Código sem uso de ponteiros nas operações de domínio; buscas por índice

## Funcionalidades

- Cadastros
  - Profissão: `codigo`, `nome`, `sigla`
  - Profissional: `matricula`, `cpf`, `nome`, `prof_codigo`, `numRP`, `tipo`, `dataNasc`, `email`, `fone`
  - Cliente: `codigo`, `nome`, `dataNasc`, `idade`, `email`, `fone`, `celular`, `endereco {logradouro, numero, bairro, cidade, estado, cep}`
  - Atendimento: `numero`, `prof_matricula`, `cliente_codigo`, `data`, `descricao`
- Edição/Exclusão
  - Validações impedem exclusão de registros com dependências (ex.: profissão em uso, cliente/profissional com atendimentos)
- Listagens
  - Profissões, Profissionais, Clientes e Atendimentos (com nomes resolvidos por índice)
- Relatórios
  - Aniversariantes da Instituição (Profissionais)
  - Aniversariantes dos Clientes (nome, dia/mês, fone, celular, email)
  - Atendimentos por Período (nome do cliente, nome do profissional, data)
  - Atendimentos por Mês em um ano (mês e quantidade)
  - Estatística de Atendimentos por Profissional em período

## Compilação

- Pré-requisito: GCC (MinGW) ou compatível
- No diretório `trabalho-2`:
  - `gcc -Wall -O2 main.c -o sistema.exe`

## Execução

- `./sistema.exe`
- Navegue pelos menus:
  - Menu Principal: Profissões, Profissionais, Clientes, Atendimentos, Relatórios
  - Cada seção possui opções de cadastrar, editar, excluir e listar

## Entrada de Dados

- Leitura de inteiros e datas com validação (sem `scanf` direto)
- Leitura de textos com `fgets` e remoção de `\n`

## Limitações

- Dados existem apenas durante a execução; ao encerrar, tudo é descartado
- Interface baseada em console

## Observações

- Em Windows, limpeza de tela usa `cls`; em ambientes POSIX, use `clear` se necessário
- Fonte monoespaçada no terminal melhora a leitura

## Estrutura

- `main.c`: estruturas, utilitários de entrada, menus, cadastros, validações, listagens e relatórios
