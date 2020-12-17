 #include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Cadastro();
void AlteraCliente();
void ExcluiCliente();
void ConsultaCliente();
void ListarClientes();

int i;//para fazer os laços de repetiçao 
int cont=0;//para fazer preenchimento no codigo
//( %[^\n]s",) para pegar nome completo
struct CadastroClientes {
	int codigo;//deve ser sequencial e o usuario nao digita ele vem no cadastro e fica para ele.
	char nome[30];
	char sexo[10];
	int nascimento;
	int cpf;
	int telefone;
	char email[50];
	char estado[10];
};
struct   Login{
	int codigo;
	char nome[30];
	int cpf;
	char senha[30];
};
//criar funçoes para cadastro, alteraçao de dados e exclusao(inativar conta), consulta clientes,listar clientes.
struct CadastroClientes p[10000];
main(){
	struct Login q[100];
	int i,r; 				// contador para os laços de repetiçao 
	int opcao; 			// opcao para o menu dos cadastros de clientes 
	int opcaoM; 		// opcao para o menu de entrada dos funcionarios responsaveis pelo cadastro
	char senha[30]; 	// para cadastro do funcionario
	char senha2[30];	// comparaçao para validar o cadastro
	char nomeL[30];		//nome para verificaçao do login 
	char senhaL[30];		//senha para a verificaçao da senha
	int valida=0;		// quando alguem coloca o nome e senha no login e ve se encontra no banco de cadastro dos funcionario principais
	for(i=0;i<100;i++){
		//menu de entrada dos funcionarios que vao mexer nas planilhas
		printf("------------------------------------------------------------------ \n");
		printf("                  BEM VINDO AO SISTEMA ULTRASOFT \n\n\n");
		printf("Aperte: | (1) para Login | (2) para cadastro | (3) para sair |\n");
		scanf("%i",&opcaoM);
		if(opcaoM==3){
			printf("finalizando o sistema...");
			break;
		}
		else if(opcaoM==1){
		printf("-------Login------\n ");
		printf("   Nome:");
		scanf("%s",&nomeL);
		printf("\n    Senha:");
		scanf("%s",&senhaL);
		for(i=0;i<1000;i++){
		if(!strcmp(nomeL,q[i].nome)&&(senhaL,q[i].senha)){
			valida+=1;
			if(valida==1){ //verificaçao para a entrada do usuario
			//Menu principal para cadastro de clientes 
			for(r=0;r<10000;r++){
				system("cls");
				printf("Usuario: %s \n",q[i].nome);
				printf("Escolha uma das opcoes do menu abaixo \n");
				printf(" (1)Cadastro Cliente \n (2)Alterar Dados dos Clientes \n (3)Excluir cliente \n (4)Consulta Clientes \n (5)Listar clientes \n (6)Sair \n");
				scanf("%i",&opcao);
				//opçoes das quais serao chamadas as funcoes
				if(opcao==1){
				 	system("cls");
					 Cadastro();
				}else if(opcao==2){
					 AlteraCliente();
				}else if(opcao==3){
					 ExcluiCliente();
				}else if(opcao==4){
					 ConsultaCliente();
				}else if(opcao==5){
					 ListarClientes();
				}else if(opcao==6){
					printf("                                               Saindo..");
					break;
				}
			}
		}
		}else if(valida==0){
			printf("  !!Nome ou senha incorretos!! \n");
			break;
		}
		}
		}
	
		else if(opcaoM==2){//cadastro dos funcionarios que vao usar o programa
			for(i=0;i<100;i++){
			q[i].codigo=i+1;
			printf("------Cadastro-----\n");
			printf("Digite o seu nome: \n");
			scanf("%s",&q[i].nome);
			printf("Digite seu CPF: \n");
			scanf("%i",&q[i].cpf);
			printf("Digite sua senha: \n");
			scanf("%s",&senha);
			printf("Digite novamente a sua senha: \n");
			scanf("%s",&senha2);
			if(!strcmp(senha,senha2)){
				strcpy(q[i].senha,senha);
				printf("Cadastro realizado com sucesso !! \n");
				break;
			}else{
				printf("As senhas nao sao iguais \n");
				break;
			}
		}
	}
}
}
//Funçoes para a realizaçao das tarefas de criaçao, modificaçao e exclusao dos clientes 
void Cadastro(){	//CADASTRO
	char sexo[2];
	cont+=1;
	printf("Digite o nome completo do cliente \n");
	scanf(" %[^\n]s",&p[cont].nome);
	printf("Qual e o sexo do cliente ? (M)Masculino (F)Feminino \n");
	scanf("%s",&sexo);
	if(!strcmp(sexo,"m")){
		strcpy(p[cont].sexo,"Masculino");	
	}else{
		strcpy(p[cont].sexo,"Feminino");
	}
	printf("Digite a data de nascimento do cliente \n");
	scanf("%i",&p[cont].nascimento);
	printf("Digite o CPF do cliente \n");
	scanf("%i",&p[cont].cpf);
	printf("Digite o Telefone do cliente \n");
	scanf("%i",&p[cont].telefone);
	printf("Digite o E-mail do cliente \n");
	scanf(" %[^\n]s",&p[cont].email);
	p[cont].codigo+=cont;
	strcpy(p[cont].estado,"Ativado");
	printf("Cadastro de cliente feito com sucesso \n");
}

