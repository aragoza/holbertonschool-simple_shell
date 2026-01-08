## ***holbertonschool-simple_shell 🐚***

## Description

```c
A shell is a programm that interprets input, and sends them to the operating system for execution. 
This program also checks that the inputs are valid.
```
## Logic of the simple shell

![alt text](Logic_of_shell.png)

### Dependencies

* ISO C89
* ANSI C
* **librairy** : unistd.h / stdlib.h / stdio.h / string.h / sys/wait.h / sys/types.h

# example of shell:
```c
 $ Hello World
```

```c
$ ls
AUTHORS.md      README.md       check_then_exec_builtin.c  find_bin.c   flowchart_all_functions.png  hsh          shell.c  tokenize.c
Logic_of_shell.png  _get_env.c  execute_command.c          find_path.c  free_iterative.c             read_line.c  shell.h
```


# Flow chart

![alt text](flowchart_all_functions.png)

## List of functions and system calls.

* ```_exit``` (man 3 exit)
* ```fork``` (man 2 fork)
* ```free``` (man 3 free)
* ```getline``` (man 3 getline)
* ```malloc``` (man 3 malloc)
* ```perror``` (man 3 perror)
* ```strtok``` (man 3 strtok)
* ```waitpid``` (man 2 waitpid)

## Help

Any advise for common problems or issues.
```
if the stream input is more than 1024 byte the shell will not work
```

```c
$ man shell
```

## Authors

Contributors names and contact info

name : Elliot CHARLET / Ilan DEVERSENNE
e-mail : _charlet.elliot@gmail.com_ _ilan.deversenne@holbertonstudents.com_

## License

This project is licensed under the [ELLIOT CHARLET and ILAN DEVERSENNE] License