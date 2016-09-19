#include <Wire.h>
#include <FreeSixIMU.h>
#include <MahonyAHRS.h>

FreeSixIMU imu;

unsigned long lastTime = 0;

float q0, q1, q2, q3;

void setup() {
  q0 = 1, q1 = 0, q2 = 0, q3 = 0;
  imu.init();
  Serial.begin(115200);
}

void loop() {
  
  float v[9];
  imu.getValues(v);
  
  float freq = 1000.f / (millis() - lastTime);
  lastTime = millis();

  MahonyAHRS::updateIMU(v[3], v[4], v[5],
        v[0], v[1], v[2],
        freq,
        q0, q1, q2, q3);

  Serial.print(q0);   
  Serial.print(",\t");
  Serial.print(q1);  
  Serial.print(",\t");
  Serial.print(q2); 
  Serial.print(",\t");
  Serial.println(q3);  

}
