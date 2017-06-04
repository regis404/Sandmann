#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define tam 1000000
int *vetor = (int*) malloc(tam*sizeof(int));
void merge(int vetor[], int comeco, int meio, int fim);
void mergeSort(int vetor[], int comeco, int fim);
int contadordeComp;


int main()
{
    
    int i /*= inicio*/, j /*= fim*/;

     printf("Gerando %d valores aleatorios...\n\n",tam);
     srand(time(NULL));
 
     for (i=0; i < tam; i++)
     {
     	vetor[i]=rand() % (tam*2);
           // gerando valores aleatórios na faixa de 0 a tam x 10
           // printf("%d ", vetor[i]);
     }   
     printf("\n\nOrdenando...");
     mergeSort(vetor, tam-tam, tam-1);

      
    printf("\n\n ");
   	//for(i=0; i < tam; i++)
   // printf("%d ", vetor[i]);
    
    printf("\n\n%d Comparacoes! ", contadordeComp);
    return 0; 
    
}
void merge(int vetor[], int comeco, int meio, int fim) {
	int com1 = comeco, com2 = meio+1, comAux = 0;
	int vetAux[fim-comeco+1];
contadordeComp++;
while(com1<=meio && com2<=fim){
	contadordeComp++;
         if(vetor[com1] <= vetor[com2]){
             vetAux[comAux] = vetor[com1];
             com1++;
         }else{
             vetAux[comAux] = vetor[com2];
             com2++;
         }
         comAux++;
     }
 contadordeComp++;
    while(com1<=meio){  //Caso ainda haja elementos na primeira metade
         vetAux[comAux] = vetor[com1];
         comAux++;com1++;
     }
 contadordeComp++;
     while(com2<=fim){   //Caso ainda haja elementos na segunda metade
         vetAux[comAux] = vetor[com2];
         comAux++;com2++;
     }
contadordeComp++;
     for(comAux=comeco;comAux<=fim;comAux++){    //Move os elementos de volta para o vetor original
         vetor[comAux] = vetAux[comAux-comeco];
     }
}
 
void mergeSort(int vetor[], int comeco, int fim){
   contadordeComp++;
   if (comeco < fim) {
         int meio = (comeco+fim)/2;
 
         mergeSort(vetor, comeco, meio);
         mergeSort(vetor, meio+1, fim);
         merge(vetor, comeco, meio, fim);
     } 
}

