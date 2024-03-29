#include <stdio.h>
#define SIZE 200

// VARIÁVEIS GLOBAIS (PÚBLICAS)
char name[SIZE][50];
char mail[SIZE][50];
int cpf[SIZE];
int option;

void createRegistry();

// FUNÇÃO PRINCIPAL
int main(void) {
  createRegistry();
  return 0;
}

// FUNÇÃO PARA REGISTAR USUÁRIO
void createRegistry() {
  static int row;
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