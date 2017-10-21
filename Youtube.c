/*
* Nome: Leandro da Silva
* OS: Linux, Mac OS , Win32 and Win64 	
* Versão: 999991³ * ∞
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef _WIN32
#define enter 13
#include <conio.h>
#define limpa (system("cls"))
#define pausa (system("pause"))
#else
#define enter 10
#include <termios.h>
static struct termios old, new;
void initTermios(int echo){
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}
void resetTermios(void){
  tcsetattr(0, TCSANOW, &old);
}
char getch_(int echo){
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
char getch(void){
  return getch_(0);
}
char getche(void){
  return getch_(1);
}
#define limpa (system("clear"))
#define pausa (getch())
#endif


typedef struct YOUTUBE
{
  char channel_name[50];
  int views;
  int subscribers;
}youtube;

void scanome(char[],int);
void addchannel(int*);
void listchannel(int);
void delete(int*);

FILE *arquivo;
int rquantidade = 0;

int main(int argc, char const *argv[]) {
  #ifdef _WIN32
  system("mode con:cols=50 lines=20");
  #endif

  int quantidade = 0;
  char tecla;

  if ((arquivo = fopen("data.dat", "a+")) == NULL) {
    printf("Erro.\n");
    exit(1);
  }
  rewind(arquivo);


  if (fscanf(arquivo,"%d\n",&rquantidade) != EOF) {
    if (rquantidade > 0) {
      quantidade = rquantidade;

    }
  }else{
    printf("Erro.\n");
  }
  fclose(arquivo);
  if ((arquivo = fopen("data.dat", "r+")) == NULL) {
    printf("Erro.\n");
    exit(1);
  }
  fprintf(arquivo, "%d\n", quantidade);
  fclose(arquivo);

  while (1) {
   
    limpa;
    printf("         |Registros = %d|\n", quantidade);
    printf("(1) Inserir um novo youtuber\n");
    printf("(2) Listar os youtubers cadastrados\n");
    printf("(3) Apagar tudo\n");
    printf("(4) Sair\n");

    
    tecla = getch();
    

    switch(tecla){
      case '1': addchannel(&quantidade); break;
      case '2': listchannel(quantidade); break;
      case '3': delete(&quantidade); break;
      case '4':
      if (quantidade != 0)
      {
        if ((arquivo = fopen("data.dat", "r+")) == NULL) {
          printf("Erro no salvamento\n");
        }else{
          fprintf(arquivo, "%d\n", quantidade);
          fclose(arquivo);
        }
      }
      exit(0);
      break;
    }

  }



  return 0;
}



void addchannel(int *quantidade){

  youtube canal;
  canal.views = 0;
  canal.subscribers = 0;

  if (*quantidade == 0)
  {
    if ((arquivo = fopen("data.dat", "w+")) == NULL) {
          printf("Erro.\n");
          exit(1);
        }
        rewind(arquivo);
        fprintf(arquivo, "%d\n", *quantidade);
        fclose(arquivo); 
  }

  if ((arquivo = fopen("data.dat", "a+")) == NULL) {
    printf("Erro, nao foi possivel abrir o arquivo\n");
  }else{
    limpa;

    printf("Informe o nome do canal: ");
    fflush(stdin);
    scanome(canal.channel_name, 50);
    

    fflush(stdin);
    while (canal.views<=0){
      printf("\nQuantidade de views: ");
      if (scanf("%d", &canal.views)==0){
        printf("Informe apenas numeros positivos\n");
        while(fgetc(stdin)!='\n');
        continue;
      }
      if (canal.views<=0) {
        printf("Erro.\n");
      }
    }
    fflush(stdin);
    while (canal.subscribers<=0){
      printf("Quantidade de inscritos: ");
      if (scanf("%d", &canal.subscribers)==0){
        printf("Informe apenas numeros positivos\n");
        while(fgetc(stdin)!='\n');
        continue;
      }
      if (canal.subscribers<=0) {
        printf("Erro.\n");
      }
    }
    fprintf(arquivo, "%s\n%d\n%d\n\n", canal.channel_name, canal.views, canal.subscribers);
    (*quantidade)++;
    fclose(arquivo);

    if ((arquivo = fopen("data.dat", "r+")) == NULL) {
      printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
      fprintf(arquivo, "%d\n", *quantidade);
      fclose(arquivo);
    }
    

  }
}
  void delete(int * quantidade){
    
    char tecla[80];

    printf("\n\nDeseja mesmo apagar? (S/N): ");
    scanf("%79[s S n N]s", &tecla);

    if (toupper(*tecla) == 'S')
    { 
      if (remove("data.dat"))
      {
       printf("O arquivo <data.dat> nao pode ser apagado.\n");
      }else{
        *quantidade = 0;
      }
    }
}



void listchannel(int quantidade){
  int view, sub;
  char nome[50];

  if (quantidade > 0) {
    limpa;
    if((arquivo = fopen("data.dat", "a+")) == NULL){
      printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{
      rewind(arquivo);
      fseek(arquivo, 2, SEEK_CUR);
      while (fscanf(arquivo, "%s\n%d\n%d\n\n", nome, &view, &sub) != EOF) {
        printf("Nome do canal: %s\nVisualizacoes: %d\nInscritos: %d\n---------------------------------------------------------\n", nome, view, sub);
      }
      fclose(arquivo);
      pausa;
    }
  }
}


void scanome(char nome[],int n)
{
  int i = 0,espaco = 0;
  char tecla;
  while (i < n) {
    fflush(stdin);
    tecla = getch();

    if (i == 0) { // primeira letra em maiusculo
      if (tecla >= 'a' && tecla <= 'z' && espaco == 0) {
        nome[i] = tecla - 32;
        printf("%c", nome[i]);
        i++;
        fflush(stdin);
        tecla  = '\x00';
      }
      if (tecla >= 'A' && tecla <= 'Z' && espaco == 0) {
        nome[i] = tecla;
        printf("%c", nome[i]);
        i++;
        fflush(stdin);
        tecla  = '\x00';
      }
    }

    if (i >= 1) { // preenche a string normalmente
      if (tecla >= 'a' && tecla <= 'z' && espaco == 0) {
        nome[i] = tecla;
        printf("%c", nome[i]);
        i++;
        fflush(stdin);
      }
      if (tecla >= 'A' && tecla <= 'Z' && espaco == 0) {
        nome[i] = tecla + 32;
        printf("%c", nome[i]);
        i++;
        fflush(stdin);
      }
      /*caso seja a proxima letra apos o espaco, torna a letra maiscula*/
      if (tecla >= 'a' && tecla <= 'z' && espaco == 1) {
        nome[i] = tecla - 32;
        printf("%c", nome[i]);
        i++;
        espaco = 0;
        fflush(stdin);
      }
      if (tecla >= 'A' && tecla <= 'Z' && espaco == 1) {
        nome[i] = tecla;
        printf("%c", nome[i]);
        i++;
        espaco = 0;
        fflush(stdin);
      }

      if (tecla == ' ') { // se pressionar a tecla espaco adiciona o espaco na string
        nome[i] = tecla;
        printf(" ");
        espaco = 1;
        i++;
        fflush(stdin);
      }

      if (tecla == enter) { // se pressionar o Enter finaliza a coleta da string
        nome[i] = '\0';
        break;
      }
      /* caso pressione o backspace apaga a string regressivamente*/
      if (tecla == 8 && i > 0) {
        printf("\x08");
        i--;
        if (nome[i-1] == ' ') {
          espaco = 1;
        }
        if (nome[i] == ' ') {
          espaco = 0;
        }
        nome[i] = '\0';
        limpa;
        printf("Informe o nome do canal: ");
        if (i > 0) {
          printf("%s",nome);
        }
        fflush(stdin);
      }
    }

  }
}