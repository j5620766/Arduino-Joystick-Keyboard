#include <Keyboard.h>

const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Keyboard.begin();
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(X_pin);
  int y = analogRead(Y_pin);
  x = map(x, 0, 1023, 0, 100);
  y = map(y, 0, 1023, 0, 100);
  
  if(x < 25)
  {
    if(y < 25)
    {
      Keyboard.press('w');
      Keyboard.press('a');
      Keyboard.release('s');
      Keyboard.release('d');
    }
    else if(y > 75)
    {
      Keyboard.release('w');
      Keyboard.press('a');
      Keyboard.press('s');
      Keyboard.release('d');
    }
    else
    {
      Keyboard.release('w');
      Keyboard.press('a');
      Keyboard.release('s');
      Keyboard.release('d');
    }
  }
  else if(x > 75)
  {
    if(y < 25)
    {
      Keyboard.press('w');
      Keyboard.release('a');
      Keyboard.release('s');
      Keyboard.press('d');
    }
    else if(y > 75)
    {
      Keyboard.release('w');
      Keyboard.release('a');
      Keyboard.press('s');
      Keyboard.press('d');
    }
    else
    {
      Keyboard.release('w');
      Keyboard.release('a');
      Keyboard.release('s');
      Keyboard.press('d');
    }
  }
  else
  {
    if(y < 25)
    {
      Keyboard.press('w');
      Keyboard.release('a');
      Keyboard.release('s');
      Keyboard.release('d');
    }
    else if(y > 75)
    {
      Keyboard.release('w');
      Keyboard.release('a');
      Keyboard.press('s');
      Keyboard.release('d');
    }
    else
    {
      Keyboard.release('w');
      Keyboard.release('a');
      Keyboard.release('s');
      Keyboard.release('d');
    }
  }
}
