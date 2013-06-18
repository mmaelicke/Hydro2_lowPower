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

/*define pins*/
int DHTPIN = 4;
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);


void setup_DHT(){
  dht.begin();
}

float get_temperature(){
  float t = dht.readTemperature();
  return t;
}

float get_humidity(){
  float h = dht.readHumidity();
  return h;
}
