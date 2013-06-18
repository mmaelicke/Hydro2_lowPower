/* This file is part of HydroStation Package
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
 */
 
void printSerialData(){

  Serial.println();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);  
  
  /* DHT22 Values */
  Serial.print("Temperature: ");
  Serial.print(Data[0]);
  Serial.print(" *C\t");
  Serial.print("Humidity: ");
  Serial.print(Data[1]);
  Serial.println(" %");
  
  /* BMP085 Values */
  float pressurehPa = Data[2] / 100;
  float atm = Data[2] / 101325; // standart atmosphere
  Serial.print("Pressure: ");
  Serial.print(pressurehPa, 1);
  Serial.print(" hPa (");
  Serial.print(Data[2], 0);
  Serial.print(" Pa) ");
  Serial.print("Standard Atmosphere: ");
  Serial.println(atm, 4); 
  
  /* Distance Values */
  Serial.print("Distance on Pin ");
  Serial.print(UltraSonicPin);
  Serial.write(": ");
  Serial.print(Data[3]);
  Serial.println(" cm");
  
  /* Weight MEasurement */
  if (LoadCellConnection1){
    //LoadCell is connected
    Serial.print("Weight on Pin ");
    Serial.print(LoadCellPin1);
    Serial.print(":");
    Serial.print(Data[4]);
    Serial.println(" g");
  }
  if (LoadCellConnection2){
    //LoadCell is connected
    Serial.print("Weight on Pin ");
    Serial.print(LoadCellPin1);
    Serial.print(":");
    Serial.print(Data[5]);
    Serial.println(" g");
  }  
}
