/*
 * ESP32 DevkitC で Stack-chan を作りたくて
 * M5GFX で市販の廉価で小さい SSD1306 I2C 128x64 (0.96inch) OLED を使おうとしたのですが
 * 何故か I2C の SSD1306 を M5GFX で使うための情報が見つからないので
 * M5GFX の M5UnitGLASS , M5UnitOLED 等を参考に作ってみました。
 * M5_GENERIC_SSD1306.h を include すれば使えるようになるはず。
 * 多分まだ不完全。
 * 
 * SDA、SCL の pin は codeを見てもらえばわかりますが
 *　#define GENERIC_SSD1306_SDA 21
 * や
 *  setup(sda,scl,freq ...)
 *
 *  等で変更できます。 
 * 　
 * 
 * 以下、使い方のイメージ
 */

//--------------------------------

#include "SSD1306_WITH_M5GFX.h"

SSD1306_WITH_M5GFX display; 

void setup(void){

  display.init();
  
  display.setTextSize(1.2);

}

void loop(void)
{
  display.clear();

  display.setRotation(2);

  display.drawString("Hello, World!", 0, 20); 

  delay(3000);
 
  display.clear();
 
  display.setRotation(3);

  display.drawString("Hello, World!", 0, 20); 

  delay(3000);

  display.clear();
 
  display.setRotation(0);

  display.drawString("Hello, World!", 0, 20); 

  delay(3000);

  display.clear();
  
  display.setRotation(1);

  display.drawString("Hello, World!", 0, 20); 

  delay(3000);
}
