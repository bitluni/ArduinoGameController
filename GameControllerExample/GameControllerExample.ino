#include "GameControllers.h"

//shared pins between all controllers
const int LATCH_PIN = 16;
const int CLOCK_PIN = 17;
//individual data pin for each controller
const int DATA_PIN_0 = 18;  

GameControllers controllers;

void setup()
{
  Serial.begin(115200); //prepare serial for text output 
  
  //initialize shared pins
  controllers.init(LATCH_PIN, CLOCK_PIN); 
  //activate first controller ans set the type to SNES
  controllers.setController(0, GameControllers::SNES, DATA_PIN_0);
}

void loop()
{
  controllers.poll(); //read all controllers at once
  if(controllers.pressed(0, GameControllers::START))  //check if Start was pressed since last loop
    Serial.println("Start was pressed.");
  if(controllers.pressed(0, GameControllers::A, 20))  //if A button is hold down repeat after 20 loops
    Serial.print("A");
  if(controllers.down(0, GameControllers::B))  //check if B button it's currently pressed down
    Serial.print("B");
  delay(50);  //read controller just ~20times a second
}


