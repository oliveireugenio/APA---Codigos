#ifndef MOTORINO
#define MOTORINO

// Pinos de Controle do LN298H(Motor Driver)
#define move_power 19
#define turn_power 21
#define foward 2
#define back 4
#define left 5
#define right 18

// Tipos de velocidade do motor
#define increased 180
#define reduced 100

// Variavel de velocidade do motor de movimentação
uint8_t move_velocity = increased;
uint8_t turn_velocity = reduced;

// Para de dobrar
void stop_turn(){
  analogWrite(turn_power, 0);

  digitalWrite(left, LOW);
  digitalWrite(right, LOW);
}

// Para de andar
void stop_move(){
  analogWrite(move_power, 0);

  digitalWrite(foward, LOW);
  digitalWrite(back, LOW);
}

// Configuraçao dos pinos do Driver
void setup_motor(){
  // Configura o motor de movimentacao e para
  pinMode(move_power, OUTPUT);
  pinMode(foward, OUTPUT);
  pinMode(back, OUTPUT);
  stop_move();
  
  // Configura o motor de giro e para
  pinMode(turn_power, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  stop_turn();
}



// Andar para frente 
void move_foward(int power = move_velocity){
  analogWrite(move_power, power);
  digitalWrite(foward, HIGH);
  digitalWrite(back, LOW);
}

// Andar para tras
void move_back(int power = move_velocity){
  analogWrite(move_power, power);
  digitalWrite(foward, LOW);
  digitalWrite(back, HIGH);
}

// Muda a direçao do robo durante um tempo determinado
void turn_left(uint8_t power = turn_velocity){
  analogWrite(move_power, power);
  digitalWrite(right, LOW);
  digitalWrite(left, HIGH);

  delay(500);
  stop_turn();
}

void turn_right(uint8_t power = turn_velocity){
  analogWrite(move_power, power);
  digitalWrite(right, HIGH);
  digitalWrite(left, LOW);

  delay(500);
  stop_turn();
}

// Alteração das variaveis para realizar curvas fechadas e abertas
void sharp_curve(){
  move_velocity = reduced;
  turn_velocity = increased;
}

void wide_curve(){
  move_velocity = increased;
  turn_velocity = reduced;
}

#endif
