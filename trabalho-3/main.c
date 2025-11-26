#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROFISSOES 50
#define MAX_PROFISSIONAIS 200
#define MAX_CLIENTES 300
#define MAX_ATENDIMENTOS 2000

#define ARQ_PROFISSOES     "profissoes.dat"
#define ARQ_PROFISSIONAIS  "profissionais.dat"
#define ARQ_CLIENTES       "clientes.dat"
#define ARQ_ATENDIMENTOS   "atendimentos.dat"

struct Data {
  int dia, mes, ano;
};

struct Endereco {
  char logradouro[80];
  char numero[10];
  char bairro[50];
  char cidade[50];
  char estado[3];
  char cep[15];
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
  struct Endereco endereco;
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

void limparEntrada() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {}
}

void lerLinha(char s[], int tam) {
  if (tam <= 0) return;
  fgets(s, tam, stdin);
  s[strcspn(s, "\n")] = 0;
}

int lerInt(const char prompt[]) {
  int x;
  int ok = 0;
  do {
    printf("%s", prompt);
    if (scanf("%d", &x) == 1) {
      ok = 1;
    } else {
      printf("Entrada invalida. Digite um numero.\n");
    }
    limparEntrada();
  } while (!ok);
  return x;
}

struct Data lerData() {
  struct Data d;
  int valida = 0;
  do {
    printf("Dia: ");
    scanf("%d", &d.dia);
    printf("Mes: ");
    scanf("%d", &d.mes);
    printf("Ano: ");
    scanf("%d", &d.ano);
    limparEntrada();
    if (d.dia < 1 || d.dia > 31 || d.mes < 1 || d.mes > 12 || d.ano < 1900) {
      printf("Data invalida. Digite novamente.\n");
    } else {
      valida = 1;
    }
  } while (!valida);
  return d;
}

int compararDatas(struct Data d1, struct Data d2) {
  if (d1.ano < d2.ano) return -1;
  if (d1.ano > d2.ano) return 1;
  if (d1.mes < d2.mes) return -1;
  if (d1.mes > d2.mes) return 1;
  if (d1.dia < d2.dia) return -1;
  if (d1.dia > d2.dia) return 1;
  return 0;
}

int dataEstaNoPeriodo(struct Data d, struct Data ini, struct Data fim) {
  return (compararDatas(d, ini) >= 0 && compararDatas(d, fim) <= 0);
}


int indiceProfissaoPorCodigo(int codigo) {
  int i;
  for (i = 0; i < qtdProfissoes; i++) {
    if (profissoes[i].codigo == codigo) return i;
  }
  return -1;
}

int indiceProfissionalPorMatricula(int mat) {
  int i;
  for (i = 0; i < qtdProfissionais; i++) {
    if (profissionais[i].matricula == mat) return i;
  }
  return -1;
}

int indiceClientePorCodigo(int cod) {
  int i;
  for (i = 0; i < qtdClientes; i++) {
    if (clientes[i].codigo == cod) return i;
  }
  return -1;
}

int indiceAtendimentoPorNumero(int num) {
  int i;
  for (i = 0; i < qtdAtendimentos; i++) {
    if (atendimentos[i].numero == num) return i;
  }
  return -1;
}


void mostrarProfissoes() {
  int i;
  printf("\n--- Lista Profissoes ---\n");
  for (i = 0; i < qtdProfissoes; i++) {
    printf("Cod: %d | Nome: %s | Sigla: %s\n",
           profissoes[i].codigo,
           profissoes[i].nome,
           profissoes[i].sigla);
  }
}

void mostrarProfissionais() {
  int i;
  printf("\n--- Lista Profissionais ---\n");
  for (i = 0; i < qtdProfissionais; i++) {
    printf("Mat: %d | Nome: %s\n",
           profissionais[i].matricula,
           profissionais[i].nome);
  }
}

void mostrarClientes() {
  int i;
  printf("\n--- Lista Clientes ---\n");
  for (i = 0; i < qtdClientes; i++) {
    printf("Cod: %d | Nome: %s\n",
           clientes[i].codigo,
           clientes[i].nome);
  }
}

