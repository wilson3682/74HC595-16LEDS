/*
  74HC595 (16 LEDS)
  https://github.com/leticia-pontes/74HC595-16LEDS/tree/main
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
  atualizar();
}

void loop() {
  Efeito1(2);
  Efeito2(2);
  Efeito3(1);
  Efeito4(1);
  Efeito5(1);
  Efeito6(1);
  Efeito7(1);
  Efeito8(1);
  Efeito9(1);
  Efeito10(1);
  Efeito11(30);
  Efeito12(10);
  Efeito13(5);
  Efeito14(5);
  Efeito15(1);
  Efeito16(1);
}

void atualizar() {
  digitalWrite(latchPin, LOW);
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, leds[i]);
    digitalWrite(clockPin, HIGH);
  }
  digitalWrite(latchPin, HIGH);
}

void limpar() {
  for (int i = 0; i < numLeds; i++) {
    leds[i] = LOW;
    atualizar();
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

//Efeito #1: acende um por um da esquerda para a direita
void Efeito1(int repeat) {
  printLabel("Effect 1", repeat);
  limpar();
  for (int t = 0; t < repeat; t++) {
    for (int i = 0; i < numLeds; i++) {
      leds[i] = HIGH;
      delay(40);
      atualizar();

      leds[i] = LOW;
      delay(40);
      atualizar();
    }
  }
}

//Efeito #2: acende um por um da direita para a esquerda
void Efeito2(int repeat) {
  printLabel("Effect 2", repeat);
  limpar();
  for (int t = 0; t < repeat; t++) {
    for (int i = numLeds - 1; i >= 0; i--) {
      leds[i] = HIGH;
      delay(40);
      atualizar();

      leds[i] = LOW;
      delay(40);
      atualizar();
    }
  }
}

//Efeito #3: acende uma fileira inteira da esquerda para a direita
void Efeito3(int repeat) {
  printLabel("Effect 3", repeat);
  limpar();
  for (int t = 0; t < repeat; t++) {
    for (int i = 0; i < numLeds; i++) {
      leds[i] = HIGH;
      delay(80);
      atualizar();
    }
    for (int i = 0; i < numLeds; i++) {
      leds[i] = LOW;
      delay(80);
      atualizar();
    }
  }
}

//Efeito #4: acende uma fileira inteira da direita para a esquerda
void Efeito4(int repeat) {
  printLabel("Effect 4", repeat);
  limpar();
  for (int t = 0; t < repeat; t++) {
    for (int i = numLeds - 1; i >= 0; i--) {
      leds[i] = HIGH;
      delay(80);
      atualizar();
    }
    for (int i = numLeds - 1; i >= 0; i--) {
      leds[i] = LOW;
      delay(80);
      atualizar();
    }
  }
}

//Efeito #5: mix dos efeitos #1 e #4
void Efeito5(int repeat) {
  printLabel("Effect 5", repeat);
  limpar();
  int k = numLeds - 1;
  for (int t = 0; t < repeat; t++) {
    for (int j = numLeds - 1; j >= 0; j--) {
      for (int i = 0; i < k; i++) {
        leds[i] = HIGH;
        delay(25);
        atualizar();
        leds[i] = LOW;
        delay(25);
        atualizar();
      }
      leds[j] = HIGH;
      delay(25);
      atualizar();
      k--;
    }
  }
}

//Efeito #6: mix dos efeitos #2 e #3
void Efeito6(int repeat) {
  printLabel("Effect 6", repeat);
  limpar();
  int k = 0;
  for (int t = 0; t < repeat; t++) {
    for (int j = 0; j < numLeds; j++) {
      for (int i = numLeds; i >= k; i--) {
        leds[i] = HIGH;
        delay(25);
        atualizar();
        leds[i] = LOW;
        delay(25);
        atualizar();
      }
      leds[j] = HIGH;
      delay(25);
      atualizar();
      k++;
    }
  }
}

//Efeito #7: acende os leds de fora para dentro
void Efeito7(int repeat) {
  printLabel("Effect 7", repeat);
  limpar();
  int j = 0;
  int k = numLeds - 1;
  for (int t = 0; t < repeat; t++) {
    for (int i = j; i < k; i++) {
      leds[j] = HIGH;
      delay(60);
      atualizar();
      leds[k] = HIGH;
      delay(60);
      atualizar();
      j++;
      k--;
    }
    j = 0;
    k = numLeds - 1;
    for (int i = j; i < k; i++) {
      leds[j] = LOW;
      delay(60);
      atualizar();
      leds[k] = LOW;
      delay(60);
      atualizar();
      j++;
      k--;
    }
  }
}

//Efeito #8: acende os leds de dentro para fora
void Efeito8(int repeat) {
  printLabel("Effect 8", repeat);
  limpar();
  int j = 7;
  int k = 8;
  for (int t = 0; t < repeat; t++) {
    for (int i = 0; i < 8; i++) {
      leds[j] = HIGH;
      delay(60);
      atualizar();
      leds[k] = HIGH;
      delay(60);
      atualizar();
      j--;
      k++;
    }
    j = 7;
    k = 8;

    for (int i = 0; i < 8; i++) {
      leds[j] = LOW;
      delay(60);
      atualizar();
      leds[k] = LOW;
      delay(60);
      atualizar();
      j--;
      k++;
    }
  }
}

//Efeito #9: inverso do efeito #5
void Efeito9(int repeat) {
  printLabel("Effect 9", repeat);
  limpar();
  int j = 0;
  for (int t = 0; t < repeat; t++) {
    for (j = 0; j < numLeds; j++) {
      leds[j] = HIGH;
      delay(40);
      atualizar();

      for (int i = j + 1; i < numLeds; i++) {
        leds[i] = HIGH;
        delay(40);
        atualizar();
        leds[i] = LOW;
        delay(40);
        atualizar();
      }
    }
  }
}

//Efeito #10: inverso do efeito #6
void Efeito10(int repeat) {
  printLabel("Effect 10", repeat);
  limpar();
  int j = numLeds - 1;
  for (int t = 0; t < repeat; t++) {
    for (j = numLeds - 1; j >= 0; j--) {
      leds[j] = HIGH;
      delay(40);
      atualizar();
      for (int i = j - 1; i >= 0; i--) {
        leds[i] = HIGH;
        delay(40);
        atualizar();
        leds[i] = LOW;
        delay(40);
        atualizar();
      }
    }
  }
}

//Efeito #11: luzes aleatórias
void Efeito11(int repeat) {
  printLabel("Effect 11", repeat);
  limpar();
  for (int t = 0; t < repeat; t++) {
    int num = random(1, 17);
    leds[num] = HIGH;
    delay(100);
    atualizar();
    leds[num] = LOW;
    delay(100);
    atualizar();
  }
}

//Efeito #12: duas luzes aleatórias por vez
void Efeito12(int repeat) {
  printLabel("Effect 12", repeat);
  limpar();
  for (int t = 0; t < repeat; t++) {
    int num1 = random(1, 17);
    int num2 = random(1, 17);
    if (num1 == num2) {
      leds[num1] = HIGH;
      delay(300);
      atualizar;
    }
    else if (num1 != num2) {
      leds[num1] = HIGH;
      atualizar();
      leds[num2] = HIGH;
      atualizar();
      delay(300);
      leds[num1] = LOW;
      atualizar();
      leds[num2] = LOW;
      atualizar();
    }
  }
}

//Efeito #13: luzes de natal (par e ímpar)
void Efeito13(int repeat) {
  printLabel("Effect 13", repeat);
  limpar();
  for (int t = 0; t < repeat; t++) {
    for (int i = 0; i < numLeds; i++) {
      if (i % 2 == 0 || i == 0) {
        leds[i] = HIGH;
        atualizar();
      }
    }
    delay(300);

    for (int i = 0; i < numLeds; i++) {
      if (i % 2 == 0 || i == 0) {
        leds[i] = LOW;
        atualizar();
      }
    }

    for (int i = 0; i < numLeds; i++)  {
      if (i % 2 != 0) {
        leds[i] = HIGH;
        atualizar();
      }
    }
    delay(300);
  }
}

//Efeito #14: fileira de leds (a cada 4)
void Efeito14(int repeat) {
  printLabel("Effect 14", repeat);
  limpar();
  int a = 0;
  int b = 4;
  int c = 8;
  int d = 12;
  for (int t = 0; t < repeat; t++) {
    for (int i = 0; i < 4; i++) {
      limpar();
      leds[a] = HIGH;
      atualizar();
      leds[b] = HIGH;
      atualizar();
      leds[c] = HIGH;
      atualizar();
      leds[d] = HIGH;
      atualizar();

      delay(200);

      leds[a] = LOW;
      atualizar();
      leds[b] = LOW;
      atualizar();
      leds[c] = LOW;
      atualizar();
      leds[d] = LOW;
      atualizar();

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

//Efeito #15: "vai e volta" até completar a sequência
void Efeito15(int repeat) {
  printLabel("Effect 15", repeat);
  limpar();
  for (int t = 0; t < repeat; t++) {
    for (int count = 0; count <= numLeds; count++)  {
      for (int i = 0; i < count; i++) {
        leds[i] = HIGH;
        delay(10);
        atualizar();
      }
      delay(100);
      for (int i = count; i >= 0; i--) {
        leds[i] = LOW;
        delay(10);
        atualizar();
      }
      delay(500);
    }
  }
}

//Efeito #16:
void Efeito16(int repeat) {
  printLabel("Effect 16", repeat);
  limpar();
  
  for (int t = 0; t < repeat; t++) {
    int a = 0;
    int b = 2;
    for (int i = 0; i < numLeds - 1; i++) {
      leds[a] = HIGH;
      delay(300);
      atualizar();
      leds[b] = HIGH;
      delay(300);
      atualizar();
      leds[a] = LOW;
      atualizar();
      leds[b] = LOW;
      atualizar;
      a++;
      b++;
    }
  }
}
