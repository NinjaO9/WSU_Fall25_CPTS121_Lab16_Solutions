#include "Lab9.h"

void runTask1()
{
	char str[18] = { 'C', 'p', 't', 'S', ' ', '1', '2', '1', ' ', 'i', 's', ' ', 'c', 'o', 'o', 'l', '!' };
	// String reversal using array notation
	char* str2 = string_reverse(str);
	printf("Reversed: %s\n", str2);


	// String Reversal using pointers
	str2 = string_reverse_pointer(str);
	printf("Reversed again (ptr): %s\n", str2);
}

char* string_reverse(char* str)
{
	int length = 0;
	for (int i = 0; str[i] != '\0'; i++)
		length++;
	length -= 1; // Do not reverse null character
	char temp = '\0';
	for (int i = 0; i < length; i++)
	{
		temp = str[length];
		str[length] = str[i];
		str[i] = temp;
		length--;
	}
	return str;
}

char* string_reverse_pointer(char* str)
{
	int length = 0;
	for (int i = 0; *(str + i) != '\0'; i++)
		length++;
	length -= 1; // Do not reverse null character
	char temp = '\0';
	for (int i = 0; i < length; i++)
	{
		temp = *(str+length);
		*(str +length) = *(str+i);
		*(str+i) = temp;
		length--;
	}
	return str;
}

void runTask2()
{
	char str[20] = {'G', 'o', 'o', 'b', '\0'};
	char str2[20] = { ' ', 'H', 'o', 'o', 'b', '\0' };
	char dest[20] = { '\0' };
	printf("Copied: %s\n", my_strcpy(dest, str));
	printf("Concatinated: %s\n", my_strcat(str, str2));
	printf("%s &%s: %d\n",str, str2, my_strcmp(str, str2));
	printf("%s len: %d\n",str, my_strlen(str));
}

char* my_strcpy(char* destination, const char* source)
{
	int length = my_strlen(source);
	for (int i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[length] = '\0';
	return destination;

}

char* my_strcat(char* destination, const char* source)
{
	int s_length = my_strlen(source);
	int d_length = my_strlen(destination);

	for (int i = 0; i < s_length; i++)
	{
		destination[d_length + i] = source[i];
	}
	return destination;

}

int my_strcmp(const char* s1, const char* s2)
{
	char temp1 = *s1, temp2 = *s2;
	int length = my_strlen(s1), length2 = my_strlen(s2);

	for(int i = 0; i < length2 && i < length; i++)
	{
		if (temp1 < temp2)
		{
			return 1;
		}
		else if (temp1 > temp2)
		{
			return -1;
		}
		temp1 = *(s1 + i);
		temp2 = *(s2 + i);
	}
	return 0;



}

int my_strlen(const char* s)
{
	int length = 0;
	for (int i = 0; *(s + i) != '\0'; i++)
		length++;
	return length;
}

void runExtraStuff()
{
}
