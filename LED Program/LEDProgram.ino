int which_function = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  
  int pressed_or_not = digitalRead(2);

  if (pressed_or_not == LOW) //If the button is pressed then it will pull down the pin, so we get a LOW
  {
    which_function += 1;
    delay(2000);
  }

  if (which_function > 3) //Ensures that once we get to the last function possible, the counter will restart
    which_function = 0;

  whichFunction(which_function); //Calls which function to do
}

void whichFunction(int numFunction) //Determines which function to run based off of how many button presses
{
  if (numFunction == 0)
    stayOn();

  else if (numFunction == 1)
    blink();

  else if (numFunction == 2)
    fadeInAndOut();

  else if (numFunction == 3)
    fadeInOneOutOther();
}

void stayOn() //Causes LEDs to stay on
{
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
}

void blink() //Makes LEDs blink
{
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  delay(1000);
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  delay(1000);
}

void fadeInAndOut() //Fades in and out with both LEDs at same time
{
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);

  for (int i = 0; i < 256; i++)
  {
    analogWrite(9, i);
    analogWrite(11, i);
    delay(7);
  }

  for (int i = 256; i > 0; i--)
  {
    analogWrite(9, i);
    analogWrite(11, i);
    delay(7);
  }
}

void fadeInOneOutOther() //Fades in and out with RED and GREEN happening at different times
{
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);

  for (int i = 0; i < 256; i++)
  {
    analogWrite(9, i);
    analogWrite(11, 256 - i);
    delay(7);
  }

  for (int i = 0; i < 256; i++)
  {
    analogWrite(9, 256 - i);
    analogWrite(11, i);
    delay(7);
  }
}
