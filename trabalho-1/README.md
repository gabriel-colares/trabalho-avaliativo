# Cinema++ - Sistema de Reserva de Poltronas

**Cinema++ - Compilando Emocoes em Tempo Real**

Um sistema de gerenciamento de reservas de poltronas para cinema desenvolvido em C.

## 📋 Descrição

O Cinema++ é uma aplicação que gerencia a reserva de poltronas em uma sala de cinema. O sistema permite que usuários façam reservas, cancelem reservas, verifiquem o status das poltronas e visualizem relatórios de ocupação.

## 🎬 Funcionalidades

- **Reservar Poltrona**: Reserva uma poltrona especificando fileira e número, com opção de escolher entre ingresso inteira ou meia
- **Cancelar Reserva**: Cancela uma reserva existente
- **Verificar Poltrona**: Consulta o status de uma poltrona específica (ocupada ou livre) e informações de preço
- **Listagem Simples**: Exibe total de poltronas, ocupadas e livres
- **Listagem Detalhada**: Mostra estatísticas completas com categorias de ingresso e valor total arrecadado
- **Interface Gráfica**: Visualização colorida da sala de cinema com animação de boas-vindas

## 🏛️ Estrutura da Sala

- **Fileiras**: A até F (6 fileiras)
- **Poltronas por fileira**: 1 até 8 (8 poltronas)
- **Total**: 48 poltronas
- **Primeira fileira (A)**: Reservada para pessoas com deficiência (PCD)

## 💰 Categorias de Ingresso

- **Inteira**: Preço padrão completo
- **Meia**: Preço reduzido (50%)
- **PCD**: Preço de meia entrada (primeira fileira)

## 🚀 Como Compilar e Executar

### Pré-requisitos
- Compilador C (GCC, Clang ou similares)
- Sistema operacional Windows (devido ao uso de `<windows.h>`)

### Compilação
```bash
gcc main.c -o cinema.exe
```

### Execução
```bash
cinema.exe
```

## 🎮 Como Usar

1. **Iniciar o programa**: O sistema exibe uma animação de boas-vindas
2. **Configurar preços**: Insira o valor do ingresso inteira e meia no início
3. **Menu Principal**: Escolha uma das opções:
   - `1` - Reservar poltrona
   - `2` - Cancelar reserva
   - `3` - Verificar poltrona
   - `4` - Listagem simples
   - `5` - Listagem detalhada
   - `0` - Sair do sistema

## 📊 Legenda de Poltronas

- `[O]` - Poltrona livre (ou `[P]` para PCD)
- `[X]` - Poltrona ocupada

## 📁 Estrutura do Código

- `sala[][]`: Matriz que armazena o estado das poltronas
- `tipo_ingresso[][]`: Matriz que armazena o tipo de ingresso (1=Meia, 2=Inteira, 3=PCD)
- Funções principais:
  - `inicializar()`: Configura o sistema
  - `desenhar_sala()`: Exibe a visualização da sala
  - `reservar()`, `cancelar()`, `verificar()`: Operações de reserva
  - `listar_simples()`, `listar_detalhada()`: Relatórios
  - `menu()`: Loop principal do programa

## 🎨 Recursos Especiais

- Animação de pato caminhando na tela de boas-vindas
- Interface colorida com posicionamento de cursor
- Gráficos de ocupação em modo texto
- Tratamento de posições inválidas e erros de entrada

## 📝 Autor

Desenvolvido como trabalho avaliativo para o curso de ATP (Algoritmos e Técnicas de Programação).

## ⚙️ Tecnologias Utilizadas

- **Linguagem**: C
- **Bibliotecas**: 
  - `stdio.h` - Entrada/saída
  - `stdlib.h` - Funções gerais
  - `ctype.h` - Manipulação de caracteres
  - `windows.h` - Funções do Windows (cores, cursor)
