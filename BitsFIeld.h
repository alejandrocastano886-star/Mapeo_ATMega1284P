/*
 * BitsFIeld.h
 *
 * Created: 4/09/2026 6:53:50 a. m.
 *  Author: Usuario
 */ 


#ifndef BITSFIELD_H_
#define BITSFIELD_H_

#ifndef BITFIELDS_ATMEGA1284P_H_
#define BITFIELDS_ATMEGA1284P_H_

/*
 * Bit-fields para ATmega1284P - AVR-GCC / Microchip Studio.
 *
 * Los registros se mapean sobre su direccion real con _SFR_MEM_ADDR().
 * Los campos b0...b7 se usan intencionalmente para no chocar con macros
 * de avr/io.h tales como PB0, DDB0, etc.
 */

#include <avr/io.h>
#include <stdint.h>

/* Registro de 8 bits, en orden de bit menos a mas significativo. */
typedef struct {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
} Bit8_t;

#define SFR_BIT8(reg) (*(volatile Bit8_t *)_SFR_MEM_ADDR(reg))

/* ==================== PUERTOS ====================
 * DDRx  : 0 entrada, 1 salida.
 * PINx  : lectura del nivel electrico del pin.
 * PORTx : salida si DDRx=1; pull-up si DDRx=0.
 */
#define DDRA_bits   SFR_BIT8(DDRA)
#define PINA_bits   SFR_BIT8(PINA)
#define PORTA_bits  SFR_BIT8(PORTA)

#define DDRB_bits   SFR_BIT8(DDRB)
#define PINB_bits   SFR_BIT8(PINB)
#define PORTB_bits  SFR_BIT8(PORTB)

#define DDRC_bits   SFR_BIT8(DDRC)
#define PINC_bits   SFR_BIT8(PINC)
#define PORTC_bits  SFR_BIT8(PORTC)

#define DDRD_bits   SFR_BIT8(DDRD)
#define PIND_bits   SFR_BIT8(PIND)
#define PORTD_bits  SFR_BIT8(PORTD)

/* ==================== UART ====================
 * UCSRnA : banderas de estado (RXC, TXC, UDRE, FE, DOR, UPE) y U2X/MPCM.
 * UCSRnB : habilitacion de TX/RX e interrupciones, bit alto de tamano de trama.
 * UCSRnC : modo, paridad, bits de parada y tamano de trama (bits bajos).
 * UBRRn (16 bits) y UDRn se manejan directo con avr/io.h, sin bit-field.
 */
typedef struct {
    unsigned char mpcm0 : 1;
    unsigned char u2x0  : 1;
    unsigned char upe0  : 1;
    unsigned char dor0  : 1;
    unsigned char fe0   : 1;
    unsigned char udre0 : 1;
    unsigned char txc0  : 1;
    unsigned char rxc0  : 1;
} UCSR0A_bits_t;

typedef struct {
    unsigned char txb80  : 1;
    unsigned char rxb80  : 1;
    unsigned char ucsz02 : 1;
    unsigned char txen0  : 1;
    unsigned char rxen0  : 1;
    unsigned char udrie0 : 1;
    unsigned char txcie0 : 1;
    unsigned char rxcie0 : 1;
} UCSR0B_bits_t;

typedef struct {
    unsigned char ucpol0  : 1;
    unsigned char ucsz00  : 1;
    unsigned char ucsz01  : 1;
    unsigned char usbs0   : 1;
    unsigned char upm00   : 1;
    unsigned char upm01   : 1;
    unsigned char umsel00 : 1;
    unsigned char umsel01 : 1;
} UCSR0C_bits_t;

#define UCSR0A_bits (*(volatile UCSR0A_bits_t *)_SFR_MEM_ADDR(UCSR0A))
#define UCSR0B_bits (*(volatile UCSR0B_bits_t *)_SFR_MEM_ADDR(UCSR0B))
#define UCSR0C_bits (*(volatile UCSR0C_bits_t *)_SFR_MEM_ADDR(UCSR0C))

