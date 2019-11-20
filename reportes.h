
#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED
#include "caja.h"
#include "misfunciones.h"

int menuReportes();
void reporteDiario();

int menuReportes(){

    cout << "En mantenimiento :) "<< endl;
    pausa();
    return -1;

short opcion;
while(true){
    borrarPantalla();
    cout << "\t\t-------MENÚ REPORTES--------  " << endl;
    cout << "\t\t----------------------------- " << endl;
    cout << "\t\t1) REPORTE DIARIO             " << endl;
    cout << "\t\t2) REPORTE MENSUAL            " << endl;
    cout << "\t\t3) REPORTE ANUAL              " << endl;
    cout << "\t\t4) REPOTE POR FECHA           " << endl;
    cout << "\t\t0) Salir "<< endl;
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
      case 1:
          reporteDiario();
        pausa();
      break;
      case 2:
          cout << "En contruccion..."<<endl;

        pausa();
      break;
      case 3:
          cout << "En contruccion..."<<endl;
        pausa();
      break;
      case 4:
          cout << "En contruccion..."<<endl;
        pausa();
        break;
      case 0:
          return 0;
        break;
      default:
          mensajes(2);

        break;

        }
    }
}

void reporteDiario(){
    Caja reg;
    int i=0;
    while(reg.LeerDeDisco(i++)){
        cout << "dia: " << i << endl;
        cout << "Cantidad vendida:  ---> " << reg.getCierreCaja() << endl;

    }
    system("pause");
}

void reporteMensual(){ /// probar
    Caja reg;
    int i=0;
    while(reg.LeerDeDisco(i++)){
        cout << "mes " << i << endl;
        cout << "Cantidad vendida:  ---> " << reg.getCierreCaja() << endl;

    }
    system("pause");
}


#endif // REPORTES_H_INCLUDED

