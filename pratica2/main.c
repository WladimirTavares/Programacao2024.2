#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct bigInt {
	char digit[101];
	int size;
} bigint;

void reverse(char s[]){
	int i = 0;
	int j = strlen(s)-1;
	while(i<j){
		char t = s[i];
		s[i] = s[j];
		s[j] = t;
		i++;
		j--;
	}
}


bigint init_bigint(char s[]){
	bigint b;
	b.size = strlen(s);
	strcpy(b.digit, s);
	reverse(b.digit);
	return b;
}




int char2int(char c){
	return c-'0';
}

char int2char(int v){
	return '0'+v;
}

bigint incremento(bigint b){
	bigint c = b;
	
	for(int i = 0; i < c.size; i++){
		if( c.digit[i] < '9'){
			c.digit[i]++;
			return c;
		}else{
			c.digit[i] = '0';
		}
	}
	c.digit[c.size] = '1';
	c.size++;
	return c;
}


void imprime_bigint(bigint b){
	printf("bigint: ");
	for(int i = b.size-1; i >= 0; i--)
		printf("%c", b.digit[i]);
	printf("\n");
}


bigint soma(bigint a, bigint b){
	bigint c = init_bigint("");
	return c;
} 

bigint soma_boquinha(bigint a, bigint b){
	bigint c = init_bigint("");
	return c;
} 


bigint shift(bigint a, int n){
	bigint c;
	return c;	
}


//maior(a,b) = -1 se a > b, 0 se a==b, 1 se a<b
int maior(bigint a, bigint b){
	return 0;
}

void problema1(){
	printf("Problema 1\n");
	
	bigint a, b;
	
	a = init_bigint("123");
	b = init_bigint("323");   
	printf("Teste 1: %s\n", (maior(a,b) == 1) ?"OK":"FAIL");
	
	a = init_bigint("123");
	b = init_bigint("123");   
	printf("Teste 2: %s\n", (maior(a,b) == 0) ?"OK":"FAIL");
	
	a = init_bigint("3523");
	b = init_bigint("323");   
	printf("Teste 3: %s\n", (maior(a,b) == -1) ?"OK":"FAIL");
	
	a = init_bigint("3523");
	b = init_bigint("45523");   
	printf("Teste 3: %s\n", (maior(a,b) == 1) ?"OK":"FAIL");
	
}


void problema2(){
	printf("Problema 2\n");
	
	bigint a, b, c;
	
	a = init_bigint("123");
	b = init_bigint("323");
	c = soma(a,b);   
	printf("Teste 1: %s\n", ( strcmp(c.digit, "644")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("123");
	b = init_bigint("123");   
	c = soma(a,b);
	printf("Teste 2: %s\n", ( strcmp(c.digit, "642")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("3523");
	b = init_bigint("323");
	c = soma(a,b);   
	printf("Teste 3: %s\n", ( strcmp(c.digit, "6483")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("3523");
	b = init_bigint("48523");   
	c = soma(a,b);//52046
	printf("Teste 4: %s\n", ( strcmp(c.digit, "64025")==0 ) ?"OK":"FAIL");
	
}


void problema3(){
	printf("Problema 3\n");
	
	bigint a;
	a = init_bigint("123");
	a = shift(a,3);   
	printf("Teste 1: %s\n", ( strcmp(a.digit, "000321")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("8567");
	a = shift(a,-2);   
	printf("Teste 2: %s\n", ( strcmp(a.digit, "58")==0 ) ?"OK":"FAIL");
	
	a = init_bigint("8567");
	a = shift(a,-5);   
	printf("Teste 3: %s\n", ( strcmp(a.digit, "0")==0 ) ?"OK":"FAIL");
	

}

void problema4(){
	printf("Problema 4\n");
	bigint a, b, c, d;
	a = init_bigint("6");
	b = init_bigint("9");
	c = init_bigint("51");
	d = soma_boquinha(a,b); // 51
	printf("Teste 1: %s\n", ( strcmp(c.digit, d.digit )==0 ) ?"OK":"FAIL");

	a = init_bigint("734");
	b = init_bigint("812");
	c = init_bigint("5146");
	d = soma_boquinha(a,b); // 5146
	printf("Teste 2: %s\n", ( strcmp(c.digit, d.digit )==0 ) ?"OK":"FAIL");

	a = init_bigint("999");
	b = init_bigint("999");
	c = init_bigint("4221");
	d = soma_boquinha(a,b);
	printf("Teste 3: %s\n", ( strcmp(c.digit, d.digit) ==0 ) ?"OK":"FAIL");

	a = init_bigint("3523");
	b = init_bigint("48523");
	c = init_bigint("61046");
	d = soma_boquinha(a,b);
	printf("Teste 4: %s\n", ( strcmp(c.digit, d.digit)==0 ) ?"OK":"FAIL");
}

int main(){
	
	//problema1();
	//problema2();
	//problema3();
	problema4();
}



