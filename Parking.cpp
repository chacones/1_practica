#include "Parking.hpp"

Parking::Parking() {}

Parking::~Parking() {}

void Parking::meter_coche(int num_plazas) {
  Coche c;
  c.leer_coche();
  list<Coche>::iterator it = aparcamiento.begin();   
  aparcamiento.insert(it,c);
  plazas_libres--;
}

void Parking::sacar_coche(int num_plazas) {
  Coche c;
  c.leer_coche();
  list<Coche>::iterator it = aparcamiento.begin();   
  bool trobat = false;
  while(it != aparcamiento.end() and not trobat) {
    Coche aux = *it;
    if(c.get_matricula() == it.get_matricula()) {
      aparcamiento.erase(it);
      plazas_libres++;
      trobat = true;
    } 
    ++it;
    
  }
}

int Parking::get_plazas_libres() {
  return plazas libres;
}
