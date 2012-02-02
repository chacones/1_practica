#include <iostream>
using namespace std;

class Coche {

private:
  int matricula;
  int hora_entrada, hora_salida;

public:
  Coche();
  ~Coche();
  int get_matricula();
  int get_hora_entrada();
  int get_hora_salida();
  void leer_coche_entrada();
  void leer_coche_salida();
  void imprimir_coche();
};

