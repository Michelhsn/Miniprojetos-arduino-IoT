void setup() {
    Serial.begin(9600);
}

void loop() {

    float sensor_volt;
    float RS_gas; // Get value of RS in a GAS
    float ratio; // Get ratio RS_GAS/RS_air
    int sensorValue = analogRead(A0);
    sensor_volt=(float)sensorValue/1024*5.0;
    RS_gas = (5.0-sensor_volt)/sensor_volt; // omit *RL
    float R0 = 10;
          /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
    ratio = RS_gas/R0;  // ratio = RS/R0
          /*-----------------------------------------------------------------------*/

    Serial.print("sensor_volt = ");
    Serial.println(sensor_volt);
    Serial.print("RS_ratio = ");
    Serial.println(RS_gas);
    Serial.print("Rs/R0 = ");
    Serial.println(ratio);
//função
//log(y-c) = log(a) + b*log(x)
//log((y-c)/a)/b = log(x)
float fco = log((ratio-a)/b)/c;
float x = exp(fco);



Serial.println("\n\n");
Serial.print("CO:"); 
Serial.print(fco); 
Serial.print("CH4:"); 
Serial.print(fco);
Serial.print( "ppm" ); 
Serial.print("LPG:"); 
Serial.print(fco);
Serial.print( "ppm" ); 
delay(1000);

}
