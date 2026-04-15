#ifndef SERVO_H
#define SERVO_H

#ifdef __cplusplus
extern "C" {
#endif

#define PIN_SERVOCAFE 9 /*RA9*/
#define PIN_SERVOAZUCAR 14 /*RB14*/

void initServos(void);

void abrirServoCafe(void);
void cerrarServoCafe(void);

void abrirServoAzucar(void);
void cerrarServoAzucar(void);


    
#ifdef __cplusplus
}
#endif

#endif /*SERVO_H*/
