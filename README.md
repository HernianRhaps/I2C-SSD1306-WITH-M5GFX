/*
 * M5GFX で SSD1306 の I2C 128x64 (0.96inch) OLED を使えるようにしたい。
 * I2CのSSD1306のOLEDをM5GFX で使うための情報が見つからないので
 * M5GFXのM5UnitOLEDなどを参考に作ってみた。
 * 多分まだ不完全
 * 
 * 以下、使い方のイメージ
 */

//--------------------------------

#include "M5_GENERIC_SSD1306.h"

M5_GENERIC_SSD1306 display; 

void setup(void){

  display.init();
  display.setTextSize(2);
  display.setRotation(3);
  display.drawString("Hollo, world", 10, 20);
}

void loop(){

}
