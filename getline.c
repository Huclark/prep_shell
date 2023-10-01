#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t n = 10;
	char *buffer = malloc(sizeof(char) *n);

	printf("Hello!\nPlease enter name: ");
	getline(&buffer, &n, stdin);
	printf("Your name is %sBuffer size is %zu\n", buffer, n);
	
	free(buffer);
	return (0);
}