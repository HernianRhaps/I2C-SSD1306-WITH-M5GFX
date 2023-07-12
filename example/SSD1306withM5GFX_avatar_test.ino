#include "M5Unified.h"
#include <Avatar.h>
#include "I2C_SSD1306_WITH_M5GFX.h"

using namespace m5avatar;

Avatar avatar;

I2C_SSD1306_WITH_M5GFX display; 

void setup(void){

  Serial.begin(115200);

  display.init();

  display.setTextSize(1);
  display.drawString("Test execute", 0, 10);
  display.drawString("Wait 10sec", 0, 25);

  delay(1000);

  display.setTextSize(2);

  for(long i = 9 ; i>=0 ; i-- ){
    
    display.drawNumber( i , 64, 45);

    delay(1000);
  }


  auto board=M5.getBoard();
  Serial.print("M5.getBoard()");
 
  if(lgfx::boards::board_M5Atom==board)
    Serial.println("board_M5Atom");
  else if(lgfx::boards::board_unknown==board)
    Serial.println("board_unknown");

  Serial.print("M5.getDisplayCount()");
  Serial.println(M5.getDisplayCount());

  Serial.print("M5.addDisplay(display)");
  Serial.println(M5.addDisplay(display));

  Serial.print("M5.getDisplayCount()");
  Serial.println(M5.getDisplayCount());

  //delay(10000);

  // avatar
  avatar.setScale(0.35);
  avatar.setPosition(0, 25);
  avatar.init();  // start drawing

  //M5.Display.init();// M5.Display.init() doesn't work.

} 


void loop(void)
{

  // avatar's face updates in another thread
  // so no need to loop-by-loop rendering

//  if (M5.BtnA.wasClicked()) {

//  Serial.println(F("BtnA.wasClicked"));
  avatar.setExpression(Expression::Happy);

  delay(2000);

//  } else if (M5.BtnB.wasClicked()) {

//  Serial.println(F("BtnB.wasClicked"));
  avatar.setExpression(Expression::Sleepy);

  delay(2000);

//  } else if (M5.BtnC.wasClicked()) {

//  Serial.println(F("BtnC.wasClicked"));
  avatar.setExpression(Expression::Neutral);

  delay(2000);

}
