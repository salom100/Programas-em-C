#include <stdio.h>
#include <stdlib.h>

int listar=0;
int primeiro_verifica=0;
int tamanho;
int posicao;
int x;
int prox_ant=0;

struct lista {
	struct lista *anterior;
	int conteudo;
	struct lista *prox;
}*lista,*inicio,*final,*local, *deletar, *atual;



void iniciando_lista(){
	lista= (struct lista*) malloc(sizeof(struct lista));
	
	if(lista!= NULL){
		lista->anterior=NULL;
		lista->prox=NULL;
	}else{
		printf("Houve um erro pois nao foi possivel mallocar espaco !!");
	}
}

void alpha(int x){
	int valor=0;
	
		do{
			if(primeiro_verifica==0){
				system("cls");
				printf("digite o valor a ser incluido no inicio: ");
				scanf("%i",&valor);
				
				lista->conteudo=valor;
				inicio=lista;
				final=lista;
				
				primeiro_verifica=1;
				tamanho+=1;
				posicao+=1;
			}else if(primeiro_verifica==1){
				system("cls");
				printf("Digite o valor a ser incluido no inicio: ");
				scanf("%i",&valor);
				
				lista->conteudo=valor;
				lista->prox=inicio;
				inicio->anterior=lista;
				
				inicio=lista;
				tamanho+=1;
				posicao+=1;
			}
			
		}while(valor==0);	
}

void omega(int x){
	int valor=0;
	
	do{
		system("cls");
		printf("Digite o valor que sera incluido no fim: ");
		scanf("%i",&valor);
		
		
		lista->conteudo=valor;
		final->prox=lista;
		lista->anterior=final;
		
		final=lista;
		tamanho+=1;
		posicao+=1;
		
	}while(valor==0);
	
}

void qualquer_posicao(int x){
	int valor=0;
	
	do{
		system("cls");
		valor=0;
		int posto;
		int contador=2;
		local=inicio;
		
		for(;;){
			system("cls");
			printf("Digite a posicao em que sera inserido o valor: ");
			scanf("%i",&posto);
			
			if(posto>=1 && posto <=tamanho){
				break;
			}else{
				printf("A posicao nao esta nos limites do tamanho da lista !!!!!");
				
			}
		}
		
		if(posto==1){
			system("cls");
			int x=1;
			alpha(x);
			
			goto encerra;
		}else{
			system("cls");
			
			while(contador<posto){
				local= local->prox;
				contador+=1;
			}
			printf("Digite o valor a ser inserido na posicao escolhida: ");
			scanf("%i",&valor);
			
			lista->conteudo=valor;
			lista->anterior=local;
			lista->prox=local->prox;
			local->prox->anterior=lista;
			local->prox=lista;
			
			goto encerra;	
		}	
	}while(valor==0);
	encerra:
	tamanho+=1;
	posicao+=1;
}
	
void inserir(int op){
	int valor;
	int escolhas;
	iniciando_lista();
	
	if(tamanho==0){ // se for assim incluira como se fosse o primeiro valor
		system("cls");
		x=1;
		
		alpha(x);
		
		system("pause");
		
	}else if(tamanho>0){
		for(;;){
			system("cls");
			printf("Aonde voce quer inserir o valor ? \n\n");
			printf("1-Inicio \n 2-Qualquer lugar \n 3-Fim \n");
			scanf("%i",&escolhas);
			if(escolhas==1){
				alpha(escolhas);
				
				system("pause");
				break;
	
			}else if(escolhas==3){
				omega(escolhas);
				
				break;
				system("pause");
				
			}else if(escolhas==2){
				qualquer_posicao(escolhas);
				break;
				system("pause");
			}else{
				printf("nao e possivel realizar essa acao !!! \n");
			}
		}
		system("cls");
	}
	
}
	
void mostrar(){
	lista= inicio;
	system("cls");
	printf("Lista Encadeada: \n");
		while(lista->prox !=NULL){
			printf(" %i |",lista->conteudo);
			lista= lista->prox;
		}
		printf(" %i  \n\n",lista->conteudo);
}
	
