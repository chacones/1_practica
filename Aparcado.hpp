/* Representa a un concepto o una idea que es cuando un coche aparca en el parking
*/

#include <iostream>
#include "Coche.hpp"
using namespace std;

class Aparcado {

private:
  Coche coche;
  int hora_entrada, hora_salida;
  int dias_aparcado;

public:
  Aparcado();
  ~Aparcado();
  int get_hora_entrada();
  int get_hora_salida();
  int get_dias_aparcado();
  Coche get_coche();
  void imprimir();
  void set_hora_entrada(int h);
  void set_hora_salida(int h);
  void set_coche(Coche c);
  void set_dias_aparcado(int d);

};
