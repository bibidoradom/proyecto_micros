#ifndef CONFIG_H
#define CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif
    
#define PIN_RELE_ELECTROVALVULA 7 //RA7
#define PIN_RELE_BOMBA 1 //RA1
#define PIN_RELE_MOTOR 10 //RA10

#define PIN_SENSORPRESENCIA 2 //RB2
    
#define PIN_RELE_CALEFACTOR 4 //RC4
    
void initPines(void);

#ifdef __cplusplus
}
#endif

#endif /* CONFIG_H */