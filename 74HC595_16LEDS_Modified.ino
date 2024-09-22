/*
  74HC595 (16 LEDS)
  https://github.com/leticia-pontes/74HC595-16LEDS/tree/main
  https://github.com/wilson3682/74HC595-16LEDS/tree/main
  wokwi simulation: https://wokwi.com/projects/409749088760157185
*/

int clockPin = 10;
int latchPin = 9;
int dataPin = 8;
#define numLeds 16
boolean leds[numLeds];

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  updateReg();
}

void loop() {
  Effect1(2);
  Effect2(2);
  Effect3(1);
  Effect4(1);
  Effect5(1);
  Effect6(1);
  Effect7(1);
  Effect8(1);
  Effect9(1);
  Effect10(1);
  Effect11(30);
  Effect12(10);
  Effect13(5);
  Effect14(5);
  Effect15(1);
  Effect16(1);
}

void updateReg() {
  digitalWrite(latchPin, LOW);
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, leds[i]);
    digitalWrite(clockPin, HIGH);
  }
  digitalWrite(latchPin, HIGH);
}

void clearReg() {
  for (int i = 0; i < numLeds; i++) {
    leds[i] = LOW;
    updateReg();
  }
}

void printLabel(char* effect, int repeat) {
  Serial.print(effect);
  Serial.print("\t");
  Serial.print("repeat");
  Serial.print(" ");
  Serial.print(repeat);
  Serial.print(" ");
  Serial.println("times");
}

//Effect #1: Lights up one LED at a time from left to right.
void Effect1(int repeat) {
  printLabel("Effect 1", repeat);
  clearReg();
  for (int t = 0; t < repeat; t++) {
    for (int i = 0; i < numLeds; i++) {
      leds[i] = HIGH;
      delay(40);
      updateReg();

      leds[i] = LOW;
      delay(40);
      updateReg();
    }
  }
}

//Effect #2: Lights up one LED at a time from right to left.
void Effect2(int repeat) {
  printLabel("Effect 2", repeat);
  clearReg();
  for (int t = 0; t < repeat; t++) {
    for (int i = numLeds - 1; i >= 0; i--) {
      leds[i] = HIGH;
      delay(40);
      updateReg();

      leds[i] = LOW;
      delay(40);
      updateReg();
    }
  }
}

//Effect #3: Lights up all LEDs sequentially from left to right.
void Effect3(int repeat) {
  printLabel("Effect 3", repeat);
  clearReg();
  for (int t = 0; t < repeat; t++) {
    for (int i = 0; i < numLeds; i++) {
      leds[i] = HIGH;
      delay(80);
      updateReg();
    }
    for (int i = 0; i < numLeds; i++) {
      leds[i] = LOW;
      delay(80);
      updateReg();
    }
  }
}

//Effect #4: Lights up all LEDs sequentially from right to left.
void Effect4(int repeat) {
  printLabel("Effect 4", repeat);
  clearReg();
  for (int t = 0; t < repeat; t++) {
    for (int i = numLeds - 1; i >= 0; i--) {
      leds[i] = HIGH;
      delay(80);
      updateReg();
    }
    for (int i = numLeds - 1; i >= 0; i--) {
      leds[i] = LOW;
      delay(80);
      updateReg();
    }
  }
}

//Effect #5: Combination of effects 1 and 4.
void Effect5(int repeat) {
  printLabel("Effect 5", repeat);
  clearReg();
  int k = numLeds - 1;
  for (int t = 0; t < repeat; t++) {
    for (int j = numLeds - 1; j >= 0; j--) {
      for (int i = 0; i < k; i++) {
        leds[i] = HIGH;
        delay(25);
        updateReg();
        leds[i] = LOW;
        delay(25);
        updateReg();
      }
      leds[j] = HIGH;
      delay(25);
      updateReg();
      k--;
    }
  }
}

//Effect #6: Combination of effects 2 and 3.
void Effect6(int repeat) {
  printLabel("Effect 6", repeat);
  clearReg();
  int k = 0;
  for (int t = 0; t < repeat; t++) {
    for (int j = 0; j < numLeds; j++) {
      for (int i = numLeds; i >= k; i--) {
        leds[i] = HIGH;
        delay(25);
        updateReg();
        leds[i] = LOW;
        delay(25);
        updateReg();
      }
      leds[j] = HIGH;
      delay(25);
      updateReg();
      k++;
    }
  }
}

//Effect #7: Lights up the LEDs from the outside to the inside.
void Effect7(int repeat) {
  printLabel("Effect 7", repeat);
  clearReg();
  int j = 0;
  int k = numLeds - 1;
  for (int t = 0; t < repeat; t++) {
    for (int i = j; i < k; i++) {
      leds[j] = HIGH;
      delay(60);
      updateReg();
      leds[k] = HIGH;
      delay(60);
      updateReg();
      j++;
      k--;
    }
    j = 0;
    k = numLeds - 1;
    for (int i = j; i < k; i++) {
      leds[j] = LOW;
      delay(60);
      updateReg();
      leds[k] = LOW;
      delay(60);
      updateReg();
      j++;
      k--;
    }
  }
}

