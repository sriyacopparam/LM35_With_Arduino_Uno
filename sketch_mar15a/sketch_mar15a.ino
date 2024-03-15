//Library for creating a delay
#include<util/delay.h>

//Using a name for the pin A0.
const int LM35_pin = A0;

//Delay function for 500ms
void delay_by_sriya_500()
{
 _delay_ms(500);
}

//Delay function for 250ms
void delay_by_sriya_250()
{
  _delay_ms(250);
}

void setup() {

//Making the built in LED as output pin
  pinMode(LED_BUILTIN, OUTPUT);

//Setting the baud rate as 9600
  Serial.begin(9600);
}

void loop() {
  //Variables for calculating the temperature
  int temperature_adc_value;
  float temperature_value;

//Reading the pin
  temperature_adc_value = analogRead(LM35_pin);

//Calculating the value from the pin
  temperature_value = (temperature_adc_value * 4.88);

//Calculating the correct temperature
  temperature_value = (temperature_value/10);


//Printing the value of temperature
  Serial.print("Temperature = ");
  Serial.print(temperature_value);
  Serial.println(" Degree Celcius");

//If the value of temperature is greater than 30 degree celcius, the built-in LED will blink for every 500ms
  if(temperature_value > 30)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println(" LED ON");
    delay_by_sriya_500();
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println(" LED OFF");
    delay_by_sriya_500();

  }
  //If the value of temperature is lesser than 30 degree celcius, the built-in LED will blink for every 250ms
  if(temperature_value < 30)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println(" LED ON");
    delay_by_sriya_250();
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println(" LED OFF");
    delay_by_sriya_250();

  }




}
