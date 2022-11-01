#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100
#define n_vertices 20

/*

  TAM 100        -> Tamanho da MATRIZ
  n_vertices 20  -> Número de vértices criados

*/

void InicializandoMatrix(int matriz[][TAM]){

  for (int i = 0; i < TAM; i++){
    for (int j = 0; j < TAM; j++){

      matriz[i][j] = -1;

    }
  }

}

void ConstrutorVerticeMatrix(int matriz[][TAM],int valor){ 

  valor = valor - 1;
  
  while(matriz[valor][valor] == 0 || matriz[valor][valor] == 1){
    valor = 1 + (rand() % TAM); //1 até 100
  }

  matriz[valor][valor] = 0;

}

int N_aresta_AdjacentesMatrix(int matriz[][TAM],int valor){

  valor = valor - 1;
  int soma = 0;

  for (int i = 0; i < TAM; i++){

    if(matriz[valor][i] != -1 && matriz[valor][i] != 0){
      soma += 1;
    }

  }

  return soma;

}

bool verticeExisteMatrix(int matriz[][TAM],int valor){

  valor = valor - 1;
  
  if(matriz[valor][valor] != -1){

    return true;

  }

  return false;

}

void ConstruirArestaMatrix(int matriz[][TAM],int vertice1,int vertice2){
  
  if(vertice1 != vertice2){
  
    if(verticeExisteMatrix(matriz,vertice1) == true && verticeExisteMatrix(matriz,vertice2) == true){

      if(N_aresta_AdjacentesMatrix(matriz,vertice1) < 3 && N_aresta_AdjacentesMatrix(matriz,vertice2) < 3){

        vertice1 = vertice1 - 1;
        vertice2 = vertice2 - 1;
        int distancia = 1 + (rand() % 20);
        matriz[vertice1][vertice2] = distancia;
        matriz[vertice2][vertice1] = distancia;
      
      }
    
    }
    
  }

}

void imprimir_matrix(int matriz[][TAM]){

  for (int i = 0; i < TAM; i++){
    if(matriz[i][i] != -1 ){
      printf("Matriz[%d]",i+1);
      for(int j = 0; j < TAM; j++){
        if(matriz[i][j] != -1 && i!=j){
          printf(" -> Matriz[%d] (%d)",j+1,matriz[i][j]);
        }
      }
    printf("\n");
    }

  }

}

void Dijkstra(int matriz[][TAM],int vertices[],int origem,int destino){

  
  
  
}

int main() {
  
  srand(time(NULL));

  int grafo_matriz[TAM][TAM]; //Matriz de adjacencia

  InicializandoMatrix(grafo_matriz); // Inicializando todos os valores na matriz com -1

  int numero_aleatorio; 

  int vertices[n_vertices];
  
  for(int i = 0; i< n_vertices; i++){ // n_vertices = 20
    numero_aleatorio = 1 + (rand() % TAM); //1 até 100
    ConstrutorVerticeMatrix(grafo_matriz,numero_aleatorio);
    vertices[i] = numero_aleatorio;
  }

  int numero_aleatorio2;

  for(int i = 0; i< n_vertices; i++){ // n_vertices = 20
    numero_aleatorio = rand() % 4;    // 0 até 3
    for(int j = 0; j< numero_aleatorio;j++){
      numero_aleatorio2 = 1 + rand() % n_vertices; //1 até 100
      ConstruirArestaMatrix(grafo_matriz,vertices[i],vertices[numero_aleatorio2]);
    }
  }
  
  imprimir_matrix(grafo_matriz);

  
  

  return 0;
  }