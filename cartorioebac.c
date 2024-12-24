#include <stdio.h> //iblioteca de comunica��o com o usuario 
#include <stdlib.h> //bilioteca de aloca��o de espa�o em mem�ria 
#include <locale.h>  // BiBlioteca de aloca��es de texto por regi�o 
#include <string.h> //bilioteca responsa�vel por cuidar dos string

int registro() //fu��o resposav�l por cadastrar os usu�rios o sistema
{
	//inicio da cria��o das vari�veis/string
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado: "); ///coletando informa��o do usu�rio
	scanf("%s" , cpf); //%s refere-se a string
	//final da cria��o das vari�veis/string
	
	strcpy(arquivo, cpf); //Respons�velpor copiar os valores das strig
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file =fopen(arquivo, "a"); //cria o arquivo atualizado
	fprintf(file, ","); //� para dar espa�o e ficar bonitinho
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta informa��o 
	scanf("%s" ,nome); //%s refere-se ao string
	
    file = 	fopen(arquivo, "a"); //guarda arquivo atualizado
    fprintf(file, nome); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // salva a variavel atualizada
	fprintf(file, ","); // da uma espa�ada
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coleta inform���o
	scanf("%s",sobrenome); // %s refere-se ao string
	
	file = fopen(arquivo, "a"); // atualiza
	fprintf(file,sobrenome); // salva informa��o
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //para voltar ao men�
			
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
   	printf("n�o foi possivel abrir o arquivo, n�o localizado!.\n");
   }
   
   while(fgets(conteudo, 200, file)  != NULL)
   {
   	printf("\nEssas s�o as informa��es do usuario: ");
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
   	  printf("O usu�rio n�o se econtra no sistema, ele  foi deletado!.\n");
   	  system("pause");
   	  
   }
    
	
}




int main ()
   {


	int opcao=0; //Defininindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    
	    system("cls");
	
	
	    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	  
	    printf("### cart�rio da EBAC ###\n\n"); //inicio de menu
	    printf("Escolha a op��o desejada do men�:\n\n");
	    printf("\t1 -  Registrar nomes\n");
	    printf("\t2 -  consultar nomes\n");
	    printf ("\t3 -  Deletar nomes\n");
	    printf("\t4 - Salir do sistema\n\n");
	    printf("Op��o: "); //fim do menu
	  
	    scanf("%d", &opcao); //armazenando a escolha do usuario
	  
	    system("cls");
	    
	    switch(opcao) //inicio da sele��o do men�
	    {
	    	case 1:
	    		registro(); // chamada do usu�rio
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
				printf("Essa op��o n�o est� disponiveil!\n");
				break;				
	   	} //fim da sele��o

} 

    
}

	  
 

