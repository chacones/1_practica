#include "Parking.hpp"
#define HORAS_DIA 24

Parking::Parking() {}

Parking::~Parking() {}

void Parking::meter_coche() {
  Aparcado a;
  Coche c;
  int hora_entrada;
  c.leer_coche();
  a.set_coche(c);
  cin >> hora_entrada;
  a.set_hora_entrada(hora_entrada);

  if (plazas_libres == 0) {
    cola_entrada.push(c);
  }
  else meter_coche(a);
}

void Parking::sacar_coche() {
  Coche c;
  int hora_salida;
  c.leer_coche();
  cin >> hora_salida;

  list<Aparcado>::iterator it = aparcamiento.begin();   
  bool trobat = false;
  while(it != aparcamiento.end() and not trobat) {
    Aparcado aux = *it;
    aux.set_hora_salida(hora_salida);
    Coche a = aux.get_coche();
    if(c.get_matricula() == a.get_matricula()) {
      aparcamiento.erase(it);
      plazas_libres++;
      trobat = true;
      int ingresos_coche = calcular_ingresos(aux);
      ingresos_dia += ingresos_coche;
      ingresos += ingresos_coche;
      if(ingresos_dia > max_ingreso) max_ingreso = ingresos_dia;
    } 
    ++it;    
  }
  if(trobat and not cola_entrada.empty()) 
    meter_coche_esperando_en_entrada(hora_salida);
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

int Parking::get_ingresos_diario() {
  return ingresos_dia;
}

int Parking::get_max_ingreso() {
  return max_ingreso;
}

void Parking::leer_parking() {
  ingresos = 0;
  ingresos_dia = 0;
  max_ingreso = 0;
  cin >> plazas_libres >> precio;
}


void Parking::imprimir() {
  cout << "IMPRIMIR PARKING: " << endl;
  list<Aparcado>::iterator it = aparcamiento.begin();   
  while(it != aparcamiento.end()) {
    Coche c = (*it).get_coche();
    cout << c.get_matricula() << endl;
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

void Parking::siguiente_dia() {
  list<Aparcado>::iterator it = aparcamiento.begin();   
  while (it != aparcamiento.end()) {
    int dias = it->get_dias_aparcado() + 1;
    it->set_dias_aparcado(dias);
    ++it;
  }
  ingresos_dia = 0;
}

int Parking::calcular_ingresos(Aparcado aux) {
  int resultado = 0;
  if(aux.get_dias_aparcado() == 0){
    resultado = precio*(aux.get_hora_salida()-aux.get_hora_entrada());
  }
  else if(aux.get_dias_aparcado() >= 1) {
    resultado = (HORAS_DIA - aux.get_hora_entrada()) * precio;
    resultado += aux.get_hora_salida() * precio;
    
    if(aux.get_dias_aparcado() > 1) {
      resultado += HORAS_DIA * (aux.get_dias_aparcado()-1);
    }
  }
  return resultado;
}


void Parking::meter_coche(Aparcado a) {
  list<Aparcado>::iterator it = aparcamiento.begin();   
  aparcamiento.insert(it,a);
  plazas_libres--;
}


void Parking::meter_coche_esperando_en_entrada(int hora_salida) {
  Aparcado a;
  Coche c = cola_entrada.front();
  a.set_coche(c);
  a.set_hora_entrada(hora_salida);
  a.set_hora_salida(-1);
  a.set_dias_aparcado(0);
  cola_entrada.pop();
  meter_coche(a);
}

