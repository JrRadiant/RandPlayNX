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
        printf("Your game of the day today is # %d, \n \n", num);

        // Write out the full skipped strings:
        int skippedstr = num / 6;
        printf("	right after a %d skipped lines, \n \n", skippedstr);  

        // Write out the additional game number on the next string:
        int addrow = num - skippedstr * 6;
        printf("		plus %d in the next row! \n \n \n \n So, have a good luck and a great fun with it. <3 \n \n", addrow);
    } 
} 

void printUI()
{
    // Print the user interface:
    printf("Please press 'A' button to choose a random game, or + to exit gracefully.\n");
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
