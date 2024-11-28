#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int maior_menor_media(int L[], int N){
	return 0;
}

int impares_ordem_crescente(int L[], int N){
	return 0;
}

void remova_duplicados_consecutivos(char L[]){
	return ;
}

int numero_ocorrencia_linear(int L[], int N, int k){
	return 0;
}

int numero_ocorrencia_jump(int L[], int N, int k){
	return 0;
}

int pico_bitonica_binaria(int L[], int N){
	return 0;
}

void problema1(){
	printf("Problema 1\n");
	int teste1[] = {5,1,3 ,10 ,8,13,6,12,4,16};
	int n = sizeof(teste1)/sizeof(int);
	if (maior_menor_media(teste1,n) == 6)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");
}

void problema2(){
	printf("Problema 2\n");
	int teste1[] = {2,1,8,4,5,6,16,7,9,12};
	int n = sizeof(teste1)/sizeof(int);
	if (impares_ordem_crescente(teste1,n) == 6)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");
}

void problema3(){
	printf("Problema 3\n");
	char s[] = "aaabbbccdd";
	
	remova_duplicados_consecutivos(s);
	
	if ( strcmp(s, "abcd") == 0)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");
}

int generate_sequence(int v[], int n, int m, int k){
	int cont = 0 ;
	
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		v[i] = rand() % m;
		if(v[i] == k) cont++;   
	}
	return cont;
}

int compara(const void *a, const void *b)
{
  return * (int *)a - * (int *)b;
}

void imprime_lista(int v[], int n){
	printf("[");
	printf("%d", v[0]);
	for(int i = 1; i < n; i++)
		printf(" , %d", v[i]);
	printf("]\n");
}

void problema4a(){
	printf("Problema 4a\n");
	int teste1[] = {1,2,2,2,3,3,4,5,6,7};
	int n = sizeof(teste1)/sizeof(int);
	if (numero_ocorrencia_linear(teste1,n,2) == 3)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");
	
	if (numero_ocorrencia_linear(teste1,n,3) == 2)
		printf("Teste 2: OK\n");
	else
		printf("Teste 2: FAIL\n");

	
	for(int i = 0; i < 5; i++){
		int n = rand() % 30 + 8 ;
		int v[n];
		int r = rand() % (n/2);
		int cont = generate_sequence(v, n, n/2, r);
		qsort(v, n, sizeof(int), compara);
		printf("v[] = "); 
		imprime_lista(v, n);
		printf("k = %d\n", r);
		printf("cont = %d\n", cont);
		if (numero_ocorrencia_linear(v,n,r) == cont)
			printf("Teste %d: OK\n", i + 3);
		else
			printf("Teste %d: FAIL\n", i + 3);

	}
	printf("\n\n");
}



void problema4b(){
	printf("Problema 4b\n");
	int teste1[] = {1,2,2,2,3,3,4,5,6,7};
	int n = sizeof(teste1)/sizeof(int);
	if (numero_ocorrencia_jump(teste1,n,2) == 3)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");
	
	if (numero_ocorrencia_jump(teste1,n,3) == 2)
		printf("Teste 2: OK\n");
	else
		printf("Teste 2: FAIL\n");

}

int generate_sequence_bitonic(int v[], int n, int m){
	int pico;
	
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		v[i] = rand() % m;   
	}
	
	qsort(v, n, sizeof(int), compara);
	
	//pico : maior elemento	
	pico = v[n-1];
	
	int r = rand() % n;
	
	int i = r;
	int j = n-1;
	
	while( i < j ){
		int t = v[i];
		v[i] = v[j];
		v[j] = t;
		i++;
		j--;
	}	
		
	return pico;
}




void problema5(){
	printf("Problema 5\n");
	int teste1[] = {0,1,4,9,16,10,12,5,3};
	int n = sizeof(teste1)/sizeof(int);
	
	if (pico_bitonica_binaria(teste1,n) == 16)
		printf("Teste 1: OK\n");
	else
		printf("Teste 1: FAIL\n");
	
	n = 100;
	int v[n];
	int pico;
	
	pico = generate_sequence_bitonic(v, n, 1000);	
	printf("v[] = "); 
	imprime_lista(v, n);
	printf("pico = %d\n", pico);
		
	if (pico_bitonica_binaria(v,n) == pico)
		printf("Teste 2: OK\n");
	else
		printf("Teste 2: FAIL\n");
}

int main(){
	//problema1();
	//problema2();
	//problema3();
	//problema4a();
	//problema4b();
	problema5();
	
	
}
