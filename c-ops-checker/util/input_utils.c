//
//  string_utils.c
//  c-ops-checker
//
//  Created by g t2 on 2/1/26.
//
#include "input_utils.h"
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

int is_simple_float(const char *s) {
    const unsigned char *p = (const unsigned char *)s;

    // Skip leading whitespace
    while (*p && isspace(*p)) p++;

    // Optional sign
    if (*p == '+' || *p == '-') p++;

    int digits = 0;
    while (isdigit(*p)) { digits++; p++; }

    int frac_digits = 0;
    if (*p == '.') {
        p++;
        while (isdigit(*p)) { frac_digits++; p++; }
    }

    if (digits == 0 && frac_digits == 0) return 0; // must have some digit

    // Skip trailing whitespace
    while (*p && isspace(*p)) p++;

    // Nothing else allowed
    return *p == '\0';
}
