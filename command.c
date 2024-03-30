#include "shell.h"

/*
*
* get_command() Read the cinput form used in new simple bash and 
*				Parse it to a legit command
*
*/
void get_command(){

	printf("$ ");
	fgets(command, MAX_SIZE_BUFF, stdin);

	int length = strlen(command);

	if( length > MAX_SIZE_CMD )
	{
		printf("\n**** ERROR: command line is longer than 1000 characters ****\n");
		memset(command, MAX_SIZE_CMD, '\0');
		strcpy(command, "");
	}

	if ((length > 0) && (command[length - 1] == '\n'))
	{
        command[length- 1] = '\0';
	}
}

/*
*
* string_parse() this funtion is check for ' " ' present in the commandline or not if yes and which is valid then considering the first string as command and next arguments as string 
*
*/
int string_parse(void)
{
	if( NULL != strstr(command, "\""))
	{
		char *ptr;
		char * str = (char *) malloc(MAX_SIZE_BUFF);
		char * str1 = (char *) malloc(MAX_SIZE_BUFF);
		memcpy(str1, command, strlen(command));
		ptr = strtok(str1, " ");

		argv[argc++] = ptr;
		int i = strlen(ptr)+1;

		if( (i+1) > strlen(command))
		{
			argv[--argc] = NULL;
			return 0;
		}

		char * head = NULL;
		char * tail = NULL;
		head = strstr(command+i, "\"");
		tail = strstr(head+1, "\"");

		if(NULL == head || NULL == tail)
			return 0;

		memcpy(str, head, (tail-head)+1);
		argv[argc++] = str;
		int j = 1;
		while(tail[j] == ' ')
		{
			j++;
		}
		int k =0;
		for (k = 0; tail[j+k] != '\0'; k++) {
        	if (tail[j+k] == '\'') {
        	    char * str_2 = (char *) malloc(MAX_SIZE_BUFF);
				strcpy(str_2, &tail[j]);
				argv[argc++] = str_2;
       	     	return 1;
			}
			printf("%c", tail[j+k]);
    	}

		ptr = strtok(&tail[j], " ");
		while(ptr != NULL){
			argv[argc] = ptr;
			argc++;
			ptr = strtok(NULL, " ");
		}
		return 1;
	}
	return 0;
}

/*
*
* parse_command() to parse the user input to array for command & arguments for bash
*
*/

void parse_command(){
	char *ptr;
	argc = 0;

	if( string_parse())
	{
		//Trace for to check command contain string ' " '
		//printf("Command conatins string quote\n");
	}else{
   		// Iterate through tokens
		ptr = strtok(command, " ");
		while(ptr != NULL){
		argv[argc] = ptr;
			argc++;
			ptr = strtok(NULL, " ");
		}
	}

	// check for background running 
	if(!strcmp("&", argv[argc-1])){
	argv[argc-1] = NULL;
	argv[argc] = "&";
	}else{
	argv[argc] = NULL;
	}
}

int remove_trailing_space(void)
{	
	int i, x;
    for(i=x=0; command[i]; ++i)
    if(!isspace(command[i]) || (i > 0 && !isspace(command[i-1])))
        command[x++] = command[i];
    command[x] = '\0';	
	return strlen(command) ? 1 : 0;

}