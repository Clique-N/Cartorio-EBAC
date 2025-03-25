#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas string

int registro() // função para entrar na tela de registro
{
	//inicio da criação de variáveis/string
	char arquivo[40]; // definindo variável/string para "arquivo"
	char cpf[40]; // definindo variável/string para "cpf"
	char nome[40]; // definindo variável/string para "nome"
	char sobrenome[40]; // definindo variável/string para "sobrenome"
	char cargo[40]; // definindo variável/string para "cargo"
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informações do usuário
	scanf("%s",cpf); // lendo a informação cadastrada pelo usuário // "%s" armazena string
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
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
		printf("CPF não cadastrado.\n");
		system("pause");
	}
	else
	{
	fgets(conteudo, 200, file); // lê o conteúdo completo
	
	char *token = strtok(conteudo, ","); // separa o conteudo em pequenas partes quando possui ","
	
	printf("\nEssas são as informações do usuário:\n\n");
	
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
	
	printf("Digite o CPF do usuário que deseja deletar:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	system("cls");
	
	if(file == NULL)
	{
		printf("CPF não cadastrado\n");
		system("pause");
	}
	
	else
	{
		fclose(file);
		
		remove(cpf); // remove um cpf
	
		printf("Usário deletado!\n");
		
		system("pause");
	}

}
int main()
{
    int opcao=0; // definindo variaveis
    int rep=1; // variável de laço de repetição
    char senhadigitada[10]="a"; // variável para armazenar a senha digitada
    char senha_correta[] = "admin"; //senha correta para o login
    
    printf("-- Cartório da EBAC --\n\n"); //barra n = pula linha 
    
    do
	{
    	printf("Login de administrador \n\n Digite a sua senha: ");
    	scanf("%s",senhadigitada); //leitura da senha informada
    	
    	if (strcmp(senhadigitada, senha_correta)!=0) //strcmp é uma função de comparação. Vai comparar a senha digitada com a varíavel senha_correta
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

   	    setlocale(LC_ALL, "Portuguese"); //estamos colocando que o código vai estar em portugues
       	printf("-- Cartório da EBAC --\n\n"); //barra n = pula linha 
       	printf("Selecione a opção desejada: \n\n");
       	printf("\t1 - Registrar nomes de alunos\n"); //barra t = pula um espaço consideravel do começo do texto
       	printf("\t2 - Consultar nomes de alunos\n");
       	printf("\t3 - Deletar nomes de alunos\n");
       	printf("\t4 - Sair do sistema\n\n");
       	printf("Opção: "); //fim do menu
					
	   	scanf("%d", &opcao); // scanf serve para armazenar o numero digitado na variavel opcao. também pausa o programa

   	    system("cls"); // tem como função limpar a tela
	
      	switch(opcao) // inicio da seleção do menu
   		{
       	    case 1:
           	registro(); // tem como objetivo chamar a função "registro" criado no int
           	break;
			
           	case 2:
           	consulta();
           	break;

           	case 3:
           	deletar();
           	break;
            
           	case 4:
           	printf("Sistema finalizado!\n");
           	return 0; // tem como função fechar o programa, quebrando os laços
           	break;

           	default:
           	printf("Opção indisponível!\n");
           	break;
       	}
   	}
}
