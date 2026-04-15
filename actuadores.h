#ifndef ACTUADORES_H 
#define ACTUADORES_H

#ifdef __cplusplus
extern "C" {
#endif
    
void initActuadores(void); // VALORAR SI QUITARLA O NO

void bombaON(void);
void bombaOFF(void);

void valvulaON(void);
void valvulaOFF(void);

int motorON(void);
int motorOFF(void);

int calefactorON(void);
int calefactorOFF(void);

int apagarTodo(void);

#ifdef __cplusplus
}
#endif

#endif /* ACTUADORES_H */