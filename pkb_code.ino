// Pins of the RGB LED.
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

// Analog input from the potentiometer
int sensorPin = 0;

// Values for each pin of the RGB LED.
int currentColorValueRed;
int currentColorValueGreen;
int currentColorValueBlue;
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  int reading = analogRead(sensorPin);  
  
  float voltage = reading * 5.0;
 voltage /= 1024.0; 

 Serial.print(voltage); Serial.println(" volts");
  float temperatureC = (voltage - 0.5) * 100 ;  
 Serial.print(temperatureC); Serial.println(" degrees C");

 
 delay(1000);
 
  if (temperatureC <= 25) {
    currentColorValueRed = 255;
    currentColorValueGreen = 0;
    currentColorValueBlue = 0;
   }
   
   if (temperatureC > 25) {
    currentColorValueRed = 0;
    currentColorValueGreen = 255;
    currentColorValueBlue = 0;
   }

   
  analogWrite(redPin, currentColorValueRed);
  analogWrite(bluePin, currentColorValueBlue);
  analogWrite(greenPin, currentColorValueGreen);
}
