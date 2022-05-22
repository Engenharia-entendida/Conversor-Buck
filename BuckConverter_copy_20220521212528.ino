//Conversor Buck 12v-5V / 700mA
//Eng. Danuzio Alves / Engenharia entendida

#include <PWM.h>                          //Biblioteca para o pwm   
#define pwm0 10                           //Pino de saída do pwm
int32_t frequency = 30000;                //Frequência em Hertz
int Duty0 = 532;                          //Variável que armazena o valor do Duty Cycle inicial
int Duty1 =0;                             //Variável que armazena o valor do Duty Cycle final      
int FeedBack = 0;                         //Variável que armazena o valor de feedback
//===================Setup===========================================================================================================================================//
void setup() {
InitTimersSafe();                         //Configura os registadores do Atmega para uma frequência maior
SetPinFrequencySafe(pwm0, frequency);     //Configura a frequência no pino de saída
}
//===================Loop============================================================================================================================================//
void loop() { 
FeedBack=analogRead(A5);                  //Lê o valor de feedback
if(FeedBack<590){                         //Se valor estiver abaixo do 5V...
  Duty0++;                                //Aumenta o Duty Cycle
  }
if(FeedBack>600){                         //Se valor estiver acima do 5V...
  Duty0--;                                //Dimunui o Duty Cycle
  }
Duty1=map(Duty0,0,1023,0,255);            //Transforma o dados de 10 bits para 8 bits
pwmWrite(pwm0,Duty1);                     //Envia o valor para o pino pwm
}


