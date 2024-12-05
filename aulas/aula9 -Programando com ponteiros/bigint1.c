#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct bigint {
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

int main(){
	bigint b = init_bigint("9999");
	b = incremento(b);
	imprime_bigint(b);
}
