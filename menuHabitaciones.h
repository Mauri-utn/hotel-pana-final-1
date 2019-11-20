#ifndef MENUHABITACIONES_H_INCLUDED
//#include "menuClientes.h"
//#include "misFunciones.h"
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<time.h>
#include"string.h"
#include <conio.h>
#include"menuClientes.h"
//#include"misFunciones.h"
#define MENUHABITACIONES_H_INCLUDED




using namespace std;
#include "misFunciones.h"
#include "menuReservas.h"
#include "productos.h"
#include "caja.h"



 const char *FILE_TIPO_HABITACION = "tipo_habitacion.dat";
 const char *FILE_HABITACIONES = "habitaciones.dat";
 const char *FILE_ESTADIAS = "habitacion_ocupada.dat";
 const char *FILE_VENTAS = "ventas.dat";
 const char *FILE_MANTENIMIENTO = "mantenimiento.dat";
int menuHabitaciones();


int contarTiposHabitaciones();/// devuelve la cantidad de registros que tiene el archivo tipo habitacion
bool verificarTipoHabitacion(char*);
int CodigoTipoHabitacion();
int mostrarHabitaciones();
void mostrarTodasHabitaciones();
void mostrarHabLibres();
void mostrarHabOcupadas();
void mostrarHabEnLimpieza();
void mostrarHabEnMantenimiento(); /// funcion del menu mostrar habitaciones , no muestra detalles solo las que estan en mantenimiento, muestra clase Habitacion
bool verificarNumeroHabitacion(char*);
int asignarNumEstadia();
void cargarEstadia();
const char* asignarHabitacion(char);
int letra_a_entero(char);
void realizarCheckOut();
int contarRegistrosHabitaciones();
bool liberarHabitacion(const char*);
int contarHabitaciones(char);
int buscarHabitacionOcupada(const char*);
int buscarVentaId(int);
void mostrarVenta();
void mostrarVentasCaja(int);

bool verificarVenta(const char*);
float totalFacturado(int);
int buscarHabitacionTipo(const char*);
bool fechaPasado(Fecha);
int sectorMantenimiento();
bool verifMantenimiento(const char*);
void sacar_de_mantenimiento();
void cargarParaMantenimiento();
void HabitacionesMantenimiento(); /// funcion del menu mantenimiento, muestra detalles , muestra clase Habitacion_mantenimiento
void mostrarTodas_Mantenimiento();/// las muestra todas ordenadas por numero ///
void listarHabMantenimiento(); /// ingresas el numero de habitacion y lista los detalles de mantenimiento ///
int contarRegistrosMantenimiento();
void modificarMantenimiento();
void historialMantenimiento();/// menu para mostrar historial
void mostrarHistorialMante(); /// las muestra todas desde tipo fifo comun ---> desde la mas antigua
void buscarEnHistorialMante();


void menuVentas();
void mostrarVentaId();


int menuRecepcion();








class FechaSistema{
private:
    int anio,mes,dia,hora,minuto;
    time_t tiempo;
    char cad[80];
    struct tm *tmPtr;
public:
    FechaSistema(int a,int b,int c,int d,int e)
    {
        anio=a;
        mes=b;
        dia=c;
        hora=d;
        minuto=e;
    }
    FechaSistema()
    {
        tiempo = time(NULL);
        tmPtr = localtime(&tiempo);

        anio=tmPtr->tm_year+1900;
        mes=tmPtr->tm_mon+1;
        dia=tmPtr->tm_mday;
        hora=tmPtr->tm_hour;
        minuto=tmPtr->tm_min;
        /*printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
        strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
        printf("\n\n%s", cad);*/
    }
    int mostar_anio()
    {
        return anio;
    }
    int mostar_mes()
    {
        return mes;
    }
    int mostar_dia()
    {
        return dia;
    }
    int mostar_hora()
    {
        return hora;
    }
    int mostar_minuto()
    {
        return minuto;
    }
    void set_dia(int d)
    {
        dia=d;
    }
    void set_mes(int m)
    {
        mes=m;
    }
    void set_anio(int a)
    {
        anio=a;
    }
    void hora_standar()
    {
        hora=12;
        minuto=00;
    }
};


