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
	system("cls");
	
	char binario[1000]="", hexa[1000];
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
	system("cls");
		printf("Frase ou Palavra : %s \n",str);
		printf("Hexadecimal da Frase: %s \n",strH);
		printf("Binario Gerado do Hexa decimal: %s \n",binario);
	int s=0;
	printf("\n Sinal passado de forma digital \n\n\n\n");
	char sinal[500]="";
	for(i=0;i<strlen(binario);i++){
        switch(binario[i]){
            case '0':
                printf("¯| ");
                strcat(sinal,"¯| ");
                switch(binario[i+1]){
                    case '0':
                    printf("|");
                    
                    
                }
                break;
            case '1':
                printf(" |¯");
                strcat(sinal," |¯");
                switch(binario[i+1]){
                    case '0':
                    printf("");
                    break;
                    case '1':
                    printf("|");
                    break;
                    
                    ;
                }
                break;
        }
    }
    printf("\n");
    for(i=0;i<strlen(binario);i++){
        
            printf("----");
            
            
       
    }
    printf("\n");
    for(i=0;i<strlen(binario);i++){
        switch(binario[i]){
            case '0':
                printf(" |_");
                switch(binario[i+1]){
                    case '0':
                        printf("|");
                    break;
                    case '1':
                        printf("");
                    break;
                }
                break;
            case '1':
                printf("_|");
                switch(binario[i+1]){
                    case '0':
                        printf(" ");
                    break;
                    case '1':
                        printf(" |");
                    break;
                }
        }
    }
	
	printf("\n Aperte qualquer botao para converter o sinal para binario \n");
 	system("pause");
 	system("cls");
 	char numero[500]="";
	printf("%s", sinal);
	for(i=0;i<=strlen(sinal);i+=3){
		switch (sinal[i]){
			case '¯':
				strcat(numero,"0");
				break;
			case ' ':
				strcat(numero,"1");
				break;
		}
	}
	
	printf("\n%s",numero);
	printf("\nAperte qualquer tecla para converter o binario em hexadecimal: \n");
	system("pause");
	system("cls");
	char linha[4];
	char hexadecimal[200]="";
	for(i=0;i<strlen(numero);i+=4){
		linha[0]=numero[i];
		linha[1]=numero[i+1];
		linha[2]=numero[i+2];
		linha[3]=numero[i+3];
		if(strcmp(linha,"0001")==0){
			printf("1");
			strcat(hexadecimal,"1");
		}else if(strcmp(linha,"0010")==0){
			printf("2");
			strcat(hexadecimal,"2");
		}else if(strcmp(linha,"0011")==0){
			printf("3");
			strcat(hexadecimal,"3");
		}else if(strcmp(linha,"0100")==0){
			printf("4");
			strcat(hexadecimal,"4");
		}else if(strcmp(linha,"0101")==0){
			printf("5");
			strcat(hexadecimal,"5");
		}else if(strcmp(linha,"0110")==0){
			printf("6");
			strcat(hexadecimal,"6");
		}else if(strcmp(linha,"0111")==0){
			printf("7");
			strcat(hexadecimal,"7");
		}else if(strcmp(linha,"1000")==0){
			printf("8");
			strcat(hexadecimal,"8");
		}else if(strcmp(linha,"1001")==0){
			printf("9");
			strcat(hexadecimal,"9");
		}else if(strcmp(linha,"1010")==0){
			printf("A");
			strcat(hexadecimal,"A");
		}else if(strcmp(linha,"1011")==0){
			printf("B");
			strcat(hexadecimal,"B");
		}else if(strcmp(linha,"1100")==0){
			printf("C");
			strcat(hexadecimal,"C");
		}else if(strcmp(linha,"1101")==0){
			printf("D");
			strcat(hexadecimal,"D");
		}else if(strcmp(linha,"1110")==0){
			printf("E");
			strcat(hexadecimal,"E");
		}else if(strcmp(linha,"1111")==0){
			printf("F");
			strcat(hexadecimal,"F");
		}else if(strcmp(linha,"0000")==0){
			printf("0");
			strcat(hexadecimal,"0");
		}
	}
	
	printf("\n aperte qualquer tecla para converter de haxadecimal para a frase original: \n");
	system("pause");
	system("cls");
	printf("\n\n\n");
	printf("A palavra provinda do sinal é : ");
	char si[3]="";
	for(i=0;i<strlen(hexadecimal);i+=2){
		si[0]=hexadecimal[i];
		si[1]=hexadecimal[i+1];
		if(strcmp(si,"30")==0){
			printf("0");
		}else if(strcmp(si,"31")==0){
			printf("1");
		}else if(strcmp(si,"32")==0){
			printf("2");
		}else if(strcmp(si,"33")==0){
			printf("3");
		}else if(strcmp(si,"34")==0){
			printf("4");
		}else if(strcmp(si,"35")==0){
			printf("5");
		}else if(strcmp(si,"36")==0){
			printf("6");
		}else if(strcmp(si,"37")==0){
			printf("7");
		}else if(strcmp(si,"38")==0){
			printf("8");
		}else if(strcmp(si,"39")==0){
			printf("9");
		}else if(strcmp(si,"41")==0){
			printf("A");
		}else if(strcmp(si,"42")==0){
			printf("B");
		}else if(strcmp(si,"43")==0){
			printf("C");
		}else if(strcmp(si,"44")==0){
			printf("D");
		}else if(strcmp(si,"45")==0){
			printf("E");
		}else if(strcmp(si,"46")==0){
			printf("F");
		}else if(strcmp(si,"47")==0){
			printf("G");
		}else if(strcmp(si,"48")==0){
			printf("H");
		}else if(strcmp(si,"49")==0){
			printf("I");
		}else if(strcmp(si,"4A")==0){
			printf("J");
		}else if(strcmp(si,"4B")==0){
			printf("K");
		}else if(strcmp(si,"4C")==0){
			printf("L");
		}else if(strcmp(si,"4D")==0){
			printf("M");
		}else if(strcmp(si,"4E")==0){
			printf("N");
		}else if(strcmp(si,"4F")==0){
			printf("O");
		}else if(strcmp(si,"50")==0){
			printf("P");
		}else if(strcmp(si,"51")==0){
			printf("Q");
		}else if(strcmp(si,"52")==0){
			printf("R");
		}else if(strcmp(si,"53")==0){
			printf("S");
		}else if(strcmp(si,"54")==0){
			printf("T");
		}else if(strcmp(si,"55")==0){
			printf("U");
		}else if(strcmp(si,"56")==0){
			printf("V");
		}else if(strcmp(si,"57")==0){
			printf("W");
		}else if(strcmp(si,"58")==0){
			printf("X");
		}else if(strcmp(si,"59")==0){
			printf("Y");
		}else if(strcmp(si,"5A")==0){
			printf("Z");
		}else if(strcmp(si,"61")==0){
			printf("a");
		}else if(strcmp(si,"62")==0){
			printf("b");
		}else if(strcmp(si,"63")==0){
			printf("c");
		}else if(strcmp(si,"64")==0){
			printf("d");
		}else if(strcmp(si,"65")==0){
			printf("e");
		}else if(strcmp(si,"66")==0){
			printf("f");
		}else if(strcmp(si,"67")==0){
			printf("g");
		}else if(strcmp(si,"68")==0){
			printf("h");
		}else if(strcmp(si,"69")==0){
			printf("i");
		}else if(strcmp(si,"6A")==0){
			printf("j");
		}else if(strcmp(si,"6B")==0){
			printf("k");
		}else if(strcmp(si,"6C")==0){
			printf("l");
		}else if(strcmp(si,"6D")==0){
			printf("m");
		}else if(strcmp(si,"6E")==0){
			printf("n");
		}else if(strcmp(si,"6F")==0){
			printf("o");
		}else if(strcmp(si,"70")==0){
			printf("p");
		}else if(strcmp(si,"71")==0){
			printf("q");
		}else if(strcmp(si,"72")==0){
			printf("r");
		}else if(strcmp(si,"73")==0){
			printf("s");
		}else if(strcmp(si,"74")==0){
			printf("t");
		}else if(strcmp(si,"75")==0){
			printf("u");
		}else if(strcmp(si,"76")==0){
			printf("v");
		}else if(strcmp(si,"77")==0){
			printf("w");
		}else if(strcmp(si,"78")==0){
			printf("x");
		}else if(strcmp(si,"79")==0){
			printf("y");
		}else if(strcmp(si,"7A")==0){
			printf("z");
		}else if(strcmp(si,"20")==0){
			printf(" ");
		}
	}

	
	
	printf("\n\nFim dos processos e passagem dos dados analogico para digital \n\n");
}
