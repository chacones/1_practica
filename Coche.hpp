#include <iostream>
using namespace std;

class Coche {

private:
  int matricula;

public:
  Coche();
  ~Coche();
  int get_matricula();
  void leer_coche();
  void imprimir_coche();
};

