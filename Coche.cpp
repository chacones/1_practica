#include "Coche.hpp"

Coche::Coche() {}

Coche::~Coche() {}

int Coche::get_matricula() {
  return matricula;
}

void Coche::leer_coche() {
  cin >> matricula;
}


void Coche::imprimir_coche() {
  cout << matricula << endl;
}