void Deletar(int op){
	
	if(tamanho==0){
		printf("Nao ha como excluir o que nao tem, por favo insira um valor a lista !!! \n");
		system("pause");
	}else if (tamanho> 0){
		int posto;
		int i=0;
		local=inicio;
		
		for(;;){
			system("cls");
			printf("Digite a posicao em que o valor se encontra: \n");
			scanf("%i",&posto);
				if(posto>=1 && posto<=tamanho){
					break;
				}else{
					printf("se faz necessario que a posicao exista na lista, por favor tente outra posicao\n");
					
				}
		}
		int cont=0;
		 for(cont;cont<posto-1;cont++){
		 	local=local->prox;
		 }
		 printf("Conteudo: %i \n", local->conteudo);
		 printf("Digite 1 para excluir !! \n");
		 scanf("%i",&op);
		 
		 if(op==1){
			if(tamanho==1){
				if(local->prox == NULL){
					printf("\n Valor Deletado !!! \n");
					free(local);
					local=inicio=NULL;
					tamanho-= 1;
					
					primeiro_verifica=0;
					printf("\n    da 1 POSICAO\n\n");
					
					system("pause");
					return;
					}	
			}
			
			if(local->prox==NULL){
				printf("Valor Deletado com sucesso !! \n");
				local=local->anterior;
				local->prox=NULL;
				local=local->prox;
				
				free(local);
				
				tamanho-= 1;
				
				system("pause");
				return;
			}else if(local->anterior==NULL){
				printf("Valor excluido com sucesso");
				
				deletar=local;
				local=local->prox;
				local->anterior=NULL;
				inicio=local;
				
				free(deletar);
				
				tamanho -=1;
				system("pause");
		        return;	
			}else{
				printf("Valor excluido com sucesso!! \n");
				local=local;
				local->anterior->prox=local->prox;
				local->prox->anterior=local->anterior;
				
				free(local);
				
				tamanho-=1;
				system("pause");
		        return;		
			}
		 }
		
		
	}
}	

void visao_1(){
	system("cls");
	mostrar();
	if(tamanho==1){
		if(lista==NULL){
			lista=inicio;
			while(lista->prox!=NULL){
				lista=lista->prox;
			}
			printf("| %i",lista->conteudo);
		}else if(lista->anterior==NULL){
			lista=inicio;
			while(lista->prox !=NULL){
				lista= lista->prox;
			}
			printf("| %i",lista->conteudo);
		}else{
			lista=lista->anterior;
			printf("| %i",lista->conteudo);
		}if(lista->prox==NULL){
			lista=inicio;
			printf("| %i",lista->conteudo);
		}else{
			lista=lista->prox;
			printf("| %i",lista->conteudo);
		}
		atual=lista;
		if(lista->prox==NULL){
			lista=inicio;
			printf("| %i",lista->conteudo);
		}else{
			lista=lista->prox;
			printf("| %i",lista->conteudo);
		}
	}
	if(tamanho>1){
		if(lista==NULL){
			lista=inicio;
			while(lista->prox !=NULL){
				lista=lista->prox;
				
			}
			printf("| %i ",lista->conteudo);
		}else if(lista->anterior == NULL){
			lista=inicio;
			while(lista->prox != NULL){
				lista=lista->prox;
			}
			printf("| %i ",lista->conteudo);
		}else{
			lista=lista->anterior;
			printf("| %i ",lista->conteudo);
		}if(lista->prox==NULL){
			lista=inicio;
			printf("| %i ",lista->conteudo);
		}else{
			lista=lista->prox;
			printf("| %i ",lista->conteudo);
		}
		atual=lista;
		if(lista->prox == NULL){
			lista=inicio;
			printf("| %i ",lista->conteudo);
		}else{
			lista=lista->prox;
			printf("| %i ",lista->conteudo);
		}
	}
	printf("\n    <<   |   II  |   >>  \n");
}

