
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
char linha[4];
char binario[100];
char hexadecimal[100];


	

int main (){
  setlocale(LC_ALL,"Portuguese");
  int i;
  char sinal[100];
  char numero[100];
  
  printf ("Digite um binario qualquer para converter em sinal digital: ");
  scanf ("%s", &binario);
//  ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
	
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
	printf("%s", sinal);
	for(i=1;i<=strlen(sinal);i+=3){
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
	system("pause");
	
	for(i=0;i<strlen(numero);i+=4){
		linha[0]=numero[i];
		linha[1]=numero[i+1];
		linha[2]=numero[i+2];
		linha[3]=numero[i+3];
		if(strcmp(linha,"0001")==0){
			printf("1");
		}else if(strcmp(linha,"0010")==0){
			printf("2");
		}else if(strcmp(linha,"0011")==0){
			printf("3");
		}else if(strcmp(linha,"0100")==0){
			printf("4");
		}else if(strcmp(linha,"0101")==0){
			printf("5");
		}else if(strcmp(linha,"0110")==0){
			printf("6");
		}else if(strcmp(linha,"0111")==0){
			printf("7");
		}else if(strcmp(linha,"1000")==0){
			printf("8");
		}else if(strcmp(linha,"1001")==0){
			printf("9");
		}else if(strcmp(linha,"1010")==0){
			printf("a");
		}else if(strcmp(linha,"1011")==0){
			printf("b");
		}else if(strcmp(linha,"1100")==0){
			printf("c");
		}else if(strcmp(linha,"1101")==0){
			printf("d");
		}else if(strcmp(linha,"1110")==0){
			printf("e");
		}else if(strcmp(linha,"1111")==0){
			printf("f");
		}
	}
}
