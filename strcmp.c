#include "monty.h"

/**
 * compare_strings - Compare two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 * Return: an integer indicating whether s1 is less than, equal to, or greater than s2.
 *
 * Description: This function compares two strings character by character
 * until a difference is found or one of the strings reaches its null terminato
 */
int compare_strings(const char *s1, const char *s2)
{
	int result = 0;

	do
	{
		result = *s1 - *s2;

		if (*s1 == '\0' || *s2 == '\0')
			break;

		s1++;
		s2++;
	}
	while (result == 0);

	return (result);
}