void convertir_fecha(char v[11],int vint[3])
{
    vint[0]=(((v[0]-'0')*10)+(v[1]-'0'));
    vint[1]=(((v[3]-'0')*10)+(v[4]-'0'));
    vint[2]=(((v[8]-'0')*10)+(v[9]-'0'))+2000;

}
bool comparar_fechas(char ini[11],char fin[11],int a,int m,int d)
{
    //if((a-1900>=strcat(ini[8],ini[9])-'0')&&(m>=strcat(ini[3],ini[4])-'0')&&(d>=strcat(ini[0],ini[1])-'0')&&(a-1900<=strcat(fin[8],fin[9])-'0')&&(m<=strcat(fin[3],fin[4])-'0')&&(d<=strcat(fin[0],fin[1])-'0'))
    int di1,di2,mi1,mi2,ai1,ai2,df1,df2,mf1,mf2,af1,af2;
    di1=ini[0]-'0';
    di2=ini[1]-'0';
    mi1=ini[3]-'0';
    mi2=ini[4]-'0';
    ai1=ini[8]-'0';
    ai2=ini[9]-'0';
    df1=fin[0]-'0';
    df2=fin[1]-'0';
    mf1=fin[3]-'0';
    mf2=fin[4]-'0';
    af1=fin[8]-'0';
    af2=fin[9]-'0';
    if((a-2000)>=((ai1*10)+ai2)&&(m>=((mi1*10)+mi2))&&(d>=(di1*10)+di2)&&(a-2000)<=((af1*10)+af2)&&(m<=(mf1*10)+mf2)&&(d<=(df1*10)+df2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
class Gasto
{
private:
    int id,tipo;
    char habitacion[4];
    float importe;
    char descripcion[240];
    FechaSistema fec;
public:
    void consulta_habitacion(); ///Muestra los gastos correspondientes al ultimo cambio de estado
    void consulta_total();///Muestra todos los gastos
    void consulta_habitacion_fecha(); ///Muestra los gastos dentro de 2 fechas
    void consulta_habitacion_tipo(); ///Muestra todos los gastos de la habitacion y tipo seleccionado
    float get_importe();///Devuelve el importe del gasto
    float get_total(); ///Devuelve el total del ultimo cambio de estado
    void cargar();///carga nuevo gasto
    void anular(); ///anula ultimo gasto
    void modificar(); ///modifica ultimo gasto
};


/// CLASE VENTA ///

class Venta{ /// luego cuando se muestran todas las ventas se forma la factura

private:

    int idCajaAbierta;
    char habitacion[4]; /// numero de habitacion a la cual pertenece
    int id;/// automatico , se relaciona con num de estadia /// luego al final se suman todas las ventas del num de estadia
    FechaSistema fec;/// fecha y hora del sistema ver como poner esto
    char codigoProducto[5];/// codigo de producto a vender
    int cantidad; /// cantidad de unidades a vender
    float total; /// total de la venta
    bool pagado;
    int numeroCaja;
    public:

        void cargar();
        void mostrar();
        /// gets
        int getCodigoCaja(){return idCajaAbierta;}
        int getId(){return id;}
        const char* getHabitacion(){return habitacion;}
       int getCantidad(){return cantidad;}
       const char* getCodProducto(){return codigoProducto;}
       float getTotal(){return total;}
       bool getPago(){return pagado;}
        /// sets
        void setCantidad(int nuevaCant){cantidad=nuevaCant;}
        void setCodigoProducto(const char*nuevoCod){strcpy(codigoProducto,nuevoCod);}
        void setTotal(float nuevoTotal){total=nuevoTotal;}
        /// funciones con archivos

        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);


};

int Venta::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;
	FILE *p;
	p=fopen(FILE_VENTAS,"rb");
	if(p==NULL)
		{
		mensajes(1);
		cout<<"\t\tPresione una tecla para continuar";
    system("pause<null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}



bool Venta::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_VENTAS,"rb+");
	if(p==NULL){
        mensajes(1);
        pausa();
        return false;
	}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	return true;
}

bool Venta::escribirEnDisco(){ /// graba un registro de reservas
FILE*P;
P=fopen(FILE_VENTAS,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}

int buscarVentaId(int cod){ ///devuelve la posicion de la venta en el archivo
	int pos=0;
	Venta reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if(cod==reg.getId())
			return pos;
		pos++;
		}
	return -1;
}



void mostrarVentasCaja(int codigo){ /// muestra las ventas de un codigo de caja ///

Venta aux;
int pos=0;
float total=0;
while(aux.leerDeDisco(pos++)==1){


    if(aux.getCodigoCaja()==codigo&&aux.getPago()==true){

        aux.mostrar();

    }

}

}






void Venta::cargar(){

    FechaSistema fec();
    char sel[5];
    idCajaAbierta=buscarId_caja_venta();
    if(idCajaAbierta==-1){

        cout << "\t\tPara gestionar una venta primero debe abrir caja "<< endl;
        cout << "\t\tAbrir ahora(si/no)?" ;
        limpiarBuffer();
        cin.getline(sel,5);
        if(strcmp(sel,"si")==0)abrirCaja();
        if(strcmp(sel,"SI")==0)abrirCaja();
        if(strcmp(sel,"Si")==0)abrirCaja();
        else return;
    }
    Producto aux;
    char pago[3];
    cout << "\t\tIngrese número de habitación: ";
    limpiarBuffer();
    cin.getline(habitacion,4);
    while(cadenaVacia(habitacion)==true){
            borrarPantalla();
            mensajes(3);
            borrarPantalla();
            cout << "\t\tIngrese número de habitación: ";
            limpiarBuffer();
            cin.getline(habitacion,4);

    }
    id=buscarHabitacionOcupada(habitacion);
    while(id==-1){
        borrarPantalla();
        cout << "\t\tIngrese una habitación valida"<< endl;
        pausa();
        borrarPantalla();
        cout << "\t\tIngrese número de habitación: ";
        limpiarBuffer();
        cin.getline(habitacion,4);
        while(cadenaVacia(habitacion)==true){
            borrarPantalla();
            mensajes(3);
            borrarPantalla();
            cout << "\t\tIngrese número de habitación: ";
            limpiarBuffer();
            cin.getline(habitacion,4);

    }

        id=buscarHabitacionOcupada(habitacion);

    }

    id++; /// el id se guarda en una posicion mas adelante asi se guarda de la 1 en adelante ///


    listaProductos();
    cout << "\t\tIngrese código de producto: ";
    limpiarBuffer();
    cin.getline(codigoProducto,5);
    /// se verifica que el producto exista ///
    if(buscarProducto(codigoProducto)==-1){
        borrarPantalla();
        cout << "\t\tCodigo invalido"<<endl;
        pausa();
        borrarPantalla();
        cout << "\t\tIngrese código de producto: ";
        limpiarBuffer();
        cin.getline(codigoProducto,5);
    }
    cout << "Ingrese cantidad: ";
    cin  >> cantidad;

    /// aca se verifica el stock disponible ///
    while(descontarStock(cantidad,codigoProducto)==false){
          borrarPantalla();
          cout << "\t\tSin stock disponible      "<< endl;
          cout << "\t\tIngrese una cantidad menor"<< endl;
          pausa();
          borrarPantalla();
          cout << "\t\tIngrese cantidad: ";
          cin  >> cantidad;
          }

    int pos=buscarProducto(codigoProducto);
    aux.leerDeDisco(pos);
    float precio=aux.getPrecio();
    total=precio*cantidad;
    cout << "\t\tTotal $"<< total << endl;
    cout << "\t\tPagar ahora(si/no): ";
    limpiarBuffer();
    cin.getline(pago,3);
    if(strcmp(pago,"si")==0){

            sumarCaja(total);
            pagado=true;
            return;
    }
    if(strcmp(pago,"SI")==0){
            sumarCaja(total);
            pagado=true;
            return;
    }
    /// si pagado es true no se suma a la cuenta final pero igual se muestra ///
    pagado=false;

}


void Venta::mostrar(){ /// probar como queda la muestra de productos asi ///

Producto aux;
cout << "\t\tNúmero de estadia: "<< id ; cout <<"\t\tNúmero de habitación: "<< habitacion << endl;
cout << "\t\tFecha de venta: "<<fec.mostar_dia();cout<<"/"<<fec.mostar_mes();cout<<"/"<<fec.mostar_anio();cout << "\t\tHora de venta: "<< fec.mostar_hora();cout <<":"<<fec.mostar_minuto();cout << endl;
cout << "\t\tCódigo de producto: "<< codigoProducto << endl;
int pos=buscarProducto(codigoProducto);
aux.leerDeDisco(pos);
cout << "\t\tProducto: ";cout << aux.getNombre();cout << "\t\tCantidad: "<< cantidad << endl;
cout << "\t\tTotal: $" << total;
if(pagado==true){

    cout << "\t\tPagado: Si" << endl;
}
else {
    cout << "\t\tPagado: No" << endl;
}
cout << "-------------------------------------"<< endl;
pausa();

 /// ver de ordenar como lista productos ///
}

int contarVentas(){
    FILE *P;
    P=fopen(FILE_VENTAS,"rb");
    if(P==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (P,0,SEEK_END);
    tam=ftell(P);
    tamanioreg=sizeof(Venta);
    cantidad=tam/tamanioreg;
    fclose(P);
    return cantidad;

}

void mostrarVentaId(){
if(contarVentas()==0){
    cout << "\t\tRegistro de ventas vacío"<< endl;
    pausa();
    return;
}
Venta aux;
char codigo[10];
cout << "\t\tIngrese id de venta a listar: ";
limpiarBuffer();
cin.getline(codigo,10);
int cod=atoi(codigo);
int pos=buscarVentaId(cod);
if(aux.leerDeDisco(pos)==1){

    aux.mostrar();
}
else {

    cout << "\t\tNo se encontro venta"<< endl;
    pausa();
}

}


void menuVentas(){

char opc;

while(true){
    system("cls");
    cout << "\t\t ----VENTAS----" << endl;
    cout << "\t\t --------------" << endl;
    cout << "\t\t1) Nueva venta         " << endl;
    cout << "\t\t2) Mostrar ventas      " << endl;
    cout << "\t\t3) Mostrar venta por id" << endl;
    cout << "\t\t0) Salir: ";
    cout << endl << "Opción: ";
    cin >> opc;
    system("cls");
    switch(opc){
      case '1':
        nuevaVenta();
      break;
      case '2':
        mostrarVenta();
      break;
      case '3':
    mostrarVentaId();

      break;
      case '0':
        return;
      break;
      default:
          mensajes(1);
      break;
    }
    cout << endl;

  }




}

/// FIN CLASE VENTA ///



/// CLASE TIPO DE HABITACION ///
class Tipo_habitacion /// tipo de habitacion /// son 4 y son fijas
{
private:
    int cod_tipo;
    char nombre[30];
    float costo;
    char adultos;
    char ninios;
    char vista[100];
    char tecnologias[100];
    char camas[100];




public:
    void cargar();
    void mostrar();

    void get_nombre(int c, char v[30]);
    float get_costo(int c);

   /// get mauri
   const char* getNombre(){return nombre;}
   float getCosto(){return costo;}
   int getCodigoTipo(){return cod_tipo;}

    /// funciones con archivos
        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);

} ; /// para cargar una habitacion

int Tipo_habitacion::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;
	FILE *p;
	p=fopen(FILE_TIPO_HABITACION,"rb");
	if(p==NULL)
		{
		mensajes(1);
		cout<<"\t\tPresione una tecla para continuar";
    system("pause<null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}



bool Tipo_habitacion::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_TIPO_HABITACION,"rb+");
	if(p==NULL){
        mensajes(1);
        pausa();
        return false;
	}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	return true;
}






bool Tipo_habitacion::escribirEnDisco(){ /// graba un registro de reservas
FILE*P;
P=fopen(FILE_TIPO_HABITACION,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}

/// moficiaciones mauri ///CLASE HABITACION

class Habitacion /// esta crea o contruye las habitaciones
{ /// siempre consultar la cantidad de habitaciones que hay de un tipo
protected:
    char numero[4];
    ///int id; /// nos sirve para desocupar una habitacion
    char tipo;
    bool estado; /// true cuando se crea, false para dar de baja definitivamente ---> crear opcion de dar de baja definitivamente
    bool limpio; /// si esta en limpieza
    bool mantenimiento; /// si esta en mantenimiento

public:
    void cargar(); /// mauri
    void mostrar(); /// mauri
    bool cargar_habitacion();
    void mostrar_habitacion();
    void mostrar_habitacion_tipo(int t);
    void mostrar_habitacion_estado(char e);
    ///gets
    const char* getNumero(){return numero;}
///    int getId(){return id;}
    char getTipo(){return tipo;}
    bool getEstado(){return estado;}
    bool getLimpio(){return limpio;}
    bool getMatenimiento(){return mantenimiento;}

    /// sets
    void setHabitacion(const char*nuevoNumero){strcpy(numero,nuevoNumero);}
///    void setId(int nuevaId){id=nuevaId;}
    void setTipo(char nuevoTipo){tipo=nuevoTipo;}
    void setEstado(bool nuevoEstado){estado=nuevoEstado;}
    void setLimpio(bool nuevoLimpio){limpio=nuevoLimpio;}
    void setMantenimietno(bool nuevoMante){mantenimiento=nuevoMante;}

    /// funciones con archivos
        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);

};

int Habitacion::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;
	FILE *p;
	p=fopen(FILE_HABITACIONES,"rb");
	if(p==NULL)
		{
		mensajes(1);
		cout<<"\t\tPresione una tecla para continuar";
    system("pause<null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}



bool Habitacion::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_HABITACIONES,"rb+");
	if(p==NULL){
        mensajes(1);
        pausa();
        return false;
	}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	return true;
}



bool Habitacion::escribirEnDisco(){ /// graba un registro de reservas
FILE*P;
P=fopen(FILE_HABITACIONES,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}

int buscarHabitacion(const char* num){ ///devuelve la posicion de la habitacion en el archivo
	int pos=0;
	Habitacion reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if(strcmp(num,reg.getNumero())==0)
			return pos;
		pos++;
		}
	return -1;
}

/// FIN CLASE HABITACION ///

/// CLASE HABITACION OCUPADA ///

class Habitacion_ocupada:public Habitacion /// habitacion para ocupar / PARTE PRINCIPAL DEL PROGRAMA
{
private:
    int numeroDeEstadia;
    char tipoHab;
    char numeroHab[4];
    Cliente datosCliente;
    char serv_contratado[150],hora_limpieza[20];
    ///bool reserva;
    float cuenta; /// total a pagar ///
    float pago_adelantado;/// sale de lo que ponga mas si puso algo en la reserva
    FechaSistema fec_salida();/// automatico cuando se carga
    FechaSistema fec_ingreso();/// automatico cuando se cargaa
    Fecha entra,sale; /// para ver la disponibilidad de habitaciones para esa fecha

    bool activa;

public:
    ///GETS
    int getNumEstadia(){return numeroDeEstadia;}
        bool getActiva(){return activa;}
        char getTipo(){return tipoHab;}
        const char* getNumero(){return numeroHab;}

    ///SETS



    void ocupar(); ///Ocupa una habitacion y carga los datos
    bool desocupar(); ///Libera una habitacion
    void consultar(); ///Consulta los datos de la habitacion seleccionada /// es como mostrar
    void consulta_fecha(); ///Consulta los datos de la habitacion entre 2 fechas

        /// funciones con archivos
        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);

};

int Habitacion_ocupada::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;                                   /// se pueden contar todos los registros si contas todos los pos
	FILE *p;
	p=fopen(FILE_ESTADIAS,"rb");
	if(p==NULL)
		{
		mensajes(1);
		cout<<"\t\tPresione una tecla para continuar";
    system("pause<null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}



bool Habitacion_ocupada::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_ESTADIAS,"rb+");
	if(p==NULL){
        mensajes(1);
        pausa();
        return false;
	}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	return true;
}


bool Habitacion_ocupada::escribirEnDisco(){ /// graba un registro de reservas
FILE*P;
P=fopen(FILE_ESTADIAS,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}

int buscarHabitacionOcupada(const char* num){ ///devuelve la posicion de la habitacion en el archivo
	int pos=0;
	Habitacion_ocupada reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if((strcmp(num,reg.getNumero())==0)&&(reg.getActiva()==true)){
			return pos;
			}
            pos++;
		}

	return -1;
}

int asignarNumEstadia(){

    FILE *F;
    F=fopen(FILE_ESTADIAS,"rb");
    if(F==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (F,0,SEEK_END);
    tam=ftell(F);
    tamanioreg=sizeof(Habitacion_ocupada);
    cantidad=tam/tamanioreg;
    fclose(F);
    return cantidad+1;

}



void Habitacion_ocupada::ocupar(){
numeroDeEstadia=asignarNumEstadia();

cout << "\t\tIngrese tipo de habitacion: "<< endl;
listaDeTipos();
cin  >> tipoHab;

/// carga fecha de ingreso ///
cout << "\t\tIngrese Fecha de ingreso: ";cout << endl;
entra.cargar();
while(fechaPasado(entra)==false){
    borrarPantalla();
    cout<<"\t\tNo puede ser una fecha menor a ";fecha(); cout << endl;
    pausa();
    borrarPantalla();
    cout << "\t\tIngrese Fecha de ingreso: ";cout << endl;
    entra.cargar();
}

///carga de fecha de salida ///
cout << "\t\tIngrese Fecha de salida: ";cout << endl;
sale.cargar();
while(fechaPasado(sale)==false){
    borrarPantalla();
    cout<<"\t\tNo puede ser una fecha menor a ";fecha(); cout << endl;
    pausa();
    borrarPantalla();
    cout << "\t\tIngrese Fecha de salida: ";cout << endl;
    sale.cargar();

} /// puede ser que entre y salga en el dia por eso la fecha de entrada puede ser igual a la de salida ///

while(!consultarDisponibilidad(entra,sale,tipoHab)){
    borrarPantalla();
    cout << "\t\tSin disponibilidad para ese rango de fecha"<< endl;
    pausa();
    borrarPantalla();
    cout << "\t\tIngrese tipo de habitacion: "<< endl;
    listaDeTipos();
    cin >> tipoHab;
    cout << "\t\tIngrese Fecha de ingreso: ";cout << endl;
    entra.cargar();
    cout << "\t\tIngrese Fecha de salida: ";cout << endl;
    sale.cargar();
}

    strcpy(numeroHab,asignarHabitacion(tipoHab));
    datosCliente.cargar();

    datosCliente.escribirEnDisco();

    cout << "\t\tServicio Contratado: ";
    limpiarBuffer();
    cin.getline(serv_contratado,150);
    cout << "\t\tHora limpieza: ";
    limpiarBuffer();
    cin.getline(hora_limpieza,20);
    cuenta=0;
    cout << "\t\tPago adelantado: ";
    cin  >> pago_adelantado;
    activa=true;

}
bool liberarHabitacion(const char *numHab){

Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos)==1){


    if(strcmp(numHab,aux.getNumero())==0){

        aux.setEstado(true);
        aux.setLimpio(false);
        aux.modificarEnDisco(pos);
        return true;
    }
    pos++;
}
return false;

}

