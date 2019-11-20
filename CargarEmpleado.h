#ifndef CARGAREMPLEADO_H_INCLUDED
#define CARGAREMPLEADO_H_INCLUDED

#include "class.h"
#include "FuncionesRamiro.h"
#include "menuClientes.h"

void cargarEmpleado();
void listarEmpleados();
void modificarEmpleados();

#include "CargarEmpleado.h"


int MenuEmpleados(){
    setlocale(LC_ALL,"spanish");
    int opcion;
    while(true){
    system("cls");
    cout << "ELIJA UNA CATEGORIA" <<endl;
    cout << "--------------" <<endl;
    cout << "1)Cargar Empleado " <<endl;
    cout << "2)Mostrar Empleados " <<endl;
    cout << "3)Modificar Empleado " <<endl;
    cout << "4) " <<endl;
    cout << "5) " <<endl;
    cout << "0)Volver " << endl;
    cout << "--------------" <<endl;
    cout << "Ingrese opcion:" << endl;
    cin >> opcion;
    system ("cls");
    switch(opcion){
    case 0:
       return -1;
    break;
    case 1:
        cargarEmpleado();
    break;
    case 2:
        listarEmpleados();
    break;
    case 3:
        modificarEmpleados();
    break;
    case 4:
//        EmpleadosActivosInactivos();
    break;
//    case 5:
//        reportes();
//    break;
//    case 6:
//    break;
//    case 7:
//
//    break;
//    case 8:
//
//    break;
//    case 9:
//
//    break;
//    case 10:
//
//    break;
//    case 11:
//    break;
//    case 12:
//    break;
//    case 13:
//    break;
//    case 14:

        }
    }
}




void cargarEmpleado(){
    setlocale(LC_ALL,"spanish");
    class Empleados reg;
    int opcion;
    system("cls");
    cout << "ELIJA UNA CATEGORIA" <<endl;
    cout << "--------------" <<endl;
    cout << "1) LIMPIEZA" <<endl;
    cout << "2) ADMINISTRACION" <<endl;
    cout << "3) SEGURIDAD" <<endl;
    cout << "4) MANTENIMIENTO" <<endl;
    cout << "5) OTROS" <<endl;
    cout << "0) Volver " << endl;
    cout << "--------------" <<endl;
    cout << "Ingrese opcion:" << endl;
    cin >> opcion;
    system ("cls");
    switch(opcion){
    case 0:
       return ;
    break;
    case 1:
        {
        reg.setArea("Limpieza");
        reg.Cargar();
        int aux = buscarId(reg);
        reg.setId(aux);
        reg.EscribirEnDisco();
        }
    break;
    case 2:
        {
        reg.setArea("Administracion");
        reg.Cargar();
        int aux = buscarId(reg);
        reg.setId(aux);
        reg.EscribirEnDisco();
        }
    break;
    case 3:
        {
        reg.setArea("Seguridad");
        reg.Cargar();
        int aux = buscarId(reg);
        reg.setId(aux);
        reg.EscribirEnDisco();
        }
    break;
    case 4:
        {
        reg.setArea("Mantenimiento");
        reg.Cargar();
        int aux = buscarId(reg);
        reg.setId(aux);
        reg.EscribirEnDisco();
        }
    break;
    case 5:
        {
        reg.setArea("otros");
        reg.Cargar();
        int aux = buscarId(reg);
        reg.setId(aux);
        reg.EscribirEnDisco();
        }
    break;
        }

}



void Personaa::Cargar()
	{

    fflush(stdin);
    do{
	cout<<"Ingrese el nombre: ";
	cin.getline(nombres,50);
    }while(comprobarNombresApellidos(nombres)==-1);
    do{
	cout<<"Ingrese el apellido: ";
	cin.getline(apellidos,50);
    }while(comprobarNombresApellidos(apellidos)==-1);
	cout<<"Ingrese la fecha de nacimiento: ";
	fecha_nac.cargar();
	cout<<"Ingrese la direccion: ";
	domicilio.cargar();
	fflush(stdin);
    do{
	cout<<"Ingrese el numero de documento: ";
	cin.getline(dni,20);
	}while(comprobarCadNumericas(dni)==-1 || buscarDNI(dni)==false);
	do{
	cout<<"Ingrese el numero de telefono(sin 0 y 15): ";
	cin.getline(telefono,20);
	}while(comprobarCadNumericas(telefono)==-1);
	}
void Personaa::Mostrar()
	{
	cout<<"Nombre: ";
	cout<<nombres<<endl;
	cout<<"Apellido: ";
	cout<<apellidos<<endl;
	cout << "FECHA DE NACIMIENTO ---> " ; fecha_nac.mostrarConBarra();
	cout<<"Domicilio: "<< endl;
	domicilio.mostrar();
	cout<<"Documento: ";
	cout<<dni<<endl;
	cout<<"Telefono: ";
	cout<<telefono<<endl;
	}
