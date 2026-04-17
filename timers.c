#include <xc.h>
#include "Pic32Ini.h"
#include "timers.h"

void initTimers(void){
    initTimer1();
    initTimer2();
    initTimer3();
}

void initTimer1(void);

void initTimer2(void){
    
    // Timer para los OC de 20 ms
    T2CON = 0;  
    TMR2 = 0;  
    PR2 = 49999;  // PERIODO de 20 ms
    T2CON |= (1 << 4);  // Pre-escalado = 1:2 (TCKPS = 001)

    T2CON |= (1 << 15);  // TIMER2 ON = 1
    
}

void initTimer3(void){
    
    // Periodo de 0.5 segundos
    T3CON = 0;
    TMR3 = 0;
    PR3 = 39062;
    T3CON |= (6 << 4); // Pre-escalado = 1:64 (TCKPS = 110)
    
    T3CON |= (1<<15); //TIMER3 ON = 1
}