#ifndef MAIN_H
#define MAIN_H

struct No{
    char valor;
    int visitado;
    int custo;
    struct No *esquerda;
    struct No *baixo;
    struct No * direita;
    struct No * cima;
    struct No * pai;
};
typedef struct No No;
/*
void constroi_matriz(int *linha,int *coluna,int *inicio_i,int *inicio_j,int *fim_i,int *fim_j, char * m,char matriz[][]){
   */




int constroi_arvore(No **pRaiz,int linha, int coluna, char M[linha][coluna], int linha_inico, int coluna_inicio,int linha_final,int coluna_final,int controle,int indicador,No **ptrpai){
    int i = linha_inico;
    int j = coluna_inicio;
    
  
    if(M[i][j] == '$'){
        printf("\nfim encontrado\nm[%d][%d]\n",i,j);
        
         (*pRaiz)->pai = &(*ptrpai);

        //checa aonde ta o valor procurado e sela o no
       

            (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
            (*pRaiz)->esquerda->valor = '-';
            (*pRaiz)->esquerda->visitado=0;
            (*pRaiz)->esquerda->custo = 0;
            (*pRaiz)->baixo = (No *) malloc(sizeof (No));
            (*pRaiz)->baixo->valor = '-';
            (*pRaiz)->baixo->custo = 0;
            (*pRaiz)->direita = (No *) malloc(sizeof (No));
            (*pRaiz)->direita->valor = '-';
            (*pRaiz)->direita->custo = 0;
            (*pRaiz)->cima = (No *) malloc(sizeof (No));
            (*pRaiz)->cima->valor = '-';
            (*pRaiz)->cima->custo = 0;
            


        
        //printf("NoPai:\n%c\n%c\n%c\n%c",(*pRaiz)->pai->pai->pai->pai->valor,(*pRaiz)->pai->pai->pai->valor,(*pRaiz)->pai->pai->valor,(*pRaiz)->pai->valor);
        
    }else{

        // if (*pRaiz == NULL){ // primeiro caso
        if (controle == 0){ // primeiro caso
            *pRaiz =  (No *) malloc(sizeof (No));
            (*pRaiz)->valor = M[i][j];
            (*pRaiz)->visitado = 0;
            (*pRaiz)->custo = (linha_final-i)+(coluna_final-j);
            indicador = 0;
            (*pRaiz)->pai = &(*pRaiz);
            printf("inicio");
            controle = 1;
            constroi_arvore(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz));
            return 0;
        
        }else{
        
       
         (*pRaiz)->pai = &(*ptrpai);
       




            // checa se o redor do no eh valido pra receber valor
            if(j-1 >= 0 ){

              if(indicador == 3){
            
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = 'A';
                (*pRaiz)->esquerda->visitado=0;
                (*pRaiz)->esquerda->custo = (linha_final-i)+(coluna_final-j);
               // printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

            }else{
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = M[i][j-1];
                (*pRaiz)->esquerda->visitado=0;
                (*pRaiz)->esquerda->custo = (linha_final-i)+(coluna_final-j);
               // printf("to no nó i:%d j:%d\n",i,j);
                // printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

            }


        }else{
            (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
            (*pRaiz)->esquerda->valor = 'A';
            (*pRaiz)->esquerda->visitado=0;
            (*pRaiz)->esquerda->custo = (linha_final-i)+(coluna_final-j);
           //printf("to no nó i:%d j:%d\n",i,j);
            //printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

        }

    

        if(i+1 < linha ){

            if(indicador==4){
                (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                (*pRaiz)->baixo->valor = 'A';
                (*pRaiz)->baixo->visitado=0;
                (*pRaiz)->baixo->custo = (linha_final-i)+(coluna_final-j);
                // printf("to no nó i:%d j:%d\n",i,j);
             // printf("valor embaixo é:%c\n\n",(*pRaiz)->baixo->valor);

            }else{


                (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                (*pRaiz)->baixo->valor = M[i+1][j];
                (*pRaiz)->baixo->visitado=0;
                (*pRaiz)->baixo->custo = (linha_final-i)+(coluna_final-j);
                //printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor embaixo é:%c\n\n",(*pRaiz)->baixo->valor);

            }
            

        }else{

            (*pRaiz)->baixo = (No *) malloc(sizeof (No));
            (*pRaiz)->baixo->valor = 'A';
            (*pRaiz)->baixo->visitado=0;
            (*pRaiz)->baixo->custo = (linha_final-i)+(coluna_final-j);
           // printf("to no nó i:%d j:%d\n",i,j);
            //printf("valor embaixo é:%c\n\n",(*pRaiz)->baixo->valor);

        }
        
        if(j+1 < coluna ){

            if(indicador == 1){
                (*pRaiz)->direita = (No *) malloc(sizeof (No));
                (*pRaiz)->direita->valor = '-';
                (*pRaiz)->direita->visitado=0;
                (*pRaiz)->direita->custo = (linha_final-i)+(coluna_final-j);
               // printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

            }else{
                (*pRaiz)->direita = (No *) malloc(sizeof (No));
                (*pRaiz)->direita->valor = M[i][j+1];
                (*pRaiz)->direita->visitado=0;
                (*pRaiz)->direita->custo = (linha_final-i)+(coluna_final-j);
                //printf("to no nó i:%d j:%d\n",i,j);
                // printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

            }



        }else{
            (*pRaiz)->direita = (No *) malloc(sizeof (No));
            (*pRaiz)->direita->valor = '-';
            (*pRaiz)->direita->visitado=0;
            (*pRaiz)->direita->custo = (linha_final-i)+(coluna_final-j);
            //printf("to no nó i:%d j:%d\n",i,j);
            //printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

         } 


            if(i-1 >= 0 ){

              if(indicador == 2){
            
                (*pRaiz)->cima = (No *) malloc(sizeof (No));
                (*pRaiz)->cima->valor = 'A';
                (*pRaiz)->cima->visitado=0;
                (*pRaiz)->cima->custo = (linha_final-i)+(coluna_final-j);
               // printf("to no nó i:%d j:%d\n",i,j);
               // printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

            }else{
                (*pRaiz)->cima = (No *) malloc(sizeof (No));
                (*pRaiz)->cima->valor = M[i-1][j];
                (*pRaiz)->cima->visitado=0;
                (*pRaiz)->cima->custo = (linha_final-i)+(coluna_final-j);
                //printf("to no nó i:%d j:%d\n",i,j);
              //  printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

            }


        }else{
            (*pRaiz)->cima = (No *) malloc(sizeof (No));
            (*pRaiz)->cima->valor = 'A';
            (*pRaiz)->cima->custo = (linha_final-i)+(coluna_final-j);
            //printf("to no nó i:%d j:%d\n",i,j);
           // printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

         }
        
            

        
       
         //checa se eh caminho valido
         // se for faz recursao pra ir criando os filhos
         // if(((*pRaiz)-> esquerda -> valor == '*') &&  (*pRaiz)-> esquerda->visitado == 0){
            if((*pRaiz)-> esquerda -> valor == '*' || (*pRaiz)-> esquerda -> valor == '$'){
            j=j-1;
            indicador = 1;
            printf("\n\n<-- ");

            constroi_arvore(&((*pRaiz)->esquerda),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz));
            j=j+1; 

         }
        

         if((*pRaiz)-> baixo -> valor == '*' || (*pRaiz)-> baixo -> valor == '$' ){
            i=i+1;
            indicador= 2;
            printf("\n\n|\nv ");
            constroi_arvore(&((*pRaiz)->baixo),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz));
            
            i=i-1;
         }
        

         //if(((*pRaiz)-> direita -> valor == '*') &&  (*pRaiz)-> direita->visitado == 0){
         if((*pRaiz)-> direita -> valor == '*' || (*pRaiz)-> direita -> valor == '$'){
            j = j+1;
            indicador = 3;
            printf("\n--> ");
            constroi_arvore(&((*pRaiz)->direita),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz));
            j=j-1;

         }


           if((*pRaiz)-> cima -> valor == '*' || (*pRaiz)-> cima -> valor == '$'){
            i = i-1;
            indicador = 4;
            printf("\n^\n| ");
            constroi_arvore(&((*pRaiz)->cima),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz));
            i = i+1;

            }
        

            return 0;

        }

    }
   
    



}


