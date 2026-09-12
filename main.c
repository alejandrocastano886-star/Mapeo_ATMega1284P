#define F_CPU 8000000UL

#include "BitsField.h"

int main(void)
{
	/* PA0 como salida */
	DDRA_bits.b0 = 1;

	/* PB1 como entrada con pull-up interno */
	DDRB_bits.b1 = 0;
	PORTB_bits.b1 = 1;

	while (1)
	{
		/* Si se presiona el botón conectado a PB1 */
		if (PINB_bits.b1 == 0)
		{
			PORTA_bits.b0 = 1;  // PA0 alto
		}
		else
		{
			PORTA_bits.b0 = 0;  // PA0 bajo
		}
	}
}