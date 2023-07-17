#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //alocacao de espacos de memoria
#include <locale.h> // alocacao de texto por regiao
#include <string.h> // resposavel por cuidar das strings


int registro() // Criar Usuarios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	system("cls"); //Limpar a tela
	
	//Inicio da definição de variaveis
	char arquivo [40]; 
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da definição de variaveis
	
	printf("Digite o CPF:\n");//coletando informalções do usuário
	scanf("%s", cpf); //referesse a string
	
	strcpy(arquivo, cpf); // copia o valor da string na segunda posição do argumento para uma variável string na primeira posiçã
	
	FILE*file;    	//cria o arquivo
	file = fopen(arquivo, "w");    	//cria o arquivo - "w" write
	fprintf(file,cpf);		//Atualiza o arquivo
	fclose(file);		//fecha o arquivo
	
	file = fopen(arquivo, "a");	//abre o arquivo - "a" atualiza	
	fprintf(file,", "); //Atualiza o arquivo
	fclose(file);	 	//Fecha o arquivo	
	
	printf("Digite o nome para cadastro:\n");
	scanf("%s", nome); //referesse a string
	
	file = fopen(arquivo, "a");	 //abre o arquivo - "a" atualiza		
	fprintf(file,nome);		 //Atualiza o arquivo
	fclose(file);	 	//Fecha o arquivo	
	
	file = fopen(arquivo, "a"); //abre o arquivo - "a" atualiza	
	fprintf(file,", "); //Atualiza o arquivo
	fclose(file); 	//Fecha o arquivo
	
	printf("Digite o sobrenome para cadastro:\n");
	scanf("%s", sobrenome); //referesse a string
	
	file = fopen(arquivo, "a");	//abre o arquivo - "a" atualiza	
	fprintf(file,sobrenome); //Atualiza o arquivo		
	fclose(file);	//Fecha o arquivo	
	 
	file = fopen(arquivo, "a");		//abre o arquivo - "a" atualiza	
	fprintf(file,", "); //Atualiza o arquivo
	fclose(file); 	//Fecha o arquivo
	
	printf("Digite o cargo para cadastro:\n");
	scanf("%s", cargo); //referesse a string
	
	file = fopen(arquivo, "a");		//abre o arquivo - "a" atualiza	
	fprintf(file,cargo);		//Atualiza o arquivo
	fclose(file);	//Fecha o arquivo
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	system("cls");
	
	//Inicio da definição de variaveis
	char cpf[40];
	char conteudo[200];
	//Final da definição de variaveis
	
	printf("Digito o CPF a consultar: "); //coletando informalções do usuário a ser consultado
	scanf("%s",cpf); //referesse a string
	
	FILE *file; //cria o arquivo
	file= fopen(cpf,"r"); // ler o arquivo "r" read
	
	//Notifica o erro 
	if(file==NULL) 
	{
		printf("\nNão Localizado!\n\n");
	}
	//Apresenta os dados
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nInformações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");	
	
}

int deletar()
{
	system("cls");

	char cpf[40];
	char conteudo[200];
	int escolha;
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
		
	FILE *file;	
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		system("cls");
		printf("\nO usuário não se encontra no sistema!.\n\n");		
		system("pause");
		return 0;
	}
	else(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nInformações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\ntem certeza que deseja deletar o usuario\n");
		printf("\t1 - Sim\n");
		printf("\t2 - Não\n");
		scanf("%d", &escolha); //escolha do usuario
		system("cls"); //Limpar a tela
		
		switch(escolha)
		{
			case 1:
				fclose(file);		
				remove(cpf);
				FILE *file;	
				file = fopen(cpf,"r");
				if(file == NULL)
				{
					printf("\nUsuário deletado com sucesso!.\n\n");
					system("pause");
				}
				fclose(file);
			break;
			case 2:
				printf("\nRetornando ao menu\n\n");
				system("pause");
				return 0;
			break;
		}
			
	}
}

int main()
	{
	//Inicio da definição de variaveis
	int opcao=0; 
	int laco=1;
	int voltar=0;
	char senhainserida[10]="a";
	int comparacao;
	
	printf("###Cartório de nomes da EBAC###\n\n"); 
	printf(" Senha admin:\n\n");
	scanf("%s",senhainserida);
	
	comparacao = strcmp(senhainserida, "admin");
		
	if(comparacao == 0)
	{
			
		for(laco=1;laco=1;)
		{

			system("cls"); //Limpar a tela
		
			setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
			printf("###Cartório de nomes da EBAC###\n\n"); //inicio do menu
			printf(" Escolha uma das opções a baixo:\n\n");
			printf("\t1 - REGISTRAR\n");
			printf("\t2 - CONSULTAR\n");
			printf("\t3 - EXCLUIR\n\n");
			printf("\t0 - SAIR\n\n "); 
			printf("Opções do sistema:\n\n"); //final do menu
	
			scanf("%d", &opcao); //escolha do usuario
		
			system("cls"); //Limpar a tela
		
			switch(opcao)
			{
				case 1:
					printf(" Deseja registar um Usuário?\n 1 - Sim   2 - Não\n");
					scanf("%d",&voltar);
				
					if(voltar==1)
					{
						registro(); //Chamada de funções	
					}
					else
					{
						system("cls"); //Limpar a tela
						printf("\nVoltando ao Menu\n\n"); //Informa que vai voltar ao Menu
						system("pause");
					}
					break;
				
				break;
			
				case 2:
					printf(" Deseja Consultar um Usuário?\n 1 - Sim   2 - Não\n");
					scanf("%d",&voltar);
				
					if(voltar==1)
					{
						consulta(); //Chamada de funções	
					}
					else
					{
						system("cls"); //Limpar a tela
						printf("\nVoltando ao Menu\n\n"); //Informa que vai voltar ao Menu
						system("pause");
					}
					break;	
						
				break;
							
				case 3:
					printf(" Deseja Deletar um Usuário?\n 1 - Sim   2 - Não\n");
					scanf("%d",&voltar);
				
					if(voltar==1)
					{
						deletar(); //Chamada de funções	
					}
					else
					{
						system("cls"); //Limpar a tela
						printf("\nVoltando ao Menu\n\n"); //Informa que vai voltar ao Menu
						system("pause");
					}
					break;
			
				break;
			
				case 0:
					printf(" Deseja Sair do Sistema?\n 1 - Sim   2 - Não\n");
					scanf("%d",&voltar);
				
					if(voltar==1)
					{
						return 0;
						break;
					}
					else
					{
						system("cls"); //Limpar a tela
						printf("\nVoltando ao Menu\n\n"); //Informa que vai voltar ao Menu
						system("pause");
					}
					break;
							
				default:
				printf("  Opção Inválida! Tente de novo\n\n");
				system("pause");
				break;	
					
			} //Fim da seleção
		}
	}
	else
		system("cls");
		printf("Senha Incorreta!");	
}
