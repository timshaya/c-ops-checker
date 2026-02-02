//
//  string_utils.c
//  c-ops-checker
//
//  Created by g t2 on 2/1/26.
//
#include "string_utils.h"
#include <ctype.h>
#include <string.h>

char *trim_whitespace(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == '\0')
        return str;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';
    return str;
}
