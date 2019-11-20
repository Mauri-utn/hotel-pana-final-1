#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

#include "misfunciones.h"
#include "menuHabitaciones.h"
#include "CargarEmpleado.h"
#include "menuReservas.h"
int menuConfiguracion();


void nuevaHabitacionTipo();
void consultarHabitaciones();
void crearHabitacion();

void realizarBackUp();
void restaurarBackUp();


/// HABITACIONES ///
void nuevaHabitacionTipo(){

Tipo_habitacion reg;
reg.cargar();
if(reg.escribirEnDisco()){
cout << "\t\tNuevo tipo de habitación cargada "<< endl;
pausa();
}

}

void consultarHabitaciones(){
Tipo_habitacion reg;
int pos=0;
while(reg.leerDeDisco(pos++)==1){
reg.mostrar();
}
pausa();

}



void crearHabitacion(){
Habitacion reg;
reg.cargar();

if(reg.escribirEnDisco()){
   cout << "\t\tHabitación creada con éxito" << endl;
   pausa();
   }
}

/// FIN HABITACIONES ///
/// BACK UPS ///


//void backUpConsumos(){

//    FILE *p;
//    p = fopen("consumos.dat","rb");
//    FILE *b;
//    b = fopen("consumos.bkp","wb");
//    if(p == NULL){
//        cout << "ERROR: no se encontro el archivo " << endl;
//        return ;
//    }
//    if(b == NULL){
//        cout << "ERROR: no se encontro el archivo " << endl;
//        return ;
//    }
//    Consumo reg;
//    while(fread(&reg,sizeof reg,1,p)==1){
//        fwrite(&reg,sizeof reg,1,b);
//    }
//    fclose(p);
//    fclose(b);
//    cout << "BackUp de Consumos realizado con exito" << endl;
//    cout << endl;
//    system("pause");
//}


void backUpHabitaciones(){
    FILE *p;
    p = fopen("habitaciones.dat","rb");
    FILE *b;
    b = fopen("habitaciones.bkp","wb");
    if(p == NULL){
        cout << "\t\tERROR: no se encontró el archivo " << endl;
        return ;
    }
    if(b == NULL){
        cout << "\t\tERROR: no se encontró el archivo " << endl;
        return ;
    }
    Habitacion reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        fwrite(&reg,sizeof reg,1,b);
    }
    fclose(p);
    fclose(b);
    cout << "\t\tBackUp de habitaciones realizado con éxito" << endl;
    cout << endl;
    system("pause");
} /// fin backup habitaciones




void backUpGastos(){
    FILE *p;
    p = fopen(FILE_VENTAS,"rb");
    FILE *b;
    b = fopen("ventas.bkp","wb");
    if(p == NULL){
        cout << "\t\tERROR: no se encontró el archivo " << endl;
        return ;
    }
    if(b == NULL){
        cout << "\t\tERROR: no se encontró el archivo " << endl;
        return ;
    }
    Gasto reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        fwrite(&reg,sizeof reg,1,b);
    }
    fclose(p);
    fclose(b);
    cout << "\t\tBackUp de ventas realizado con éxito" << endl;
    cout << endl;
    system("pause");
} /// fin back up ventas



void backUpEmpleados(){
    FILE *p;
    p = fopen("empleados.dat","rb");
    FILE *b;
    b = fopen("empleados.bkp","wb");
    if(p == NULL){
        cout << "\t\tERROR: no se encontró el archivo " << endl;
        return ;
    }
    if(b == NULL){
        cout << "\t\tERROR: no se encontró el archivo " << endl;
        return ;
    }
    Empleados reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        fwrite(&reg,sizeof reg,1,b);
    }
    fclose(p);
    fclose(b);
    cout << "\t\tBackUp de empleados realizado con éxito" << endl;
    cout << endl;
    system("pause");
} /// fin back up empleados

