
#include <xc.h>
#include "adc.h"
void init_adc(void)
{
    /* Selecting Right Justification */
    ADFM = 1;
    
    /* Starting the ADC Module */
    ADON = 1;
}

unsigned short read_adc(unsigned char channel)
{
    unsigned short adc_reg_val; // 2bytes
    
    /* Start the ADC conversion */
    GO = 1;
    
    ADCON0 = (ADCON0 & 0xC7) | (channel << 3);
    /* Wait for the conversion to complete */
    while (nDONE); //nDONE = 0 GO = 0
    
   
    adc_reg_val = (ADRESH << 8) | ADRESL; 
    
    return adc_reg_val; // 0 to 1023
    
}