int profissaoEmUso(int codProfissao) {
  int i;
  for (i = 0; i < qtdProfissionais; i++) {
    if (profissionais[i].prof_codigo == codProfissao) return 1;
  }
  return 0;
}

int profissionalTemAtendimentos(int mat) {
  int i;
  for (i = 0; i < qtdAtendimentos; i++) {
    if (atendimentos[i].prof_matricula == mat) return 1;
  }
  return 0;
}

int clienteTemAtendimentos(int cod) {
  int i;
  for (i = 0; i < qtdAtendimentos; i++) {
    if (atendimentos[i].cliente_codigo == cod) return 1;
  }
  return 0;
}


void salvarProfissoesEmArquivo() {
  FILE *f = fopen(ARQ_PROFISSOES, "wb");
  if (f == NULL) return;
  fwrite(profissoes, sizeof(struct Profissao), qtdProfissoes, f);
  fclose(f);
}

void salvarProfissionaisEmArquivo() {
  FILE *f = fopen(ARQ_PROFISSIONAIS, "wb");
  if (f == NULL) return;
  fwrite(profissionais, sizeof(struct Profissional), qtdProfissionais, f);
  fclose(f);
}

void salvarClientesEmArquivo() {
  FILE *f = fopen(ARQ_CLIENTES, "wb");
  if (f == NULL) return;
  fwrite(clientes, sizeof(struct Cliente), qtdClientes, f);
  fclose(f);
}

void salvarAtendimentosEmArquivo() {
  FILE *f = fopen(ARQ_ATENDIMENTOS, "wb");
  if (f == NULL) return;
  fwrite(atendimentos, sizeof(struct Atendimento), qtdAtendimentos, f);
  fclose(f);
}

void carregarProfissoesDeArquivo() {
  FILE *f = fopen(ARQ_PROFISSOES, "rb");
  if (f == NULL) {
    qtdProfissoes = 0;
    return;
  }
  qtdProfissoes = (int)fread(profissoes, sizeof(struct Profissao), MAX_PROFISSOES, f);
  fclose(f);
}

void carregarProfissionaisDeArquivo() {
  FILE *f = fopen(ARQ_PROFISSIONAIS, "rb");
  if (f == NULL) {
    qtdProfissionais = 0;
    return;
  }
  qtdProfissionais = (int)fread(profissionais, sizeof(struct Profissional), MAX_PROFISSIONAIS, f);
  fclose(f);
}

void carregarClientesDeArquivo() {
  FILE *f = fopen(ARQ_CLIENTES, "rb");
  if (f == NULL) {
    qtdClientes = 0;
    return;
  }
  qtdClientes = (int)fread(clientes, sizeof(struct Cliente), MAX_CLIENTES, f);
  fclose(f);
}

void carregarAtendimentosDeArquivo() {
  FILE *f = fopen(ARQ_ATENDIMENTOS, "rb");
  if (f == NULL) {
    qtdAtendimentos = 0;
    return;
  }
  qtdAtendimentos = (int)fread(atendimentos, sizeof(struct Atendimento), MAX_ATENDIMENTOS, f);
  fclose(f);
}

void inicializarDados() {
  carregarProfissoesDeArquivo();
  carregarProfissionaisDeArquivo();
  carregarClientesDeArquivo();
  carregarAtendimentosDeArquivo();
}

void cadastrarProfissao() {
  struct Profissao p;
  titulo("Cadastro de Profissao");
  if (qtdProfissoes >= MAX_PROFISSOES) {
    printf("Limite atingido.");
    pause();
    return;
  }
  p.codigo = lerInt("Codigo (0 cancela): ");
  if (p.codigo == 0) return;
  if (indiceProfissaoPorCodigo(p.codigo) != -1) {
    printf("Codigo ja existe.\n");
    pause();
    return;
  }
  printf("Nome: ");
  lerLinha(p.nome, 50);
  printf("Sigla: ");
  lerLinha(p.sigla, 10);
  profissoes[qtdProfissoes++] = p;
  salvarProfissoesEmArquivo();
  printf("Sucesso!");
  pause();
}

