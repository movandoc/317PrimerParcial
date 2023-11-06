#include <stdio.h>
#include <string.h>
#include "omp.h"

void main(){
	int cantidad, procesador;
	int suma1=0, suma2=0;
	
	char* cad="tres tristes tigres tragaban trigo por culpa del Bolivar";
	int c=0;
	char *p;
	char *g;
	p=cad;
	g=cad;
	#pragma omp parallel
	{
		#pragma omp single
		{
			cantidad = omp_get_num_threads();
			procesador = omp_get_thread_num();
			printf("Proceso cantidad de procesadores %d, procesador %d \n", cantidad, procesador);
			
			while(*p != '\0'){
				if(c%2==0){
					if(*p==' '){
						printf("%c",*p);
						c++;
						suma1=suma1+1;
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
			suma1=suma1+1;
			printf("\n");
			printf("El numero de palabras par son: %i\n",suma1);
		}
		
		
		printf("------------------------------------------\n");
		#pragma omp critical
		{
			cantidad = omp_get_num_threads();
			procesador = omp_get_thread_num();
			printf("Proceso cantidad de procesadores %d, procesador %d \n", cantidad, procesador);
			
			while(*g != '\0'){
				if(c%2!=0){
					if(*g==' '){
						printf("%c",*g);
						c++;
						suma2++;
					}else{
						printf("%c",*g);
					}
				}else{
					if(*g==' '){
						c++;
					}
				}
				g++;
			}
			g=cad;
			printf("\n");
			printf("El numero de palabras impares son: %i\n",suma2);
		}
		
		
		printf("Cantidad de palabras 1: %d, Cantidad de palabras 2: %d\n", suma1, suma2);
	
	}
}
