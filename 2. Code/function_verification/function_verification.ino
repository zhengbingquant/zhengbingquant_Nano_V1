#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define BUTTON_PIN 2
#define POT_PIN A0

// Non-PWM LEDs
int leds[] = {4, 7, 8, 12, 13};
int numLeds = sizeof(leds)/sizeof(leds[0]);

// PWM LEDs
int pwmLeds[] = {3, 5, 6, 9, 10, 11};
int numPwm = sizeof(pwmLeds)/sizeof(pwmLeds[0]);

bool ledState = false;          // Current state of non-PWM LEDs
bool buttonPressed = false;     // Tracks button press
int lastButtonState = HIGH;     // Last reading from button
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  for(int i=0; i<numLeds; i++){
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  for(int i=0; i<numPwm; i++){
    pinMode(pwmLeds[i], OUTPUT);
  }

  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.display();
}

void loop() {
  // --- Button toggle logic ---
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // reset debounce timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If button just pressed
    if (reading == LOW && !buttonPressed) {
      buttonPressed = true;    // mark as pressed
      ledState = !ledState;    // toggle LED state

      // Update non-PWM LEDs
      for(int i=0; i<numLeds; i++){
        digitalWrite(leds[i], ledState ? HIGH : LOW);
      }
    }
    // If button released
    if (reading == HIGH) {
      buttonPressed = false;
    }
  }

  lastButtonState = reading;

  // --- Potentiometer for PWM LEDs ---
  int potVal = analogRead(POT_PIN);
  int pwmVal = map(potVal, 0, 1023, 0, 255);

  for(int i=0; i<numPwm; i++){
    analogWrite(pwmLeds[i], pwmVal);
  }

  // --- Serial output ---
  Serial.println(potVal);

  // --- OLED display ---
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("PWM Brightness:");

  int barWidth = map(potVal, 0, 1023, 0, SCREEN_WIDTH);
  display.fillRect(0, 20, barWidth, 10, SSD1306_WHITE);
  display.drawRect(0, 20, SCREEN_WIDTH, 10, SSD1306_WHITE);

  display.display();

  delay(20);
}
