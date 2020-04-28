// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Also include time.h for rand() seeding
#include <time.h> 

// Include the main libnx system header, for Switch development
#include <switch.h>

// initialize printRandoms
void printRandoms(int lower, int upper, int count) 
{ 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % 
           (upper - lower + 1)) + lower; 
        printf("%d ", num); 
    } 
} 

// Main program entrypoint
int main(int argc, char* argv[])
{
    consoleInit(NULL);

    // Other initialization goes here. Print the user interface:
    printf("Please press 'A' button to play a random game, or + to exit gracefully.\n");

    int lower = 1, upper = 128, count = 1; 
    srand(time(0)); 

    // Main loop
    while (appletMainLoop())
    {
        // Scan all the inputs. This should be done once for each frame
        hidScanInput();

        // hidKeysDown returns information about which buttons have been
        // just pressed in this frame compared to the previous one
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if (kDown & KEY_PLUS)
            break; // break in order to return to hbmenu

        // The main code goes here
        if (kDown & KEY_A)
        printRandoms(lower, upper, count); 

        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}
