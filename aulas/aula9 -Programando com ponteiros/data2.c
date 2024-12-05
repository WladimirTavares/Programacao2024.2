#include <stdio.h>
#include <string.h>

struct Data{
	int dia;
	int mes;
	int ano;
	char evento[51];
};

typedef struct Data Data;


void criar_data(Data * d, int dia, int mes, int ano, char evento[]){
	
	d->dia = dia;
	d->mes = mes;
	d->ano = ano;
	strcpy(d->evento, evento);
}

void imprime_data(Data* d){
	printf("%02d/%02d/%4d: %s\n", d->dia, d->mes, d->ano, d->evento);
}

int main(){
	Data d1;
	criar_data(&d1,7,9,1822,"Dia da Independencia");
	imprime_data(&d1);
}
