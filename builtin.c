#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _myexit - Exit the shell with a given exit status.
 * @info: Structure containing potential arguments.
 * Return: Always returns -2 or 1 if an error occurs.
 */
int _myexit(info_t *info)
{
    if (!info->argv[1])
    {
        info->err_num = -1;
        return -2; // No argument provided, exit with error.
    }

    int exit_status = _erratoi(info->argv[1]);
    if (exit_status == -1)
    {
        info->status = 2;
        print_error(info, "Illegal number: ");
        _eputs(info->argv[1]);
        _eputchar('\n');
        return 1; // Illegal exit status, exit with error.
    }

    info->err_num = exit_status;
    return -2; // Valid exit status provided.
}

/**
 * _mycd - Change the current directory of the process.
 * @info: Structure containing potential arguments.
 * Return: 0 on success, 1 on error.
 */
int _mycd(info_t *info)
{
    char buffer[1024];
    char *dir = NULL;
    int chdir_ret = 0;

    char *current_dir = getcwd(buffer, 1024);
    if (!current_dir)
    {
        perror("getcwd");
        return 1;
    }

    if (!info->argv[1])
    {
        dir = _getenv(info, "HOME=");
        if (!dir)
            dir = _getenv(info, "PWD=");
    }
    else if (strcmp(info->argv[1], "-") == 0)
    {
        dir = _getenv(info, "OLDPWD=");
        if (!dir)
        {
            fprintf(stderr, "OLDPWD not set\n");
            return 1;
        }
        printf("%s\n", dir);
    }
    else
    {
        dir = info->argv[1];
    }

    if (chdir(dir) == -1)
    {
        perror("chdir");
        return 1;
    }

    _setenv(info, "OLDPWD", current_dir);
    _setenv(info, "PWD", getcwd(buffer, 1024));
    return 0;
}

/**
 * _myhelp - Display help information.
 * @info: Structure containing potential arguments.
 * Return: 0
 */
int _myhelp(info_t *info)
{
    (void)info; // Suppress unused parameter warning

    printf("Help call works. Function not yet implemented.\n");
    return 0;
}
