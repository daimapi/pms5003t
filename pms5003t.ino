//UTF-8
#include <PMS.h> 
#include <SoftwareSerial.h> 

SoftwareSerial Serial1(2, 3); // 將Arduino Pin2設定為RX, Pin3設定為TX
PMS pms(Serial1);
PMS::DATA data;

void setup()
{
  Serial.begin(9600);   
  Serial1.begin(9600);//for pms
  pms.passiveMode();
}
void loop()
{
  
  if (Serial.available()>0 && Serial.read()=='1')
  {
    Serial.println("o");
    pms.wakeUp();
    delay(30000);
    pms.requestRead();
    if (pms.readUntil(data))
    {
      Serial.println(data.PM_AE_UG_1_0);
      Serial.println(data.PM_AE_UG_2_5);
      Serial.println(data.PM_AE_UG_10_0);
    }
    delay(1000);
    pms.sleep();
    Serial.println("d");
  }
}