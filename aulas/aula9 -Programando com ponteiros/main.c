#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListaDinamica{
    int * v;
    int tamanhoAtual;
    int tamanhoMaximo;
} ListaDinamica;


void inicializa(ListaDinamica * L){
    L->tamanhoAtual = 0;
    L->tamanhoMaximo = 2;
    L->v = (int *)malloc(L->tamanhoMaximo*sizeof(int));
}

void push_back(ListaDinamica * L, int valor){
    if(L->tamanhoAtual < L->tamanhoMaximo ){
        L->v[L->tamanhoAtual] = valor;
        L->tamanhoAtual++;
    }else{
        int * v2 = (int *)malloc(2*L->tamanhoAtual*sizeof(int));
        for(int i = 0; i < L->tamanhoAtual; i++){
			v2[i] = L->v[i];
		}
        
        free(L->v);
        L->v = v2;
        L->tamanhoMaximo = 2*L->tamanhoAtual;
        push_back(L, valor);
    }
}

void pop_back(ListaDinamica * L){
	if(L->tamanhoAtual > 0){
		L->tamanhoAtual--;
	}
}

void mostra(ListaDinamica * L){
    printf("[");
    for(int i = 0; i < L->tamanhoAtual; i++)
        printf("%d ", L->v[i]);
    printf("]\n");
}

int main(){
    ListaDinamica * L = (ListaDinamica* )malloc(sizeof(ListaDinamica));
    inicializa(L);
    for(int i = 0; i < 16; i++){
		push_back(L, i);
		mostra(L);
	} 
}