float totalFacturado(int estadia){
Venta reg;
int pos=0;
float total=0;
cout << "\t\t--------------------------"<< endl;
while(reg.leerDeDisco(pos++)==1){


    if((estadia==reg.getId())&&(reg.getPago()==false)){

        total+=reg.getTotal();
        reg.mostrar();

    }
    else {

        if((estadia==reg.getId()))
            reg.mostrar();

    }
cout << "\t\t--------------------------"<< endl;

}

return total;


}


bool Habitacion_ocupada::desocupar(){

Venta reg;
Tipo_habitacion aux;
char pago[3];
///cout << "Numero de estadia: "<< numeroDeEstadia << endl;
///cout << "Numero de Habitación: "<< numeroHab << endl;
int pos=tipoHab-'0';
/// se le resta una unidad para que concuerde con la pos del archivo
aux.leerDeDisco(pos-1);
cout << "\t\tTipo de habitación: "<< aux.getNombre();
cout << endl;
float precioEstadia=aux.getCosto();
cuenta=totalFacturado(numeroDeEstadia)+precioEstadia-pago_adelantado;

cout << "\t\tPrecio por noche           --->$"<< precioEstadia << endl;
cout << "\t\tPrecio por estadia completa--->$"<< precioEstadia << endl; /// falta calcular cantidad de dias x precio por dia
cout << "\t\tPago adelantado            --->$"<< pago_adelantado << endl;
cout << "\t\tCuenta final               --->$"<< cuenta << endl;
/// EN ESTE PUNTO SE LE MUESTRAN TODAS LAS COMPRAS QUE HIZO LA HABITACION ///
/// TANTO LAS PAGADAS COMO LAS NO PAGADAS ///
/// Y OBVIO SE LE COBRAN LAS QUE NO PAGO ///
cout << "\t\tPagar (si/no): ";
limpiarBuffer();
cin.getline(pago,3);

if (strcmp(pago,"si")==0){
        if(liberarHabitacion(numeroHab)){
            cout << "\t\tHabitación "<< numeroHab << " liberada y en limpieza..."<< endl;
            pausa();
        }
        activa=false;
        return true;
}
if (strcmp(pago,"SI")==0){
        if(liberarHabitacion(numeroHab)){
            cout << "\t\tHabitación "<< numeroHab << " liberada y en limpieza..."<< endl;
            pausa();
        }
        activa=false;
        return true;
}

return false;

}

void Habitacion_ocupada::consultar(){
    Tipo_habitacion aux;
cout << "\t\tNúmero de estadia: "<< numeroDeEstadia << endl;
cout << "\t\tNúmero de habitación: "<< numeroHab << endl;
datosCliente.mostrar();
int pos=tipoHab-'0';
/// se le resta una unidad para que concuerde con la pos del archivo
aux.leerDeDisco(pos-1);
cout << "\t\tTipo de habitación: "<< aux.getNombre();
cout << endl;
cout << "\t\tServicio contratado: "<< serv_contratado << endl;
cout << "\t\tHora limpieza: "<< hora_limpieza << endl;
cout << "\t\tCuenta actual: $"<< cuenta << endl;
cout << "\t\tPago adelantado: $"<< pago_adelantado << endl;
cout << "\t\tFecha de entrada: "; entra.mostrarConBarra();
cout << "\t\tFecha de salida: "; sale.mostrarConBarra();

}

/// FIN HABITACION OCUPADA ///

/// CLASE GASTO ///
void Gasto::cargar() /// cambiarle tipo de gasto por codigo de producto a vender
{                    /// agregarle la cantidad a vender
    FILE *g;         /// añadir pago si / pago no
    g=fopen("gastos.dat","ab");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    fseek(g,0,2);
    id=((ftell(g)/sizeof(*this))+1);
    cout<<"Ingrese la habitacion que realizo el gasto: ";
    cin>>habitacion;
    cout<<"Ingrese el tipo de gasto: ";
    cin>>tipo;
    cout<<"Ingrese el importe del gasto: $";
    cin>>importe;
    cout<<"Ingrese la descripcion del importe: ";
    cin.ignore();
    cin.getline(descripcion,240);
    fwrite(this,sizeof(*this),1,g);

    fclose(g);

}

void Gasto::consulta_habitacion()/// consulta los gastos actuales del cliente
{
    FILE *g;
    char cons[4];
    g=fopen("gastos.dat","rb");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    cout<<"Ingrese la habitacion por la que quiere consultar: ";
    cin>>cons;
    while(fread(this,sizeof(*this),1,g)==1)
    {
        if(strcmp(habitacion,cons)==0)
        {
            cout<<id<<endl;
            cout<<habitacion<<endl;
            cout<<tipo<<endl;
            cout<<importe<<endl;
            cout<<descripcion<<endl<<endl;
            cout<<fec.mostar_dia()<<"/"<<fec.mostar_mes()<<"/"<<fec.mostar_anio()<<"  "<<fec.mostar_hora()<<":"<<fec.mostar_minuto()<<endl;
            cout<<"-------------------------------"<<endl;
        }
    }
    fclose(g);
}

void Gasto::consulta_habitacion_fecha() /// gastos o consumos de habitacion entre dos fechas
{
    FILE *g;
    char cons[4],fecini[11],fecfin[11];
    g=fopen("gastos.dat","rb");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    cout<<"Ingrese la habitacion por la que quiere consultar: ";
    cin>>cons;
    cout<<"Ingrese fecha de inicio de la busqueda";
    cin>>fecini;
    cout<<"Ingrese fecha de fin de la busqueda";
    cin>>fecfin;
    while(fread(this,sizeof(*this),1,g)==1)
    {
        if(strcmp(habitacion,cons)==0&&comparar_fechas(fecini,fecfin,fec.mostar_anio(),fec.mostar_mes(),fec.mostar_dia())==true)
        {
            cout<<id<<endl;
            cout<<habitacion<<endl;
            cout<<tipo<<endl;
            cout<<importe<<endl;
            cout<<descripcion<<endl<<endl;
            cout<<fec.mostar_dia()<<"/"<<fec.mostar_mes()<<"/"<<fec.mostar_anio()<<"  "<<fec.mostar_hora()<<":"<<fec.mostar_minuto()<<endl;
            cout<<"-------------------------------"<<endl;
        }
    }
    fclose(g);
}

