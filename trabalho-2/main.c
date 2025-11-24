#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROFISSOES 50
#define MAX_PROFISSIONAIS 200
#define MAX_CLIENTES 300
#define MAX_ATENDIMENTOS 2000

struct Data {
  int dia, mes, ano;
};

struct Profissao {
  int codigo;
  char nome[50];
  char sigla[10];
};

struct Profissional {
  int matricula;
  char cpf[20];
  char nome[80];
  int prof_codigo;
  char numRP[20];
  char tipo[40];
  struct Data nascimento;
  char email[80];
  char fone[20];
};

struct Cliente {
  int codigo;
  char nome[80];
  struct Data nascimento;
  int idade;
  char email[80];
  char fone[20];
  char celular[20];
  char endereco[150];
};

struct Atendimento {
  int numero;
  int prof_matricula;
  int cliente_codigo;
  struct Data data;
  char descricao[200];
};

struct Profissao profissoes[MAX_PROFISSOES];
struct Profissional profissionais[MAX_PROFISSIONAIS];
struct Cliente clientes[MAX_CLIENTES];
struct Atendimento atendimentos[MAX_ATENDIMENTOS];

int qtdProfissoes = 0;
int qtdProfissionais = 0;
int qtdClientes = 0;
int qtdAtendimentos = 0;

void clrscr() {
  system("cls");
}

void titulo(const char txt[]) {
  clrscr();
  printf("=== %s ===\n", txt);
}

void pause() {
  int c;
  printf("\nPressione Enter para continuar...");
  while ((c = getchar()) != '\n' && c != EOF) {}
}

struct Data lerData() {
  struct Data d;
  printf("Dia: ");
  scanf("%d", &d.dia);
  printf("Mes: ");
  scanf("%d", &d.mes);
  printf("Ano: ");
  scanf("%d", &d.ano);
  return d;
}

void cadastrarProfissao() {
  titulo("Cadastro de Profissao");

  if (qtdProfissoes >= MAX_PROFISSOES) {
    printf("Limite de profissoes atingido.");
    pause();
    return;
  }

  struct Profissao p;

  printf("Codigo: ");
  scanf("%d", &p.codigo);

  printf("Nome: ");
  getchar();
  fgets(p.nome, 50, stdin);
  p.nome[strcspn(p.nome, "\n")] = 0;

  printf("Sigla (CRM, CRO...): ");
  fgets(p.sigla, 10, stdin);
  p.sigla[strcspn(p.sigla, "\n")] = 0;

  profissoes[qtdProfissoes++] = p;

  printf("\nProfissao cadastrada!");
  pause();
}

void listarProfissoes() {
  titulo("Listagem de Profissoes");

  for (int i = 0; i < qtdProfissoes; i++) {
    printf("%d - %s (%s)\n",
           profissoes[i].codigo,
           profissoes[i].nome,
           profissoes[i].sigla);
  }

  pause();
}

void cadastrarProfissional() {
  titulo("Cadastro de Profissional");

  if (qtdProfissionais >= MAX_PROFISSIONAIS) {
    printf("Limite atingido.");
    pause();
    return;
  }

  struct Profissional p;

  printf("Matricula: ");
  scanf("%d", &p.matricula);

  printf("CPF: ");
  getchar();
  fgets(p.cpf, 20, stdin);
  p.cpf[strcspn(p.cpf, "\n")] = 0;

  printf("Nome: ");
  fgets(p.nome, 80, stdin);
  p.nome[strcspn(p.nome, "\n")] = 0;

  printf("Codigo da profissao: ");
  scanf("%d", &p.prof_codigo);

  printf("Numero RP: ");
  getchar();
  fgets(p.numRP, 20, stdin);
  p.numRP[strcspn(p.numRP, "\n")] = 0;

  printf("Tipo de profissional (medico, enfermeiro...): ");
  fgets(p.tipo, 40, stdin);
  p.tipo[strcspn(p.tipo, "\n")] = 0;

  printf("Data de nascimento:\n");
  p.nascimento = lerData();

  printf("Email: ");
  fgets(p.email, 80, stdin);
  p.email[strcspn(p.email, "\n")] = 0;

  printf("Fone: ");
  fgets(p.fone, 20, stdin);
  p.fone[strcspn(p.fone, "\n")] = 0;

  profissionais[qtdProfissionais++] = p;

  printf("\nProfissional cadastrado!");
  pause();
}

