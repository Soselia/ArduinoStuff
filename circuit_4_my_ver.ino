/* Programmed By Isabella Brooks
 *  i have tried to optimize the code so there are alot of chars and lessser byte variables since arduino has low storage
 *  this is my first run at optimization and the exercise was more about repetition and commenting anyways
 *  the program just runs through a couple different led modes
 */

//an array that holds all the pins for easy initialization
byte Pins[] = {2,3,4,5,6,7,8,9};
void setup() {
 // just runs 0 - 7 to initialize all the pins according to their array location
 for (char i=0;i<=7;i++)
 {
  Serial.begin(9600);
  pinMode(Pins[i],OUTPUT); 
  //digitalWrite(Pins[i],HIGH);
 }
}

void loop() {
 /* five sperate types of light movement. scroll right. scroll right bounce back. light one at a time scroll right. the two at a time  4 apart. and the random led 
  *  implement all through seperate methods then call a random switch case to play them all at random intervals
  *  more specifics will be given with actual code
  */
 ScrollRight();
 Bounce();
 ScrollOne();
 OneBounce();
 Marquee();
 MarqueeBounce();
 RandomLED();
}
 
 void ScrollRight()
   {
    // just uses a for loop to run through the array lgihting them up til they are all lit
      for (char i=0;i<=7;i++)
      {
        digitalWrite(Pins[i],HIGH);
        delay(200);  
      } 
      // turns them all off for the next function to run. no delay so its seamless
        for (char i=0;i<=7;i++)
      {
        digitalWrite(Pins[i],LOW);  
      } 
   }
 void Bounce()
 {
  // lights them all up then turns them all off in oppisite order
  //same thing as last time but with a delay on the turn off loop so its visible
    for (char i=0;i<=7;i++)
    {
       digitalWrite(Pins[i],HIGH);
       delay(200);
    }
    for (char i=7;i>=0;i--)
    {
       digitalWrite(Pins[i],LOW);
       delay(200);
    }
 }
 void ScrollOne()
 {
   //turns the led on then waits and turns it off and keerps going to give it a one at a time scrolling effect
    for(char i=0;i<=7;i++)
    {
      digitalWrite(Pins[i],HIGH);
      delay(200);
      digitalWrite(Pins[i],LOW);
    }
 }
  void OneBounce()
  {
    //same as last, but when it hits the led at pin 9 it reverses direction
    for (char i = 0; i<=7;i++)
    {
      digitalWrite(Pins[i],HIGH);
      delay(200);  
      digitalWrite(Pins[i],LOW);
    }
        for (char i=7;i>=0;i--)
    {
      digitalWrite(Pins[i],HIGH);
      delay(200);  
      digitalWrite(Pins[i],LOW);
    }
  }
  void Marquee()
  {
    //no good way to explain this other then presentation. lights up one led and one 4 over from it.
    for (char i=0;i<=3;i++)
    {
    digitalWrite(Pins[i],HIGH);
    digitalWrite(Pins[i+4],HIGH);
    delay(200);
    digitalWrite(Pins[i],LOW);
    digitalWrite(Pins[i+4],LOW);  
    }
  }
  void MarqueeBounce()
  {
    //ditto on lastbut bounces back at the end
    for(char i=0; i<=3;i++)
    {
      digitalWrite(Pins[i],HIGH);
      digitalWrite(Pins[i+4],HIGH);
      delay(200);
      digitalWrite(Pins[i],LOW);
      digitalWrite(Pins[i+4],LOW);
    }
    for(char i=7;i>=4;i--)
    {
      digitalWrite(Pins[i],HIGH);
      digitalWrite(Pins[i-4],HIGH);
      delay(200);
      digitalWrite(Pins[i],LOW);
      digitalWrite(Pins[i-4],LOW);   
    }
  }
   void RandomLED()
    {
      // just lights a random led
      char RL=random(8);
      digitalWrite(Pins[RL],HIGH);
      delay(200);
      digitalWrite(Pins[RL],LOW);  
    }
