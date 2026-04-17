#include <xc.h>
#include <stdint.h>
#include "UART1.h"
#include "BitWhacker.h"
#include "config.h"

static int pulsador_ant, pulsador_act;

int main(void)
{ 
    int pedido_recibido = 0;
    int temperatura_agua = 2;
    int pulsador_ant, pulsador_act, agua_echada;
    
    enum {Inicio, Espera_Datos, Comprobaciones, Calentar_Agua, Echar_Agua, Echar_Cafe, 
    Echar_Azucar, Terminar_Remover, Servir_Cafe, Pausa, Fin_Cafe, Error} estado;
    
    estado = Inicio;

    // Habilitar interrupciones
    INTCONbits.MVEC = 1;
    asm("ei");
    
    pulsador_ant = (PORTB >> PIN_PULSADOR) & 1;
    
    while(1)
    {
        // Presionas pulsador
        pulsador_act = (PORTB >> PIN_PULSADOR) & 1;
        
        if ((pulsador_ant != pulsador_act) && (pulsador_act == 0)){
            pedido_recibido = 1;
        }
        
        pulsador_ant = pulsador_act;
        
        switch(estado){
            case Inicio:
                initPines();
                InicializarUART1(9600);
                estado = Espera_Datos;
                break;
                
            case Espera_Datos:
                if (pedido_recibido == 1){
                    reiniciarFlagsT3();
                    initTimer3();
                    initServos();
                    estado = Comprobaciones;
                }
                break;
                
            case Comprobaciones:
                
                if (temperatura_agua == 1){
                    reiniciarFlagsT3();
                    estado = Echar_Agua;
                }
                if (temperatura_agua == 0){
                    estado = Calentar_Agua;
                }
                break;
            
            case Echar_Agua:
                if (agua_echada == 1){
                    reiniciarFlagsT3();
                    estado = Echar_Cafe;
                }
                break;
                
            case Calentar_Agua:
                if (temperatura_agua == 1){
                    reiniciarFlagsT3();
                    estado = Echar_Agua;
                }
                break;
        }
        

        
        if (estado == Espera_Datos){
            recibirOrden(); 
            LATCCLR = 1 << PIN_LED_APAGADO;
        }
        
        if (estado == Comprobaciones){
            desactivarReceptor();
            abrirServoAzucar();
            // temperatura_agua = leerADC
            if (getFlagsT3() == 1){
                temperatura_agua = 1;
            }
            LATCSET = 1 << PIN_LED_APAGADO;
            LATCCLR = 1 << PIN_LED_PREPARACION;
        }
        
        if (estado == Echar_Agua){
            valvulaON();
            cerrarServoAzucar();
            LATCSET = 1 << PIN_LED_PREPARACION;
            LATCCLR = 1 << PIN_LED_LISTO; 
            if (getFlagsT3() == 10){
                valvulaOFF();
                agua_echada = 1;
                
            }
        }
        
        if (estado == Calentar_Agua){
            LATCSET = 1 << PIN_LED_LISTO;
            LATCCLR = 1 << 3;
        }
       
    }
}

