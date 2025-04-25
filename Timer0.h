#ifndef _TIMER0_H
#define _TIMER0_H

#include <inttypes.h>

/* Función para inicializar el Timer0 y generar */
/* la temporización de 1 Sec. */
void Timer0_Ini ( void );

/* Función para verificar bandera del segundo */
uint8_t Timer0_SecFlag ( void );

typedef void (*timer_callback_t)(void);

typedef enum {
    TIMER_ONE_SHOT,
    TIMER_CONTINUOUS
} timer_mode_t;

typedef struct {
    uint8_t active;
    uint32_t timeout_ms;
    timer_callback_t callback;
    timer_mode_t mode;
} virtual_timer_t;

#endif /* _TIMER0_H */