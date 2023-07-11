/*
 * ESP32 DevkitC で Stack-chan を作りたかった。
 * そのために M5GFX で市販の廉価で小さい SSD1306 I2C 128x64 (0.96inch) OLED を使いたかったが
 * 何故か I2C の SSD1306 を M5GFX で使うための情報が見つからないので
 * M5GFX の M5UnitGLASS , M5UnitOLED 等を参考に作ってみた。
 * M5_GENERIC_SSD1306.h を include すれば使えるようになるはず。
 * しかし、多分まだ不完全
 * 
 * 以下、使い方のイメージ
 */

//--------------------------------

#include "M5_GENERIC_SSD1306.h"

M5_GENERIC_SSD1306 display; 

void setup(void){

  display.init();
  
  display.setTextSize(1.2);
  
  display.drawString("Hello, World!", 0, 20); 
}

void loop(void)
{

}
