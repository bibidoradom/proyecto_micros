#include <xc.h>
#include <stdint.h>
#include "UART1.h"

// 1) defines
#define TAM_COLA 100
#define TAM_ORDEN 20

// 2) estructura de cola

typedef struct{
    int icabeza;
    int icola;
    char datos[TAM_COLA];
} cola_t;

// 3) variables estáticas

static cola_t cola_rx;
static cola_t cola_tx;

// 4) InicializarUART1()
void InicializarUART1(int baudios){
    // 1) Inicialización de colas
    cola_rx.icabeza = 0;
    cola_rx.icola   = 0;
    cola_tx.icabeza = 0;
    cola_tx.icola   = 0;

    // 2) Configuración de pines
    ANSELB &= ~((1 << 13) | (1 << 7));   // RB13 y RB7 digitales
    TRISB  |=  (1 << 13);                // RB13 entrada (RX)
    TRISB  &= ~(1 << 7);                 // RB7 salida (TX)
    LATB   |=  (1 << 7);                 // TX en reposo alto

    // 3) PPS: asignación de pines
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
    U1RXR  = 3;      // U1RX en RB13
    RPB7R  = 1;      // U1TX en RB7
    SYSKEY = 0x1CA11CA1;

    // 4) Apagar UART antes de configurar
    U1MODE = 0;
    U1STA  = 0;

    // 5) Configurar velocidad
    if(baudios > 38400){
        U1MODEbits.BRGH = 1;                  // divisor por 4
        U1BRG = (5000000 / (4 * baudios)) - 1;
    }else{
        U1MODEbits.BRGH = 0;                  // divisor por 16
        U1BRG = (5000000 / (16 * baudios)) - 1;
    }

    // 6) Formato 8N1
    U1MODEbits.PDSEL = 0;   // 8 bits, sin paridad
    U1MODEbits.STSEL = 0;   // 1 bit de stop

    // 7) Configuración de interrupciones
    IFS1bits.U1RXIF = 0; //Boramos flag
    IFS1bits.U1TXIF = 0; //Borramos flag
    IEC1bits.U1RXIE = 1; //Habilitamos recepcion
    IEC1bits.U1TXIE = 0; //Al principio no hay nada que mandar

    IPC8bits.U1IP = 3; //PRIORIDAD
    IPC8bits.U1IS = 1; //SUBPRIORIDAD

    U1STAbits.URXISEL = 0;  // interrumpe al llegar 1 carácter
    U1STAbits.UTXISEL = 2;  // interrumpe cuando la FIFO TX está vacía

    // 8) Habilitar RX y TX
    U1STAbits.URXEN = 1;
    U1STAbits.UTXEN = 1;

    // 9) Encender UART
    U1MODEbits.ON = 1;
}
// 5) Rutina de interrupcion
void __attribute__((vector(32), interrupt(IPL3SOFT), nomips16)) InterrupcionUART1(void){
    
    if(IFS1bits.U1RXIF == 1){   // interrumpido el receptor
        
        if( (cola_rx.icabeza + 1 == cola_rx.icola) ||
            (cola_rx.icabeza + 1 == TAM_COLA && cola_rx.icola == 0) ){
            // La cola RX está llena
        }
        else{
            cola_rx.datos[cola_rx.icabeza] = U1RXREG;   // Leer carácter recibido
            cola_rx.icabeza++;

            if(cola_rx.icabeza == TAM_COLA){
                cola_rx.icabeza = 0;
            }
        }

        IFS1bits.U1RXIF = 0;    // Borrar flag de RX
    }

    if(IFS1bits.U1TXIF == 1){   // interrumpido el transmisor
        
        if(cola_tx.icola != cola_tx.icabeza){   // Hay datos por enviar
            U1TXREG = cola_tx.datos[cola_tx.icola];
            cola_tx.icola++;

            if(cola_tx.icola == TAM_COLA){
                cola_tx.icola = 0;
            }
        }
        else{   // Ya no queda nada en la cola TX
            IEC1bits.U1TXIE = 0;   // Deshabilitar TX para no entrar en bucle
        }

        IFS1bits.U1TXIF = 0;    // Borrar flag de TX
    }
}
// 6) getcUART()
char getcUART(void){
    char c;
    if(cola_rx.icola != cola_rx.icabeza){   // Hay datos nuevos en la cola RX
        c = cola_rx.datos[cola_rx.icola];
        cola_rx.icola++;

        if(cola_rx.icola == TAM_COLA){
            cola_rx.icola = 0;
        }
    }
    else{
        c = '\0';   // No ha llegado nada
    }

    return c;
}
// 7) putsUART()
void putsUART(char s[]){
    uint8_t i = 0;

    while(s[i] != '\0'){
        if( (cola_tx.icabeza + 1 == cola_tx.icola) ||
            (cola_tx.icabeza + 1 == TAM_COLA && cola_tx.icola == 0) ){
            break;   // La cola está llena, se aborta lo que queda
        }
        else{
            cola_tx.datos[cola_tx.icabeza] = s[i];
            i++;
            cola_tx.icabeza++;

            if(cola_tx.icabeza == TAM_COLA){
                cola_tx.icabeza = 0;
            }
        }
    }
    // Habilitar TX para que empiece a enviar la ISR
    IEC1bits.U1TXIE = 1;
}

//La cabeza escribe el dato nuevo y la cola lee el dato más antiguo; 
//en RX escribe la ISR y lee el programa, 
//y en TX escribe el programa y lee la ISR


void recibirOrden(){
    
    char c;
    char orden[TAM_ORDEN];
    int i = 0;
    
    c = getcUART();

        if(c != '\0')
        {
            if(c == '\n')        // fin de orden
            {
                orden[i] = '\0'; // terminar string
                ProcesaOrden(orden);
                i = 0;           // reiniciar buffer
            }
            else
            {
                if(i < TAM_ORDEN-1)
                {
                    orden[i] = c;
                    i++;
                }
            }
        }
}
