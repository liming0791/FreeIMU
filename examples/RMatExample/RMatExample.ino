#include <Wire.h>
#include <FreeSixIMU.h>

FreeSixIMU imu;

void setup() {
  imu.init();
  Serial.begin(9600);
}

void loop() {
  
  float R[9];
  //float q[4];
  //  
  //imu.getYawPitchRoll(angles);  
  //imu.getQ(q);
  imu.getRMat(R);

  //float y = -angles[0]/180*PI;
  //float p = -angles[1]/180*PI;
  //float r = -angles[2]/180*PI;

  //float sy = sin(y), cy = cos(y),
  //      sp = sin(p), cp = cos(p),
  //      sr = sin(r), cr = cos(r);

  //float m00=cp*cy,          m01=cp*sy,          m02=-sp,
  //      m10=sr*sp*cy-cr*sy, m11=sr*sp*sy+cr*cy, m12=sr*cp,
  //      m20=cr*sp*cy+sr*sy, m21=cr*sp*sy-sr*cy, m22=cr*cp;

  Serial.print(R[0]);
  Serial.print(" ");
  Serial.print(R[1]);
  Serial.print(" ");
  Serial.print(R[2]);
  Serial.print(" ");
  Serial.print(R[3]);
  Serial.print(" ");
  Serial.print(R[4]);
  Serial.print(" ");
  Serial.print(R[5]);
  Serial.print(" ");
  Serial.print(R[6]);
  Serial.print(" ");
  Serial.print(R[7]);
  Serial.print(" ");
  Serial.println(R[8]);
  
  //Serial.print(-angles[0]);   //yaw
  //Serial.print(",\t");
  //Serial.print(-angles[1]);  //pitch
  //Serial.print(",\t");
  //Serial.println(-angles[2]);  //roll


  // Serial.print(q[0]);   
  // Serial.print(",\t");
  // Serial.print(q[1]);  
  // Serial.print(",\t");
  // Serial.print(q[2]); 
  // Serial.print(",\t");
  // Serial.println(q[3]);  

}
