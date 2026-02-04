//
//  string_utils.c
//  c-ops-checker
//
//  Created by g t2 on 2/1/26.
//
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <fenv.h>
#include <errno.h>
#include "input_utils.h"


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

int sanitize_and_parse_float(const char *s, float *out, double min_allowed, double max_allowed) {
    if(s == NULL || out == NULL) return 0;
    
    /* faster textual sanity check */
    errno = 0;
    feclearexcept(FE_ALL_EXCEPT);
    
    char *local_end = NULL;
    /* parse as double to get best range detection, then cast to float */
    double dv = strtod(s, &local_end);
    
    /* require that strtod consumed something and ended at end */
    if(local_end == s) return 0;
    
    /* skip trainling whitespace then require end */
    while(*local_end && isspace((unsigned char)*local_end)) local_end++;
    if(*local_end != '\0') return 0;
    
    /* check errno range errors and isfinite */
    if(errno == ERANGE) return 0;
    if(!isfinite(dv)) return 0;
    
    /* check FP exceptions (just in case) */
    if(fetestexcept(FE_INVALID | FE_OVERFLOW | FE_UNDERFLOW)) return 0;
    
    /* enforce application specific bounds to prevent spikes */
    if(!isnan(min_allowed) && dv < min_allowed) return 0;
    if(!isnan(max_allowed) && dv > max_allowed) return 0;
    
    /* cast to float safely */
    *out = (float)dv;
    return 1;
}