void Gasto::consulta_habitacion_tipo()
{
    FILE *g;
    char cons[4];
    int tip;
    g=fopen("gastos.dat","rb");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    cout<<"Ingrese la habitacion por la que quiere consultar: ";
    cin>>cons;
    cout<<"Ingrese el tipo de gasto que quiere consultar: ";
    cin>>tip;
    while(fread(this,sizeof(*this),1,g)==1)
    {
        if((strcmp(habitacion,cons)==0)&&(tipo==tip))
        {
            cout<<id<<endl;
            cout<<habitacion<<endl;
            cout<<tipo<<endl;
            cout<<importe<<endl;
            cout<<descripcion<<endl<<endl;
            cout<<fec.mostar_dia()<<"/"<<fec.mostar_mes()<<"/"<<fec.mostar_anio()<<"  "<<fec.mostar_hora()<<":"<<fec.mostar_minuto()<<endl;
            cout<<"-------------------------------"<<endl;
        }
    }
    fclose(g);
}

void Gasto::consulta_total()
{
    FILE *g;
    g=fopen("gastos.dat","rb");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,g)==1)
    {

        cout<<id<<endl;
        cout<<habitacion<<endl;
        cout<<tipo<<endl;
        cout<<importe<<endl;
        cout<<descripcion<<endl<<endl;
        cout<<fec.mostar_dia()<<"/"<<fec.mostar_mes()<<"/"<<fec.mostar_anio()<<"  "<<fec.mostar_hora()<<":"<<fec.mostar_minuto()<<endl;
        cout<<"-------------------------------"<<endl;

    }
    fclose(g);
}


void Gasto::anular() /// anula gasto que vos quieras
{
    FILE *g,*aux;
    int idanul;
    g=fopen("gastos.dat","rb");
    aux=fopen("auxiliar.dat","wb");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    if(aux==NULL)
    {
        cout<<"Fallo al abrir el archivo"<<endl;
        return;
    }
    cout<<"Ingrese el id del gasto que quiere anular";
    cin>>idanul;
    while(fread(this,sizeof(*this),1,g)==1)
    {

        if(id!=idanul)
        {
            fwrite(this,sizeof(*this),1,aux);
        }
    }
    fclose(g);
    fclose(aux);
    g=fopen("gastos.dat","wb");
    aux=fopen("auxiliar.dat","rb");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    if(aux==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,aux)==1)
    {
        fwrite(this,sizeof(*this),1,g);
    }
    fclose(g);
    fclose(aux);

}

void Gasto::modificar()
{
    FILE *g;
    g=fopen("gastos.dat","rb+");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    fseek(g,0,2);
    id=(ftell(g)/sizeof(*this));
    cout<<"Ingrese la habitacion que realizo el gasto: ";
    cin>>habitacion;
    cout<<"Ingrese el tipo de gasto: ";
    cin>>tipo;
    cout<<"Ingrese el importe del gasto: $";
    cin>>importe;
    cout<<"Ingrese la descripcion del importe: ";
    cin.ignore();
    cin.getline(descripcion,240);
    fseek(g,(ftell(g)-sizeof(*this)),0);
    fwrite(this,sizeof(*this),1,g);

    fclose(g);
}


/// FIN CLASE GASTO ///

/*void Habitacion_reserva::cargar()
{
    char fi[11],fs[11];
    int aux[3];
    FILE *r;
    r=fopen("reserva.dat","ab");
    if(r==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    fseek(r,0,2);
    id=((ftell(r)/sizeof(*this))+1);
    cout<<"Ingrese la habitacion que quiere reservar: ";
    cin>>habitacion;
    estado='A';
    cout<<"Ingrese el importe del pago adelantado: $";
    cin>>pago_adelantado;
    cout<<"Ingrese la fecha de entrada: ";
    cin>>fi;
    convertir_fecha(fi,aux);
    fec_ingreso.set_dia(aux[0]);
    fec_ingreso.set_mes(aux[1]);
    fec_ingreso.set_anio(aux[2]);
    fec_ingreso.hora_standar();
    cout<<"Ingrese la fecha de salida: ";
    cin>>fs;
    convertir_fecha(fs,aux);
    fec_salida.set_dia(aux[0]);
    fec_salida.set_mes(aux[1]);
    fec_salida.set_anio(aux[2]);
    fec_salida.hora_standar();
    fwrite(this,sizeof(*this),1,r);
    fclose(r);
}
void Habitacion_reserva::consulta_total()
{
    FILE *r;
    r=fopen("reserva.dat","rb");
    if(r==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,r)==1)
    {
            cout<<"Id: "<<id<<endl;
            cout<<"Habitacion: "<<habitacion<<endl;
            cout<<"Pago adelantado: $"<<pago_adelantado<<endl;
            cout<<fec_ingreso.mostar_dia()<<"/"<<fec_ingreso.mostar_mes()<<"/"<<fec_ingreso.mostar_anio()<<"  "<<fec_ingreso.mostar_hora()<<":"<<fec_ingreso.mostar_minuto()<<endl;
            cout<<fec_salida.mostar_dia()<<"/"<<fec_salida.mostar_mes()<<"/"<<fec_salida.mostar_anio()<<"  "<<fec_salida.mostar_hora()<<":"<<fec_salida.mostar_minuto()<<endl;
            cout<<"-------------------------------"<<endl;
    }
    fclose(r);
}*/


int contarTiposHabitaciones(){
    FILE *F;
    F=fopen(FILE_TIPO_HABITACION,"rb");
    if(F==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (F,0,SEEK_END);
    tam=ftell(F);
    tamanioreg=sizeof(Tipo_habitacion);
    cantidad=tam/tamanioreg;
    fclose(F);
    return cantidad;

}

void listaDeTipos(){
Tipo_habitacion aux;
int pos=0;
/*char **matriz;
int filas=contarTiposHabitaciones();
int columna=strlen(aux.getNombre());
matriz = new char *[fila_dinamica];
for (int i=0;i<filas;i++){
        matriz[i] = new char[columna];
    }*/
while(aux.leerDeDisco(pos++)==1){

    cout << "\t\t"<< cout <<pos<<")"<< aux.getNombre() << endl;
}

}

void mostrarTipo(char tipo){
int pos=tipo-'0';
Tipo_habitacion aux;
aux.leerDeDisco(pos-1);
cout << "\t\tHabitación: ";cout << aux.getNombre();cout << endl;

}

bool verificarNumeroHabitacion(char *numHabitacion){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){

    if(strcmp(numHabitacion,aux.getNumero())==0)
        return false;

}

return true;

}



bool Habitacion::cargar_habitacion() /// no esta en uso actualmente
{
  FILE *h;
    h=fopen("habitaciones.dat","ab");
    if(h==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return false;
    }
    fseek(h,0,2);
///    id=((ftell(h)/sizeof(*this))+1);
    cout<<"Ingrese el numero de la habitacion: ";
    limpiarBuffer();
    cin.getline(numero,4);
    while(!verificarNumeroHabitacion(numero)){
        borrarPantalla();
        cout << "Habitación con ese numero ya fue creada"<< endl;
        pausa();
        borrarPantalla();
        cout<<"Ingrese el numero de la habitacion: ";
        limpiarBuffer();
        cin.getline(numero,4);


    }
    listaDeTipos();
    cout << "Seleccione tipo de habitacion: "<< endl;
    cin  >>tipo;
    estado=true;
    limpio=true;
    mantenimiento=false; /// se carga en false , si va a mantenimiento se pone en true
    fwrite(this,sizeof(*this),1,h);
    fclose(h);
    return true;


}

int CodigoTipoHabitacion(){
int cant=contarTiposHabitaciones();
return cant+1;
}

bool verificarTipoHabitacion(char *nombre){
Tipo_habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){


    if(strcmp(nombre,aux.getNombre())==0)return false;

}
return true;

}

void Tipo_habitacion::cargar(){
    /// PANA LA CAMBIE PARA NO ABRIR EL ARCHIVO DETRO DE LA CARGA ///

    cod_tipo=CodigoTipoHabitacion();
    cout<<"\t\tIngrese el nombre del tipo: ";
    limpiarBuffer();
    cin.getline(nombre,30);
    while(!verificarTipoHabitacion(nombre)){
            borrarPantalla();
     cout << "\t\tya existe ese tipo de habitación" << endl;
        pausa();
        borrarPantalla();
        cout<<"\t\tIngrese el nombre del tipo: ";
        limpiarBuffer();
        cin.getline(nombre,30);

    }

    cout<<"\t\tIngrese el precio del tipo: $";
    cin>>costo;
    cout << "\t\tCapacidad máxima adultos: ";
    limpiarBuffer();
    cin >> adultos;
    cout << "\t\tCapacidad máxima niños: ";
    cin >> ninios;
    cout << "\t\tIngrese tipo de camas: ";
    limpiarBuffer();
    cin.getline(camas,100);
    cout << "\t\tIngrese tecnologías disponibles: ";
    limpiarBuffer();
    cin.getline(tecnologias,100);
    cout << "\t\tIngrese vistas desde a habitación: ";
    limpiarBuffer();
    cin.getline(vista,500);

}

void Tipo_habitacion::mostrar(){


        cout <<"\t\tCódigo de tipo: "<<cod_tipo<<endl;
        cout <<"\t\tNombre: "<<nombre<<endl;
        cout <<"\t\tcosto: "<<costo<<endl;
        cout <<"\t\tCapacidad máxima: "<< adultos << " Adulto/s + "<< ninios << " niño/s"<< endl;
        cout <<"\t\tCARACTERISTICAS: "<< endl;
        cout <<"\t\t*"<<camas << endl;
        cout <<"\t\t*"<<tecnologias << endl;
        cout <<"\t\t*"<<vista << endl;
        cout<<"\t\t---------------------------"<<endl;
        pausa();



}

/*const char* nombreTipoHabitacion(char tipe){

Tipo_habitacion reg;
char nombreHab[30];
int pos=tipe-'0';
reg.leerDeDisco(pos-1);
strcpy(nombreHab,reg.getNombre());

return nombreHab;

}*/



