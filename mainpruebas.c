#include <xc.h>
#include "sensores.h"
#include "actuadores.h"

int main(void) {
    
    int pulsador_ant, pulsador_act;
    int abierto = 0;

    ANSELC = 0;
    ANSELB = 0;
    
    TRISC = 0;
    TRISB |= 1<<5;
    
    pulsador_ant = (PORTB >> 5) & 1;
    
    apagarTodo();
    
    while(1){
        
        // Leer Sensor Presencia
        LATC = leerSensorIR();
        
        // Presionas pulsador
        pulsador_act = (PORTB >> 5) & 1;
        
        if ((pulsador_act != pulsador_act) && (pulsador_act == 0)){
            if (abierto == 0){
                valvulaON();
                motorON();
                bombaON();
                calefactorON();
                abierto = 1;
            } else {
                apagarTodo();
                abierto = 0;
            }
            
        }
    }
}

