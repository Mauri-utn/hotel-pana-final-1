#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED


const char *FILE_CAJA = "caja.dat";
const char *FILE_EGRESOS = "egresos.dat";

void abrirCaja();
void cerrarCaja();
void mostrarCaja();
void sumarCaja(float);
bool restarCaja(float);
int menuEgresos();
int buscarIdCaja();
void mostrarVentasCaja(int);
void nuevoEgreso();
void listarCajas();
void mostrarCajaId();
int buscarCaja(int);
int comprobarEstadoCaja();
void mostrarHistorialCajas();
int menuEgresos();
void mostrarEgresos();
int contarEgresos();
int buscarCajaAbierta();



///relacionar con reporte diarion mensual y anual


class Caja{ /// relacionar con venta sumandole las que van pagando, el pago anticipado , y el check out
    private:
        bool estadoCaja; /// true cuando se abre , false cuando se cierra ///
        float aperturaCaja;
        float cierreCaja;
        float ingresos;
        float egresos;
        int codigoCaja;
    public:
        void abrir();
        void cerrar();
        void mostrar();
        /// GETS

        bool getEstadoCaja(){ return estadoCaja;}
        float getAperturaCaja(){ return aperturaCaja;}
        float getCierreCaja(){ return cierreCaja;}
        int getCodigoCaja(){ return codigoCaja;}
        /// SETS
        void setIngresos(float monto){ingresos+=monto;}
        void setEgresos(float monto){egresos+=monto;}
        void setEstadoCaja(bool e){estadoCaja=e;}
        void setAperturaCaja(float a){aperturaCaja=a;}
        void setCierreCaja(float c){cierreCaja=c;}
        void setCodigoCaja(int c){estadoCaja=c;}

        bool EscribirEnDisco(void);
        int LeerDeDisco(int);
        bool modificarEnDisco(int);

};

void copiarArchivoMemoriaCaja(Caja *,long);
void mostrarVectorCaja(Caja *,long);



bool Caja::EscribirEnDisco(){
    FILE *p;
    p = fopen(FILE_CAJA,"ab");
    if(p==NULL){return false;}
    fwrite(this,sizeof (Caja),1,p);
    fclose(p);
}

int Caja::LeerDeDisco(int posicion){
    FILE *p;
    p = fopen(FILE_CAJA,"rb");
    if(p==NULL){ return false;}
    fseek(p,sizeof *this*posicion,0);
    int leyo=fread(this,sizeof *this,1,p);
    fclose(p);
    return leyo;
}

bool Caja::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_CAJA,"rb+");
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

void Caja::abrir(){

    int nuevoId=buscarIdCaja();
    nuevoId++;
    codigoCaja=nuevoId;
    cout << "\t\tIngrese monto de apertura" << endl;
    cin >> aperturaCaja;
    estadoCaja=true;
    ingresos=0;
    egresos=0;
    cierreCaja=aperturaCaja;

}
void Caja::mostrar(){
cout << "\t\tId caja: "<< codigoCaja << endl;
cout << "\t\tMonto apertura: $"<< aperturaCaja << endl;
cout << "\t\tIngresos: $" << ingresos << endl;
cout << "\t\tEgresos: $" << egresos << endl;
cout << "\t\tMonto cierre: &"<< cierreCaja << endl;

}

int menuCaja(){

char opcion;
while(true){
    borrarPantalla();
    cout << "\t\t-------MENÚ CAJA-------------" << endl;
    cout << "\t\t----------------------------- " << endl;
    cout << "\t\t1) ABRIR CAJA                 " << endl;
    cout << "\t\t2) CERRAR CAJA                " << endl;
    cout << "\t\t3) MOSTRAR CAJA               " << endl; /// muestra caja abierta y las anteriores ya cerradas ///
    cout << "\t\t4) EGRESOS                    " << endl;
    cout << "\t\t0) Salir: ";
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
      case '1':
          abrirCaja();
      break;
      case '2':
          cerrarCaja();

      break;
      case '3':
        listarCajas();
      break;
      case '4':

        break;
      case '0':
          return 0;
        break;
      default:
          mensajes(2);

        break;

        }
    }
}



void abrirCaja(){
    Caja reg;
    int estado;
    estado = comprobarEstadoCaja();
    if(estado==-1){cout << "\t\tYa hay una caja abierta" << endl; return ;}
    else{
        reg.abrir();
        if(reg.EscribirEnDisco()){
            cout << "\t\tCaja abierta con éxito" << endl;
            pausa();
            return;
        }
    }

}