typedef struct {
    unsigned char mpcm1 : 1;
    unsigned char u2x1  : 1;
    unsigned char upe1  : 1;
    unsigned char dor1  : 1;
    unsigned char fe1   : 1;
    unsigned char udre1 : 1;
    unsigned char txc1  : 1;
    unsigned char rxc1  : 1;
} UCSR1A_bits_t;

typedef struct {
    unsigned char txb81  : 1;
    unsigned char rxb81  : 1;
    unsigned char ucsz12 : 1;
    unsigned char txen1  : 1;
    unsigned char rxen1  : 1;
    unsigned char udrie1 : 1;
    unsigned char txcie1 : 1;
    unsigned char rxcie1 : 1;
} UCSR1B_bits_t;

typedef struct {
    unsigned char ucpol1  : 1;
    unsigned char ucsz10  : 1;
    unsigned char ucsz11  : 1;
    unsigned char usbs1   : 1;
    unsigned char upm10   : 1;
    unsigned char upm11   : 1;
    unsigned char umsel10 : 1;
    unsigned char umsel11 : 1;
} UCSR1C_bits_t;

#define UCSR1A_bits (*(volatile UCSR1A_bits_t *)_SFR_MEM_ADDR(UCSR1A))
#define UCSR1B_bits (*(volatile UCSR1B_bits_t *)_SFR_MEM_ADDR(UCSR1B))
#define UCSR1C_bits (*(volatile UCSR1C_bits_t *)_SFR_MEM_ADDR(UCSR1C))

/* ==================== ADC ====================
 * ADMUX  : selecciona canal (MUX), formato de resultado (ADLAR) y referencia.
 * ADCSRA : habilitacion, inicio de conversion, bandera/interrupcion y prescaler.
 * ADCSRB : fuente de auto-trigger y comparador analogico.
 * ADC (16 bits, ADCL+ADCH) se lee directo con avr/io.h.
 */
typedef struct {
    unsigned char mux0  : 1;
    unsigned char mux1  : 1;
    unsigned char mux2  : 1;
    unsigned char mux3  : 1;
    unsigned char mux4  : 1;
    unsigned char adlar : 1;
    unsigned char refs0 : 1;
    unsigned char refs1 : 1;
} ADMUX_bits_t;

typedef struct {
    unsigned char adps0 : 1;
    unsigned char adps1 : 1;
    unsigned char adps2 : 1;
    unsigned char adie  : 1;
    unsigned char adif  : 1;
    unsigned char adate : 1;
    unsigned char adsc  : 1;
    unsigned char aden  : 1;
} ADCSRA_bits_t;

typedef struct {
    unsigned char adts0 : 1;
    unsigned char adts1 : 1;
    unsigned char adts2 : 1;
    unsigned char        : 3;
    unsigned char acme  : 1;
    unsigned char        : 1;
} ADCSRB_bits_t;

#define ADMUX_bits  (*(volatile ADMUX_bits_t  *)_SFR_MEM_ADDR(ADMUX))
#define ADCSRA_bits (*(volatile ADCSRA_bits_t *)_SFR_MEM_ADDR(ADCSRA))
#define ADCSRB_bits (*(volatile ADCSRB_bits_t *)_SFR_MEM_ADDR(ADCSRB))

/* ==================== SPI ====================
 * SPCR : habilitacion, modo maestro/esclavo, polaridad/fase de reloj y velocidad.
 * SPSR : bandera de interrupcion, colision de escritura y doble velocidad.
 * SPDR (dato de 8 bits) se maneja directo con avr/io.h.
 */
typedef struct {
    unsigned char spr0 : 1;
    unsigned char spr1 : 1;
    unsigned char cpha : 1;
    unsigned char cpol : 1;
    unsigned char mstr : 1;
    unsigned char dord : 1;
    unsigned char spe  : 1;
    unsigned char spie : 1;
} SPCR_bits_t;

typedef struct {
    unsigned char spi2x : 1;
    unsigned char        : 5;
    unsigned char wcol  : 1;
    unsigned char spif  : 1;
} SPSR_bits_t;

