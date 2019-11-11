#include <LiquidCrystal_I2C.h>
#include <Arduino_FreeRTOS.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

void counter_task(void *p){
  while(1){
    for(int i=0; i<=100;i++){
      lcd.setCursor(1,0);
      lcd.print("hello everyone");
      lcd.setCursor(1,1);
      lcd.print(i);
      Serial.println(i);
      
      }
    }
  }
  
void setup(){
  Serial.begin(9600);
  lcd.begin();
  // Print a message to the LCD.
  lcd.backlight();
  xTaskCreate(counter_task, "counter", 120, NULL, 1, NULL);
  } 

void loop(){
  }
