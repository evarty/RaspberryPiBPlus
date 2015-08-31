#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define PWMPin 7

main(void){
 
  wiringPiSetup(); 
  int Success = 1;
  Success = softPwmCreate(PWMPin, 0, 100);
  if(Success){
    printf("PWM initialization failed. Please restart program\n");
    return 0;
  }
  int DutyCycle = 0;

  while(1){

    printf("Enter duty cycle: ");
    scanf("%i", &DutyCycle);
    softPwmWrite(PWMPin, DutyCycle);
    printf("PWM duty cycle is %i/100\n\n", DutyCycle);

  }
 
}
