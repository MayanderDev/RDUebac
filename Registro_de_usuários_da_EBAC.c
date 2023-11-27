#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{ 
	//Início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da variável
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
} //Final do registro de usuários

int consulta() //Consulta de usuários cadastrados
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	char cpf[40]; //Inicio da criação de variáveis
	char conteudo[200]; //Fim da criação de variáveis
	
	printf("digite o CPF a ser consultado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //Acessa os arquivos
	file = fopen(cpf,"r"); //Abre e lê o arquivo
	
	if(file == NULL) //Arquivo não encontrado
	{
		printf("\tNão foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //Arquivo encontrado
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //%s refere-se a string
		printf("\n\n");	//Pula as linhas
	}
	
	system("pause");
} //Final da consulta

int deletar() //Deletando usuários cadastrados
{
	char cpf[40]; //Criação de variável
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //Acessa os arquivos
	file = fopen(cpf,"r"); //Abre e lê o arquivo
	
	if(file == NULL) //Se o arquivo não se encontra no sistema
	{
		printf("\tO usuário não se encontra no sistema!\n");
		system("pause");
	}
	
	remove(cpf); //Remove o arquivo
	
	if(file != NULL) //Usuário deletado
	{
		printf("\tO usuário foi deletado com sucesso!\n");
		system("pause");
	}
		
} //Fim da deleta de usuários

int main() //Função principal
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
		
		printf("\tRegistro de usuários da EBAC\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nome\n\n"); 
		printf("Opção: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls"); //Responsável por limpar a tela
		
		switch(opcao) //Início da seleção do menu
		{
			case 1:
				registro(); //Chamada de funções
				break;
				
			case 2:
				consulta(); //Chamada de funções
				break;
				
			case 3:
				deletar(); //Chamada de funções
				break;
				
			default:
				printf("\tEssa opção não está disponível!\n"); //Função inexistente
				system("pause");
				break;
		} //Fim da seleção
		
	}

}
