#include "stdio.h"
#include <string.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
	int procesador, cantidad, valor, recepcion;

	char* cad="tres tristes tigres tragaban trigo por culpa del Bolivar";
	int c=0;
	char *p;
	char *g;
	p=cad;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &procesador); //rank
	MPI_Comm_size(MPI_COMM_WORLD, &cantidad); //size 
	printf("procesador ejecutando %d de %d \n", procesador, cantidad);
	
	while(*p != '\0'){
		if(c%2==0){
			if(*p==' '){
				printf("%c",*p);
				c++;
			}else{
				printf("%c",*p);
			}
		}else{
			if(*p==' '){
				c++;
			}
		}
		p++;
	}
	p=cad;
	printf("\n");
	printf("El numero de espacios son: %i\n",c);


	if (procesador == 0 || procesador == 2)
	{
		printf("procesador: %i\n", procesador);
	   	while(*p != '\0'){
			if(c%2==0){
				if(*p==' '){
					printf("%c",*p);
					c++;
				}else{
					printf("%c",*p);
				}
			}else{
				if(*p==' '){
					c++;
				}
			}
			p++;
		}
		p=cad;
		printf("\n");
		printf("------------------------------------------\n");
	}
	if (procesador == 1 || procesador == 3)
	{
		printf("procesador: %i\n", procesador);
	   	while(*p != '\0'){
			if(c%2!=0){
				if(*p==' '){
					printf("%c",*p);
					c++;
				}else{
					printf("%c",*p);
				}
			}else{
				if(*p==' '){
					c++;
				}
			}
			p++;
		}
		p=cad;
		printf("\n");
		printf("------------------------------------------\n");
	}
MPI_Finalize();
}