float Tipo_habitacion::get_costo(int c)
{
    FILE *t;
    float cost;
    t=fopen("tipo_habitacion.dat","rb");
    if(t==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        exit;
    }
    fseek(t,((c-1)*sizeof(*this)),0);
    fread(this,sizeof(*this),1,t);
    cost=costo;
    fclose(t);
    return cost;
}
void Tipo_habitacion::get_nombre(int c,char v[30])
{
    FILE *t;
    t=fopen("tipo_habitacion.dat","rb");
    if(t==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        exit;
    }
    fseek(t,(c-1)*sizeof(*this),0);
    fread(this,sizeof(*this),1,t);
    strcpy(v,nombre);
    fclose(t);
}

void Habitacion::mostrar_habitacion()
{
    FILE *h;
    char nom[30];
    Tipo_habitacion t;
    h=fopen("habitaciones.dat","rb");
    if(h==NULL)
    {
        cout<<"\t\tFallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,h)==1)
    {
        t.get_nombre(tipo,nom);
///        cout<<"ID:         "<<id<<endl;
        cout<<"\t\tHabitacion: "<<numero<<endl;
        cout<<"\t\tTipo:       "<<nom<<endl;
        cout<<"\t\tCosto: $    "<<t.get_costo(tipo)<<endl;
        if (estado==true){
        cout<<"\t\tEstado: Disponible"<<endl;
        }
        else{
            cout<<"\t\tEstado: Ocupada" <<endl;
        }
        if(limpio==false){

            cout << "\t\tEn limpieza "<< endl;
        }

        if(mantenimiento==true){
            cout << "\t\tEn mantenimiento "<< endl;
        }

        cout<<"\t\t-------------------------------"<<endl;
        pausa();
    }

    fclose(h);
}

int contarRegistrosHabitaciones(){

Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos)==1){

    pos++;

}

return pos;
}


void Habitacion::cargar(){

    ///int cant=contarRegistrosHabitaciones();
    ///id=cant+1;
    cout<<"\t\tIngrese el numero de la habitacion: ";
    limpiarBuffer();
    cin.getline(numero,4);
    while(!verificarNumeroHabitacion(numero)){
        borrarPantalla();
        cout << "\t\tHabitación con ese numero ya fue creada"<< endl;
        pausa();
        borrarPantalla();
        cout<<"\t\tIngrese el numero de la habitacion: ";
        limpiarBuffer();
        cin.getline(numero,4);


    }
    listaDeTipos();
    cout << "\t\tSeleccione tipo de habitacion: ";
    cin  >>tipo;
    estado=true;
    limpio=true; /// se inicializan limpias /// por eso el estado true
    mantenimiento=false; /// se carga en false , si va a mantenimiento se pone en true


}


/// mostrar habitacion mauri
void Habitacion::mostrar(){
Tipo_habitacion aux;
///cout << "Id: "<< id << endl;
cout << "\t\tNumero de habitación: "<< numero << endl;
int pos=tipo-'0';
/// se le resta una unidad para que concuerde con la pos del archivo
aux.leerDeDisco(pos-1);
cout << "\t\tTipo de habitación: "<< aux.getNombre();
cout << endl;
cout << "\t\tPrecio por noche: $ "<< aux.getCosto();
cout << endl;
if (estado==true){
        cout<<"\t\tEstado: Disponible"<<endl;
        }
        else{
            cout<<"\t\tEstado: Ocupada" <<endl;
        }
        if(limpio==false){

            cout << "\t\tEn limpieza "<< endl;
        }

        if(mantenimiento==true){
            cout << "\t\tEn mantenimiento "<< endl;
        }
        cout << "\t\t----------------------"<< endl;
        pausa();

}

void Habitacion::mostrar_habitacion_tipo(int ti)
{
  FILE *h;
    char nom[30];
    Tipo_habitacion t;
    h=fopen("habitaciones.dat","rb");
    if(h==NULL)
    {
        cout<<"\t\tFallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,h)==1)
    {
        if(tipo==ti)
        {
        t.get_nombre(tipo,nom);
///        cout<<"ID:         "<<id<<endl;
        cout<<"\t\tHabitacion: "<<numero<<endl;
        cout<<"\t\tTipo:       "<<nom<<endl;
        cout<<"\t\tCosto: $"<<t.get_costo(tipo)<<endl;
        cout<<"\t\tEstado:     "<<estado<<endl;
        cout<<"\t\t-------------------------------"<<endl;
        }
    }
    fclose(h);
}
void Habitacion::mostrar_habitacion_estado(char e)
{
    FILE *h;
    char nom[30];
    Tipo_habitacion t;
    h=fopen("habitaciones.dat","rb");
    if(h==NULL)
    {
        cout<<"\t\tFallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,h)==1)
    {
        if(estado==e)
        {
        t.get_nombre(tipo,nom);
///        cout<<"ID: "<<id<<endl;
        cout<<"\t\tHabitacion: "<<numero<<endl;
        cout<<"\t\tTipo: "<<nom<<endl;
        cout<<"\t\tCosto: $"<<t.get_costo(tipo)<<endl;
        cout<<"\t\tEstado: "<<estado<<endl;
        cout<<"\t\t-------------------------------"<<endl;
        }
    }
    fclose(h);
}


void mostrarTodasHabitaciones(){
Habitacion aux;
int pos=0;
int cont=0;
while(aux.leerDeDisco(pos)==1){


      aux.mostrar();
        pos++;
        cont++;
  }
if(cont == 0){

   cout << "\t\tAún no hay habitaciones cargadas."<< endl;
    pausa();
   }

}

int contarHabitaciones(char _tipo){ /// cuenta las habitaciones de un tipo
Habitacion aux;
int pos=0;
int cantidad=0;
while(aux.leerDeDisco(pos++)==1){

if(aux.getTipo()==_tipo){

    cantidad++;
    }

}
return cantidad;

}

bool consultarDisponibilidad(Fecha in,Fecha out,char tipo){


int cantReg=contarRegistrosReservas();
if(cantReg==0)return true;
Reserva aux;
int pos=0;
int cantHabitaciones=contarHabitaciones(tipo);
cout << "\t\tcantidad habitaciones(sacar esto desp)"<< cantHabitaciones << endl;
pausa();
int chances=cantHabitaciones;

while(aux.leerDeDisco(pos++)==1){

    if(aux.getTipo()==tipo){

        if((comprobarFecha1(aux,in,out)==false)){chances--;}
        if((comprobarFecha2(aux,in,out)==false)){chances--;}
        if((comprobarFecha3(aux,in,out)==false)){chances--;}
        if((comprobarFecha4(aux,in,out)==false)){chances--;}
        if(chances==0)return false;

            }

        }


return true;

}


void mostrarHabLibres(){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos)==1){


    if(aux.getEstado()==true){
            aux.mostrar();
          }
          pos++;
  }

}


const char* asignarHabitacion(char tipo){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos)==1){

    if((aux.getEstado()==true)&&(aux.getTipo()==tipo)){
        aux.setEstado(false);
        aux.modificarEnDisco(pos);
        return aux.getNumero();
                }
        pos++;
        }


}

void mostrarHabOcupadas(){
Habitacion_ocupada aux;
int pos=0;
bool vacio=true;
while(aux.leerDeDisco(pos)==1){

    if(aux.getActiva()==true){
            vacio=false;
        aux.consultar();
    }
    pos++;
}
if(vacio==true){

    cout << "\t\tEn este momento no hay habitaciones ocupadas."<< endl;
    pausa();
}

}

void mostrarHabEnLimpieza(){
Habitacion aux;
int pos=0;
int cont=0;
while(aux.leerDeDisco(pos)==1){


    if(aux.getLimpio()==false){
            aux.mostrar();
            cont++;
          }
          pos++;
  }
  if(cont==0){

        cout << "\t\tEn este momento todas las habitaciones están limpias."<< endl;
        pausa();

  }

}
void mostrarHabEnMantenimiento(){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos)==1){


    if(aux.getMatenimiento()==true){
            aux.mostrar(); /// se deberia mostrar clase habitacion en mantenimiento
          }
          pos++;
  }

}


int mostrarHabitaciones(){
short opcion;
while(true){
    borrarPantalla();

    cout << "\t\t1)Habitaciones libres            " << endl;
    cout << "\t\t2)Habitaciones ocupadas          " << endl; /// las muestra con los datos de las perosnas que estan ocupandola
    cout << "\t\t3)Haitaciones en limpieza        " << endl;
    cout << "\t\t4)Haitaciones en mantenimiento   " << endl;
    cout << "\t\t5)Mostrar todas las habitaciones "<< endl;
    cout << "\t\t0) Salir ";
    cout << endl << "Opción: ";
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
      case 1:
        mostrarHabLibres();
            break;
      case 2:
        mostrarHabOcupadas();
      break;
      case 3:
        mostrarHabEnLimpieza();
      break;
      case 4:
          mostrarHabEnMantenimiento();
        break;
      case 5:
    mostrarTodasHabitaciones();
      break;

      case 0:
        return 0;
      break;
      default:
        mensajes(2);
        break;
    }
    cout << endl;

  }

}

void cargarEstadia(){
Habitacion_ocupada reg;
reg.ocupar();
if(reg.escribirEnDisco()){

    cout << "\t\tEstadia cargada con éxito"<< endl;
    cout << "\t\tSe asigno habitación "<< reg.getNumero(); cout << endl;
    pausa();
        }
}



void realizarCheckOut(){

Habitacion_ocupada aux;
char num[4];
cout << "\t\tIngrese habitación: ";
limpiarBuffer();
cin.getline(num,4);
int pos=buscarHabitacionOcupada(num);
aux.leerDeDisco(pos);
if(aux.desocupar()){
    aux.modificarEnDisco(pos);

    cout << "\t\tCheck out realizado con éxito"<< endl;
    pausa();
}
 else{
        cout << "\t\tNo se realizo check out "<< endl;
        cout << "\t\tCuenta pendiente de pago"<< endl;
        pausa();
    }
}


void nuevaVenta(){

Venta reg;
reg.cargar();
reg.escribirEnDisco();
if (reg.getPago()==true){

    cout << "\t\tVenta procesada con éxito"<< endl;
    pausa();
}
else{

    cout << "\t\tEL total se sumo a la facturación final"<< endl;
    pausa();

}


}

