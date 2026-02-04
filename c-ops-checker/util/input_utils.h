//
//  string_utils.h
//  c-ops-checker
//
//  Created by g t2 on 2/1/26.
//

#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

char *trim_whitespace(char *str);
int is_simple_float(const char *s);
int sanitize_and_parse_float(const char *s, float *out, double min_allowed, double max_allowed);

#endif
