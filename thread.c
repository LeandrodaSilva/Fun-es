#include <stdio.h> /* scanf() */
#include <process.h> /* _beginthread() */
#include <windows.h> // sleep()

void beep(); // Prot�tipo da fun��o beep()

int main()
{
     char nome[100];
     int idade;

     _beginthread(beep,0,NULL); // Chama a fun��o beep() e faz dela uma thread

     printf("Insira o seu nome\n");
     scanf("%s",nome);

     printf("Insira a sua idade\n");
     fflush(stdin);
     scanf("%d",&idade);

     printf("Seu nome: %s\nSua idade: %d\n\nPrime qq tecla para continuar",nome,idade);
     getch();
     return(0);
}

void beep() // Observe que a fun��o n�o tem o par�metro ponteiro
{
        for(;;){
             printf("\a"); // o c�digo de barra invertida \a � equivalente ao c�digo ASCII 7 que simboliza 'beep' (som tamb�m � um car�cter)
             Sleep(1000); // a cada segundo o programa emite um beep
        }
}
