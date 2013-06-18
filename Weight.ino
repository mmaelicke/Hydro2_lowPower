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
 
float get_loadweight(int pin, float tara, float weight, float loada){
  /* get the load and print it to serial monitor.
   * as enabled (in future version) start conversion of weight
   * to mm or d mm/dt 
   */
  float load = getLoad(pin);

  //conversion from load to weight:
  float value = (load - tara) * (weight - 0) / (loada - tara) + 0;

  //print value to global result array
  return value;
}

float getLoad( int pin){
  /* one load measurement is done by 1000 single measurements
   * afterwards the result is smoothed
   */
   
  float average = 0;
  for (int i = 0; i < 1000; i++){
    int value = analogRead(pin);
    average = 0.99 * average + 0.01 * value;
  }
  return average;
}

