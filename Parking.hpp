#include <iostream>
#include <list>
#include <queue>
#include "Aparcado.hpp"
using namespace std;

class Parking {

private:
  list<Aparcado> aparcamiento;
  queue<Coche> cola_entrada;
  int plazas_libres;
  int precio;
  int ingresos, ingresos_dia, max_ingreso;

public:
  Parking();
  ~Parking();
  void meter_coche();
  void sacar_coche();
  int get_plazas_libres();
  int get_precio();
  int get_ingresos();
  int get_ingresos_diario();
  int get_max_ingreso();
  void leer_parking();
  void imprimir();
  void siguiente_dia();
  int calcular_ingresos(Aparcado aux);
  void meter_coche(Aparcado a);
  void meter_coche_esperando_en_entrada(int hora_salida);

};