void editarProfissao() {
  int cod, idx;
  titulo("Editar Profissao");
  mostrarProfissoes();
  cod = lerInt("\nCodigo da profissao para editar: ");
  idx = indiceProfissaoPorCodigo(cod);
  if (idx == -1) {
    printf("Nao encontrado.");
    pause();
    return;
  }
  printf("Novo Nome: ");
  lerLinha(profissoes[idx].nome, 50);
  printf("Nova Sigla: ");
  lerLinha(profissoes[idx].sigla, 10);
  salvarProfissoesEmArquivo();
  printf("Atualizado com sucesso!");
  pause();
}

void excluirProfissao() {
  int cod, idx, i;
  titulo("Excluir Profissao");
  mostrarProfissoes();
  cod = lerInt("\nCodigo da profissao para excluir: ");
  idx = indiceProfissaoPorCodigo(cod);
  if (idx == -1) {
    printf("Nao encontrado.");
    pause();
    return;
  }
  if (profissaoEmUso(cod)) {
    printf("ERRO: Existem profissionais cadastrados com esta profissao.\nExclusao negada.");
    pause();
    return;
  }
  for (i = idx; i < qtdProfissoes - 1; i++) {
    profissoes[i] = profissoes[i + 1];
  }
  qtdProfissoes--;
  salvarProfissoesEmArquivo();
  printf("Profissao excluida.");
  pause();
}


void cadastrarProfissional() {
  struct Profissional p;
  titulo("Cadastro de Profissional");
  if (qtdProfissoes == 0) {
    printf("Cadastre uma profissao antes.");
    pause();
    return;
  }
  if (qtdProfissionais >= MAX_PROFISSIONAIS) {
    printf("Limite atingido.");
    pause();
    return;
  }
  p.matricula = lerInt("Matricula (0 cancela): ");
  if (p.matricula == 0) return;
  if (indiceProfissionalPorMatricula(p.matricula) != -1) {
    printf("Matricula ja existe.");
    pause();
    return;
  }
  printf("CPF: ");
  lerLinha(p.cpf, 20);
  printf("Nome: ");
  lerLinha(p.nome, 80);
  printf("Email: ");
  lerLinha(p.email, 80);
  printf("Fone: ");
  lerLinha(p.fone, 20);
  mostrarProfissoes();
  p.prof_codigo = lerInt("Codigo da Profissao: ");
  while (indiceProfissaoPorCodigo(p.prof_codigo) == -1) {
    printf("Profissao invalida. Tente novamente: ");
    scanf("%d", &p.prof_codigo);
    limparEntrada();
  }
  printf("Num RP: ");
  lerLinha(p.numRP, 20);
  printf("Tipo (Medico, Enfermeiro...): ");
  lerLinha(p.tipo, 40);
  printf("Data Nascimento:\n");
  p.nascimento = lerData();
  profissionais[qtdProfissionais++] = p;
  salvarProfissionaisEmArquivo();
  printf("Sucesso!");
  pause();
}

void editarProfissional() {
  int mat, idx;
  titulo("Editar Profissional");
  mat = lerInt("Digite a matricula do profissional: ");
  idx = indiceProfissionalPorMatricula(mat);
  if (idx == -1) {
    printf("Nao encontrado.");
    pause();
    return;
  }
  printf("Editando: %s\n", profissionais[idx].nome);
  printf("Novo Nome: ");
  lerLinha(profissionais[idx].nome, 80);
  printf("Novo Email: ");
  lerLinha(profissionais[idx].email, 80);
  printf("Novo Fone: ");
  lerLinha(profissionais[idx].fone, 20);
  printf("Novo Tipo: ");
  lerLinha(profissionais[idx].tipo, 40);
  salvarProfissionaisEmArquivo();
  printf("Dados atualizados!");
  pause();
}

