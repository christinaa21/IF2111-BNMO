#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

int main() {
	char* file = "file.txt";
    /* Tes Mesin Karakter */
    START(file);
    while (!IsEOP()) {
        printf("GetCC: %c\n", GetCC());
        ADV();
    }
    STARTINPUT();
    while (currentChar != '\n') {
        printf("%c\n", GetCC());
        ADV();
    }
    printf("---------------------------------\n");
    /* Tes Mesin Kata */
	STARTWORD(file);
	char* kata;
	printf("WordLength: %d\n", currentWord.Length);
	kata = WordToString(currentWord);
	printf("%s\n", kata);
	int kata_int = WordToInt(currentWord);
	printf("%d\n", kata_int);
	while (!IsEOP()) {
		ADVWORD();
		printf("WordLength: %d\n", currentWord.Length);
		kata = WordToString(currentWord);
		printf("%s\n", kata);
	}
	STARTINPUTKATA();
	printf("IsEqual:%d\n", IsEqual(currentWord, kata));
	printf("WordLength: %d\n", currentWord.Length);
	kata = WordToString(currentWord);
	printf("%s\n", kata);
	printf("IsEqual:%d\n", IsEqual(currentWord, kata));
	Word take2 = takeword(currentWord, 2);
	printf("WordLength: %d\n", take2.Length);
	kata = WordToString(take2);
	printf("%s\n", kata);
    return 0;
}