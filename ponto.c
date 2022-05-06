#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

Ponto* criar(int x, int y){
  Ponto *p = (Ponto*)malloc(sizeof(Ponto));
  p->x = x; //(*p).x = x;
  p->y = y;
  return p;
}

void imprimir(Ponto *p){
  printf("\n Ponto: (%d, %d)", p->x, p->y);
}

void liberar(Ponto *p){
  printf("\n >> Memoria liberada do ponto");
  free(p);
}

void calcularDistancia(Ponto *p1, Ponto *p2) {
  float d = sqrt(pow((p1->x - p2->x),2) + pow((p1->y - p2->y),2));
  
  printf("\n >> Distância entre os pontos: %.2f", d);
}

Ponto* mudarPosicao(Ponto *p, int x, int y) {
  p->x += x;
  p->y += y;
  return p;
}