#include <xc.h>
#include "sensores.h"
#include "config.h"

void initSensores(void){
    
}

int leerSensorIR(void){
    // 1 si hay vaso, 0 si no hay vaso
    return ~((PORTB >> PIN_SENSORPRESENCIA) & 1);
}

int leerADCTemperatura(void);
int calcularTemperatura(void);