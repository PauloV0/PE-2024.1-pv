#include <stdio.h>
#include <stdlib.h>

// estrutura q representa conjunto

typedef struct {
    
    int *elements; //vetor de elementos do conjunto
    int size;     //tamanho do conjunto
} Conjunto;  //nome da estrutura


//funçao q inicializa um conjunto vazio

void inicializarConjunto(Conjunto *conjunto) {
    conjunto->elements = NULL;
    conjunto->size = 0;
    
}

//funçao q adiciona um elemento conjunto

void adicionarElemento(Conjunto *conjunto, int element) {
    conjunto->size++;
    conjunto->elements = realloc(conjunto->elements, conjunto->size * sizeof(int));
    conjunto->elements[conjunto->size - 1] = element;
} 

// funçao q verifica se um elemento esta no conjunto

int isHere(Conjunto conjunto, int element) {
    for (int i = 0; i < conjunto.size; i++){
      if (conjunto.elements[i] == element){
          return 1; //retorna 1 se o elemento esta presente
      }

    } 
    return 0; //retorna 0 se o elemento nao esta
}

//funçao q imprime um conjunto

void imprimirConjunto(Conjunto conjunto){
    printf("{");
    for (int i = 0; i < conjunto.size; i++){
        printf("%d", conjunto.elements[i]);
        if (i <conjunto.size - 1){
            printf(", "); //separa os numeros por virgulas
        }
    }
    printf("}\n");
}

int main(){
    //declarar variaveis
    Conjunto conjuntoA, conjuntoB, uniao, intersecao, difAB, difBA;
    int sizeA, sizeB, element;
    
    //inicializar os conjuntos
    
    inicializarConjunto(&conjuntoA);
    inicializarConjunto(&conjuntoB);
    inicializarConjunto(&uniao);
    inicializarConjunto(&intersecao);
    inicializarConjunto(&difAB);
    inicializarConjunto(&difBA);
    
    printf("Digite o tamanho do conjunto A: ");
    scanf("%d", &sizeA);
    printf("Digite o tamanho do conjunto B: ");
    scanf("%d", &sizeB);
    
    // elementos de a
    
    printf("Digite os elementos de A (sem repeticoes):\n");
    for (int i = 0; i < sizeA; i++) {
        scanf("%d", &element);
        if (!isHere(conjuntoA, element)){
            adicionarElemento(&conjuntoA, element);
        }
        
    }
  
    // elementos de b
    
    printf("Digite os elementos de B (sem repeticoes):\n");
    for (int i = 0; i < sizeB; i++) {
        scanf("%d", &element);
        if (!isHere(conjuntoB, element)){
            adicionarElemento(&conjuntoB, element);
        }
        
    }
  
  // uniao
  
  for(int i = 0; i < conjuntoA.size; i++){
      adicionarElemento(&uniao, conjuntoA.elements[i]);
  } 
 
  for(int i = 0; i < conjuntoB.size; i++){
      if(!isHere(uniao, conjuntoB.elements[i])){
 
      adicionarElemento(&uniao, conjuntoB.elements[i]);
      
      }
  }
  
  // intersecao
  
  for(int i = 0; i < conjuntoA.size; i++){
      if(isHere(conjuntoB,conjuntoA.elements[i])){
          adicionarElemento(&intersecao, conjuntoA.elements[i]);
      }
  }
  
  // diferença A - B
  
  for (int i = 0; i < conjuntoA.size; i++) {
      if(!isHere(conjuntoB, conjuntoA.elements[i])){
          adicionarElemento(&difAB, conjuntoA.elements[i]);
      }
  }
  
  // diferença B - A
  
  for (int i = 0; i < conjuntoB.size; i++) {
      if(!isHere(conjuntoA, conjuntoB.elements[i])){
          adicionarElemento(&difBA, conjuntoB.elements[i]);
      }
  }
  
  // impressao dos resultados
  
  
  printf("\nUnião dos conjuntos:\n");
  imprimirConjunto(uniao);
  
  printf("\nInterseção dos conjuntos:\n");
  imprimirConjunto(intersecao);
  
  printf("\nDiferença A - B:\n");
  imprimirConjunto(difAB);
  
  printf("\nDiferença B - A:\n");
  imprimirConjunto(difBA);
  
  //liberaçao da memoria
  
  free(conjuntoA.elements);
  free(conjuntoB.elements);
  free(uniao.elements);
  free(intersecao.elements);
  free(difAB.elements);
  free(difBA.elements);
  
  return 0;
  
}


