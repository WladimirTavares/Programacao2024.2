#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char buffer[1024];
int offset = 0;

void inicia_buffer(){
	memset(buffer, 0, sizeof(buffer));
	offset = 0;
}

void salva_buffer(char * s){
	int r = sprintf(buffer + offset, "%s", s);
	offset += r;
}

void mostra_buffer(){
	printf("%s\n", buffer);
}

void pula_linha(){
	salva_buffer("\n");
}

void print_space(int n){
	if(n == 0) return ;
	else {
		salva_buffer(" ");
		print_space(n-1);
	}
}

void print_asterisco(int n){
	if(n == 0) return ;
	else {
		salva_buffer("*");
		print_asterisco(n-1);
	}
}

/*
triangulo(4)
*\n
**\n
***\n
****\n   
*/

void triangulo(int n){
	if(n==1){
		print_asterisco(1);
		pula_linha();
	}else{
		triangulo(n-1);
		print_asterisco(n);
		pula_linha();
	}
}

void trianguloIterativo(int n){
	for(int i = 1; i <= n; i++){
		print_asterisco(i);
		pula_linha();
	}
}

/*
retangulo(4,5)
*****\n
*****\n
*****\n
*****\n  
*/

void retanguloIterativo(int n, int m){
	for(int i = 1; i <= n; i++){
		print_asterisco(m);
		pula_linha();
	}
}

void retangulo(int n, int m){
	return;
}


void letraVIterativo(int n){
	for(int i = n; i >= 1; i--){
		if(i == 1){
			print_space(n-i);
			print_asterisco(1);
			pula_linha();
		}else{
			print_space(n-i);
			print_asterisco(1);
			print_space(2*i-3);
			print_asterisco(1);
			pula_linha();
		}
	}
}

void letraV(int n){
	return ;
}

/*
**********\n
****  ****\n
***    ***\n
**      **\n
*        *\n
**      **\n
***    ***\n
****  ****\n
**********\n        
*/


void bandeira_iterativa(int n){
	for(int i = n; i >= 1; i--){
		print_asterisco(i);
		print_space(2*n-2*i);
		print_asterisco(i);
		pula_linha();
	}
	for(int i = 2; i <= n; i++){
		print_asterisco(i);
		print_space(2*n-2*i);
		print_asterisco(i);
		pula_linha();
	}
	
}

void bandeira(int n){
	return ;
}

int ordenado_iterativo(int v[], int n){
	for(int i = 2; i < n; i++){
		if(v[i-1] > v[i]) return 0;
	}
	return 1;
}

int ordenado_recursivo(int v[], int n){
	return 0;
}

void inverte_iterativo(char * s){
	int n = strlen(s);
	int i = 0;
	int j = n-1;
	while(i < j){
		char t = s[i];
		s[i] = s[j];
		s[j] = t;
		i++;
		j--;
	}
}

void __inverte(char * s, int i, int j){
	return ;
}

void inverte(char * s){
	int n = strlen(s);
	__inverte(s, 0, n-1);
}

void triangulo_teste(int n){
	char tmp[1024];
	
	inicia_buffer();
	trianguloIterativo(n);
	strcpy(tmp, buffer);
	inicia_buffer();
	triangulo(n);
		
	if( strcmp(buffer, tmp) == 0){
		printf("Teste : OK\n");
	}else{
		printf("Teste : FAIL\n");
	}
}


void problema1(){
	printf("Problema 1\n");	
	triangulo_teste(10);	
}

void retangulo_teste(int k, int n, int m){
	char tmp[1024];
	
	inicia_buffer();
	retanguloIterativo(n,m);
	strcpy(tmp, buffer);
	inicia_buffer();
	retangulo(n,m);
	
	printf("Teste %d: %s\n", k, ( strcmp(buffer, tmp) == 0) ? "OK" : "FAIL" );
}

void problema2(){
	printf("Problema 2\n");
	retangulo_teste(1,4,5);
	retangulo_teste(2,6,7);
}

void letraV_teste(int teste, int n){
	char tmp[1024];
	
	inicia_buffer();
	letraVIterativo(n);
	strcpy(tmp, buffer);
	inicia_buffer();
	letraV(n);
	printf("Teste %d: %s\n", teste, ( strcmp(buffer, tmp) == 0) ? "OK" : "FAIL" );
}

void problema3(){
	printf("Problema 3\n");
	letraV_teste(1,4);
	letraV_teste(2,6);
}






void bandeira_teste(int teste, int n){
	char tmp[1024];
	inicia_buffer();
	bandeira_iterativa(n);
	strcpy(tmp, buffer);
	inicia_buffer();
	bandeira(n);
	printf("Teste %d: %s\n", teste, ( strcmp(buffer, tmp) == 0) ? "OK" : "FAIL" );
}

void problema4(){
	printf("Problema 3\n");
	bandeira_teste(1,4);
	bandeira_teste(2,6);
	bandeira_teste(3,7);
	
}

void problema5(){
	printf("Problema 5\n");
	int n;
	
	int v1[] = {2,3,4,7,9,10};
	n = sizeof(v1)/sizeof(int);	
	printf("Teste 1 : %s\n", (ordenado_recursivo(v1,n) == 1) ? "OK" : "FAIL");
	
	int v2[] = {2,3,4,7,9,8};
	n = sizeof(v2)/sizeof(int);	
	printf("Teste 2 : %s\n", (ordenado_recursivo(v2,n) == 0) ? "OK" : "FAIL");
	
	int v3[] = {2,3,4,7,9,10,11,14,18,25};
	n = sizeof(v3)/sizeof(int);	
	printf("Teste 3 : %s\n", (ordenado_recursivo(v3,n) == 1) ? "OK" : "FAIL");
	
	int v4[] = {2,3,4,7,6,10,11,14,18,25};
	n = sizeof(v3)/sizeof(int);	
	printf("Teste 4 : %s\n", (ordenado_recursivo(v4,n) == 0) ? "OK" : "FAIL");
	
}

void teste_inverte1(){
	char s1[] = "xarope";
	char s2[] = "xarope";
	inverte(s1);
	inverte_iterativo(s2);
	printf("Teste 1 : %s\n", ( strcmp(s1, s2) == 0 ) ? "OK" : "FAIL");
}

void teste_inverte2(){
	char s1[] = "universidade";
	char s2[] = "universidade";
	inverte(s1);
	inverte_iterativo(s2);
	printf("Teste 2 : %s\n", ( strcmp(s1, s2) == 0 ) ? "OK" : "FAIL");
	
}

void problema6(){
	teste_inverte1();
	teste_inverte2();
	
	
	
}


int main(){
	//problema1();
	//problema2();
	//problema3();
	//problema4();
	//problema5();
	//problema6();
	
	
}
