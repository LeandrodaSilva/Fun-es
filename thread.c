#include <stdio.h> /* scanf() */
#include <process.h> /* _beginthread() */
#include <windows.h> // sleep()

void beep(); // Protótipo da função beep()

int main()
{
     char nome[100];
     int idade;

     _beginthread(beep,0,NULL); // Chama a função beep() e faz dela uma thread

     printf("Insira o seu nome\n");
     scanf("%s",nome);

     printf("Insira a sua idade\n");
     fflush(stdin);
     scanf("%d",&idade);

     printf("Seu nome: %s\nSua idade: %d\n\nPrime qq tecla para continuar",nome,idade);
     getch();
     return(0);
}

void beep() // Observe que a função não tem o parâmetro ponteiro
{
        for(;;){
             printf("\a"); // o código de barra invertida \a é equivalente ao código ASCII 7 que simboliza 'beep' (som também é um carácter)
             Sleep(1000); // a cada segundo o programa emite um beep
        }
}