void excluirProfissional() {
  int mat, idx, i;
  titulo("Excluir Profissional");
  mat = lerInt("Digite a matricula para excluir: ");
  idx = indiceProfissionalPorMatricula(mat);
  if (idx == -1) {
    printf("Nao encontrado.");
    pause();
    return;
  }
  if (profissionalTemAtendimentos(mat)) {
    printf("ERRO: Este profissional possui atendimentos registrados.\nExclusao negada para manter historico.");
    pause();
    return;
  }
  for (i = idx; i < qtdProfissionais - 1; i++) {
    profissionais[i] = profissionais[i + 1];
  }
  qtdProfissionais--;
  salvarProfissionaisEmArquivo();
  printf("Profissional excluido.");
  pause();
}


void cadastrarCliente() {
  struct Cliente c;
  titulo("Cadastro de Cliente");
  if (qtdClientes >= MAX_CLIENTES) {
    printf("Limite atingido.");
    pause();
    return;
  }
  c.codigo = lerInt("Codigo (0 cancela): ");
  if (c.codigo == 0) return;
  if (indiceClientePorCodigo(c.codigo) != -1) {
    printf("Codigo ja existe.");
    pause();
    return;
  }
  printf("Nome: ");
  lerLinha(c.nome, 80);
  printf("Data Nascimento:\n");
  c.nascimento = lerData();
  c.idade = lerInt("Idade: ");
  printf("Email: ");
  lerLinha(c.email, 80);
  printf("Fone: ");
  lerLinha(c.fone, 20);
  printf("Celular: ");
  lerLinha(c.celular, 20);
  printf("\n--- Endereco ---\n");
  printf("Logradouro (Rua/Av): ");
  lerLinha(c.endereco.logradouro, 80);
  printf("Numero: ");
  lerLinha(c.endereco.numero, 10);
  printf("Bairro: ");
  lerLinha(c.endereco.bairro, 50);
  printf("Cidade: ");
  lerLinha(c.endereco.cidade, 50);
  printf("Estado (UF): ");
  lerLinha(c.endereco.estado, 3);
  printf("CEP: ");
  lerLinha(c.endereco.cep, 15);
  clientes[qtdClientes++] = c;
  salvarClientesEmArquivo();
  printf("Sucesso!");
  pause();
}

void editarCliente() {
  int cod, idx;
  titulo("Editar Cliente");
  cod = lerInt("Codigo do cliente: ");
  idx = indiceClientePorCodigo(cod);
  if (idx == -1) {
    printf("Nao encontrado.");
    pause();
    return;
  }
  printf("Editando: %s\n", clientes[idx].nome);
  printf("Novo Nome: ");
  lerLinha(clientes[idx].nome, 80);
  printf("Novo Email: ");
  lerLinha(clientes[idx].email, 80);
  printf("Novo Celular: ");
  lerLinha(clientes[idx].celular, 20);
  printf("--- Atualizar Endereco ---\n");
  printf("Novo Logradouro: ");
  lerLinha(clientes[idx].endereco.logradouro, 80);
  printf("Novo Numero: ");
  lerLinha(clientes[idx].endereco.numero, 10);
  printf("Novo Bairro: ");
  lerLinha(clientes[idx].endereco.bairro, 50);
  salvarClientesEmArquivo();
  printf("Dados atualizados!");
  pause();
}

void excluirCliente() {
  int cod, idx, i;
  titulo("Excluir Cliente");
  cod = lerInt("Codigo do cliente para excluir: ");
  idx = indiceClientePorCodigo(cod);
  if (idx == -1) {
    printf("Nao encontrado.");
    pause();
    return;
  }
  if (clienteTemAtendimentos(cod)) {
    printf("ERRO: Este cliente possui atendimentos registrados.\nExclusao negada.");
    pause();
    return;
  }
  for (i = idx; i < qtdClientes - 1; i++) {
    clientes[i] = clientes[i + 1];
  }
  qtdClientes--;
  salvarClientesEmArquivo();
  printf("Cliente excluido.");
  pause();
}


