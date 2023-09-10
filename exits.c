#include "shell.h"

/**
 * _strncpy - copies a portion of a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the maximum number of characters to be copied
 * Return: the resulting string in the destination buffer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - concatenates two strings with a maximum byte limit
 * @dest: the first string
 * @src: the second string
 * @n: the maximum number of bytes to be used from src
 * Return: a pointer to the concatenated string in dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr - locates the first occurrence of a character in a string
 * @s: the string to be searched
 * @c: the character to find
 * Return: a pointer to the first occurrence of 'c' in 's' or NULL if not found
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}