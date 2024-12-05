#include <stdio.h>

struct Data{
	int dia;
	int mes;
	int ano;
	char evento[51];
};

typedef struct Data Data;


Data criar_data(int dia, int mes, int ano, char evento[]){
	Data d;
	d.dia = dia;
	d.mes = mes;
	d.ano = ano;
	int i;
	for(i = 0; evento[i] != '\0'; i++){
		d.evento[i] = evento[i];
	}
	d.evento[i] = '\0';
	//strcpy(d.evento, evento);
	return d;
}

void imprime_data(Data d){
	printf("%02d/%02d/%4d: %s\n", d.dia, d.mes, d.ano, d.evento);
}

int main(){
	Data d1 = criar_data(7,9,1822,"Dia da Independencia");
	imprime_data(d1);
}
