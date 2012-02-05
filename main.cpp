/* Diseño modular: Aparcamiento para coches.
Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos un modulo para representar el Parking en el que se desarrollaran las tareas. Ademas utilizaremos la clase Coche para lograr estas acciones. 
*/

#include "Parking.hpp"
#include "utils.PRO2"

using namespace std;

int main() {
  Parking p;
  int tarea;
  p.leer_parking();

  while(cin >> tarea and tarea != -1) {
    if(tarea == 1) {
      p.meter_coche();
    }
    else if(tarea == 2) {
      p.sacar_coche();
    }
    else if(tarea == 3) {
      cout << p.get_plazas_libres() << endl;
    }
    else if(tarea == 4) {
      cout << p.get_ingresos() << endl;
    }
    else if(tarea == 5) {
      cout << p.get_ingresos_diario() << endl;
    }
    else if(tarea == 6) {
      cout << p.get_max_ingreso() << endl;
    }
    else if(tarea == 7) {
      p.siguiente_dia();
    }
  }
  //p.imprimir();
}
