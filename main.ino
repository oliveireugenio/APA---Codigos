// Bibliotecas de Distancia e Motor
#include "distance.ino"
#include "motor.ino"

// Retorna se tem alguma distancia menor que...
bool less_than(uint8_t dist){
  for(int i = 0; i < len; i++){
    if(distances[i] > dist){
      return true;
    }
  }
  return false;
}

// Retorna qual sensor é menor que tal distancia
uint8_t which_sensor(uint8_t dist){
  for(int i = 0; i < len; i++){
    if(distances[i] < dist){
      return i;
    }
  }
  return len;
}

// Logica de fuga
void follow(){
  update_distances();

  if(less_than(2)){
    stop_move();
    return;
  }

  if(less_than(10)){
    sharp_curve();
  }else{
    wide_curve();
  }

  switch(which_sensor(15)){
    case left:
      turn_right();
      break;
    case central:
      move_foward();
      break;
    case right:
      turn_left();
      break;
    default:
      stop_move();
      break;
  }
}

void setup() {
  // Sensores de Distancia
  setup_distances();

  // Motor Driver
  setup_motor();
}

void loop() {
  follow();
}