void cadastrarAtendimento() {
  struct Atendimento a;
  titulo("Novo Atendimento");
  if (qtdAtendimentos >= MAX_ATENDIMENTOS) {
    printf("Limite atingido.");
    pause();
    return;
  }
  if (qtdProfissionais == 0 || qtdClientes == 0) {
    printf("Faltam cadastros previos.");
    pause();
    return;
  }
  a.numero = lerInt("Numero Atendimento (0 cancela): ");
  if (a.numero == 0) return;
  if (indiceAtendimentoPorNumero(a.numero) != -1) {
    printf("Numero ja existe.");
    pause();
    return;
  }
  mostrarProfissionais();
  a.prof_matricula = lerInt("Matricula Profissional: ");
  while (indiceProfissionalPorMatricula(a.prof_matricula) == -1) {
    printf("Invalido. Digite novamente: ");
    scanf("%d", &a.prof_matricula);
    limparEntrada();
  }
  mostrarClientes();
  a.cliente_codigo = lerInt("Codigo Cliente: ");
  while (indiceClientePorCodigo(a.cliente_codigo) == -1) {
    printf("Invalido. Digite novamente: ");
    scanf("%d", &a.cliente_codigo);
    limparEntrada();
  }
  printf("Data Atendimento:\n");
  a.data = lerData();
  printf("Descricao: ");
  lerLinha(a.descricao, 200);
  atendimentos[qtdAtendimentos++] = a;
  salvarAtendimentosEmArquivo();
  printf("Sucesso!");
  pause();
}

void editarAtendimento() {
  int num, idx;
  titulo("Editar Atendimento");
  num = lerInt("Numero do atendimento: ");
  idx = indiceAtendimentoPorNumero(num);
  if (idx == -1) {
    printf("Nao encontrado.");
    pause();
    return;
  }
  printf("Nova Descricao: ");
  lerLinha(atendimentos[idx].descricao, 200);
  printf("Nova Data:\n");
  atendimentos[idx].data = lerData();
  salvarAtendimentosEmArquivo();
  printf("Atualizado!");
  pause();
}

void excluirAtendimento() {
  int num, idx, i;
  titulo("Excluir Atendimento");
  num = lerInt("Numero do atendimento: ");
  idx = indiceAtendimentoPorNumero(num);
  if (idx == -1) {
    printf("Nao encontrado.");
    pause();
    return;
  }
  for (i = idx; i < qtdAtendimentos - 1; i++) {
    atendimentos[i] = atendimentos[i + 1];
  }
  qtdAtendimentos--;
  salvarAtendimentosEmArquivo();
  printf("Atendimento excluido.");
  pause();
}


void relListagemProfissionais() {
  int i;
  titulo("Relatorio: Lista de Profissionais");
  for (i = 0; i < qtdProfissionais; i++) {
    printf("Mat: %d | Nome: %s | Tipo: %s\n",
           profissionais[i].matricula,
           profissionais[i].nome,
           profissionais[i].tipo);
  }
  pause();
}

void relAniversariantes() {
  int mes, i, achou = 0;
  titulo("Aniversariantes da Instituicao (Profissionais)");
  mes = lerInt("Mes (1-12): ");
  for (i = 0; i < qtdProfissionais; i++) {
    if (profissionais[i].nascimento.mes == mes) {
      printf("%s - %02d/%02d\n",
             profissionais[i].nome,
             profissionais[i].nascimento.dia,
             profissionais[i].nascimento.mes);
      achou = 1;
    }
  }
  if (!achou) printf("Ninguem encontrado.");
  pause();
}

