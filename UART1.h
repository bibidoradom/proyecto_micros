#ifndef UART1_H
#define UART1_H

void InicializarUART1(int baudios);
void putsUART(char s[]);
char getcUART(void);
void recibirOrden(void);
void desactivarReceptor(void);

#endif