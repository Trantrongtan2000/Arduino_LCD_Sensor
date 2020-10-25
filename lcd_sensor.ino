#include <DHT.h>
#include <Wire.h>   
#include <LiquidCrystal_I2C.h>    
 int cambien = 10;
int relay = 7;
 
const int DHTPIN = 8;       //Đọc dữ liệu từ DHT11 ở chân 2 trên mạch Arduino
const int DHTTYPE = DHT11;  //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
DHT dht(DHTPIN, DHTTYPE);


int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup() {
  Serial.begin(9600);
pinMode(cambien,INPUT);
pinMode(relay,OUTPUT);
  dht.begin();    // Khởi động cảm biến
  lcd.begin();    // turn on LCD backlight                      
  lcd.backlight();
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Da khoi dong");
  lcd.setCursor(0,1);
  lcd.print("Made by Tan");
  delay(1000);
  lcd.clear();
}
 
void loop() {
  int as = digitalRead(cambien);    // Đọc cảm biến ánh sáng
  float h = dht.readHumidity();    //Đọc độ ẩm
  float t = dht.readTemperature(); //Đọc nhiệt độ

    
String nd="Nhiet do: "+ String(round(t))+"'C ";
String da="Do am: "+String(round(h))+"%";

  if (as==int(1)) {
    
    lcd.setCursor(0, 0);
    lcd.print("Troi toi");
    digitalWrite(relay,HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Relay dang bat");
    
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Troi sang");
    digitalWrite(relay,LOW);
    lcd.setCursor(0, 1);
    lcd.print("Relay dang tat");
  } 
    delay(1000);
    lcd.clear();
    
    lcd.setCursor(0, 0);       
    lcd.print(nd);
    lcd.setCursor(0, 1);    
    lcd.print(da); 
     
    delay(1000);
    lcd.clear();


}
