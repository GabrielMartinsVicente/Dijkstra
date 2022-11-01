#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
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
 
  while(matriz[valor][valor] == 0 || matriz[valor][valor] == 1){
    valor =  (rand() % TAM); //0 até 99
  }

  matriz[valor][valor] = 0;

}

int N_aresta_AdjacentesMatrix(int matriz[][TAM],int valor){

  int soma = 0;

  for (int i = 0; i < TAM; i++){

    if(matriz[valor][i] != -1 && matriz[valor][i] != 0){
      soma += 1;
    }

  }

  return soma;

}

bool verticeExisteMatrix(int matriz[][TAM],int valor){
  
  if(matriz[valor][valor] != -1){

    return true;

  }

  return false;

}

void ConstruirArestaMatrix(int matriz[][TAM],int vertice1,int vertice2){
  
  if(vertice1 != vertice2){
  
    if(verticeExisteMatrix(matriz,vertice1) == true && verticeExisteMatrix(matriz,vertice2) == true){

      if(N_aresta_AdjacentesMatrix(matriz,vertice1) < 3 && N_aresta_AdjacentesMatrix(matriz,vertice2) < 3){

        int distancia = 1 + (rand() % 20);
        matriz[vertice1][vertice2] = distancia;
        matriz[vertice2][vertice1] = distancia;
      
      }
    
    }
    
  }

}

void imprimir_matrix(int matriz[][TAM]){

  printf("\n\nImpressão Grafo\n\n");
  for (int i = 0; i < TAM; i++){
    if(matriz[i][i] != -1 ){
      printf("Matriz[%d]",i+1); //i+1
      for(int j = 0; j < TAM; j++){
        if(matriz[i][j] != -1 && i!=j){
          printf(" -> Matriz[%d] (%d)",j+1,matriz[i][j]); //j+1
        }
      }
    printf("\n");
    }

  }

}

void Vertices(int matriz[][TAM],int vertice[]){  //Passa os valores dos Vértices para um Vetor

  int j = 0;
  for (int i = 0; i < TAM; i++){
    if(matriz[i][i] != -1 ){
      vertice[j] = i;
      j++;
    }
  }
    
}

void Dijkstra(int matriz[][TAM]){

  //-------Inicialização--------
  int vertice[n_vertices];

  Vertices(matriz,vertice);

  int visitado[n_vertices];
  int distancia[n_vertices];
  int predecessor[n_vertices];

  for(int t = 0; t<n_vertices; t++){
    visitado[t] = 0;
    distancia[t] = INT_MAX/2;
    predecessor[t] = -1;
  }
  //-------------------------

  // O vertice inicial será o 1° vertice na ordem crescente 

  int i;   // variável para interar entre os valores 
  int v;   // variável que armazena valor do vertice
  int p;   // variável que armazena o valor dos pesos das arestas

  i = 0;
  distancia[i] = 0;
  predecessor[i] = 0;
  
  bool chave = false;

  while(chave == false){
    
    v = vertice[i];
    visitado[i] = 1;

    for(int k = 0; k<TAM; k++){
  
      p = matriz[v][k];
  
      if(p != -1 && p != 0){
  
        for(int l = 0; l< n_vertices; l++){
  
          if(k == vertice[l] && visitado[l] == 0){
            
            if(distancia[l] > (distancia[i]+p)){
              distancia[l] = distancia[i]+p;
              predecessor[l] = i; 
            }
          }
        }
      }


    }
    
    i = -1;
    int aux = INT_MAX/2;
    for(int x = 0; x<n_vertices; x++){

      if(visitado[x] == 0){
        if(distancia[x] < aux){
          aux = distancia[x];
          i = x;
        }

      }
      
    }

    if(aux == INT_MAX/2){ 
      chave = true;
    }  

  }

  printf("\n\nVISITA\n\n");
  for(int r = 0; r<n_vertices; r++){

    if(visitado[r] == 1){
      printf("Visita[%d] = Visitado\n",vertice[r]+1);
    }
    else{
      printf("Visita[%d] = Não Visitado\n",vertice[r]+1);
    }

  }

  printf("\n\nDISTANCIA\n\n");
  for(int r = 0; r<n_vertices; r++){

    if(distancia[r] == INT_MAX/2){
       printf("Distancia[%d] = Infinito\n",vertice[r]+1);
    }
    else{
      printf("Distancia[%d] = %d\n",vertice[r]+1,distancia[r]);
    }
   

  }
  
  printf("\n\nPREDECESSOR\n\n");
  for(int r = 0; r<n_vertices; r++){

    if(predecessor[r] == -1){
      printf("Predecessor[%d] = NULL\n",vertice[r]+1);
    }
    else{
      printf("Predecessor[%d] = %d\n",vertice[r]+1,vertice[predecessor[r]]+1);
    }

  }

}

void imprimir_arestas(int matriz[][TAM]){

  printf("\n\nLista de pesos de cada Aresta de cada um dos Vértices\n\n");
  for (int i = 0; i < TAM; i++){
    if(matriz[i][i] != -1 ){
      for(int j = 0; j < TAM; j++){
        if(matriz[i][j] != -1 && i!=j){
          printf("[%d,%d,%d]\n",i+1,j+1,matriz[i][j]);
        }
      }
    }

  }
  
}

int main() {
  
  srand(time(NULL));

  int grafo_matriz[TAM][TAM]; //Matriz de adjacencia

  InicializandoMatrix(grafo_matriz); // Inicializando todos os valores na matriz com -1

  int numero_aleatorio; 

  int vertices[n_vertices];
  
  for(int i = 0; i< n_vertices; i++){ // n_vertices = 20
    numero_aleatorio = (rand() % TAM); //0 até 99
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

  imprimir_arestas(grafo_matriz);
  
  Dijkstra(grafo_matriz);

  return 0;
  }