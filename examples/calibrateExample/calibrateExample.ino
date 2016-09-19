#include <Wire.h>
#include <FreeSixIMU.h>
#include <MahonyAHRS.h>

FreeSixIMU imu;

float ax = 0, 
      ay = 0, 
      az = 0, 
      gx = 0, 
      gy = 0, 
      gz = 0;

void setup() {
  imu.init();
  Serial.begin(115200);
}

void loop() {
  
    float v[9];
    imu.getValues(v);

    ax = (ax + v[0])/2;
    ay = (ay + v[1])/2;
    az = (az + v[2])/2;

    gx = (gx + v[3])/2;
    gy = (gy + v[4])/2;
    gz = (gz + v[5])/2;

    Serial.print(ax );   
    Serial.print(",\t");
    Serial.print(ay);  
    Serial.print(",\t");
    Serial.print(az); 
    Serial.print(",\t");
    Serial.print(gx);
    Serial.print(",\t");
    Serial.print(gy);
    Serial.print(",\t");
    Serial.println(gz);

}