void relAtendimentoGeral() {
  int i, idxProf, idxCli;
  const char *nomeProf;
  const char *nomeCli;
  titulo("Relatorio: Atendimento Geral");
  for (i = 0; i < qtdAtendimentos; i++) {
    idxProf = indiceProfissionalPorMatricula(atendimentos[i].prof_matricula);
    idxCli = indiceClientePorCodigo(atendimentos[i].cliente_codigo);
    nomeProf = (idxProf != -1) ? profissionais[idxProf].nome : "Desc.";
    nomeCli = (idxCli != -1) ? clientes[idxCli].nome : "Desc.";
    printf("Cli: %-20s | Prof: %-20s | Data: %02d/%02d/%04d\n",
           nomeCli,
           nomeProf,
           atendimentos[i].data.dia,
           atendimentos[i].data.mes,
           atendimentos[i].data.ano);
  }
  pause();
}

void relAtendimentoPorPeriodo() {
  int i, idxProf, idxCli;
  struct Data ini, fim;
  const char *nomeProf;
  const char *nomeCli;
  titulo("Relatorio: Atendimentos por Periodo");
  printf("Data Inicial:\n");
  ini = lerData();
  printf("Data Final:\n");
  fim = lerData();
  printf("\n");
  for (i = 0; i < qtdAtendimentos; i++) {
    if (dataEstaNoPeriodo(atendimentos[i].data, ini, fim)) {
      idxProf = indiceProfissionalPorMatricula(atendimentos[i].prof_matricula);
      idxCli = indiceClientePorCodigo(atendimentos[i].cliente_codigo);
      nomeProf = (idxProf != -1) ? profissionais[idxProf].nome : "Desc.";
      nomeCli = (idxCli != -1) ? clientes[idxCli].nome : "Desc.";
      printf("%02d/%02d/%04d | Cli: %s | Prof: %s\n",
             atendimentos[i].data.dia,
             atendimentos[i].data.mes,
             atendimentos[i].data.ano,
             nomeCli,
             nomeProf);
    }
  }
  pause();
}

void relAtendimentosPorMesAno() {
  int ano, contadores[13], i, m;
  titulo("Estatistica: Atendimentos por Mes/Ano");
  ano = lerInt("Digite o ano: ");
  for (i = 0; i < 13; i++) contadores[i] = 0;
  for (i = 0; i < qtdAtendimentos; i++) {
    if (atendimentos[i].data.ano == ano) {
      contadores[atendimentos[i].data.mes]++;
    }
  }
  for (m = 1; m <= 12; m++) {
    printf("Mes %02d: %d atendimentos\n", m, contadores[m]);
  }
  pause();
}

void relEstatisticaProfissionalPeriodo() {
  int p, a, count;
  struct Data ini, fim;
  titulo("Estatistica por Profissional (Periodo)");
  printf("Data Inicial:\n");
  ini = lerData();
  printf("Data Final:\n");
  fim = lerData();
  printf("\n%-30s | %s\n", "Profissional", "Qtd Atendimentos");
  printf("----------------------------------------------\n");
  for (p = 0; p < qtdProfissionais; p++) {
    count = 0;
    for (a = 0; a < qtdAtendimentos; a++) {
      if (atendimentos[a].prof_matricula == profissionais[p].matricula) {
        if (dataEstaNoPeriodo(atendimentos[a].data, ini, fim)) {
          count++;
        }
      }
    }
    if (count > 0) {
      printf("%-30s | %d\n", profissionais[p].nome, count);
    }
  }
  pause();
}

void relAniversariantesClientes() {
  int mes, i;
  titulo("Aniversariantes Clientes");
  mes = lerInt("Mes (1-12): ");
  for (i = 0; i < qtdClientes; i++) {
    if (clientes[i].nascimento.mes == mes) {
      printf("%s (%02d/%02d) | Fone: %s | Email: %s | Cel: %s\n",
             clientes[i].nome,
             clientes[i].nascimento.dia,
             clientes[i].nascimento.mes,
             clientes[i].fone,
             clientes[i].email,
             clientes[i].celular);
    }
  }
  pause();
}

void menuProfissoes() {
  int op;
  do {
    titulo("GESTAO DE PROFISSOES");
    printf("1. Cadastrar\n");
    printf("2. Editar\n");
    printf("3. Excluir\n");
    printf("4. Listar\n");
    printf("0. Voltar\n");
    op = lerInt("Opcao: ");
    switch (op) {
      case 1: cadastrarProfissao(); break;
      case 2: editarProfissao(); break;
      case 3: excluirProfissao(); break;
      case 4: mostrarProfissoes(); pause(); break;
    }
  } while (op != 0);
}

