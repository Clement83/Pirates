#define CHIP_SELECT 10

#include <SdFat.h>
SdFat sd;
File myFile;

#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;

byte stateGame = 0;
void setup()
{
  gb.begin();
  initSD();
  goTitleScreen();
  initMenu();
}


void loop(){

 if(gb.update())
 {
   if(gb.buttons.pressed(BTN_C)){
      goTitleScreen();
    }
    
    switch(stateGame)
    {
      case 0:
       updateMenu();
       drawMenu(); 
      break;
      
      case 1:
       updatePrevi();
       drawPrevi(); 
      break;
    }
  }
}

#define BASE_NAME "PIRATE.JC"

void initSD()
{
   if (!sd.begin(CHIP_SELECT)) {
    Serial.println(F("begin error"));
    gb.popup(F("ERROR SD"),10);
    //return;
  }
  
}

