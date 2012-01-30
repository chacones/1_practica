/* Diseño modular: Aparcamiento para coches.
Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos un modulo para representar el Parking en el que se desarrollaran las tareas. Ademas utilizaremos la clase Coche para lograr estas acciones. 
*/

#include "Parking.hpp"
#include "utils.PRO2"

using namespace std;

int main() {
  Parking p;
  int tarea;
  int num_plazas;
  cin >> num_plazas;

  while(cin >> tarea and tarea != -1) {
    if(tarea == 1) {
      p.meter_coche(num_plazas);
    }
    else if(tarea == 2) {
      p.sacar_coche(num_plazas);
    }
    else {
      cout << p.get_plazas_libres() << endl;
    }
  }
}
