# Saúde++ - Sistema de Gestão de Atendimentos

**Saúde++ – Cuidando de dados com precisão e simplicidade**

Aplicação em C para gerenciamento de profissões, profissionais, clientes e atendimentos, com listagens e relatórios úteis para o dia a dia administrativo.

## 📋 Descrição
- Sistema de console orientado a menu, com entradas validadas e prompts amigáveis.
- Foco em fluxo simples no Windows, utilizando limpeza de tela e leitura robusta de inputs.

## 🎯 Funcionalidades
- Cadastrar Profissão, Profissional, Cliente e Atendimento
- Listar Profissões, Profissionais, Clientes e Atendimentos
- Relatórios:
  - Aniversariantes de Profissionais
  - Aniversariantes de Clientes
  - Atendimentos por Período
  - Atendimentos por Mês de um Ano
  - Estatística por Profissional

## 🧱 Estrutura de Dados
- Constantes de capacidade:
  - `MAX_PROFISSOES`, `MAX_PROFISSIONAIS`, `MAX_CLIENTES`, `MAX_ATENDIMENTOS`
- Estruturas principais:
  - `struct Data`, `struct Profissao`, `struct Profissional`, `struct Cliente`, `struct Atendimento`
- Armazenamento em memória (arrays):
  - `profissoes[]`, `profissionais[]`, `clientes[]`, `atendimentos[]`

## 🚀 Como Compilar e Executar
### Pré-requisitos
- Compilador C (GCC/MinGW ou similares)
- Sistema operacional Windows (devido ao uso de `system("cls")`)

### Compilação
```bash
gcc -Wall -O2 main.c -o saude.exe
```

### Execução
```bash
saude.exe
```

> Observação: Em outros sistemas, substitua `system("cls")` por `system("clear")` no código.

## 🎮 Como Usar
1. Iniciar o programa para exibir o menu principal
2. Escolher uma opção:
   - `1` – Cadastrar Profissão
   - `2` – Cadastrar Profissional
   - `3` – Cadastrar Cliente
   - `4` – Cadastrar Atendimento
   - `5` – Listar Profissões
   - `6` – Listar Profissionais
   - `7` – Listar Clientes
   - `8` – Listar Atendimentos
   - `9` – Relatório de Aniversariantes (Profissionais)
   - `10` – Relatório de Aniversariantes (Clientes)
   - `11` – Atendimentos por Período
   - `12` – Atendimentos por Mês
   - `13` – Estatística por Profissional
   - `0` – Sair

## ✅ Boas Práticas de Entrada
- Após `scanf` de números, o sistema limpa o buffer antes de ler textos
- Placeholders indicam formatos esperados (ex.: `usuario@dominio.com`, `92 3333-3333`)
- Código/matrícula duplicados solicitam nova entrada
- As listagens e relatórios permanecem na tela até confirmação com Enter

## 📁 Estrutura do Código
- Arrays e estruturas de domínio (`main.c`)
- Utilitários de entrada:
  - `lerLinha()`, `lerInt()`, `lerData()`, `limparEntrada()`, `pause()`
- Fluxo principal:
  - `menu()`, `cadastrarProfissao()`, `cadastrarProfissional()`, `cadastrarCliente()`, `cadastrarAtendimento()`
  - `listarProfissoes()`, `listarProfissionais()`, `listarClientes()`, `listarAtendimentos()`
  - Relatórios: `relAniversariantesProfissionais()`, `relAniversariantesClientes()`, `relAtendimentosPorPeriodo()`, `relAtendimentoPorMes()`, `relEstatisticaPorProfissional()`

## 📝 Autor
Desenvolvido como trabalho avaliativo para o curso de ATP (Algoritmos e Técnicas de Programação).

## ⚙️ Tecnologias Utilizadas
- **Linguagem**: C
- **Bibliotecas**:
  - `stdio.h`, `stdlib.h`, `string.h`
