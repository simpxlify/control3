#include <conio.h>
#include <ctype.h>
#include <dir.h>
#include <dirent.h>
#include <locale.h>
#include <math.h>
#include <process.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <windows.h>
#pragma warning(disable: 4996);

int i, j;
int voltar_menu;
void menu();
struct data {
int mes, dia, ano;
};
typedef struct todos_users {
		char password[20];
		int data_nascimento;
		double nr_telemovel;
}todos_users;

struct {
	char nome[60];
	int nr_de_conta, idade, nif, certidao;
	char morada[60];
	char nacionalidade[15];
	double nr_telemovel;
	char acc_type[10];
	char registo_criminal[10];
	char genero[20];
	char email[20];
	char passaporte[20];
	char estado_civil[20];
	char profissao[20];
	float dinheiro;
	struct data acm;
	struct data deposito;
	struct data levantamento;
}adicionar, alterar, verificar, eliminar, transacoes;


bool loginGestorBalcao(char NOME[20]) { //Login do Gstor de Balcão

  FILE * fp;
  int i=1, num, encont = 0, a;
  char c[20], pass[20], name[20];
  char GestBalcao[13] = "GestBalcao ";

  todos_users x;

  strcat(GestBalcao, NOME);
  strcat(GestBalcao, ".dat");

  fp = fopen(GestBalcao, "rb");

  if (fp == NULL) {
    puts("\n\n\t Esse user nao existe \t\n\n");
    system("pause");
    system("cls");
    return false;

  } else {

    puts("\nInsira a Palavra-passe: ");
    fflush(stdin);
    scanf("%s", & pass);

    fscanf(fp,"%s %s %d %d",&(x).password,&(x).nr_telemovel,&(x).data_nascimento);

    while (i == 1) {
      if ((strcmp(pass, x.password) == 0)) {
        system("pause");
        system("cls");

        printf("\n\nUtilizador autenticado com sucesso,\n\t\t Bem Vindo %s \n\n", NOME);

        system("pause");
        system("cls");
	i=0;
        return true;

        system("pause");
        system("cls");
      } else {

        puts("\n\n PALAVRA-PASSE INVÁLIDA, Tente novamente \n\n");

        system("pause");
        system("cls");
        system("exit");

        return false;
      }
    }
  }
}


bool loginGestorConta(char NOME[20]) { //Login do Gestor de Conta

  FILE * fp;
  int i=1;
  char pass[20];
  char GestConta[12] = "GestConta ";

  todos_users x;

  strcat(GestConta, NOME);
  strcat(GestConta, ".dat");

  fp = fopen(GestConta, "rb");

  if (fp == NULL) {
    puts("\n\n\t Esse user nao existe \t\n\n");
    system("pause");
    system("cls");

    return false;
  } 
  else {

    puts("\nInsira a Palavra-passe: ");
    fflush(stdin);
    scanf("%s", & pass);

    fscanf(fp,"%s %s %d %d",&(x).password,&(x).nr_telemovel,&(x).data_nascimento);

    while (i == 1) {
      if ((strcmp(pass, x.password) == 0)) {
        system("pause");
        system("cls");

        printf("\n\nUtilizador autenticado com sucesso,\n\t\t Bem Vindo %s \n\n", NOME);

        system("pause");
        system("cls");
		i=0;
        return true;
      } else {

        puts("\n\n Palavra passe errada, tente novamente \n\n");

        system("pause");
        system("cls");
        system("exit");

        return false;
      }
    }
  }
}
bool loginGestorMarketing(char NOME[20]) { //Login do Gestor de Marketing

  FILE * fp;
  int i=1;
  char pass[20], name[20];
  char GestMark[11] = "GestMark ";

  todos_users x;

  strcat(GestMark, NOME);
  strcat(GestMark, ".dat");

  fp = fopen(GestMark, "rb");
  if (fp == NULL) {
    puts("\n\n\t Esse user nao existe \t\n\n");

    system("pause");
    system("cls");

    return false;
  } else {

    puts("\nInsira a Palavra-passe: ");
    fflush(stdin);
    scanf("%s", & pass);
    fscanf(fp,"%s %s %d %d",&(x).password,&(x).nr_telemovel,&(x).data_nascimento);

   
    while (i == 1) {
      if ((strcmp(pass, x.password) == 0)) {
        system("pause");
        system("cls");

        printf("\n\nUtilizador autenticado com sucesso,\n\t\t Bem Vindo %s \n\n", NOME);

        system("pause");
        system("cls");
i=0;
        return true;
      } 
	  else {

        puts("\n\n PALAVRA-PASSE INVÁLIDA, Tente novamente \n\n");

        system("pause");
        system("cls");
        system("exit");

        return false;
      }
    }
  }
}

bool loginAdmin(char NOME[20]) { //Login do Administrador

  FILE * fp;
  int i=1;
  char pass[20], name[20];
  char admin[8] = "Admin ";

  todos_users x;
  strcat(admin, NOME);
  strcat(admin, ".dat"); // Pega no Admin e ve o nome digitado, e adiciona a isso tudo um .dat

  fp = fopen(admin, "r+"); // abre o ficheiro em modo leitura de binario

  if (fp == NULL) { // verifica se tem um ficheiro criado
    puts("\n\n\t Esse user nao existe! \t\n\n");
    system("pause");
    system("cls");

    return false;
  } 
  else { // senão pede a palavra-passe, abre o arquivo em modo de leitura e compara a password guardada no ficheiro com o que foi digitado

    puts("\nInsira a Palavra-passe: ");
    fflush(stdin);
    scanf("%s", & pass);
		
    fscanf(fp,"%s %s %d %d",&(x).password,&(x).nr_telemovel,&(x).data_nascimento);
     
    while (i == 1) {
      if ((strcmp(pass, x.password) == 0)) {
        system("pause");
        system("cls");

        printf("\n\nUtilizador autenticado com sucesso,\n\t\t\t Bem Vindo %s \n\n", NOME);

        system("pause");
        system("cls");
		i=0;
        return true;
      } 
	  else {

        puts("\n\n PALAVRA-PASSE INVÁLIDA, Tente novamente \n\n");

        system("pause");
        system("cls");
        system("exit");

        return false;
      }

    }
  }
}

void listar_conteudo_pastas () { // lista os ficheiros dentro de um diretorio
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("D:\\Desktop\\")) != NULL) {
  	while ((ent = readdir (dir)) != NULL) {
    printf ("%s\n", ent->d_name);
  	}
  	closedir (dir);
	}
	else {
  	perror ("Não há");
	}
}

