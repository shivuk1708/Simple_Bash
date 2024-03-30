#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>


#define	MAX_SIZE_BUFF	1500            //Max Buffer size
#define	MAX_SIZE_CMD	1000            //Max command line length
#define	MAX_SIZE_ARG	100             //Maximum arguments

char command[MAX_SIZE_BUFF];			// Bash command 
char *argv[MAX_SIZE_ARG];			    // an array for command and arguments
pid_t pid;								// global variable for the child process ID
unsigned int argc;						// argument count / index  value for argv command line arguments for new process

extern void get_command(void);		    // get commands from $ bash
extern void parse_command(void);	    // parse the command string to the bash command line
extern void launch_bash(void);          // to start the $ bash
extern void signal_handler(void); 		// Signal handler to register SIGNAL and handle function						
extern void handle(int sig);			// handle funtion to hanle individual signals.
extern int remove_trailing_space(void); // remove trailing space
#endif