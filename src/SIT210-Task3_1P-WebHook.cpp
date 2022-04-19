/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "f:/Particle_Projects/SIT210-Task3_1P-WebHook/src/SIT210-Task3_1P-WebHook.ino"
/*
 * Project SIT210-Task3_1P-WebHook
 * Description: 
 * Author:
 * Date:
 */
#include <BH1750.h>
void setup();
void loop();
#line 8 "f:/Particle_Projects/SIT210-Task3_1P-WebHook/src/SIT210-Task3_1P-WebHook.ino"
BH1750 sensor(0x23, Wire);
int led = D7;

SYSTEM_THREAD(ENABLED);

void setup() {
  pinMode(led, OUTPUT);
  sensor.begin();
  sensor.set_sensor_mode(BH1750::forced_mode_high_res2);
  Serial.begin();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  sensor.make_forced_measurement();
  float lightLevel = sensor.get_light_level();
  Particle.publish("lightLevel", String::format("%f", lightLevel), PRIVATE);
  Serial.println(String::format("Light Level: %f", lightLevel));
  if (lightLevel > 400) digitalWrite(led, LOW);
  else digitalWrite(led, HIGH);
  delay(10000);
}