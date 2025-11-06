#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// driver function of code
int main()
{
	char binary1[100];
	char binary2[100];

	return 0;
}

char* addBinary(char* item_1, char* item_2)
{
	int len_item_1 = strlen(item_1);
	int len_item_2 = strlen(item_2);
	int max_len = (len_item_1 > len_item_2) ? len_item_1 : len_item_2;

	// allocate memory of results
	char* result = (char*)malloc(sizeof(char) * (max_len + 2));

	if (result == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	result[max_len + 1] = '\0';
}