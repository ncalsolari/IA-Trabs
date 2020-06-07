#ifndef MAIN_H
#define MAIN_H

struct No{
    char valor;
    int visitado;
    int custo;
    int custo_G;
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




int constroi_arvore(No **pRaiz,int linha, int coluna, char M[linha][coluna], int linha_inicio, int coluna_inicio,int linha_final,int coluna_final,int controle,  int indicador,No **ptrpai, int m_antiloop[2][linha*coluna],int pos_atual,int pos_total,int v_filhos[linha*coluna],int v_indicador[linha*coluna],int v_pais[linha*coluna],int posicao_i[linha*coluna],int posicao_j[linha*coluna]){
    int i = linha_inicio;
    int j = coluna_inicio;
    int controle_j=0;
    int modulo_custo = 0;
    int tam_max=linha*coluna;
    int ja_criado = 0;
    
    (*pRaiz)->visitado=1;
    
     printf("\nM[%d][%d] no:%d\n",i,j,&(*pRaiz));
    
   
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
        (*pRaiz)->custo=0;




            pos_atual=pos_atual+1; 
            indicador = v_indicador[pos_atual];
            pRaiz = v_filhos[pos_atual];
            ptrpai = v_pais[pos_atual];

            if(indicador==1){
                
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);

            }

