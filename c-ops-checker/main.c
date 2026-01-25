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

char buffer[256];
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
    
    printf("You entered this many minutes: %f\n\n", m);
    
    _days = convertMinToDays(m);
    _years = convertMinToYears(m);
    
    printf("Which is this many days: %f\n\nAnd this many years: %f\n\n", _days, _years);
}

int main(int argc, const char * argv[]) {
    
    printf("Enter a number of minutes:\n");

    while(fgets(buffer, sizeof buffer, stdin)) {
        
        //quit the app
        if(buffer[0] == 'q') break;
        
        //Enter 'h' for help
        if(buffer[0] == 'h') {
            printf("");
            continue;
        }

        // Reject NaN or infinities. e.g. Enter "10e545458457346 34" to get "inf"
        if (!isfinite(strtod(buffer, &endptr)) || endptr == buffer) {
            printf("%s", get_error_msg(MSG_ERROR_MUST_BE_FINITE_NUM));
            continue;
        }
        
        //fix issue "Using floating point absolute value function 'fabsf' when argument is of integer type /
        //Format string is not a string literal (potentially insecure)"
        // Clamp using abs() for char (integer type)
        if (abs((int)buffer[0]) > 1000000) {  // 1e6 as int
            printf("%s", get_error_msg(MSG_ERROR_VALUES_OUT_OF_RANGE));  // Safe format
            continue;
        }
        
        //assigns value of buffer[] to address of _min while casting to float
        if (sscanf(buffer, "%f", &_min) != 1) {
            printf("Invalid input\n");
            continue;
        }

        //if sending buffer[0]) directly, instead of _min after "&_min" above,
        //  it'll read in the wrong data type from buffer[0] and convert it to the first character's hext value
        showView(_min);
        
        printf("Enter minutes again or hit 'q' to quit:\n");
    }
    
    return EXIT_SUCCESS;
}