void mostrarVenta(){

Venta aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){


    aux.mostrar();
    pausa();
}

}

/// SECTOR LIMPIEZA ///

void cargarHabitacionLimpieza(void);
void mostrarHabitacionesEnLimpieza(void);
void buscarHabitacionEnLimpieza(void);
void sacarDeLimpieza();


/// la comente por que tenia una ya creada y es igual jaja
/*int buscarHabitacion(char *habitacion){
    FILE *p;
    p = fopen(FILE_HABITACIONES,"rb");
    if(p==NULL){return -1;}
    Habitacion aux;
    int pos=0;
    while(fread(&aux,sizeof aux,1,p)==1){
        if(strcmp(habitacion,aux.get_habitacion())==0){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}*/


void cargarHabitacionLimpieza(){ /// carga una habitacion para limpieza manualmente ///
    Habitacion aux;
    int pos;
    char hab[4];
    cout << "\t\tIngrese el número de Habitación: ";
    limpiarBuffer();
    cin.getline(hab,4);
    pos = buscarHabitacion(hab); if(pos==-1){ cout << "\t\tno se encontro habitacion" << endl; pausa(); return ;}
    //FILE *p; p = fopen(FILE_HABITACIONES,"rb+");
    //if(p==NULL){ return ;}
    //fseek(p,sizeof aux*pos,0);
    //fread(&aux,sizeof aux,1,p);
    /*if(strcmpi(aux.get_limpiezaMantenimiento(),"En mantenimiento")==0){
        cout << "La habitacion se encuentra en Mantenimiento" << endl;
        pausa();
        fclose(p);
        return ;
    }*/ /// VERIFICA SI LA HABITACION ESTA EN MANTENIMIENTO /// PARA USARLO ANTES INGRESAR HABITACIONES EN MANTENIMIENTO
    aux.leerDeDisco(pos);
    aux.setLimpio(false);
    //fwrite(&aux,sizeof aux,1,p);
    if(aux.modificarEnDisco(pos)){
    cout << "\t\tHabitación "<< aux.getNumero();cout << " está ahora en limpieza."<< endl;
    pausa();
    }
    //fclose(p);

}

void mostrarHabitacionesEnLimpieza(){ /// muestra las habitaciones en limpieza actualmente ///
    FILE *p; p = fopen("habitaciones.dat","rb");
    if(p==NULL){ return ;}
    Habitacion aux;
    int cont=0;
    while(fread(&aux,sizeof aux,1,p)==1){
        if(aux.getLimpio()==false){
            aux.mostrar();
            pausa();
            cont ++;
        }
    }
    fclose(p);
    if(cont==0){

        cout << "\t\tEn este momento todas las habitaciones están limpias."<< endl;
        pausa();
    }
}


void buscarHabitacionEnLimpieza(){ /// busca una habitacion , si esta en limpieza la muestra /// sino dice que esta limpia
    char hab[4];
    int pos;
    Habitacion aux;
    cout << "\t\tingrese el numero de Habitacion: ";
    limpiarBuffer();
    cin.getline(hab,4);
    pos = buscarHabitacion(hab); if(pos==-1){ cout << "\t\tno se encontro habitacion" << endl; pausa(); return ;}
    FILE *p; p = fopen(FILE_HABITACIONES,"rb+");
    if(p==NULL){ return ;}
    //fseek(p,sizeof aux*pos,0);
    //fread(p,sizeof aux,1,p);
    aux.leerDeDisco(pos);
    if(aux.getLimpio()==false){
    aux.mostrar();
    pausa();
    }
    else {
        cout << "\t\tLa habitación ";cout << aux.getNumero(); cout << " se encuentra limpia "<< endl;
        pausa();
    }
    fclose(p);
}

void sacarDeLimpieza(){
char hab[4];
Habitacion aux;
cout << "\t\tIngrese habitación: ";
limpiarBuffer();
cin.getline(hab,4);
int pos=buscarHabitacion(hab);
if(pos==-1){

    cout << "\t\tNo se encontro habitación"<< endl;
    pausa();
}
else {
    aux.leerDeDisco(pos);
    aux.setLimpio(true);
    if(aux.modificarEnDisco(pos)){

        cout << "\t\tHabitación ";aux.getNumero();cout << " ya se encuentra limpia "<< endl;
        pausa();
    }
}

}



int menuLimpieza(){ /// MENU LIMPIEZA ///
    setlocale(LC_ALL,"spanish");
    char opcion;
    while(true){
    system("cls");
    cout << "\t\t ----SECTOR LIMPIEZA----" <<endl;
    cout << "\t\t -----------------------" <<endl;
    cout << "\t\t1)Cargar habitacion para limpieza  " <<endl;
    cout << "\t\t2)Sacar habitación de limpieza     " <<endl;
    cout << "\t\t3)Mostrar habitaciones en limpieza " <<endl;
    cout << "\t\t4)Buscar Habitacion                " <<endl;
    cout << "\t\t0)Volver "<< endl;
    cout << "\t\tIngrese opcion:" << endl;
    cin >> opcion;
    system ("cls");
    switch(opcion){
    case '0':
       return 0;
    break;
    case '1':
        cargarHabitacionLimpieza();
    break;
    case '2':
    sacarDeLimpieza();
    break;
    case '3':
        mostrarHabitacionesEnLimpieza();
    break;
    case '4':
        buscarHabitacionEnLimpieza();
        break;
    default:
    mensajes(1);
        break;

        }
    }
}
 ///FIN SECTOR LIMPIEZA ///

 /// SECTOR MANTENIMIENTO ///

 class Habitacion_mantenimiento{
private:
    char numero[4];
    char tipo;
    bool estado;
    float gasto_total;
    int dias_estimado;
    char descripcion [500];
    char descripcion1[500];
    char descripcion2[500];
    char descripcion3[500];
public:
    void enviar_mantenimiento(); ///Carga una habitacion al sistema de mantenimiento
    void mostrar();
    ///GETS
    const char* getNumero(){return numero; }
    bool getEstado(){return estado;}
    float getGasto(){return gasto_total;}
    int getDias_en_mantenimiento(){return dias_estimado;}
    const char* getDescripcion(){return descripcion;}
    const char* getDescripcion1(){return descripcion1;}
    const char* getDescripcion2(){return descripcion2;}
    const char* getDescripcion3(){return descripcion3;}
    char getTipo(){return tipo;}

    /// SETS
    void setNumero(const char* nuevoNum){strcpy(numero,nuevoNum);}
    void setEstado(bool nuevoEstado){estado=nuevoEstado;}
    void setGasto(float nuevoTotal){gasto_total=nuevoTotal;}
    void setDiasEstimado(int diasNuevo ){dias_estimado=diasNuevo;}
    void setDescripcion(const char* descrip_){strcpy(descripcion,descrip_);}
    void setDescripcion1(const char* descrip1_){strcpy(descripcion1,descrip1_);}
    void setDescripcion2(const char* descrip2_){strcpy(descripcion2,descrip2_);}
    void setDescripcion3(const char* descrip3_){strcpy(descripcion3,descrip3_);}

    /// funciones con archivos
        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);

};

void mostrarVector_Mante(Habitacion_mantenimiento *v, long);


int Habitacion_mantenimiento::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;
	FILE *p;
	p=fopen(FILE_MANTENIMIENTO,"rb");
	if(p==NULL)
		{
		mensajes(1);
		cout<<"Presione una tecla para continuar";
    system("pause<null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}



bool Habitacion_mantenimiento::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_MANTENIMIENTO,"rb+");
	if(p==NULL){
        mensajes(1);
        pausa();
        return false;
	}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	return true;
}

bool Habitacion_mantenimiento::escribirEnDisco(){ /// graba un registro
FILE*P;
P=fopen(FILE_MANTENIMIENTO,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}

int buscarHabMantenimiento(const char* numero){ ///devuelve la posicion de la en el archivo
	int pos=0;
	Habitacion_mantenimiento reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if(strcmp(numero,reg.getNumero())==0&&reg.getEstado()==true)
			return pos;
		pos++;
		}
	return -1;
}


void Habitacion_mantenimiento::enviar_mantenimiento(){

    /// cargar ///
    Habitacion aux;
    cout << "\t\tNumero de habitación que quiere ingresa a mantenimiento: ";
    limpiarBuffer();
    cin.getline(numero,4);
    while(!verifMantenimiento(numero)){
      borrarPantalla();
      cout << "\t\tHabitación "<< numero << " ya se encuentra en mantenimiento"<< endl;
      pausa();
      borrarPantalla();
      if(salir())return;
      cout << "\t\tNumero de habitación que quiere ingresa a mantenimiento: ";
      limpiarBuffer();
      cin.getline(numero,4);

    }
    int pos=buscarHabitacion(numero);
    aux.leerDeDisco(pos);
    tipo=aux.getTipo();
    estado=true;
    cout << "\t\tDescripcion o motivo: ";
    cin.getline(descripcion,500);
    if(cadenaVacia(descripcion)==true){
        strcpy(descripcion,"no indica");
    }
    char gasto[10];
    cout << "\t\tGasto: ";
    limpiarBuffer();
    cin.getline(gasto,10);
    gasto_total=atof(gasto);
    char dias[10];
    cout << "\t\tDias estimados de reparación: ";
    limpiarBuffer();
    cin.getline(dias,10);
    if(cadenaVacia(dias)==true){
        borrarPantalla();
        mensajes(3);
        borrarPantalla();
        cout << "\t\tDias estimados de reparación: ";
        limpiarBuffer();
        cin.getline(dias,10);
    }

    dias_estimado=atoi(dias);
    aux.setMantenimietno(true);
    aux.modificarEnDisco(pos);

}

