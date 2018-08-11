#ifndef __UTILITIES_H__
#define __UTILITIES_H__

int getLine(char *buf, size_t size);

void colour_select(char *clr);

void bg_colour_select(char *clr);

extern char *colour, *bg_colour;

#endif
