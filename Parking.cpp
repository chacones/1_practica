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
  if(trobat and not cola_entrada.empty()) { 
    c = cola_entrada.front();
    cola_entrada.pop();
    list<Coche>::iterator it = aparcamiento.begin();   
    aparcamiento.insert(it,c);
    plazas_libres--;
  }
}

int Parking::get_plazas_libres() {
  return plazas_libres;
}

int Parking::get_precio() {
  return precio;
}


void Parking::leer_parking() {
  cin >> plazas_libres >> precio;
}


void Parking::imprimir() {
  cout << "IMPRIMIR PARKING: " << endl;
  list<Coche>::iterator it = aparcamiento.begin();   
  while(it != aparcamiento.end()) {
    cout << (*it).get_matricula() << endl;
    ++it;
  }
  cout << endl << "IMPRIMIR COLA: " << endl;
  Coche c;
  while (not cola_entrada.empty()) {
    c = cola_entrada.front();
    cout << c.get_matricula() << endl;
    cola_entrada.pop();
  }
  cout << endl;
}
