#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas string

int registro() // fun��o para entrar na tela de registro
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40]; // definindo vari�vel/string para "arquivo"
	char cpf[40]; // definindo vari�vel/string para "cpf"
	char nome[40]; // definindo vari�vel/string para "nome"
	char sobrenome[40]; // definindo vari�vel/string para "sobrenome"
	char cargo[40]; // definindo vari�vel/string para "cargo"
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s",cpf); // lendo a informa��o cadastrada pelo usu�rio // "%s" armazena string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo "w" serve para criar
	fprintf(file, cpf); // armazena o arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" serve para alterar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" serve para alterar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" serve para alterar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
		
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" ler o arquivo
	
	system("cls");
	
	if(file == NULL)
	{
		printf("CPF n�o cadastrado.\n");
		system("pause");
	}
	else
	{
	fgets(conteudo, 200, file); // l� o conte�do completo
	
	char *token = strtok(conteudo, ","); // separa o conteudo em pequenas partes quando possui ","
	
	printf("\nEssas s�o as informa��es do usu�rio:\n\n");
	
	strupr(token); // Converte as letras de minuscula para maiusculas
	printf("\tCPF: %s\n", token); // aparece o CPF separado
	
	token = strtok(NULL, ","); // separa o conteudo da proxima ","
	strupr(token);
	printf("\tNome: %s\n", token); // aparece o nome separado
	
	token = strtok(NULL, ",");
	strupr(token);
	printf("\tSobrenome: %s\n", token); // aparece o sobrenome separado
	
	token = strtok(NULL, ",");
	strupr(token);
	printf("\tCargo: %s\n", token); // aparece o cargo separado
	
	printf("\n");
	
	fclose(file);	
	system("pause");
	}
}

int deletar ()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	system("cls");
	
	if(file == NULL)
	{
		printf("CPF n�o cadastrado\n");
		system("pause");
	}
	
	else
	{
		fclose(file);
		
		remove(cpf); // remove um cpf
	
		printf("Us�rio deletado!\n");
		
		system("pause");
	}

}
int main()
{
    int opcao=0; // definindo variaveis
    int rep=1; // vari�vel de la�o de repeti��o
    char senhadigitada[10]="a"; // vari�vel para armazenar a senha digitada
    char senha_correta[] = "admin"; //senha correta para o login
    
    printf("-- Cart�rio da EBAC --\n\n"); //barra n = pula linha 
    
    do
	{
    	printf("Login de administrador \n\n Digite a sua senha: ");
    	scanf("%s",senhadigitada); //leitura da senha informada
    	
    	if (strcmp(senhadigitada, senha_correta)!=0) //strcmp � uma fun��o de compara��o. Vai comparar a senha digitada com a var�avel senha_correta
			{ 
    		printf("\n\nSenha incorreta! Tente novamente!\n\n"); 
    		}
    	else
    	{
    		printf("\n\nLogin bem-sucedido!\n");
    		break;
		}
	}
	while (1); // Saida do loop caso correto 

   	for (rep=1;rep=1;)
   	{

   	    system("cls");

   	    setlocale(LC_ALL, "Portuguese"); //estamos colocando que o c�digo vai estar em portugues
       	printf("-- Cart�rio da EBAC --\n\n"); //barra n = pula linha 
       	printf("Selecione a op��o desejada: \n\n");
       	printf("\t1 - Registrar nomes de alunos\n"); //barra t = pula um espa�o consideravel do come�o do texto
       	printf("\t2 - Consultar nomes de alunos\n");
       	printf("\t3 - Deletar nomes de alunos\n");
       	printf("\t4 - Sair do sistema\n\n");
       	printf("Op��o: "); //fim do menu
					
	   	scanf("%d", &opcao); // scanf serve para armazenar o numero digitado na variavel opcao. tamb�m pausa o programa

   	    system("cls"); // tem como fun��o limpar a tela
	
      	switch(opcao) // inicio da sele��o do menu
   		{
       	    case 1:
           	registro(); // tem como objetivo chamar a fun��o "registro" criado no int
           	break;
			
           	case 2:
           	consulta();
           	break;

           	case 3:
           	deletar();
           	break;
            
           	case 4:
           	printf("Sistema finalizado!\n");
           	return 0; // tem como fun��o fechar o programa, quebrando os la�os
           	break;

           	default:
           	printf("Op��o indispon�vel!\n");
           	break;
       	}
   	}
}
