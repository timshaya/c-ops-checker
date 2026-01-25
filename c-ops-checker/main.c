//
//  main.c
//  c-ops-checker
//
//  Created by g t2 on 1/24/26.
//

#include <stdlib.h>
#include <stdio.h>

char buffer[256];
float _min =  0.0f;
float _days = 0.0f;
float _years = 0.0f;

float convertMinToDays(float m) {
   
    float _d = (m * 60) * 24;
    return _d;
}

float convertMinToYears(float m) {
    
    float _y = ((m * 60) * 24) * 356;
    return _y;
}

void showView(float m) {
    
    printf("You entered this many minutes: %.2f\n\n",_min);
    
    _days = convertMinToDays(_min);
    _years = convertMinToYears(_min);
    
    printf("Which is this many days: %.8f\n\nAnd this many years: %.8f\n\n", _days, _years);
}

int main(int argc, const char * argv[]) {
    
    printf("Enter a number of minutes:\n");

    while(fgets(buffer, sizeof buffer, stdin)) {
        
        //quit the app
        if(buffer[0] == 'q') break;
        
        showView(_min);
        printf("Enter minutes again or hit 'q' to quit:\n");
    }
    
    return EXIT_SUCCESS;
}
