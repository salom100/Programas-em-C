#include <stdio.h>
#include <stdlib.h>

	int op;
struct arvore{
	struct arvore *cima;
	int valor;
	struct arvore *esquerda;
	struct arvore *direita;
}*raiz, *atual, *anterior, *cavar, *andar, *inserir;

void colocar(){
	int valor;
	int teste=1;
	if(raiz == NULL){//se nao tiver nada deve cavar e plantar a semente
		cavar= (struct arvore *)malloc(sizeof(struct arvore));
		atual=cavar;
		printf("Digite um valor \n");
		scanf("%i",&cavar->valor);
		cavar->cima=NULL;
		cavar->direita=NULL;
		cavar->esquerda=NULL;
		raiz=cavar;
		andar=cavar;
	}else if(raiz!=NULL){
		printf("\n Digite um valor \n");
		scanf("%i",&valor);
		inserir=raiz;
		anterior=raiz;
		while(inserir!=NULL){
			if(valor>inserir->valor){//direita
				inserir = inserir->direita;
			}else if(valor<inserir->valor){//esquerda
				inserir = inserir->esquerda;
			}else if(valor == inserir->valor){//se o valor ja foi inserido
				inserir=NULL;
				teste=0;
			}
			if(inserir != NULL){
				anterior=inserir;
			}
		}	
		if(teste==1){
		
		cavar= (struct arvore*)malloc(sizeof(struct arvore));
		atual=cavar;
		cavar->valor=valor;
		cavar->direita=NULL;
		cavar->esquerda=NULL;
		cavar->cima=anterior;
		cavar=cavar->cima;
		
			if(valor<cavar->valor){
				cavar->esquerda=atual;
			}else if(valor>cavar->valor){
				cavar->direita=atual;
			}
		}	
	}
	
	printf("O valor foi inserido!! \n\n");
	
}

void quebraGalho(){
	arvore *temporaria = andar;
	andar = temporaria->cima;
	
	if (temporaria->direita == NULL && temporaria->esquerda != NULL){//Esquerda
		if (temporaria->cima->direita == temporaria){
			temporaria->cima->direita = temporaria->esquerda;
			temporaria->esquerda->cima = temporaria->cima;
			free(temporaria);
			
		}else if (temporaria->cima->esquerda == temporaria){
			temporaria->cima->esquerda = temporaria->esquerda;
			temporaria->esquerda->cima = temporaria->cima;
		}
	}else if (temporaria->esquerda == NULL && temporaria->direita != NULL){//Direita
		if (temporaria->cima->direita == temporaria){
			temporaria->cima->direita = temporaria->direita;
			temporaria->direita->cima = temporaria->cima;
		}else if (temporaria->cima->esquerda == temporaria){
			temporaria->cima->esquerda = temporaria->direita;
			temporaria->direita->cima = temporaria->cima;
		}
	}else if (temporaria->esquerda != NULL && temporaria->direita != NULL){//Direita Esquerda
		if (temporaria->esquerda->direita == NULL){
			temporaria->esquerda->direita = temporaria->direita;
			temporaria->esquerda->cima = NULL;
			
		}else {
			arvore *deletar = temporaria;
			deletar = deletar->esquerda;
			while (deletar->direita != NULL){
				deletar = deletar->direita;
			}
			if (deletar->esquerda == NULL){
				temporaria->valor = deletar->valor;
				deletar->cima->direita = NULL;
				temporaria->esquerda->direita= NULL;
				temporaria->esquerda->cima = temporaria->cima->esquerda;
				free(deletar);
			}else if (deletar->esquerda != NULL){
				temporaria->valor = deletar->valor;
				deletar->cima->direita = deletar->esquerda;
				deletar->esquerda->cima = deletar->cima;
				free(deletar);
			}
		}
		andar = temporaria;
	}else if (temporaria->direita == NULL && temporaria->esquerda == NULL) {
		if (temporaria->cima->direita == temporaria){
			temporaria->cima->direita = NULL;
			free(temporaria);
		}else if (temporaria->cima->esquerda == temporaria){
			temporaria->cima->esquerda = NULL;
			free(temporaria);
		}
	}
}


void macaco(){
	int escolha;
	andar=raiz;
	if(raiz==NULL){
		printf("\n Nao ha valores inseridos \n");
		system("pause");
	}else if(raiz !=NULL){
		for(;;){
			if((andar!=NULL)&& (andar->esquerda!=NULL)&&(andar->direita!=NULL)){
				system("cls");
				printf(" (1)esquerda (5)cima (3)direita (0)deletar (9)sair \n\n\n");
				printf("   {%i}  \n",andar->valor);
				printf("{%i}  {%i}",andar->esquerda->valor, andar->direita->valor );
			}else if((andar!=NULL)&& (andar->esquerda==NULL)&&(andar->direita!=NULL)){
				system("cls");
				printf(" (1)esquerda (5)cima (3)direita (0)deletar (9)sair \n\n\n");
				printf("   {%i}  \n",andar->valor);
				printf("{N}   {%i}",andar->direita->valor );
			}else if((andar!=NULL)&& (andar->esquerda!=NULL)&&(andar->direita==NULL)){
				system("cls");
				printf(" (1)esquerda (5)cima (3)direita (0)deletar (9)sair \n\n\n");
				printf("   {%i}  \n",andar->valor);
				printf("{%i}   {N}",andar->esquerda->valor );
			}else if((andar!=NULL)&& (andar->esquerda==NULL)&&(andar->direita==NULL)){
				system("cls");
				printf(" (1)esquerda (5)cima (3)direita (0)deletar (9)sair \n\n\n");
				printf("   {%i}  \n",andar->valor);
				printf("{N}    {N}");
			}
			scanf("%i",&escolha);
			if(escolha==5){
				if(andar != raiz){
					andar=andar->cima;
				}
			}else if(escolha==1){
				if(andar->esquerda!=NULL){
					andar=andar->esquerda;
				}
			}else if(escolha==3){
				if(andar->direita!=NULL){
					andar=andar->direita;
				}
			}else if(escolha==9){
				break;
			}else if(escolha==0){
				quebraGalho();
			}else{
				printf("Opcao invalida...");
			}

		}
	}
}

void preOrdem(){
	int vetor[20];
	int i=0;
	int j=0;
	//monta vetor
	for(i=0;i<20;i++){ // preenche
		vetor[i]=999;
	}
	system("cls");
	
	//Organiza
	i=0;
	vetor[i]=andar->valor;
	i++;
	
			while(andar->esquerda != NULL){
				andar= andar->esquerda;
				vetor[i]=andar->valor;
				i++;
				j++;
				printf("Profundidade %i \n",j);
			}
			while(andar->cima != NULL){
				andar= andar->cima;
				
			}
	
	
	
	
	
	
	
	//mostra o resultado pronto
	printf("vetor Pronto \n");
	for(i=0;i<20;i++){ 
		printf(" %i ",vetor[i]);
	}
	system("pause");
	
}



int main(){

	for(;;){
		system("cls");
		printf("\n Bem vindo a arvore binaria escolha uma opcao \n");
		printf("(1)inserir (2)andar (3)sair (4)Listar em Pre-Ordem\n");
		scanf("%i",&op);
		if(op==1){
			colocar();
		}else if(op==2){
			macaco();
		}else if(op==3){
			printf("Fim de Programa...\n");
			break;
		}else if(op==4){
			preOrdem();
		}
	}
}
