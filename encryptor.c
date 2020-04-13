#include <stdio.h>
#include <cs50.h>

char encrypt_char(char letter, string key);
int contains_all_letters(string key);

int main(int argc, string argv[]) {
	//printf("Number of options passed by user: %i\n", argc - 1);
	if (argc != 2) {
		printf("Invalid number of arguments, only one argument for cipher key will be accepted\n");
		return 1;
	}
	string key = argv[1];
	int key_length = 0;
	for (int i = 0; key[i] != '\0'; i++ ) {
		if (key[i] >= 'A' && key[i] <= 'Z' || key[i] >= 'a' && key[i] <= 'z') {
			key_length++;
		}
		else {
			printf("Key must only contain alphabetical characters\n");
			return 1;
		}
		
	}
	//printf("Number of characters passed in: %i\n", key_length);
	if (key_length != 26) {
		printf("Key must contain 26 characters.\n");
		return 1;
	}
	string plaintext = get_string("plaintext:");
	for (int i = 0; plaintext[i] != '\0'; i++) {
		char current_character = encrypt_char(plaintext[i],key);
		printf("%c",current_character);
	}
	int all_letters = contains_all_letters(key);
	printf("Your key contains all letters: %i\n", all_letters);
}

char encrypt_char(char character, string key) {
	int ascii_index = character;
	int array_index;
	if (ascii_index <= 90 && ascii_index >= 65) {
		array_index = ascii_index - 65;
		//printf("Array index: %i\n", array_index);
		//printf("Array element: %c\n", key[array_index]);
		return key[array_index];
	}
	else if (ascii_index <= 122 && ascii_index >= 97) {
		array_index = ascii_index - 97;
		//printf("Array index: %i\n",return encrypted_chari array_index);
		//printf("Array element: %c\n", key[array_index]);
		return key[array_index];
	} 
	else {
		return character;
	}	
}

int contains_all_letters(string key) {
	int bool_array[26];
	for (int i = 0; key[i] != '\0'; i++) {
		if (key[i] <= 'Z' && key[i] >= 'A') {
			bool_array[(int) key[i] - 65] = 1;
		} 
		else if (key[i] <= 'z' && key[i] >= 'a'){
	 		bool_array[ (int) key[i] - 97 ] = 1;
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("Array element %i: %i\n", i+1, bool_array[i]);
		if ( bool_array[i] != 1 ){
			return 1;
		}
	}
	return 0;
}
