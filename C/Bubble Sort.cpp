// NOVA MATERIA 
// BUBBLE SORT
// VAI TER UMA VARIAVEL DO TIPO FLAG, ELE VALE 0 SE NAO TIVER ALTERA��O 
// E SE TIVER 1 SIGNIFICA QUE HOUVE UMA ALTERA��O 
// CRIAMOS UMA VARIAVEL TEMPORARIA QUE VAI GUARDAR UM DOS ELEMENTOS TEMPORARIAMENTE 
// CRIO UM PONTO AONDE  CAMINHO PELAS POSI��ES E FA�O A PERGUNTA
// A VARIAVEL PERGUNTA: O PRIMEIRO VALOR E MAIOR QUE O PROXIMO ? 
// SE NAO FOR ELE ANDA RETO NA FILA
// SE  VALOR NAO � MENOR QUE O PROXIMO EU MUDO MINHA FLAG PARA 1 
// COLOCO O VALOR MAIOR NA TEMPORARIA E O VALOR DA FRENTE PASSA PARA A POSI��O DO MAIOR ANTERIOR 
// PEGO O VALOR DA TEMPORARIA E COLOCO NA POSI��O SEGUINTE
// SE TIVER OUTRO VALOR E FOR FEITA OUTRA ALTERA��O A FLAG CONTINUA VALENDO 1 
// O PROGRAMA SO ENCERRA SE A FLAG FOR IGUAL A 1 
// ATE LA ELE FICA REPETINDO A FUN��O

 // JAVA, C# E PYTHON JA TEM SEUS ORDENADORES 
 
 
// RESULTADO

 #include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
	int flag=0;// usado para anotar a altera��o
	int temporaria;// mantem um valor temporariamente para a troca de organiza��o
	int op;// receber uma op��o
	int i; 
	int vetor[5];
	

	
	FILE *ponteiro_arquivo;// Cria variavel ponteiro para salvar
	
	
	for(;;){
		printf(" \nEscolha uma das opcoes \n");
		printf("(1)Inserir (2)mostrar (3)Organizar (4)GRAVAR (5)SAIR \n");
		scanf("%i",&op);
		if(op==1){
			for( i=0;i<5;i++){
				printf("Insira um numero: \n");
				scanf("%i",&vetor[i]);
			}
		}else if(op==2){
			for( i=0;i<5;i++){
				printf(" %i -",vetor[i]);
			}
		}else if(op==3){
			for(;;){
				for(i=0;i<4;i++){
						if(vetor[i]>vetor[i+1]){
							temporaria=vetor[i];
							vetor[i]=vetor[i+1];
							vetor[i+1]=temporaria;
							flag=1;
						}	
				}
				if(flag==0){
					break;
				}
				flag=0;
			}
		}else if(op==4){
			
			ponteiro_arquivo=fopen("arquivo_organizado.txt","w");
			
			//testando se o arquivo foi realmente criado
			if(ponteiro_arquivo==NULL){
			printf("Erro na Abertura do arquivo");
			return 1;
			}
			
			for(i=0;i<5;i++){
				fprintf(ponteiro_arquivo, "%d -", vetor[i]);
			}
			
			
			fclose(ponteiro_arquivo);
			printf("DADOS GRAVADOS COM SUCESSO");
	
		}else if(op=5){
			printf("Fim do programa....");
			break;
		}	
	}	
}
