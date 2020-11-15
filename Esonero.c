#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char testo_M[128];
char testo_K[128];
char testo_C[128];
int so,i,j;
int menu_scelta;
int lun_M,lun_K;


void InserisciK()
{
//LETTURA STRINGA INPUT
  printf("Inserire chiave K che non superi il testo precedente: \n");
  //fgets(testo_K,128,stdin);
  do{
    //printf("Inserire chiave K che non superi il testo precedente: \n");
    fgets(testo_K,128,stdin);
    (so = getchar() != '\0');
  }
  while( strlen(testo_K) > strlen(testo_M) );

}
  void GeneraK()
{
//GENERAZIONE NUMERO CASUALE
  time_t t;
  srand((unsigned) time(&t));
  printf("La sua chiave K casuale è:\n");
  for (i=0;i<strlen(testo_M)-1;i++)
  {
    testo_K[i]=(32+rand() % 96);
    printf("_%d",testo_K[i]);
  }
  printf("\n");
}

int main()
{
printf("Inserire testo da codificare (MAX=128 caratteri):\n");
    fgets(testo_M,128,stdin);
    lun_M = strlen(testo_M);
    lun_K = strlen(testo_K);
    fflush(stdin);

    printf("Lunghezza testo: %d caratteri.\n\n",(lun_M-1));

//MENU DI SELEZIONE
printf("Come vuole procedere?\n");
printf("-0 Termina processo.\n");
printf("-1 Insere manualmente chiave K.\n");
printf("-2 Genera casuale una chiave K.\n");

scanf("%d",&menu_scelta);
switch(menu_scelta)
{
  case 1:
        {
        InserisciK();
//OPERAZIONE XOR(1)
        for (i=0; i<strlen(testo_M); ++i){
          testo_C[i] = testo_M[i] ^ testo_K[i];
        }
        printf("Messaggio codificato:\n");
        printf("%s\n",testo_C);

//RICONVERSIONE TESTO ORIGINALE(1)
        for(i=0 ; i<strlen(testo_M)-1 ; i++){
           testo_M[i]=testo_C[i]^testo_K[i];
            }
        printf("Ecco cosa aveva inserito: %s\n", testo_M);
        break;
        }
case 2:
        {
        GeneraK();
//OPERAZIONE XOR(2)
        for (i=0; i<strlen(testo_M); ++i){
          testo_C[i] = testo_M[i] ^ testo_K[i];
          }
        printf("Messaggio codificato:\n");
        printf("%s\n",testo_C);

//RICONVERSIONE TESTO ORIGINALE(2)
        for(i=0 ; i<strlen(testo_M)-1 ; i++)
          testo_M[i]=testo_C[i]^testo_K[i];

        printf("Ecco cosa aveva inserito: %s\n", testo_M);
        break;
        }
case 0:
        printf("Processo terminato.\n");
        break;
      }
return 0;
}
