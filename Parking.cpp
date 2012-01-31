#include "Parking.hpp"

Parking::Parking() {}

Parking::~Parking() {}

void Parking::meter_coche() {
  Coche c;
  c.leer_coche();
  list<Coche>::iterator it = aparcamiento.begin();   
  aparcamiento.insert(it,c);
  plazas_libres--;
}

void Parking::sacar_coche() {
  Coche c;
  c.leer_coche();
  list<Coche>::iterator it = aparcamiento.begin();   
  bool trobat = false;
  while(it != aparcamiento.end() and not trobat) {
    Coche aux = *it;
    if(c.get_matricula() == aux.get_matricula()) {
      aparcamiento.erase(it);
      plazas_libres++;
      trobat = true;
    } 
    ++it;    
  }
}

int Parking::get_plazas_libres() {
  return plazas_libres;
}

void Parking::leer_parking() {
  cin >> plazas_libres;
}
