#include <stdio.h>
#include <string.h>

char letter[7];

char letters[] = {
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    ',', '.', ' '
};

char* code[] = {
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--",
    "--..", ".----", "..---", "...--", "....-", ".....", "-....",
    "--...", "---..", "----.", "-----", ".-.-.-", "--..--", ""
};

int
main(int argc, char** argv) {
	if (argc != 3) {
		puts("Usage: ./<exec> < -d | -e > <message>");
		return 1;
	}
	if (!strcmp(argv[1], "-d") && 
		(argv[2][0] != '.' && 
		argv[2][0] != '-')) {
		puts("Bad input.");
		return 1;
	}
	if (!strcmp(argv[1], "-e") && 
		(argv[2][0] == '.' || 
		argv[2][0] == '-')) {
		puts("Bad input.");
		return 1;
	}
    return 0;
}