void Habitacion_mantenimiento::mostrar(){
cout << "\t\tNumero: "<< numero << endl;
if (!cadenaVacia(descripcion)){
    cout << "\t\tNota 1" << endl;
    cout << "\t\tDescipción: " << endl;
    cout << "\t\t" << cout << descripcion << endl;
    cout << endl;
}
if (!cadenaVacia(descripcion1)){
    cout << "\t\tNota 2" << endl;
    cout << "\t\tDescipción: " << endl;
    cout << "\t\t"<<cout << descripcion << endl;
    cout << endl;
}

    if (!cadenaVacia(descripcion2)){
    cout << "\t\tNota 3" << endl;
    cout << "\t\tDescipción: " << endl;
    cout << "\t\t"<<cout << descripcion << endl;
    cout << endl;
    }

if (!cadenaVacia(descripcion3)){
    cout << "\t\tNota 4" << endl;
    cout << "\t\tDescipción: " << endl;
    cout << "\t\t"<<cout << descripcion << endl;
    cout << endl;
}
    if(strcmp(descripcion,"no indica")==0){

        cout << "\t\tSin descripción del mantenimiento"<< endl;
        pausa();
    }
    cout << "\t\t---------------------------"<< endl;
    cout << "\t\tGasto total: $"<< gasto_total << endl;
    cout << "\t\tDias de reparación " << dias_estimado << endl;
    cout << "\t\t---------------------------" << endl;
    pausa();

}

bool verifMantenimiento(const char *num){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){


    if (aux.getMatenimiento()==true)
        return false;

}
return true;

}

void cargarParaMantenimiento(){
Habitacion_mantenimiento reg;
reg.enviar_mantenimiento();
if(reg.escribirEnDisco()){

    cout << "\t\tHabitación ";cout << reg.getNumero(); cout << " enviada a mantenimiento "<< endl;
    pausa();
}
else {

    cout << "\t\tNo se pude enviar habitación ";cout << reg.getNumero(); cout << " a mantenimiento "<< endl;
    pausa();
}


}

void sacar_de_mantenimiento(){
char hab[4];
Habitacion_mantenimiento aux;
Habitacion reg;
cout << "\t\tNúmero de habitación a habilitar"<< endl;
limpiarBuffer();
cin.getline(hab,4);
int posi=buscarHabitacion(hab);
int pos=buscarHabMantenimiento(hab);
if(pos==-1){

    cout << "\t\tHabitación "<< hab << " no se encuentra en mantenimiento "<< endl;
    pausa();
    return;
}
if(posi==-1){

    cout << "\t\tHabitación "<< hab << " no se encuentró"<< endl;
    pausa();
    return;

}
else {

    aux.leerDeDisco(pos);
    aux.setEstado(false);
    aux.modificarEnDisco(pos);

    reg.leerDeDisco(posi);
    reg.setMantenimietno(false);
    reg.modificarEnDisco(posi);
}

}

void copiarArchivoMemoriaMante(Habitacion_mantenimiento *v,int cant){
  FILE *P;
  P=fopen(FILE_MANTENIMIENTO,"rb");
  if(P==NULL){
      mensajes(1);
      return;
      }
    fread(v, sizeof(Habitacion_mantenimiento),cant,P);
  fclose(P);
  }

  void ordenarVectorMante(Habitacion_mantenimiento *v, int cant){
  int i, j, posmin;
  Habitacion_mantenimiento aux;
  for(i=0;i<cant-1;i++){


      posmin=i;
      for(j=i+1;j<cant;j++){
       if(strcmp(v[posmin].getNumero(),v[j].getNumero())>0)
                posmin=j;

      }
      aux=v[i];
      v[i]=v[posmin];
      v[posmin]=aux;


    }
}

void mostrarVectorMante(Habitacion_mantenimiento *v, int cant){
    int i;
    for(i=0; i<cant; i++){
        ///if(v[i].estado==true){
        v[i].mostrar();
        pausa();
        ///}
      }
}

