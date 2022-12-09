

/* Elaborar um progama para o kit 1611 que faça o LED
piscar indefinidamente na seguinte temporização:
1s acesso;
1s apagado;
3s acesso;
3s apagado;
*/


#include "io430.h"

#define Fclk 750e3
#define DISPLAY P5OUT 

// Protótipos
void Delay1ms();

//Funções

// Função com tempo de atraso variável em milisegundos com 
// faixa de 0 a 10.000ms (escala de tempo arbitrária)

void Delayms (int Tempo)
{  
  while (Tempo)
  {
    Delay1ms();
    Tempo--;
  }  
}


void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

// CONFIGURANDO PERIFERICOS
// Configura apenas o bit utilizado no programa
// Não altere os demais bits!  
  P1SEL = P1SEL & ~(BIT0+BIT1+BIT7);    // Altera apenas os bits 0, 1 e 7
  P1DIR = P1DIR | (BIT0+BIT1);          // Configura P1.0 e P1.1 como saída
  
  

 //Loop principal (loop infinito)
  while(1)
  {
    
  P1OUT = P1OUT | BIT0;  // Faz o P1.0 = 1
  Delayms(1000);
  
  P1OUT = P1OUT & ~BIT0;  // Faz P1.0 = 0
  Delayms(1000);
  
  P1OUT = P1OUT | BIT0;  // Faz o P1.0 = 1
  Delayms(3000);
  
  P1OUT = P1OUT & ~BIT0;  // Faz P1.0 = 0
  Delayms(3000);
  
  
  } 
}


// Função com tempmo de atraso fixo em 1ms ou seja 750 pulsos de clk
void Delay1ms()
{
 int Repete = 184;
 
 while (Repete)
   Repete--;
}


