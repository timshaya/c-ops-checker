//
//  main.c
//  c-ops-checker - skeleton app for exploring basic operations in C
//
//  Created by g t2 on 1/24/26.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "msg/messages.h"
#include "util/input_utils.h"

float _min =  0.0f;
float _days = 0.0f;
float _years = 0.0f;
char *endptr;

float convertMinToDays(float m) {
   
    float _d = m / 1440; //24 hours x 60 minutes per hour
    return _d;
}

float convertMinToYears(float m) {
    
    float _y = m / 525600; //365 days x 24 hrs x 60 min = 525,600
    return _y;
}

void showView(float m) {
    
    //safer than just using 'printf(get_usr_msg(MSG_YOU_ENTERED), m);'
    //  for "You entered this many minutes: %f\n\n"
    const char *msg1 = get_usr_msg(MSG_YOU_ENTERED); // should NOT contain %
    printf("%s %f\n", msg1, m);
    
    _days = convertMinToDays(m);
    _years = convertMinToYears(m);
    
    //safer than just using 'printf(get_usr_msg(MSG_DAYS_N_YEARS), _days, _years);'
    const char *msg2 = get_usr_msg(MSG_DAYS);
    const char *msg2_2 = get_usr_msg(MSG_YEARS);
    printf("%s %f\n%s %f\n\n", msg2, _days, msg2_2, _years);
}

int main(int argc, const char * argv[]) {
    
    //less accessible to attackers here than in its former global scope:
    char buffer[256];

    const double ALLOWED_MIN = -1e12;
    const double ALLOWED_MAX = 1e12; //1,901,285 years should suffice for now?
    
    //safer against format‑string vulnerabilityn than just 'printf(get_usr_msg(MSG_ENTER_NUM_MIN))'
    printf("%s", get_usr_msg(MSG_ENTER_NUM_MIN));

    while(fgets(buffer, sizeof buffer, stdin)) {
        
        trim_whitespace(buffer);
        
        //Enter 'q'  to quit the app
        if(buffer[0] == 'q' || buffer[1] == '\n' || buffer[0] == '\0') break;
        
        //Enter 'h' for help
        if(buffer[0] == 'h') {
            printf("Help placeholder text for now.\n\nEnter minutes again or hit 'q' to quit:\n");
            continue;
        }

        //Sanitize input to reduce risk of fuzzing
        if (!is_simple_float(buffer)) {
            printf("Invalid numeric format\n");
            continue;
        }
        
        //TODO: how to sanitize input against spiking?
        float parsed;
        if(!sanitize_and_parse_float(buffer, &parsed, ALLOWED_MIN, ALLOWED_MAX)) {
            printf("%s", get_error_msg(MSG_ERROR_SPIKING)); // "No spiking, please\n");
            continue;
        }
        
        // Reject NaN or infinities. e.g. Enter "10e545458457346 34" to get "inf"
        if (!isfinite(strtod(buffer, &endptr)) || endptr == buffer) {
            printf("%s", get_error_msg(MSG_ERROR_MUST_BE_FINITE_NUM));
            continue;
        }
        
        //assigns value of buffer[] to address of _min while casting to float
        if (sscanf(buffer, "%f", &_min) != 1) {
            printf("Invalid input\n");
            continue;
        }

        _min = parsed; 
        showView(_min);
        
        puts("Enter minutes again or hit 'q' to quit:\n");
    }
    
    return EXIT_SUCCESS;
}
