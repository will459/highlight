#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <unistd.h>

#include "highlight.h"
#include "utilities.h"

char *colour = RED;
char *bg_colour = "";

int parse_args(int argc, char **argv){
    int c;
    while ((c = getopt(argc, argv, "c:b:")) != -1) {
        switch(c) {
            case 'c':
                colour_select(optarg);
                break;
            case 'b':
                bg_colour_select(optarg);
                break;
            default:
                fprintf(stderr, "Usage: hl PATTERN [OPTION]...\n"); /*TODO: Make error printing handled by a function*/
        }
    }
    return 0;
}

int main(int argc, char **argv) {

    if(argc < 2) {
        fprintf(stderr, "Usage: hl PATTERN [OPTION]...\n");
        return 1;
    }

    if(argc > 2) {
        parse_args(argc - 1, argv + 1);
    }

    char *buf = calloc(MAX_LEN, sizeof(char));
    regex_t regex;
    int cflags = REG_NEWLINE;

    int ret = regcomp(&regex, argv[1], cflags);
    if(ret) {
        fprintf(stderr, "Invalid Regular Expression.\n");
        return 1;
    }

    while(getLine(buf, MAX_LEN) == 0) {
        regmatch_t *pmatch = malloc(MAX_MATCHES * sizeof(regmatch_t));
        int cursor = 0;
        while(!(ret = regexec(&regex, buf + cursor, MAX_MATCHES, pmatch, 0)))
        {
            char *temp = calloc(MAX_LEN, sizeof(char));
            strncpy(temp, buf + cursor, pmatch->rm_so);
            strcat(temp, colour);
            strcat(temp, bg_colour);
            strncat(temp, buf + cursor + pmatch->rm_so, pmatch->rm_eo - pmatch->rm_so);
            strcat(temp, RESET);
            printf(temp);
            free(temp);
            cursor += pmatch->rm_eo;
        }
        printf(buf + cursor);
        free(pmatch);
    }
    free(buf);
    regfree(&regex);
}
