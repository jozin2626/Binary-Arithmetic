#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


// driver function of code
int main()
{
	// seed rng, will use randomly generated binary to test
	srand(time(NULL));
	unsigned char bin1 = generate_8bit_char();
	unsigned char bin2 = generate_8bit_char();

	return 0;
}

unsigned char generate_8bit_char()
{
	unsigned char random_byte = 0;

	for (int i = 0; i < CHAR_BIT; i++)
	{
		int random_bit = rand() % 2;
		// shift existing bit left and add new bit
		random_byte = (random_byte << 1) | random_bit;
	}
	return random_byte;
}

char* addBinary(char* item_1, char* item_2)
{
	// both items being binary numbers input to function
	int len_item_1 = strlen(item_1);
	int len_item_2 = strlen(item_2);
	// determine max length
	int max_len = (len_item_1 > len_item_2) ? len_item_1 : len_item_2;

	// allocate memory of results
	char* result = (char*)malloc(sizeof(char) * (max_len + 2));

	if (result == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	result[max_len + 1] = '\0';

	// variables used for looping and storing results
	int idx_1 = len_item_1 - 1;
	int idx_2 = len_item_2 - 1;
	int idx_end = max_len;
	int carry = 0;

	while (idx_1 >= 0 || idx_2 >= 0 || carry > 0)
	{
		int bit_1 = (idx_1 >= 0) ? item_1[idx_1] - '0' : 0;
		int bit_2 = (idx_2 >= 0) ? item_2[idx_2] - '0' : 0;

		// add the numbers
		int sum = bit_1 + bit_2 + carry;
		result[idx_end] = (sum % 2) + '0'; // store current bit
		carry = sum / 2; // calculate new carry val
		idx_1--;
		idx_2--;
		idx_end--;
	}

	// adjust result if leading carry
	if (idx_end == -1)
	{
		// means leading carry
		return result;
	}
	else
	{
		// no leading carry
		return result + idx_end + 1; // return pointer to actual start
	}
}