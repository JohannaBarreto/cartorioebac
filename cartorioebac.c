#include <stdio.h> //iblioteca de comunicação com o usuario 
#include <stdlib.h> //bilioteca de alocação de espaço em memória 
#include <locale.h>  // BiBlioteca de alocações de texto por região 
#include <string.h> //bilioteca responsaável por cuidar dos string

int registro() //fução resposavél por cadastrar os usuários o sistema
{
	//inicio da criação das variáveis/string
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado: "); ///coletando informação do usuário
	scanf("%s" , cpf); //%s refere-se a string
	//final da criação das variáveis/string
	
	strcpy(arquivo, cpf); //Responsávelpor copiar os valores das strig
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file =fopen(arquivo, "a"); //cria o arquivo atualizado
	fprintf(file, ","); //é para dar espaço e ficar bonitinho
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta informação 
	scanf("%s" ,nome); //%s refere-se ao string
	
    file = 	fopen(arquivo, "a"); //guarda arquivo atualizado
    fprintf(file, nome); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // salva a variavel atualizada
	fprintf(file, ","); // da uma espaçada
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coleta informãção
	scanf("%s",sobrenome); // %s refere-se ao string
	
	file = fopen(arquivo, "a"); // atualiza
	fprintf(file,sobrenome); // salva informação
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //para voltar ao menú
			
}

int consulta()
{
	setlocale(LC_ALL, "portugues"); //definindo a lingugem
	
   char cpf [40];
   char conteudo[200];
   
   printf("Digite o CPF a ser cosultado: ");
   scanf("%s" ,cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   if(file == NULL)
   {
   	printf("não foi possivel abrir o arquivo, não localizado!.\n");
   }
   
   while(fgets(conteudo, 200, file)  != NULL)
   {
   	printf("\nEssas são as informações do usuario: ");
   	printf("\n\n");
   	
   }
   
   
   system("pause");
     
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s" ,cpf); //responsavel por limpar a tela
	
    remove(cpf);
    
   FILE *file;
   file = fopen(cpf, "r");
   
   if(file == NULL )
   {
   	  printf("O usuário não se econtra no sistema, ele  foi deletado!.\n");
   	  system("pause");
   	  
   }
    
	
}




int main ()
   {


	int opcao=0; //Defininindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    
	    system("cls");
	
	
	    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	  
	    printf("### cartório da EBAC ###\n\n"); //inicio de menu
	    printf("Escolha a opção desejada do menú:\n\n");
	    printf("\t1 -  Registrar nomes\n");
	    printf("\t2 -  consultar nomes\n");
	    printf ("\t3 -  Deletar nomes\n");
	    printf("\t4 - Salir do sistema\n\n");
	    printf("Opção: "); //fim do menu
	  
	    scanf("%d", &opcao); //armazenando a escolha do usuario
	  
	    system("cls");
	    
	    switch(opcao) //inicio da seleção do menú
	    {
	    	case 1:
	    		registro(); // chamada do usuário
	    		break;
	    		
	    	case 2:
			     consulta();
				 break;
				 
			case 3:
				deletar();
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema\n");
				return 0;
				break;
				
			default:
				printf("Essa opção não está disponiveil!\n");
				break;				
	   	} //fim da seleção

} 

    
}

	  
 