void AlteraCliente(){ //AlTERA DADOS DO CLIENTE 
	int modificar;
	int opcaoM;
	int ativar;
	char sexo[2];
	printf("Digite o codigo do cliente que deseja modificar \n");
	scanf("%i",&modificar);
	for(i=1;i<=cont;i++){
		if(modificar==i){
			printf("1|Nome: %s \n",p[i].nome);
			printf("2|Sexo: %s \n",p[i].sexo);
			printf("3|Data de Nascimento: %i \n",p[i].nascimento);
			printf("4|CPF: %i \n",p[i].cpf);
			printf("5|Telefone: %i \n",p[i].telefone);
			printf("6|E-mail: %s \n",p[i].email);
			if(!strcmp(p[i].estado,"Desativado")){//so aparecera essa opçao se o cliente estiver desativado 
			printf("7|Estado: %s \n",p[i].estado);//so aparecera essa opçao se o cliente estiver desativado 
			}
			printf("Digite o numero correspondente que voce deseja modificar \n");
			scanf("%i",&opcaoM);
			if(opcaoM==1){
				printf("Digite o nome que vai substituir o anterior \n");
				scanf(" %[^\n]",&p[i].nome);
			}
			else if(opcaoM==2){
				printf("Digite o sexo do cliente (M)Masculino (F)Feminino \n");
				scanf("%s",&sexo);
				if(!strcmp(sexo,"m")){
					strcpy(p[i].sexo,"Masculino");
				}else{
					strcpy(p[i].sexo,"Feminino");
				}	
			}
			else if(opcaoM==3){
				printf("Digite a nova data de nascimento \n");
				scanf("%i",&p[i].nascimento);
			}
			else if(opcaoM==4){
				printf("Digite o novo cpf \n");
				scanf("%i",&p[i].cpf);
			}
			else if(opcaoM==5){
				printf("Digite o novo telefone do cliente \n");
				scanf("%i",&p[i].telefone);
			}
			else if(opcaoM==6){
				printf("Digite o novo email do cliente \n");
				scanf(" %[^\n]s",&p[i].email);
			}
			else if(opcaoM==7){
				printf("Voce deseja ativar o cliente ? (1)Sim (2)Nao \n");
				scanf("%i",&ativar);
				if(ativar==1){
					strcpy(p[i].estado,"Ativado");//Reativa o cliente 
				}
			}
		}
	}
}

void ExcluiCliente(){ // CLIENTE QUE DESEJO EXCLUIR
	int procura;
	int permissao;
	printf("Digite o codigo do cliente que deseja desativar \n");
	scanf("%i",&procura);
	for(i=1;i<=cont;i++){
		if(procura==i){
		printf("%i |%s | %s \n",p[i].codigo,p[i].nome,p[i].sexo);
		printf("Voce realmente deseja desativar o usuario ? (1)Sim (2)nao \n");
		scanf("%i",&permissao);
		if(permissao==1){
			strcpy(p[i].estado,"Desativado");
		}
	}
	}
}

void ConsultaCliente(){ //CONSULTA OS CLIENTES (codigo ou nome)	
	int consulta;
	int sair;
	printf("Digite o codigo do cliente que deseja consultar \n");
	scanf("%i",&consulta);
	for(i=1;i<=cont;i++){
		if(consulta==i){
			printf("Nome: %s \n",p[i].nome);
			printf("Sexo: %s \n",p[i].sexo);
			printf("Data de Nascimento: %i \n",p[i].nascimento);
			printf("CPF: %i \n",p[i].cpf);
			printf("Telefone: %i \n",p[i].telefone);
			printf("E-mail: %s \n",p[i].email);
			printf("Estado: %s \n",p[i].estado);
			printf("Digite 1 para sair \n");
			scanf("%i",&sair);
		}
	}
}

void ListarClientes(){ //LISTA OS CLIENTES
	int sair;
	printf("PESSOAS CADASTRADAS \n");
	for(i=1;i<=cont;i++){
		if(!strcmp(p[i].estado,"Ativado")){
		printf("%i | %s | %s  | \n",p[i].codigo,p[i].nome,p[i].sexo);
		}
	}
	printf("Pressione 1 para sair \n");
	scanf("%i",&sair);
}
