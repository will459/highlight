#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utilities.h"
#include "highlight.h"
char b_colour_change = 0;

int getLine(char *buf, size_t size) {
    if(fgets(buf, size, stdin) == NULL) {
        return 1;
    }
    return 0;
}

void colour_select(char *clr) {
	b_colour_change = 1; //colour was changed
    if(strcmp(clr, "RED") == 0) {
        colour = RED;
    }
    else if(strcmp(clr, "GRN") == 0) {
        colour = GRN;
    }
    else if(strcmp(clr, "YEL") == 0) {
        colour = YEL;
    }
    else if(strcmp(clr, "BLU") == 0) {
        colour = BLU;
    }
    else if(strcmp(clr, "MAG") == 0) {
        colour = MAG;
    }
    else if(strcmp(clr, "CYN") == 0) {
        colour = CYN;
    }
    else if(strcmp(clr, "WHT") == 0) {
        colour = WHT;
	}
    else {
        fprintf(stderr, "Error: Invalid colour. Highlighting will default to red.\n\n");
        b_colour_change = 0; //user attempted to change colour but it could not
    }
}
void bg_colour_select(char *clr) {
    if (b_colour_change == 0) { //if user did not change text colour, it does not default to red
        colour = "";
    }
	if(strcmp(clr, "RED") == 0) {
		bg_colour = B_RED;
    }
    else if(strcmp(clr, "GRN") == 0) {
        bg_colour = B_GRN;
    }
    else if(strcmp(clr, "YEL") == 0) {
        bg_colour = B_YEL;
    }
    else if(strcmp(clr, "BLU") == 0) {
        bg_colour = B_BLU;
    }
    else if(strcmp(clr, "MAG") == 0) {
        bg_colour = B_MAG;
    }
    else if(strcmp(clr, "CYN") == 0) {
        bg_colour = B_CYN;
    }
    else if(strcmp(clr, "WHTL") == 0) {
        bg_colour = B_YEL;
    }
    else {
		fprintf(stderr, "Error: Invalid colour. No background highlighting will be performed.\n\n");
    }
}

