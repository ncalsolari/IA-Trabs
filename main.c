#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "main.h"

int main(int argc, char *argv[]){

     if(argc == 1) {  //Execução sem enviar arquivo txt
        printf("[ERRO] Arquivo a ser lido não enviado\n");
        return 0;
    }

    

    No *ptrRaiz = (No *) malloc(sizeof (No));
   // No *ptrRaiz;
   // ptrRaiz = &Raiz;
    // No **ptrRaiz2 = (No **) malloc(sizeof (No));
    No **ptrRaiz2;
    ptrRaiz2 = &ptrRaiz;

    //printf("argv[2]:%c\n\n",*argv[3]);
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
    char matriz_global[linha][coluna];
    //criação da matriz
    int i=0;
    int j=0;
    int linha_inicio=0;
    int coluna_inicio=0;
    int linha_final=0;
    int coluna_final=0;

    int m_antiloop[4][linha*coluna];
    int *pmatriz;
     pmatriz = m_antiloop[0];
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
  
    for(i=0;i<(linha*coluna);i++){
        m_antiloop[0][i]=-1;
        m_antiloop[1][i]=-1;
        m_antiloop[2][i]=-1;
        m_antiloop[3][i]=-1;

    }

    for( i=0; i<linha;i++){

      

        for( j = 0; j<coluna; j ++){
            
            matriz[i][j]=buffer;
            matriz_global[i][j]=buffer;
           
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

    int pos_atual = 0;
    int pos_total = 0;
    int controle = 0;
    int indicador = 0;
    int v_indicador[linha*coluna];
    int v_proximos_nos[linha*coluna];
    int v_pais[linha*coluna];
    int posicao_i[linha*coluna];
    int posicao_j[linha*coluna];

    for(int x=0; x<(linha*coluna);x++){
        v_indicador[x]=0;
        v_proximos_nos[x]=0;
        v_pais[x]=0;
    }
    No **teste;

    constroi_arvore(pmatriz,ptrRaiz2,linha,coluna,matriz,linha_inicio,coluna_inicio,linha_final,coluna_final,controle,indicador,teste,m_antiloop,pos_atual,pos_total,v_proximos_nos,v_indicador,v_pais,posicao_i,posicao_j);

   

     for(int i=0; i<linha;i++){

        for(int j = 0; j<coluna; j ++){
           printf("%c ",matriz[i][j]);

        }

        printf("\n");
    }

  //  printf("inicio:\nlinha:%d coluna:%d\n\nfim:\nlinha:%d coluna:%d\n",linha_inicio,coluna_inicio,linha_final,coluna_final);


   
   int final = 0;
  
   int * ptrfinal ;
   
   ptrfinal = &final;

   int tam_max = (linha*coluna);
    int posicao_caminho = 0;
    char vetor_caminho[tam_max];
    for(int i = 0;i<tam_max;i++){
        vetor_caminho[i]='@';
    }
    
  
  // busca_profundidade(ptrRaiz2,linha_inicio,coluna_inicio,ptrfinal,posicao_caminho,tam_max,vetor_caminho,linha,coluna,matriz,linha_inicio,coluna_inicio);

    pos_atual = 0;
    pos_total = 0;
    int direcao = 0;

    int matriz_num [tam_max][tam_max];

    int v_filhos[tam_max];
    int v_direcao[tam_max];
    
    for(int i = 0;i<tam_max;i++){
        v_filhos[i]=0;
        v_direcao[i]=0;
        
    }
    for (int i=0;i<tam_max;i++){
        for(int j=0;j<tam_max;j++){
            matriz_num[i][j]=0;
        }
    }

    //reseta a matriz
    for (int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            matriz[i][j]=matriz_global[i][j];
        }
    }


  // busca_largura(ptrRaiz2,linha,coluna,tam_max,v_filhos,matriz_num,pos_atual,pos_total,v_direcao,direcao,matriz,linha_inicio,coluna_inicio);
   
   int matriz_custo[3][tam_max];
   int matriz_direcao[2][tam_max];
   int vetor_ordena[tam_max];
   int custoF = 0;
   int custoG = 0;

    for(int i =0; i<tam_max;i++){
        vetor_ordena[i]=0;
    }

    for (int i=0;i<3;i++){
        for(int j=0;j<tam_max;j++){
            matriz_custo[i][j]=0;
        }
    }

     for (int i=0;i<2;i++){
        for(int j=0;j<tam_max;j++){
            matriz_direcao[i][j]=0;
        }
    }
   
   //reseta a matriz
    for (int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            matriz[i][j]=matriz_global[i][j];
        }
    }
   
   for (int i=0;i<tam_max;i++){
        for(int j=0;j<tam_max;j++){
            matriz_num[i][j]=0;
        }
    }
   
  
   
    //busca_a_estrela(ptrRaiz2,custoF,custoG,tam_max,matriz_custo,matriz_num,linha,coluna,direcao,matriz_direcao,matriz,linha_inicio,coluna_inicio);
    
      for (int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            matriz[i][j]=matriz_global[i][j];
        }
    }


    for (int i=0;i<tam_max;i++){
        for(int j=0;j<tam_max;j++){
            matriz_num[i][j]=0;
        }
    }

    int m_custo[2][4];

    for(int i=0;i<2;i++){
        for(int j =0;j<4;j++){
            m_custo[i][j]=5000;
        }
    }

   busca_greedy(ptrRaiz2,custoF,tam_max,m_custo,matriz_num,linha,coluna,direcao,matriz,linha_inicio,coluna_inicio);

 for (int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            matriz[i][j]=matriz_global[i][j];
        }
    }


    for (int i=0;i<10;i++){
        for(int j=0;j<tam_max;j++){
            matriz_num[i][j]=0;
        }
       
    }


    for(int i=0;i<2;i++){
        for(int j =0;j<4;j++){
            m_custo[i][j]=5000;
        }
    }
    //busca_hillclimb(pmatriz,ptrRaiz2,custoF,tam_max,m_custo,matriz_num,linha,coluna,direcao,matriz,linha_inicio,coluna_inicio,m_antiloop);

   free (ptrRaiz);
 
    return 0;


   


}



