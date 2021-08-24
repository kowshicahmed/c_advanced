#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
//#include "fsm.h"
typedef struct Fsm {
    State state; /* current state */
}Fsm;
typedef struct Event Event;
//typedef struct Fsm Fsm;

/* a state is represented by a function pointer, called for each transition emanating in this state */
typedef void (*State)(Fsm *, const Event *);

/* base type for events*/
struct Event {
    int signal;
};

/* base type for state machine */

//typedef struct Fsm {
    //State state; /* current state */
//};


/* dispatches events to state machine, called in application*/
inline static void fsm_dispatch(Fsm* fsm, const Event* event) {
    fsm->state(fsm, event);
}

/* sets and calls initial state of state machine */
inline static void fsm_init(Fsm* fsm, State init) {
    fsm->state = init;
    fsm_dispatch(fsm, NULL);
}

typedef struct {
    Fsm super;
} KeyboardFsm;

typedef struct {
    Event super;
    char code;
} KeyboardEvent;

/* signals used by the keyboard FSM */
enum {SHIFT_PRESSED_SIG, SHIFT_RELEASED_SIG, ANY_KEY_SIG};
void keyboard_init(Fsm *fsm, const Event *event);
void keyboard_default(Fsm *fsm, const Event *e);
void keyboard_shifted(Fsm *fsm, const Event *e);

void keyboard_init(Fsm *fsm, const Event *event) {
    fsm->state = keyboard_default;
    printf("init\n"); //debug info
}
void keyboard_default(Fsm *fsm, const Event *e) {
    switch (e->signal) {
        case SHIFT_PRESSED_SIG:
        printf("default::SHIFT_PRESSED\n"); //debug info
        fsm->state = keyboard_shifted;
        break;
        case ANY_KEY_SIG:
        printf("default::ANY_KEY (%c) \n", (char) tolower(((const KeyboardEvent*) e)->code));
        break;
    }
}

void keyboard_shifted(Fsm *fsm, const Event *e) {
    switch (e->signal) {
        case SHIFT_RELEASED_SIG:
        printf("shifted::SHIFT_RELEASED\n"); //debug info
        fsm->state = keyboard_default;
        break;
        case ANY_KEY_SIG:
        printf("shifted::ANY_KEY (%c) \n", (char) toupper(((const KeyboardEvent*) e)->code));
        break;
    }
}

int main(void) {
    KeyboardFsm keyboard;
    fsm_init((Fsm*) &keyboard, keyboard_init);
    while (1) {
        KeyboardEvent e;
        e.code = getc(stdin);
        getc(stdin); // discard \n
        switch (e.code) {
            case '^': e.super.signal = SHIFT_PRESSED_SIG; break;
            case '6': e.super.signal = SHIFT_RELEASED_SIG; break;
            case '.': return 0;
            default: e.super.signal = ANY_KEY_SIG; break;
            }
    fsm_dispatch((Fsm*) &keyboard, (const Event*) &e);
    }
    return 0;
}
