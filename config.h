#ifndef CONFIG_H
#define CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif
    
#define PIN_SENSOR_TEMPERATURA 0 //RA0
#define PIN_RELE_BOMBA 1 //RA1
#define PIN_SERVO_CAFE 9 //RA9

#define PIN_SENSOR_PRESENCIA 2 //RB2
#define PIN_PULSADOR 5 //RB5)
#define PIN_SERVO_AZUCAR 14 //RB14
    
#define PIN_LED_APAGADO 0 //RC0
#define PIN_LED_PREPARACION 1 //RC1   
#define PIN_LED_LISTO 2 //RC2
#define PIN_RELE_CALEFACTOR 4 //RC4
#define PIN_RELE_ELECTROVALVULA 8 //RC8
#define PIN_RELE_MOTOR 9 //RC9
    
void initPines(void);

#ifdef __cplusplus
}
#endif

#endif /* CONFIG_H */