#include <stdint.h>
#include <TouchScreen.h> 
#include <TFT.h>

#ifdef SEEEDUINO
#define YP A2   // must be an analog pin, use "An" notation!
#define XM A1   // must be an analog pin, use "An" notation!
#define YM 14   // can be a digital pin, this is A0
#define XP 17   // can be a digital pin, this is A3 
#endif

#ifdef MEGA
#define YP A2   // must be an analog pin, use "An" notation!
#define XM A1   // must be an analog pin, use "An" notation!
#define YM 54   // can be a digital pin, this is A0
#define XP 57   // can be a digital pin, this is A3 
#endif 

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
char xbuff[7];
char ybuff[7];
char zbuff[7];
String xval="0";
String yval="0";
String zval="0";

Point p;

void setup()
{

  Tft.init();  //init TFT library
  Tft.setDisplayDirect(UP2DOWN);
  Tft.drawString("TOUCHSCREENREPORTER",12,12,1,CYAN);
  Tft.drawString("x",60,12,5,CYAN);
  Tft.drawString("y",120,12,5,CYAN);
  Tft.drawString("z",180,12,5,CYAN);
}

void loop()
{
  p = ts.getPoint();
  xval = String(p.x);
  xval.toCharArray(xbuff,7);
  Tft.drawString(xbuff,60,50,5,YELLOW);

  p = ts.getPoint();
  yval = String(p.y);
  yval.toCharArray(ybuff,7);
  Tft.drawString(ybuff,120,50,5,RED);

  p = ts.getPoint();
  zval = String(p.z);
  zval.toCharArray(zbuff,7);
  Tft.drawString(zbuff,180,50,5,GREEN);
  delay(250);

  Tft.fillRectangle(15,48,200,150,BLACK);
}

