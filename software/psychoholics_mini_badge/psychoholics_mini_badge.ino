
/* Psychoholics Mini Badge */

#include <SoftPWM.h>

#define TURN_ON_DELAY 1500
#define TURN_OFF_DELAY 2000
#define NEXT_LED 30
#define ON_OFF_WEIGHT 190    // between 0 - 255, lower means more leds turn on
#define ON_VALUE 95
#define OFF_VALUE 5


#define NUM_LEDS 11
// int leds[] = {0,1,2,3,4,5,6,7,9,10,A0,A1,A2,A3,A4,A5};
int leds[] = {0, 1, 2, 3, 4, 5, 6, 7, 17, 18, 19};

void setup()
{
  // seed based on analog pin 7
  randomSeed(analogRead(0) + analogRead(1) + analogRead(2));

  // Initialize soft PWM
  SoftPWMBegin();

  // Setup pins
  for (int i = 0 ; i < NUM_LEDS ; i++)
  {
    SoftPWMSet(leds[i], OFF_VALUE);
    // Set fade time for pin 13 to 100 ms fade-up time, and 500 ms fade-down time
    SoftPWMSetFadeTime(leds[i], TURN_ON_DELAY, TURN_OFF_DELAY);
  }
}

void loop()
{
  // choose random LED
  uint8_t rand_num = random(NUM_LEDS);
  if (random(255) > ON_OFF_WEIGHT)
  {
    // turn a LED on
    SoftPWMSetPercent(leds[rand_num], ON_VALUE);
  }
  else
  {
    // turn a LED off
    SoftPWMSetPercent(leds[rand_num], OFF_VALUE);
  }
  delay(NEXT_LED);
}
