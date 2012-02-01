#include <iostream>
#include <list>
#include <queue>
#include "Coche.hpp"
using namespace std;

class Parking {

private:
  list<Coche> aparcamiento;
  queue<Coche> cola_entrada;
  int plazas_libres;
  int precio;

public:
  Parking();
  ~Parking();
  void meter_coche();
  void sacar_coche();
  int get_plazas_libres();
  int get_precio();
  void leer_parking();
  void imprimir();

};
