#include "Coche.hpp"

Coche::Coche() {}

Coche::~Coche() {}

int Coche::get_matricula() {
  return matricula;
}

int Coche::get_hora_entrada() {
  return hora_entrada;
}
int Coche::get_hora_salida() {
  return hora_salida;
}

void Coche::leer_coche_entrada() {
  cin >> matricula >> hora_entrada;
}

void Coche::leer_coche_salida() {
  cin >> matricula >> hora_salida;
}