//void restaurarBackUpConsumos(){
//    FILE *p;
//    p = fopen("consumos.bkp","rb");
//    FILE *b;
//    b = fopen("consumos.dat","wb");
//    if(p == NULL){
//        cout << "ERROR: no se encontro el archivo " << endl;
//        return ;
//    }
//    if(b == NULL){
//        cout << "ERROR: no se encontro el archivo " << endl;
//        return ;
//    }
//    Consumo reg;
//    while(fread(&reg,sizeof reg,1,p)==1){
//        fwrite(&reg,sizeof reg,1,b);
//    }
//    fclose(p);
//    fclose(b);
//    cout << "Restauracion de Consumos realizado con exito" << endl;
//    cout << endl;
//    system("pause");
//}

void restaurarBackUpHabitaciones(){
    FILE *p;
    p = fopen("habitaciones.bkp","rb");
    FILE *b;
    b = fopen("habitaciones.dat","wb");
    if(p == NULL){
        cout << "\t\tERROR: no se encontró el archivo " << endl;
        return ;
    }
    if(b == NULL){
        cout << "\t\tERROR: no se encontró el archivo " << endl;
        return ;
    }
    Habitacion reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        fwrite(&reg,sizeof reg,1,b);
    }
    fclose(p);
    fclose(b);
    cout << "\t\tRestauracion de habitaciones realizado con éxito" << endl;
    cout << endl;
    system("pause");
} /// fin  restaurar back up habitaciones ///


void restaurarBackUpGastos(){
    FILE *p;
    p = fopen("ventas.bkp","rb");
    FILE *b;
    b = fopen(FILE_VENTAS,"wb");
    if(p == NULL){
        cout << "\t\tERROR: no se encontró el archivo " << endl;
        return ;
    }
    if(b == NULL){
        cout << "\t\tERROR: no se encontró el archivo " << endl;
        return ;
    }
    Gasto reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        fwrite(&reg,sizeof reg,1,b);
    }
    fclose(p);
    fclose(b);
    cout << "\t\trestauracion de ventas realizado con éxito" << endl;
    cout << endl;
    system("pause");
}/// fin  restaurar back up ventas ///



void restaurarBackUpEmpleados(){
    FILE *p;
    p = fopen("empleados.bkp","rb");
    FILE *b;
    b = fopen("empleados.dat","wb");
    if(p == NULL){
        cout << "\t\tERROR: no se encontró el archivo " << endl;
        return ;
    }
    if(b == NULL){
        cout << "\t\tERROR: no se encontró el archivo " << endl;
        return ;
    }
    Empleados reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        fwrite(&reg,sizeof reg,1,b);
    }
    fclose(p);
    fclose(b);
    cout << "\t\trestauracion de empleados realizado con éxito" << endl;
    cout << endl;
    system("pause");
}/// fin  restaurar back up empleados ///




void realizarBackUp(){
///    backUpConsumos();
    backUpHabitaciones();
    backUpGastos();
    backUpEmpleados();
}
void restaurarBackUp(){
///    RestaurarBackUpConsumos();
    restaurarBackUpHabitaciones();
    restaurarBackUpGastos();
    restaurarBackUpEmpleados();
}



int menuConfiguracion(){
char opcion;
while(true){
    borrarPantalla();
    cout << "\t\t ----MENU CONFIGURACIÓN----" << endl;
    cout << "\t\t --------------------------" << endl;
    cout << "\t\t1) CREAR NUEVA HABITACIÓN               "<< endl;
    cout << "\t\t2) CREAR NUEVA TIPO DE HABITACIÓN       " << endl; /// crea una nueva habitacion
    cout << "\t\t3) MOSTRAR TIPO DE HABITACIONES         " << endl; /// consulta habitaciones disponibles
    cout << "\t\t4) REALIZAR BACKUP" <<endl;
    cout << "\t\t5) RESTAURAR BACKUP" <<endl;
    cout << "\t\t0) Salir "<< endl;
    cout << "\t\t   Opción: ";
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
  case '1':
      crearHabitacion();
    break;
  case '2':
      nuevaHabitacionTipo();
    break;
  case '3':
      consultarHabitaciones();
    break;
  case '4':
    realizarBackUp();
    break;
  case '5':
    restaurarBackUp();
    break;
      case '0':
        return 0;
      break;
    }
    cout << endl;

  }

}



#endif // MENUCONFIGURACION_H_INCLUDED
