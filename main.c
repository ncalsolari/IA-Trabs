#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "main.h"

int main(int argc, char *argv[]){

     if(argc == 1) {  //Execução sem enviar arquivo txt
        printf("[ERRO] Arquivo a ser lido não enviado\n");
        return 0;
    }
printf("a");

    //No Raiz;

    No *ptrRaiz = (No *) malloc(sizeof (No));
  // No *ptrRaiz;
   // ptrRaiz = &Raiz;
printf("b");
    // No **ptrRaiz2 = (No **) malloc(sizeof (No));
    No **ptrRaiz2;
    ptrRaiz2 = &ptrRaiz;


    FILE *arq_entrada = fopen(argv[1],"r");
    int linha, coluna;
    char buffer_matriz[2];
    char buffer;

    if(arq_entrada == NULL){
        printf("[ERRO] Arquivo Vazio");
        return 0;
    }

    fseek(arq_entrada,0,SEEK_SET);

    fread(&buffer_matriz,2,1,arq_entrada);
    linha = atoi(buffer_matriz); //transforma a string em numero
    printf("Linha: %d\n", linha);
  
    fread(&buffer,1,1,arq_entrada); //le o espaço
   
    fread(&buffer_matriz,2,1,arq_entrada);
    coluna = atoi(buffer_matriz); //transforma a string em numero
    printf("Coluna: %d\n", coluna);
    fread(&buffer,1,1,arq_entrada); //le o qubra de linha
    fread(&buffer,1,1,arq_entrada); //le o qubra de linha
    //printf("proximo char:%c\n", buffer);
    char matriz[linha][coluna];
    //criação da matriz
    int i=0;
    int j=0;
    int linha_inicio=0;
    int coluna_inicio=0;
    int linha_final=0;
    int coluna_final=0;
/*
    int * ptr_linha;
    int * ptr_coluna;
    int * ptr_linha_inicio;
    int * ptr_coluna_inicio;
    int * ptr_linha_final;
    int * ptr_coluna_final;
    char * ptr_matriz;

    ptr_linha = &i;
    ptr_coluna = &j;
    ptr_linha_inicio = &linha_inicio;
    ptr_coluna_inicio = &coluna_inicio;
    ptr_linha_final = &linha_final;
    ptr_coluna_final = &coluna_final;
   
    constroi_matriz(ptr_linha,ptr_coluna,ptr_linha_inicio,ptr_coluna_inicio,ptr_linha_final,ptr_coluna_final);
*/
  

    for( i; i<linha;i++){

      

        for( j = 0; j<coluna; j ++){
            
            matriz[i][j]=buffer;
            if(matriz[i][j]=='#'){
                linha_inicio = i;
                coluna_inicio = j;
            }

            if(matriz[i][j]=='$'){
                linha_final = i;
                coluna_final = j;
            }
            
            fread(&buffer,1,1,arq_entrada); 

        }

        if (buffer != '\n')
        {
            printf("caracter a mais em: M[%d][%d]\n",i,j);
            fread(&buffer,1,1,arq_entrada);
        }

        fread(&buffer,1,1,arq_entrada);

    }
    int controle = 0;
    int indicador = 0;
    
     constroi_arvore(ptrRaiz2,linha,coluna,matriz,linha_inicio,coluna_inicio,controle,indicador);


    printf("\n");

     for(int i=0; i<linha;i++){

        for(int j = 0; j<coluna; j ++){
           printf("%c ",matriz[i][j]);

        }

        printf("\n");
    }

    printf("inicio:\nlinha:%d coluna:%d\n\nfim:\nlinha:%d coluna:%d\n",linha_inicio,coluna_inicio,linha_final,coluna_final);


    teste_matriz_referencia(linha,coluna,matriz);

   free (ptrRaiz);
   
    return 0;


   


}



