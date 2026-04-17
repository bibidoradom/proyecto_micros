#include <xc.h>
#include "config.h"
#include "sensores.h"
#include "actuadores.h"

int main(void) {
    
    int pulsador_ant, pulsador_act;
    int abierto = 0;

    ANSELC = 0;
    ANSELB = 0;
    
    TRISC = 0;
    TRISB |= 1<<5;
    
    pulsador_ant = (PORTB >> PIN_PULSADOR) & 1;
    
    apagarTodo();
    
    while(1){
        
        // Presionas pulsador
        pulsador_act = (PORTB >> PIN_PULSADOR) & 1;
        
        if ((pulsador_act != pulsador_act) && (pulsador_act == 0)){
            if (abierto == 0){
                LATCCLR = 1 << 1;
                valvulaON();
                motorON();
                bombaON();
                calefactorON();
                abierto = 1;
            } else {
                LATCSET = 1 << 1;
                apagarTodo();
                abierto = 0;
            }
            
        }
        
        pulsador_ant = pulsador_act;
    }
}

