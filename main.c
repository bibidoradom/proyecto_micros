#include <xc.h>
#include <stdint.h>
#include "UART1.h"
#include "BitWhacker.h"


int main(void)
{
    
    int i = 0;

    InicializarUART1(9600);

    // Habilitar interrupciones
    INTCONbits.MVEC = 1;
    asm("ei");

    // Ponemos a digital para poder leer 1o 0 en los analógicos
    ANSELB = 0x0;
    ANSELC = 0x0;
    
    while(1)
    {
        
        
        // CAMBIAR ESTE CÓDIGO DE A CONTINUACIÓN AL ARCHIVO UART1.h A UNA FUNCIÓN QUE SEA "recibirOrden" PARA QUE CUADRE CON LOS ESQUEMAS
        // AQUÍ MÁQUINA DE ESTADOS
        
        
    }
}

