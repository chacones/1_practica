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
  void meter_coche(int num_plazas);
  void sacar_coche(int num_plazas);
  int get_plazas_libres();

};
