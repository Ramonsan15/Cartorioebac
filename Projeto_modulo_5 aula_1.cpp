#include <stdio.h> // bibçioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de testo por região
#include <string.h> // biblioteca responsavel por cuidar das strings


int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPf a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // criando o arquivo
	fprintf(file,cpf); //sava o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
		
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
    
	
}

int consultar()

{
	setlocale(LC_ALL,"Portuguese");//Definindo a linguagens
	
 	char cpf[40];
 	char conteudo[200];
 	
 	printf("Digite o CPF a ser consultado:\n ");
 	scanf("%s",cpf);
 	
 	FILE *file;
 	file = fopen(cpf,"r");
 	
 	if(file ==NULL)
 	{
 		printf(" Não foi possivel abrir o arqivo, não encontrado!.\n\n");
	 }
	 
	 while(fgets(conteudo,200,file) !=NULL)
	 {
	 	printf("\nEssas são as informações encontradas: ");
	 	printf("%s",conteudo);
	 	printf("\n\n");
	 } 
	 system("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	printf("Usuario removido com sucesso:.\n");
	system("pause");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuario não encontrado!.\n");
		system ("pause");
	}
}

int main()

{	
	
	int opcao=0; //Definindo as váriaveis 
	int x=1;
	
	for(x=1;x=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL,"Portuguese");//Definindo a linguagens
	
		printf("@@@ cártorio da EBAC @@@\n\n");//Inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Resgistra nomes: \n");
		printf("\t2 - Consultar nomes:\n");
		printf("\t3 - Deletar nomes: \n");
		printf("\t4 - Sair do sistema:\n");
		printf("Opção");//Fim do menu
	
		scanf("%d", &opcao);//Armarzenando as escolhas do usuário
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consultar();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4: 
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel!\n\n");
			system("pause");
			break;
				
		} 	
	}
}
