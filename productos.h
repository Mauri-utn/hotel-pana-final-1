#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED


#include "misfunciones.h"
#include "menuPrincipal.h"
#include "menuHabitaciones.h"
const char *FILE_PRODUCTOS = "productos.dat";

int menuProductos();
void nuevoProducto();
void bajarProducto();
void mostrarProductos();
void sumarStock();
void procesarVenta();
void listaProductos();
bool verificarCodigo(const char*);
int buscarProducto(const char*);
void nuevaVenta();
bool descontarStock(int,const char*);

class Producto{
    private:
        char id[5];
        char nombre[30];
        char descripcion[100];
        float precioUnidad;
        int stock;
        bool estado;

    public:

        void cargar();
        void cargarVenta();
        void mostrar();
        void mostrarVenta();
        ///GETS
        const char* getId(){return id;}
        const char* getNombre(){return nombre;}
        const char* getDescripcion(){return descripcion;}
        float getPrecio(){return precioUnidad;}
        bool getEstado(){return estado;}
        int getStock(){return stock;}
        ///SETS
        void setId(const char*);
        void setNombre(const char*);
        void setDescripcion(const char*);
        void setPrecio(float);
        void setEstado(bool);
        void setStock(int);
        /// funciones con archivos
        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);


};

int Producto::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;
	FILE *p;
	p=fopen(FILE_PRODUCTOS,"rb");
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



bool Producto::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_PRODUCTOS,"rb+");
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

bool Producto::escribirEnDisco(){ /// graba un registro de reservas
FILE*P;
P=fopen(FILE_PRODUCTOS,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}

int buscarProducto(const char* id){ ///devuelve la posicion de la reserva en el archivo
	int pos=0;
	Producto reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if((strcmp(id,reg.getId())==0)&& reg.getEstado()==true){
			return pos;
			}
		pos++;
		}
	return -1;
}

///SETS
void Producto::setId(const char*codigo){
    strcpy(id,codigo);
}
void Producto::setNombre(const char*nuevoNom){
        strcpy(nombre,nuevoNom);
}
void Producto::setDescripcion(const char*nuevaDesc){
    strcpy(descripcion,nuevaDesc);
}
void Producto::setPrecio(float nuevoPrecio){
precioUnidad=nuevoPrecio;
}
void Producto::setEstado(bool variable){
estado=variable;
}
void Producto::setStock(int nuevoStock){

stock=nuevoStock;
}
/// FIN SETS PRODCUTO
void Producto::cargar(){
cout << "\t\tCodigo de producto: ";
limpiarBuffer();
cin.getline(id,5);
cout << "\t\tNoubre del producto: ";
limpiarBuffer();
cin.getline(nombre,30);
cout << "\t\tDescripcion: ";
limpiarBuffer();
cin.getline(descripcion,100);
cout << "\t\tPrecio unitario: $";
cin  >> precioUnidad;
cout << "\t\tStock inicial: ";
cin  >> stock;
estado=true;

}

void Producto::mostrar(){

cout << "\t\tCódigo de producto:  "<< id << endl;
cout << "\t\tNombre del producto: "<< nombre << endl;
cout << "\t\tDescripción:         "<< descripcion <<endl;
cout << "\t\tPrecio unitario: $"<< precioUnidad<<endl;
cout << "\t\tStock actual:        "<< stock << endl;
cout << "\t\t----------------------"<< endl;
pausa();

}

void Producto::cargarVenta(){
cout << "\t\tIngrese código de producto: ";
limpiarBuffer();
cin.getline(id,5);

}


void Producto::mostrarVenta(){
cout << "\t\tCodigo de producto\tNombre del producto\tDescripción\tPrecio unitario";
cout << "\t\t"<<cout << "\t"<<id<<"\t"<<nombre<<"\t"<< descripcion<<"\t"<< precioUnidad<<endl;
cout << "\t\t---------------------------------------------------------------------"<< endl;
}

