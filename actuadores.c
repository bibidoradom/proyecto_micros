#include <xc.h>
#include "actuadores.h"
#include "config.h"

void initActuadores(void); //VALORAR SI QUITARLA

void bombaON(void){
    LATA &= ~(1 << PIN_RELE_BOMBA); 
}
void bombaOFF(void){ 
    LATA |= (1 << PIN_RELE_BOMBA);
}

void valvulaON(void){
    LATC &= ~(1 << PIN_RELE_ELECTROVALVULA);
}

void valvulaOFF(void){
    LATC |= (1 << PIN_RELE_ELECTROVALVULA); 
}

int motorON(void){
    LATCCLR = 1 << PIN_RELE_MOTOR;
    
}

int motorOFF(void){
    LATCSET = 1 << PIN_RELE_MOTOR;
    
}

int calefactorON(void){
    LATC &= ~(1 << PIN_RELE_CALEFACTOR);
}

int calefactorOFF(void){
   LATC |= (1 << PIN_RELE_CALEFACTOR);
}

int apagarTodo(void){
    bombaOFF();
    valvulaOFF();
    motorOFF();
    calefactorOFF();
}