#define SPCR_bits (*(volatile SPCR_bits_t *)_SFR_MEM_ADDR(SPCR))
#define SPSR_bits (*(volatile SPSR_bits_t *)_SFR_MEM_ADDR(SPSR))
#define SPDR_bits SFR_BIT8(SPDR)

/* ==================== TWI (I2C) ====================
 * TWCR : habilitacion, condiciones START/STOP, ACK e interrupcion.
 * TWSR : codigo de estado (TWS) y prescaler.
 * TWDR (dato) y TWBR (bit-rate) se manejan directo con avr/io.h.
 * TWAR (direccion propia como esclavo) tampoco requiere bit-field aqui.
 */
typedef struct {
    unsigned char twie  : 1;
    unsigned char        : 1;
    unsigned char twen  : 1;
    unsigned char twwc  : 1;
    unsigned char twsto : 1;
    unsigned char twsta : 1;
    unsigned char twea  : 1;
    unsigned char twint : 1;
} TWCR_bits_t;

typedef struct {
    unsigned char twps0 : 1;
    unsigned char twps1 : 1;
    unsigned char        : 1;
    unsigned char tws3  : 1;
    unsigned char tws4  : 1;
    unsigned char tws5  : 1;
    unsigned char tws6  : 1;
    unsigned char tws7  : 1;
} TWSR_bits_t;

#define TWCR_bits (*(volatile TWCR_bits_t *)_SFR_MEM_ADDR(TWCR))
#define TWSR_bits (*(volatile TWSR_bits_t *)_SFR_MEM_ADDR(TWSR))

/* ==================== TIMER 0 ====================
 * PWM: OC0A = PB3, OC0B = PB4.
 * Fast PWM (WGM01:00 = 11) + COM0A/COM0B = 10 (no invertido) generan PWM
 * en OC0A/OC0B usando OCR0A_bits/OCR0B_bits como ciclo de trabajo (0-255).
 */
typedef struct {
    unsigned char wgm00  : 1;
    unsigned char wgm01  : 1;
    unsigned char        : 2;
    unsigned char com0b0 : 1;
    unsigned char com0b1 : 1;
    unsigned char com0a0 : 1;
    unsigned char com0a1 : 1;
} TCCR0A_bits_t;

typedef struct {
    unsigned char cs00   : 1;
    unsigned char cs01   : 1;
    unsigned char cs02   : 1;
    unsigned char wgm02  : 1;
    unsigned char        : 2;
    unsigned char foc0b  : 1;
    unsigned char foc0a  : 1;
} TCCR0B_bits_t;

#define TCCR0A_bits (*(volatile TCCR0A_bits_t *)_SFR_MEM_ADDR(TCCR0A))
#define TCCR0B_bits (*(volatile TCCR0B_bits_t *)_SFR_MEM_ADDR(TCCR0B))
#define TCNT0_bits  SFR_BIT8(TCNT0)
#define OCR0A_bits  SFR_BIT8(OCR0A)
#define OCR0B_bits  SFR_BIT8(OCR0B)

/* ==================== TIMER 1 ====================
 * PWM: OC1A = PD5, OC1B = PD4.
 * TCNT1, OCR1A, OCR1B e ICR1 son registros de 16 bits (se acceden directo
 * con avr/io.h, ej. OCR1A = valor, sin necesidad de bit-field).
 * Fast PWM 8 bits: WGM10=1 (TCCR1A_bits) y WGM12=1 (TCCR1B_bits),
 * COM1A/COM1B = 10 para salida no invertida.
 */
typedef struct {
    unsigned char wgm10  : 1;
    unsigned char wgm11  : 1;
    unsigned char        : 2;
    unsigned char com1b0 : 1;
    unsigned char com1b1 : 1;
    unsigned char com1a0 : 1;
    unsigned char com1a1 : 1;
} TCCR1A_bits_t;

