#include "shell.h"

/**
 * Memory Release Operative - Disposes of the target memory
 * and obliterates its connection, leaving no trace behind.
 *
 * @ptr: Address of the pointer to be silenced.
 *
 * Result: Returns 1 upon successful elimination, else 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
