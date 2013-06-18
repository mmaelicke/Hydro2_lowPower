/* Hydro2_lowPower Arduino - Sketch
 * Main sketch to run HydroStation hydrological measuring device
 * Upload to your Arduino - based Station
 * More information under http:openhydro.org
 *
 * This file is part of HydroStation Package
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * author: Mirko Maelicke
 *
 * This software includes several other libaries or files, which may not be
 * published under GPL 3.0. All rights belong to their respective owners.
 * This applies to: "DHT.h", "LowPower.h", "RTClib.h", "SdFat.h"
 */

/*include libaries*/
#include "DHT.h"
#include "LowPower.h"
#include "RTClib.h"
#include <Wire.h>
#include <SdFat.h>

int const len = 6;
float Data[len];
/* Data[0] = Temperature; Data[1] = Humidity; Data[2] = Pressure
 * Data[3] = Distance; Data[4] = Weight 1; Data[5] = Weight 2;
 */

RTC_DS1307 RTC;
DateTime now;

int UltraSonicPin = 6;

/* Each Load Cell has to be calibrated seperately.
 * To calibrate a Load Cell, use a LoadCell_only script.
 * Note the Tara Load (taraX), the Load of any weight 
 * (loadaX)and the weight itself (weightX).
 */
int LoadCellPin1 = 0;
int LoadCellPin2 = 1;
int LoadCellConnection1 = 1;    // 0 = N.C.; 1 = Conn.
int LoadCellConnection2 = 0;    // 0 = N.C.; 1 = Conn.
 
float tara1 = 73.3;
float loada1 = 371;
float weight1 = 201.1;

float tara2 = 100.0;
float loada2 = 200.0;
float weight2  = 50.0;

long timestep = 60; //in seconds
long duration = 0;


void setup(){
  Wire.begin();
  Serial.begin(9600);
  for (int i = 0; i < len; i++){
    Data[i] = 0;
  }
  
  setup_RTC();
  setup_Sd();
  setup_DHT();
  setup_BMP();
}

void loop(){
  delay(10);
  now = RTC.now();
  Data[0] = get_temperature();
  Data[1] = get_humidity();
  Data[2] = get_pressure();
  Data[3] = get_distance(UltraSonicPin);
  Data[4] = get_loadweight(LoadCellPin1, tara1, weight1, loada1);
  Data[5] = get_loadweight(LoadCellPin2, tara2, weight2, loada2);
  
  printSerialData();
  printSdData();
  
  Serial.end();
  while (duration < timestep){
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    duration += 8;
  }
  duration = 0;
  Serial.begin(9600);
}