int contarRegistrosMantenimiento(){
    FILE *F;
    F=fopen(FILE_MANTENIMIENTO,"rb");
    if(F==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (F,0,SEEK_END);
    tam=ftell(F);
    tamanioreg=sizeof(Cliente);
    cantidad=tam/tamanioreg;
    fclose(F);
    return cantidad;

}

void mostrarTodas_Mantenimiento(){

    int cant;
  cant=contarRegistrosMantenimiento();
  if(cant==0){
    char letra;
    cout << "\t\tPara visualizar habitaciones en mantenimiento debe cargar una primero"<<endl;
    cout << "\t\tDesea cargar una ahora?(s/n)";
    cin  >> letra;
    if (letra=='s'||letra=='S'){
            cargarParaMantenimiento();
            return;
    }
    else return;

    }
  Habitacion_mantenimiento *vec;
  vec = new Habitacion_mantenimiento[cant];
  if(vec==NULL) return;

  copiarArchivoMemoriaMante(vec,cant);
  ordenarVectorMante(vec,cant); /// ver como lo ordena ///
  mostrarVectorMante(vec,cant);/// se muestra el vector ordenado
  borrarPantalla();
  delete vec;

}


void listarHabMantenimiento(){
char hab[4];
Habitacion_mantenimiento aux;
cout << "\t\tIngrese número de habitación: ";
limpiarBuffer();
cin.getline(hab,4);
int pos=buscarHabMantenimiento(hab); /// buscar en las habitaciones activas ///
if(pos==-1){
    cout << "\t\tHabitación " << hab << " no está en mantenimiento"<< endl;
    pausa();
}
else {

    aux.leerDeDisco(pos);
    aux.mostrar();
}


}

void HabitacionesMantenimiento(){
char opcion;
while(true){
    system("cls");
    cout << "\t\t----BUSQUEDA HABITACIONES EN MANTENIMIENTO----" << endl;
    cout << "\t\t----------------------------------------------" << endl;
    cout << "\t\t1)Mostrar Habitaciones en mantenimiento"<< endl;/// mostrarlas ordenadas por numero
    cout << "\t\t2)Buscar habitación en mantenimiento   "<< endl;
    cout << "\t\t0) Salir ";
    cout << endl << "Opción: ";
    cin >> opcion;
    system("cls");
    switch(opcion){
      case '1':
    mostrarTodas_Mantenimiento();
      break;
      case '2':
    listarHabMantenimiento();
      break;
      case '0':
        return ;
      break;
      default:

      break;
    }
    cout << endl;

  }




}



void actualizarGastoMante(int);
void actualizarDiasEstimados(int);
void modificarDescripcionMante(int);
void agregarDescripcionMante(int);

void actualizarGastoMante(int pos){
Habitacion_mantenimiento aux;
aux.leerDeDisco(pos);
char gasto[10];
float nuevo_gasto;
cout << "\t\tGasto total parcial: $" << aux.getGasto(); cout << endl;
cout << "\t\tIngrese nuevo gasto: $" ;
limpiarBuffer();
cin.getline(gasto,10);
nuevo_gasto=atof(gasto);
float gastoFinal=aux.getGasto()+nuevo_gasto;
aux.setGasto(gastoFinal);
aux.modificarEnDisco(pos);
cout << "\t\tNuevo gasto total parcial: $" << gastoFinal << endl;
pausa();

}

void actualizarDiasEstimados(int pos){
Habitacion_mantenimiento aux;
aux.leerDeDisco(pos);
char dias[10];
int nuevoDias;
cout << "\t\tDias estimados" << aux.getDias_en_mantenimiento(); cout << endl;
cout << "\t\tAca se podría mostrar la fecha apróx de alta habitación" << endl;
cout << "\t\tAgregar dias al plazo de mantenimiento:" ;
limpiarBuffer();
cin.getline(dias,10);
nuevoDias=atoi(dias);
int diasFinal=aux.getDias_en_mantenimiento()+nuevoDias;
aux.setDiasEstimado(diasFinal);
aux.modificarEnDisco(pos);
cout << "\t\tDías estimados actualizados" << diasFinal << endl;
cout << "\t\tAca se podría mostrar la nueva fecha apróx de alta habitación" << endl;
pausa();

}


void modificarDescripcionMante(int pos){
Habitacion_mantenimiento aux;
aux.leerDeDisco(pos);
char nuevaDescripcion[500];
if(cadenaVacia(aux.getDescripcion())==false){
    cout << "\t\tDescripción 1: "<< endl;
    cout << "\t\t"<<cout << aux.getDescripcion(); cout<<endl;
}
if(cadenaVacia(aux.getDescripcion1())==false){
    cout << "\t\tDescripción 2: "<< endl;
    cout << "\t\t"<<cout << aux.getDescripcion(); cout<<endl;
}
if(cadenaVacia(aux.getDescripcion2())==false){
    cout << "Descripción 3: "<< endl;
    cout << "\t\t"<<cout << aux.getDescripcion(); cout<<endl;
}
if(cadenaVacia(aux.getDescripcion3())==false){
    cout << "Descripción 4: "<< endl;
    cout << "\t\t"<<cout << aux.getDescripcion(); cout<<endl;
}
char selec;
cout << "\t\tIngrese número de descripción a reemplazar: ";
limpiarBuffer();
cin >> selec;
switch (selec){
case '1':
    cout << "\t\tNueva descripción: ";
    limpiarBuffer();
    cin.getline(nuevaDescripcion,500);
    aux.setDescripcion(nuevaDescripcion);
    aux.modificarEnDisco(pos);
    break;
case '2':
    cout << "\t\tNueva descripción: ";
    limpiarBuffer();
    cin.getline(nuevaDescripcion,500);
    aux.setDescripcion1(nuevaDescripcion);
    aux.modificarEnDisco(pos);
    break;
case '3':
    cout << "\t\tNueva descripción: ";
    limpiarBuffer();
    cin.getline(nuevaDescripcion,500);
    aux.setDescripcion2(nuevaDescripcion);
    aux.modificarEnDisco(pos);
    break;
case '4':
    cout << "\t\tNueva descripción: ";
    limpiarBuffer();
    cin.getline(nuevaDescripcion,500);
    aux.setDescripcion3(nuevaDescripcion);
    aux.modificarEnDisco(pos);
    break;

default:
    mensajes(1);
    break;
}


}

void agregarDescripcionMante(int pos){
Habitacion_mantenimiento aux;
aux.leerDeDisco(pos);

char nuevaDesc[500];
if(cadenaVacia(aux.getDescripcion())==true){
    cout << "\t\tAgregar descripción: "<< endl;
    limpiarBuffer();
    cin.getline(nuevaDesc,500);
    while(cadenaVacia(nuevaDesc)==true){
        borrarPantalla();
        mensajes(3);
        borrarPantalla();
        cout << "\t\tAgregar descripción: "<< endl;
        limpiarBuffer();
        cin.getline(nuevaDesc,500);
    }
    aux.setDescripcion(nuevaDesc);
    aux.modificarEnDisco(pos);
    return;

}

if(cadenaVacia(aux.getDescripcion1())==true){
    cout << "\t\tAgregar descripción: "<< endl;
    limpiarBuffer();
    cin.getline(nuevaDesc,500);
    while(cadenaVacia(nuevaDesc)==true){
        borrarPantalla();
        mensajes(3);
        borrarPantalla();
        cout << "\t\tAgregar descripción: "<< endl;
        limpiarBuffer();
        cin.getline(nuevaDesc,500);
    }
    aux.setDescripcion1(nuevaDesc);
    aux.modificarEnDisco(pos);
    return;

}


if(cadenaVacia(aux.getDescripcion2())==true){
    cout << "\t\tAgregar descripción: "<< endl;
    limpiarBuffer();
    cin.getline(nuevaDesc,500);
    while(cadenaVacia(nuevaDesc)==true){
        borrarPantalla();
        mensajes(3);
        borrarPantalla();
        cout << "\t\tAgregar descripción: "<< endl;
        limpiarBuffer();
        cin.getline(nuevaDesc,500);
    }
    aux.setDescripcion2(nuevaDesc);
    aux.modificarEnDisco(pos);
    return;

}


if(cadenaVacia(aux.getDescripcion3())==true){
    cout << "\t\tAgregar descripción: "<< endl;
    limpiarBuffer();
    cin.getline(nuevaDesc,500);
    while(cadenaVacia(nuevaDesc)==true){
        borrarPantalla();
        mensajes(3);
        borrarPantalla();
        cout << "\t\tAgregar descripción: "<< endl;
        limpiarBuffer();
        cin.getline(nuevaDesc,500);
    }
    aux.setDescripcion3(nuevaDesc);
    aux.modificarEnDisco(pos);
    return;

}

cout << "\t\tNo hay mas espacio para almacenar una nueva descripción" << endl;
cout << "\t\tSi desea puede modificar las existentes"<< endl;
pausa();
return;




}



void modificarMantenimiento(){


char num[5];
cout << "\t\tIngrese número de habitación a modificar: ";
limpiarBuffer();
cin.getline(num,5);
if(cadenaVacia(num)){
    borrarPantalla();
    mensajes(3);
    cout << "\t\tIngrese número de habitación a modificar: ";
    limpiarBuffer();
    cin.getline(num,5);
}
int pos=buscarHabMantenimiento(num);
if(pos==-1){

    cout << "\t\tNo se encontró habitación"<< endl;
    pausa();
}


char opcion;
while(true){
    cout << "\t\t----MODIFICACIONES MANTENIMIENTO----" << endl;
    cout << "\t\t------------------------------------" << endl;
    cout << "\t\t1) Modificar gasto                          " << endl;
    cout << "\t\t2) Modificar dias estimados de mantenimiento" << endl;
    cout << "\t\t3) Modificar descripcion                    " << endl;
    cout << "\t\t4) Añadir descripción                       " << endl;
    cout << "\t\t0) Salir ";
    cout << endl << "Opción: ";
    cin >> opcion;
    system("cls");
    switch(opcion){
      case '1':
                actualizarGastoMante(pos);
      break;
      case '2':
                actualizarDiasEstimados(pos);
      break;
      case '3':
                modificarDescripcionMante(pos);
      break;
      case '4':
                agregarDescripcionMante(pos);
      break;
      case '0':
        return;
      break;
      default:
          mensajes(1);
      break;
    }
    cout << endl;

  }


}

void historialMantenimiento(){

char opcion;
while(true){
    system("cls");
    cout << "\t\t1)Mostrar todas"<< endl;
    cout << "\t\t2)Buscar "<< endl;
    cout << "\t\t0)Salir "<< endl;
    cout << "\t\t  Opción: ";
    cin >> opcion;
    system("cls");
    switch(opcion){
      case '1':
    mostrarHistorialMante();
      break;
      case '2':
    buscarEnHistorialMante();
      break;
      case '0':
        return;
      break;
      default:
      mensajes(1);
      break;
    }
    cout << endl;

  }

}


void mostrarHistorialMante(){
/// muestra desde las abiertas recientemente hasta las mas antiguas ///

    long cant=contarRegistrosMantenimiento();
    if(cant==0){

        cout << "\t\tAún no hay historial de mantenimiento "<< endl;
        pausa();
    }
    Habitacion_mantenimiento *vec;
    vec = new Habitacion_mantenimiento[cant];
    if(vec==NULL) return;
    copiarArchivoMemoriaMante(vec,cant);
    mostrarVector_Mante(vec,cant);/// se muestra el vector de atras para adelante ///
    borrarPantalla();
    delete vec;
}


  void mostrarVector_Mante(Habitacion_mantenimiento *v, long cant){
    int i;
    for(i=cant; i>0; i--){
        ///if(v[i].estado==true){
        v[i].mostrar();
        pausa();
        ///}
      }
}

void buscarEnHistorialMante(){
Habitacion_mantenimiento aux;
char num[4];
cout << "\t\tIngrese número de habitación: ";
limpiarBuffer();
cin.getline(num,4);
int pos=0;
int cant=0;
while(aux.leerDeDisco(pos++)==1){

    if ((strcmp(num,aux.getNumero())==0)&&(aux.getEstado()==false)){
        cant++;
        aux.mostrar();
        }
}
if (cant==0){
    printf("\t\tNo se encontró registros de la habitación en el archivo\n");
    pausa();
}


}

 int sectorMantenimiento(){
 char opcion;
 while(true){
     borrarPantalla();
     cout << "\t\t   ----SECTOR MANTENIMIENTO----" << endl;
     cout << "\t\t   ----------------------------" << endl;
     cout << "\t\t1) Cargar habitación para mantenimiento          " << endl;
     cout << "\t\t2) Sacar habitación de mantenimiento             "  << endl;
     cout << "\t\t3) Ver historial de habitaciones en mantenimiento" << endl; /// muestra los registros que ya estan en false ///
     cout << "\t\t4) Ver habitaciones en mantenimiento         " << endl; /// muestra todas juntas o una por numero ///
     cout << "\t\t5) Modificar habitacion en mantenimiento     " << endl; /// modifica lo que se lleva gastado, se agrega una descripcion mas
     cout << "\t\t0) Salir: "<< endl;
     cout << "\t\t  Opción: ";
     cin >> opcion;
     borrarPantalla();
     switch(opcion){
       case '1':
    cargarParaMantenimiento();
       break;
       case '2':
    sacar_de_mantenimiento();
       break;
       case '3':
        historialMantenimiento();
       break;
       case '4':
    HabitacionesMantenimiento();
        break;


       case '5':
        modificarMantenimiento();
        break;
        case '0':
         return 0;
       break;
       default:
           mensajes(1);
        break;
     }
     cout << endl;

   }

 }

 /// FIN SECTOR MANTENIMIENTO ///



int menuHabitaciones()
{

    char opcion;
    while(true){
        borrarPantalla();
        cout << "\t\t----MENÚ HABITACIONES----     " << endl;
        cout << "\t\t-------------------------     " << endl;
        /// si hay habitacion disponible cargar el cliente y le asigna la habitacion seleccionada
        /// sin necesidad de que haya reservado
        cout << "\t\t1) CARGAR NUEVA ESTADIA SIN RESERVA     "<< endl;
        cout << "\t\t2) RECEPCIÓN                            "<< endl;
        cout << "\t\t3) CHECK OUT                            "<< endl;
        cout << "\t\t4) VER HABITACIONES                     "<< endl; ///LIBRES , OCUPADAS, EN LIMPIEZA, TODAS
        cout << "\t\t5) VENTA DE PRODUCTOS                   " << endl;///Cargar modificar y eliminar gastos,
        cout << "\t\t6) MANTENIMIENTO HABITACIÓN             " << endl; /// PONE Y SACA UNA HABITACION DE MANTENIMIENTO
        cout << "\t\t7) LIMPIEZA HABITACIÓN                  " << endl; /// PONE Y SACA UNA HABITACION DE LIMPIEZA
        cout << "\t\t0) Salir ";
        cout << "\t\t   Opción: ";
        cin >> opcion;
        borrarPantalla();
        switch(opcion){
          case '1':
        cargarEstadia();
          break;
          case '2':
         menuRecepcion();
          break;
          case '3':
         realizarCheckOut();
          break;
          case '4':
            mostrarHabitaciones();
          break;
          case '5':
          menuVentas();

          break;
          case '6':
            sectorMantenimiento();
            break;
          case '7':
          menuLimpieza();
            break;
          case '0':
            return 0;
          break;
          default:
              mensajes(2);
            break;
        }
        cout << endl;

      }
}


/// SECTOR RECEPCION ///



int menuRecepcion(){
    char codReserva[10];
    Reserva aux;
cout << "\t\t---RECEPCIONAR CLIENTE---"<< endl;
cout << "\t\t-------------------------"<< endl;
cout << "\t\tIngrese id de reserva: ";
limpiarBuffer();
cin.getline(codReserva,10);
int codRes= atoi(codReserva);

int pos=buscarReservaId(codRes);
aux.leerDeDisco(pos);

if(pos==-1){
    cout << "\t\tLa reserva no se encuntra registrada o fue dada de baja"<< endl;
    pausa();
    return -1;
}
else{
aux.mostrar();
pausa();
cout << "\t\tAntes de seguir debe cargar el cliente en el sistema..." <<endl;
nuevoCliente();
cargarEstadia();
}

}

/// FIN RECEPCION ///


#endif // MENUHABITACIONES_H_INCLUDED



