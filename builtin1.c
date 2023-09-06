#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _myhistory - Displays the history list, one command per line, preceded
 *              by line numbers, starting at 0.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
    print_list(info->history);
    return 0;
}

/**
 * unset_alias - Unsets an alias.
 * @info: Parameter struct.
 * @str: The alias string.
 * Return: Always 0 on success, 1 on error.
 */
int unset_alias(info_t *info, const char *str)
{
    char *equal_sign = strchr(str, '=');
    if (equal_sign)
    {
        char alias_name[MAX_ALIAS_LENGTH];
        strncpy(alias_name, str, equal_sign - str);
        alias_name[equal_sign - str] = '\0';
        if (delete_node(&(info->alias), alias_name) == 0)
            return 0;
    }
    return 1;
}

/**
 * set_alias - Sets an alias.
 * @info: Parameter struct.
 * @str: The alias string.
 * Return: Always 0 on success, 1 on error.
 */
int set_alias(info_t *info, const char *str)
{
    char *equal_sign = strchr(str, '=');
    if (equal_sign)
    {
        char alias_name[MAX_ALIAS_LENGTH];
        strncpy(alias_name, str, equal_sign - str);
        alias_name[equal_sign - str] = '\0';
        if (unset_alias(info, alias_name) == 0)
        {
            if (add_node(&(info->alias), str) == 0)
                return 0;
        }
    }
    return 1;
}

/**
 * print_alias - Prints an alias string.
 * @node: The alias node.
 * Return: Always 0 on success, 1 on error.
 */
int print_alias(list_t *node)
{
    if (node)
    {
        printf("%s\n", node->str);
        return 0;
    }
    return 1;
}

/**
 * _myalias - Mimics the alias built-in (man alias).
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int _myalias(info_t *info)
{
    if (info->argc == 1)
    {
        print_list(info->alias);
    }
    else
    {
        for (int i = 1; info->argv[i]; i++)
        {
            if (strchr(info->argv[i], '='))
            {
                if (set_alias(info, info->argv[i]) != 0)
                {
                    fprintf(stderr, "Error setting alias: %s\n", info->argv[i]);
                }
            }
            else
            {
                if (print_alias(get_node(info->alias, info->argv[i])) != 0)
                {
                    fprintf(stderr, "Alias not found: %s\n", info->argv[i]);
                }
            }
        }
    }
    return 0;
}
