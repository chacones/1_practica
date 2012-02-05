#include "Aparcado.hpp"

Aparcado::Aparcado() {
  dias_aparcado = 0;
}

Aparcado::~Aparcado() {}

int Aparcado::get_hora_entrada() {
  return hora_entrada;
}

int Aparcado::get_hora_salida() {
  return hora_salida;
}

Coche Aparcado::get_coche() {
  return coche;
}

int Aparcado::get_dias_aparcado() {
  return dias_aparcado;
}

void Aparcado::imprimir() {
  cout << hora_salida << " " << hora_entrada << endl;
}

void Aparcado::set_hora_entrada(int h) {
  hora_entrada = h;
}

void Aparcado::set_hora_salida(int h) {
  hora_salida = h;
}

void Aparcado::set_coche(Coche c) {
  coche = c;
}

void Aparcado::set_dias_aparcado(int d) {
  dias_aparcado = d;
}
