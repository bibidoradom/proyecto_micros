#ifndef SENSORES_H 
#define SENSORES_H

#ifdef __cplusplus
extern "C" {
#endif
    
void initSensores(void);

int leerSensorIR(void);

int leerADCTemperatura(void);
int calcularTemperatura(void);

#ifdef __cplusplus
}
#endif

#endif /* SENSORES_H */