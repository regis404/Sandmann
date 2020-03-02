#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define tam 100
//substituir o "tam" pelo tamanho do vetor

int contadordeComp;
void Quick(int vetor[], int inicio, int fim);

int main()
{   int vetor[tam];
    int i /*= inicio*/, j /*= fim*/;

     printf("Gerando %d valores aleatorios...\n\n",tam);
     srand(time(NULL));
 
     for (i=0; i < tam; i++)
     {
     	vetor[i]=rand() % (tam*2);
           // gerando valores aleatórios na faixa de 0 a tam x 10
            printf("%d ", vetor[i]);
     }   
     printf("\n\nOrdenando...");
     Quick(vetor, tam-tam, tam-1);

      
    printf("\n\n ");
   	for(i=0; i < tam; i++)
    printf("%d ", vetor[i]);
    
    printf("\n\n%d Comparacoes! ", contadordeComp);
    return 0; 
    
 }
 void Quick(int vetor[tam], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      contadordeComp++;
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   contadordeComp++;
   if(inicio < j) Quick(vetor, inicio, j);
   contadordeComp++;
   if(i < fim) Quick(vetor, i, fim);   

}
