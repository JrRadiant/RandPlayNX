#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <switch.h>

// Custom keyboard headers, thanks to thomleg50!
#include "keyboard.h"

// Also include time.h for rand() seeding
#include <time.h> 

// Initialize calc vars:
int result;
float resultF;
long int first;
char		*swkdbout = 0;

// initialize printRandoms function and printing end results:
void printRandoms() 
{ 
    int i; 
    for (i = 0; i < 1; i++) { 
        int num = (rand() % 
           (result - 1 + 1)) + 1; 

        // Write out the number of the game:
        printf("Your Game of the Day today is # %d, \n \n", num);

        // Write out the full skipped strings:
        int skippedstr = num / 6;
        printf("	right after a");
		printf("\033[1;35m"); //Set the text to the color bold-cyan
		printf(" %d ", skippedstr);  
		printf("\033[0m"); //Resets the text to default color.
		printf("skipped lines, \n \n");  

        // Write out the additional game number on the next string:
        int addrow = num - skippedstr * 6;
        printf("		plus");
		printf("\033[1;33m"); //Set the text to the color bold-yellow
        printf(" %d ", addrow);
		printf("\033[0m"); 
        printf("in the next row. \n \n \n \n ");
		printf("\033[1;32m");  //Set the text to the color bold-green
        printf("Good luck and have a great fun!.. <3 \n \n");
		printf("\033[0m"); 
    } 
} 

void printUI()
{
    // Print the welcome greetings:
    printf("\n Please press 'A' button to choose a");
	printf("\033[1;34m"); //Set the text to the color bold-blue
	printf(" random game");
	printf("\033[0m"); 
    printf(", or + to exit gracefully.\n");
}

int main(int argc, char* argv[])
{
	consoleInit(NULL);
	userAppInit();
    srand(time(0));

	printUI();

	while (appletMainLoop()){
	  
		hidScanInput();

		u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
			
		if(kDown & KEY_A)
		{
			swkdbout = popKeyboardf("So, how many games do you have installed?", 128);
			first = atol(swkdbout);
			result = first;
			consoleClear();
			printRandoms();
		}

        if (kDown & KEY_PLUS)
            break; // break with + key in order to return to hbmenu
        if (kDown & KEY_B)
            break; // break with B key in order to return to hbmenu

		if (kDown & KEY_MINUS)
		{
			consoleClear();
			first = 0;
			printUI();
		}

		consoleUpdate(NULL);
	}

	consoleExit(NULL);
	return 0;
}
