#include <avr/interrupt.h>
#include <inttypes.h>

#define MAX_TIMERS 10

static virtual_timer_t timers[MAX_TIMERS];
static clock_t hw_timer_start;

void Timer0_Ini ( void )
{
    TCNT0=0x06; /* Inicializar valor para el timer0 */
    TCCR0A=0x00; /* inicializa timer0 en modo 0 (normal) */
    /* Inicializar con fuente de osc. Int. */
    TCCR0B=0x03; /* con Prescalador 64 */
    TIMSK0=0x01; /* habilita interrupcion del Timer0 */
    sei(); /* habilita interrupciones (global) */
    
    // TO-DO: Inicializar virtual timers
}

ISR (TIMER0_OVF_vect)
{ /* TIMER0_OVF_vect */
    static uint16_t mSecCnt;
    TCNT0+=0x06; /* reinicializar Timer0 sin perder conteo */
    mSecCnt++; /* Incrementa contador de milisegundos */
    if( mSecCnt==1000 )
    {
        mSecCnt=0;
        SecFlag=1; /* Bandera de Segundos */
    }
    // TO-DO: Revisar si alguno de los timers virtuales a expirado
}

int register_timer(uint32_t timeout_ms, timer_mode_t mode, timer_callback_t callback) 
{
    for (int i = 0; i < MAX_TIMERS; i++) {
        // TO-DO: Implementar
    }
    return -1; // No available timer slots
}

void stop_timer(int timer_id) 
{
    // TO-DO: Implementar
}