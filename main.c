#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){

     if(argc == 1) {  //Execução sem enviar arquivo txt
        printf("[ERRO] Arquivo a ser lido não enviado\n");
        return 0;
    }

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
    for(i; i<linha;i++){

        for( j = 0; j<coluna; j ++){
            
            matriz[i][j]=buffer;
             fread(&buffer,1,1,arq_entrada); 

        }

        if (buffer != '\n')
        {
            printf("caracter a mais em: M[%d][%d]\n",i,j);
            fread(&buffer,1,1,arq_entrada);
        }

        fread(&buffer,1,1,arq_entrada);

    }


     for(int i=0; i<linha;i++){

        for(int j = 0; j<coluna; j ++){
           printf("%c ",matriz[i][j]);

        }

        printf("\n");
    }


    return 0;


   


}



