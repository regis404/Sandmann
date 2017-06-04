#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define tam 600000
//substituir o "tam" pelo tamanho do vetor sem ultrapassar meio milhao

int main()
{
     int i, j, aux, vetor[tam],contadordeComp;
 
     printf("Gerando %d valores aleatorios...\n\n",tam);
     srand(time(NULL));
     for (i=0; i < tam; i++)
     {
     	vetor[i]=rand() % (tam*2);
           // gerando valores aleatórios na faixa de 0 a 1000
           printf("%d ", vetor[i]);
     }   
     printf("\n\nOrdenando...");
    for (i = 1; i < tam; i++) {
        for (j = 0; j < tam - 1; j++) {
        	contadordeComp++;//contando comparacoes
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    printf("\n\n ");
   	for(i=0; i < tam; i++)
    printf("%d ", vetor[i]);
    printf("\n\n%d Comparacoes! ", contadordeComp);
	return 0;
}

