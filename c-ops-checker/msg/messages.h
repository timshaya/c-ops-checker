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

const char* get_error_msg(ErrorMsgs code);

#endif /* MESSAGES_H */
