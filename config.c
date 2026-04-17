#include <xc.h>
#include "config.h"

void initPines(void){
    
   ANSELA = 0;
   ANSELA |= 1 << PIN_SENSOR_TEMPERATURA;
   ANSELB = 0;
   ANSELC = 0;
   
   TRISA = 0;
   TRISA |= 1 << PIN_SENSOR_TEMPERATURA;
   TRISB = 0;
   TRISB |= 1 << PIN_SENSOR_PRESENCIA;
   TRISC = 0;

}