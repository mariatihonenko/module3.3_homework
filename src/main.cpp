#include <Arduino.h>


#define POT_PIN   4  
#define LED_PIN   18  
#define MOTOR_PIN 19  


#define LED_CHANNEL    0
#define MOTOR_CHANNEL  1

#define LED_FREQ_HZ    1000  
#define MOTOR_FREQ_HZ  20000 

#define PWM_RESOLUTION 10    

void setup() {
    analogReadResolution(12);


    ledcSetup(LED_CHANNEL, LED_FREQ_HZ, PWM_RESOLUTION);
    ledcAttachPin(LED_PIN, LED_CHANNEL);

    ledcSetup(MOTOR_CHANNEL, MOTOR_FREQ_HZ, PWM_RESOLUTION);
    ledcAttachPin(MOTOR_PIN, MOTOR_CHANNEL);
}

void loop() {

    int raw_adc = analogRead(POT_PIN);


    int duty = raw_adc / 4;

    ledcWrite(LED_CHANNEL, duty);
    ledcWrite(MOTOR_CHANNEL, duty);

    delay(50); 
}