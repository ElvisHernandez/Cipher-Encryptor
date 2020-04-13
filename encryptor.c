#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[]) {
	printf("Number of options passed by user: %i\n", argc - 1);
	if (argc != 2) {
		printf("Usage: ./substitution key\n");
		return 1;
	}
	string key = argv[1];
	int key_length = 0;
	for (int i = 0; key[i] != '\0'; i++ ) {
		key_length++;
	}
	printf("Number of characters passed in: %i\n", key_length);
	if (key_length != 26) {
		printf("Key must contain 26 characters.\n");
		return 1;
	}
}

