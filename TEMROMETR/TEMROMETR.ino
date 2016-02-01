//PinOut 
//From LCD to Arduino 
//VCC to 3.3v (better contrast) 
//GND to GND
//SCE to 11
//RST to 12
//D/C to 10
//SCLK to 9
//Led to VCC
//TEMP to Arduino 
//Vcc to Vcc 
//GND to GND
//Sensor to 7



#include <OneWire.h>
#include <DallasTemperature.h>
#include <LCD5110_Graph.h>

#define ONE_WIRE_BUS 7

LCD5110 lcd(8,9,10,12,11);

extern unsigned char SmallFont[];
extern unsigned char BigNumbers[];
extern uint8_t temperatureIcon[];

char temperatureF[6];

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float tempC = 0;
float tempF = 0;

void setup(void)
{
  lcd.InitLCD();
  lcd.setFont(BigNumbers);
  sensors.begin();
}

void loop(void)
{ 

  lcd.clrScr();

  
  sensors.requestTemperatures();
  
  tempC = sensors.getTempCByIndex(0);
  tempF = sensors.toFahrenheit(tempC);
  
  //convertToString(tempF);
  
  convertToString(tempC);  //Uncomment this for degrees Celsius
 
  lcd.print(temperatureF,25,11);
  
  lcd.update();  
  delay(60);
}

void convertToString(float number)
{
   dtostrf(number, 3, 1, temperatureF);
}


