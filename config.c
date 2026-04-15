#include <xc.h>
#include "config.h"

void initPines(void){
    
   ANSELA = 0;
   ANSELB = 0;
   ANSELC = 0;
   
   TRISA = 0;
   TRISB = 0;
   TRISB |= 1 << PIN_SENSORPRESENCIA;
   TRISC = 0;

}