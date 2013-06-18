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

long get_distance(int pin){
  // a ultrasonic signal is emitted by setting pin min. 2 mics
  // to HIGH. The reflected signal is detected by the same pin.
  long duration, cm;
  //first set to LOW
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  //send signal
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin, LOW);
  
  //fetch the reflected signal
  pinMode(pin,INPUT);
  duration = pulseIn(pin, HIGH);  //the time
  
  //convert to cm
  //sound speed is 3400 m/s equals 29 microseconds/cm
  //signal traveled the distance twice
  cm = duration / 29 / 2;
  
  return cm;
}


