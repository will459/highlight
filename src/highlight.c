#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <unistd.h>

#include "highlight.h"
#include "utilities.h"

char *colour = RED;

int parse_args(int argc, char **argv){
    int c;
    while ((c = getopt(argc, argv, "c:")) != -1) {
        switch(c) {
            case 'c':
                colour_select(optarg);
        }
    }
    return 0;
}

int main(int argc, char **argv) {

    if(argc < 2) {
        fprintf(stderr, "Usage: highlight PATTERN [FILE] [OPTION]...\n");
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
        ret = regexec(&regex, buf, MAX_MATCHES, pmatch, 0);
        if(!ret) {
            char *temp = calloc(MAX_LEN, sizeof(char));
            strncpy(temp, buf, pmatch->rm_so);
            strcat(temp, colour);
            strncat(temp, buf+pmatch->rm_so, pmatch->rm_eo - pmatch->rm_so);
            strcat(temp, RESET);
            strcat(temp, buf+pmatch->rm_eo);
            printf(temp);
            free(temp);
        }
        else {
            printf(buf);
        }
        free(pmatch);
    }
    free(buf);
}
