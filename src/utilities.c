#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utilities.h"
#include "highlight.h"

int getLine(char *buf, size_t size) {
    if(fgets(buf, size, stdin) == NULL) {
        return 1;
    }
    return 0;
}

void colour_select(char *clr) {
    if(strcmp(clr, "RED") == 0) {
        colour = RED;
    }
    else if(strcmp(clr, "GREEN") == 0) {
        colour = GRN;
    }
    else if(strcmp(clr, "YELLOW") == 0) {
        colour = YEL;
    }
    else if(strcmp(clr, "BLUE") == 0) {
        colour = BLU;
    }
    else if(strcmp(clr, "MAGENTA") == 0) {
        colour = MAG;
    }
    else if(strcmp(clr, "CYAN") == 0) {
        colour = CYN;
    }
    else if(strcmp(clr, "WHITE") == 0) {
        colour = WHT;
    }
}