void listarProfissionais() {
  titulo("Listagem de Profissionais");

  for (int i = 0; i < qtdProfissionais; i++) {
    printf("Mat: %d | Nome: %s | Profissao: %d\n",
           profissionais[i].matricula,
           profissionais[i].nome,
           profissionais[i].prof_codigo);
  }

  pause();
}

void cadastrarCliente() {
  titulo("Cadastro de Cliente");

  if (qtdClientes >= MAX_CLIENTES) {
    printf("Limite atingido!");
    pause();
    return;
  }

  struct Cliente c;

  printf("Codigo: ");
  scanf("%d", &c.codigo);

  printf("Nome: ");
  getchar();
  fgets(c.nome, 80, stdin);
  c.nome[strcspn(c.nome, "\n")] = 0;

  printf("Data nascimento:\n");
  c.nascimento = lerData();

  printf("Idade: ");
  scanf("%d", &c.idade);

  printf("Email: ");
  getchar();
  fgets(c.email, 80, stdin);
  c.email[strcspn(c.email, "\n")] = 0;

  printf("Fone: ");
  fgets(c.fone, 20, stdin);
  c.fone[strcspn(c.fone, "\n")] = 0;

  printf("Celular: ");
  fgets(c.celular, 20, stdin);
  c.celular[strcspn(c.celular, "\n")] = 0;

  printf("Endereco completo: ");
  fgets(c.endereco, 150, stdin);
  c.endereco[strcspn(c.endereco, "\n")] = 0;

  clientes[qtdClientes++] = c;

  printf("\nCliente cadastrado!");
  pause();
}

void listarClientes() {
  titulo("Listagem de Clientes");

  for (int i = 0; i < qtdClientes; i++) {
    printf("%d - %s | %d/%d | Fone: %s\n",
           clientes[i].codigo,
           clientes[i].nome,
           clientes[i].nascimento.dia,
           clientes[i].nascimento.mes,
           clientes[i].fone);
  }

  pause();
}

void cadastrarAtendimento() {
  titulo("Cadastro de Atendimento");

  if (qtdAtendimentos >= MAX_ATENDIMENTOS) {
    printf("Limite atingido!");
    pause();
    return;
  }

  struct Atendimento a;

  printf("Numero do atendimento: ");
  scanf("%d", &a.numero);

  printf("Matricula do profissional: ");
  scanf("%d", &a.prof_matricula);

  printf("Codigo do cliente: ");
  scanf("%d", &a.cliente_codigo);

  printf("Data do atendimento:\n");
  a.data = lerData();

  printf("Descricao: ");
  getchar();
  fgets(a.descricao, 200, stdin);
  a.descricao[strcspn(a.descricao, "\n")] = 0;

  atendimentos[qtdAtendimentos++] = a;

  printf("\nAtendimento cadastrado!");
  pause();
}

void listarAtendimentos() {
  titulo("Atendimentos");

  for (int i = 0; i < qtdAtendimentos; i++) {
    printf("%d - Prof:%d Cliente:%d | %d/%d/%d\n",
           atendimentos[i].numero,
           atendimentos[i].prof_matricula,
           atendimentos[i].cliente_codigo,
           atendimentos[i].data.dia,
           atendimentos[i].data.mes,
           atendimentos[i].data.ano);
  }

  pause();
}

void relAniversariantesProfissionais() {
  titulo("Aniversariantes Profissionais");

  int mes;
  printf("Digite o mes: ");
  scanf("%d", &mes);

  printf("\n");

  for (int i = 0; i < qtdProfissionais; i++) {
    if (profissionais[i].nascimento.mes == mes) {
      printf("%s - %d/%d\n",
             profissionais[i].nome,
             profissionais[i].nascimento.dia,
             profissionais[i].nascimento.mes);
    }
  }

  pause();
}

