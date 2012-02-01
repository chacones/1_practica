#include "Parking.hpp"

Parking::Parking() {}

Parking::~Parking() {}

void Parking::meter_coche() {
  Coche c;
  c.leer_coche_entrada();

  if (plazas_libres == 0) {
    cola_entrada.push(c);
  }
  else {
    list<Coche>::iterator it = aparcamiento.begin();   
    aparcamiento.insert(it,c);
    plazas_libres--;
  }

}

void Parking::sacar_coche() {
  Coche c;
  c.leer_coche_salida();
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

int Parking::get_precio() {
  return precio;
}


void Parking::leer_parking() {
  cin >> precio >> plazas_libres;
}


void Parking::imprimir() {
  list<Coche>::iterator it = aparcamiento.begin();   
  while(it != aparcamiento.end()) {
    cout << (*it).get_matricula() << endl;
    ++it;
  }
}
