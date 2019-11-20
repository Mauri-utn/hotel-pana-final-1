#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include <clocale>
#include <conio.h>
#include <vector>
#include <ctype.h>




using namespace std;
#include "menuPrincipal.h"
#include "menuClientes.h"
#include "misFunciones.h"
#include "menuHabitaciones.h"
#include "login_pass.h"
#include "menuReservas.h"

#include "productos.h"
#include "CargarEmpleado.h"
#include "FuncionesRamiro.h"
#include "class.h"
#include "reportes.h"

#include "menuConfiguracion.h"




///PROTOTIPO DE FUNCIONES
void abrirArchivos();
void cClientes();
void cHabitaciones();
void cEmpleados();
void cMenores();
void cConsumos();
void cGastos();
void cReservas();
void cProductos();
bool validarLogin(string);
bool validarContrasenia(string);
void cTipoHabitacion();
void cEstadias();
void cVentas();
void cHabitacionMantenimiento();
void cEgresos();


    int ingresar();
    /// ARCHIVOS
    ///const char *FILE_LOGIN = "usuarios.dat"; LOS LOGIN Y CONTRA SE AGREGARAN A LA CLASE EMPLEADOS PARA DIFERENCIARLOS


    const char *FILE_CONSUMOS     = "consumos.dat";
    const char *FILE_GASTOS       = "gastos.dat";



    /*const char Usuario[6] = "admin";
    const char contrasenia[5] = "7705";*/



void abrirArchivos(){


 cClientes();
 cHabitaciones();
 cEmpleados();
// cMenores();
 cConsumos();
 cGastos();
 cReservas();
 cProductos();
 cTipoHabitacion();
 cEstadias();
 cVentas();
 cHabitacionMantenimiento();
 cEgresos();
}


void cEgresos(){
FILE*P;
P=fopen(FILE_EGRESOS,"ab");
if(P==NULL){fclose(P);return;}
fclose(P);
return;

}

void cHabitacionMantenimiento(){
FILE*P;
P=fopen(FILE_MANTENIMIENTO,"ab");
if(P==NULL){fclose(P);return;}
fclose(P);
return;

}



void cVentas(){
FILE*P;
P=fopen(FILE_VENTAS,"ab");
if(P==NULL){fclose(P);return;}
fclose(P);
return;

}


void cEstadias(){

FILE*P;
P=fopen(FILE_ESTADIAS,"ab");
if(P==NULL){fclose(P);return;}
fclose(P);
return;

}

void cTipoHabitacion(){
FILE*P;
P=fopen(FILE_TIPO_HABITACION,"ab");
if(P==NULL){fclose(P);return;}
fclose(P);
return;
}

void cClientes(){
    FILE*C;
    C=fopen(FILE_CLIENTES,"ab");
    if(C==NULL){fclose(C);return;}
    fclose(C);
    return;
}
void cHabitaciones(){
    FILE*H;
    H=fopen(FILE_HABITACIONES,"ab");
    if(H==NULL){fclose(H);return;}
    fclose(H);
    return;
}
void cEmpleados(){
    FILE*E;
///    E=fopen(FILE_EMPLEADOS,"ab");
    if(E==NULL){fclose(E);return;}
    fclose(E);
    return;
}
/*void cMenores(){
    FILE*M;
    M=fopen(FILE_MENORES,"ab");
    if(M==NULL)return;
    fclose(M);
    return;
}*/
void cConsumos(){
    FILE*C;
    C=fopen(FILE_CONSUMOS,"ab");
    if(C==NULL){fclose(C);return;}
    fclose(C);
    return;
}
void cGastos(){

    FILE*G;
    G=fopen(FILE_GASTOS,"ab");
    if(G==NULL){fclose(G);return;}
    fclose(G);
    return;
}
void cReservas(){

    FILE*R;
    R=fopen(FILE_RESERVAS,"ab");
    if(R==NULL){fclose(R);return;}
    fclose(R);
    return;

}
void cProductos(){
    FILE*P;
    P=fopen(FILE_PRODUCTOS,"ab");
    if(P==NULL){fclose(P);return;}
    fclose(P);
    return;

}




