//
//  messages.c
//  c-ops-checker
//
//  Created by g t2 on 1/24/26.
//

#include "messages.h"
#include <stdio.h>  

static const char* messages[] = {
    "Enter 'q' to quit.\nEnter 'h' for Help.\nOtherwise, enter a width & height as decimal numbers, like the prompt asks.\n",
    "Value must be a finite number.\n\nEnter minutes:\n",
    "Value is out of allowed range.\n\nEnter minutes: \n"
};

const char* get_error_msg(ErrorMsgs code) {
    size_t num_msgs = sizeof(messages) / sizeof(messages[0]);
    return (code >= 0 && code < num_msgs) ? messages[code] : "Unknown error";
}
