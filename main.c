#include <stdio.h>
#include <string.h>
#define SIZE 200

// VARIÁVEIS GLOBAIS (PÚBLICAS)
char name[SIZE][50];
char mail[SIZE][50];
int cpf[SIZE];
int option;

// INICIALIZAÇÃO DAS FUNÇÕES
void createRegistry();
void searchRegistry();
void listRegistry();

// FUNÇÃO PRINCIPAL
int main(void) {
  do {
    system("cls");
    printf("\nIdentityNest v1.0\n");
    printf("Author: Nader Fares\n");
    printf("\n---- Menu ----\n1 - Create User\n2 - List Users\n3 - Search User\n4 - Exit\n----> ");
    scanf("%d", &option);
    switch (option) {
      case 1:
        createRegistry();
        break;
      case 2:
        listRegistry();
        break;
      case 3:
        searchRegistry();
        break;
      case 4:
        system("exit");
        break;
      default:
        printf("Invalid Option");
        getchar();
        getchar();
        break;
    }
  } while (option != 4);
}

// FUNÇÃO PARA LISTAR TODOS OS REGISTROS
void listRegistry() {
  int i;
  for(i = 0; i < SIZE; i++) {
    // CONDIÇÃO PARA LISTAR SOMENTE OS ESPAÇOS OCUPADOS
    if (cpf[i] > 0) {
      printf("\n Name: %s\n Mail: %s\n CPF: %d\n ###\n", name[i], mail[i], cpf[i]);
    } else {
      break;
    }
  }
  getchar();
  getchar();
}

// FUNÇÃO PARA REGISTAR USUÁRIO
void createRegistry() {
  static int row;

  printf("\n### Create Registry ###\n");

  do {
    printf("\n Enter name: ");
    scanf("%s", &name[row]);

    printf("\n Enter e-mail: ");
    scanf("%s", &mail[row]);

    printf("\n Enter CPF: ");
    scanf("%d", &cpf[row]);

    printf("\n Press 1 to continue or press another value to exit: ");
    scanf("%d", &option);
    row++;
  } while(option == 1);
}

// FUNÇÃO DE PESQUISA
void searchRegistry() {
  // VARIÁVEL LOCAL
  int searchCPF;
  char searchMail[50];
  int i;

  printf("\n### Search Registry ###\n");

  do {
   printf("\nPress 1 to search by CPF or Press 2 to search by Mail: ");
   scanf("%d", &option);

   switch (option) {
      case 1:
        printf("\n Enter CPF: ");
        scanf("%d", &searchCPF);
        for (i = 0; i < SIZE; i++) {
          if (cpf[i] == searchCPF) {
            printf("\n Name: %s\n Mail: %s\n CPF: %d", name[i], mail[i], cpf[i]);
          }
        }
        break;
      case 2:
        printf("\n Enter e-mail: ");
        scanf("%s", &searchMail);
        for (i = 0; i < SIZE; i++) {
          if (strcmp(mail[i], searchMail) == 0) {
            printf("\n Name: %s\n Mail: %s\n CPF: %d", name[i], mail[i], cpf[i]);
          }
        }
        break;
      default:
        printf("\n Invalid Option ");
        break;
    }
   printf("\n Press 1 to continue searching or press another value to exit: ");
   scanf("%d", &option);
  } while(option == 1);
}