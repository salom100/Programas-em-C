#include <stdio.h>
#include <stdlib.h>

int listagem=0;
int primeiro_valor=0;
int tamanho;
int posicao;
int multi;

struct lista {
	struct lista *anterior;
	int valor;
	struct lista *prox;
}*lista,*primeiro,*ultimo,*P, *A, *P1, *A1, *ESPECIFICO, *controle;

void criando_lista(){
	
	lista= (struct lista*)malloc(sizeof(struct lista));
	
	if(lista!=NULL){
		lista->anterior=NULL;
		lista->prox=NULL;
	}else{
		printf("HOUVE UM ERRO");
	}
}

void ALPHA(int multi){
	int valor = 0;
	
	do {
		if (listagem == 0){
			system ("cls");
			printf ("Digite um valor: ");
			scanf ("%i", &valor);
			
			lista->valor = valor;
			primeiro = lista;
			ultimo = primeiro;
			
			primeiro_valor = 1;
			
			posicao+=1;
			tamanho+=1;	
			
		}else if(primeiro_valor == 1){
			system ("cls");
			printf ("Digite um valor: ");
			scanf ("%i", &valor);
			
			lista->valor = valor;
			lista->prox = primeiro;
			primeiro->anterior= lista;
			
			primeiro = lista;
			P1 = lista;    
			
    		posicao+=1;
    		tamanho+=1;
    		
		}
	}while (valor == 0);	
}

void FIM(int multi){
	int valor = 0;
	do {
		system ("cls");
		
		printf ("Digite um valor para ser incluido no fim: ");
		scanf ("%i", &valor);
		
		lista->valor = valor;	
        ultimo->prox = lista;
		lista->anterior = ultimo;
		
		ultimo = lista;
		P1 = lista;  
		
		posicao+=1;
    	tamanho+=1;
    	
	}while (valor == 0);
}

void ESPECIFICA(int multi){
	
	int valor=0;
	
	do{
		system("cls");
	
			
		valor=0;	
		int posicao;
		int i = 2; 
		ESPECIFICO = primeiro;
			
		do{
				
			system("cls");
				
			printf("Digite a posicao para inserir o valor: ");
			scanf(" %i", &posicao);
			
				if(posicao >= 1 && posicao <= tamanho) {
  					break;
  				}
  						
				 else if ((posicao < 1) || (posicao >= tamanho + 1))
   					 {
        				printf("\n Posição NOT FOUND\n\n");
        				
        				
        				
        				
  					  }
  					  
			}while(2>1);
			
  					
			  						
			  		if (posicao== 1){
			    		
			    			system("cls");
			    			int multi=1;
			      			(multi);
			      			
			      			listagem = 1;
			      			goto final;
			      			
			   			 }
			   		else
			   		{
			        
			    			system("cls");
			    			
			    			
			      			listagem = 3;
					
						while (i < posicao)
			        	{
			           	 	ESPECIFICO = ESPECIFICO->prox;
			            	i+=1;
			        	}
			        		
						printf("Digite o valor para incluir: ");
						scanf(" %i", &valor);
							        	
							lista->valor = valor;
									
							A1 = lista;
											
						   	lista->anterior = ESPECIFICO;
						        	
						   	lista->prox = ESPECIFICO->prox;
						        	
						   	ESPECIFICO->prox->anterior = lista;
						        	
						   	ESPECIFICO->prox = lista;
						        	
							P1 = lista;  
				        	goto final;
			}	
		}while(valor == 0);	
		
		final:
   		posicao+=1;
    	tamanho+=1;
}

void Incluir(int op){
  
	int valor;
	
	if (tamanho == 0){
		
		
			system("cls");

			printf("A LISTA ESTA VAZIA, O VALOR SERA INCLUIDO NO INICIO.");
				
			multi= 1; 	


			
			ALPHA(multi);
			
			Listar1();
			
			system("pause");
			
	} else if(tamanho>0){
				
		system("cls");
	    printf("Escolha uma opcao para incluir:");
	 
		printf("\n");
		printf("1 - Incluir no inicio\n");
		printf("2 - Incluir no fim\n");
		printf("3 - Incluir em posicao especifica\n");
		printf("\n");
		scanf("%i", &multi);
		
		switch (multi){
	
			case(1):
				//INCLUI NO INICIO
				
				ALPHA(multi);
				Listar1();
				
				system("pause");
				break;
	
			case(2):
				//INCLUI NO FIM
				FIM(multi);
				Listar2();
				
				system("pause");
				break;
	
			case(3):
				//INCLUI EM POSICAO ESPECIFICA
				
				ESPECIFICO(multi);
				
				
				if(	flag_lista == 3){
					
				Listar3();	
				system("pause");
				
				}
				else if(listagem == 1){
					Listar1();
					system("pause");
				}
				      			
				break;
				
			default:
				printf("OPCAO INVALIDA!!!\n");
				printf("Por favor, verifique novamente as opcoes.\n");
			}
	system("cls");
	}   
}


void Listar(){
	lista = primeiro;
	system ("cls");
	printf ("Lista\n\n");
	while (lista->prox != NULL){
        printf(" %i |", lista->valor);
        lista = lista->prox;
    }
    printf(" %i ", lista->valor);
    printf("\n\n");
}