typedef struct {
    unsigned char cs10   : 1;
    unsigned char cs11   : 1;
    unsigned char cs12   : 1;
    unsigned char wgm12  : 1;
    unsigned char wgm13  : 1;
    unsigned char        : 1;
    unsigned char ices1  : 1;
    unsigned char icnc1  : 1;
} TCCR1B_bits_t;

typedef struct {
    unsigned char        : 6;
    unsigned char foc1b  : 1;
    unsigned char foc1a  : 1;
} TCCR1C_bits_t;

#define TCCR1A_bits (*(volatile TCCR1A_bits_t *)_SFR_MEM_ADDR(TCCR1A))
#define TCCR1B_bits (*(volatile TCCR1B_bits_t *)_SFR_MEM_ADDR(TCCR1B))
#define TCCR1C_bits (*(volatile TCCR1C_bits_t *)_SFR_MEM_ADDR(TCCR1C))

/* ==================== TIMER 2 ====================
 * PWM: OC2A = PD7, OC2B = PD6.
 * Puede usar reloj asincrono externo en TOSC1/PC6 y TOSC2/PC7.
 * Fast PWM (WGM21:20 = 11) + COM2A/COM2B = 10 igual que Timer0.
 */
typedef struct {
    unsigned char wgm20  : 1;
    unsigned char wgm21  : 1;
    unsigned char        : 2;
    unsigned char com2b0 : 1;
    unsigned char com2b1 : 1;
    unsigned char com2a0 : 1;
    unsigned char com2a1 : 1;
} TCCR2A_bits_t;

typedef struct {
    unsigned char cs20   : 1;
    unsigned char cs21   : 1;
    unsigned char cs22   : 1;
    unsigned char wgm22  : 1;
    unsigned char        : 2;
    unsigned char foc2b  : 1;
    unsigned char foc2a  : 1;
} TCCR2B_bits_t;

typedef struct {
    unsigned char tcr2bub : 1;
    unsigned char tcr2aub : 1;
    unsigned char ocr2bub : 1;
    unsigned char ocr2aub : 1;
    unsigned char tcn2ub  : 1;
    unsigned char as2     : 1;
    unsigned char exclk   : 1;
    unsigned char         : 1;
} ASSR_bits_t;

#define TCCR2A_bits (*(volatile TCCR2A_bits_t *)_SFR_MEM_ADDR(TCCR2A))
#define TCCR2B_bits (*(volatile TCCR2B_bits_t *)_SFR_MEM_ADDR(TCCR2B))
#define TCNT2_bits  SFR_BIT8(TCNT2)
#define OCR2A_bits  SFR_BIT8(OCR2A)
#define OCR2B_bits  SFR_BIT8(OCR2B)
#define ASSR_bits   (*(volatile ASSR_bits_t *)_SFR_MEM_ADDR(ASSR))

/* ==================== TIMER 3 ====================
 * PWM: OC3A = PB6, OC3B = PB7.
 * TCNT3, OCR3A, OCR3B e ICR3 son registros de 16 bits.
 */
typedef struct {
    unsigned char wgm30  : 1;
    unsigned char wgm31  : 1;
    unsigned char        : 2;
    unsigned char com3b0 : 1;
    unsigned char com3b1 : 1;
    unsigned char com3a0 : 1;
    unsigned char com3a1 : 1;
} TCCR3A_bits_t;

typedef struct {
    unsigned char cs30   : 1;
    unsigned char cs31   : 1;
    unsigned char cs32   : 1;
    unsigned char wgm32  : 1;
    unsigned char wgm33  : 1;
    unsigned char        : 1;
    unsigned char ices3  : 1;
    unsigned char icnc3  : 1;
} TCCR3B_bits_t;

typedef struct {
    unsigned char        : 6;
    unsigned char foc3b  : 1;
    unsigned char foc3a  : 1;
} TCCR3C_bits_t;

#define TCCR3A_bits (*(volatile TCCR3A_bits_t *)_SFR_MEM_ADDR(TCCR3A))
#define TCCR3B_bits (*(volatile TCCR3B_bits_t *)_SFR_MEM_ADDR(TCCR3B))
#define TCCR3C_bits (*(volatile TCCR3C_bits_t *)_SFR_MEM_ADDR(TCCR3C))