void cerrarCaja(){
    Caja aux;
    int pos=buscarCajaAbierta();
    if(pos==-1){
            cout << "\t\tEn este momento no hay cajas abiertas"<< endl;
            pausa();
            return;
    }
    aux.LeerDeDisco(pos);
    aux.mostrar();
    pausa();
    char opcion[10];
    cout << "\t\tSeguro que quiere cerrar la caja(si/no)?" << endl;
    limpiarBuffer();
    cin.getline(opcion,10);
    while(cadenaVacia(opcion)==true){
        borrarPantalla();
        mensajes(3);
        borrarPantalla();
        cout << "\t\tSeguro que quiere cerrar la caja(si/no)?" << endl;
        limpiarBuffer();
        cin.getline(opcion,10);

    }

    if(strcmpi(opcion,"No")){
        return;
    }
    else{

        aux.setEstadoCaja(false);
        if(aux.modificarEnDisco(pos)){

            cout << "Caja cerrada con éxito "<< endl;
            pausa();
            return;

        }
    }
}

void listarCajas(){

char opcion;
while(true){
    system("cls");
    cout << "\t\t----LISTADO DE CAJA----" << endl;
    cout << "\t\t-----------------------" << endl;
    cout << "\t\t1) Mostrar caja abierta.      " << endl;
    cout << "\t\t2) Mostrar historial de cajas." << endl;
    cout << "\t\t3) Mostrar caja por id.       " << endl;
    cout << "\t\t0) Salir " << endl;
    cout << "\t\t   Opción: ";
    cin >> opcion;
    system("cls");
    switch(opcion){
      case '1':
        mostrarCaja();
      break;
      case '2':
        mostrarHistorialCajas();
      break;
      case '3':
        mostrarCajaId();
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

int buscarCaja(int id){

Caja aux;
int pos=0;
while(aux.LeerDeDisco(pos)==1){

    if(id==aux.getCodigoCaja()){
        return pos;
    }
    pos ++;

}

return -1;

}

void mostrarCajaId(){
Caja aux;
char cod[10];
cout << "\t\tIngrese Id de caja a listar: ";
limpiarBuffer();
cin.getline(cod,10);
int id=atoi(cod);
int pos=buscarCaja(id);
aux.LeerDeDisco(pos);
aux.mostrar();

}




int comprobarEstadoCaja(){
    Caja aux;
    int pos=0;
    while(aux.LeerDeDisco(pos++)==1){
        if(aux.getEstadoCaja()==true){
            return -1;
        }
    }
    return 1;
}


int buscarIdCaja(){ /// tambien cuenta la cantidad de registros que tiene caja
    FILE *P;
    P=fopen(FILE_CAJA,"rb");
    if(P==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (P,0,SEEK_END);
    tam=ftell(P);
    tamanioreg=sizeof(Caja);
    cantidad=tam/tamanioreg;
    fclose(P);
    return cantidad;
}


int buscarCajaAbierta(){
    Caja aux;
    int pos=0;
    while(aux.LeerDeDisco(pos)==1){

        if(aux.getEstadoCaja()==true){
            return pos;
            }
            pos ++;

    }
    return -1;
}

int buscarId_caja_venta(){

    Caja aux;
    int pos=0;
    while(aux.LeerDeDisco(pos++)==1){
        if(aux.getEstadoCaja()==true){
            return aux.getCodigoCaja();
        }
    }
    return -1;

}

void sumarCaja(float monto){

Caja aux;
int pos=buscarCajaAbierta();
if(pos==-1){
    cout << "\t\tEn este momento no hay cajas abiertas "<< endl;
    cout << "\t\tSe abrira caja para poder gestionar el monto ingresado"<< endl;
    pausa();
    abrirCaja();
    pos=buscarCajaAbierta();
}

aux.LeerDeDisco(pos);
aux.setIngresos(monto);
float nuevoCierre=monto+aux.getCierreCaja();
aux.setCierreCaja(nuevoCierre);
aux.modificarEnDisco(pos);

}

bool restarCaja(float monto){
Caja aux;
int pos=buscarCajaAbierta();
if(pos==-1){
    cout << "\t\tEn este momento no hay cajas abiertas "<< endl;
    pausa();
    cout << "\t\tSe abrira caja para poder gestionar el monto ingresado"<< endl;
    pausa();
    abrirCaja();
    pos=buscarCajaAbierta();
}

    aux.LeerDeDisco(pos);
    aux.setEgresos(monto);
    float nuevoCierre=aux.getCierreCaja()-monto;
    if(nuevoCierre<0)return false;
    else{
    aux.setCierreCaja(nuevoCierre);
    if(aux.modificarEnDisco(pos))return true;

     }
}




void mostrarCaja(){
Caja aux;
int pos=buscarCajaAbierta();
if(pos==-1){
    cout << "\t\tEn este momento no hay cajas abiertas "<< endl;
    pausa();
    return;
}
else {

    aux.LeerDeDisco(pos);
    mostrarVentasCaja(aux.getCodigoCaja());
    aux.mostrar();
}

}
void mostrarHistorialCajas(){
/// muestra desde las abiertas recientemente hasta las mas antiguas ///

    long cant=buscarIdCaja();
    if(cant==0){

        cout << "\t\tAún no hay historial de cajas "<< endl;
        pausa();
        return;
    }
    else{
    Caja *vec;
    vec = new Caja[cant];
    if(vec==NULL) return;
    copiarArchivoMemoriaCaja(vec,cant);
    mostrarVectorCaja(vec,cant);/// se muestra el vector de atras para adelante ///
    borrarPantalla();
    delete vec;
    }
}

void copiarArchivoMemoriaCaja(Caja *v,long cant){
  FILE *P;
  P=fopen(FILE_CAJA,"rb");
  if(P==NULL){
      mensajes(1);
      return;
      }
    fread(v, sizeof(Caja),cant,P);
  fclose(P);
  }

  void mostrarVectorCaja(Caja *v, long cant){
    int i;
    for(i=cant; i>0; i--){
        ///if(v[i].estado==true){
        v[i].mostrar();
        pausa();
        ///}
      }
}


/// SECTOR EGRESOS ///

class Egreso{

private:

    int codEgreso;
    char descripcion[500];
    float monto;
public:
    void cargar();
    void mostrar();
    ///gets
    int getCodEgreso(){return codEgreso;}
    const char* getDescripcion(){return descripcion;}
    float getMonto(){return monto;}
    /// sets
    void setMonto(float nuevoMonto){monto=nuevoMonto;}

    /// funciones con archivos
        bool escribirEnDisco(void);
        int leerDeDisco(int);
        bool modificarEnDisco(int);

};

void copiarArchivoMemEgresos(Egreso*,long);
void mostrarVecEgresos(Egreso*,long);

int Egreso::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;
	FILE *p;
	p=fopen(FILE_EGRESOS,"rb");
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



bool Egreso::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_EGRESOS,"rb+");
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

bool Egreso::escribirEnDisco(){ /// graba un registro de reservas
FILE*P;
P=fopen(FILE_EGRESOS,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}


void Egreso::cargar(){
int cod=contarEgresos();
codEgreso=cod+1;
cout << "\t\tDescripción: ";
limpiarBuffer();
cin.getline(descripcion,500);
cout << "\t\tMonto: $";
cin  >> monto;
if(!restarCaja(monto)){

    cout << "El egreso o gasto supera el dinero disponible en la caja abierta"<< endl;
    pausa();
    return;
}

}

void Egreso::mostrar(){
cout << "\t\tCódigo de egreso: "<< codEgreso << endl;
cout << "\t\tDescripción: "<< descripcion << endl;
cout << "\t\tMonto: $" << monto << endl;
cout << "\t\t-----------------" << endl;
pausa();
}

void nuevoEgreso(){

    Egreso reg;
    reg.cargar();
    if(reg.escribirEnDisco()){

        cout << "\t\tNuevo Egreso cargado con éxito"<< endl;
        pausa();
    }
    else {

        cout << "\t\tNo se pudo guardar el egreso ingresado"<< endl;
        pausa();

    }

}

void mostrarEgresos(){

    long cant=contarEgresos();
    if(cant==0){

        cout << "\t\tAún no hay registros de egresos "<< endl;
        pausa();
        return;
    }
    else{
    Egreso *vec;
    vec = new Egreso[cant];
    if(vec==NULL) return;
    copiarArchivoMemEgresos(vec,cant);
    mostrarVecEgresos(vec,cant);/// se muestra el vector de atras para adelante ///
    borrarPantalla();
    delete vec;
    }
}

void copiarArchivoMemEgresos(Egreso *v,long cant){
  FILE *P;
  P=fopen(FILE_EGRESOS,"rb");
  if(P==NULL){
      mensajes(1);
      return;
      }
    fread(v, sizeof(Egreso),cant,P);
    fclose(P);
  }

  void mostrarVecEgresos(Egreso *v, long cant){
    int i;
    for(i=cant; i>0; i--){
        ///if(v[i].estado==true){
        v[i].mostrar();
        pausa();
        ///}
      }
}


int contarEgresos(){ /// tambien cuenta la cantidad de registros que tiene caja
    FILE *P;
    P=fopen(FILE_EGRESOS,"rb");
    if(P==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (P,0,SEEK_END);
    tam=ftell(P);
    tamanioreg=sizeof(Egreso);
    cantidad=tam/tamanioreg;
    fclose(P);
    return cantidad;
}


int menuEgresos(){
char opc;
while(true){
    borrarPantalla();
    cout << "\t\t------EGRESOS------" << endl;
    cout << "\t\t-------------------" << endl;
    cout << "\t\t1) Cargar egreso  " << endl;
    cout << "\t\t2) Motrar egresos." << endl; /// muestra del mas reciente al mas antiguo ///
    cout << "\t\t0) Salir "<< endl;
    cout << "\t\t   Opción: ";
    cin >> opc;
    borrarPantalla();
    switch(opc){
      case '1':
    nuevoEgreso();
      break;
      case '2':
    mostrarEgresos();
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

/// FIN SECTOR EGRESO ///


#endif // CAJA_H_INCLUDED
