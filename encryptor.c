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
	if (contains_all_letters(key) == 1) {
		printf("Every letter must be present at least once.\n");
		return 1;
	}
	string plaintext = get_string("plaintext: ");
	printf("ciphertext: ");
	for (int i = 0; plaintext[i] != '\0'; i++) {
		char current_character = encrypt_char(plaintext[i],key);
		printf("%c",current_character);
	}
	printf("\n");
}

char encrypt_char(char character, string key) {
	int ascii_index = character;
	int array_index;
	if (ascii_index <= 90 && ascii_index >= 65) {
		array_index = ascii_index - 65;
		//printf("Array index: %i ", array_index);
		//printf("Array element: %c ", key[array_index]);	
		if (key[array_index] <= 'Z' && key[array_index] >= 'A') {
			return key[array_index];
		} else {
			int case_insensitive_index = (int) key[array_index] - 32;
			//printf("This is the case insensitive character: %i\n", case_insensitive_index);
			return (char) case_insensitive_index;

		}
	}
	else if (ascii_index <= 122 && ascii_index >= 97) {
		array_index = ascii_index - 97;
		//printf("Array index: %i ", array_index);
		//printf("Array element: %c ", key[array_index]);
		if (key[array_index] <= 'z' && key[array_index] >= 'a'){
			return key[array_index];
		} else {
			int case_insensitive_index = (int) key[array_index] + 32;
			//printf("This is the case insensitive character: %i\n", case_insensitive_index);
			return (char) case_insensitive_index;
		}
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
		//printf("Array element %i: %i\n", i+1, bool_array[i]);
		if ( bool_array[i] != 1 ){
			return 1;
		}
	}
	return 0;
}
