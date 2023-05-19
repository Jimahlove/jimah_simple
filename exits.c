#include "shell.h"

/**
 **_strncpy -  this copies a string
 *@dest: destination string to be copied to
 *@src:  source string
 *@n: amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j, t;
	char *s = dest;

	j = 0;
	while (src[j] != '\0' && j < n - 1)
	{
		dest[j] = src[j];
		j++;
	}
	if (j < n)
	{
		t = j;
		while (t < n)
		{
			dest[t] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - conc. two strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes to be maximally used
 *Return: the conc. string
 */
char *_strncat(char *dest, char *src, int n)
{
	int j, t;
	char *s = dest;

	j = 0;
	t = 0;
	while (dest[j] != '\0')
		j++;
	while (src[t] != '\0' && t < n)
	{
		dest[j] = src[t];
		j++;
		t++;
	}
	if (t < n)
		dest[j] = '\0';
	return (s);
}

/**
 **_strchr -  this locates a character in a string
 *@s: string to be parsed
 *@c: character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

