#include <xc.h>
#include "servo.h"
#include "timers.h"

void initServos(void){
    
    int t_alto = 1250;  // Tiempo en alto inicial 0.5 ms, -90° 

    // REMAPEO DE OC2 AL RA9 Y DE OC3 A RB14
    SYSKEY = 0xAA996655;  
    SYSKEY = 0x556699AA;
    RPA9R = 5;
    RPB14R = 5;
    SYSKEY = 0x1CA11CA1;
   

    // CONFIGURACIÓN OUTPUT COMPARE (OC2)
    OC2CON = 0;  // Primero apagamos OC1
    OC2R = t_alto;  
    OC2RS = t_alto;
    OC2CON = 0x8006;  // Modo PWM sin fallos (OCM = 110)

    OC2CON |= (1 << 15);  // ON = 1, activar OC
    
    // CONFIGURACIÓN OUTPUT COMPARE (OC3)
    OC3CON = 0;  // Primero apagamos OC1
    OC3R = t_alto;  
    OC3RS = t_alto;
    OC3CON = 0x8006;  // Modo PWM sin fallos (OCM = 110)

    OC3CON |= (1 << 15);  // ON = 1, activar OC
    
    initTimer2();
}


void abrirServoCafe(void){
    int t_alto = 3500; // A modificar para ver cuanto café queremos que pase
    OC2RS = t_alto;
}
void cerrarServoCafe(void){
    int t_alto = 1250;
    OC2RS = t_alto;
}

void abrirServoAzucar(void){
    int t_alto = 3500; // A modificar para ver cuanto azúcar queremos que pase
    OC3RS = t_alto;
}
void cerrarServoAzucar(void){
    int t_alto = 1250; // A modificar para ver cuanto café queremos que pase
    OC3RS = t_alto;
}