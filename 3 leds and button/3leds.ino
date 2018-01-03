const int button = 2;
bool old_click, plus_vector;
int leds_glows;
void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(button, INPUT);
  old_click = false;
  leds_glows = 0;
  plus_vector = true;

}
void loop() {
  bool is_click = digitalRead(button);
  if (is_click && !old_click) {
    switch (leds_glows) {
      case 4: plus_vector = false; break;
      case 0: plus_vector = true; break;
    }
    leds_glows += plus_vector ? 1 : -1;
    if (plus_vector)
      digitalWrite(leds_glows + 3, HIGH);
    else
      digitalWrite(leds_glows + 3, LOW);
  }
  old_click = is_click;
  delay(10);
}