void nuevoProducto(){
Producto reg;
reg.cargar();
if(reg.escribirEnDisco()){
        cout << "\t\tPRODUCTO CARGADO CON ÉXITO!"<< endl;
        pausa();
}

}
void bajarProducto(){
Producto reg;
char ide[5];
cout << "\t\tIngrese ID de producto: "<< endl;
limpiarBuffer();
cin.getline(ide,5);
int pos=buscarProducto(ide);
if(pos==-1){

    cout << "\t\tEl producto no esta registrado o fue dado de baja"<< endl;
    pausa();
    return;
}
else{


    reg.leerDeDisco(pos);
    reg.setEstado(false);
    if(reg.modificarEnDisco(pos)){

        cout << "\t\tProducto dado de baja con éxito"<< endl;
        pausa();
        return;
    }

}



}


void mostrarProductos(){
Producto aux;
int pos=0;
while(aux.leerDeDisco(pos++)==true){

    if(aux.getEstado()==true){
            aux.mostrar();
            cout << endl;
    }
}

}

void listaProductos(){

Producto aux;
int pos=0;
int cont=0;
cout << "\t\tProducto\tCodigo\t\tPrecio por unidad"<< endl;
cout << "\t\t............................................"<< endl;
while(aux.leerDeDisco(pos++)==true){

    if(aux.getEstado()==true&&cont==0){
            cout << aux.getId();cout<<"\t\t";cout<<aux.getNombre();cout<<"\t\t\t$";cout<<aux.getPrecio();
            cout << endl;
    }

    if(aux.getEstado()==true&&cont>0){
            cout << "\t\t"<<cout << aux.getId();cout<<"\t\t";cout<<aux.getNombre();cout<<"\t\t$";cout<<aux.getPrecio();
            cout << endl;
    }

    cont++;
}
cout << "\t\t............................................"<< endl;
    pausa();

}


void sumarStock(){

Producto aux;
char cod[5];
int cant;
cout << "\t\tIngrese el ID del producto y el stock que ingresa"<< endl;
cout << "\t\tID: ";
limpiarBuffer();
cin.getline(cod,5);
cout << "\t\tStock ingresante: ";
cin  >> cant;
int pos=buscarProducto(cod);
if(pos==-1){

    cout << "\t\tEl producto no esta registrado o fue dado de baja"<< endl;
    pausa();
    return;
}
else{


    aux.leerDeDisco(pos);
    int stockNuevo=aux.getStock()+cant;
    aux.setStock(stockNuevo);
    if(aux.modificarEnDisco(pos)){

        cout << "\t\tSe agrego stock a producto con éxito"<< endl;
        pausa();
        return;
    }

}

}

bool descontarStock(int cant,const char *cod){ /// descuenta stock en la venta ///
Producto aux;
int pos=buscarProducto(cod);
aux.leerDeDisco(pos);
int nStock=aux.getStock()-cant;
aux.setStock(nStock);
if(aux.modificarEnDisco(pos))return true;
return false;

}



int menuProductos(){
char opcion;
while(true){
    borrarPantalla();
    cout << "\t\t-------MENÚ PRODUCTOS-------- " << endl;
    cout << "\t\t----------------------------- " << endl;
    cout << "\t\t1) PUNTO DE VENTA.            " << endl;
    cout << "\t\t2) AÑADIR PRODUCTOS           " << endl;
    cout << "\t\t3) DAR DE BAJA PRODUCTOS      " << endl;
    cout << "\t\t4) AÑADIR STOCK A PRODUCTOS   " << endl;
    cout << "\t\t5) MOSTRAR TODOS LOS PRODUCTOS" << endl;
    cout << "\t\t6) MODIFICAR PRODUCTOS        " << endl;
    cout << "\t\t0) Salir ";
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
      case '1':
    nuevaVenta();
      break;
      case '2':
    nuevoProducto();
      break;
      case '3':
    bajarProducto();
      break;
      case '4':
    sumarStock();
        break;
      case '5':
          mostrarProductos();
        break;
      case '6':
          listaProductos();
        break;

      case '0':
        return 0;
      break;
    }
    cout << endl;

  }

}




#endif // PRODUCTOS_H_INCLUDED