void menuProfissionais() {
  int op;
  do {
    titulo("GESTAO DE PROFISSIONAIS");
    printf("1. Cadastrar\n");
    printf("2. Editar\n");
    printf("3. Excluir\n");
    printf("4. Listar\n");
    printf("0. Voltar\n");
    op = lerInt("Opcao: ");
    switch (op) {
      case 1: cadastrarProfissional(); break;
      case 2: editarProfissional(); break;
      case 3: excluirProfissional(); break;
      case 4: mostrarProfissionais(); pause(); break;
    }
  } while (op != 0);
}

void menuClientes() {
  int op;
  do {
    titulo("GESTAO DE CLIENTES");
    printf("1. Cadastrar\n");
    printf("2. Editar\n");
    printf("3. Excluir\n");
    printf("4. Listar\n");
    printf("0. Voltar\n");
    op = lerInt("Opcao: ");
    switch (op) {
      case 1: cadastrarCliente(); break;
      case 2: editarCliente(); break;
      case 3: excluirCliente(); break;
      case 4: mostrarClientes(); pause(); break;
    }
  } while (op != 0);
}

void menuAtendimentos() {
  int op;
  do {
    titulo("GESTAO DE ATENDIMENTOS");
    printf("1. Novo Atendimento\n");
    printf("2. Editar\n");
    printf("3. Excluir\n");
    printf("4. Listar Todos (Detalhado)\n");
    printf("0. Voltar\n");
    op = lerInt("Opcao: ");
    switch (op) {
      case 1: cadastrarAtendimento(); break;
      case 2: editarAtendimento(); break;
      case 3: excluirAtendimento(); break;
      case 4: relAtendimentoGeral(); break;
    }
  } while (op != 0);
}

void menuRelatorios() {
  int op;
  do {
    titulo("RELATORIOS GERENCIAIS");
    printf("1. Listagem de Profissionais (Completa)\n");
    printf("2. Aniversariantes da Instituicao (Profissionais)\n");
    printf("3. Atendimento Geral\n");
    printf("4. Atendimento por Periodo\n");
    printf("5. Estatistica Mensal (Ano)\n");
    printf("6. Estatistica por Profissional (Periodo)\n");
    printf("7. Aniversariantes Clientes\n");
    printf("0. Voltar\n");
    op = lerInt("Opcao: ");
    switch (op) {
      case 1: relListagemProfissionais(); break;
      case 2: relAniversariantes(); break;
      case 3: relAtendimentoGeral(); break;
      case 4: relAtendimentoPorPeriodo(); break;
      case 5: relAtendimentosPorMesAno(); break;
      case 6: relEstatisticaProfissionalPeriodo(); break;
      case 7: relAniversariantesClientes(); break;
    }
  } while (op != 0);
}


int main() {
  int op;
  inicializarDados();

  do {
    titulo("SISTEMA DE SAUDE (Trabalho 2 - IFAM)");
    printf("1. Profissoes\n");
    printf("2. Profissionais\n");
    printf("3. Clientes\n");
    printf("4. Atendimentos\n");
    printf("5. Relatorios\n");
    printf("0. Sair\n");
    op = lerInt("Escolha: ");
    switch (op) {
      case 1: menuProfissoes(); break;
      case 2: menuProfissionais(); break;
      case 3: menuClientes(); break;
      case 4: menuAtendimentos(); break;
      case 5: menuRelatorios(); break;
      case 0:
        printf("Encerrando...\n");
        break;
      default:
        printf("Invalido!");
        pause();
    }
  } while (op != 0);

  salvarProfissoesEmArquivo();
  salvarProfissionaisEmArquivo();
  salvarClientesEmArquivo();
  salvarAtendimentosEmArquivo();

  return 0;
}
