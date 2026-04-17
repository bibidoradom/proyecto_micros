#include <xc.h>
#include <stdint.h>
#include "UART1.h"

// Tamaños
#define TAM_RX 100
#define TAM_TX 100
#define TAM_ORDEN 20

// Buffers simples
static char rx_buffer[TAM_RX];
static volatile int rx_index = 0;
static volatile int rx_flag = 0;   // indica que hay datos nuevos

static char tx_buffer[TAM_TX];
static volatile int tx_index = 0;
static volatile int tx_len = 0;


void InicializarUART1(int baudios){

    // Configuración de pines
    ANSELB &= ~((1 << 13) | (1 << 7));   // RB13 y RB7 digitales
    TRISB  |=  (1 << 13);                // RB13 entrada (RX)
    TRISB  &= ~(1 << 7);                 // RB7 salida (TX)
    LATB   |=  (1 << 7);                 // TX en reposo alto

    // Remapeo de pines
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;
    U1RXR  = 3;      // U1RX en RB13
    RPB7R  = 1;      // U1TX en RB7
    SYSKEY = 0x1CA11CA1;

    // Apagar UART antes de configurar
    U1MODE = 0;
    U1STA  = 0;

    // Configurar velocidad
    if(baudios > 38400){
        U1MODEbits.BRGH = 1;                  // divisor por 4
        U1BRG = (5000000 / (4 * baudios)) - 1;
    }else{
        U1MODEbits.BRGH = 0;                  // divisor por 16
        U1BRG = (5000000 / (16 * baudios)) - 1;
    }

    // Formato 8N1
    U1MODEbits.PDSEL = 0;   // 8 bits, sin paridad
    U1MODEbits.STSEL = 0;   // 1 bit de stop

    // Configuración de interrupciones
    IFS1bits.U1RXIF = 0; //Boramos flag
    IFS1bits.U1TXIF = 0; //Borramos flag
    IEC1bits.U1RXIE = 1; //Habilitamos recepcion
    IEC1bits.U1TXIE = 0; //Al principio no hay nada que mandar

    IPC8bits.U1IP = 3; //PRIORIDAD
    IPC8bits.U1IS = 1; //SUBPRIORIDAD

    U1STAbits.URXISEL = 0;  // interrumpe al llegar 1 carácter
    U1STAbits.UTXISEL = 2;  // interrumpe cuando la FIFO TX está vacía

    // Habilitar RX y TX
    U1STAbits.URXEN = 1;
    U1STAbits.UTXEN = 1;

    // 9) Encender UART
    U1MODEbits.ON = 1;
}

void __attribute__((vector(32), interrupt(IPL3SOFT), nomips16)) InterrupcionUART1(void){

    // RECEPCIÓN
    if(IFS1bits.U1RXIF){
        char c = U1RXREG;

        if(rx_index < TAM_RX - 1){
            rx_buffer[rx_index++] = c;

            if(c == '\n'){
                rx_buffer[rx_index] = '\0'; // cerrar string
                rx_flag = 1;                // hay orden lista
                rx_index = 0;               // reiniciar buffer
            }
        } else {
            rx_index = 0; // overflow ? reinicio
        }

        IFS1bits.U1RXIF = 0;
    }

    // TRANSMISIÓN
    if(IFS1bits.U1TXIF){

        if(tx_index < tx_len){
            U1TXREG = tx_buffer[tx_index++];
        } else {
            IEC1bits.U1TXIE = 0; // fin de envío
        }

        IFS1bits.U1TXIF = 0;
    }
}

char getcUART(void){
    if(rx_flag){
        rx_flag = 0;
        return 1; // hay datos disponibles
    }
    return 0;
}

void putsUART(char s[]){
    int i = 0;

    while(s[i] != '\0' && i < TAM_TX){
        tx_buffer[i] = s[i];
        i++;
    }

    tx_len = i;
    tx_index = 0;

    IEC1bits.U1TXIE = 1; // activar envío
}

void recibirOrden(void){
    
    void recibirOrden(){

    if(rx_flag){
        rx_flag = 0;
        ProcesaOrden(rx_buffer);
    }
}
    
void desactivarReceptor(void){
    U1STAbits.URXEN = 0;
}
