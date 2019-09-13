#include <OneWire.h>
#include <DallasTemperature.h>

//gpio16(D0) is for 1wire temp sensors(ds18b20)
const int oneWireBus = 16; 

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

int pin_seq[8] = {4, 5, 0, 14, 12, 15, 13,  2};
int num_array[10][8] = {  { 1,1,1,1,1,1,0 ,0},    // 0
                          { 0,1,1,0,0,0,0 ,0},    // 1
                          { 1,1,0,1,1,0,1 ,0},    // 2
                          { 1,1,1,1,0,0,1 ,0},    // 3
                          { 0,1,1,0,0,1,1 ,0},    // 4
                          { 1,0,1,1,0,1,1 ,0},    // 5
                          { 1,0,1,1,1,1,1 ,0},    // 6
                          { 1,1,1,0,0,0,0 ,0},    // 7
                          { 1,1,1,1,1,1,1 ,0},    // 8
                          { 1,1,1,1,0,1,1 ,0}};   // 9

void seg_off(){
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(0,LOW);
  digitalWrite(2,LOW);
  digitalWrite(14,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  digitalWrite(15,LOW);
}

void seg_num(int num){
  seg_off();

  switch(num){
    case 0:
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(0,HIGH);
        digitalWrite(14,HIGH);
        digitalWrite(12,HIGH);
        digitalWrite(15,HIGH);
          digitalWrite(2,HIGH);
        break;
    case 1:
        digitalWrite(5,HIGH);
        digitalWrite(0,HIGH);
          digitalWrite(2,HIGH);
        break;
    case 2:
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(13,HIGH);
        digitalWrite(12,HIGH);
        digitalWrite(14,HIGH);
          digitalWrite(2,HIGH);
        break;
    case 3:
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(13,HIGH);
        digitalWrite(0,HIGH);
        digitalWrite(14,HIGH);
          digitalWrite(2,HIGH);
        break;
    case 4:
        digitalWrite(15,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(13,HIGH);
        digitalWrite(0,HIGH);
          digitalWrite(2,HIGH);
        break;
    case 5:
        digitalWrite(4,HIGH);
        digitalWrite(15,HIGH);
        digitalWrite(13,HIGH);
        digitalWrite(0,HIGH);
        digitalWrite(14,HIGH);
          digitalWrite(2,HIGH);
        break;
    case 6:
        digitalWrite(4,HIGH);
        digitalWrite(15,HIGH);
        digitalWrite(13,HIGH);
        digitalWrite(0,HIGH);
        digitalWrite(12,HIGH);
        digitalWrite(14,HIGH);
          digitalWrite(2,HIGH);
        break;
    case 7:
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(0,HIGH);
          digitalWrite(2,HIGH);
        break;
    case 8:
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(0,HIGH);
        digitalWrite(14,HIGH);
        digitalWrite(12,HIGH);
        digitalWrite(13,HIGH);
        digitalWrite(15,HIGH);
          digitalWrite(2,HIGH);
        break;
    case 9:
        digitalWrite(4,HIGH);
        digitalWrite(15,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(0,HIGH);
        digitalWrite(14,HIGH);
        digitalWrite(13,HIGH);
          digitalWrite(2,HIGH);
        break;
    default:
        seg_off();
        digitalWrite(2,HIGH); // point
  }
 
}

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);
  Serial.println("Setup section");
  // Start the DS18B20 sensor
  sensors.begin();

  // определить режимы работы выводов
  pinMode(5,OUTPUT);  //D1
  pinMode(4,OUTPUT);  //D2
  pinMode(0,OUTPUT);  //D3
  pinMode(2,OUTPUT);  //D4
  pinMode(14,OUTPUT); //D5
  pinMode(12,OUTPUT); //D6
  pinMode(13,OUTPUT); //D7
  pinMode(15,OUTPUT); //D8

  seg_num(0);
}


void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  Serial.print(temperatureC);
  Serial.println("ºC");

  for(int i = 0; i < 10; i++){
    seg_num(i);
    delay(500);
  }
  delay(5000);
}
