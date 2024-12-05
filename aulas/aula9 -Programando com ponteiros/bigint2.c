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




void incremento(bigint * b){
	for(int i = 0; i < b->size; i++){
		if( b->digit[i] < '9'){
			b->digit[i]++;
			return ;
		}else{
			b->digit[i] = '0';
		}
	}
	b->digit[b->size] = '1';
	b->size++;
}

void imprime_bigint(bigint * b){
	printf("bigint: ");
	for(int i = b->size-1; i >= 0; i--)
		printf("%c", b->digit[i]);
	printf("\n");
}

int main(){
	bigint b = init_bigint("9999");
	incremento(&b);
	imprime_bigint(&b);
}
