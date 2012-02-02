#include "Parking.hpp"

Parking::Parking() {}

Parking::~Parking() {}

void Parking::meter_coche() {
  Aparcado a;
  Coche c;
  c.leer_coche();
  a.set_coche(c);
  cin >> hora_entrada;
  a.set_hora_entrada(hora_entrada);

  if (plazas_libres == 0) {
    cola_entrada.push(a);
  }
  else {
    list<Coche>::iterator it = aparcamiento.begin();   
    aparcamiento.insert(it,a);
    plazas_libres--;
  }
  //cout << a.get_hora_entrada() << endl;
}

void Parking::sacar_coche() {
  Aparcado a;
  Coche c;
  c.leer_coche();
  a.set_coche(c);
  cin >> hora_entrada;
  a.set_hora_entrada(hora_entrada);

  list<Coche>::iterator it = aparcamiento.begin();   
  bool trobat = false;
  while(it != aparcamiento.end() and not trobat) {
    Coche aux = *it;
    if(c.get_matricula() == aux.get_matricula()) {
      //imprimir_coche();
      aparcamiento.erase(it);
      plazas_libres++;
      trobat = true;
      //cout << "ENTRADA: " << c.get_hora_entrada() << endl;
      //cout << "SALIDA: " << c.get_hora_salida() << endl;
      ingresos += (precio*(a.get_hora_salida()-a.get_hora_entrada()));
    } 
    ++it;    
  }
  if(trobat and not cola_entrada.empty()) { 
    c = cola_entrada.front();
    a.set_coche(c);
    cola_entrada.pop();
    list<Coche>::iterator it = aparcamiento.begin();   
    aparcamiento.insert(it,a);
    plazas_libres--;
  }
}

int Parking::get_plazas_libres() {
  return plazas_libres;
}

int Parking::get_precio() {
  return precio;
}

int Parking::get_ingresos() {
  return ingresos;
}

void Parking::leer_parking() {
  ingresos = 0;
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
