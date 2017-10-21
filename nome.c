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