//Effect #8: Lights up the LEDs from the inside to the outside.
void Effect8(int repeat) {
  printLabel("Effect 8", repeat);
  clearReg();
  int j = 7;
  int k = 8;
  for (int t = 0; t < repeat; t++) {
    for (int i = 0; i < 8; i++) {
      leds[j] = HIGH;
      delay(60);
      updateReg();
      leds[k] = HIGH;
      delay(60);
      updateReg();
      j--;
      k++;
    }
    j = 7;
    k = 8;

    for (int i = 0; i < 8; i++) {
      leds[j] = LOW;
      delay(60);
      updateReg();
      leds[k] = LOW;
      delay(60);
      updateReg();
      j--;
      k++;
    }
  }
}

//Effect #9: Inverse version of effect 5.
void Effect9(int repeat) {
  printLabel("Effect 9", repeat);
  clearReg();
  int j = 0;
  for (int t = 0; t < repeat; t++) {
    for (j = 0; j < numLeds; j++) {
      leds[j] = HIGH;
      delay(40);
      updateReg();

      for (int i = j + 1; i < numLeds; i++) {
        leds[i] = HIGH;
        delay(40);
        updateReg();
        leds[i] = LOW;
        delay(40);
        updateReg();
      }
    }
  }
}

//Effect #10: Inverse version of effect 6.
void Effect10(int repeat) {
  printLabel("Effect 10", repeat);
  clearReg();
  int j = numLeds - 1;
  for (int t = 0; t < repeat; t++) {
    for (j = numLeds - 1; j >= 0; j--) {
      leds[j] = HIGH;
      delay(40);
      updateReg();
      for (int i = j - 1; i >= 0; i--) {
        leds[i] = HIGH;
        delay(40);
        updateReg();
        leds[i] = LOW;
        delay(40);
        updateReg();
      }
    }
  }
}

//Effect #11: Lights up a random LED.
void Effect11(int repeat) {
  printLabel("Effect 11", repeat);
  clearReg();
  for (int t = 0; t < repeat; t++) {
    int num = random(1, 17);
    leds[num] = HIGH;
    delay(100);
    updateReg();
    leds[num] = LOW;
    delay(100);
    updateReg();
  }
}

//Effect #12: Lights up two random LEDs.
void Effect12(int repeat) {
  printLabel("Effect 12", repeat);
  clearReg();
  for (int t = 0; t < repeat; t++) {
    int num1 = random(1, 17);
    int num2 = random(1, 17);
    if (num1 == num2) {
      leds[num1] = HIGH;
      delay(300);
      updateReg;
    }
    else if (num1 != num2) {
      leds[num1] = HIGH;
      updateReg();
      leds[num2] = HIGH;
      updateReg();
      delay(300);
      leds[num1] = LOW;
      updateReg();
      leds[num2] = LOW;
      updateReg();
    }
  }
}

//Effect #13: Lights up even and odd LEDs alternately.
void Effect13(int repeat) {
  printLabel("Effect 13", repeat);
  clearReg();
  for (int t = 0; t < repeat; t++) {
    for (int i = 0; i < numLeds; i++) {
      if (i % 2 == 0 || i == 0) {
        leds[i] = HIGH;
        updateReg();
      }
    }
    delay(300);

    for (int i = 0; i < numLeds; i++) {
      if (i % 2 == 0 || i == 0) {
        leds[i] = LOW;
        updateReg();
      }
    }

    for (int i = 0; i < numLeds; i++)  {
      if (i % 2 != 0) {
        leds[i] = HIGH;
        updateReg();
      }
    }
    delay(300);
  }
}

//Effect #14: Lights up LEDs in groups of 4.
void Effect14(int repeat) {
  printLabel("Effect 14", repeat);
  clearReg();
  int a = 0;
  int b = 4;
  int c = 8;
  int d = 12;
  for (int t = 0; t < repeat; t++) {
    for (int i = 0; i < 4; i++) {
      clearReg();
      leds[a] = HIGH;
      updateReg();
      leds[b] = HIGH;
      updateReg();
      leds[c] = HIGH;
      updateReg();
      leds[d] = HIGH;
      updateReg();

      delay(200);

      leds[a] = LOW;
      updateReg();
      leds[b] = LOW;
      updateReg();
      leds[c] = LOW;
      updateReg();
      leds[d] = LOW;
      updateReg();

      a++;
      b++;
      c++;
      d++;

      if (a == numLeds) {
        a = 0;
      }
      else if (b == numLeds) {
        b = 0;
      }
      else if (c == numLeds) {
        c = 0;
      }
      else if (d == numLeds) {
        d = 0;
      }
    }
  }
}

//Effect #15: LEDs go back and forth until the sequence is complete.
void Effect15(int repeat) {
  printLabel("Effect 15", repeat);
  clearReg();
  for (int t = 0; t < repeat; t++) {
    for (int count = 0; count <= numLeds; count++)  {
      for (int i = 0; i < count; i++) {
        leds[i] = HIGH;
        delay(10);
        updateReg();
      }
      delay(100);
      for (int i = count; i >= 0; i--) {
        leds[i] = LOW;
        delay(10);
        updateReg();
      }
      delay(500);
    }
  }
}

//Effect #16: Sequence in alternating pairs.
void Effect16(int repeat) {
  printLabel("Effect 16", repeat);
  clearReg();

  for (int t = 0; t < repeat; t++) {
    int a = 0;
    int b = 2;
    for (int i = 0; i < numLeds - 1; i++) {
      leds[a] = HIGH;
      delay(300);
      updateReg();
      leds[b] = HIGH;
      delay(300);
      updateReg();
      leds[a] = LOW;
      updateReg();
      leds[b] = LOW;
      updateReg;
      a++;
      b++;
    }
  }
}
