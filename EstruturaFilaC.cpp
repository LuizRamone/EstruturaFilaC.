#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct no{
	int num;
	struct no *prox;
}T_no;

typedef struct cab_fila{
	struct no *inicio;
	struct no *fim;
}T_fila;

//prototipo das funcoes
T_fila *inicializa_fila();
void insere(int,T_fila*);
void retira(T_fila*);
void mostra_dados(T_fila*);

//cria fila
T_fila *inicializa_fila(){
T_fila *nova;
nova =(T_fila*)malloc(sizeof(T_fila));
if(nova==NULL){
	printf("\nERRO, memoria insuficiente");
	exit(0);
}
nova->inicio=NULL;
nova->fim=NULL;
return(nova);
}

//insere na fila
void insere(int n,T_fila *pfila){
	T_no *novo_no;
	novo_no=(T_no*)malloc(sizeof(T_no));
	if(novo_no==NULL){
		  printf("\nERRO, memoria insuficiente");
		  exit(0);
	}
	if(pfila->inicio==NULL){
		pfila->inicio=novo_no;
		pfila->fim=novo_no;
	novo_no->num=n;
	novo_no->prox==NULL;
	}
	else {//sera inserido no final da fila
		pfila->fim->prox=novo_no;
		pfila->fim=novo_no;
		novo_no->num=n;
		novo_no->prox=NULL;
		
	}
}
void retira(T_fila *pfila){
	T_no *aux;
	if(pfila->inicio==NULL){
			printf("\n Fila Vazia"); }
	else{
		aux = pfila->inicio;
		pfila->inicio=aux->prox;
		free(aux);
	}
}

void mostra_dados(T_fila *pfila){
	T_no *aux;
	aux = pfila->inicio;
	while(aux!=NULL){
		printf("\t%d",aux->num);
		aux = aux->prox;
	}
	
	
	
}

int main (){
	   char op; 
	int valor;  
	T_fila *pfila;  				
    pfila=inicializa_fila();  // Cria a fila vazia
    printf("Inicio= %p   Fim= %p",pfila->inicio,pfila->fim);
    do 
    {   printf("\n (I)ncluir     (E)xcluir     (F)inalizar  : ");
        fflush(stdin);
		scanf("%c",&op); 
       // if ((opcao == 'I') || (opcao == 'i'))
        op=toupper(op);  //transforma a opção em maiúscula
		if (op == 'I') {	
			printf("\n Entre com o numero a incluir : ");
			scanf("%d",&valor);
			insere(valor,pfila); 
		//	printf("\nInicio= %p   Fim= %p",pfila->inicio,pfila->fim);   
	     }    
        else if ((op == 'E') || (op == 'e'))
        		{   retira(pfila);        }
        	else if ((op != 'F') || (op != 'f')) {
		       		mostra_dados(pfila);  
                     }     
     } while ((op != 'F') && (op != 'f'));  
	
}


