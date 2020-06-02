#ifndef MAIN_H
#define MAIN_H

struct No{
    char valor;
    int visitado;
    struct No *esquerda;
    struct No *baixo;
    struct No * direita;
    struct No * cima;
};
typedef struct No No;
/*
void constroi_matriz(int *linha,int *coluna,int *inicio_i,int *inicio_j,int *fim_i,int *fim_j, char * m,char matriz[][]){
   */




int constroi_arvore(No **pRaiz,int linha, int coluna, char M[linha][coluna], int linha_inico, int coluna_inicio,int controle,int indicador){
    int i = linha_inico;
    int j = coluna_inicio;
    
    
    if(M[i][j-1] == '$' || M[i+1][j] == '$' || M[i][j+1] == '$' || M[i-1][j] == '$'){
        printf("\nfim encontrado\nm[%d][%d]\n",i,j);
        
    }
   
    


   // if (*pRaiz == NULL){ // primeiro caso
   if (controle == 0){ // primeiro caso
        *pRaiz =  (No *) malloc(sizeof (No));
        (*pRaiz)->valor = M[i][j];
        (*pRaiz)->visitado = 0;
        indicador = 0;
        printf("inicio");
        controle = 1;
        constroi_arvore(&(*pRaiz),linha,coluna,M,i,j,controle,indicador);
        return 0;
        
    }else{
        // checa se o redor do no eh valido pra receber valor
        if(j-1 >= 0 ){

              if(indicador == 3){
            
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = 'A';
                (*pRaiz)->esquerda->visitado=1;
               // printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

            }else{
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = M[i][j-1];
                (*pRaiz)->esquerda->visitado=0;
               // printf("to no nó i:%d j:%d\n",i,j);
                // printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

            }


        }else{
            (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
            (*pRaiz)->esquerda->valor = 'A';
            (*pRaiz)->esquerda->visitado=1;
           //printf("to no nó i:%d j:%d\n",i,j);
            //printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

        }

    

        if(i+1 < linha ){

            if(indicador==4){
                  (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                (*pRaiz)->baixo->valor = 'A';
                (*pRaiz)->baixo->visitado=1;
                 // printf("to no nó i:%d j:%d\n",i,j);
                  // printf("valor embaixo é:%c\n\n",(*pRaiz)->baixo->valor);

            }else{
                (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                (*pRaiz)->baixo->valor = M[i+1][j];
                (*pRaiz)->baixo->visitado=0;
                //printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor embaixo é:%c\n\n",(*pRaiz)->baixo->valor);

            }
            

        }else{

            (*pRaiz)->baixo = (No *) malloc(sizeof (No));
            (*pRaiz)->baixo->valor = 'A';
            (*pRaiz)->baixo->visitado=1;
           // printf("to no nó i:%d j:%d\n",i,j);
            //printf("valor embaixo é:%c\n\n",(*pRaiz)->baixo->valor);

        }
        
        if(j+1 < coluna ){

            if(indicador == 1){
                (*pRaiz)->direita = (No *) malloc(sizeof (No));
                (*pRaiz)->direita->valor = '-';
                (*pRaiz)->direita->visitado=1;
               // printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

            }else{
                (*pRaiz)->direita = (No *) malloc(sizeof (No));
                (*pRaiz)->direita->valor = M[i][j+1];
                (*pRaiz)->direita->visitado=0;
                //printf("to no nó i:%d j:%d\n",i,j);
                // printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

            }



        }else{
            (*pRaiz)->direita = (No *) malloc(sizeof (No));
            (*pRaiz)->direita->valor = '-';
            (*pRaiz)->direita->visitado=1;
            //printf("to no nó i:%d j:%d\n",i,j);
            //printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

        }


            if(i-1 >= 0 ){

              if(indicador == 2){
            
                (*pRaiz)->cima = (No *) malloc(sizeof (No));
                (*pRaiz)->cima->valor = 'A';
                (*pRaiz)->cima->visitado=1;
               // printf("to no nó i:%d j:%d\n",i,j);
               // printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

            }else{
                (*pRaiz)->cima = (No *) malloc(sizeof (No));
                (*pRaiz)->cima->valor = M[i-1][j];
                (*pRaiz)->cima->visitado=0;
                //printf("to no nó i:%d j:%d\n",i,j);
              //  printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

            }


        }else{
            (*pRaiz)->cima = (No *) malloc(sizeof (No));
            (*pRaiz)->cima->valor = 'A';
            (*pRaiz)->cima->visitado=1;
            //printf("to no nó i:%d j:%d\n",i,j);
           // printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

        }
        
            

        
       
        //checa se eh caminho valido
        // se for faz recursao pra ir criando os filhos
       // if(((*pRaiz)-> esquerda -> valor == '*') &&  (*pRaiz)-> esquerda->visitado == 0){
            if((*pRaiz)-> esquerda -> valor == '*'){
            j=j-1;
            indicador = 1;
            (*pRaiz)->visitado = 1;
            printf("\n\n<-- ");

            constroi_arvore(&((*pRaiz)->esquerda),linha,coluna,M,i,j,controle,indicador);
            j=j+1; 

        }
        

        if((*pRaiz)-> baixo -> valor == '*'){
            i=i+1;
            (*pRaiz)->visitado = 1;
            indicador= 2;
            printf("\n\n|\nv ");
            constroi_arvore(&((*pRaiz)->baixo),linha,coluna,M,i,j,controle,indicador);
            
            i=i-1;
        }
        

        //if(((*pRaiz)-> direita -> valor == '*') &&  (*pRaiz)-> direita->visitado == 0){
        if((*pRaiz)-> direita -> valor == '*'){
            j = j+1;
            indicador = 3;
            (*pRaiz)->visitado = 1;
            printf("\n--> ");
            constroi_arvore(&((*pRaiz)->direita),linha,coluna,M,i,j,controle,indicador);
            j=j-1;

        }


        if((*pRaiz)-> cima -> valor == '*'){
            i = i-1;
            indicador = 4;
            (*pRaiz)->visitado = 1;
             printf("\n^\n| ");
            constroi_arvore(&((*pRaiz)->cima),linha,coluna,M,i,j,controle,indicador);
            i = i+1;

        }
        

       return 0;

    }
   



}


/*
int constroi_arvore(No **pRaiz,int linha, int coluna, char M[linha][coluna], int linha_inico, int coluna_inicio,int controle,int indicador){
    int i = linha_inico;
    int j = coluna_inicio;

    if(M[i][j-1] == '$' || M[i+1][j] == '$' || M[i][j+1] == '$'){
        printf("\nfim encontrado\n\n");
        return 0;
    }
   
    


   // if (*pRaiz == NULL){ // primeiro caso
   if (controle == 0){ // primeiro caso
        *pRaiz =  (No *) malloc(sizeof (No));
        (*pRaiz)->valor = M[i][j];
        (*pRaiz)->visitado = 0;
        indicador = 0;
        printf("inicio");
        controle = 1;
        constroi_arvore(&(*pRaiz),linha,coluna,M,i,j,controle,indicador);
        return 0;
        
    }
    
    else{
        // checa se o redor do no eh valido pra receber valor
        if(j-1 >= 0 ){

              if(indicador == 3){
            
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = 'A';
                (*pRaiz)->esquerda->visitado=1;
                printf("to no nó i:%d j:%d\n",i,j);
            printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

            }else{
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = M[i][j-1];
                (*pRaiz)->esquerda->visitado=0;
                printf("to no nó i:%d j:%d\n",i,j);
            printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

            }


        }else{
            (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
            (*pRaiz)->esquerda->valor = 'A';
            (*pRaiz)->esquerda->visitado=1;
            printf("to no nó i:%d j:%d\n",i,j);
            printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

        }
          if((*pRaiz)-> esquerda -> valor == '*'){
            j=j-1;
            indicador = 1;
            (*pRaiz)->visitado = 1;
            //printf("\n\n<--   i:%d j:%d",i,j+1);

            constroi_arvore(&((*pRaiz)->esquerda),linha,coluna,M,i,j,controle,indicador);
            

        }

    

        if(i+1 < linha ){
            (*pRaiz)->baixo = (No *) malloc(sizeof (No));
            (*pRaiz)->baixo->valor = M[i+1][j];
            (*pRaiz)->baixo->visitado=0;
            printf("to no nó i:%d j:%d\n",i,j);
            printf("valor embaixo é:%c\n\n",(*pRaiz)->baixo->valor);

        }else{

            (*pRaiz)->baixo = (No *) malloc(sizeof (No));
            (*pRaiz)->baixo->valor = 'A';
            (*pRaiz)->baixo->visitado=1;
            printf("to no nó i:%d j:%d\n",i,j);
            printf("valor embaixo é:%c\n\n",(*pRaiz)->baixo->valor);

        }
         if((*pRaiz)-> baixo -> valor == '*'){
            i=i+1;
            (*pRaiz)->visitado = 1;
            indicador= 0;
        //printf("\n\n|\nv   i:%d j:%d",i-1,j);
            constroi_arvore(&((*pRaiz)->baixo),linha,coluna,M,i,j,controle,indicador);
            

        }

        
        if(j+1 < coluna ){

            if(indicador == 1){
                (*pRaiz)->direita = (No *) malloc(sizeof (No));
                (*pRaiz)->direita->valor = '-';
                (*pRaiz)->direita->visitado=1;
                printf("to no nó i:%d j:%d\n",i,j);
            printf("indvalor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

            }else{
            (*pRaiz)->direita = (No *) malloc(sizeof (No));
            (*pRaiz)->direita->valor = M[i][j+1];
            (*pRaiz)->direita->visitado=0;
            printf("to no nó i:%d j:%d\n",i,j);
            printf("elseindvalor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

            }

            

            
        }else{
            (*pRaiz)->direita = (No *) malloc(sizeof (No));
            (*pRaiz)->direita->valor = '-';
            (*pRaiz)->direita->visitado=1;
            printf("to no nó i:%d j:%d\n",i,j);
            printf("elseelsevalor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

        }
            if((*pRaiz)-> direita -> valor == '*'){
            j = j+1;
            indicador = 3;
            (*pRaiz)->visitado = 1;
         // printf("\n-->   i:%d j:%d  M:%c indicador:%d",i,j-1,(*pRaiz)-> direita -> valor,indicador);
            constroi_arvore(&((*pRaiz)->direita),linha,coluna,M,i,j,controle,indicador);
            

        }

            

        
       
        //checa se eh caminho valido
        // se for faz recursao pra ir criando os filhos
     
       return 0;

    }
   



}

*/
int teste_matriz_referencia(int linha, int coluna, char M[linha][coluna]){

     int i =0;
    int j =0;

    printf("\n\nteste matriz por referencia\n");

    for( i=0; i<linha;i++){

        for( j = 0; j<coluna; j ++){
           printf("%c ",M[i][j]);

        }

        printf("\n");
    }

       return 0;

       

    }

















#endif