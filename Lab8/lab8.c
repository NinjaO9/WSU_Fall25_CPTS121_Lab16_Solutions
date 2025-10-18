#include "lab8.h"

void runTask1()
{
	int arr[SIZE] = {0};
	int input = 0, index = 0, size;
	FILE* infile = fopen("input1.txt", "r");

	// Keep iterating in loop util at EOF or when we are about to overflow array
	while (index < SIZE && fscanf(infile, " %d", &input) != EOF)
	{
		arr[index] = input;
		index++; // iterate through array
	}
	size = index; // Saved for printing
	index--; // Getting the largest index (which is size - 1)

	printf("Before Reversal:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	// Reverse array
	int count = 0, temp = 0;
	while (count < index)
	{
		temp = arr[index];
		arr[index] = arr[count];
		arr[count] = temp;
		++count;
		--index;
	}

	printf("After Reversal:\n");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

void runTask2()
{
	char var[15] = {'C', 'p', 't', 'S', ' ', '1', '2', '1', ' ','i', 's', ' ', 'f', 'u', 'n'};
	int size = 15;

	remove_whitespace(var, size);

	for (int i = 0; i < size; i++)
	{
		printf("%c", var[i]);
	}
}

int remove_whitespace(char* str, int size)
{
	int whitespace_counter = 0, nextvalid = 0;
	char temp = '\0';
	for (int i = 0; i < size; i++) // Iterate through char array
	{
		if (str[i] == ' ') // Whitespace found
		{
			whitespace_counter++; // increment
			nextvalid = i;
			findNextValid(str, &nextvalid, size); // Find the next space that does not contain whitespace

			// Swap indexes
			temp = str[nextvalid];
			str[i] = temp;
			str[nextvalid] = ' ';

			// Nothing left to replace, so break loop
			if (nextvalid + 1 >= size) {
				break;
			}
		}
	}
}

void findNextValid(char list[], int* index, int size) {
	*index += 1; // iterate by 1 to get the next character so that we do not try to swap the same char
	for (; *index < size; ++*index) {
		if (list[*index] != ' ') { // if we found a character that is not a whitespace, then we will swap that character
			break;
		}
	}
	if (*index == size) { // No more non-whitespace characters
		printf("Error! No Valid Space found!");
	}
}

void runTask3()
{
	srand(time(NULL));

	int nums[100] = { 0 };
	int rnums[20] = { 0 };

	for (int i = 0; i < 20; i++) // populate list with random numbers
	{
		rnums[i] = rand() % 100;
	}

	for (int i = 0; i < 20; i++) 
	{
		nums[rnums[i]]++;
	}

	for (int i = 0; i < 100; i++)
	{
		printf("Count of %d: %d\n\n", i + 1, nums[i]);
	}

}

void runTask4(void) {
	char word[8] = { 'c', 'o', 'm', 'p', 'u', 't', 'e', 'r' };
	int size = 8;
	char guessed[27] = { '*', '*','*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*' };
	char activeGuess = '\0';
	int correct = 0, round = 1, index = 0;
	printf("Hangman! \n");
	do {
		if (round > 6) {
			break;
		}
		printf("Enter a letter!\n");
		scanf(" %c", &activeGuess);
		if (isNotInList(activeGuess, guessed)) {
			if (!isNotInList(activeGuess, word)) {
				printf("%c is in the word!\n", activeGuess);
			}
			else {
				printf("Wrong! Guess again!\n");
				printf("(%d fails remaining)\n", 6 - round);
				++round;
			}
			guessed[index] = activeGuess;

		}
		else {
			printf("You've already guessed that!\n");
		}
		++index;
		printWordProgress(word, guessed, &correct, size);
	} while (!correct);
	if (!correct) {
		printf("You failed! The word was: ");
		for (int i = 0; i < size; i++)
		{
			printf("%c", word[i]);
		}
	}
}

int isNotInList(char activeGuess, char guessed[]) {
	int valid = 0;
	for (int i = 0; i < 27; ++i) {
		if (guessed[i] == activeGuess) {
			valid = 0;
			break;
		}
		valid = 1;
	}
	return valid;
}

void printWordProgress(char word[], char guessed[], int* correct, int size) {
	int letterfound = 0, wordcompletion = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 27; ++j) {
			if (word[i] == guessed[j]) {
				printf("%c", word[i]);
				letterfound = 1;
				wordcompletion += 1;
			}
		}
		if (!letterfound) {
			printf("_");
		}
		letterfound = 0;
	}
	printf("\n");
	if (wordcompletion == size) {
		*correct = 1;
		printf("Congratulations! You guessed the word!\n");
	}


}