void visao_2(){
	system("cls");
	mostrar();
	printf("\n");
	
	if(tamanho==1){
		lista=inicio;
		atual=lista;
		printf(" %i ",lista->conteudo, "| %i ",lista->conteudo, "| %i ",lista->conteudo);
	}else if(tamanho>1){
		lista=atual;
		lista=lista->anterior;
		printf("\n");
		if(lista==NULL){
			lista= inicio;
			while(lista->prox != NULL){
				lista= lista->prox;
			}
			lista=lista->anterior;
			printf("| %i",lista->conteudo);
		}else if(lista->anterior==NULL){
			lista=inicio;
			while(lista->prox !=NULL){
				lista=lista->prox;
			}
			printf("| %i ",lista->conteudo);
		}else{
			lista=lista->anterior;
			printf("| %i ",lista->conteudo);
		}
		if(lista->prox==NULL){
			lista=inicio;
			printf("| %i ",lista->conteudo);
		}else{
			lista->prox;
			printf("| %i ",lista->conteudo);
		}
		atual=lista;
		if(lista->prox==NULL){
			lista=inicio;
			printf("| %i ",lista->conteudo);
		}else{
			lista= lista->prox;
			printf("| %i ",lista->conteudo);
		}
	}
	printf("\n << | II | >> \n");
}

visao_3(){
	system("cls");
		mostrar();
		printf("\n\n");
		if(tamanho==1){
			lista=inicio;
			printf("| %i ",lista->conteudo," |%i ",lista->conteudo, "| %i ", lista->conteudo);
		}else if(tamanho>1){
			lista=atual;
			lista=lista->prox;
			if(lista==NULL){
				lista=inicio;
				while(lista->prox!=NULL){
					lista=lista->prox;
				}
				printf("| %i ",lista->conteudo);
			}else if(lista->anterior==NULL){
				lista=inicio;
				while(lista->prox!=NULL){
					lista= lista->prox;
				}
				printf("| %i ",lista->conteudo);
			}else{
				lista=lista->anterior;
				printf("| %i ",lista->conteudo);
			}
			
			if(lista->prox==NULL){
				lista=inicio;
				printf("| %i ",lista->conteudo);
			}else{
				lista=lista->prox;
				printf("| %i ",lista->conteudo);
			}
			atual=lista;
			
			if(lista->prox==NULL){
				lista=inicio;
				printf("| %i ",lista->conteudo);
			}else{
				lista= lista->prox;
				printf("| %i ",lista->conteudo);
			}
		}
		printf("\n << | II | >> \n");	
}

void playlist(){
	system("cls");
	int op;
	if(tamanho==0){
		printf("    Nao ha valores na lista, por favor insira um valor \n ");
	}else{
		if(tamanho==1){
			ini:
				visao_1();
				
				printf("(1)Anterior || (2)Proximo \n");
				printf("(3)SAIR \n");
				scanf("%i",&op);
				switch (op){
					
				case(1) :				
					goto ini;
					break;
			
				case(2) :		
					goto ini;	
					break;
			
				case(3) :
					break;
						
				default:
					printf("Opcao invalida \n");
					system("pause");
				}
			}
		
		else if(tamanho>1){
			
			
			int visualiza=1;
			int cont=0;
			
			retorno:
				
			if(visualiza==1){
				visao_1();
				visualiza=2;
				cont+=1;
				goto escolha;
			}
			 if(visualiza==2){
				visao_2();
					if(cont<(tamanho-1)){
						cont+=1;
					}else{
						cont=0;
						visualiza=1;
					}
				goto escolha;
			}
			 if(visualiza==3){
				visao_3();
				visualiza=2;
				goto escolha;
			}
			escolha:
				printf("\n (1)Anterior || (2)Proximo \n(3)Sair ");
				scanf("%i",&op);
				
				switch (op){
		
				case(1) :
					goto retorno;
					
					
					break;
				case(2) :
					prox_ant = 1;
					visualiza=3;
					
					
					goto retorno;
					break;
					
		
				case(3) :
				
					prox_ant = 0;
					break;
					goto retorno;
					
		
		
				default:
					printf("Nao ha essa opcao \n");
				break;
			}
		}
	}
}
	int main(){
	int op;
	
	for(;;){
		system("cls");
		printf ("(1)Inserir (2)Remover (3)Playlist (4)sair\n");
		scanf("%i",&op);
		
		if(op==1){
			inserir(op);
		}else if(op==2){
			Deletar(op);
		}else if(op==3){
			playlist();
		}else if(op==4){
			printf("Fim de Programa");
			break;
		}
	}
}