int busca_profundidade(No **pRaiz, int linha, int coluna,int *final,int posicao_caminho,int tam_max, char vetor_caminho[tam_max],int lin, int col, char M[lin][col],int lin_inic,int col_inic){
    

    if((*pRaiz)->valor == '$'){

        *final = 1;

        printf("M[%d][%d] o/ %c\nCaminho Encontrado\n",linha,coluna,(*pRaiz)->valor);

        for(int i = 0; i<posicao_caminho; i++){

        printf("%c",vetor_caminho[i]);

        }

        for(int i=0; i<lin;i++){

            for(int j = 0; j<col; j ++){
           printf("%c ",M[i][j]);
            }
            printf("\n");

        }
       
        int x = 0;
        while(vetor_caminho[x]!='@'){

            if(vetor_caminho[x]=='<'){
                sleep(1);
                system("clear");
                col_inic=col_inic-1;
                M[lin_inic][col_inic] = 'o';
                x=x+1;

                for(int i=0; i<lin;i++){

                    for(int j = 0; j<col; j ++){

                        printf("%c ",M[i][j]);
                    
                    }
                    printf("\n");

                    

                }



            }

            if(vetor_caminho[x]=='v'){
                sleep(1);
                system("clear");
                lin_inic = lin_inic+1;
                M[lin_inic][col_inic] = 'o';
                x=x+1;

                for(int i=0; i<lin;i++){

                    for(int j = 0; j<col; j ++){

                        printf("%c ",M[i][j]);
                    
                    }
                    printf("\n");
                    

                }



            }

            if(vetor_caminho[x]=='>'){
                sleep(1);
                system("clear");
                col_inic=col_inic+1;
                M[lin_inic][col_inic] = 'o';
                x=x+1;

                for(int i=0; i<lin;i++){

                    for(int j = 0; j<col; j ++){

                        printf("%c ",M[i][j]);
                    
                    }
                    printf("\n");
                    

                }



            }

            if(vetor_caminho[x]=='^'){
                sleep(1);
                system("clear");
                lin_inic=lin_inic-1;
                M[lin_inic][col_inic] = 'o';
                x=x+1;

                for(int i=0; i<lin;i++){

                    for(int j = 0; j<col; j ++){

                        printf("%c ",M[i][j]);
                    
                    }
                    printf("\n");
                    

                }



            }






        }
        
        printf("\n");
    
        



        
        



    }else{
        

        if(((*pRaiz)-> esquerda -> valor == '*' || (*pRaiz)-> esquerda -> valor == '$') && *final == 0  ){

            vetor_caminho[posicao_caminho]='<';
            posicao_caminho = posicao_caminho + 1;

            printf("M[%d][%d] <\n",linha,coluna);

    

            coluna= coluna - 1;

            
            busca_profundidade(&((*pRaiz)->esquerda), linha, coluna, final, posicao_caminho, tam_max,  vetor_caminho,lin,col,M,lin_inic,col_inic);
            posicao_caminho = posicao_caminho - 1;
            if(*final == 0){ // se voltou na recursao e i==0 entao o caminho q ele achou a partir daqui eh inviavel

                for(int i = posicao_caminho;i<tam_max;i++){
                    vetor_caminho[i]='@';
    
                }



            }

            coluna = coluna +1;


        }

         if(((*pRaiz)-> baixo -> valor == '*' || (*pRaiz)-> baixo -> valor == '$') && *final == 0  ){


             printf("M[%d][%d] v\n",linha,coluna);
            linha= linha + 1;
            vetor_caminho[posicao_caminho]='v';
            posicao_caminho = posicao_caminho + 1;
            
        

            
            busca_profundidade(&((*pRaiz)->baixo), linha, coluna,final, posicao_caminho, tam_max,  vetor_caminho,lin,col,M,lin_inic,col_inic);
             posicao_caminho = posicao_caminho - 1;
            if(*final == 0){ // se voltou na recursao e i==0 entao o caminho q ele achou a partir daqui eh inviavel
               

                for(int i = posicao_caminho;i<tam_max;i++){
                    vetor_caminho[i]='@';
    
                }



            }

            linha= linha - 1;


        }

         if(((*pRaiz)-> direita -> valor == '*' || (*pRaiz)-> direita -> valor == '$') && *final == 0  ){
            printf("M[%d][%d] >\n",linha,coluna);
            coluna= coluna + 1;
            vetor_caminho[posicao_caminho]='>';
            posicao_caminho = posicao_caminho + 1;

             

            
            busca_profundidade(&((*pRaiz)->direita), linha, coluna, final, posicao_caminho, tam_max,  vetor_caminho,lin,col,M,lin_inic,col_inic);
            posicao_caminho = posicao_caminho - 1;

            if(*final == 0){ // se voltou na recursao e i==0 entao o caminho q ele achou a partir daqui eh inviavel
                
                for(int i = posicao_caminho;i<tam_max;i++){
                    vetor_caminho[i]='@';
    
                }



            }

            coluna = coluna - 1;


        }

         if(((*pRaiz)-> cima -> valor == '*' || (*pRaiz)-> cima -> valor == '$') && *final == 0  ){

             printf("M[%d][%d] ^\n",linha,coluna);
            linha=linha - 1;
            vetor_caminho[posicao_caminho]='^';
            posicao_caminho = posicao_caminho + 1;

            

           
            busca_profundidade(&((*pRaiz)->cima), linha, coluna,final, posicao_caminho, tam_max,  vetor_caminho,lin,col,M,lin_inic,col_inic);
            posicao_caminho = posicao_caminho - 1;
            if(*final == 0){ // se voltou na recursao e i==0 entao o caminho q ele achou a partir daqui eh inviavel
                
                for(int i = posicao_caminho;i<tam_max;i++){
                    vetor_caminho[i]='@';
    
                }



            }

            linha = linha + 1;


        }







    }

    
    

    return 0;


}

