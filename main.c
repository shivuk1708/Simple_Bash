#include "shell.h"

void display(void)
{
	printf("\n*********************************************\n");
	printf("**  This is simple Unix shell(bash)        **\n");
	printf("**  Plase read README.md for instructions  **\n");
	printf("*********************************************\n");
}

/*
*
* main() In this funtion Displayed info and called the signal handler function to
*        Handle the signals and invoked the shell.
*
*/
int main(){

	// Display intial information 
 	display();
    
	// Handle funtion signal from key board
	signal_handler();

	// start the $ bash shell
	launch_bash();

	return 0;
}
