/*
FreeSixIMU.cpp - A libre and easy to use orientation sensing library for Arduino
Copyright (C) 2011 Fabio Varesano <fabio at varesano dot net>

Development of this code has been supported by the Department of Computer Science,
Universita' degli Studi di Torino, Italy within the Piemonte Project
http://www.piemonte.di.unito.it/


This program is free software: you can redistribute it and/or modify
it under the terms of the version 3 GNU General Public License as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <inttypes.h>
//#define DEBUG
#include "FreeSixIMU.h"
// #include "WireUtils.h"
//#include "DebugUtils.h"


FreeSixIMU::FreeSixIMU() {
	acc = ADXL345();
	gyro = ITG3200();
	magn = HMC58X3();
}

void FreeSixIMU::init() {
  init(FIMU_ACC_ADDR, FIMU_ITG3200_DEF_ADDR, false);
}

void FreeSixIMU::init(bool fastmode) {
  init(FIMU_ACC_ADDR, FIMU_ITG3200_DEF_ADDR, fastmode);
}

void FreeSixIMU::init(int acc_addr, int gyro_addr, bool fastmode) {
  delay(5);

#ifdef __AVR__
  
  // disable internal pullups of the ATMEGA which Wire enable by default
  #if defined(__AVR_ATmega168__) || defined(__AVR_ATmega8__) || defined(__AVR_ATmega328P__)
    // deactivate internal pull-ups for twi
    // as per note from atmega8 manual pg167
    cbi(PORTC, 4);
    cbi(PORTC, 5);
  #else
    // deactivate internal pull-ups for twi
    // as per note from atmega128 manual pg204
    cbi(PORTD, 0);
    cbi(PORTD, 1);
  #endif
  
  if(fastmode) { // switch to 400KHz I2C - eheheh
    TWBR = ((16000000L / 400000L) - 16) / 2; // see twi_init in Wire/utility/twi.c
    // TODO: make the above usable also for 8MHz arduinos..
  }

#else // Due
  Wire.begin();
#endif
    // init ADXL345
  acc.init(acc_addr);
	

  // init ITG3200
  gyro.init(gyro_addr);
  delay(1000);
  // calibrate the ITG3200
  gyro.zeroCalibrate(128,5);
  
  // init HMC5843
  magn.init(false); // Don't set mode yet, we'll do that later on.
  // Calibrate HMC using self test, not recommended to change the gain after calibration.
  magn.calibrate(1); // Use gain 1=default, valid 0-7, 7 not recommended.
  // Single mode conversion was used in calibration, now set continuous mode
  magn.setMode(0);
  //delay(10);
  magn.setDOR(B110);
  
}


void FreeSixIMU::getRawValues(short * raw_values) {
  acc.readAccel(&raw_values[0], &raw_values[1], &raw_values[2]);
  gyro.readGyroRaw(&raw_values[3], &raw_values[4], &raw_values[5]);
  magn.getValues(&raw_values[6], &raw_values[7], &raw_values[8]);
  
}


void FreeSixIMU::getValues(float * values) {  
  short accval[3];
  acc.readAccel(&accval[0], &accval[1], &accval[2]);
  values[0] = ((float) accval[0]);
  values[1] = ((float) accval[1]);
  values[2] = ((float) accval[2]);
  
  gyro.readGyro(&values[3]);
  
  magn.getValues(&values[6]);
}

