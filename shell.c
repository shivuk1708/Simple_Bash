#include "shell.h"

/*
*
* Launch_bash() is an actual funtion which launch the bash and wait user command, 
*               once command is available which calles fork, upon creation successful child process
*               which calls the execvp() and replace the child process with the bew command
*
*/

void launch_bash(){

	//Run in while to interact wiht user
	while(1){

		// Read the command from user in $ bash
		get_command();
		
		// given command is empty or \n again read comand from new line $ bash
		if(!strcmp("", command)) 
			continue;

		if(!(remove_trailing_space()))
		{
			continue;
		}

		// if the command is exit exit from simple bash
        if(!strcmp("exit", command)) 
			exit(0);

		// Parse the input string itno command and its arguments
		parse_command();
	
		if (strcmp(argv[0], "cd\0") == 0) {
			int i = 1;
			char * str = (char *) malloc(MAX_SIZE_BUFF);
			memset(str, MAX_SIZE_BUFF, '\0');
			for(i = 1;i < argc; i++)
			{
        		strcat(str, argv[i]);
			}
 			if (chdir(str) != 0) {
            	perror("chdir");
        	}
			continue;
    	}

		// Check for the command limitaitons 
		if( argc >= MAX_SIZE_ARG)
		{
			printf("\n**** ERROR: command line contains more than 100 arguments ****\n");
			memset(command, MAX_SIZE_BUFF, '\0');
			strcpy(command, "");
			continue;
		}
		else{
			// do fork and create new address space for child process.
			pid = fork();
			if(-1 == pid){
				printf("failed to create a child\n");
			}
			else if(0 == pid){
				// Replace the new command with child address space
				int error_no =  execvp(argv[0], argv);
				if( error_no == -1){
				    fprintf(stderr, "error: command exited with code %d\n", error_no);
					exit(-1);
				}
			}else{
				// wait if new command not running in back ground using "&"
				int error_no  = 0;
				if(NULL == argv[argc]) 
					waitpid(pid, (void *) &error_no, 0);

				if( error_no != 0)
				{
			 	    fprintf(stderr, "error: %s failed with code %d\n",argv[0], error_no);
					kill(pid, SIGKILL);
				}
			}
		}
	}
}