            if(indicador==2){
                
                 i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);

            }

            if(indicador==3){
                
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);

            }

            if(indicador==4){
               
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);

            }


        return 0;
        


        
        //printf("NoPai:\n%c\n%c\n%c\n%c",(*pRaiz)->pai->pai->pai->pai->valor,(*pRaiz)->pai->pai->pai->valor,(*pRaiz)->pai->pai->valor,(*pRaiz)->pai->valor);
        
    }else{

        // if (*pRaiz == NULL){ // primeiro caso
        if (controle == 0){ // primeiro caso
    
            *pRaiz =  (No *) malloc(sizeof (No));
            (*pRaiz)->valor = M[i][j];
            (*pRaiz)->visitado = 0;
            modulo_custo=(linha_final-i)+(coluna_final-j);
            if(modulo_custo < 0){
                modulo_custo = modulo_custo*(-1);
            }

            (*pRaiz)->custo = modulo_custo;
            indicador = 0;
            (*pRaiz)->pai = &(*pRaiz);
            (*pRaiz)->custo_G=0;
            printf("inicio");
            controle = 1;
            constroi_arvore(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);
            return 0;
        
        }else{
            
       
            (*pRaiz)->pai = &(*ptrpai);
      




            // checa se o redor do no eh valido pra receber valor
            if(j-1 >= 0 ){
                ja_criado=0;

              if(indicador == 3){
            
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = 'A';
                (*pRaiz)->esquerda->visitado=0;
                
               
               // printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

                }else{
                    for(int y=0;y<tam_max;y++){

                        if(m_antiloop[0][y]<0){
                                
                            controle_j=y;
                            y = tam_max;
                            
                        }else{

                            if(m_antiloop[0][y]==(linha_inicio) && m_antiloop[1][y]==(coluna_inicio-1)){

                               if(M[i][j-1] != '$'){
                                ja_criado=1;
                                }

                                }


                        }

                    

                    }

                    if(ja_criado==0){
                        (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                        (*pRaiz)->esquerda->valor = M[i][j-1];
                        printf("criou esquerda com valor:%c\n",(*pRaiz)->esquerda->valor);
                        (*pRaiz)->esquerda->visitado=0;
                        (*pRaiz)->esquerda->custo = abs((linha_final-i))+abs((coluna_final-(j-1)));
                        m_antiloop[0][controle_j]=linha_inicio;
                        m_antiloop[1][controle_j]=coluna_inicio-1;

                    }else{
                        (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                        (*pRaiz)->esquerda->valor = 'A';

                    }

                     
                
                
              

                }


            }else{
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = 'A';
                (*pRaiz)->esquerda->visitado=0;
            
            }

    

            if(i+1 < linha ){
                ja_criado=0;

                if(indicador==4){
                    (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                    (*pRaiz)->baixo->valor = 'A';
                    (*pRaiz)->baixo->visitado=0;
                   
                }else{

                     for(int y=0;y<tam_max;y++){

                        if(m_antiloop[0][y]<0){
                                
                            controle_j=y;
                            y = tam_max;
                            
                        }else{

                            if(m_antiloop[0][y]==(linha_inicio+1) && m_antiloop[1][y]==(coluna_inicio)){

                                 if(M[i+1][j] != '$'){
                                        ja_criado=1;
                                    }

                                }


                        }

                    

                    }

                    if(ja_criado==0){
                        (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                        (*pRaiz)->baixo->valor = M[i+1][j];
                        printf("criou baixo com valor:%c\n",(*pRaiz)->baixo->valor);
                        (*pRaiz)->baixo->visitado=0;
                        (*pRaiz)->baixo->custo =abs((linha_final-(i+1)))+abs((coluna_final-j));
                        m_antiloop[0][controle_j]=linha_inicio+1;
                        m_antiloop[1][controle_j]=coluna_inicio;

                    }else{
                        (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                        (*pRaiz)->baixo->valor = 'A';

                    }

                    //ja_criado = 0;


                } 
                    
        

            }else{

                (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                (*pRaiz)->baixo->valor = 'A';
                (*pRaiz)->baixo->visitado=0;
            
           
                
            }
        
                if(j+1 < coluna ){
                    ja_criado=0;

                    if(indicador == 1){
                        (*pRaiz)->direita = (No *) malloc(sizeof (No));
                        (*pRaiz)->direita->valor = '-';
                        (*pRaiz)->direita->visitado=0;
                
                        // printf("to no nó i:%d j:%d\n",i,j);
                        //printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

                    }else{

                        for(int y=0;y<tam_max;y++){

                            if(m_antiloop[0][y]<0){
                                
                                controle_j=y;
                                y = tam_max;
                            
                            }else{

                                if(m_antiloop[0][y]==(linha_inicio) && m_antiloop[1][y]==(coluna_inicio+1)){

                                     if(M[i][j+1] != '$'){
                                        ja_criado=1;
                                    }

                                }


                            }

                    

                        }

                        if(ja_criado==0){
                            (*pRaiz)->direita = (No *) malloc(sizeof (No));
                            (*pRaiz)->direita->valor = M[i][j+1];
                            printf("criou direita com valor:%c\n",(*pRaiz)->direita->valor);
                            (*pRaiz)->direita->visitado=1;
                            (*pRaiz)->direita->custo = abs((linha_final-i))+abs((coluna_final-(j+1)));
                            m_antiloop[0][controle_j]=linha_inicio;
                            m_antiloop[1][controle_j]=coluna_inicio+1;

                        }else{
                            (*pRaiz)->direita = (No *) malloc(sizeof (No));
                            (*pRaiz)->direita->valor = 'A';

                        }

                       // ja_criado = 0;
                            
                        
                        
                    }



                }else{
                (*pRaiz)->direita = (No *) malloc(sizeof (No));
                (*pRaiz)->direita->valor = '-';
                (*pRaiz)->direita->visitado=0;
                
                //printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

                } 


                if(i-1 >= 0 ){
                    ja_criado=0;

                    if(indicador == 2){
                
                        (*pRaiz)->cima = (No *) malloc(sizeof (No));
                        (*pRaiz)->cima->valor = 'A';
                        (*pRaiz)->cima->visitado=0;
                
                        // printf("to no nó i:%d j:%d\n",i,j);
                        // printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

                    }else{

                    
                        for(int y=0;y<tam_max;y++){

                            if(m_antiloop[0][y]<0){
                                
                                controle_j=y;
                                y = tam_max;
                            
                            }else{

                                if(m_antiloop[0][y]==(linha_inicio-1) && m_antiloop[1][y]==coluna_inicio){
                                    if(M[i-1][j] != '$'){
                                        printf("M[%d][%d]   nno%d\n\n",(i-1),j,&(*pRaiz));
                                        ja_criado=1;
                                    }
                                    

                                }


                            }

                    

                        }

                        printf("fora M[%d][%d]   nno%d\n\nVARIAVEL CRIADO: %d",(i-1),j,&(*pRaiz),ja_criado);
                        if(ja_criado==0){
                            (*pRaiz)->cima = (No *) malloc(sizeof (No));
                            (*pRaiz)->cima->valor = M[i-1][j];
                            (*pRaiz)->cima->visitado=1;
                            printf("criou cima com valor:%c\n",(*pRaiz)->cima->valor);
                            (*pRaiz)->cima->custo = abs((linha_final-(i-1)))+abs((coluna_final-j));
                            m_antiloop[0][controle_j]=linha_inicio-1;
                            m_antiloop[1][controle_j]=coluna_inicio;

                        }else{
                            (*pRaiz)->cima = (No *) malloc(sizeof (No));
                            (*pRaiz)->cima->valor = 'A';

                        }

                            //ja_criado = 0;
                
              
                     }


            }else{
                (*pRaiz)->cima = (No *) malloc(sizeof (No));
                (*pRaiz)->cima->valor = 'A';
            
                //printf("to no nó i:%d j:%d\n",i,j);
                // printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

            }
        
            

        
       
         //checa se eh caminho valido
         // se for faz recursao pra ir criando os filhos
            indicador=0; // se n tiver nenhum caminho ele nao chama a func dnv e termina essa etapa
            if((*pRaiz)-> esquerda -> valor == '*' || (*pRaiz)-> esquerda -> valor == '$'){

                pos_total=pos_total+1;
                v_filhos[pos_total]= &(*pRaiz)->esquerda;
                v_pais[pos_total] = &(*pRaiz);
                posicao_i[pos_total]=i;
                posicao_j[pos_total]=j-1;
                v_indicador[pos_total]=1;
             
                printf("\n\n<-- ");
               

              

            }
        

            if((*pRaiz)-> baixo -> valor == '*' || (*pRaiz)-> baixo -> valor == '$'){

                pos_total=pos_total+1;
                v_filhos[pos_total]= &(*pRaiz)->baixo;
                v_pais[pos_total] = &(*pRaiz);
                posicao_i[pos_total]=i+1;
                posicao_j[pos_total]=j;
                v_indicador[pos_total]=2;
             
                printf("\n\n|\nv ");
               
            
            }
        

         //if(((*pRaiz)-> direita -> valor == '*') &&  (*pRaiz)-> direita->visitado == 0){
            
            if((*pRaiz)-> direita -> valor == '*' || (*pRaiz)-> direita -> valor == '$' ){
             
                pos_total=pos_total+1;
                
                v_filhos[pos_total]= &(*pRaiz)->direita;
                v_pais[pos_total] = &(*pRaiz);
                posicao_i[pos_total]=i;
                posicao_j[pos_total]=j+1;
                 
                v_indicador[pos_total]=3;
                printf("\n--> ");
               
            }


           if((*pRaiz)-> cima -> valor == '*' || (*pRaiz)-> cima -> valor == '$'){
                pos_total=pos_total+1;
                v_filhos[pos_total]= &(*pRaiz)->cima;
                v_pais[pos_total] = &(*pRaiz);
                posicao_i[pos_total]=i-1;
                posicao_j[pos_total]=j;
                v_indicador[pos_total]=4;
            
                printf("\n^\n| ");
            

            }
            
            pos_atual=pos_atual+1;
            
            indicador = v_indicador[pos_atual];
            printf("posicao atual: %d ",pos_atual);
            printf("indicador: %d\n",v_indicador[pos_atual]);
            printf("Vetor filhos:");
            for(int k = 0;k<tam_max;k++){
                printf( "%d   ",v_filhos[k]);
                
            }
            
            
            pRaiz = v_filhos[pos_atual];
            ptrpai = v_pais[pos_atual];

            if(indicador==1){
                
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);


            }

            if(indicador==2){
                
                 i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);


            }

            if(indicador==3){
                
               i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];

                constroi_arvore(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);


            }

            if(indicador==4){
               
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];

                constroi_arvore(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);


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

      
    printf("nova func\nto no ponteiro:%d   %c\n\n",&(*pRaiz),(*pRaiz)->valor);
    printf("valor a minha esquerda:%c\nvalor embaixo:%c\nvalor a minha direita:%c\nvalor acima:%c\n",(*pRaiz)->esquerda->valor,(*pRaiz)->esquerda->valor,(*pRaiz)->baixo->valor,(*pRaiz)->direita->valor,(*pRaiz)->cima->valor);
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
           
             printf("valor pelo ponteiro: %d\n",&(*pRaiz)->esquerda);
             printf("esquerda end pai:%d\n",(*pRaiz)->esquerda->pai);
            
        }
        if((*pRaiz)->baixo->valor == '*' || (*pRaiz)->baixo->valor == '$'){
           

            pos_total=pos_total+1;
            v_filhos[pos_total]= &(*pRaiz)->baixo;
            v_direcao[pos_total]=2;
            printf("valor pelo ponteiro: %d\n",&(*pRaiz)->baixo);
            printf("baixo end pai:%d\n",(*pRaiz)->baixo->pai);
            
        }
        if((*pRaiz)->direita->valor == '*' || (*pRaiz)->direita->valor == '$'){
           
            pos_total=pos_total+1;
            v_filhos[pos_total]= &(*pRaiz)->direita;
            v_direcao[pos_total]=3;
             printf("valor pelo ponteiro: %d\n",&(*pRaiz)->direita);
             printf("direita end pai:%d\n",(*pRaiz)->direita->pai);
            
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


int busca_a_estrela(No **pRaiz,int custo_F,int custo_G,int tam_max, int matriz_custo[3][tam_max],int M[tam_max][tam_max],int linha, int coluna,int direcao,int matriz_direcao[2][tam_max],char m[linha][coluna],int l_inic,int c_inic){

    custo_G=(*pRaiz)->custo_G;
    int y = 0;
    int vetor_ordena[tam_max];


    for(int i =0; i<tam_max;i++){
        vetor_ordena[i]=0;
    }

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
        printf("encontrado\n");


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
    }else{
        printf("nao encontrado\n");


        if((*pRaiz)->esquerda->valor == '*' || (*pRaiz)-> esquerda->valor == '$'){



            (*pRaiz)->esquerda->custo_G=custo_G+1;
            custo_F= (*pRaiz)->esquerda->custo_G + (*pRaiz)->esquerda->custo;//calcula o custo do no

            for(int i =0; i<tam_max; i++){ //roda a matriz q armazena os dados

                if(matriz_direcao[0][i]==0){  //essa armazena a direcao e o no daquela direcao
                    matriz_direcao[0][i]=&(*pRaiz)->esquerda;
                    matriz_direcao[1][i]=1;
                }

                if(matriz_custo[1][i]==0){  //
                    matriz_custo[2][i]=custo_F;
                    matriz_custo[1][i]=&(*pRaiz)->esquerda;
                    i=tam_max;
                }

            }
            


        }

        if((*pRaiz)->baixo->valor == '*' || (*pRaiz)-> baixo ->valor== '$'){

            (*pRaiz)->baixo->custo_G=custo_G+1;
            custo_F= (*pRaiz)->baixo->custo_G + (*pRaiz)->baixo->custo;
            printf("custo g:%d custo no:%d",(custo_G+1),(*pRaiz)->baixo->custo);

            for(int i =0; i<tam_max; i++){

                if(matriz_direcao[0][i]==0){
                    matriz_direcao[0][i]=&(*pRaiz)->baixo;
                    matriz_direcao[1][i]=2;
                }

                if(matriz_custo[1][i]==0){
                    matriz_custo[2][i]=custo_F;
                    matriz_custo[1][i]=&(*pRaiz)->baixo;
                     printf("filho abaixo valor: %d\n",&(*pRaiz)->baixo);
                    i=tam_max;
                }

            }

           



        }

        if((*pRaiz)->direita->valor == '*' || (*pRaiz)-> direita ->valor== '$'){

            (*pRaiz)->direita->custo_G=custo_G+1;
            custo_F= (*pRaiz)->direita->custo_G + (*pRaiz)->direita->custo;
            printf("entro direita\n\n\n");
            printf("custo g:%d custo no:%d",custo_G+1,(*pRaiz)->direita->custo);

            for(int i =0; i<tam_max; i++){

                if(matriz_direcao[0][i]==0){
                    matriz_direcao[0][i]=&(*pRaiz)->direita;
                    matriz_direcao[1][i]=3;
                }

                if(matriz_custo[1][i]==0){
                    matriz_custo[2][i]=custo_F;
                    matriz_custo[1][i]=&(*pRaiz)->direita;
                    i=tam_max;
                }

            }



        }

        if((*pRaiz)->cima->valor == '*' || (*pRaiz)-> cima->valor == '$'){

            (*pRaiz)->cima->custo_G=custo_G+1;
            custo_F= (*pRaiz)->cima->custo_G + (*pRaiz)->cima->custo;

            for(int i =0; i<tam_max; i++){

                if(matriz_direcao[0][i]==0){
                    matriz_direcao[0][i]=&(*pRaiz)->cima;
                    matriz_direcao[1][i]=4;
                }

                if(matriz_custo[1][i]==0){
                    matriz_custo[2][i]=custo_F;
                    matriz_custo[1][i]=&(*pRaiz)->cima;
                    i=tam_max;
                }

            }



        }
        //passo o valor da 3 linha(custo) para um vetor para ordenar e achar o menor valor
        for(int i=0;i<tam_max;i++){

            if(matriz_custo[0][i]==0){//vasculha ateh n ter no salvo na matriz
                printf("endereço:%d valor do custo:%d\n valor i: %d\n",matriz_custo[1][i],matriz_custo[2][i],i);
                 

                 
                vetor_ordena[y]=matriz_custo[2][i];
                y++;
                for(int k=0;k<y;k++){
                printf("v[%d]:%d ",k,vetor_ordena[k]);

                }
                printf("\n");
                

                
            }
            if(matriz_custo[1][i+1]==0){
                i=tam_max;
            }
        }

        int contagem=0;
        int aux=0;
        int i = 0;
    

        
        while(vetor_ordena[i]!=0){ //vejo tamanho preenchido do vetor
        contagem ++;
        i++;
        }
        

        for(int j = y-1;j>0;j--){ //ordeno a parte preenchido
            for(int x=0;x<j;x++){
                printf("valor do j: %d\n",j);

                if(vetor_ordena[j-1]>vetor_ordena[j]){
                aux=vetor_ordena[j-1];
                vetor_ordena[j-1]=vetor_ordena[j];
                vetor_ordena[j]=aux;

                }

            }
        }
        for(int k=0;k<y;k++){
            printf("v[%d]:%d ",k,vetor_ordena[k]);

        }
        printf("\n\n");
        int menor_valor;

        menor_valor=vetor_ordena[0];

 printf("menor valor %d\n",menor_valor);

printf("end no raiz%d\n",&(*pRaiz));
printf("end no filho%d\n",&(*pRaiz)->baixo);
        for(int i=0;i<tam_max;i++){//acha o end q corresponde ao menor custo e checa se le ja foi visitado
                                    //para o caso de 2 nos com custo igual

            if(menor_valor==matriz_custo[2][i] && matriz_custo[0][i] == 0){
                 
                matriz_custo[0][i]=1;
                printf("valor do end achado %d\n",matriz_custo[1][i]);
                pRaiz = matriz_custo[1][i];
                i = tam_max;

                
            }
        }
printf("end no raiz%d\n",&(*pRaiz));

printf("entrou8\n");
printf("custo_G: %d",custo_G);

        for(int i=0;i<tam_max;i++){
            if(&(*pRaiz)==matriz_direcao[0][i]){
                direcao=matriz_direcao[1][i];
            }
        }

        busca_a_estrela(pRaiz,custo_F,custo_G,tam_max,matriz_custo,M,linha,coluna,direcao,matriz_direcao,m,l_inic,c_inic);






    }


    return 0;


}

int busca_greedy(No **pRaiz,int custo_F,int tam_max, int m_custo[2][4],int M[tam_max][tam_max],int linha, int coluna,int direcao,char m[linha][coluna],int l_inic,int c_inic){

    
   
    //se eu zerar e ele nao tiver a opcao de ir pra algum dos nos esses vao ser ordenado como com menor custo
    //entao foi adotado um valor absurdo p nunca ocorrer isso
    m_custo[1][0]=50000;
    m_custo[1][1]=50000;
    m_custo[1][2]=50000;
    m_custo[1][3]=50000;

   

    
     printf("valor:%c\n",(*pRaiz)->valor);
    
    int controle_i=0;
    int controle_j=0;
    int end_pai;

    for(int i = 0;i<tam_max;i++){//add o no na matriz que guarda o caminho
        if(M[i][0]==0){
            
            
            M[i][0]=&(*pRaiz);
            
            controle_i = i;
            i=tam_max;
        }
    }
  
    end_pai = (*pRaiz)->pai;//endera o pai
   
    

    for(int i=0;i<=controle_i;i++){ //vasculha a matriz do caminho acha o pai copia o caminho dele e acresecenta o caminho do no atual
       
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
      
    if(direcao==1){ // adciciona o caminho desse no
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

     direcao=0;
   

    if((*pRaiz)->valor == '$'){
        printf("entrofinal\n");


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
    }else{
    


        if((*pRaiz)->esquerda->valor == '*' || (*pRaiz)-> esquerda->valor == '$'){

            custo_F= (*pRaiz)->esquerda->custo;//calcula o custo do no

            m_custo[0][0]=1;
            m_custo[1][0]=custo_F;
              printf("custo esquerda:%d\n",custo_F);


        }

        if((*pRaiz)->baixo->valor == '*' || (*pRaiz)-> baixo ->valor== '$'){

            
            custo_F=  (*pRaiz)->baixo->custo;
            m_custo[0][1]=2;
            m_custo[1][1]=custo_F;
              printf("custo baixo:%d\n",custo_F);

        }

        if((*pRaiz)->direita->valor == '*' || (*pRaiz)-> direita ->valor== '$'){

            custo_F= (*pRaiz)->direita->custo;
            m_custo[0][2]=3;
            m_custo[1][2]=custo_F;  
              printf("custo direita:%d\n",custo_F);         

        }

        if((*pRaiz)->cima->valor == '*' || (*pRaiz)-> cima->valor == '$'){

            custo_F= (*pRaiz)->cima->custo_G + (*pRaiz)->cima->custo;
            m_custo[0][3]=4;
            m_custo[1][3]=custo_F;
            printf("custo cima:%d\n",custo_F);
            }
        
    
        
        int aux=0;
        int aux2=0;
        
     for(int k=0;k<4;k++){
            printf("v[%d]:%d ",k,m_custo[1][k]);

        }

        for(int j = 3;j>0;j--){ //ordeno 
            for(int x=0;x<j;x++){

                if(m_custo[1][x]>m_custo[1][x+1]){
                aux=m_custo[0][x];
                aux2=m_custo[1][x];
                m_custo[0][x]=m_custo[0][x+1];
                m_custo[1][x]=m_custo[1][x+1];
                m_custo[0][x+1]=aux;
                m_custo[1][x+1]=aux2;

                }

            }
        }
        for(int k=0;k<4;k++){
            printf("posicao %d custo[%d]direcao:[%d] \n",k,m_custo[1][k],m_custo[0][k]);

        }
        
        
        direcao=m_custo[0][0];
        if(m_custo[1][0]==50000){
            direcao=0;
            printf("\n\ncaminho nao encontrado\n\n");
        }
        printf("direcao:%d\n\n",direcao);

        if(direcao==1){

            busca_greedy(&(*pRaiz)->esquerda,custo_F,tam_max,m_custo,M,linha,coluna,direcao,m,l_inic,c_inic);
  
        }
        if(direcao==2){

            busca_greedy(&(*pRaiz)->baixo,custo_F,tam_max,m_custo,M,linha,coluna,direcao,m,l_inic,c_inic);
  
        }
        if(direcao==3){

            printf("entroaaaa valor do prs no:%c\n",(*pRaiz)->direita->valor);

            busca_greedy(&(*pRaiz)->direita,custo_F,tam_max,m_custo,M,linha,coluna,direcao,m,l_inic,c_inic);
  
        }
        if(direcao==4){

         busca_greedy(&(*pRaiz)->cima,custo_F,tam_max,m_custo,M,linha,coluna,direcao,m,l_inic,c_inic);
  
        }



    }







    return 0;



}



int ordena_vetor(int tam_max,int v[tam_max]){
    int contagem=0;
    int aux=0;
    int i=0;
    

    while(v[i]!=0){ //vejo tamanho preenchido do vetor
        contagem ++;
        i++;
    }

    for(int j = contagem-1;j>0;j--){ //ordeno a parte preenchido
        for(int x=0;x<j;x++){

            if(v[j]>v[j+1]){
            aux=v[j];
            v[j]=v[j+1];
            v[j+1]=aux;

        }

        }
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



int constroi_arvore2(No **pRaiz,int linha, int coluna, char M[linha][coluna], int linha_inicio, int coluna_inicio,int linha_final,int coluna_final,int controle,  int indicador,No **ptrpai, int m_antiloop[2][linha*coluna],int pos_atual,int pos_total,int v_filhos[linha*coluna],int v_indicador[linha*coluna],int v_pais[linha*coluna],int posicao_i[linha*coluna],int posicao_j[linha*coluna]){
    int i = linha_inicio;
    int j = coluna_inicio;
    int controle_j=0;
    int modulo_custo = 0;
    int tam_max=linha*coluna;
    int ja_criado = 0;
    
    (*pRaiz)->visitado=1;
    
     printf("\nM[%d][%d] no:%d\n",i,j,&(*pRaiz));
    
   
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
        (*pRaiz)->custo=0;




            pos_atual=pos_atual+1; 
            indicador = v_indicador[pos_atual];
            pRaiz = v_filhos[pos_atual];
            ptrpai = v_pais[pos_atual];

            if(indicador==1){
                
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore2(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);

            }

            if(indicador==2){
                
                 i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore2(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);

            }

            if(indicador==3){
                
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore2(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);

            }

            if(indicador==4){
               
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore2(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);

            }


        return 0;
        


        
        //printf("NoPai:\n%c\n%c\n%c\n%c",(*pRaiz)->pai->pai->pai->pai->valor,(*pRaiz)->pai->pai->pai->valor,(*pRaiz)->pai->pai->valor,(*pRaiz)->pai->valor);
        
    }else{

        // if (*pRaiz == NULL){ // primeiro caso
        if (controle == 0){ // primeiro caso
    
            *pRaiz =  (No *) malloc(sizeof (No));
            (*pRaiz)->valor = M[i][j];
            (*pRaiz)->visitado = 0;
            modulo_custo=(linha_final-i)+(coluna_final-j);
            if(modulo_custo < 0){
                modulo_custo = modulo_custo*(-1);
            }

            (*pRaiz)->custo = modulo_custo;
            indicador = 0;
            (*pRaiz)->pai = &(*pRaiz);
            (*pRaiz)->custo_G=0;
            printf("inicio");
            controle = 1;
            constroi_arvore2(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);
            return 0;
        
        }else{
            
       
            (*pRaiz)->pai = &(*ptrpai);
      




            // checa se o redor do no eh valido pra receber valor
            if(j-1 >= 0 ){
                ja_criado=0;

              if(indicador == 3){
            
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = 'A';
                (*pRaiz)->esquerda->visitado=0;
                
               
               // printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

                }else{
                   

                        (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                        (*pRaiz)->esquerda->valor = M[i][j-1];
                        printf("criou esquerda com valor:%c\n",(*pRaiz)->esquerda->valor);
                        (*pRaiz)->esquerda->visitado=0;
                        (*pRaiz)->esquerda->custo = abs((linha_final-i))+abs((coluna_final-(j-1)));
                        m_antiloop[0][controle_j]=linha_inicio;
                        m_antiloop[1][controle_j]=coluna_inicio-1;

                  
                     
                
                
              

                }


            }else{
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = 'A';
                (*pRaiz)->esquerda->visitado=0;
            
            }

    

            if(i+1 < linha ){
                ja_criado=0;

                if(indicador==4){
                    (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                    (*pRaiz)->baixo->valor = 'A';
                    (*pRaiz)->baixo->visitado=0;
                   
                }else{

            

                        (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                        (*pRaiz)->baixo->valor = M[i+1][j];
                        printf("criou baixo com valor:%c\n",(*pRaiz)->baixo->valor);
                        (*pRaiz)->baixo->visitado=0;
                        (*pRaiz)->baixo->custo =abs((linha_final-(i+1)))+abs((coluna_final-j));
                        m_antiloop[0][controle_j]=linha_inicio+1;
                        m_antiloop[1][controle_j]=coluna_inicio;


                    //ja_criado = 0;


                } 
                    
        

            }else{

                (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                (*pRaiz)->baixo->valor = 'A';
                (*pRaiz)->baixo->visitado=0;
            
           
                
            }
        
                if(j+1 < coluna ){
                    ja_criado=0;

                    if(indicador == 1){
                        (*pRaiz)->direita = (No *) malloc(sizeof (No));
                        (*pRaiz)->direita->valor = '-';
                        (*pRaiz)->direita->visitado=0;
                
                        // printf("to no nó i:%d j:%d\n",i,j);
                        //printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

                    }else{

                        
                        
                            (*pRaiz)->direita = (No *) malloc(sizeof (No));
                            (*pRaiz)->direita->valor = M[i][j+1];
                            printf("criou direita com valor:%c\n",(*pRaiz)->direita->valor);
                            (*pRaiz)->direita->visitado=1;
                            (*pRaiz)->direita->custo = abs((linha_final-i))+abs((coluna_final-(j+1)));
                            m_antiloop[0][controle_j]=linha_inicio;
                            m_antiloop[1][controle_j]=coluna_inicio+1;

                       

                     
                            
                        
                        
                    }



                }else{
                (*pRaiz)->direita = (No *) malloc(sizeof (No));
                (*pRaiz)->direita->valor = '-';
                (*pRaiz)->direita->visitado=0;
                
                //printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

                } 


                if(i-1 >= 0 ){
                    ja_criado=0;

                    if(indicador == 2){
                
                        (*pRaiz)->cima = (No *) malloc(sizeof (No));
                        (*pRaiz)->cima->valor = 'A';
                        (*pRaiz)->cima->visitado=0;
                
                        // printf("to no nó i:%d j:%d\n",i,j);
                        // printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

                    }else{

                    
                       
                        printf("fora M[%d][%d]   nno%d\n\nVARIAVEL CRIADO: %d",(i-1),j,&(*pRaiz),ja_criado);
                        
                            (*pRaiz)->cima = (No *) malloc(sizeof (No));
                            (*pRaiz)->cima->valor = M[i-1][j];
                            (*pRaiz)->cima->visitado=1;
                            printf("criou cima com valor:%c\n",(*pRaiz)->cima->valor);
                            (*pRaiz)->cima->custo = abs((linha_final-(i-1)))+abs((coluna_final-j));
                            m_antiloop[0][controle_j]=linha_inicio-1;
                            m_antiloop[1][controle_j]=coluna_inicio;

                       
                           

                        

                            //ja_criado = 0;
                
              
                     }


            }else{
                (*pRaiz)->cima = (No *) malloc(sizeof (No));
                (*pRaiz)->cima->valor = 'A';
            
                //printf("to no nó i:%d j:%d\n",i,j);
                // printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

            }
        
            

        
       
         //checa se eh caminho valido
         // se for faz recursao pra ir criando os filhos
            indicador=0; // se n tiver nenhum caminho ele nao chama a func dnv e termina essa etapa
            if((*pRaiz)-> esquerda -> valor == '*' || (*pRaiz)-> esquerda -> valor == '$'){

                pos_total=pos_total+1;
                v_filhos[pos_total]= &(*pRaiz)->esquerda;
                v_pais[pos_total] = &(*pRaiz);
                posicao_i[pos_total]=i;
                posicao_j[pos_total]=j-1;
                v_indicador[pos_total]=1;
             
                printf("\n\n<-- ");
               

              

            }
        

            if((*pRaiz)-> baixo -> valor == '*' || (*pRaiz)-> baixo -> valor == '$'){

                pos_total=pos_total+1;
                v_filhos[pos_total]= &(*pRaiz)->baixo;
                v_pais[pos_total] = &(*pRaiz);
                posicao_i[pos_total]=i+1;
                posicao_j[pos_total]=j;
                v_indicador[pos_total]=2;
             
                printf("\n\n|\nv ");
               
            
            }
        

         //if(((*pRaiz)-> direita -> valor == '*') &&  (*pRaiz)-> direita->visitado == 0){
            
            if((*pRaiz)-> direita -> valor == '*' || (*pRaiz)-> direita -> valor == '$' ){
             
                pos_total=pos_total+1;
                
                v_filhos[pos_total]= &(*pRaiz)->direita;
                v_pais[pos_total] = &(*pRaiz);
                posicao_i[pos_total]=i;
                posicao_j[pos_total]=j+1;
                 
                v_indicador[pos_total]=3;
                printf("\n--> ");
               
            }


           if((*pRaiz)-> cima -> valor == '*' || (*pRaiz)-> cima -> valor == '$'){
                pos_total=pos_total+1;
                v_filhos[pos_total]= &(*pRaiz)->cima;
                v_pais[pos_total] = &(*pRaiz);
                posicao_i[pos_total]=i-1;
                posicao_j[pos_total]=j;
                v_indicador[pos_total]=4;
            
                printf("\n^\n| ");
            

            }
            
            pos_atual=pos_atual+1;
            
            indicador = v_indicador[pos_atual];
            printf("posicao atual: %d ",pos_atual);
            printf("indicador: %d\n",v_indicador[pos_atual]);
            printf("Vetor filhos:");
            for(int k = 0;k<tam_max;k++){
                printf( "%d   ",v_filhos[k]);
                
            }
            
            
            pRaiz = v_filhos[pos_atual];
            ptrpai = v_pais[pos_atual];

            if(indicador==1){
                
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore2(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);


            }

            if(indicador==2){
                
                 i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore2(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);


            }

            if(indicador==3){
                
               i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];

                constroi_arvore2(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);


            }

            if(indicador==4){
               
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];

                constroi_arvore2(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);


            }

            

        

            return 0;

        }

    }

 
    



}




int constroi_arvore3(No **pRaiz,int linha, int coluna, char M[linha][coluna], int linha_inico, int coluna_inicio,int linha_final,int coluna_final,int controle,int indicador,No **ptrpai){
    int i = linha_inico;
    int j = coluna_inicio;
    int modulo_custo = 0;
    
  
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
            (*pRaiz)->custo=0;
            


        
        //printf("NoPai:\n%c\n%c\n%c\n%c",(*pRaiz)->pai->pai->pai->pai->valor,(*pRaiz)->pai->pai->pai->valor,(*pRaiz)->pai->pai->valor,(*pRaiz)->pai->valor);
        
    }else{

        // if (*pRaiz == NULL){ // primeiro caso
        if (controle == 0){ // primeiro caso
            *pRaiz =  (No *) malloc(sizeof (No));
            (*pRaiz)->valor = M[i][j];
            (*pRaiz)->visitado = 0;
            modulo_custo=(linha_final-i)+(coluna_final-j);
            if(modulo_custo < 0){
                modulo_custo = modulo_custo*(-1);
            }

            (*pRaiz)->custo = modulo_custo;
            indicador = 0;
            (*pRaiz)->pai = &(*pRaiz);
            (*pRaiz)->custo_G=0;
            printf("inicio");
            controle = 1;
            constroi_arvore3(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz));
            return 0;
        
        }else{
        
       
         (*pRaiz)->pai = &(*ptrpai);
       




            // checa se o redor do no eh valido pra receber valor
            if(j-1 >= 0 ){

              if(indicador == 3){
            
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = 'A';
                (*pRaiz)->esquerda->visitado=0;
                
               
               // printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

            }else{
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = M[i][j-1];
                (*pRaiz)->esquerda->visitado=0;
               
                (*pRaiz)->esquerda->custo = abs((linha_final-i))+abs((coluna_final-(j-1)));
               // printf("to no nó i:%d j:%d\n",i,j);
                // printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

            }


        }else{
            (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
            (*pRaiz)->esquerda->valor = 'A';
            (*pRaiz)->esquerda->visitado=0;
           
            
           //printf("to no nó i:%d j:%d\n",i,j);
            //printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

        }

    

        if(i+1 < linha ){

            if(indicador==4){
                (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                (*pRaiz)->baixo->valor = 'A';
                (*pRaiz)->baixo->visitado=0;
                
            
                // printf("to no nó i:%d j:%d\n",i,j);
             // printf("valor embaixo é:%c\n\n",(*pRaiz)->baixo->valor);

            }else{


                (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                (*pRaiz)->baixo->valor = M[i+1][j];
                (*pRaiz)->baixo->visitado=0;
               
                (*pRaiz)->baixo->custo =abs((linha_final-(i+1)))+abs((coluna_final-j));
                //printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor embaixo é:%c\n\n",(*pRaiz)->baixo->valor);

            }
            

        }else{

            (*pRaiz)->baixo = (No *) malloc(sizeof (No));
            (*pRaiz)->baixo->valor = 'A';
            (*pRaiz)->baixo->visitado=0;
        
           // printf("to no nó i:%d j:%d\n",i,j);
            //printf("valor embaixo é:%c\n\n",(*pRaiz)->baixo->valor);

        }
        
        if(j+1 < coluna ){

            if(indicador == 1){
                (*pRaiz)->direita = (No *) malloc(sizeof (No));
                (*pRaiz)->direita->valor = '-';
                (*pRaiz)->direita->visitado=0;
        
               // printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

            }else{
                (*pRaiz)->direita = (No *) malloc(sizeof (No));
                (*pRaiz)->direita->valor = M[i][j+1];
                (*pRaiz)->direita->visitado=0;
                
                (*pRaiz)->direita->custo = abs((linha_final-i))+abs((coluna_final-(j+1)));
                //printf("to no nó i:%d j:%d\n",i,j);
                // printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

            }



        }else{
            (*pRaiz)->direita = (No *) malloc(sizeof (No));
            (*pRaiz)->direita->valor = '-';
            (*pRaiz)->direita->visitado=0;
            
            //printf("to no nó i:%d j:%d\n",i,j);
            //printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

         } 


            if(i-1 >= 0 ){

              if(indicador == 2){
            
                (*pRaiz)->cima = (No *) malloc(sizeof (No));
                (*pRaiz)->cima->valor = 'A';
                (*pRaiz)->cima->visitado=0;
              
               // printf("to no nó i:%d j:%d\n",i,j);
               // printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

            }else{
                (*pRaiz)->cima = (No *) malloc(sizeof (No));
                (*pRaiz)->cima->valor = M[i-1][j];
                (*pRaiz)->cima->visitado=0;
            
                (*pRaiz)->cima->custo = abs((linha_final-(i-1)))+abs((coluna_final-j));
                //printf("to no nó i:%d j:%d\n",i,j);
              //  printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

            }


        }else{
            (*pRaiz)->cima = (No *) malloc(sizeof (No));
            (*pRaiz)->cima->valor = 'A';
           
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

            constroi_arvore3(&((*pRaiz)->esquerda),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz));
            j=j+1; 

         }
        

         if((*pRaiz)-> baixo -> valor == '*' || (*pRaiz)-> baixo -> valor == '$' ){
            i=i+1;
            indicador= 2;
            printf("\n\n|\nv ");
            constroi_arvore3(&((*pRaiz)->baixo),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz));
            
            i=i-1;
         }
        

         //if(((*pRaiz)-> direita -> valor == '*') &&  (*pRaiz)-> direita->visitado == 0){
         if((*pRaiz)-> direita -> valor == '*' || (*pRaiz)-> direita -> valor == '$'){
            j = j+1;
            indicador = 3;
            printf("\n--> ");
            constroi_arvore3(&((*pRaiz)->direita),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz));
            j=j-1;

         }


           if((*pRaiz)-> cima -> valor == '*' || (*pRaiz)-> cima -> valor == '$'){
            i = i-1;
            indicador = 4;
            printf("\n^\n| ");
            constroi_arvore3(&((*pRaiz)->cima),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz));
            i = i+1;

            }
        

            return 0;

        }

    }
   
    



}







int constroi_arvore4(No **pRaiz,int linha, int coluna, char M[linha][coluna], int linha_inicio, int coluna_inicio,int linha_final,int coluna_final,int controle,  int indicador,No **ptrpai, int m_antiloop[3][linha*coluna],int pos_atual,int pos_total,int v_filhos[linha*coluna],int v_indicador[linha*coluna],int v_pais[linha*coluna],int posicao_i[linha*coluna],int posicao_j[linha*coluna]){
    int i = linha_inicio;
    int j = coluna_inicio;
    int controle_j=0;
    int modulo_custo = 0;
    int tam_max=linha*coluna;
    int ja_criado = 0;
    
   // (*pRaiz)->visitado=1;
    printf("banana\n");
     printf("\nM[%d][%d] no:%c\n",i,j,(*pRaiz)->valor);
      printf("banana2\n");
     

   
    if(M[i][j] == '$'){
       // printf("\nfim encontrado\nm[%d][%d]\n",i,j);
        
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
        (*pRaiz)->custo=0;




            pos_atual=pos_atual+1; 
            indicador = v_indicador[pos_atual];
            pRaiz = v_filhos[pos_atual];
            ptrpai = v_pais[pos_atual];

            if(indicador==1){
                
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore4(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);

            }

            if(indicador==2){
                
                 i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore4(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);

            }

            if(indicador==3){
                
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore4(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);

            }

            if(indicador==4){
               
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore4(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);

            }


        return 0;
        


        
        //printf("NoPai:\n%c\n%c\n%c\n%c",(*pRaiz)->pai->pai->pai->pai->valor,(*pRaiz)->pai->pai->pai->valor,(*pRaiz)->pai->pai->valor,(*pRaiz)->pai->valor);
        
    }else{

        // if (*pRaiz == NULL){ // primeiro caso
        if (controle == 0){ // primeiro caso
    
            *pRaiz =  (No *) malloc(sizeof (No));
            (*pRaiz)->valor = M[i][j];
            (*pRaiz)->visitado = 0;
            modulo_custo=(linha_final-i)+(coluna_final-j);
            if(modulo_custo < 0){
                modulo_custo = modulo_custo*(-1);
            }

            (*pRaiz)->custo = modulo_custo;
            indicador = 0;
            (*pRaiz)->pai = &(*pRaiz);
            (*pRaiz)->custo_G=0;
            printf("inicio\n");
            controle = 1;
            constroi_arvore4(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);
            return 0;
        
        }else{
            
       
            (*pRaiz)->pai = &(*ptrpai);

            
            printf("passo aaaaaaaaa\n");
      




            // checa se o redor do no eh valido pra receber valor
            if(j-1 >= 0 ){
                ja_criado=0;

               // printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor na esquerda é:%c\n\n",(*pRaiz)->esquerda->valor);

               
                    for(int y=0;y<tam_max;y++){

                        if(m_antiloop[0][y]<0){
                                
                            controle_j=y;
                            y = tam_max;
                            
                        }else{

                            if((m_antiloop[0][y]==(linha_inicio) && m_antiloop[1][y]==(coluna_inicio-1)) && indicador != 3){

                               if(M[i][j-1] != '$'){
                                 No **pAux;
                                    pAux=m_antiloop[2][y];

                                    (*pRaiz)->baixo=(*pAux);
                                         
                                    (*pRaiz)->baixo->cima=(*pRaiz);
                                printf("merda aqui esquerda\n");
                               
                                ja_criado=1;
                                }

                            }


                        }

                    

                    }

                    if(ja_criado==0){
                       (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                        (*pRaiz)->esquerda->valor = M[i][j-1];
                        printf("criou esquerda com valor:%c\n",(*pRaiz)->esquerda->valor);
                        (*pRaiz)->esquerda->visitado=0;
                        (*pRaiz)->esquerda->custo = abs((linha_final-i))+abs((coluna_final-(j-1)));
                        m_antiloop[0][controle_j]=linha_inicio;
                        m_antiloop[1][controle_j]=coluna_inicio;
                        m_antiloop[2][controle_j]=&(*pRaiz);

                    }else{
                        (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                        (*pRaiz)->esquerda->valor = 'A';

                    }


            }else{
                (*pRaiz)->esquerda = (No *) malloc(sizeof (No));
                (*pRaiz)->esquerda->valor = 'A';
                (*pRaiz)->esquerda->visitado=0;
            
            }

    

            if(i+1 < linha ){
                ja_criado=0;

        

                     for(int y=0;y<tam_max;y++){

                        if(m_antiloop[0][y]<0){
                                
                            controle_j=y;
                            y = tam_max;
                            
                        }else{

                            if((m_antiloop[0][y]==(linha_inicio+1) && m_antiloop[1][y]==(coluna_inicio))){

                                 if(M[i+1][j] != '$'){
                                     No **pAux;
                                    pAux=m_antiloop[2][y];

                                    (*pRaiz)->baixo=(*pAux);
                                         
                                    (*pRaiz)->baixo->cima=(*pRaiz);
                                    printf("merda aqui baixo\n");
                                    
                                    ja_criado=1;
                                }

                             }


                        }

                    

                    }

                    if(ja_criado==0){
                        (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                        (*pRaiz)->baixo->valor = M[i+1][j];
                       // printf("criou baixo com valor:%c\n",(*pRaiz)->baixo->valor);
                        (*pRaiz)->baixo->visitado=0;
                        (*pRaiz)->baixo->custo =abs((linha_final-(i+1)))+abs((coluna_final-j));
                        m_antiloop[0][controle_j]=linha_inicio;
                        m_antiloop[1][controle_j]=coluna_inicio;
                        m_antiloop[2][controle_j]=&(*pRaiz);

                    }else{
                        (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                        (*pRaiz)->baixo->valor = 'A';

                    }

                    //ja_criado = 0;


                
                    
        

            }else{

                (*pRaiz)->baixo = (No *) malloc(sizeof (No));
                (*pRaiz)->baixo->valor = 'A';
                (*pRaiz)->baixo->visitado=0;
            
           
                
            }
        
                if(j+1 < coluna ){
                    ja_criado=0;

                   

                        for(int y=0;y<tam_max;y++){

                            if(m_antiloop[0][y]<0){
                                
                                controle_j=y;
                                y = tam_max;
                            
                            }else{

                                if((m_antiloop[0][y]==(linha_inicio) && m_antiloop[1][y]==(coluna_inicio+1)) ){

                                     if(M[i][j+1] != '$'){
                                         No **pAux;
                                         pAux=m_antiloop[2][y];

                                         (*pRaiz)->direita=(*pAux);
                                         
                                        (*pRaiz)->direita->esquerda=(*pRaiz);
                                      // (*pRaiz)->direita=m_antiloop[2][y];
                                      
                                      (*pRaiz)->direita = (No *) malloc(sizeof (No));
                                        (*pRaiz)->direita->valor = M[i][j+1];
                                        //constroi_arvore4(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*pRaiz),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);
                                        printf("merda3 %d \n",&(*pRaiz)->esquerda->direita);
                                        
                                      
                                        ja_criado=1;
                                    }

                                }


                            }

                    

                        }

                        if(ja_criado==0){
                            (*pRaiz)->direita = (No *) malloc(sizeof (No));
                            (*pRaiz)->direita->valor = M[i][j+1];
                            printf("criou direita com valor:%c\n",(*pRaiz)->direita->valor);
                            No **pAux;
                            pAux = pRaiz;
                            printf("pRaiz:%d  pAux:%d \n",pRaiz,pAux);
                            (*pRaiz)->direita->baixo = (*pAux); 
 printf("\n(*pRaiz)->valor:%c,(*pRaiz)->direita->baixo->valor:%c AAAAAAAA&pRaiz: %d  pAux: %d pRaiz:%d  (*pRaiz):%d  &(*pRaiz):%d  pAux:%d  (*pAux):%d  &(*pAux):%d  &(*pRaiz)->direita:%d (*pRaiz)->direita:%d  &(*pRaiz)->direita->baixo:%d (*pRaiz)->direita->baixo:%d\n",(*pRaiz)->valor,(*pRaiz)->direita->baixo->valor,&pRaiz,&pAux, pRaiz,(*pRaiz),&(*pRaiz),pAux,(*pAux),&(*pAux),(*pRaiz)->direita,&(*pRaiz)->direita,&(*pRaiz)->direita->baixo,(*pRaiz)->direita->baixo);
                                        (*pRaiz)->direita->visitado=1;
                            (*pRaiz)->direita->custo = abs((linha_final-i))+abs((coluna_final-(j+1)));
                            (*pRaiz)->direita->esquerda=(*pRaiz);
                            printf("fez memso\n");
                            m_antiloop[0][controle_j]=linha_inicio;
                            m_antiloop[1][controle_j]=coluna_inicio;
                            m_antiloop[2][controle_j]=&(*pRaiz);

                        }else{
                            (*pRaiz)->direita = (No *) malloc(sizeof (No));
                            (*pRaiz)->direita->valor = 'A';

                        }

                       // ja_criado = 0;
                            
                        
                        
                    



                }else{
                (*pRaiz)->direita = (No *) malloc(sizeof (No));
                (*pRaiz)->direita->valor = '-';
                (*pRaiz)->direita->visitado=0;
                
                //printf("to no nó i:%d j:%d\n",i,j);
                //printf("valor a minha direita é:%c\n\n",(*pRaiz)->direita->valor);

                } 


                if(i-1 >= 0 ){
                    ja_criado=0;

                

                    
                        for(int y=0;y<tam_max;y++){

                            if(m_antiloop[0][y]<0){
                              
                                
                                controle_j=y;
                                y = tam_max;
                            
                            }else{
//&& indicador != 2
                                if((m_antiloop[0][y]==(linha_inicio-1) && m_antiloop[1][y]==coluna_inicio) ){
                                    if(M[i-1][j] != '$'){
                                        printf("Muyasgdkasuyd\n");

                                    No **pAux;
                                pAux=m_antiloop[2][y];

                                (*pRaiz)->cima=(*pAux);
                                         
                                (*pRaiz)->cima->baixo=(*pRaiz);
                                
                                        ja_criado=1;

                                         (*pRaiz)->cima=m_antiloop[2][y];
                                    }
                                    

                                }


                            }

                    

                        }

                        if(ja_criado==0){
                            (*pRaiz)->cima = (No *) malloc(sizeof (No));
                            (*pRaiz)->cima->valor = M[i-1][j];
                            (*pRaiz)->cima->visitado=1;
                         //   printf("criou cima com valor:%c\n",(*pRaiz)->cima->valor);
                            (*pRaiz)->cima->custo = abs((linha_final-(i-1)))+abs((coluna_final-j));
                            m_antiloop[0][controle_j]=linha_inicio;
                            m_antiloop[1][controle_j]=coluna_inicio;
                            m_antiloop[2][controle_j]=&(*pRaiz);

                        }else{
                            (*pRaiz)->cima = (No *) malloc(sizeof (No));
                            (*pRaiz)->cima->valor = 'A';

                        }

                            //ja_criado = 0;
                
              
                  


            }else{
                (*pRaiz)->cima = (No *) malloc(sizeof (No));
                (*pRaiz)->cima->valor = 'A';
            
                //printf("to no nó i:%d j:%d\n",i,j);
                // printf("valor na cima é:%c\n\n",(*pRaiz)->cima->valor);

            }
        
            

             printf("\nM[%d][%d] no:%d\n",i,j,&(*pRaiz));
     printf("no da direita:%d\n no da esquerda visto do da direita:%d\n\n\n",(*pRaiz)->esquerda,(*pRaiz)->esquerda->direita);
    
       
         //checa se eh caminho valido
         // se for faz recursao pra ir criando os filhos
           // indicador=0; // se n tiver nenhum caminho ele nao chama a func dnv e termina essa etapa
            if(((*pRaiz)-> esquerda -> valor == '*' || (*pRaiz)-> esquerda -> valor == '$') && indicador!=3){

                pos_total=pos_total+1;
                v_filhos[pos_total]= &(*pRaiz)->esquerda;
                v_pais[pos_total] = &(*pRaiz);
                posicao_i[pos_total]=i;
                posicao_j[pos_total]=j-1;
                v_indicador[pos_total]=1;
             
                printf("\n\n<-- ");
               

              

            }
        

            if(((*pRaiz)-> baixo -> valor == '*' || (*pRaiz)-> baixo -> valor == '$')&& indicador!=4){

                pos_total=pos_total+1;
                v_filhos[pos_total]= &(*pRaiz)->baixo;
                v_pais[pos_total] = &(*pRaiz);
                posicao_i[pos_total]=i+1;
                posicao_j[pos_total]=j;
                v_indicador[pos_total]=2;
             
                printf("\n\n|\nv ");
               
            
            }
        

         //if(((*pRaiz)-> direita -> valor == '*') &&  (*pRaiz)-> direita->visitado == 0){
            
            if(((*pRaiz)-> direita -> valor == '*' || (*pRaiz)-> direita -> valor == '$')&&indicador!=1 ){
             
                pos_total=pos_total+1;
                
                v_filhos[pos_total]= &(*pRaiz)->direita;
                v_pais[pos_total] = &(*pRaiz);
                posicao_i[pos_total]=i;
                posicao_j[pos_total]=j+1;
                 
                v_indicador[pos_total]=3;
                printf("\n--> ");
               
            }


           if(((*pRaiz)-> cima -> valor == '*' || (*pRaiz)-> cima -> valor == '$')&&indicador!=2){
                pos_total=pos_total+1;
                v_filhos[pos_total]= &(*pRaiz)->cima;
                v_pais[pos_total] = &(*pRaiz);
                posicao_i[pos_total]=i-1;
                posicao_j[pos_total]=j;
                v_indicador[pos_total]=4;
            
                printf("\n^\n| ");
            

            }
            
            pos_atual=pos_atual+1;
            
            indicador = v_indicador[pos_atual];
           // printf("posicao atual: %d ",pos_atual);
           // printf("indicador: %d\n",v_indicador[pos_atual]);
           // printf("Vetor filhos:");
           // for(int k = 0;k<tam_max;k++){
           //     printf( "%d   ",v_filhos[k]);
                
           // }
           
             printf("valor a direita esquerda:%c\n",(*pRaiz)->direita->esquerda->valor);
            pRaiz = v_filhos[pos_atual];
            ptrpai = v_pais[pos_atual];
            printf("pos alocacao\n");
            printf("\n&pRaiz:%d pRaiz:%d  (*pRaiz):%d  &(*pRaiz):%d   &(*pRaiz)->esquerda:%d  (*pRaiz)->esquerda:%d (**pRaiz):%d &(**pRaiz):%d\n",&pRaiz, pRaiz,(*pRaiz),&(*pRaiz),&(*pRaiz)->esquerda,(*pRaiz)->esquerda,(**pRaiz),&(**pRaiz));
           

           // printf("valor a esquerda:%c\n",(*pRaiz)->esquerda->valor);
            if(indicador==1){
                
             //   (*pRaiz)->esquerda->direita=&(*pRaiz);
                
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore4(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);


            }

            if(indicador==2){
                
                 i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];
                constroi_arvore4(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);


            }

            if(indicador==3){
                
               i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];

                constroi_arvore4(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);


            }

            if(indicador==4){
               
                i=posicao_i[pos_atual];
                j=posicao_j[pos_atual];

                constroi_arvore4(&(*pRaiz),linha,coluna,M,i,j,linha_final,coluna_final,controle,indicador,&(*ptrpai),m_antiloop,pos_atual,pos_total,v_filhos,v_indicador,v_pais,posicao_i,posicao_j);


            }

            

        

            return 0;

        }

    }

 
    



}



















#endif