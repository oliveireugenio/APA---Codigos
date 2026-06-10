#ifndef DISTANCEH
#define DISTANCEH

// Fator de conversao da leitura de tempo para centimetros
#define sound_speed 0.017

// Pinos de Trigger e Echo do HC-SR04(Sensor Ultrassônico)
#define left_dist_tr 32
#define left_dist_ec 33
#define right_dist_tr 14
#define right_dist_ec 13
#define central_dist_tr 12
#define central_dist_ec 27

// Numero de sensores
#define len 3

// Arrays dos sensores
uint8_t triggers[len] = {left_dist_tr, central_dist_tr, right_dist_tr};
uint8_t echos[len] = {left_dist_ec, central_dist_ec, right_dist_ec};
float distances[len];

// Indice de cada um dos sensores
#define left 0
#define central 1
#define right 2

// Função de configuraçao dos pinos
void setup_distances(){
  for(int i = 0; i < len; i++){
    pinMode(triggers[i], OUTPUT);
    digitalWrite(triggers[i], LOW);
    pinMode(echos[i], INPUT);
  }
}

// Funçao de atualizaçao das leituras do sensor 
void update_distances(){
  for(int i = 0; i < len; i++){
    digitalWrite(triggers[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(triggers[i], LOW);
    distances[i] = pulseIn(echos[i], HIGH, 30000) * 0.017;
  }
}

#endif
