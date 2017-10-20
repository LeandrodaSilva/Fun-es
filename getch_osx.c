/*detecção do sistema e getch alternativo para mac*/
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#define limpa (system("cls"))
#define baixo 80
#define cima 72
#define enter 13
#define pausa (system("pause"))
#elif __APPLE__
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
#define pausa (system("read -n 1 -s -p \"Pressione uma Tecla...\""))
#define baixo 115
#define cima 119
#define enter 10
#else
exit(1);
#endif
