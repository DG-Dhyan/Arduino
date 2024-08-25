// C++ code
//
int moisture = 0;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(6,OUTPUT);
}

void loop()

{
  // Apply power to the soil moisture sensor
  digitalWrite(A0, HIGH);
  delay(10); // Wait for 10 millisecond(s)
  moisture = analogRead(A5);
  // Turn off the sensor to reduce metal corrosion
  // over time
  digitalWrite(A0, LOW);
  Serial.println(moisture);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(9, LOW);
  digitalWrite(13, LOW);
  digitalWrite(6,LOW);
  if (moisture < 200) {
    digitalWrite(13, HIGH);
    digitalWrite(6,HIGH);
  } else {
    if (moisture < 400) {
      digitalWrite(9, HIGH);
      digitalWrite(6,HIGH);
    } else {
      if (moisture < 600) {
        digitalWrite(5, HIGH);
        digitalWrite(6,LOW);
      } else {
        if (moisture < 800) {
          digitalWrite(3, HIGH);
          digitalWrite(6,LOW);
        } else {
          digitalWrite(2, HIGH);
        }
      }
    }
  }
  delay(100); // Wait for 100 millisecond(s)
}