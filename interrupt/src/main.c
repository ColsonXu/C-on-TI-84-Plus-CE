#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <intce.h>


void interrupt isr_on(void);
bool exit_loop = false;


void main(void) {

    prgm_CleanUp();
    os_SetCursorPos( 0, 0 );
    os_PutStrFull("PRESS ON, YOU MUTHERFUCKER!!!");

    int_Initialize();

    int_SetVector(ON_IVECT, isr_on);

    int_EnableConfig = INT_ON;

    int_Enable();

    while( !exit_loop );

    os_SetCursorPos( 0, 0 );
    os_PutStrFull("PRESS ON, YOU MUTHERFUCKER!!!");

    int_Reset();
    prgm_CleanUp();
}

void interrupt isr_on(void) {
    exit_loop = true;
    int_Acknowledge = INT_ON;
}