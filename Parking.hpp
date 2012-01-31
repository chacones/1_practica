#include <iostream>
#include <list>
#include "Coche.hpp"
using namespace std;

class Parking {

private:
  list<Coche> aparcamiento;
  int plazas_libres;

public:
  Parking();
  ~Parking();
  void meter_coche();
  void sacar_coche();
  int get_plazas_libres();
  void leer_parking();

};
