#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#define MAX_LINHAS 6
#define MAX_COLUNAS 8

char sala[MAX_LINHAS][MAX_COLUNAS];
int tipo_ingresso[MAX_LINHAS][MAX_COLUNAS];
float preco_inteira, preco_meia;
const char *EMPRESA = "Cinema++ - Compilando Emocoes em Tempo Real";

void gotoxy(int x, int y)
{
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void clrscr()
{
  system("cls");
}

void desenhar_cinema()
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
  gotoxy(48, 2);
  printf("   _______  ");
  gotoxy(48, 3);
  printf("  /       \\ ");
  gotoxy(48, 4);
  printf(" | CINEMA++ |");
  gotoxy(48, 5);
  printf(" |_________|");
  gotoxy(48, 6);
  printf("   |  |  |  ");
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void pato(int x, int y, int aberto, int cor)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
  gotoxy(x, y);
  printf("   _");
  gotoxy(x, y + 1);

  if (aberto == 1)
  {
    printf("__\\(o)<");
  }
  else
  {
    printf("__\\(o)>");
  }

  gotoxy(x, y + 2);
  printf(" \\___)");
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void animar_pato_cinema()
{
  clrscr();
  int destino = 43;

  for (int x = 0; x <= destino; x++)
  {
    desenhar_cinema();
    pato(x, 9, x % 2, 14);
    Sleep(45);
    clrscr();
  }

  for (int i = 0; i < 8; i++)
  {
    int cor;

    if (i % 2 == 0)
    {
      cor = 10;
    }
    else
    {
      cor = 15;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
    gotoxy(44, 0);
    printf("BEM-VINDO AO CINEMA++");
    desenhar_cinema();
    pato(destino, 9, i % 2, 14);
    Sleep(400);
    clrscr();
  }

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
  gotoxy(44, 0);
  printf("BEM-VINDO AO CINEMA++");
  desenhar_cinema();
  pato(destino, 9, 0, 14);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
  Sleep(800);
}

void inicializar()
{
  for (int i = 0; i < MAX_LINHAS; i++)
  {
    for (int j = 0; j < MAX_COLUNAS; j++)
    {
      sala[i][j] = 'O';
      tipo_ingresso[i][j] = 0;
    }
  }

  clrscr();
  gotoxy(5, 1);
  printf("======== %s ========", EMPRESA);
  gotoxy(0, 3);
  printf("Valor ingresso INTEIRA: R$ ");
  scanf("%f", &preco_inteira);
  gotoxy(0, 4);
  printf("Valor ingresso MEIA: R$ ");
  scanf("%f", &preco_meia);
  animar_pato_cinema();
}

void desenhar_sala()
{
  clrscr();
  gotoxy(10, 0);
  printf("=== %s ===", EMPRESA);

  gotoxy(0, 2);
  printf("     ");

  for (int c = 1; c <= MAX_COLUNAS; c++)
  {
    printf("%2d ", c);
  }

  printf("\n");

  for (int i = 0; i < MAX_LINHAS; i++)
  {
    gotoxy(0, 3 + i);
    printf(" %c  ", 'A' + i);

    for (int j = 0; j < MAX_COLUNAS; j++)
    {
      if (i == 0)
      {
        if (sala[i][j] == 'O')
        {
          printf("[P]");
        }
        else
        {
          printf("[X]");
        }
      }
      else
      {
        printf("[%c]", sala[i][j]);
      }
    }
  }

  gotoxy(30, 3);
  printf("Legenda:");
  gotoxy(30, 4);
  printf("[O] Livre");
  gotoxy(30, 5);
  printf("[X] Ocupado");
  gotoxy(30, 6);
  printf("[P] Livre PCD");
}

void reservar()
{
  char linha;
  int coluna, tipo;

  desenhar_sala();
  gotoxy(0, 10);
  printf("Fileira (A-%c): ", 'A' + MAX_LINHAS - 1);
  scanf(" %c", &linha);
  gotoxy(0, 11);
  printf("Numero (1-%d): ", MAX_COLUNAS);
  scanf("%d", &coluna);

  int i = toupper(linha) - 'A';
  int j = coluna - 1;

  if (i < 0 || i >= MAX_LINHAS || j < 0 || j >= MAX_COLUNAS)
  {
    gotoxy(0, 13);
    printf("Posicao invalida!");
    getchar();
    getchar();
    return;
  }

  if (sala[i][j] == 'X')
  {
    gotoxy(0, 13);
    printf("Poltrona ja reservada!");
    getchar();
    getchar();
    return;
  }

  if (i == 0)
  {
    gotoxy(0, 13);
    printf("Poltrona PCD. Marcada como PCD.");
    tipo = 3;
  }
  else
  {
    gotoxy(0, 13);
    printf("Tipo: 1=Meia 2=Inteira: ");
    scanf("%d", &tipo);

    if (tipo != 1 && tipo != 2)
    {
      tipo = 2;
    }
  }

  sala[i][j] = 'X';
  tipo_ingresso[i][j] = tipo;
  gotoxy(0, 15);
  printf("Reserva realizada!");
  getchar();
  getchar();
}

void cancelar()
{
  char linha;
  int coluna;

  desenhar_sala();
  gotoxy(0, 10);
  printf("Fileira (A-%c): ", 'A' + MAX_LINHAS - 1);
  scanf(" %c", &linha);
  gotoxy(0, 11);
  printf("Numero (1-%d): ", MAX_COLUNAS);
  scanf("%d", &coluna);

  int i = toupper(linha) - 'A';
  int j = coluna - 1;

  if (i < 0 || i >= MAX_LINHAS || j < 0 || j >= MAX_COLUNAS)
  {
    gotoxy(0, 13);
    printf("Posicao invalida!");
    getchar();
    getchar();
    return;
  }

  if (sala[i][j] == 'O')
  {
    gotoxy(0, 13);
    printf("Poltrona ja esta livre!");
    getchar();
    getchar();
    return;
  }

  sala[i][j] = 'O';
  tipo_ingresso[i][j] = 0;
  gotoxy(0, 15);
  printf("Reserva cancelada.");
  getchar();
  getchar();
}

void verificar()
{
  char linha;
  int coluna;

  desenhar_sala();
  gotoxy(0, 10);
  printf("Fileira (A-%c): ", 'A' + MAX_LINHAS - 1);
  scanf(" %c", &linha);
  gotoxy(0, 11);
  printf("Numero (1-%d): ", MAX_COLUNAS);
  scanf("%d", &coluna);

  int i = toupper(linha) - 'A';
  int j = coluna - 1;

  clrscr();
  gotoxy(10, 2);
  printf("=== Verificacao de Poltrona ===");

  gotoxy(0, 4);
  printf("Posicao: %c%d", 'A' + i, j + 1);

  if (sala[i][j] == 'X')
  {
    gotoxy(0, 5);
    printf("Status: OCUPADA");

    if (i == 0)
    {
      gotoxy(0, 6);
      printf("Categoria: PCD");
    }
    else if (tipo_ingresso[i][j] == 1)
    {
      gotoxy(0, 6);
      printf("Categoria: Meia");
    }
    else
    {
      gotoxy(0, 6);
      printf("Categoria: Inteira");
    }

    float preco;

    if (tipo_ingresso[i][j] == 1 || tipo_ingresso[i][j] == 3)
    {
      preco = preco_meia;
    }
    else
    {
      preco = preco_inteira;
    }

    gotoxy(0, 7);
    printf("Valor pago: R$ %.2f", preco);
  }
  else
  {
    gotoxy(0, 5);
    printf("Status: LIVRE");

    if (i == 0)
    {
      gotoxy(0, 6);
      printf("Categoria: PCD");
    }
    else
    {
      gotoxy(0, 6);
      printf("Categoria: Comum");
    }

    gotoxy(0, 7);
    printf("Valores: Inteira R$ %.2f | Meia R$ %.2f", preco_inteira, preco_meia);
  }

  gotoxy(0, 9);
  printf("Pressione ENTER para voltar...");
  getchar();
  getchar();
}

void grafico()
{
  int ocupadas = 0;
  int livres = 0;

  for (int i = 0; i < MAX_LINHAS; i++)
  {
    for (int j = 0; j < MAX_COLUNAS; j++)
    {
      if (sala[i][j] == 'X')
      {
        ocupadas++;
      }
      else
      {
        livres++;
      }
    }
  }

  int total = MAX_LINHAS * MAX_COLUNAS;
  int bar_ocup = ocupadas * 40 / total;
  int bar_livre = livres * 40 / total;

  printf("\nGrafico de Ocupacao:\n");
  printf("Ocupadas: ");
  for (int i = 0; i < bar_ocup; i++)
  {
    printf("%c", 219);
  }
  printf(" %d\n", ocupadas);

  printf("Livres:   ");
  for (int i = 0; i < bar_livre; i++)
  {
    printf("%c", 176);
  }
  printf(" %d\n", livres);
}

void listar_simples()
{
  int ocupadas = 0;
  int livres = 0;

  for (int i = 0; i < MAX_LINHAS; i++)
  {
    for (int j = 0; j < MAX_COLUNAS; j++)
    {
      if (sala[i][j] == 'X')
      {
        ocupadas++;
      }
      else
      {
        livres++;
      }
    }
  }

  clrscr();
  gotoxy(10, 1);
  printf("=== LISTAGEM SIMPLES ===");
  gotoxy(0, 3);
  printf("Total: %d", MAX_LINHAS * MAX_COLUNAS);
  gotoxy(0, 4);
  printf("Ocupadas: %d", ocupadas);
  gotoxy(0, 5);
  printf("Livres: %d", livres);
  getchar();
  getchar();
}

void listar_detalhada()
{
  int total_pcd = 0;
  int total_meia = 0;
  int total_inteira = 0;
  float valor_total = 0.0;

  for (int i = 0; i < MAX_LINHAS; i++)
  {
    for (int j = 0; j < MAX_COLUNAS; j++)
    {
      if (tipo_ingresso[i][j] == 3)
      {
        total_pcd++;
        valor_total += preco_meia;
      }
      if (tipo_ingresso[i][j] == 1)
      {
        total_meia++;
        valor_total += preco_meia;
      }
      if (tipo_ingresso[i][j] == 2)
      {
        total_inteira++;
        valor_total += preco_inteira;
      }
    }
  }

  clrscr();
  gotoxy(10, 1);
  printf("=== LISTAGEM DETALHADA ===");
  gotoxy(0, 3);
  printf("PCD: %d (R$ %.2f)", total_pcd, preco_meia);
  gotoxy(0, 4);
  printf("Meia: %d (R$ %.2f)", total_meia, preco_meia);
  gotoxy(0, 5);
  printf("Inteira: %d (R$ %.2f)", total_inteira, preco_inteira);
  gotoxy(0, 7);
  printf("Total ingressos: %d", total_pcd + total_meia + total_inteira);
  gotoxy(0, 8);
  printf("Valor total: R$ %.2f", valor_total);
  gotoxy(0, 10);
  grafico();
  getchar();
  getchar();
}

void menu()
{
  int op;

  do
  {
    desenhar_sala();
    gotoxy(0, 4 + MAX_LINHAS);
    printf("=== MENU PRINCIPAL ===");
    gotoxy(0, 5 + MAX_LINHAS);
    printf("[1] Reservar poltrona");
    gotoxy(0, 6 + MAX_LINHAS);
    printf("[2] Cancelar reserva");
    gotoxy(0, 7 + MAX_LINHAS);
    printf("[3] Verificar poltrona");
    gotoxy(0, 8 + MAX_LINHAS);
    printf("[4] Listagem simples");
    gotoxy(0, 9 + MAX_LINHAS);
    printf("[5] Listagem detalhada");
    gotoxy(0, 10 + MAX_LINHAS);
    printf("[0] Sair");
    gotoxy(0, 12 + MAX_LINHAS);
    printf("Escolha: ");
    scanf("%d", &op);

    if (op == 1)
    {
      reservar();
    }
    else if (op == 2)
    {
      cancelar();
    }
    else if (op == 3)
    {
      verificar();
    }
    else if (op == 4)
    {
      listar_simples();
    }
    else if (op == 5)
    {
      listar_detalhada();
    }
    else if (op == 0)
    {
      clrscr();
      gotoxy(10, 5);
      printf("Encerrando o sistema Cinema++...");
    }
    else
    {
      gotoxy(0, 19 + MAX_LINHAS);
      printf("Opcao invalida!");
      getchar();
      getchar();
    }

  } while (op != 0);
}

int main()
{
  inicializar();
  menu();
  return 0;
}
