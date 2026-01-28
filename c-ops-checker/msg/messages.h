//
//  messages.h
//  c-ops-checker
//
//  Created by g t2 on 1/24/26.
//

#ifndef MESSAGES_H
#define MESSAGES_H

typedef enum {
    MSG_HELP_MENU,
    MSG_ERROR_MUST_BE_FINITE_NUM,
    MSG_ERROR_VALUES_OUT_OF_RANGE
} ErrorMsgs;

typedef enum {
    MSG_ENTER_NUM_MIN, //"Enter a number of minutes:\n"
    MSG_YOU_ENTERED, //"You entered this many minutes: %f\n\n"
    MSG_DAYS_N_YEARS //"Which is this many days: %f\n\nAnd this many years: %f\n\n",
} UsrMsgs;

const char* get_error_msg(ErrorMsgs code);
const char* get_usr_msg(UsrMsgs code);

#endif /* MESSAGES_H */
