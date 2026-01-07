#include "shell.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/* TEMP */
int is_built_in(char *str)
{
	return (0);
}

int pre_exec(char **args)
{
	int fd;
	struct stat sb;
	char *new_bin_path;

	char bin_path[6] = "/bin/";
	new_bin_path = str_concat(bin_path, args[0]);
	printf("%s\n", new_bin_path);

	if (is_built_in(args[0]))
	{
		/* Call built-in */
	}
	else if (stat(new_bin_path, &sb) != -1)
	{
		args[0] = new_bin_path;
		exec_args(args);
	}
	else
	{
		/* Scan all dirs ENV PATH */
	}

	free(new_bin_path);
}