void relAniversariantesClientes() {
  titulo("Aniversariantes Clientes");

  int mes;
  printf("Digite o mes: ");
  scanf("%d", &mes);

  for (int i = 0; i < qtdClientes; i++) {
    if (clientes[i].nascimento.mes == mes) {
      printf("%s - %d/%d | Fone:%s | Cel:%s | Email:%s\n",
             clientes[i].nome,
             clientes[i].nascimento.dia,
             clientes[i].nascimento.mes,
             clientes[i].fone,
             clientes[i].celular,
             clientes[i].email);
    }
  }

  pause();
}

void relAtendimentosPorPeriodo() {
  titulo("Atendimentos por Periodo");

  struct Data ini, fim;

  printf("Data inicial:\n");
  ini = lerData();

  printf("\nData final:\n");
  fim = lerData();

  printf("\n");

  for (int i = 0; i < qtdAtendimentos; i++) {
    struct Data d = atendimentos[i].data;

    if (
        (d.ano > ini.ano || (d.ano == ini.ano && (d.mes > ini.mes || (d.mes == ini.mes && d.dia >= ini.dia)))) &&
        (d.ano < fim.ano || (d.ano == fim.ano && (d.mes < fim.mes || (d.mes == fim.mes && d.dia <= fim.dia)))))
    {
      printf("Num: %d | Prof:%d | Cliente:%d | %d/%d/%d\n",
             atendimentos[i].numero,
             atendimentos[i].prof_matricula,
             atendimentos[i].cliente_codigo,
             d.dia, d.mes, d.ano);
    }
  }

  pause();
}

void relAtendimentoPorMes() {
  titulo("Atendimento por mes");

  int ano;
  printf("Digite o ano: ");
  scanf("%d", &ano);

  int meses[13] = {0};

  for (int i = 0; i < qtdAtendimentos; i++) {
    if (atendimentos[i].data.ano == ano) {
      meses[atendimentos[i].data.mes]++;
    }
  }

  printf("\nMes | Quantidade\n");
  for (int m = 1; m <= 12; m++) {
    printf("%02d | %d\n", m, meses[m]);
  }

  pause();
}

void relEstatisticaPorProfissional() {
  titulo("Estatistica por Profissional");

  int mat;
  printf("Matricula do profissional: ");
  scanf("%d", &mat);

  int total = 0;

  for (int i = 0; i < qtdAtendimentos; i++) {
    if (atendimentos[i].prof_matricula == mat) total++;
  }

  printf("\nTotal de atendimentos: %d\n", total);
  pause();
}

void menu() {
  int op;

  do {
    titulo("SISTEMA DE SAUDE");

    printf("[1] Cadastrar Profissao\n");
    printf("[2] Cadastrar Profissional\n");
    printf("[3] Cadastrar Cliente\n");
    printf("[4] Cadastrar Atendimento\n");
    printf("[5] Listar Profissoes\n");
    printf("[6] Listar Profissionais\n");
    printf("[7] Listar Clientes\n");
    printf("[8] Listar Atendimentos\n");
    printf("[9] Rel: Aniversariantes Profissionais\n");
    printf("[10] Rel: Aniversariantes Clientes\n");
    printf("[11] Rel: Atendimentos por Periodo\n");
    printf("[12] Rel: Atendimentos por Mes de um Ano\n");
    printf("[13] Rel: Estatistica por Profissional\n");
    printf("[0] Sair\n");
    printf("\nEscolha: ");
    scanf("%d", &op);

    switch (op) {
      case 1: cadastrarProfissao(); break;
      case 2: cadastrarProfissional(); break;
      case 3: cadastrarCliente(); break;
      case 4: cadastrarAtendimento(); break;
      case 5: listarProfissoes(); break;
      case 6: listarProfissionais(); break;
      case 7: listarClientes(); break;
      case 8: listarAtendimentos(); break;
      case 9: relAniversariantesProfissionais(); break;
      case 10: relAniversariantesClientes(); break;
      case 11: relAtendimentosPorPeriodo(); break;
      case 12: relAtendimentoPorMes(); break;
      case 13: relEstatisticaPorProfissional(); break;
      case 0: printf("Encerrando..."); break;
      default:
        printf("Opcao invalida!");
        pause();
    }
  } while (op != 0);
}

int main() {
  menu();
  return 0;
}