int busca_largura(No **pRaiz,int linha, int coluna,int tam_max,int v_filhos[],int M[tam_max][tam_max],int pos_atual,int pos_total,int v_direcao[],int direcao,char m[linha][coluna],int l_inic, int c_inic){

      
    printf("nova func\nto no ponteiro:%d   %d\n\n",&(*pRaiz),M[0][0]);
    int controle_i=0;
    int controle_j=0;
    int end_pai;
    for(int i = 0;i<tam_max;i++){
        if(M[i][0]==0){
            
            
            M[i][0]=&(*pRaiz);
            
            controle_i = i;
            i=tam_max;
        }
    }
  
    end_pai = (*pRaiz)->pai;
   
    

    for(int i=0;i<=controle_i;i++){
       
        if(M[i][0]==end_pai){
            
            for(int j=1;j<tam_max;j++){
                
                M[controle_i][j]=M[i][j];
                if(M[i][j]==0){
                   
                    controle_j=j;
                    j=tam_max;
                }
            }

            i=controle_i;
        }


    }
      
    if(direcao==1){
        M[controle_i][controle_j]=1;
    }
    if(direcao==2){
        M[controle_i][controle_j]=2;
    }
    if(direcao==3){
        M[controle_i][controle_j]=3;
    }
    if(direcao==4){
        M[controle_i][controle_j]=4;
    }

   
    if((*pRaiz)->valor == '$'){

        printf("Caminho Encontrado\n");
        printf("Caminho:");
        for(int i = 1;i<=controle_j;i++){
            printf("%d",M[controle_i][i]);

        }

        printf("\n");
            int x = 1;
         while(M[controle_i][x] != 0){
              system("clear");
            for(int i=0;i<linha;i++){
                for(int j =0; j<coluna;j++){
                    printf("%c ",m[i][j]);

                }
                printf("\n");
            }

            if(M[controle_i][x] == 1){
                m[l_inic][c_inic-1] = 'o';
                c_inic=c_inic-1;
            }
            if(M[controle_i][x] == 2){
                m[l_inic+1][c_inic] = 'o';
                l_inic=l_inic+1;
            }
            if(M[controle_i][x] == 3){
                m[l_inic][c_inic+1] = 'o';
                c_inic=c_inic+1;
            }
            if(M[controle_i][x] == 4){
                m[l_inic-1][c_inic] = 'o';
                l_inic=l_inic-1;
            }

            x++;
            sleep(1);
           

        }
    
        printf("\n");


    }else{

        if((*pRaiz)->esquerda->valor == '*' || (*pRaiz)->esquerda->valor == '$' ){
            

            pos_total=pos_total+1;
            v_filhos[pos_total]= &(*pRaiz)->esquerda;
            v_direcao[pos_total]=1;
           
            // printf("valor pelo ponteiro: %d\n",&(*pRaiz)->esquerda);
            // printf("esquerda end pai:%d\n",(*pRaiz)->esquerda->pai);
            
        }
        if((*pRaiz)->baixo->valor == '*' || (*pRaiz)->baixo->valor == '$'){
           

            pos_total=pos_total+1;
            v_filhos[pos_total]= &(*pRaiz)->baixo;
            v_direcao[pos_total]=2;
            //printf("valor pelo ponteiro: %d\n",&(*pRaiz)->baixo);
           // printf("baixo end pai:%d\n",(*pRaiz)->baixo->pai);
            
        }
        if((*pRaiz)->direita->valor == '*' || (*pRaiz)->direita->valor == '$'){
           
            pos_total=pos_total+1;
            v_filhos[pos_total]= &(*pRaiz)->direita;
            v_direcao[pos_total]=3;
            // printf("valor pelo ponteiro: %d\n",&(*pRaiz)->direita);
            // printf("direita end pai:%d\n",(*pRaiz)->direita->pai);
            
        }
        if((*pRaiz)->cima->valor == '*' || (*pRaiz)->cima->valor == '$'){
          
            pos_total=pos_total+1;
            v_filhos[pos_total]= &(*pRaiz)->cima;
            v_direcao[pos_total]=4;
            
        }

        pos_atual=pos_atual+1;


        pRaiz = v_filhos[pos_atual];
        direcao = v_direcao[pos_atual];


        busca_largura(&(*pRaiz),linha,coluna,tam_max,v_filhos,M,pos_atual,pos_total,v_direcao,direcao,m,l_inic,c_inic);

             

    }

   


    
   
    return 0;



}





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