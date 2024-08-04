// C++ code
//
#include <Servo.h>

int i = 0;

int pos = 0;

int j = 0;

Servo servo_3;

void setup()
{
  servo_3.attach(3, 500, 2500);
}

void loop()
{
  for (i = 0; i <= 90; i += 1) {
    servo_3.write(pos);
    delay(15); // Wait for 15 millisecond(s)
  }
  for (pos = 90; pos >= 0; pos -= 1) {
    servo_3.write(pos);
    delay(15); // Wait for 15 millisecond(s)
  }
}