void Empleados::Cargar(){
    Personaa::Cargar();
    do{
    cout << "Ingrese Genero(F o M)" << endl;
    cin.getline(Genero,2);
    }while(comprobarGenero(Genero)==-1);
    do{
    cout << "ingrese Turno" << endl;
    cin.getline(Turno,10);
    }while(comprobarTurno(Turno)==-1);
    do{
    cout << "Ingrese Sueldo" << endl;
    cin.getline(Sueldo,10);
    }while(comprobarSueldo(Sueldo)==-1);
    do{
    cout << "Ingrese Cuil" << endl;
    cin.getline(Cuil,15);
    }while(comprobarCuil(Cuil,dni)==-1 || comprobarCadNumericas(Cuil)==-1);
    strcpy(ActivoInactivo,"Activo");
}



void Empleados::Mostrar(){
    Personaa::Mostrar();
    cout << "Id: " << Id << endl;
    cout << "Genero: " << Genero << endl;
    cout << "Area: " << Area << endl;
    cout << "Turno: " << Turno << endl;
    cout << "Sueldo: $" << Sueldo << endl;
    cout << "Cuil: " << Cuil << endl;
    cout << "Estado " << ActivoInactivo << endl;
}

///LISTAR EMPLEADOS
#include "class.h"


void ListarTodosLosEmpleados(Empleados);
void ListarTodosLosEmpleadosApellido(Empleados);

void listarEmpleados(){
    setlocale(LC_ALL,"spanish");
    class Empleados reg;
    int opcion;
    system("cls");
    cout << "ELIJA UNA CATEGORIA" <<endl;
    cout << "--------------" <<endl;
    cout << "1) Listar todos los empleados" <<endl;
    cout << "2) Listar todos los empleados ordenados alfabeticamente por apellido" <<endl;
    cout << "3) " <<endl;
    cout << "4) " <<endl;
    cout << "5) " <<endl;
    cout << "0)Volver " << endl;
    cout << "--------------" <<endl;
    cout << "Ingrese opcion:" << endl;
    cin >> opcion;
    system ("cls");
    switch(opcion){
    case 0:
       return ;
    break;
    case 1:
        ListarTodosLosEmpleados(reg);
        system("pause");
    break;
    case 2:

    break;
    case 3:

    break;
    case 4:

    break;
    case 5:

    break;
        }

}



void ListarTodosLosEmpleados(Empleados reg){
    int pos=0;
    while(reg.LeerDeDisco(pos++)){
        reg.Mostrar();
    }
}

void ListarTodosLosEmpleadosApellido(Empleados reg){
    int pos=0;
    while(reg.LeerDeDisco(pos++)){

    }
}
///MODIFICAR EMPLEADOS
void modificarTodoElEmpleado();

void modificarEmpleados(){
    setlocale(LC_ALL,"spanish");
    class Empleados reg;
    int opcion;
    system("cls");
    cout << "ELIJA UNA CATEGORIA" <<endl;
    cout << "--------------" <<endl;
    cout << "1) Modicar todo el empleado " <<endl;
    cout << "2) " <<endl;
    cout << "3) " <<endl;
    cout << "4) " <<endl;
    cout << "5) " <<endl;
    cout << "0)Volver " << endl;
    cout << "--------------" <<endl;
    cout << "Ingrese opcion:" << endl;
    cin >> opcion;
    system ("cls");
    switch(opcion){
    case 0:
       return ;
    break;
    case 1:
        modificarTodoElEmpleado();
    break;
    case 2:

    break;
    case 3:

    break;
    case 4:

    break;
    case 5:

    break;
        }

}
bool buscarId(int id){
    Empleados buscar;
    int pos=0;
    while(buscar.LeerDeDisco(pos++)){
        if(id==buscar.getId()){
            return pos;
        }
    }
    return -1;
}
void modificarTodoElEmpleado(){
    int id;
    cout << "Ingrese Id del Empleado" << endl;
    cin >> id;
    int aux = buscarId(id);
    if(aux==-1){ cout << "No se encontro el Id" << endl; system("pause"); return ;}
    Empleados reg;
    reg.Cargar();
    reg.EscribirEnDisco();
}
///EMPLEADOS ACTIVOS INACTIVOS
void EmpleadoActivo(void);
void EmpleadoInactivo(void);
void EmpleadosActivosInactivos(){
    class Empleados reg;
    int opcion;
    system("cls");
    cout << "ELIJA UNA CATEGORIA" <<endl;
    cout << "--------------" <<endl;
    cout << "1) Cambiar estado de empleado a Activo" <<endl;
    cout << "2) Cambiar estado de empleado a Inactivo" <<endl;
    cout << "0) Volver " << endl;
    cout << "--------------" <<endl;
    cout << "Ingrese opcion:" << endl;
    cin >> opcion;
    system ("cls");
    switch(opcion){
    case 0:
       return ;
    break;
    case 1:
//        EmpleadoActivo();
    break;
    case 2:
//        EmpleadoInactivo();
    break;
    }
}

//void EmpleadoActivo(){
//    int dni;
//    bool aux;
//    cout << "ingrese el DNI del empleado que quiere dar de Alta" << endl;
//    cin >> dni;
//    aux = buscarDNI(dni);
//    if(aux==true){cout << "No se encontro el dni" << endl; return;}
//    while()
//}

#endif // CARGAREMPLEADO_H_INCLUDED



