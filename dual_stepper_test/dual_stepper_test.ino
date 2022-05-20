const int A = 32;  //red
const int Am = 25; //black
const int B = 26;  //green
const int Bm = 33; //blue

const int A_two = 27;  //red
const int Am_two = 12; //black
const int B_two = 13;  //green
const int Bm_two = 14; //blue

const int pot = 34;

void setup() {
  Serial.begin(115200);
  pinMode(A, OUTPUT);
  pinMode(Am, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(Bm, OUTPUT);
  digitalWrite(A, 0);
  digitalWrite(Am, 0);
  digitalWrite(B, 0);
  digitalWrite(Bm, 0);
  pinMode(A_two, OUTPUT);
  pinMode(Am_two, OUTPUT);
  pinMode(B_two, OUTPUT);
  pinMode(Bm_two, OUTPUT);
  digitalWrite(A_two, 0);
  digitalWrite(Am_two, 0);
  digitalWrite(B_two, 0);
  digitalWrite(Bm_two, 0);
}

int d=2, N=200;
int potValue = 0;


void loop() {
  
  potValue = analogRead(pot);
  N = potValue/100;
  Serial.print(N);

  Serial.println(" | up");
  for(int i=0; i<N; ++i)
  {
    digitalWrite(A,  1);
    digitalWrite(Am, 0);
    digitalWrite(B,  0);
    digitalWrite(Bm, 1);
    digitalWrite(A_two,  1);
    digitalWrite(Am_two, 0);
    digitalWrite(B_two,  0);
    digitalWrite(Bm_two, 1);
    delay(d);
    digitalWrite(A,  1);
    digitalWrite(Am, 0);
    digitalWrite(B,  1);
    digitalWrite(Bm, 0);
    digitalWrite(A_two,  1);
    digitalWrite(Am_two, 0);
    digitalWrite(B_two,  1);
    digitalWrite(Bm_two, 0);
    delay(d);
    digitalWrite(A,  0);
    digitalWrite(Am, 1);
    digitalWrite(B,  1);
    digitalWrite(Bm, 0);
    digitalWrite(A_two,  0);
    digitalWrite(Am_two, 1);
    digitalWrite(B_two,  1);
    digitalWrite(Bm_two, 0);
    delay(d);
    digitalWrite(A,  0);
    digitalWrite(Am, 1);
    digitalWrite(B,  0);
    digitalWrite(Bm, 1);
    digitalWrite(A_two,  0);
    digitalWrite(Am_two, 1);
    digitalWrite(B_two,  0);
    digitalWrite(Bm_two, 1);
    delay(d);
  }
  delay(500);
  
  potValue = analogRead(pot);
  N = potValue/100;
  Serial.print(N);

  Serial.println(" | down");
  for(int i=0; i<N; ++i)
  {
    digitalWrite(A,  0);
    digitalWrite(Am, 1);
    digitalWrite(B,  1);
    digitalWrite(Bm, 0);
    digitalWrite(A_two,  0);
    digitalWrite(Am_two, 1);
    digitalWrite(B_two,  1);
    digitalWrite(Bm_two, 0);
    delay(d);
    digitalWrite(A,  1);
    digitalWrite(Am, 0);
    digitalWrite(B,  1);
    digitalWrite(Bm, 0);
    digitalWrite(A_two,  1);
    digitalWrite(Am_two, 0);
    digitalWrite(B_two,  1);
    digitalWrite(Bm_two, 0);
    delay(d);
    digitalWrite(A,  1);
    digitalWrite(Am, 0);
    digitalWrite(B,  0);
    digitalWrite(Bm, 1);
    digitalWrite(A_two,  1);
    digitalWrite(Am_two, 0);
    digitalWrite(B_two,  0);
    digitalWrite(Bm_two, 1);
    delay(d);
    digitalWrite(A,  0);
    digitalWrite(Am, 1);
    digitalWrite(B,  0);
    digitalWrite(Bm, 1);
    digitalWrite(A_two,  0);
    digitalWrite(Am_two, 1);
    digitalWrite(B_two,  0);
    digitalWrite(Bm_two, 1);
    delay(d);
  }
  delay(500);
}