void Listar1(){
	system("cls");
		if (tamanho == 0){
			printf ("A lista esta vazia !!!");
		}else {
			Listar();
			if (tamanho == 1){
				if (lista == NULL){
					lista = primeiro;
					while (lista->prox != NULL){
     			   		lista = lista->prox;
  			 		}
					printf("| %i ",lista->valor);
				}else if(lista->anterior == NULL){
  			
  					lista=primeiro;
  			
 					while (lista->prox != NULL){
     			   		lista = lista->prox;
  			 		}
  			 	printf("| %i ",lista->valor);
				}else{
					lista=lista->anterior;
					printf("| %i ",lista->valor);
				}if(lista->prox==NULL){
  					lista=a;
					printf("| %i ",lista->valor);
				}else{
					lista= lista->prox;
					printf("| %i ",lista->valor);
				}
				controle=lista;
				if(lista->prox == NULL){
					lista=primeiro;
					printf("| %i ",lista->valor);
				}else {
					lista = lista->prox;
					printf("| %i ",lista->valor);
				}
				
			}else if (tamanho > 1){
				
				if(lista == NULL){
  					lista=primeiro;
  					
  					while (lista->prox != NULL){
     			   		lista = lista->prox;
  			 		}
  					printf("| %i ",lista->valor);
		
  				}else if(lista->anterior == NULL){
  					lista=primeiro;
  					
  					while (lista->prox != NULL){
     			   		lista = lista->prox;
  			 		}
  			 	printf("| %i ",lista->valor);
		
  				}else{
					lista=lista->anterior;	
					printf("| %i ",lista->valor);
				}if(lista->ponteiro_proximo==NULL){
					
				  	lista=primeiro;
					printf("| %i ",lista->valor);
				}else{
						
					lista= lista->prox;
					printf("| %i ",lista->valor);
				}
				
				controle=lista;
				
				if(lista->prox == NULL){
					lista=primeiro;	
					printf("| %i ",lista->valor);
				}else{
					lista = lista->prox; 
					printf("| %i ",lista->valor);
				}	
			}
		}
	printf("\nANTERIOR | ATUAL | PROXIMO");
	printf ("\n");
}

void Listar4() {
	system("cls");
	
	Listar();
	
	printf("\n");
	
	if (tamanho==1){
    
		lista = primeiro;
	    controle=lista;
	    
	    printf("| %i ",lista->valor);       
		
		printf("| %i ",lista->valor);
		
		printf("| %i ",lista->valor);
    } else if (tamanho>1){
 	
		lista=controle;
		lista=lista->anterior;
		printf ("\n");
	
		if(lista == NULL){
	  			
			lista=primeiro;
			
		 	while (lista->prox != NULL){
		       lista = lista->prox;
		  	} 	
		  			 	
			lista=lista->anterior;
		  			
			printf("| %i ",lista->valor);
			
	  	} else if(lista->anterior == NULL){
	  			
		  	lista=primeiro;
		  			
		 	while (lista->prox != NULL){
		       lista = lista-prox;
		  	}
		  					
			printf("| %i ",lista->valor);
			
	  	}else{
		
			lista=lista->anterior;	
			printf("| %i ",lista->valor);
		}
		
		if(lista->prox==NULL){
			
		  	lista=primeiro;
		  	
			printf("| %i ",lista->valor);	
			
		}else{
			
			lista= lista->prox;
			printf("| %i ",lista->valor);
		}
		
		controle=lista;
				
		if(lista->prox== NULL){
			
			lista=primeiro;	
			printf("| %i ",lista->valor);
			
		}else{
			
			lista = lista->prox;    
			printf("| %i ",lista->valor);
			
		}
	}
	printf("\n");
	printf("ANTERIOR | ATUAL | PROXIMO");
	printf("\n");		
}

void Listar5(){
	system("cls");
			
	Listar();
	printf("\n");
	printf("\n");
			
	if (tamanho==1){
    
		lista = primeiro;
	
	    printf("| %i ",lista->valor);       
		printf("| %i ",lista->valor);
		printf("| %i ",lista->valor);
	}
	
	else if (tamanho>1){
	 	lista=controle;
	
		
		lista = lista->prox;
		
		if(lista == NULL){
	  			
		  		lista=primeiro;
		  			
		 		while (lista->prox != NULL){
		    	   lista = lista->prox;
		  		}
		  		printf("| %i ",lista->valor);
			
		}else if(lista->anterior == NULL){
	  			
		  		lista=primeiro;
		  		
		 		while (lista->prox != NULL){
		    	   lista = lista->prox;
		  		}  			
				printf("| %i ",lista->valor);
			
	  	}else{
			lista=lista->anterior;	
			printf("| %i ",lista->valor);
		}
		
		
		if(lista->prox==NULL){	
		  	lista=primeiro;	
			printf("| %i ",lista->valor);
		}else{
				
			lista= lista->prox;
			printf("| %i ",lista->valor);
		}
			
		controle=lista;
		
		if(lista->prox == NULL){		
			
			lista=primeiro;
			printf("| %i ",lista->valor);
		} else{
			
			lista = lista->prox;        
			printf("| %i ",lista->valor);		
		}
	}
	printf("\n");	
	printf("ANTERIOR | ATUAL | PROXIMO");
	printf("\n");
}



















int main(){
	
	
}
