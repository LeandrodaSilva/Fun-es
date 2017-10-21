#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char  *argv[])
{
	char str[80];
	if (argc!=2)
	{	
		/* code */
		printf("uso: xerase <nomearq>\n");
		exit(1);
	}

	printf("apaga %s? (S/N): ", argv[1]);
	scanf("%s", &str);

	if (toupper(*str) == 'S')
	{	
		/* code */
		if (remove(argv[1]))
		{
			/* code */
			printf("O arquivo nao pode ser apagado.\n");
			exit(1);
		}
	}
	return 0;
}