/* ================= INTERRUPCIONES DE TIMERS =================
 * TIMSKx habilita interrupciones. TIFRx contiene banderas; las banderas
 * se limpian escribiendo un 1, no un 0.
 */
typedef struct {
    unsigned char toie   : 1;
    unsigned char ociea  : 1;
    unsigned char ocieb  : 1;
    unsigned char        : 5;
} TIMSK_8bits_t;

typedef struct {
    unsigned char tov    : 1;
    unsigned char ocfa   : 1;
    unsigned char ocfb   : 1;
    unsigned char        : 5;
} TIFR_8bits_t;

typedef struct {
    unsigned char toie1  : 1;
    unsigned char ocie1a : 1;
    unsigned char ocie1b : 1;
    unsigned char        : 2;
    unsigned char icie1  : 1;
    unsigned char        : 2;
} TIMSK1_bits_t;

typedef struct {
    unsigned char tov1   : 1;
    unsigned char ocf1a  : 1;
    unsigned char ocf1b  : 1;
    unsigned char        : 2;
    unsigned char icf1   : 1;
    unsigned char        : 2;
} TIFR1_bits_t;

typedef struct {
    unsigned char toie3  : 1;
    unsigned char ocie3a : 1;
    unsigned char ocie3b : 1;
    unsigned char        : 2;
    unsigned char icie3  : 1;
    unsigned char        : 2;
} TIMSK3_bits_t;

typedef struct {
    unsigned char tov3   : 1;
    unsigned char ocf3a  : 1;
    unsigned char ocf3b  : 1;
    unsigned char        : 2;
    unsigned char icf3   : 1;
    unsigned char        : 2;
} TIFR3_bits_t;

#define TIMSK0_bits (*(volatile TIMSK_8bits_t *)_SFR_MEM_ADDR(TIMSK0))
#define TIFR0_bits  (*(volatile TIFR_8bits_t  *)_SFR_MEM_ADDR(TIFR0))
#define TIMSK1_bits (*(volatile TIMSK1_bits_t  *)_SFR_MEM_ADDR(TIMSK1))
#define TIFR1_bits  (*(volatile TIFR1_bits_t   *)_SFR_MEM_ADDR(TIFR1))
#define TIMSK2_bits (*(volatile TIMSK_8bits_t *)_SFR_MEM_ADDR(TIMSK2))
#define TIFR2_bits  (*(volatile TIFR_8bits_t  *)_SFR_MEM_ADDR(TIFR2))
#define TIMSK3_bits (*(volatile TIMSK3_bits_t  *)_SFR_MEM_ADDR(TIMSK3))
#define TIFR3_bits  (*(volatile TIFR3_bits_t   *)_SFR_MEM_ADDR(TIFR3))

/* ================= CONTROL GLOBAL DE TIMERS ================= */
typedef struct {
    unsigned char psrsync : 1;
    unsigned char psrasy  : 1;
    unsigned char         : 5;
    unsigned char tsm     : 1;
} GTCCR_bits_t;

typedef struct {
    unsigned char pradc    : 1;
    unsigned char prusart0 : 1;
    unsigned char prspi     : 1;
    unsigned char prtim1    : 1;
    unsigned char prusart1 : 1;
    unsigned char prtim0    : 1;
    unsigned char prtim2    : 1;
    unsigned char prtwi     : 1;
} PRR0_bits_t;

typedef struct {
    unsigned char prtim3 : 1;
    unsigned char        : 7;
} PRR1_bits_t;

#define GTCCR_bits (*(volatile GTCCR_bits_t *)_SFR_MEM_ADDR(GTCCR))
#define PRR0_bits  (*(volatile PRR0_bits_t  *)_SFR_MEM_ADDR(PRR0))
#define PRR1_bits  (*(volatile PRR1_bits_t  *)_SFR_MEM_ADDR(PRR1))

#endif





#endif /* BITSFIELD_H_ */