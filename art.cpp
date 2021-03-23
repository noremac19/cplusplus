#include "turtle.h"
#include "draw.h"

int main() {
   draw::show(750);
   draw::setpenwidth(6);
   draw::setrange(-100, 100);

   Turtle turtle(-90, 0, 180);
   Turtle tortoise(-85, -15, 60);
   Turtle shell(-70, -15, 60);
   Turtle ocean(-50, -15, 60);

   turtle.setColor(draw::GREEN);
   turtle.move(10);
   tortoise.setColor(draw::ORANGE);
   tortoise.move(15);
   shell.setColor(draw::RED);
   shell.move(15);
   ocean.setColor(draw::BLUE);
    ocean.move(15);
  

   draw::show(750);

   turtle.turn(90);
   turtle.move(15);
    
   draw::show(750); 
    
   turtle.turn(90);
   turtle.move(15);

   draw::show(750);

   tortoise.turn(-120);
   tortoise.move(15);

   draw::show(750);

   shell.turn(-120);
   shell.move(15);
   
   draw::show(750);

   shell.turn(120);
   shell.move(15);

   draw::show(750);

   shell.turn(-120);
   shell.move(15);

   draw::show(750);
    
   ocean.turn(-120);
   ocean.move(15);
   ocean.turn(-165);
   ocean.move(15);
   ocean.turn(225);
   ocean.move(15);
   ocean.turn(-135);
   ocean.move(15);
    



   return 0;
}