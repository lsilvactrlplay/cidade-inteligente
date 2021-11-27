#include <Servo.h>

#define botao_ponte_1 4
int estado_botao_ponte_1 = 0;
Servo ponte_1;
bool estado_ponte_1 = 0;
int posicao_ponte_1 = 90;

#define botao_ponte_2 5
int estado_botao_ponte_2 = 0;
Servo ponte_2;
bool estado_ponte_2 = 0;
int posicao_ponte_2 = 90;

#define sinal_verde_ponte_1 10
#define sinal_amarelo_ponte_1 9 
#define sinal_vermelho_ponte_1 8

#define sinal_verde_ponte_2 13
#define sinal_amarelo_ponte_2 12
#define sinal_vermelho_ponte_2 11

#define sinal_verde_rua 16
#define sinal_amarelo_rua 15
#define sinal_vermelho_rua 14

#define luzes 6
#define ldr A3
int claridade = 0;

void setup() {
  pinMode(botao_ponte_1, INPUT);
  ponte_1.attach(2);

  pinMode(botao_ponte_2, INPUT);
  ponte_2.attach(3);

  pinMode(sinal_verde_ponte_1, OUTPUT);
  pinMode(sinal_amarelo_ponte_1, OUTPUT);
  pinMode(sinal_vermelho_ponte_1, OUTPUT);

  pinMode(sinal_verde_ponte_2, OUTPUT);
  pinMode(sinal_amarelo_ponte_2, OUTPUT);
  pinMode(sinal_vermelho_ponte_2, OUTPUT);

  pinMode(sinal_verde_rua, OUTPUT);
  pinMode(sinal_amarelo_rua, OUTPUT);
  pinMode(sinal_vermelho_rua, OUTPUT);

  pinMode(luzes, OUTPUT);
  pinMode(ldr, INPUT);

  Serial.begin(9600);

  ponte_1.write(posicao_ponte_1);
  ponte_2.write(posicao_ponte_2);

  digitalWrite(sinal_verde_ponte_1, HIGH);
  digitalWrite(sinal_amarelo_ponte_1, LOW);
  digitalWrite(sinal_vermelho_ponte_1, LOW);

  digitalWrite(sinal_verde_ponte_2, HIGH);
  digitalWrite(sinal_amarelo_ponte_2, LOW);
  digitalWrite(sinal_vermelho_ponte_2, LOW);

  digitalWrite(sinal_verde_rua, HIGH);
  digitalWrite(sinal_amarelo_rua, LOW);
  digitalWrite(sinal_vermelho_rua, LOW);
};

void loop() {
  estado_botao_ponte_1 = digitalRead(botao_ponte_1);
  estado_botao_ponte_2 = digitalRead(botao_ponte_2);

  if (estado_botao_ponte_1 == HIGH) {
    controlar_ponte(1);
  };
  if (estado_botao_ponte_2 == HIGH) {
    controlar_ponte(2);
  };

  claridade = analogRead(ldr);

  if (claridade < 500) {
    digitalWrite(luzes, HIGH);
  } else {
    digitalWrite(luzes,LOW);
  }
};

void controlar_ponte(int ponte) {
  if (ponte == 1) {
    if (estado_ponte_1) {
      for (posicao_ponte_1; posicao_ponte_1 > 90; posicao_ponte_1 -= 1) {
        ponte_1.write(posicao_ponte_1);
        delay(30);
      };

      delay(500);
      digitalWrite(sinal_verde_ponte_1, HIGH);
      digitalWrite(sinal_amarelo_ponte_1, LOW);
      digitalWrite(sinal_vermelho_ponte_1, LOW);

    } else {
      digitalWrite(sinal_verde_ponte_1, LOW);
      digitalWrite(sinal_amarelo_ponte_1, HIGH);
      digitalWrite(sinal_vermelho_ponte_1, LOW);
      delay(3000);
      digitalWrite(sinal_verde_ponte_1, LOW);
      digitalWrite(sinal_amarelo_ponte_1, LOW);
      digitalWrite(sinal_vermelho_ponte_1, HIGH);
      delay(500);

      for (posicao_ponte_1; posicao_ponte_1 < 150; posicao_ponte_1 += 1) {
        ponte_1.write(posicao_ponte_1);
        delay(30);
      };
    };
    estado_ponte_1 = !estado_ponte_1;
    
  } else {
    if (estado_ponte_2) {
      for (posicao_ponte_2; posicao_ponte_2 > 90; posicao_ponte_2 -= 1) {
        ponte_2.write(posicao_ponte_2);
        delay(30);
      };

      delay(500);
      digitalWrite(sinal_verde_ponte_2, HIGH);
      digitalWrite(sinal_amarelo_ponte_2, LOW);
      digitalWrite(sinal_vermelho_ponte_2, LOW);

    } else {
      digitalWrite(sinal_verde_ponte_2, LOW);
      digitalWrite(sinal_amarelo_ponte_2, HIGH);
      digitalWrite(sinal_vermelho_ponte_2, LOW);
      delay(3000);
      digitalWrite(sinal_verde_ponte_2, LOW);
      digitalWrite(sinal_amarelo_ponte_2, LOW);
      digitalWrite(sinal_vermelho_ponte_2, HIGH);
      delay(500);

      for (posicao_ponte_2; posicao_ponte_2 < 150; posicao_ponte_2 += 1) {
        ponte_2.write(posicao_ponte_2);
        delay(30);
      };
    };
    estado_ponte_2 = !estado_ponte_2;
  };
};