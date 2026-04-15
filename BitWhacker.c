#include <xc.h>
#include <stdint.h>
#include <ctype.h>
#include <stdio.h>
#include "UART1.h"
#include "BitWhacker.h"

int toInt(char c)
{
    c = toupper(c);  // convierte a mayúscula si es letra

    if(c >= '0' && c <= '9')
        return c - '0';

    if(c >= 'A' && c <= 'F')
        return c - 'A' + 10;

    return -1;
}

void ProcesaOrden(char orden[])
{
    char respuesta[20];
    char puerto;
    int pin;
    int valor;
    int i = 0;

    // 1) Pasar todo a mayúsculas
    while(orden[i] != '\0'){
        orden[i] = toupper(orden[i]);
        i++;
    }

    // 2) Comando PD si el ultimo digito es un 1 entrada si no salida
    if(orden[0] == 'N' && orden[2] == 'C'){
        if(orden[2] != ',' || orden[4] != ',' || orden[6] != ','){ //|| orden[8] != '\0'
            putsUART("Error\n");
            return;
        }
        
        puerto = orden[3];
        pin = toInt(orden[5]);
        valor = toInt(orden[7]);   // 0 salida, 1 entrada

        if(puerto != 'B' && puerto != 'C'){
            putsUART("Puerto no soportado\n");
            return;
        }

        if(pin < 0 || pin > 15 || (valor != 0 && valor != 1)){
            putsUART("Error\n");
            return;
        }

        if(puerto == 'B'){
            if(valor == 0)
                TRISB &= ~(1 << pin);
            else
                TRISB |= (1 << pin);
        }
        else{ // puerto C
            if(valor == 0)
                TRISC &= ~(1 << pin);
            else
                TRISC |= (1 << pin);
        }

        putsUART("OK\n");
        return;
    }

    // 3) Comando PI lee el estado del pin
    if(orden[0] == 'P' && orden[1] == 'I'){
        if(orden[2] != ',' || orden[4] != ','){//|| orden[6] != '\0'
            putsUART("Error\n");
            return;
        }

        puerto = orden[3];
        pin = toInt(orden[5]);

        if(puerto != 'B' && puerto != 'C'){
            putsUART("Puerto no soportado\n");
            return;
        }

        if(pin < 0 || pin > 15){
            putsUART("Error\n");
            return;
        }

        if(puerto == 'B'){
            valor = (PORTB >> pin) & 1;
        }
        else{ // puerto C
            valor = (PORTC >> pin) & 1;
        }

        sprintf(respuesta, "PI,%d\n", valor);
        putsUART(respuesta);
        return;
    }

    // 4) Comando PO, cambia el estado del pin
    
    if(orden[0] == 'P' && orden[1] == 'O'){
        if(orden[2] != ',' || orden[4] != ',' || orden[6] != ','){//|| orden[8] != '\0'
            putsUART("Error\n");
            return;
        }

        puerto = orden[3];
        pin = toInt(orden[5]);
        valor = toInt(orden[7]);   // 0 o 1

        if(puerto != 'B' && puerto != 'C'){
            putsUART("Puerto no soportado\n");
            return;
        }

        if(pin < 0 || pin > 15 || (valor != 0 && valor != 1)){
            putsUART("Error\n");
            return;
        }

        if(puerto == 'B'){
            if(valor == 0)
                LATB &= ~(1 << pin);
            else
                LATB |= (1 << pin);
        }
        else{ // puerto C
            if(valor == 0)
                LATC &= ~(1 << pin);
            else
                LATC |= (1 << pin);
        }

        putsUART("OK\n");
        return;
    }

    // 5) Instrucción desconocida
    putsUART("Instruccion desconocida\n");
}
