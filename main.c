#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*autor: Jose AlyssonP.S*/

char nomeUsuario[50];
char senhaUsuario[50];
char comandoControle;
char nomeDigitado[50];
char senhaDigitada[50];
char c;

struct tm tempo;
int i=0;
struct pacientes{
        int identPaciente;
        char nome[50];
        char cpf[15];
        char telefone[15];
        char rua[100];
        char bairro[100];
        int numeroRua;
        int anoNasc;
        char cep[12];
        char comorbidade[100];

    };






void telaCadastro(){
    system("cls");
    printf("\n\n\n\t ------APERTE QUALQUER TECLA PARA CONTINUAR COM O CADASTRO:-----\n\n");
    system("pause");
    system("cls");
    printf("\t\t\tCADASTRO DE USUÁRIO\n\n");
    printf("Digite um nome de usuário:");
    fflush(stdin);
    char nomeDigitado[50];
    char senhaDigitada[50];
    char c;
    int i=0;
    do
    {
       c=getch();//captura o caractere digitado pelo usuário
       if (isalpha(c)!=0 || isalnum(c)!=0)//se for uma letra ou numero
       {
          nomeDigitado[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o índice do vetor de caracteres
          printf ("%c", c);//exibe o caractere digitado
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
       {
          nomeDigitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
          i--;//o índice do vetor de caracteres é decrementado
          printf("\b \b");//o caractere digitado é apagado da tela
       }
    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)

    nomeDigitado[i]='\0';
    strcpy(nomeUsuario, nomeDigitado);
    printf("\nSeu nome de usuário será: %s", nomeUsuario);
    fflush(stdin);
    printf("\nDigite uma senha:");
    fflush(stdin);
    i=0;
    do
    {
       c=getch();//captura o caractere digitado pelo usuário
       if (isalpha(c)!=0 || isalnum(c)!=0)//se for uma letra ou numero
       {
          senhaDigitada[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o índice do vetor de caracteres
          printf ("%c", c);//exibe o caractere digitado
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
       {
          senhaDigitada[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
          i--;//o índice do vetor de caracteres é decrementado
          printf("\b \b");//o caractere digitado é apagado da tela
       }
    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)

    senhaDigitada[i]='\0';
    strcpy(senhaUsuario, senhaDigitada);
    printf("\nSua senha será: %s", senhaUsuario);
    cadastrar(nomeUsuario, senhaUsuario);









}
void cadastrar(char cadastrarNome[50], char cadastrarSenha[50]){
    char verificadorTexto[50];
    int achouNome=0;
    FILE *cadastroUser;
    cadastroUser= fopen("cadastro-usuarios.txt", "r");
        while(fgets(verificadorTexto,50, cadastroUser)!=NULL){
        strtok(verificadorTexto, "\n");
        if(strcmp(verificadorTexto, nomeUsuario)==0){
            achouNome++;
            fclose(cadastroUser);
            break;

        }
    }
    if(achouNome>0){
        printf("\n\nERRO:ESTE NOME DE USUARIO JÁ EXISTE. TENTE SE CADASTRAR COM OUTRO NOME.\n");
        printf("\nAPERTE QUALQUER TECLA PARA TENTAR SE CADASTRAR NOVAMENTE:");
        system("pause");
        telaCadastro();

    }else{
        cadastroUser= fopen("cadastro-usuarios.txt", "a");
        fputs(nomeUsuario, cadastroUser);
        fprintf(cadastroUser, "\n");
        fputs(senhaUsuario, cadastroUser);
        fprintf(cadastroUser, "\n");
        fclose(cadastroUser);
        printf("\n-----------CADASTRO DE USUÁRIO CONCLUÍDO--------------\n\n");
        system("pause");
        telaLogin();

    }
    }



void listarPacientesRisco(){
        system("cls");
        struct pacientes paciente;
        FILE *cadastropacienteRisco;
        cadastropacienteRisco= fopen("cadastro-pacientes-risco.txt", "rb");
        printf("\n\n\t\t--------LISTA DE PACIENTES DE RISCO--------");


   while(fread(&paciente, sizeof(struct pacientes),1,cadastropacienteRisco)==1){
        printf("\n\n\n\nPaciente Núemro: %d", paciente.identPaciente);
        printf("\n---------------------------");
        printf("\nNome: %s", paciente.nome);
        printf("\nCPF: %s", paciente.cpf);
        printf("\nAno de Nascimento: %d", paciente.anoNasc);
        printf("\nComorbidade: %s", paciente.comorbidade);
        printf("\nTelefone: %s", paciente.telefone);
        printf("---------------------------");
        printf("\n\tENDEREÇO");
        printf("\nCEP: %s", paciente.cep);
        printf("\nRua: %s", paciente.rua);
        printf("\nNúmero da rua: %d", paciente.numeroRua);
        printf("\nBairro: %s", paciente.bairro);

   }




    fclose(cadastropacienteRisco);
    printf("\n\n\t\tAPERTE V PARA VOLTAR");
    fflush(stdin);
    comandoControle=getch();
    if(comandoControle=='v'){
        telaLogado();
    }
    }



void listarPacientes(){
    system("cls");
    FILE *cadastroPac;
    cadastroPac=fopen("cadastro-pacientes.txt", "rb");
    struct pacientes paciente;
    printf("\n\n\t\t--------LISTA DE PACIENTES GERAIS--------");


   while(fread(&paciente, sizeof(struct pacientes),1,cadastroPac)==1){
        printf("\n\n\n\nPaciente Núemro: %d", paciente.identPaciente);
        printf("\n---------------------------");
        printf("\nNome: %s", paciente.nome);
        printf("\nCPF: %s", paciente.cpf);
        printf("\nAno de Nascimento: %d", paciente.anoNasc);
        printf("\nComorbidade: %s", paciente.comorbidade);
        printf("\nTelefone: %s", paciente.telefone);
        printf("---------------------------");
        printf("\n\tENDEREÇO");
        printf("\nCEP: %s", paciente.cep);
        printf("\nRua: %s", paciente.rua);
        printf("\nNúmero da rua: %d", paciente.numeroRua);
        printf("\nBairro: %s", paciente.bairro);

   }




    fclose(cadastroPac);
    printf("\n\n\t\tAPERTE V PARA VOLTAR");
    fflush(stdin);
    comandoControle=getch();
    if(comandoControle=='v'){
        telaLogado();
    }
    }

void cadastrarPaciente(){
    int nComorbidade;
    FILE *cadastroPac;
    cadastroPac= fopen("cadastro-pacientes.txt", "ab");
    system("cls");
    struct pacientes paciente;
    printf("\n\t\tCADASTRO DE PACIENTE\n");
    printf("\nDIGITE UM NÚMERO DE IDENTIFICAÇÃO PARA O PACIENTE NO SISTEMA:");
    fflush(stdin);
    scanf("%d", &paciente.identPaciente);
    printf("\nDIGITE O NOME DO PACIENTE: ");
    fflush(stdin);
    fgets(paciente.nome,50, stdin);
    printf("\nDIGITE O ANO DE NASCIMENTO DO PACIENTE(SOMENTE NÚMEROS): ");
    fflush(stdin);
    scanf("%d", &paciente.anoNasc);
    printf("\nDIGITE O CPF DO PACIENTE(COM AS PONTUAÇÕES): ");
    fflush(stdin);
    fgets(paciente.cpf,15, stdin);
    fflush(stdin);
    printf("\nDIGITE O TELEFONE OU CELULAR DO PACIENTE(SOMENTE NÚMEROS): ");
    fflush(stdin);
    fgets(paciente.telefone,15,stdin);
    fflush(stdin);
    printf("\nO PACIENTE POSSUI COMORBIDADES? s/n");
    comandoControle= getch();
    if(comandoControle=='s'){
            printf("\nCITE QUAL COMORBIDADE O PACIENTE POSSUI: ");
            fflush(stdin);
            fgets(paciente.comorbidade, 100, stdin);
            nComorbidade=1;

    }else{
       nComorbidade=0;
    }
    printf("\n\t\t-----ENDEREÇO DO PACIENTE----\n");
    printf("\nDIGITE O CEP DO PACIENTE:");
    fflush(stdin);
    fgets(paciente.cep,12, stdin);
    printf("\nDIGITE O NOME DA RUA ONDE O PACIENTE MORA: ");
    fflush(stdin);
    fgets(paciente.rua,100, stdin);
    printf("\nDIGITE O NÚMERO DA RUA: ");
    fflush(stdin);
    scanf("%d", &paciente.numeroRua);
    printf("\nDIGITE O BAIRRO: ");
    fflush(stdin);
    fgets(paciente.bairro,100,stdin);
    if(2021-paciente.anoNasc>=65|| nComorbidade==1){
        FILE *cadastropacienteRisco;
        cadastropacienteRisco= fopen("cadastro-pacientes-risco.txt", "ab");
         fwrite(&paciente, sizeof(struct pacientes),1,cadastropacienteRisco);
         printf("\n\t-----CADASTRO DE PACIENTE CONCLUIDO-----");
         printf("\n\tOBS: ESTE PACIENTE É DO GRUPO DE RISCO-----\n");
         fclose(cadastropacienteRisco);
         printf("\n\t\tAPERTE V PARA VOLTAR AO PAINEL DE USUÁRIO:");
         fflush(stdin);
        comandoControle=getch();
        if(comandoControle=='v'){
            telaLogado();

    }
    }
    fwrite(&paciente, sizeof(struct pacientes),1,cadastroPac);
    fclose(cadastroPac);
    printf("\n\t-----CADASTRO DE PACIENTE CONCLUIDO-----\n");
    printf("\n\tOBS: ESTE PACIENTE NÃO FAZ PARTE DO GRUPO DE RISCO\n");
    printf("\n\tAPERTE V PARA VOLTAR AO PAINEL DE USUÁRIO:");
    fflush(stdin);
    comandoControle=getch();
    if(comandoControle=='v'){
            telaLogado();

    }





}
void telaLogado(){
    system("cls");
    printf("\n\t\tSEJA BEM VINDO(A) %s\n", nomeUsuario);
    printf("\n\n\n VOCÊ PODE REALIZAR AS SEGUINTES OPERAÇÕES:");
    printf("\n\n\tAPERTE C PARA CADASTRAR UM NOVO PACIENTE.");
    printf("\n\n\tAPERTE L PARA VER A LISTA DE TODOS OS PACIENTES.");
    printf("\n\n\tAPERTE R PARA VER A LISTA DE TODOS OS PACIENTES DE RISCO.");
    comandoControle=getch();
    switch(comandoControle){
    case 'c':
        cadastrarPaciente();
        break;
    case 'l':
        listarPacientes();
        break;
    case 'r':
        listarPacientesRisco();
        break;
    }

}
void telaLogin(){
    char verificadorUsuario[50];
    char verificadorSenha[50];
    int encontrouNome=0;
    int encontrouSenha=0;
    system("cls");
    printf("\n\n\n\t ------APERTE QUALQUER TECLA PARA CONTINUAR EM ENTRAR:-----\n\n");
    system("pause");
    system("cls");
     printf("\t\t\tENTRAR NO SISTEMA");
     fflush(stdin);
     i=0;
     printf("\n\ndigite seu nome de usuário:");
     do
    {
       c=getch();//captura o caractere digitado pelo usuário
       if (isalpha(c)!=0 || isalnum(c)!=0)//se for uma letra
       {
          nomeDigitado[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o índice do vetor de caracteres
          printf ("%c", c);//exibe o caractere digitado
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
       {
          nomeDigitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
          i--;//o índice do vetor de caracteres é decrementado
          printf("\b \b");//o caractere digitado é apagado da tela
       }
    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)

    nomeDigitado[i]='\0';
    strcpy(nomeUsuario, nomeDigitado);
    fflush(stdin);
    printf("\nDigite sua senha:");
    fflush(stdin);
    i=0;
    do
    {
       c=getch();//captura o caractere digitado pelo usuário
       if (isalpha(c)!=0 || isalnum(c)!=0)//se for uma letra
       {
          senhaDigitada[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o índice do vetor de caracteres
          printf ("%c", c);//exibe o caractere digitado
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
       {
          senhaDigitada[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
          i--;//o índice do vetor de caracteres é decrementado
          printf("\b \b");//o caractere digitado é apagado da tela
       }
    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)

    senhaDigitada[i]='\0';
    strcpy(senhaUsuario, senhaDigitada);
    FILE *cadastroUser;
    cadastroUser= fopen("cadastro-usuarios.txt", "r");

        while(fgets(verificadorUsuario,50, cadastroUser)!=NULL){
        fgets(verificadorSenha,50, cadastroUser);
        strtok(verificadorUsuario, "\n");
        strtok(verificadorSenha, "\n");
        if(strcmp(verificadorUsuario, nomeUsuario)==0 && strcmp(verificadorSenha, senhaUsuario)==0){
            encontrouNome++;
            encontrouSenha++;
            fclose(cadastroUser);
            break;

            }
        }

        if(encontrouNome>0&& encontrouSenha>0){
            telaLogado(nomeUsuario);
        }else{
            printf("\n\nERRO:NOME DE USUARIO OU SENHA INCORRETOS TENTE NOVAMENTE OU CADASTRE-SE.\n");
            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR A TELA INICIAL:\n");
            system("pause");
            telaInicial();
        }



}

void telaInicial(){
    system("cls");
    printf("Seja bem vindo(a) ao Sistema de cadastro de pacientes com COVID-19.\n\n");
    printf("Aperte a tecla E para entrar ou C para cadastrar um usuário do sistema:\n");
    comandoControle=getch();
    if(comandoControle== 'c'|| comandoControle=='C'){
        telaCadastro();
    }
    else if(comandoControle== 'e'|| comandoControle=='E'){
        telaLogin();
    }



}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    telaInicial();
    return 0;

    /*ty*/

}
