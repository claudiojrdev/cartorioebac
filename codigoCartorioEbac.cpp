#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criacao de variáveis
	char arquivo[40];
	char cpf[40]; //CPF do tipo 40 (string de 40 caracteres)
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim criacao de variáveis
	
	printf("Digite o CPF a ser cadastrado:");//coletando informações do usuário
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
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

int consulta() //Função Consulta
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
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
}

int deletar() //Função Deletar
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL )
	{
		printf("O Usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{	
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)//Início laço de Repetição
	{
		
		system("cls"); // Limpando a Tela
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //Início do Menu
		printf("Escolha a opção desejado do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Opcao: "); //Fim do Menu
	
		scanf("%d",&opcao); //Armazenando a escolha do usuário
		
		system("cls");

		switch (opcao)
		{
			case 1: //caso opcao for 1 
			registro(); //instruções
			break; //quebra
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível\n");
			system("pause"); //fim da seleção
		}
	}
}
