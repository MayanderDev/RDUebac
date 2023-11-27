#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{ 
	//In�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,","); //Acrescenta "," ao arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,nome); //Acrescenta o nome ao arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,","); //Acrescenta "," ao arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,sobrenome); //Acrescenta o sobrenome ao aquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,","); //Acrescenta "," ao arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,cargo); //Acrescenta o sobrenome ao arquivo
	fclose(file); //Fecha o arquivo
	
	system("pause");
} //Final do registro de usu�rios

int consulta() //Consulta de usu�rios cadastrados
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	char cpf[40]; //Inicio da cria��o de vari�veis
	char conteudo[200]; //Fim da cria��o de vari�veis
	
	printf("digite o CPF a ser consultado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //Acessa os arquivos
	file = fopen(cpf,"r"); //Abre e l� o arquivo
	
	if(file == NULL) //Arquivo n�o encontrado
	{
		printf("\tN�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //Arquivo encontrado
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n");	//Pula as linhas
	}
	
	system("pause");
} //Final da consulta

int deletar() //Deletando usu�rios cadastrados
{
	char cpf[40]; //Cria��o de vari�vel
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //Acessa os arquivos
	file = fopen(cpf,"r"); //Abre e l� o arquivo
	
	if(file == NULL) //Se o arquivo n�o se encontra no sistema
	{
		printf("\tO usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	
	remove(cpf); //Remove o arquivo
	
	if(file != NULL) //Usu�rio deletado
	{
		printf("\tO usu�rio foi deletado com sucesso!\n");
		system("pause");
	}
		
} //Fim da deleta de usu�rios

int main() //Fun��o principal
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
		
		printf("\tRegistro de usu�rios da EBAC\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nome\n\n"); 
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //Respons�vel por limpar a tela
		
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1:
				registro(); //Chamada de fun��es
				break;
				
			case 2:
				consulta(); //Chamada de fun��es
				break;
				
			case 3:
				deletar(); //Chamada de fun��es
				break;
				
			default:
				printf("\tEssa op��o n�o est� dispon�vel!\n"); //Fun��o inexistente
				system("pause");
				break;
		} //Fim da sele��o
		
	}

}
