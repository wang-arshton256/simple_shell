#include "main.h"


/**
 * _getenv - Gets the given environment variable from the set of
 * environment variables.
 *
 * @name: Pointer to a character value, which represents the
 * name of the enviroment variable to be searched for.
 *
 * Return: Address of the value corresponding to the key envrionment variable.
 *	   NULL if environment variable not found.
 */

char *_getenv(char *name)
{
	int i, var_len = _strlen(name) + 1;
	char *token, *env_var = malloc(sizeof(char) * var_len);

	if (name == NULL)
		return (NULL);

	/**
	 * Typecasting the environment variable.
	 * TODO: allocate memory to env_var instead of typecasting.
	 */
	_strcpy(env_var, name);

	for (i = 0; environ[i] != NULL; i++)
	{
		token = strtok(environ[i], "=");

		if (_strcmp(token, env_var) == 0)
		{
			token = strtok(NULL, "=");
			return (&environ[i][var_len]);
		}
	}
	return (NULL);
}