void nova_conta_cliente_empresa(){
	int opcao;
	FILE* novaconta;

	novaconta = fopen("Empresa.dat", "a+");

    criacao_conta_empresa:
	system("cls");
	printf("\n Novo Cliente");
	printf("\n Introduza a data de hoje no formato (dia/mes/ano):");
	scanf("%d/%d/%d", &adicionar.deposito.dia, &adicionar.deposito.mes, &adicionar.deposito.ano);
	printf("\n Introduza o numero da conta");
	scanf("%d", &verificar.nr_de_conta);
while (fscanf(novaconta, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", &adicionar.certidao, adicionar.email, &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.dia, &adicionar.acm.mes, &adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, 
       &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)
	{
		if (verificar.nr_de_conta == adicionar.nr_de_conta)
		{
			printf(" Essa conta já existe!");
			goto criacao_conta_empresa;
	    }
		
	}
	
	adicionar.nr_de_conta = verificar.nr_de_conta;
	printf("\n Introduza o Nome:");
	scanf("%s", adicionar.nome);
	printf("\n Introduza a Certidão:");
	scanf("%d", &adicionar.certidao);
	printf("\n Introduza a data de hoje no formato (dia/mes/ano):");
	scanf("%d/%d/%d", &adicionar.deposito.dia, &adicionar.deposito.mes, &adicionar.deposito.ano);
	printf("\n Introduza o Email:");
	scanf("%s", &adicionar.email);
	printf("\n Introduza a Morada:");
	scanf("%s", adicionar.morada);
	printf("\n Introduza a Nacionalidade:");
	scanf("%s", adicionar.nacionalidade);
	printf("\n Introduza o Contacto: ");
	scanf("%lf", &adicionar.nr_telemovel);
	printf("\n Introduza quanto quer depositar na conta:");
	scanf("%f", &adicionar.dinheiro);
	
	printf("\n Tipo de Conta a criar:\n\t#->Poupanca\n\t->Particular\n\t \n\t->Empresa\n\t \n\t Escreva a opcao:");
	scanf("%s", adicionar.acc_type);

	fprintf(novaconta, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", adicionar.certidao, adicionar.email, adicionar.nr_de_conta, adicionar.nome, adicionar.acm.dia, adicionar.acm.mes, adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, 
            adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
	fclose(novaconta);
	printf("\n Conta criada com sucesso!");

	se_adicionar_invalido:
	printf("\n Prima 1 para ir para o menu inicial e 0 para sair");
	scanf("%d", &voltar_menu);
	system("cls");
	if (voltar_menu == 1)
		menu();
	else if (voltar_menu == 0)
		system("cls");
	else
	{
		printf("\nOpção Invalida! ");
		goto se_adicionar_invalido;
	}
}

void ver_lista_empresa() {
  FILE * ver_lista;
  ver_lista = fopen("Empresa.dat", "r");
  int teste = 0;
  system("cls");
  printf("\n Numero da Conta \t Nome \t Morada \t Contacto\n");

  while (fscanf(ver_lista, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", &adicionar.certidao, adicionar.email, &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.dia, &adicionar.acm.mes, &adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, 
       &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF) 
  {
    printf("\n %6d \t %10s \t %10s \t %.0lf", adicionar.nr_de_conta, adicionar.nome, adicionar.morada, adicionar.nr_telemovel);
    teste++;
  }

  fclose(ver_lista);
  if (teste == 0) {
    system("cls");
    printf("\n Não existe \n");
  }

  se_ver_lista_invalido:
    printf("\n Prima 1 para ir para o menu inicial e 0 para sair");
  scanf("%d", & voltar_menu);
  system("cls");
  if (voltar_menu == 1)
    menu();
  else if (voltar_menu == 0)
    system("cls");
  else {
    printf("\n Opção Invalida!");
    goto se_ver_lista_invalido;
  }
}

void edicao_cliente_empresa(void) {
  int opcao, teste = 0;
  FILE * antiga_versao, * nova_versao;
  antiga_versao = fopen("Empresa.dat", "r");
  nova_versao = fopen("Novaempresa.dat", "w");

  printf("\n Insira o numero da conta empresa para editar informacoes: ");
  scanf("%d", & alterar.nr_de_conta);
  while (fscanf(antiga_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", &adicionar.certidao, adicionar.email, &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.dia, &adicionar.acm.mes, &adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, 
       &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)  
  {
    if (adicionar.nr_de_conta == alterar.nr_de_conta) {
      teste = 1;
      printf("\n Qual a informação deseja modificar?\n1.Morada\n2.Contacto\n\nSelecione opção ( 1 para Morada and 2 para Contacto ):");
      scanf("%d", & opcao);
      system("cls");
      if (opcao == 1) {
        printf(" Introduza a nova morada:");
        scanf("%s", alterar.morada);
        fprintf(nova_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", adicionar.certidao, adicionar.email, adicionar.nr_de_conta, adicionar.nome, adicionar.acm.dia, adicionar.acm.mes, adicionar.acm.ano, alterar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, 
       adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
        system("cls");
        printf(" Alteracoes gravadas!");
      } 
	  else if (opcao == 2) {
        printf(" Introduza o seu novo numero de contacto:");
        scanf("%lf", & alterar.nr_telemovel);
        fprintf(nova_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", adicionar.certidao, adicionar.email, adicionar.nr_de_conta, adicionar.nome, adicionar.acm.dia, adicionar.acm.mes, adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, alterar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, 
       adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
        system("cls");
        printf(" Alteracoes gravadas!");

      }

    }
	 else
      fprintf(nova_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", adicionar.certidao, adicionar.email, adicionar.nr_de_conta, adicionar.nome, adicionar.acm.dia, adicionar.acm.mes, adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, 
       adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);;
  }
  fclose(antiga_versao);
  fclose(nova_versao);
  remove("Empresa.dat");
  rename("Novaempresa.dat", "Empresa.dat");

  if (teste != 1) {
    system("cls");
    printf("\n Nada encontrado");

    se_edicao_cliente_invalido:
      printf("\n Prima 0 para tentar outra vez, 1 para voltar ao menu e 2 para sair:");
    scanf("%d", & voltar_menu);
    system("cls");
    if (voltar_menu == 1)

      menu();
    else if (voltar_menu == 2)
      system("cls");
    else if (voltar_menu == 0)
      edicao_cliente();
    else {
      printf("\nOpção Invalida! ");
      goto se_edicao_cliente_invalido;
    }
  } 
  else {
    printf("\n Prima 1 para ir para o menu inicial e 0 para sair");
    scanf("%d", & voltar_menu);
    system("cls");
    if (voltar_menu == 1)
      menu();
    else
      system("cls");
  }
}

void deposito_levantamento_empresa(void) {
	todos_users x;
      int opcao, teste = 0;
      FILE * antiga_versao, * nova_versao;
      antiga_versao = fopen("Empresa.dat", "r");
      nova_versao = fopen("Novaempresa.dat", "w");

      printf(" Introduza o numero da conta do cliente:");
      scanf("%d", & transacoes.nr_de_conta);
      while (fscanf(antiga_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", &adicionar.certidao, adicionar.email, &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.dia, &adicionar.acm.mes, &adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, 
       &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)  
	  {

        if (adicionar.nr_de_conta == transacoes.nr_de_conta ) {
          teste = 1;
          if (strcmp(adicionar.acc_type, "nada") == 0) {
            printf("\n Nada");
            system("cls");
            menu();

          }
          printf("\n Desejar fazer um..\n 1.Deposito \n 2.Levantamento \n Introduza 1 ou 2:");
          scanf("%d", & opcao);
          if (opcao == 1) {
            printf(" Introduza quanto quer depositar em euros (€): ");
            scanf("%f", & transacoes.dinheiro);
            adicionar.dinheiro += transacoes.dinheiro;
            fprintf(nova_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", adicionar.certidao, adicionar.email, adicionar.nr_de_conta, adicionar.nome, adicionar.acm.dia, adicionar.acm.mes, adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, 
            adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
            printf("\n Efectuou um deposito com sucesso ");
          } else {
            printf(" Introduza quanto quer levantar em euros (€): ");
            scanf("%f", & transacoes.dinheiro);
            adicionar.dinheiro -= transacoes.dinheiro;
            fprintf(nova_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", adicionar.certidao, adicionar.email, adicionar.nr_de_conta, adicionar.nome, adicionar.acm.dia, adicionar.acm.mes, adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, 
            adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
          }
        } else {
          fprintf(nova_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", adicionar.certidao, adicionar.email, adicionar.nr_de_conta, adicionar.nome, adicionar.acm.dia, adicionar.acm.mes, adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, 
            adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
        }
      }
      fclose(antiga_versao);
      fclose(nova_versao);
      remove("Empresa.dat");
      rename("Novaempresa.dat", "Empresa.dat");
      if (teste != 1) {
        printf("\n Nada encontrado");
        se_deposito_levantamento_cliente_invalido:
          printf("\n Prima 0 para tentar outra vez, 1 para voltar ao menu e 2 para sair:");
        scanf("%d", & voltar_menu);
        system("cls");
        if (voltar_menu == 0)
          deposito_levantamento_cliente();
        else if (voltar_menu == 1)
          menu();
        else if (voltar_menu == 2)
          system("cls");
        else {
          printf("\n Opção Invalida!");
          goto se_deposito_levantamento_cliente_invalido;
        }

      } else {
        printf("\n Prima 1 para ir para o menu inicial e 0 para sair");
        scanf("%d", & voltar_menu);
        system("cls");
        if (voltar_menu == 1)
          menu();
        else
          system("cls");
      }

    }
    
void apagar_cliente_empresa(void) {
      FILE * antiga_versao, * nova_versao;
      int teste = 0;
      antiga_versao = fopen("Empresa.dat", "r");
      nova_versao = fopen("Novaempresa.dat", "w");
      printf(" Introduza o numero da conta do cliente a apagar:");
      scanf("%d", & eliminar.nr_de_conta);
      while (fscanf(antiga_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", &adicionar.certidao, adicionar.email, &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.dia, &adicionar.acm.mes, &adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, 
       &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF) 
	  {
        if (adicionar.nr_de_conta != eliminar.nr_de_conta)
          fprintf(nova_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", adicionar.certidao, adicionar.email, adicionar.nr_de_conta, adicionar.nome, adicionar.acm.dia, adicionar.acm.mes, adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, 
       adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);

        else {
          teste++;
          printf("\n Cliente eliminado com sucesso\n");
        }
      }
      fclose(antiga_versao);
      fclose(nova_versao);
      remove("Empresa.dat");
      rename("Novaempresa.dat", "Empresa.dat");
      if (teste == 0) {
        printf("\n Não existe");
        apagar_cliente_Invalida:
          printf("\n Prima 1 para ir para o menu inicial e 0 para sair:");
        scanf("%d", & voltar_menu);

        if (voltar_menu == 1)
          menu();
        else if (voltar_menu == 2)
          system("cls");
        else if (voltar_menu == 0)
          apagar_cliente();
        else {
          printf("\n Opção Invalida!");
          goto apagar_cliente_Invalida;
        }
      } else {
        printf("\n Prima 1 para ir para o menu inicial e 0 para sair");
        scanf("%d", & voltar_menu);
        system("cls");
        if (voltar_menu == 1)
          menu();
        else
          system("cls");
      }

    }
    
void ver_cliente_empresa(void) {
      FILE * fp;
      int teste = 0;
      int opcao;
      fp = fopen("Empresa.dat", "r");
      printf(" Ver cliente atraves do \n 1.Numero da Conta do Cliente \n 2.Nome \n Introduza 1 ou 2:");
      scanf("%d", & opcao);
      if (opcao == 1) {
        printf(" Introduza o numero da conta:");
        scanf("%d", & verificar.nr_de_conta);

        while (fscanf(fp, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", &adicionar.certidao, adicionar.email, &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.dia, &adicionar.acm.mes, &adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, 
       &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)  
		{
          if (adicionar.nr_de_conta == verificar.nr_de_conta) {
            system("cls");
            teste = 1;

            printf("\n Numero da Conta: %d\n Nome: %s \n Data de Criacao da Conta: %d/%d/%d \n Morada:%s \n Nacionalidade:%s \n Numero de Contacto:%.0lf \n Tipo de Conta:%s \n Dinheiro: %.2f \n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel,
              adicionar.acc_type, adicionar.dinheiro);
          }
        }
      } else if (opcao == 2) {
        printf(" Introduza o seu nome:");
        scanf("%s", & verificar.nome);
        while (fscanf(fp, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", &adicionar.certidao, adicionar.email, &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.dia, &adicionar.acm.mes, &adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, 
       &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)
		{
          if (strcmp(adicionar.nome, verificar.nome) == 0) {
            system("cls");
            teste = 1;
            printf("\n Numero da Conta: %d\n Nome: %s \n Data de Criacao da Conta: %d/%d/%d \n Morada:%s \n Nacionalidade:%s \n Numero de Contacto:%.0lf \n Tipo de Conta:%s \n Dinheiro: %.2f \n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel,
              adicionar.acc_type, adicionar.dinheiro);
          }
        }
      }

      fclose(fp);
      if (teste != 1) {
        system("cls");
        printf("\n Não existe");
        se_ver_cliente_invalido:
          printf("\n Prima 1 para ir para o menu inicial e 0 para sair:");
        scanf("%d", & voltar_menu);
        system("cls");
        if (voltar_menu == 1)
          menu();
        else if (voltar_menu == 2)
          system("cls");
        else if (voltar_menu == 0)
          ver_cliente();
        else {
          system("cls");
          printf("\nOpção Invalida!");
          goto se_ver_cliente_invalido;
        }
      } else {
        printf("\nPrima 1 para ir para o menu inicial e 0 para sair");
        scanf("%d", & voltar_menu);
      }
      if (voltar_menu == 1) {
        system("cls");
        menu();
      } else {

        system("cls");
      }
  }    
      
void emprestimo_empresa(void)
{	
	float capital;
	float taxa_juro = 2.2;
	int meses;
	float calculo_mes;
	int opcao, teste = 0;
	FILE* antiga_versao, * nova_versao;
	antiga_versao = fopen("Empresa.dat", "r");
	nova_versao = fopen("Novaempresa.dat", "w");

	printf(" Introduza o numero da conta:");
	scanf("%d", &transacoes.nr_de_conta);
	while (fscanf(antiga_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", &adicionar.certidao, adicionar.email, &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.dia, &adicionar.acm.mes, &adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, 
       &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)
	{

		if (adicionar.nr_de_conta == transacoes.nr_de_conta && adicionar.idade <= 60)
		{
				teste = 1;
				printf(" Introduza quanto quer pedir emprestado: ");
				scanf("%f", &transacoes.dinheiro);
				adicionar.dinheiro += transacoes.dinheiro;
				fprintf(nova_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", adicionar.certidao, adicionar.email, adicionar.nr_de_conta, adicionar.nome, adicionar.acm.dia, adicionar.acm.mes, adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, 
       adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
				printf("\n Insira em quantos meses deseja pagar: ");
				scanf("%d", &meses);
				capital = transacoes.dinheiro;
				calculo_mes = (capital * taxa_juro) / meses;
				printf("\n Vai pagar %f euros por mes durante %d meses", calculo_mes, meses);
				printf("\n Emprestimo concedido");

		}
		else
		{
			fprintf(nova_versao, "%d %s %d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n", adicionar.certidao, adicionar.email, adicionar.nr_de_conta, adicionar.nome, adicionar.acm.dia, adicionar.acm.mes, adicionar.acm.ano, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, 
       adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
		}
	}
	fclose(antiga_versao);
	fclose(nova_versao);
	remove("Empresa.dat");
	rename("Novaempresa.dat", "Empresa.dat");
	if (teste != 1)
	{
		printf("\n Erro nao pode pedir emprestimo ou a conta nao existe ");
		se_emprestimo_invalido:
		printf("\n Enter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d", &voltar_menu);
		system("cls");
		if (voltar_menu == 0)
			emprestimo();
		else if (voltar_menu == 1)
			menu();
		else if (voltar_menu == 2)
			system("cls");
		else
		{
			printf("\nOpção Invalida!");
			goto se_emprestimo_invalido;
		}

	}
	else
	{
		printf("\nPrima 1 para ir para o menu inicial e 0 para sair");
		scanf("%d", &voltar_menu);
		system("cls");
		if (voltar_menu == 1)
			menu();
		else
			system("cls");
	}

}
void nova_conta_cliente()

{
	int opcao;
	FILE* novaconta;

	novaconta = fopen("Clientes.dat", "a+");
	
    criacao_conta_cliente:
	system("cls");
	printf("\n Novo Cliente");
	printf("\n Introduza o numero da conta");
	scanf("%d", &verificar.nr_de_conta);
	while (fscanf(novaconta, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.dia, &adicionar.acm.mes, &adicionar.acm.ano, &adicionar.idade, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)
	{
		if (verificar.nr_de_conta == adicionar.nr_de_conta)
		{
			printf(" Essa conta já existe!");
			goto criacao_conta_cliente;

		}
		else if (adicionar.idade > 65)
		{
			printf(" Não pode criar conta no banco com a sua idade ");
			goto criacao_conta_cliente;
		}
		
	}
	adicionar.nr_de_conta = verificar.nr_de_conta;
	printf("\n Introduza o nome:");
	scanf("%s", adicionar.nome);
	printf("\n Introduza a data de hoje no formato (dia/mes/ano):");
	scanf("%d/%d/%d", &adicionar.deposito.dia, &adicionar.deposito.mes, &adicionar.deposito.ano);
	printf("\n Introduza a idade:");
	scanf("%d", &adicionar.idade);
	printf("\n Introduza a morada:");
	scanf("%s", adicionar.morada);
	printf("\n Introduza a sua nacionalidade:");
	scanf("%s", adicionar.nacionalidade);
	printf("\n Introduza o seu numero de telemovel: ");
	scanf("%lf", &adicionar.nr_telemovel);
	printf("\n Introduza quanto quer depositar na sua conta:");
	scanf("%f", &adicionar.dinheiro);
	
	printf("\n Tipo de Conta a criar:\n\t#->Poupanca\n\t->Particular\n\t \n\t Escreva a opcao:");
	scanf("%s", adicionar.acc_type);

	fprintf(novaconta, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.dia, adicionar.acm.mes, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, adicionar.deposito.dia, adicionar.deposito.mes, adicionar.deposito.ano);
	fclose(novaconta);
	printf("\n Conta criada com sucesso!");
	
	se_adicionar_invalido:
	printf("\n Prima 1 para ir para o menu inicial e 0 para sair");
	scanf("%d", &voltar_menu);
	system("cls");
	if (voltar_menu == 1)
		menu();
	else if (voltar_menu == 0)
		system("cls");
	else
	{
		printf("\nOpção Invalida! ");
		goto se_adicionar_invalido;
	}
}
void ver_lista_clientes()
{
	FILE* ver_lista;
	ver_lista = fopen("Clientes.dat", "r");
	int teste = 0;
	system("cls");
	printf("\n Numero da Conta \t Nome \t Morada \t nr_telemovel\n");

	while (fscanf(ver_lista, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.dia, &adicionar.acm.mes, &adicionar.acm.ano, &adicionar.idade, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, &adicionar.deposito.dia, &adicionar.deposito.mes, &adicionar.deposito.ano) != EOF)
	{
		printf("\n %6d \t %10s \t %10s \t %.0lf", adicionar.nr_de_conta, adicionar.nome, adicionar.morada, adicionar.nr_telemovel);
		teste++;
	}

	fclose(ver_lista);
	if (teste == 0)
	{
		system("cls");
		printf("\n Não eacmiste \n");
	}

	se_ver_lista_invalido:
	printf("\n Prima 1 para ir para o menu inicial e 0 para sair");
	scanf("%d", &voltar_menu);
	system("cls");
	if (voltar_menu == 1)
		menu();
	else if (voltar_menu == 0)
		system("cls");
	else
	{
		printf("\n Opção Invalida!");
		goto se_ver_lista_invalido;
	}
}
void edicao_cliente(void)
{
	int opcao, teste = 0;
	FILE* antiga_versao, * nova_versao;
	antiga_versao = fopen("Clientes.dat", "r");
	nova_versao = fopen("Novoclientes.dat", "w");

	printf("\n Insira o numero da conta cliente para editar informacoes: ");
	scanf("%d", &alterar.nr_de_conta);
	while (fscanf(antiga_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.mes, &adicionar.acm.dia, &adicionar.acm.ano, &adicionar.idade, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)
	{
		if (adicionar.nr_de_conta == alterar.nr_de_conta)
		{
			teste = 1;
			printf("\n Qual a informacao quer modificar?\n1.morada\n2.nr_telemovel\n\nEnter your opcao(1 for morada and 2 for nr_telemovel):");
			scanf("%d", &opcao);
			system("cls");
			if (opcao == 1)
			{
				printf(" Introduza a sua nova morada:");
				scanf("%s", alterar.morada);
				fprintf(nova_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.idade, alterar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
				system("cls");
				printf(" Alteracoes gravadas!");
			}
			else if (opcao == 2)
			{
				printf(" Introduza o seu novo numero de nr_telemovel:");
				scanf("%lf", &alterar.nr_telemovel);
				fprintf(nova_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, alterar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
				system("cls");
				printf(" Alteracoes gravadas!");
			
			}

		}
		else
			fprintf(nova_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
	}
	fclose(antiga_versao);
	fclose(nova_versao);
	remove("Clientes.dat");
	rename("Novoclientes.dat", "Clientes.dat");

	if (teste != 1)
	{
		system("cls");
		printf("\n Nada encontrado");
		
		se_edicao_cliente_invalido:
		printf("\n Prima 0 para tentar outra vez, 1 para voltar ao menu e 2 para sair:");
		scanf("%d", &voltar_menu);
		system("cls");
		if (voltar_menu == 1)

			menu();
		else if (voltar_menu == 2)
			system("cls");
		else if (voltar_menu == 0)
			edicao_cliente();
		else
		{
			printf("\nOpção Invalida! ");
			goto se_edicao_cliente_invalido;
		}
	}
	else
	{
		printf("\n Prima 1 para ir para o menu inicial e 0 para sair");
		scanf("%d", &voltar_menu);
		system("cls");
		if (voltar_menu == 1)
			menu();
		else
			system("cls");
	}
}
void deposito_levantamento_cliente(void)
{
	int opcao, teste = 0;
	FILE* antiga_versao, * nova_versao;
	antiga_versao = fopen("Clientes.dat", "r");
	nova_versao = fopen("Novoclientes.dat", "w");

	printf(" Introduza o numero da conta do cliente:");
	scanf("%d", &transacoes.nr_de_conta);
	while (fscanf(antiga_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.mes, &adicionar.acm.dia, &adicionar.acm.ano, &adicionar.idade, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)
	{

		if (adicionar.nr_de_conta == transacoes.nr_de_conta)
		{
			teste = 1;
			if (strcmp(adicionar.acc_type, "nada") == 0)
			{
				printf("\n Nada");
				system("cls");
				menu();

			}
			printf("\n Desejar fazer um..\n 1.Deposito \n 2.Levantamento \n Introduza 1 ou 2:");
			scanf("%d", &opcao);
			if (opcao == 1)
			{
				printf(" Introduza quanto quer depositar em euros (€): ");
				scanf("%f", &transacoes.dinheiro);
				adicionar.dinheiro += transacoes.dinheiro;
				fprintf(nova_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
				printf("\n Efectuou um deposito com sucesso ");
			}
			else
			{
				printf(" Introduza quanto quer levantar em euros (€): ");
				scanf("%f", &transacoes.dinheiro);
				adicionar.dinheiro -= transacoes.dinheiro;
				fprintf(nova_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
				printf("\n Efectuou o levantamento com sucesso ");
			}
		}
		else
		{
			fprintf(nova_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);
		}
	}
	fclose(antiga_versao);
	fclose(nova_versao);
	remove("Clientes.dat");
	rename("Novoclientes.dat", "Clientes.dat");
	if (teste != 1)
	{
		printf("\n Nada encontrado");
		se_deposito_levantamento_cliente_invalido:
		printf("\n Prima 0 para tentar outra vez, 1 para voltar ao menu e 2 para sair:");
		scanf("%d", &voltar_menu);
		system("cls");
		if (voltar_menu == 0)
			deposito_levantamento_cliente();
		else if (voltar_menu == 1)
			menu();
		else if (voltar_menu == 2)
			system("cls");
		else
		{
			printf("\n Opção Invalida!");
			goto se_deposito_levantamento_cliente_invalido;
		}

	}
	else
	{
		printf("\n Prima 1 para ir para o menu inicial e 0 para sair");
		scanf("%d", &voltar_menu);
		system("cls");
		if (voltar_menu == 1)
			menu();
		else
			system("cls");
	}

}
void apagar_cliente(void)
{
	FILE* antiga_versao, * nova_versao;
	int teste = 0;
	antiga_versao = fopen("Clientes.dat", "r");
	nova_versao = fopen("Novoclientes.dat", "w");
	printf(" Introduza o numero da conta do cliente a apagar:");
	scanf("%d", &eliminar.nr_de_conta);
	while (fscanf(antiga_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.mes, &adicionar.acm.dia, &adicionar.acm.ano, &adicionar.idade, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)
	{
		if (adicionar.nr_de_conta != eliminar.nr_de_conta)
			fprintf(nova_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, adicionar.deposito.mes, adicionar.deposito.dia, adicionar.deposito.ano);

		else
		{
			teste++;
			printf("\n Cliente eliminado com sucesso\n");
		}
	}
	fclose(antiga_versao);
	fclose(nova_versao);
	remove("Clientes.dat");
	rename("Novoclientes.dat", "Clientes.dat");
	if (teste == 0)
	{
		printf("\n Não existe");
	apagar_cliente_Invalida:
		printf("\n Prima 0 para tentar outra vez, 1 para voltar ao menu e 2 para sair:");
		scanf("%d", &voltar_menu);

		if (voltar_menu == 1)
			menu();
		else if (voltar_menu == 2)
			system("cls");
		else if (voltar_menu == 0)
			apagar_cliente();
		else
		{
			printf("\n Opção Invalida!");
			goto apagar_cliente_Invalida;
		}
	}
	else
	{
		printf("\n Prima 1 para ir para o menu inicial e 0 para sair");
		scanf("%d", &voltar_menu);
		system("cls");
		if (voltar_menu == 1)
			menu();
		else
			system("cls");
	}

}

void newsletter() {

    FILE * fp;
    int teste = 0;
    int opcao;
    fp = fopen("Clientes.dat", "r");
    printf(" Ver cliente atraves do \n 1.Numero da Conta do Cliente \n 2.Nome \n Introduza 1 ou 2:");
    scanf("%d", & opcao);
    if (opcao == 1) {
    	teste = 1;
    	printf(" Introduza o numero da conta:");
		scanf("%d", &verificar.nr_de_conta);

		while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.mes, &adicionar.acm.dia, &adicionar.acm.ano, &adicionar.idade, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)
		{
			if (adicionar.nr_de_conta == verificar.nr_de_conta)
			{
				system("cls");
				printf("\n Numero da Conta: %d\n Nome: %s \n Data de Criacao da Conta: %d/%d/%d \n Idade:%d \n Morada:%s \n Nacionalidade:%s \n Numero de nr_telemovel:%.0lf \n Tipo de Conta:%s \n Dinheiro: %.2f \n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel,
					adicionar.acc_type, adicionar.dinheiro);
					
			printf("\nVoce deseja enviar Newsletter para esse cliente? [1-SIM|2-NAO|PRIMA OUTRO QUALQUER PARA VOLTAR AO MENU] \n");
          	do {

            scanf("%d", & opcao);
            switch (opcao) {
            case 1:
              {

                printf("\n\n Newsletter enviada com sucesso!\n\n");
                system("cls");
                system("pause");
                newsletter();
                break;
              }
            case 2:
              {
                system("cls");
                newsletter();

                break;
              }
            default:
              {
                menu();
                break;
              }
            }
			}while (opcao != 3);
			}
		}
	}
	else if (opcao == 2)
	{
		teste = 1;
		printf(" Introduza o seu nome:");
		scanf("%s", &verificar.nome);
		while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.mes, &adicionar.acm.dia, &adicionar.acm.ano, &adicionar.idade, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)
		{
			if (strcmp(adicionar.nome, verificar.nome) == 0)
			{
				system("cls");
				printf("\n Numero da Conta: %d\n Nome: %s \n Data de Criacao da Conta: %d/%d/%d \n Idade:%d \n Morada:%s \n Nacionalidade:%s \n Numero de nr_telemovel:%.0lf \n Tipo de Conta:%s \n Dinheiro: %.2f \n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel,
					adicionar.acc_type, adicionar.dinheiro);
			
			printf("\nVoce deseja enviar Newsletter para esse cliente? [1-SIM|2-NAO|PRIMA OUTRO QUALQUER PARA VOLTAR AO MENU] \n");		
			do {

            scanf("%d", & opcao);
            switch (opcao) {
            case 1:
              {

                printf("\n\n Newsletter enviada com sucesso!\n\n");
                system("cls");
                newsletter();
                break;
              }
            case 2:
              {
                system("cls");
				newsletter();
                break;
              }
            default:
              {
                menu();
                break;
              }
            }
			}while (opcao != 3);
			}
		}
	}


	fclose(fp);
	if (teste != 1)
	{
		system("cls");
		printf("\n Não existe");
		se_newsletter_invalido:
		printf("\n Prima 0 para tentar outra vez, 1 para voltar ao menu e 2 para sair:");
		scanf("%d", &voltar_menu);
		system("cls");
		if (voltar_menu == 1)
			menu();
		else if (voltar_menu == 2)
			system("cls");
		else if (voltar_menu == 0)
			newsletter();
		else
		{
			system("cls");
			printf("\nOpção Invalida!");
			goto se_newsletter_invalido;
		}
	}
	else
	{
		printf("\nPrima 1 para ir para o menu inicial e 0 para sair");
		scanf("%d", &voltar_menu);
	}
	if (voltar_menu == 1)
	{
		system("cls");
		menu();
	}

	else
	{

		system("cls");
	}
      
}

void backup_admin() { // faz backup de um file
	int teste = 0;
	FILE *fp, *fpbackup; 
    char ficheiro[100], acc; 
  
    printf(" Introduza o nome do ficheiro para ser copiado \n"); 
    scanf("%s", ficheiro); 
  
    fp = fopen(ficheiro, "r"); 
    if (fp == NULL) 
    { 
        printf(" Erro ao abrir o ficheiro %s \n", ficheiro); 
        backup_admin();
    } 
  
    printf(" Introduza o nome do ficheiro backup \n"); 
    scanf("%s", ficheiro); 
  
    fpbackup = fopen(ficheiro, "w"); 
    if (fpbackup == NULL) 
    { 
        printf(" Erro ao abrir o ficheiro %s \n", ficheiro); 
        backup_admin(); 
    } 
  
    acc = fgetc(fp); 
    while (acc != EOF) 
    { 
        fputc(acc, fpbackup); 
        acc = fgetc(fp); 
    } 
  
    printf("\n Tudo copiado com sucesso para %s", ficheiro);
  
    fclose(fp);
    fclose(fpbackup);
    if (teste != 1)
	{
		system("cls");
		printf("\n Não existe");
		se_backup_admin_invalido:
		printf("\n Prima 0 para tentar outra vez, 1 para voltar ao menu e 2 para sair:");
		scanf("%d", &voltar_menu);
		system("cls");
		if (voltar_menu == 1)
			menu();
		else if (voltar_menu == 2)
			system("cls");
		else if (voltar_menu == 0)
			backup_admin();
		else
		{
			system("cls");
			printf("\nOpção Invalida!");
			goto se_backup_admin_invalido;
		}
	}
	else
	{
		printf("\nPrima 1 para ir para o menu inicial e 0 para sair");
		scanf("%d", &voltar_menu);
	}
	if (voltar_menu == 1)
	{
		system("cls");
		menu();
	}

	else
	{

		system("cls");
	}
}

void ver_cliente(void)
{
	FILE* fp;
	int teste = 0;
	int opcao;
	fp = fopen("Clientes.dat", "r");
	printf(" Ver cliente atraves do \n 1.Numero da Conta do Cliente \n 2.Nome \n Introduza 1 ou 2:");
	scanf("%d", &opcao);
	if (opcao == 1)
	{
		printf(" Introduza o numero da conta:");
		scanf("%d", &verificar.nr_de_conta);

		while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.mes, &adicionar.acm.dia, &adicionar.acm.ano, &adicionar.idade, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)
		{
			if (adicionar.nr_de_conta == verificar.nr_de_conta)
			{
				system("cls");
				teste = 1;

				printf("\n Numero da Conta: %d\n Nome: %s \n Data de Criacao da Conta: %d/%d/%d \n Idade:%d \n Morada:%s \n Nacionalidade:%s \n Numero de nr_telemovel:%.0lf \n Tipo de Conta:%s \n Dinheiro: %.2f \n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel,
					adicionar.acc_type, adicionar.dinheiro);
			}
		}
	}
	else if (opcao == 2)
	{
		printf(" Introduza o seu nome:");
		scanf("%s", &verificar.nome);
		while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.mes, &adicionar.acm.dia, &adicionar.acm.ano, &adicionar.idade, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)
		{
			if (strcmp(adicionar.nome, verificar.nome) == 0)
			{
				system("cls");
				teste = 1;
				printf("\n Numero da Conta: %d\n Nome: %s \n Data de Criacao da Conta: %d/%d/%d \n Idade:%d \n Morada:%s \n Nacionalidade:%s \n Numero de nr_telemovel:%.0lf \n Tipo de Conta:%s \n Dinheiro: %.2f \n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel,
					adicionar.acc_type, adicionar.dinheiro);
			}
		}
	}


	fclose(fp);
	if (teste != 1)
	{
		system("cls");
		printf("\n Não existe");
		se_ver_cliente_invalido:
		printf("\n Prima 0 para tentar outra vez, 1 para voltar ao menu e 2 para sair:");
		scanf("%d", &voltar_menu);
		system("cls");
		if (voltar_menu == 1)
			menu();
		else if (voltar_menu == 2)
			system("cls");
		else if (voltar_menu == 0)
			ver_cliente();
		else
		{
			system("cls");
			printf("\nOpção Invalida!");
			goto se_ver_cliente_invalido;
		}
	}
	else
	{
		printf("\nPrima 1 para ir para o menu inicial e 0 para sair");
		scanf("%d", &voltar_menu);
	}
	if (voltar_menu == 1)
	{
		system("cls");
		menu();
	}

	else
	{

		system("cls");
	}

}
void emprestimo(void)
{	
	float capital;
	float taxa_juro = 2.2;
	int meses;
	float calculo_mes;
	int opcao, teste = 0;
	FILE* antiga_versao, * nova_versao;
	antiga_versao = fopen("Clientes.dat", "r");
	nova_versao = fopen("Novoclientes.dat", "w");

	printf(" Introduza o numero da conta:");
	scanf("%d", &transacoes.nr_de_conta);
	while (fscanf(antiga_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &adicionar.nr_de_conta, adicionar.nome, &adicionar.acm.mes, &adicionar.acm.dia, &adicionar.acm.ano, &adicionar.idade, adicionar.morada, adicionar.nacionalidade, &adicionar.nr_telemovel, adicionar.acc_type, &adicionar.dinheiro, &adicionar.deposito.mes, &adicionar.deposito.dia, &adicionar.deposito.ano) != EOF)
	{

		if (adicionar.nr_de_conta == transacoes.nr_de_conta && adicionar.idade <= 60)
		{
				teste = 1;
				printf(" Introduza quanto quer pedir emprestado: ");
				scanf("%f", &transacoes.dinheiro);
				adicionar.dinheiro += transacoes.dinheiro;
				fprintf(nova_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.mes, adicionar.acm.dia, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, adicionar.deposito.dia, adicionar.deposito.mes, adicionar.deposito.ano);
				printf("\n Insira em quantos meses deseja pagar: ");
				scanf("%d", &meses);
				capital = transacoes.dinheiro;
				calculo_mes = (capital * taxa_juro) / meses;
				printf("\n Vai pagar %f euros por mes durante %d meses", calculo_mes, meses);
				printf("\n Emprestimo concedido");

		}
		else
		{
			fprintf(nova_versao, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", adicionar.nr_de_conta, adicionar.nome, adicionar.acm.dia, adicionar.acm.mes, adicionar.acm.ano, adicionar.idade, adicionar.morada, adicionar.nacionalidade, adicionar.nr_telemovel, adicionar.acc_type, adicionar.dinheiro, adicionar.deposito.dia, adicionar.deposito.mes, adicionar.deposito.ano);
		}
	}
	fclose(antiga_versao);
	fclose(nova_versao);
	remove("Clientes.dat");
	rename("Novoclientes.dat", "Clientes.dat");
	if (teste != 1)
	{
		printf("\n Erro nao pode pedir emprestimo ou a conta nao existe ");
		se_emprestimo_invalido:
		printf("\n Prima 0 para tentar outra vez, 1 para voltar ao menu e 2 para sair:");
		scanf("%d", &voltar_menu);
		system("cls");
		if (voltar_menu == 0)
			emprestimo();
		else if (voltar_menu == 1)
			menu();
		else if (voltar_menu == 2)
			system("cls");
		else
		{
			printf("\nOpção Invalida!");
			goto se_emprestimo_invalido;
		}

	}
	else
	{
		printf("\nPrima 1 para ir para o menu inicial e 0 para sair");
		scanf("%d", &voltar_menu);
		system("cls");
		if (voltar_menu == 1)
			menu();
		else
			system("cls");
	}

}
void menu()
{
	int opcao;
	system("cls");
	printf("\n CONTROL3 - APLICACAO");
	printf("\n MENU");
	printf("\n \t 1.Criar Nova Conta \n\t 2.Alterar informacoes de uma conta \n\t 3.Depositos e Levantamentos \n\t 4.Ver Cliente \n\t 5.Eliminar Cliente \n\t 6.Ver Lista de Clientes \n\t 7.Emprestimo \n\t 8.Newsletter \n\t 9.Criar Nova Conta Empresa \n\t 10.Alterar informacoes de uma conta empresa \n\t 11.Depositos e Levantamentos de Empresa \n\t 12.Ver Cliente Empresa \n\t 13.Eliminar Cliente Empresa \n\t 14.Ver Lista de Clientes Empresa \n\t 15.Emprestimo Empresa \n\t 16.Backup do Ficheiro \n\t 17.Sair \n\t Introduza uma opcao:");
	scanf("%d", &opcao);

	system("cls");
	switch (opcao)
	{
	case 1:nova_conta_cliente();
		break;
	case 2:edicao_cliente();
		break;
	case 3:deposito_levantamento_cliente();
		break;
	case 4:ver_cliente();
		break;
	case 5:apagar_cliente();
		break;
	case 6:ver_lista_clientes();
		break;
	case 7:emprestimo();
		break;
	case 8:newsletter();
		break;
	case 9:nova_conta_cliente_empresa();
		break;
	case 10:edicao_cliente_empresa();
		break;
	case 11:deposito_levantamento_empresa();
		break;
	case 12:ver_cliente_empresa();
		break;
	case 13:apagar_cliente_empresa();
		break;
	case 14:ver_lista_empresa();
		break;
	case 15:emprestimo_empresa();
		break;
	case 16:backup_admin();
		break;	
	case 17:system("cls");
		break;

	}
}
void adminmenu()
{
	int opcao;
	system("cls");
	printf("\n CONTROL3 - APLICACAO");
	printf("\n MENU");
	printf("\n \t 1.Criar Nova Conta \n\t 2.Alterar informacoes de uma conta \n\t 3.Depositos e Levantamentos \n\t 4.Ver Cliente \n\t 5.Eliminar Cliente \n\t 6.Ver Lista de Clientes \n\t 7.Emprestimo \n\t 8.Newsletter \n\t 9.Criar Nova Conta Empresa \n\t 10.Alterar informacoes de uma conta empresa \n\t 11.Depositos e Levantamentos de Empresa \n\t 12.Ver Cliente Empresa \n\t 13.Eliminar Cliente Empresa \n\t 14.Ver Lista de Clientes Empresa \n\t 15.Emprestimo Empresa \n\t 16.Backup do Ficheiro \n\t 17.Sair \n\t Introduza uma opcao:");
	scanf("%d", &opcao);

	system("cls");
	switch (opcao)
	{
	case 1:nova_conta_cliente();
		break;
	case 2:edicao_cliente();
		break;
	case 3:deposito_levantamento_cliente();
		break;
	case 4:ver_cliente();
		break;
	case 5:apagar_cliente();
		break;
	case 6:ver_lista_clientes();
		break;
	case 7:emprestimo();
		break;
	case 8:newsletter();
		break;
	case 9:nova_conta_cliente_empresa();
		break;
	case 10:edicao_cliente_empresa();
		break;
	case 11:deposito_levantamento_empresa();
		break;
	case 12:ver_cliente_empresa();
		break;
	case 13:apagar_cliente_empresa();
		break;
	case 14:ver_lista_empresa();
		break;
	case 15:emprestimo_empresa();
		break;
	case 16:backup_admin();
		break;	
	case 17:system("cls");
		break;
	}
}
void gestorcontamenu()
{
	int opcao;
	system("cls");
	printf("\n CONTROL3 - APLICACAO");
	printf("\n MENU");
	printf("\n \t 1.Criar Nova Conta \n\t 2.Alterar informacoes de uma conta \n\t 3.Depositos e Levantamentos \n\t 4.Ver Cliente \n\t 5.Eliminar Cliente \n\t 6.Ver Lista de Clientes \n\t 7.Emprestimo \n\t 8.Criar Nova Conta Empresa \n\t 9.Alterar informacoes de uma conta empresa \n\t 10.Depositos e Levantamentos de Empresa \n\t 11.Ver Cliente Empresa \n\t 12.Eliminar Cliente Empresa \n\t 13.Ver Lista de Clientes Empresa \n\t 14.Emprestimo Empresa \n\t 15.Sair \n\t Introduza uma opcao:");
	scanf("%d", &opcao);

	system("cls");
	switch (opcao)
	{
	case 1:nova_conta_cliente();
		break;
	case 2:edicao_cliente();
		break;
	case 3:deposito_levantamento_cliente();
		break;
	case 4:ver_cliente();
		break;
	case 5:apagar_cliente();
		break;
	case 6:ver_lista_clientes();
		break;
	case 7:emprestimo();
		break;
	case 8:nova_conta_cliente_empresa();
		break;
	case 9:edicao_cliente_empresa();
		break;
	case 10:deposito_levantamento_empresa();
		break;
	case 11:ver_cliente_empresa();
		break;
	case 12:apagar_cliente_empresa();
		break;
	case 13:ver_lista_empresa();
		break;
	case 14:emprestimo_empresa();
		break;
	case 15:system("cls");
		break;
	}
}
void gestorbalcaomenu()
{
	int opcao;
	system("cls");
	printf("\n CONTROL3 - APLICACAO");
	printf("\n MENU");
	printf("\n \t 1.Depositos e Levantamentos \n\t 2.Depositos e Levantamentos de Empresa \n\t 3.Sair \n\t Introduza uma opcao:");
	scanf("%d", &opcao);

	system("cls");
	switch (opcao)
	{
	case 1:deposito_levantamento_cliente();
		break;
	case 2:deposito_levantamento_empresa();
		break;
	case 3:system("cls");
		break;

	}
}
void gestormarketingmenu()
{
	int opcao;
	system("cls");
	printf("\n CONTROL3 - APLICACAO");
	printf("\n MENU");
	printf("\n \t 1.Criar Nova Conta \n\t 2.Newsletter \n\t 3.Criar Nova Conta Empresa \n\t 4.Sair \n\t Introduza uma opcao:");
	scanf("%d", &opcao);

	system("cls");
	switch (opcao)
	{
	case 1:nova_conta_cliente();
		break;
	case 2:newsletter();
		break;
	case 3:nova_conta_cliente_empresa();
		break;
	case 4:system("cls");
		break;

	}
}
void lerUtilizador(todos_users * x) {
int a; 
  puts("\nInsira a Palavra-passe: ");
  fflush(stdin);
  scanf("%s", & ( * x).password);
										
  puts("\nInsira o seu número de Telemóvel: ");
  fflush(stdin);
  scanf("%d", & (*x).nr_telemovel);
  

  puts("\nInsira o ano de nascimento: \n");
  fflush(stdin);
  scanf("%d", & ( * x).data_nascimento);
  
  
}
void novoUtilizadorBd() { //Criar novo utilizador na base de dados

  FILE * fp;
  todos_users x;
  int a;
  char NOME[20];

  printf("\nInsira o seu Nome:	\n ");
  fflush(stdin);
  scanf("%s", &NOME);
  printf("\nEscolha que Utilizador deseja Cadastrar:\n\t 1 --> Administrador \n\t 2 --> Gerente de Conta \n\t 3 --> Gerente de Marketing \n\t 4-> Gerente Balcao \n\t \n\n\tOPCAO: ");
  scanf("%d", &a);

  switch (a) { // vai criar um novo utilizador na base de dados e ao pedir o nome guarda como Utilizador_Nome dependendo do utilizador que escolha
  case 1:
    {
      char admin[8] = "Admin ";
      strcat(admin, NOME);
      strcat(admin, ".dat");

      fp = fopen(admin, "wb");

      if (fp == NULL) {
        puts("Esse user nao existe");
      } else {

        lerUtilizador( &x);
        fprintf(fp,"%s %d %d",(x).password,(x).nr_telemovel,(x).data_nascimento);
        fclose(fp);

        break;
      }
    }

  case 2:
    {
      char GestConta[12] = "GestConta ";
      strcat(GestConta, NOME);
      strcat(GestConta, ".dat");

      fp = fopen(GestConta, "wb");

      if (fp == NULL) {
        puts("Erro ao Criar novo user!!");
      } else {

        lerUtilizador( & x);
        fprintf(fp," %s %d %d",(x).password,(x).nr_telemovel,(x).data_nascimento);
        fclose(fp);

        break;
      }
    }

  case 3:
    {
      char GestMark[11] = "GestMark ";
      strcat(GestMark, NOME);
      strcat(GestMark, ".dat");

      fp = fopen(GestMark, "wb");

      if (fp == NULL) {
        puts("Erro ao Criar novo user!!");
      } else {

        lerUtilizador( & x);
        fprintf(fp," %s %d %d",(x).password,(x).nr_telemovel,(x).data_nascimento);
        fclose(fp);

        break;
      }
    }

  case 4:
    {
      char GestBalcao[13] = "GestBalcao ";
      strcat(GestBalcao, NOME);
      strcat(GestBalcao, ".dat");

      fp = fopen(GestBalcao, "wb");

      if (fp == NULL) {
        puts("Erro ao Criar novo user!!");
      } else {

        lerUtilizador( & x);
        fprintf(fp," %s %d %d",(x).password,(x).nr_telemovel,(x).data_nascimento);
        fclose(fp);

        break;
      }
    }
  }
 
  system("pause");
  system("cls");
}
void delay(unsigned int value)
{
	unsigned int count1 = 0;
	unsigned int count2 = 0;

	for (count1 = 0; count1 < value; count1++)
	{
		for (count2 = 0; count2 < count1; count2++)
		{

		}
	}
}

const char bee[] =
"                     \n\
	        (o ^ o) \n\
               (%%%%%%%) \n\
 _____________(%%%%%%%%%)_____________ \n\
(___/__/___/_(%%%%%%%%%%%)__\\__\\___\\__) \n\
 (_/__/___/_(   Coding   )\\__\\__\\___\\_) \n\
  (__/___/__/(   Hive   )__\\__\\__\\___) \n\
    (___/__/_(%%%%%%%%%%)___\\__\\__\\) \n\
              (%%%%%%%%) \n\
               (%%%%%%)   \n\
                (%%%%) \n\
                  \\/ \n\
";
int main()
{
	setlocale(LC_ALL, "Portuguese");
	int a = 0, OPLC = 0, tipocliente = 0, exit = 0,op;
	char asd[20], CU[20], CAG[20]; //CU = Criar User e CAG = Criar Admin Gestores etc

		int jumpControlAtBottom = 0;
		const int someDelay = 12000;
		int shifControl = 0;

		for (jumpControlAtBottom = 0; jumpControlAtBottom < 30; ++jumpControlAtBottom)
		{
		printf("\n");
		}

		fputs(bee, stdout);

		for (shifControl = 0; shifControl < 30; ++shifControl)
		{

		delay(someDelay);

		printf("\n");
		}
		system("cls");
voltar_paratras:
printf("\n\n\n\n\n\n\t\tSE FOR A PRIMEIRA VEZ A UTILIZADOR A O PROGRAMAR PRIMA 1 SENAO PRIMA 2 (1-SIM, 2-NAO)?\n");
scanf("%d",&op);
system("cls");

if(op==1){
	novoUtilizadorBd();
	goto voltar_paratras;
}
else if(op==2){
	printf("\n\tSelecione o Utilizador para continuar com a Autenticacao: \n\n 1 --> Administrador \n 2 --> Gestor de Conta \n 3 --> Gestor de Marketing \n 4 --> Gestor de Balcão\n\n \tOPCAO: ");
  	scanf("%d", & OPLC);
 	system("cls");
  	system("pause");
	system("cls");
  switch (OPLC)
  {
  case 1:
      {

      while (a != 1)
        {
            printf("Insira o seu Nome: \n");
            fflush(stdin);
            gets(asd);
      a = loginAdmin(asd);

        system("cls");
        printf("Bem Vindo %c \n\n", asd);
        system("cls");
        }
		adminmenu();
        break;
    }

  case 2:
      {
          while (a != 1)
            {
                printf("Insira o seu Nome: \n");
                fflush(stdin);
                gets(asd);
          a = loginGestorConta(asd);

          system("cls");
          printf("Bem Vindo %c \n\n", asd);
          system("cls");
            }
			gestorcontamenu();
            break;
       }

      case 3:
          {
              while (a != 1)
                {

          printf("Insira o seu nome: \n");
          fflush(stdin);
          gets(asd);

          a = loginGestorMarketing(asd);

          system("cls");
          printf("Bem Vindo %c \n\n", asd);
          system("cls");
        }
		gestormarketingmenu();
        break;
    }

  case 4: {

        while ((a != 1))
            {

        printf("Insira o seu nome: \n");
        fflush(stdin);
        gets(asd);

        a = loginGestorBalcao(asd);

        system("cls");
        printf("Bem Vindo %c \n\n", asd);
        system("cls");
        }
		gestorbalcaomenu();
        break;
      }

  default:
    {
      printf("\n\t Por favor, selecione uma opção válida \t\n");
      a = 9;
      break;
    }
  }
}

else{
	system("cls");
	printf("Essa opcao nao existe");
	goto voltar_paratras;

}
	return 0;
}
