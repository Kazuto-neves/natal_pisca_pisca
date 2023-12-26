#define PIN_LEDS1 11
#define PIN_LEDS2 10
#define PIN_BUTTON 9

#define NUM_FUNCTIONS 3

int brightness = 0;
int currentIndex = 0;
int previousButtonState = LOW;

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LEDS1, OUTPUT);
  pinMode(PIN_LEDS2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonStatus = digitalRead(PIN_BUTTON);
  
  if (buttonStatus == HIGH && previousButtonState == LOW) {
    currentIndex = ChangeFunction(currentIndex);
  }
  
  Menu(currentIndex);
  
  previousButtonState = buttonStatus;
}

int ChangeFunction(int index){
  return index<NUM_FUNCTIONS?(index + 1):index=0;
}

void Menu(int index){
  if(index == 0){
    Fade();
  }else if(index == 1){
    Combination();
  }else if(index == 2){
    Combination2();
  }
}

void Fade(int opicao){
  if(opicao == 1){
  	for (brightness = 0; brightness <= 255; brightness += 5) {
    	analogWrite(PIN_LEDS1, brightness);
    	analogWrite(PIN_LEDS2, brightness);
    	delay(30);
  	}
  	for (brightness = 255; brightness >= 0; brightness -= 5) {
    	analogWrite(PIN_LEDS1, brightness);
    	analogWrite(PIN_LEDS2, brightness);
    	delay(30);
  	}
  }else if(opicao == 2){
    for (brightness = 0; brightness <= 255; brightness += 5) {
      analogWrite(PIN_LEDS1, brightness);
      analogWrite(PIN_LEDS2, (brightness));
      delay(30);
      
  	}
  	for (brightness = 255; brightness >= 0; brightness -= 5) {
    	analogWrite(PIN_LEDS1, brightness);
    	analogWrite(PIN_LEDS2, brightness);
    	delay(30);
  	}
  }
}

void Combination(){
  for (int Flashes = 0; Flashes <= 4; Flashes +=1) {
    if(Flashes<=2){
  		digitalWrite(PIN_LEDS1, HIGH);
  		delay(90);
  		digitalWrite(PIN_LEDS1, LOW);
  		delay(90);
    }else{
    	digitalWrite(PIN_LEDS2, HIGH);
  		delay(90);
  		digitalWrite(PIN_LEDS2, LOW);
  		delay(90);
    }
  }
}

void Combination2(){
  for (int Delay = 500; Delay >= 100; Delay -=25) {
    digitalWrite(PIN_LEDS1, HIGH);
    delay(Delay);
    digitalWrite(PIN_LEDS1, LOW);
    delay(Delay);
    digitalWrite(PIN_LEDS2, HIGH);
    delay(Delay);
    digitalWrite(PIN_LEDS2, LOW);
    delay(Delay);
    if(Delay < 100){
      Delay = 500;
    }
    Serial.println(Delay);
  }
}