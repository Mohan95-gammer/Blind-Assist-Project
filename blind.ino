/*
 * Blind Assist Project – Text to Braille Converter
 * Developed by Mohana Krishna
 * Description: Converts text into Braille using Arduino-based hardware.
 */
#define MESSAGE 100  // buffer size

// Define LED pins
const int ledPins[6] = {8, 9, 10, 11, 12, 13};

char voice[MESSAGE];
int indx = 0;

void setup() {
  Serial.begin(9600); // Bluetooth baud rate
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH); // LEDs off initially (HIGH = off)
  }
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    voice[indx++] = c;
    voice[indx] = '\0';

    if (indx >= MESSAGE) {
      indx = 0;
      memset(voice, 0, sizeof(voice));
    }

    handleCharacter(c);
  }
}

void handleCharacter(char c) {
  // Reset all LEDs (off)
  for (int i = 0; i < 6; i++) digitalWrite(ledPins[i], HIGH);

  c = toupper(c); // case-insensitive

  // Letters A–Z
  if (c == 'A') digitalWrite(ledPins[0], LOW);
  else if (c == 'B') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); }
  else if (c == 'C') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[3], LOW); }
  else if (c == 'D') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[4], LOW); }
  else if (c == 'E') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[4], LOW); }
  else if (c == 'F') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[3], LOW); }
  else if (c == 'G') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[4], LOW); }
  else if (c == 'H') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[4], LOW); }
  else if (c == 'I') { digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[3], LOW); }
  else if (c == 'J') { digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[4], LOW); }
  else if (c == 'K') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[2], LOW); }
  else if (c == 'L') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[2], LOW); }
  else if (c == 'M') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[3], LOW); }
  else if (c == 'N') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[4], LOW); }
  else if (c == 'O') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[4], LOW); }
  else if (c == 'P') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[3], LOW); }
  else if (c == 'Q') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[4], LOW); }
  else if (c == 'R') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[4], LOW); }
  else if (c == 'S') { digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[3], LOW); }
  else if (c == 'T') { digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[4], LOW); }
  else if (c == 'U') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[5], LOW); }
  else if (c == 'V') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[5], LOW); }
  else if (c == 'W') { digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[4], LOW); digitalWrite(ledPins[5], LOW); }
  else if (c == 'X') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[5], LOW); }
  else if (c == 'Y') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[4], LOW); digitalWrite(ledPins[5], LOW); }
  else if (c == 'Z') { digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[4], LOW); digitalWrite(ledPins[5], LOW); }

  // Numbers 0–9
  else if (isdigit(c)) handleNumber(c);

  // Punctuation
  else if (c == '.') { digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[4], LOW); digitalWrite(ledPins[5], LOW); }
  else if (c == ',') { digitalWrite(ledPins[1], LOW); }
  else if (c == '#') { digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[4], LOW); digitalWrite(ledPins[5], LOW); }
  else if (c == '-') { digitalWrite(ledPins[2], LOW); digitalWrite(ledPins[5], LOW); }
  else if (c == ' ') { for (int i = 0; i < 6; i++) digitalWrite(ledPins[i], HIGH); }

  delay(1000);
  for (int i = 0; i < 6; i++) digitalWrite(ledPins[i], HIGH);
}

void handleNumber(char c) {
  for (int i = 0; i < 6; i++) digitalWrite(ledPins[i], HIGH);

  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[4], LOW);
  digitalWrite(ledPins[5], LOW);
  delay(500);
  for (int i = 2; i <= 5; i++) digitalWrite(ledPins[i], HIGH);
  delay(400);

  switch (c) {
    case '1': digitalWrite(ledPins[0], LOW); break;
    case '2': digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); break;
    case '3': digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[3], LOW); break;
    case '4': digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[4], LOW); break;
    case '5': digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[4], LOW); break;
    case '6': digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[3], LOW); break;
    case '7': digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[4], LOW); break;
    case '8': digitalWrite(ledPins[0], LOW); digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[4], LOW); break;
    case '9': digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[3], LOW); break;
    case '0': digitalWrite(ledPins[1], LOW); digitalWrite(ledPins[3], LOW); digitalWrite(ledPins[4], LOW); break;
  }
}
