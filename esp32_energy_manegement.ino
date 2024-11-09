#include <LiquidCrystal_I2C_Hangul.h> 
LiquidCrystal_I2C_Hangul lcd(0x27,16,2)
const int Relay_LED = 4;    
const int LDR_sensor = 13;
void setup() 
{
  // put your setup code here, to run once:

  delay(500);
  pinMode(LDR_sensor,INPUT);
  pinMode(Relay_LED, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  delay(500);

  lcd.setCursor(0,0);
  lcd.print(" SMRT NRG  MGMT ");
  lcd.setCursor(0,1);
  lcd.print("     SYSTEM     ");
  delay(1000);

  digitalWrite(Relay_LED, HIGH);
  delay(1000);
  digitalWrite(Relay_LED, LOW);
  delay(500);


  lcd.clear();
  delay(500);

}

void loop() 
{
 

  // put your main code here, to run repeatedly:
if(digitalRead(LDR_sensor) == HIGH)
{
  digitalWrite(Relay_LED, HIGH);
  delay(500);

  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("LIGHT TURNED ON ");
  delay(500);
}
else
{
  digitalWrite(Relay_LED, LOW);
  delay(500);

  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("LIGHT TURNED OFF");
  delay(500);
}

}