int main(){

abrirArchivos();
setlocale (LC_ALL, "spanish");
int login;
char cerrar[2];
 while(true){
    borrarPantalla();
    char opc;
    system("color 8F");
    cout << "\t\t1)INGRESAR                     --->"<<endl;
    cout << "\t\t2)RECUPERAR CONTRASEÑA         --->"<<endl;
    cout << "\t\t3)CAMBIAR CONTRASEÑA           --->"<<endl;
    cout << "\t\t0)SALIR                        --->"<<endl;
    cout << "\t\tOPCIÓN: ";
    cin  >> opc;
    switch(opc){
      case '1':
      case 'a':
      case 'A':

    login=ingresar();
    if(login>=1)menuPrincipal(login);

            break;

      case '2':
      case 'b':
      case 'B':
///            menuLogins(opc);
        break;

      case '3':
      case 'c':
      case 'C':
///          menuLogins(opc);
        break;
      case '0':
          cout << "\t\t¿Seguro que quiere cerrar el programa?"<< endl;
            cout << "\t\tsi-no: ";
            cin  >>  cerrar;
            if (strcmp(cerrar,"si")==0){
                return 0;
            }
        break;
      default:
        break;
    }

 }

pausa();
return 0;
}

int ingresar(){

    vector<string>usuarios;
    vector<string>claves;

    /// USUARIOS ///
    usuarios.push_back("admin"); /// permiso 1
    usuarios.push_back("limpieza01"); /// permiso 2
    usuarios.push_back("mante01"); /// permiso 3
    usuarios.push_back("gerente29"); /// permiso 1
    /// CONTRASEÑAS ///
    claves.push_back("7705");
    claves.push_back("londres2012");
    claves.push_back("brasil2014");
    claves.push_back("7732");


int permiso;
int contador = 0;
bool ingresa=false;
do {
borrarPantalla();
if(contador==0){
    cin.ignore();
}
 string user,pass;
cout << "\t\t\tLOGIN DE USUARIO"<<endl;
cout << "\t\t\t-----------------"<<endl;
cout << "\n\tUsuario: ";
getline(cin,user);
cout << "\tContraseña: ";
//getline(cin,pass);
char caracter;
caracter = getch();
pass = "";
while (caracter!=13){
        if (caracter != 8){
     pass.push_back(caracter);
    cout << "*";
        }
        else{

            if(pass.length() > 0){
                cout << "\b \b";
                pass = pass.substr(0,pass.length() - 1);
            }
        }

    caracter = getch();

}

for(int i=0;i<usuarios.size();i++){

    if(usuarios[i]==user&&claves[i]==pass){
        ingresa=true;
        if (user==usuarios[0])permiso=1;
        if (user==usuarios[1])permiso=2;
        if (user==usuarios[2])permiso=3;
        if (user==usuarios[3])permiso=1;
        break;
    }
}

/*if ((Usuario==user)&&(contrasenia==pass)||(validarContrasenia(pass))&&(validarLogin(user))){
    ingresa = true;
}*/
if(!ingresa){

    cout << "\n\tEl usuario y/o password son incorrectos "<< endl;
    pausa();
    contador ++;
}


} while( ingresa==false && contador < 3 ); /// FIN DO WHILE

if ( ingresa==false ){

    cout << "\n\tUsted no pudo ingresar al sistema "<< endl;
    pausa();
    return -1;

    }
else {

    cout << "\n\tBienvenido al sistema "<<endl;
    pausa();
    return permiso;

}

}

bool validarContrasenia(string pasw){
/*FILE *P;
P=fopen(FILE_EMPLEADOS,"rb");
if(P==NULL)return false;
Empleado aux;
while(fread(&aux,sizeof(Empleado),1,P)==1){
    if(pasw==aux.getContra())
        fclose(P);
    return true;
}
fclose(P);*/
return false;

}

bool validarLogin(string log){
/*FILE *P;
P=fopen(FILE_EMPLEADOS,"rb");
if(P==NULL)return false;
Empleado aux;
while(fread(&aux,sizeof(Empleado),1,P)==1){
    if(log==aux.getLegajo())
        fclose(P);
    return true;
}
fclose(P);*/
return false;

}
