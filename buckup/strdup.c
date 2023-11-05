#include "shell.h"

char* my_strdup(const char* src) 
{
	int i;
    if (src == NULL) 
    {
        return (NULL);
    }

    size_t len = strlen(src) + 1; // account for the null terminator
    char* dest = (char*) malloc(len * sizeof(char));

    if (dest == NULL) {
        return NULL;
    }
	for(i = 0; i < (len - 1); i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
    return (dest);
}
