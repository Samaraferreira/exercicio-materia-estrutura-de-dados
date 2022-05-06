#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

// void addPonto(Ponto *pontos, int tamanho) {
//   if (pontos == NULL) {
//     printf("Não foi possível alocar memória");
//   } else {
//     int x, y;
//     printf("Digite o valor x: \n");
//     scanf("%d", &x);

//     printf("Digite o valor y: \n");
//     scanf("%d", &y);

//     for(int i = 0; i < tamanho; i++) {
//       if (pontos[i] == NULL) {
//         pontos = criar(x, y); 
//         break;
//       }
//     }
//   }
// }

void addPontos(Ponto **pontos, int tamanho) {
  if (pontos == NULL) {
    printf("Não foi possível alocar memória");
  } else {
    for(int i = 0; i < tamanho; i++) {
      int x, y;
      printf("Digite o valor x: \n");
      scanf("%d", &x);
  
      printf("Digite o valor y: \n");
      scanf("%d", &y);

      Ponto *ponto = criar(x, y);
      pontos[i] = ponto;
    }
  }
}

void exibirPontos(Ponto **pontos, int tamanho) {
  printf("\nPontos registrados: \n");
  for(int i = 0; i < tamanho; i++) {
    imprimir(pontos[i]);
  }
}

void liberarPonto(Ponto **pontos) {
  int p1, p2;
  printf("Posição do ponto: ");
  scanf("%d", &p1);
  liberar(pontos[p1]);
}

void calcularDistanciaEntrePontos(Ponto **pontos) {
  int p1, p2;
  printf("Posição do ponto 1: ");
  scanf("%d", &p1);

  printf("Posição do ponto 2: ");
  scanf("%d", &p2);

  calcularDistancia(pontos[p1], pontos[p2]);
}

int main(void) {
  printf("********** Parte 1 **********\n");
  Ponto *p1 = criar(10, 12);
  Ponto *p2 = criar(5, 25);
  
  imprimir(p1);
  imprimir(p2);
  calcularDistancia(p1, p2);
  mudarPosicao(p1, 15, 25);
  imprimir(p1);
  
  printf("\n*************************\n");

  int tamanho, opcao;
  
  printf("\nQuantidade de elementos: ");
  scanf("%d", &tamanho);
  
  Ponto **pontos = (Ponto**) malloc(tamanho*sizeof(Ponto));

  while(1) {
    printf("\n\nAção: \n 1 - criar ponto no vetor \n 2 - exibir todos os pontos \n 3 - liberar um ponto p do vetor \n 4 - calcular a distância de dois pontos \n Digite uma opção: ");
    scanf("%d", &opcao);
    
    switch (opcao) {
      case 1: 
        addPontos(pontos, tamanho); 
        break;
      case 2: 
        exibirPontos(pontos, tamanho);
        break;
      case 3: 
        liberarPonto(pontos);
        break;
      case 4: 
        calcularDistanciaEntrePontos(pontos);
        break;
      default: 
        break;
    }
  }

  free(pontos);
  
  return 0;
}