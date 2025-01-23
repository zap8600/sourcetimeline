#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

char extension[5];
char configname[13] = "CONFIG.";
char SaveName[13] = "SAVEGAM?.";
char audioname[13] = "AUDIO.";
char demoname[13] = "DEMO?.";
char helpfilename[13] = "HELPART.";

void CheckForEpisodes() {
    // TODO: Support the Japanese and Spear versions
    
    // Find any files with the extension .WL1 and quit with error if none are found
    // TODO: Make this code better
    extension[0] = '\0';
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if(d) {
        while((dir = readdir(d)) != NULL) {
            char *tmp = strrchr(dir->d_name, ".");
            if(!strcmp(tmp, ".WL1")) {
                strcpy(extension, "WL1");
                break;
            }
        }
        closedir(d);
    } else {
        fprintf(stderr, "Couldn't open current directory!\n");
        exit(1);
    }
    if(!strcmp(extension, "\0")) {
        fprintf(stderr, "NO WOLFENSTEIN 3-D DATA FILES to be found!\n");
        exit(1);
    }

    strcat(configname, extension);
    strcat(SaveName, extension);
    // TODO: Add preprocessor flag for using a page file for platforms that need it
    strcat(audioname, extension);
    strcat(demoname, extension);
    strcat(helpfilename, extension); // TODO: Figure out what the GOODTIMES define is in the source code and why it affects this
}

void InitGame() {
    // Gets some paramater that sets a bool called virtual reality to true or false
    // Sets up a memory manager, shouldn't be needed
    // Checks for a video card
    // Sets up an input manager
    // Sets up a page manager, might be needed for platforms requiring a swap file
    // Sets up a sound manager, will be optional
    // Opens all files and loads in headers
    // Sets up user manager
}

int main() {
    CheckForEpisodes();
    // If I had to guess, Patch386 is a patch for the i386 processors.
    InitGame();
}