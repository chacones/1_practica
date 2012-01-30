#include "Parking.hpp"

Parking::Parking() {}

Parking::~Parking() {}

void Parking::meter_coche(int num_plazas) {
  Coche c;
  c.leer_coche();
  list<Coche>::iterator it = aparcamiento.begin();
  it = num_plazas - plazas_libres + 1;
}

void Parking::sacar_coche(int num_plazas) {
  Coche c;
  c.leer_coche();

}

int Parking::get_plazas_libres() {
  return plazas libres;
}
