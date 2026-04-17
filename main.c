#include <xc.h>
#include <stdint.h>
#include "UART1.h"
#include "BitWhacker.h"


int main(void)
{
    
    enum {Inicio, Espera_Datos, Comprobaciones, Calentar_Agua, Echar_Agua, Echar_Cafe, 
    Echar_Azucar, Terminar_Remover, Servir_Cafe, Pausa, Fin_Cafe, Error} estado;
    
    

    InicializarUART1(9600);

    // Habilitar interrupciones
    INTCONbits.MVEC = 1;
    asm("ei");

    // Ponemos a digital para poder leer 1o 0 en los analógicos
    ANSELB = 0x0;
    ANSELC = 0x0;
    
    
    
    while(1)
    {
        
        switch(estado){
            case Inicio:
                if (){
                    estado = 
                }
        }
       
    }
}

