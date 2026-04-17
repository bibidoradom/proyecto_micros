#include <xc.h>
#include "Pic32Ini.h"
#include "timers.h"

static flagsT3 = 0;

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
    
    IFS0bits.T3IF = 0;
    IEC0bits.T3IE = 1;
    IPC3bits.T3IP = 2;// Prioridad 2
    IPC3bits.T3IS = 0; //subprioridad 0
    
    T3CON |= (1<<15); //TIMER3 ON = 1
}

void __attribute__((vector(12), interrupt(IPL2SOFT), nomips16)) 
InterrupcionTimer3(void){
    flagsT3 ++;
}

void reiniciarFlagsT3(void){
    flagsT3 = 0;
}