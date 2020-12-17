#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 1000

int main(){
	setlocale(LC_ALL,"Portuguese");
	char str[100];
	char strH[200];
	int i;
	int j;
	printf(" Digite a frase: \n");
	scanf(" %[^\n]s",str);
	
	printf("\n a frase e: %s \n",str);
	
	
	memset(strH,0,sizeof(strH));
	
	for(i=0,j=0;i<strlen(str);i++,j+=2){
		sprintf((char*)strH+j,"%02X",str[i]);
	}
	strH[j]='\0'; // adiciona nulo no final para na hora nao inserir um valor desnecessario
	
	printf("A frase em hexadecimal e : \n");
	printf("%s \n",strH);
	
	printf("aperte o botao para passar para de hexadecimal para binario\n");
	system("pause");
	
	char binario[1000], hexa[1000];
	int k=0;
	
	
	printf("\n O binario equivalente para o hexadecimal e: \n");
	
	while(strH[k]){
		switch(strH[k]){
			case '0':
				strcat(binario,"0000");
				 break;
			case '1':
				strcat(binario,"0001");
				 break;
			case '2':
				strcat(binario,"0010");
				 break;
			case '3':
				strcat(binario,"0011");
				 break;
			case '4':
				strcat(binario,"0100");
				 break;
			case '5':
				strcat(binario,"0101");
				 break;
			case '6':
				strcat(binario,"0110");
				 break;
			case '7':
				strcat(binario,"0111");
				 break;
			case '8':
				strcat(binario,"1000");
				 break;
			case '9':
				strcat(binario,"1001");
				 break;
			case 'A':
				strcat(binario,"1010");
				 break;
			case 'B':
				strcat(binario,"1011");
				 break;
			case 'C':
				strcat(binario,"1100");
				 break;
			case 'D':
				strcat(binario,"1101");
				 break;
			case 'E':
				strcat(binario,"1110");
				 break;
			case 'F':
				strcat(binario,"1111");
				 break;
			case 'a':
				strcat(binario,"1010");
				 break;
			case 'b':
				strcat(binario,"1011");
				 break;
			case 'c':
				strcat(binario,"1100");
				 break;
			case 'd':
				strcat(binario,"1101");
				 break;
			case 'e':
				strcat(binario,"1110");
				 break;
			case 'f':
				strcat(binario,"1111");
				 break;
			default:
				printf("\n digito invalido %c ", strH[k]);
				return 0;
				
		}
		k++;
	}
	
	printf("\n %s \n",binario);
	printf("Aperte para saber qual e o sinal gerado\n");
	system("pause");
	
	int s=0;
	printf("sinal passado de forma digital \n\n\n\n");
	
	FILE *sinal;
	char linha[100];
	int onda;
	int h=0;;
	sinal = fopen("sinal.txt","w");
	for(h=0;h<strlen(binario);h++){
		switch(binario[h]){
			case '0':
				strcpy(linha," ");
				onda= fputs(linha, sinal);
				break;
			case '1':
				strcpy(linha,"-");
				onda= fputs(linha, sinal);
				break;
		}
	}
	fclose(sinal);
	sinal = fopen("sinal.txt","a");
	fprintf(sinal,"\n");
	for(h=0;h<strlen(binario);h++){
		switch(binario[h]){
			case '0':
				strcpy(linha,"-");
				onda= fputs(linha, sinal);
				break;
			case '1':
				strcpy(linha,"-");
				onda= fputs(linha, sinal);
				break;
		}
	}
	
	sinal = fopen("sinal.txt","a");
	for(h=0;h<strlen(binario);h++){
		switch(binario[h]){
			case '0':
				strcpy(linha," ");
				onda= fputs(linha, sinal);
				break;
			case '1':
				strcpy(linha,"-");
				onda= fputs(linha, sinal);
				break;
		}
	}
	
	
	
	printf("\n\nFim dos processos e passagem dos dados analogico para digital \n\n");
}
