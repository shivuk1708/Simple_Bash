#include "shell.h"

/*
*
* signal_handler () Handled the SIGCHLD with other signal from key board like CTR^C, SOTP and HANGUP
*
*/
void signal_handler( void )
{
	signal(SIGCHLD, handle);
	signal(SIGINT, handle);
	signal(SIGSTOP, handle);
	signal(SIGHUP, handle);
}

/*
*
* handle() Printe the Child process signal status from bash
*
*
*/
void handle(int sig){
    switch(sig)
    {
        case 1: 
        {
            printf("SIGHUP Received and handled process not terminates\n");
            break;
        }
        case 2: 
        {
            printf("SIGINT Received and handled process not terminates\n");
            break;
        }
        case 17: 
        {
            printf("SIGSTOP Received and handled process not terminates\n");
            break;
        }        
        case 20: 
        {
            // to trach child execution please uncomment beloow trace statement
            //fprintf(stdout, "Command completed.\n");
            break;
        }
    }
    
}