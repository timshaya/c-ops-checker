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

static const char* messagesUsr[] = {
    "Enter a number of minutes:\n",
    "You entered this many minutes:", //"You entered this many minutes: %f\n\n"
    "Which is this many days: ", //"Which is this many days: %f\n\nAnd this many years: %f\n\n"
    "And this many years: " //"Which is this many days: %f\n\nAnd this many years: %f\n\n"
};

const char* get_error_msg(ErrorMsgs code) {
    size_t num_msgs = sizeof(messages) / sizeof(messages[0]);
    return (code >= 0 && code < num_msgs) ? messages[code] : "Unknown error";
}

const char* get_usr_msg(UsrMsgs code) {
    size_t num_msgs = sizeof(messagesUsr) / sizeof(messagesUsr[0]);
    return (code >= 0 && code < num_msgs) ? messagesUsr[code] : "Unknown error";
}
