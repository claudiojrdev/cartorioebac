#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio criacao de vari�veis
	char arquivo[40];
	char cpf[40]; //CPF do tipo 40 (string de 40 caracteres)
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim criacao de vari�veis
	
	printf("Digite o CPF a ser cadastrado:");//coletando informa��es do usu�rio
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //anotando o cpf no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abrir e atualizar o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");//responsavel por pausar a tela
	
}

int consulta() //Fun��o Consulta
{	
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
}

int deletar() //Fun��o Deletar
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL )
	{
		printf("O Usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{	
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)//In�cio la�o de Repeti��o
	{
		
		system("cls"); // Limpando a Tela
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do Menu
		printf("Escolha a op��o desejado do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Opcao: "); //Fim do Menu
	
		scanf("%d",&opcao); //Armazenando a escolha do usu�rio
		
		system("cls");

		switch (opcao)
		{
			case 1: //caso opcao for 1 
			registro(); //instru��es
			break; //quebra
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause"); //fim da sele��o
		}
	}
}
