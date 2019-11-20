#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED


#include "misFunciones.h"

const char* traerMes(int);
const char* traerGenero(char);
bool validarDni(const char *);
bool validarFechadeNac(int,int,int);
bool validarTarjeta(char*);
int modificarCliente();
int listarUnCliente();
int buscarCliente (char*);
int buscarClienteTarjeta(char *);
int buscarClienteTelefono(char *);
bool validarVencimientoTarjeta(int,int);

const char *FILE_CLIENTES     = "clientes.dat";


    /// ////// ///
    ///CLASES///
    /// ///// ///

    class Direccion{

private:
    char calle[30];
    char numero[10];
    char ciudad[30];
    char cp[10];
    char pais[30];

public:
    ///Direccion(char*,char*,char*,char*);
    void mostrar();
    void cargar();
    ///GETS()
    const char* getCalle(){return calle;}
    const char* getNumero(){return numero;}
    const char* getCP(){return cp;}
    const char* getCiudad(){return ciudad;}

    ///SETS()
    void setCalle(const char*);
    void setNumero(const char*);
    void setCP(const char*);
    void setCiudad(const char*);

};

/*Direccion::Direccion(char street[30]="CASA S/NÚMERO",char num="0000",char codP="0000",char ciud[30]="aaaa"){
    strcpy(calle,street);
    strcpy(numero,num);
    strcpy(cp,codP);
    strcpy(ciudad,ciud);

}*/


void Direccion::setCalle(const char*nuevaCalle){
strcpy(calle,nuevaCalle);
}
void Direccion::setNumero(const char *nuevoNumero){
strcpy(numero,nuevoNumero);
}
void Direccion::setCP(const char *nuevoCp){
strcpy(cp,nuevoCp);
}
void Direccion::setCiudad(const char* nuevaCiudad){
strcpy(ciudad,nuevaCiudad);
}



void Direccion::cargar(){

    cout << "\t\tCalle: ";
    cin.ignore();
    cin.getline(calle,30);
    while(cadenaVacia(calle)==true){
        borrarPantalla();
        mensajes(3);
        borrarPantalla();
        cout << "\t\tCalle: ";
        cin.ignore();
        cin.getline(calle,30);
    }

    cout << "\t\tNúmero: ";
    limpiarBuffer();
    cin.getline(numero,10);
    while(cadenaVacia(numero)==true){
        borrarPantalla();
        mensajes(3);
        borrarPantalla();
        cout << "\t\tNúmero: ";
        cin.ignore();
        cin.getline(numero,10);
    }


    cout << "\t\tCódigo postal: ";
    limpiarBuffer();
    cin.getline(cp,10);
    while(cadenaVacia(cp)==true){
        borrarPantalla();
        mensajes(3);
        borrarPantalla();
        cout << "\t\tCódigo postal: ";
        cin.ignore();
        cin.getline(cp,10);
    }


    cout << "\t\tCiudad: ";
    cin.ignore();
    cin.getline(ciudad,30);
    while(cadenaVacia(ciudad)==true){
        borrarPantalla();
        mensajes(3);
        borrarPantalla();
        cout << "\t\tCiudad: ";
        cin.ignore();
        cin.getline(ciudad,30);
    }


    cout << "\t\tPaís: ";
    cin.ignore();
    cin.getline(pais,30);
    while(cadenaVacia(pais)==true){
        borrarPantalla();
        mensajes(3);
        borrarPantalla();
        cout << "\t\tpaís: ";
        cin.ignore();
        cin.getline(pais,30);
    }


}
void Direccion::mostrar(){

cout << "\t\tCalle: "<< calle;cout << "\tNúmero: "<< numero << endl;
cout << "\t\tCódigo postal: "<< cp;cout <<"\tCiudad: "<< ciudad << endl;
cout << "\t\tPaís: "<< pais << endl;


}

    /// CLASES FECHA ///
class Fecha{

private:
    int dia,mes,anio;
public:
    Fecha(int d=1,int m=1,int a=2000){
    dia=d;
    mes=m;
    anio=a;
    }
    void mostrar();
    void mostrarConBarra();
    void mostrarConPalabra();
    void cargar();
    bool cargarVenc();
    void mostrarVenc();
    ///GETS()
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
   ///SETS()
    void setDia(int nuevoDia){
    dia=nuevoDia;
    }
    void setMes(int nuevoMes){
    mes=nuevoMes;
    }
    void setAnio(int nuevoAnio){
    anio=nuevoAnio;
    }

    /// sobrecarga de operadores
    bool operator==(Fecha &);
};

bool Fecha::operator==(Fecha &obj)
{

  if((dia==obj.dia) && (mes==obj.mes) && (anio==obj.anio))return true;
  return false;
} /// operatos == por referencia





void Fecha::cargar(){

    cout << "\t\tDía: ";
    cin  >> dia;
    cout << "\t\tMes: ";
    cin  >> mes;
    cout << "\t\tAño: ";
    cin >> anio;

}
bool validarVencimientoTarjeta(int mes, int anio){
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    ///FECHA ACTUAL tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year
    ///cout << tmPtr->tm_mday <<"/"<<tmPtr->tm_mon+1<<"/"<<1900+tmPtr->tm_year<<endl;
    ///cout << tmPtr->tm_hour<<":"<<tmPtr->tm_min<<":"<<tmPtr->tm_sec<<endl;///HORA

    if(anio<1900+tmPtr->tm_year)return false;
    /// si el año es menor retorna falso
    if((anio==1900+tmPtr->tm_year)&&(mes<tmPtr->tm_mon+1))return false;
    return true;


}

bool Fecha::cargarVenc(){
    cout << "\t\tMes: ";
    cin  >> mes;
    cout << "\t\tAño: ";
    cin  >> anio ;
    if(validarVencimientoTarjeta(mes,anio)==false){
        borrarPantalla();
        cout << "\t\tTarjeta vencida"<< endl;
        pausa();
        borrarPantalla();
        return false;
    }

    return true;

}
void Fecha::mostrarVenc(){

    cout << mes << "/" << anio <<endl;
}
void Fecha::mostrar(){
    cout << "\t\tDía: "<< dia << endl;
    cout << "\t\tMes: "<< mes << endl;
    cout << "\t\tAño: "<< anio << endl;
}


void Fecha::mostrarConBarra(){

    cout << dia << "/" << mes << "/" << anio << endl;

}

void Fecha::mostrarConPalabra(){

cout << dia << " de "<<traerMes(mes)<< " del "<< anio << endl;

}

const char* traerMes(int m){

switch(m){
    case 1:return "Enero";
    break;
    case 2:return "Febrero";
    break;
    case 3:return "Marzo";
    break;
    case 4:return "Abril";
    break;
    case 5:return "Mayo";
    break;
    case 6:return "Junio";
    break;
    case 7:return "Julio";
    break;
    case 8:return "Agosto";
    break;
    case 9:return "Septiembre";
    break;
    case 10:return "Octubre";
    break;
    case 11:return "Noviembre";
    break;
    case 12:return "Diciembre";
    break;
}

}
/// CLASE PERSONA /// SE USA PARA CARGAR UN MENOR DE EDAD Y PARTE DE UN CLIENTE
class Persona {

protected:
    char apellidos[50];
    char nombres[50];
    char genero;
    char dni[10];
    char nacionalidad[50];
public:
    Fecha fechaNac;

    void cargar();
    void mostrar();
    ///GETS()
    char* getApellido(){return apellidos;}
    char* getNombre(){return nombres;}
    char getGenero(){return genero;}
    char* getDni(){return dni;}
    const char* getNacionalidad(){return nacionalidad;}
    int getDiaNac(){return fechaNac.getDia();}
    int getMesNac(){return fechaNac.getMes();}
    int getAnioNac(){return fechaNac.getAnio();}

    /// SETS()
    void setApellido(char*);
    void setNombre(char*);
    void setGenero(char);
    void setDni(char*);
    void setNacionalidad(char*);
    void setDiaNac(int nDia){fechaNac.setDia(nDia);}
    void setMesNac(int nMes){fechaNac.setMes(nMes);}
    void setAnioNac(int nAnio){fechaNac.setAnio(nAnio);}
    ///FUNCIONES DE ARCHIVOS
    bool escribirDisco(int);
    bool leerDisco(int);
    bool grabarRegistro();

};

void Persona::setApellido(char *nuevoApellido){
strcpy(apellidos,nuevoApellido);
}
void Persona::setNombre(char *nuevoNombre){
strcpy(apellidos,nuevoNombre);
}
void Persona::setGenero(char nuevoGenero){
genero=nuevoGenero;
}
void Persona::setDni(char *nuevoDni){
strcpy(dni,nuevoDni);
}
void Persona::setNacionalidad(char *nuevaNacionalidad){
strcpy(nacionalidad,nuevaNacionalidad);
}

/*bool Persona::grabarRegistro(){
FILE*P;
P=fopen(FILE_MENORES,"ab");
if(P==NULL){
    mensajes(1);
    pausa();
    return false;
}
fwrite(this,sizeof(Persona),1,P);
fclose(P);
return true;
} */ /// graba una persona


void Persona::cargar(){

    cout << "\t\tApellido: ";
    cin.ignore();
    cin.getline(apellidos,50);
    while(strlen(apellidos)==0)
    {
        borrarPantalla();
        mensajes(3);
        pausa();
        borrarPantalla();
        cout << "\t\tApellido: ";
        cin.getline(apellidos,50);
    }
    cout << "\t\tNombre: ";
    cin.getline(nombres,50);
    while(strlen(nombres)==0)
    {
        borrarPantalla();
        mensajes(3);
        pausa();
        borrarPantalla();
        cout << "\t\tNombre: ";
        cin.getline(nombres,50);
    }
    /*
    cout << "GÉNERO---> "<<endl;
    cout << "M)Mujer    "<<endl;
    cout << "H)Hombre   "<<endl;
    cout << "O)Otro     "<<endl;
    cout << "OPCIÓN---> ";
    cin  >> genero;
    while(genero==""){
        borrarPantalla();
        mensajes(3);
        pausa();
        borrarPantalla();
        cout << "GÉNERO---> "<<endl;
    cout << "M)Mujer    "<<endl;
    cout << "H)Hombre   "<<endl;
    cout << "O)Otro     "<<endl;
    cout << "OPCIÓN---> ";
    cin  >> genero;
    }*/ /// SACAMOS GENERO NO NOS PARECIA RELEVANTE PARA QUE LA CARGA NO SEA TAN LARGA ///

    cout << "\t\tDni: ";
    cin.ignore();
    cin.getline(dni,10);
    while(strlen(dni)==0){
    borrarPantalla();
    mensajes(3);
    pausa();
    borrarPantalla();
    cout << "\t\tDni: ";
    cin.ignore();
    cin.getline(dni,10);
    }
    while(!validarDni(dni)){
    borrarPantalla();
    char sel;
    cout << "\t\tEL DNI YA ESTA REGISTRADO"<<endl;
    cout << "\t\tsalir(s)/cargar otro(c)";
    cin  >> sel;
    switch (sel){
    case 's':
    case 'S':
    return;
    break;
    case 'c':
    case 'C':
    cout << "\t\tDni: ";
    cin.ignore();
    cin.getline(dni,10);

    break;
default:
    mensajes(2);
    break;
        }
}
    cout << "\t\tNacionalidad: ";
    cin.getline(nacionalidad,50);
    cout << "\t\tFecha de nacimiento: "<<endl;
    fechaNac.cargar();
    bool vof=validarFechadeNac(getDiaNac(),getMesNac(),getAnioNac());
    while (vof==false){
        borrarPantalla();
        cout <<"\t\tFECHA DE NACIMIENTO INVALIDA POR FAVOR VOLVER A INGRESAR!"<<endl;
        pausa();
        borrarPantalla();
        cout << "\t\tFecha de nacimiento: "<<endl;
        fechaNac.cargar();
        vof=validarFechadeNac(getDiaNac(),getMesNac(),getAnioNac());
    }

}

void Persona::mostrar(){

    cout << "\t\tApellido: "<< apellidos;cout << "\t\tNombre: "<< nombres   << endl;
    ///cout << "GÉNERO: "<< traerGenero(genero) << endl;
    cout << "\t\tDni: "<< dni;cout << "\t\tNacionalidad: "<< nacionalidad << endl;
    cout << "\t\tFecha de nacimiento: " ; fechaNac.mostrarConBarra();

}
const char* traerGenero(char g){

    switch(g){
    case 'm':
    case 'M':
    return "Mujer";
    break;
    case 'h':
    case 'H':
    return "Hombre";
    break;
    case 'o':
    case '0':
        return "Otro";
        break;
    }
}


    /// CLASE CLIENTE ///

class Cliente: public Persona  {
    private:
    char mail[50];
    char telefono[30];
    Direccion domicilio;
    char NroTarjeta[21],codSeguridad[5];
    Fecha vencimientoTarjeta;

    public:
    void cargar();
    void mostrar();
    ///GETS()
    const char* getMail(){return mail;}
    const char* getTelefono(){return telefono;}
    const char* getTarjeta(){return NroTarjeta;}
    const char* getCodSeguridad(){return codSeguridad;}
    int getMesVenc(){return vencimientoTarjeta.getMes();}
    int getAnioVenc(){return vencimientoTarjeta.getAnio();}
    /// SETS()
    void setMail(const char*);
    void setTelefono(const char*);
    void setNroTarjeta(const char*);
    void setCodigoSeguridad(const char*);
    void setMesVenc(int nMes){vencimientoTarjeta.setMes(nMes);}
    void setAnioVenc(int nAnio){vencimientoTarjeta.setAnio(nAnio);}
    void setCalle(const char*nCalle){domicilio.setCalle(nCalle);}
    void setNum(const char* num){domicilio.setNumero(num);}
    void setCp(const char* nCp){domicilio.setCP(nCp);}
    void setCiudad(const char *nCiu){domicilio.setCiudad(nCiu);}


    /// FUNCIONES CON ARCHIVOS
        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);



};

/// FUNCIONES DE GRABADO, LECTURA Y MODIFICACION EN DISCO ///
bool Cliente::escribirEnDisco(){
FILE*P;
P=fopen(FILE_CLIENTES,"ab");
if(P==NULL)return false;
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}

int Cliente::leerDeDisco(int pos){/// lee el disco hasta encontrar el registro
	int x;
	FILE *p;
	p=fopen(FILE_CLIENTES,"rb");
	if(p==NULL){
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



bool Cliente::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_CLIENTES,"rb+");
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

/// FIN FUNCIONES DE GRABADO , MODIFICACION Y LECTURA EN DISCO ///

int buscarCliente(char *doc){ ///devuelve la posicion del cliente en el archivo
	int pos=0;
	Cliente reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if(strcmp(doc,reg.getDni())==0)
			return pos;
		pos++;
		}
	return -1;
}

int buscarClienteTarjeta(char *tarjeta){ ///devuelve la posicion del cliente en el archivo
	int pos=0;
	Cliente reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if(strcmp(tarjeta,reg.getTarjeta())==0)
			return pos;
		pos++;
		}
	return -1;
}

int buscarClienteTelefono(char *numTelefono){ ///devuelve la posicion del cliente en el archivo
	int pos=0;
	Cliente reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if(strcmp(numTelefono,reg.getTelefono())==0)
			return pos;
		pos++;
		}
	return -1;
}


void  Cliente::setMail(const char *nuevoMail){
strcpy(mail,nuevoMail);
}
void  Cliente::setTelefono(const char* nuevoTelefono){
    strcpy(telefono,nuevoTelefono);
}
void  Cliente::setNroTarjeta(const char *nuevaTarjeta){
strcpy(NroTarjeta,nuevaTarjeta);
}
void  Cliente::setCodigoSeguridad(const char *nuevoCS){
strcpy(codSeguridad,nuevoCS);
}


void Cliente::cargar(){
    Persona::cargar();
    bool tarjeta=true;
    ///mail
    cout << "\t\tMail: ";
    fflush(stdin);
    cin.getline(mail,50);
    while(cadenaVacia(mail)){
    borrarPantalla();
    mensajes(3);
    pausa();
    borrarPantalla();
    cout << "\t\tMail: ";
    fflush(stdin);
    cin.getline(mail,50);
}
    /// telefono
    cout << "\t\tTélefono: ";
    cin.ignore();
    cin.getline(telefono,30);
    while(cadenaVacia(telefono)){
    borrarPantalla();
    mensajes(3);
    pausa();
    borrarPantalla();
    cout << "\t\tTélefono: ";
    cin.ignore();
    cin.getline(telefono,30);
    }

    /// domicilio
    cout <<"\t\tDomicilio--->"<<endl;
    domicilio.cargar();

    /// tarjeta de credito ///
    bool cargada=false;
    char opc[10];
    cout << "\t\tCargar tarjeta de crédito(si/no)?: ";
    limpiarBuffer();
    cin.getline(opc,10);
    while(cadenaVacia(opc)==true){
        borrarPantalla();
        mensajes(3);
        borrarPantalla();
        cout << "\t\tCargar tarjeta de crédito(si/no)?: ";
        limpiarBuffer();
        cin.getline(opc,10);

    }

    if(strcmp(opc,"no")==0||strcmp(opc,"NO")==0||strcmp(opc,"No")==0){
            strcpy(NroTarjeta,"no indica");
            strcpy(codSeguridad,"no indica");
            tarjeta=false;
            cargada=true;
    }



    while(cargada==false){
    if(tarjeta==true){
    cout << "\t\tNro.tarjeta: ";
    cin.ignore();
    cin.getline(NroTarjeta,21);
    while(cadenaVacia(NroTarjeta)){
        borrarPantalla();
        mensajes(3);
        cout << "\t\tNro.Tarjeta: ";
        limpiarBuffer();
        cin.getline(NroTarjeta,21);

    }
    while(!validarTarjeta(NroTarjeta)&&tarjeta==true){
    borrarPantalla();
    char sel;
    cout << "\t\tLA TARJETA YA ESTA REGISTRADA"<<endl;
    cout << "\t\tsalir(s)/cargar otra(c)      "<< endl;
    cin  >> sel;
    switch (sel){
    case 's':
    case 'S':
        strcpy(NroTarjeta,"no indica");
        strcpy(codSeguridad,"no indica");
        tarjeta=false;
        cargada=true;
    break;

    case 'c':
    case 'C':
    cout << "\t\tNro.Tarjeta: ";
    cin.ignore();
    cin.getline(NroTarjeta,30);
    while(cadenaVacia(NroTarjeta)){
        borrarPantalla();
        mensajes(3);
        cout << "\t\tNro.tarjeta: ";
        cin.ignore();
        cin.getline(NroTarjeta,30);
    }
    break;
default:
    mensajes(2);
    break;

    }

        } /// fin while que valida la tarjeta

} /// fin if tarjeta == true


    /// campos si indica tarjeta ///

    if(tarjeta==true){
    cout << "\t\tCódigo de seguridad: ";
    cin.getline(codSeguridad,5);
    while(cadenaVacia(codSeguridad)){
        borrarPantalla();
        mensajes(3);
        pausa();
    cout << "\t\tCódigo de seguridad: ";
    cin.getline(codSeguridad,5);
    }

    cout << "\t\tVencimiento tarjeta: "<<endl;
    if(vencimientoTarjeta.cargarVenc()==false){
        char pago[10];
        cout << "\t\tPaga en efectivo(si/no)?: ";
        limpiarBuffer();
        cin.getline(pago,10);
        if(cadenaVacia(pago)==true){
            borrarPantalla();
            mensajes(3);
            borrarPantalla();
            cout << "\t\tPaga en efectivo(si/no): ";
            limpiarBuffer();
            cin.getline(pago,10);
        }
        if(strcmp(pago,"si")==0||strcmp(pago,"SI")==0||strcmp(pago,"Si")==0){
        strcpy(NroTarjeta,"no indica");
        strcpy(codSeguridad,"no indica");
        tarjeta=false;
        cargada=true;

        }
        else{
             tarjeta=true;
            cargada=false;/// vuelve a cargar una tarjeta de cero ///
        }

        }/// verificar que no este vencida ///
    }

    } /// FIN WHILE CARGA DE TARJETA ///
}



void Cliente::mostrar(){

    Persona::mostrar();
    cout << "\t\tMail: "<< mail << endl;
    cout << "\t\tTélefono: "<< telefono << endl;
    cout << "\t\tDomicilio: "<<endl;
    domicilio.mostrar();
    if(strcmp(NroTarjeta,"no indica")==0){

        cout << "\t\tNro.Tarjeta: "<< NroTarjeta << endl;
    }
    else{
    cout << "\t\tNro.Tarjeta: "<< NroTarjeta << endl;
    cout << "\t\tCódigo de seguridad: "<< codSeguridad << endl;
    cout << "\t\tVencimiento tarjeta: "; vencimientoTarjeta.mostrarVenc();
    }
    cout << "\t\t-------------------------------"<< endl;
    pausa();


}

///PROTOTIPO FUNCIONES GLOBALES

bool existeCliente(const char*);

int menuClientes();
void nuevoCliente(); /// crea un nuevo cliente y lo graba
int listarTodos(); /// menu para listar clientes segun opcion ingresada
/// TODOS LOS MENUS VAN CON INT PARA DIFERENCIARLOS DE OTRAS FUNCIONES ///

void listadoAlfabeticoCliente(); /// listado de A-Z
void listarClientes(); /// lista primero el mas viejo en el sistema
void copiarArchivoMemoriaCliente(Cliente *,long);
void ordenarVectorCliente(Cliente *,long);
void mostrarVectorCliente(Cliente *,long);
void heapsortClientes(Cliente *, long); /// prueba de ordenamiento por heapsort
bool validarDni(const char*);
int contarRegistrosClientes();/// cuenta la cantidad de registros que hay en el archivo clientes
bool grabarCliente(Cliente);
int biciesto(int);
void cargarDias(int *, int );
//int contarRegistrosMenores();/// cuenta la cantidad de registros que hay en el archivo menores
//bool grabarPersona(Persona);
//void listadoAlfabeticoMenores(); /// listado albafetico de menores
//void copiarArchivoMemoria(Persona*,long);
//void mostrarVectorPersona(Persona *, long );
//void ordenarVectorPersona(Persona*, long );
//bool existeMenor(const char*);

/// FUNCIONES GLOBALES CLIENTES

void nuevoCliente(){
 cout << "\t\tCARGAR NUEVO CLIENTE "<< endl;
 cout << "\t\t-------------------- "<< endl;
Cliente reg;
reg.cargar();
if(reg.escribirEnDisco()){
        cout << "\t\tCLIENTE GRABADO CON ÉXITO"<< endl;
        pausa();
        return;
     }
}



int contarRegistrosClientes(){
    FILE *F;
    F=fopen(FILE_CLIENTES,"rb");
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

/*bool grabarCliente(Cliente aux){
FILE*P;
P=fopen(FILE_CLIENTES,"ab");
if(P==NULL){
    mensajes(1);
    pausa();
    return false;
}
fwrite(&aux,sizeof(Cliente),1,P);
fclose(P);
return true;
}*/ /// SE REEMPLAZO POR UNA FUNCION EN LA MISMA CLASE CLIENTE

void listadoAlfabeticoCliente(){

  long cant;
  cant=contarRegistrosClientes();
  if(cant==0){
    char letra;
    cout << "\t\tPara visualizar clientes debe cargar uno primero"<<endl;
    cout << "\t\tDesea cargar un cliente ahora?(s/n)";
    cin  >> letra;
    if (letra=='s'||letra=='S'){
            nuevoCliente();
            return;
    }
    else return;

    }
  Cliente *vec;
  vec=(Cliente*) malloc(cant*sizeof(Cliente));
  if(vec==NULL) return;

  copiarArchivoMemoriaCliente(vec,cant);
  ordenarVectorCliente(vec,cant);
  mostrarVectorCliente(vec,cant);// se muestra el vector ordenado
  borrarPantalla();
  free(vec);

}
void copiarArchivoMemoriaCliente(Cliente *v,long cant){
  FILE *P;
  P=fopen(FILE_CLIENTES,"rb");
  if(P==NULL){
      mensajes(1);
      return;
      }
    fread(v, sizeof(Cliente),cant,P);
  fclose(P);
  }

  void ordenarVectorCliente(Cliente *v, long cant){
  int i, j, posmin;
  Cliente aux;
  for(i=0;i<cant-1;i++){


      posmin=i;
      for(j=i+1;j<cant;j++){
       if(strcmp(v[posmin].getNombre(),v[j].getNombre())>0)
                posmin=j;

      }
      aux=v[i];
      v[i]=v[posmin];
      v[posmin]=aux;


    }
}

void mostrarVectorCliente(Cliente *v, long cant){
    int i;
    for(i=0; i<cant; i++){
        ///if(v[i].estado==true){
        v[i].mostrar();
        pausa();
        ///}
      }
}

void listarClientes(){
  long cant;
  cant=contarRegistrosClientes();
  if(cant==0){
    char letra;
    cout << "\t\tPara visualizar clientes debe cargar uno primero"<<endl;
    cout << "\t\tDesea cargar un cliente ahora?(s/n)";
    cin  >> letra;
    if (letra=='s'||letra=='S'){
            nuevoCliente();
            return;
    }
    else return;

    }
  Cliente *vec;
  ///vec=(Cliente*) malloc(cant*sizeof(Cliente));
  vec = new Cliente[cant];
  if(vec==NULL) return;

  copiarArchivoMemoriaCliente(vec,cant);
  /// ordenarVectorCliente(vec,cant);
  mostrarVectorCliente(vec,cant);/// se muestra el vector sin ordenar
  borrarPantalla();
  delete vec;
}


/*void heapsortClientes(Cliente *v, long cant){
    int A[max],j,item,temp,i,k,n;
	cout<<"Ingresa la cantidad de elementos del arreglo: ";
	cin>>n;
	for(i=1;i<=n;i++)
	cin >> A[i];
	for(k=n;k>0;k--)
	{
		for(i=1;i<=k;i++)
		{
			item=A[i];
			j=i/2;
			while(j>0 && A[j]<item)
			{
				A[i]=A[j];
				i=j;
				j=j/2;
			}
			A[i]=item;
		}
		temp=A[1];
		A[1]=A[k];
		A[k]=temp;
	}
	cout<<"El orden es:"<<endl;
	for(i=1;i<=n;i++)
	cout<<A[i] << endl;
	return 0;
}*/

/// FUNCIONES PARA COMBINAR CON HABITACIONES
bool existeCliente(const char*doc){
FILE*P;
P=fopen(FILE_CLIENTES,"rb");
if(P==NULL){

    mensajes(1);
    pausa();
    return false;
}
if(contarRegistrosClientes()==0){
    fclose(P);
 return false;
}
Cliente aux;
while(fread(&aux,sizeof(Cliente),1,P)==1){
    if (strcmp(doc,aux.getDni())==0){

        fclose(P);
        return true;
    }
     }
fclose(P);
return false;

}

/*void buscacliente(const char*doc){ /// buscar otra funcion alternativa
FILE*P;
P=fopen(FILE_CLIENTES,"rb");
if(P==NULL){
    mensajes(1);
    pausa();
    return;
}
Cliente aux;
while(fread(&aux,sizeof(Cliente),1,P)==1){
    if (strcmp(doc,aux.getDni())==0){
    /// lo que quieras
        fclose(P);
        return;
    }
     }
fclose(P);
return;
}*/
/// FIN FUNCIONES PARA COMBINAR CON HABITACIONES


/*/// FUNCIONES GLOBALES MENORES ///
bool grabarPersona(Persona aux){
FILE*P;
P=fopen(FILE_MENORES,"ab");
if(P==NULL){
    mensajes(1);
    pausa();
    return false;
}
fwrite(&aux,sizeof(Persona),1,P);
fclose(P);
return true;
}
void listadoAlfabeticoMenores(){
  long cant;
  cant=contarRegistrosMenores();
  if(cant==0){
        mensajes(2);
        pausa();
        return ;
    }
  Persona *vec;
  vec=(Persona*) malloc(cant*sizeof(Persona));
  if(vec==NULL) return;
  copiarArchivoMemoria(vec,cant);
  ordenarVectorPersona(vec,cant);
  mostrarVectorPersona(vec,cant);// se muestra el vector ordenado
  pausa();
  borrarPantalla();
  free(vec);
}
void copiarArchivoMemoria(Persona *v,long cant){
  FILE *P;
  P=fopen(FILE_MENORES,"rb");
  if(P==NULL){
      mensajes(1);
      return;
      }
    fread(v, sizeof(Persona),cant,P);
  fclose(P);
  }
  void ordenarVectorPersona(Persona *v, long cant){
  int i, j, posmin;
  Persona aux;
  for(i=0;i<cant-1;i++){
      posmin=i;
      for(j=i+1;j<cant;j++){
       if(strcmp(v[posmin].getNombre(),v[j].getNombre())>0)
                posmin=j;
      }
      aux=v[i];
      v[i]=v[posmin];
      v[posmin]=aux;
    }
}
void mostrarVectorPersona(Persona *v, long cant){
    int i;
    for(i=0; i<cant; i++){
        ///if(v[i].estado==true){
        v[i].mostrar();
        pausa();
        ///}
      }
}
int contarRegistrosMenores(){
    FILE *F;
    F=fopen(FILE_MENORES,"rb");
    if(F==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (F,0,SEEK_END);
    tam=ftell(F);
    tamanioreg=sizeof(Persona);
    cantidad=tam/tamanioreg;
    fclose(F);
    return cantidad;
}
bool existeMenor(const char*docu){
    FILE*P;
    P=fopen(FILE_CLIENTES,"rb");
    if(P==NULL){
    mensajes(1);
    pausa();
    return false;
    }
    if(contarRegistrosMenores()==0){
        fclose(P);
        return false;
    }
    Cliente aux;
    while(fread(&aux,sizeof(Cliente),1,P)==1){
    if (strcmp(docu,aux.getDni())==0){
        fclose(P);
        return true;
        }
     }
    fclose(P);
    return false;
}*/ /// FIN FUNCIONES GLOBALES MENORES ///

int listarTodos(){

char opcion;
while(true){
    borrarPantalla();
    cout << "\t\tLISTADO DE CLIENTES" << endl;
    cout << "\t\t-------------------" << endl;
    cout << "\t\t1) Listado alfabetico clientes por nombre  " << endl;
    cout << "\t\t2) Listado alfabetico clientes por apellido" << endl;
    cout << "\t\t3) Listado por antiguedad clientes " << endl;
    ///cout << "4) Listado Heapsort." << endl;
    ///cout << "5) Listado por nacionalidad ." << endl;
    ///cout << "6) PUNTO D." << endl;
    cout << "\t\t0) volver al menú clientes"<< endl;
    cout << endl << "\t\t Opción: ";
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
      case '1':
      case 'a':
      case 'A':
        listadoAlfabeticoCliente();
      break;
      case '2':
      case 'b':
      case 'B':
        cout << "\t\ten contruccion..."<< endl;
        pausa();
      break;
      case '3':
      case 'c':
      case 'C':
          listarClientes();

      break;
      case '0':
        return 0;
      break;
    }
    cout << endl;

  }

}



/// VALIDACIONES ///


bool validarFechadeNac(int _dia,int _mes, int _anio){

    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    ///FECHA ACTUAL tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year

    if(_dia<0||_mes<0||_anio<0)return false;
    if(_anio>1900+tmPtr->tm_year||_anio<1900)return false;
    int *vecdias;
    const int meses=12;
    int a;
    a=biciesto(_anio);
    if(a==1){
        vecdias=(int*)malloc(meses*sizeof(int));
        cargarDias(vecdias,1);
        if(_dia>vecdias[_mes-1]){
            free(vecdias);
            return false;
        }
    }
    else{
        vecdias=(int*)malloc(meses*sizeof(int));
        cargarDias(vecdias,0);
        if(_dia>vecdias[_mes-1]){
            free(vecdias);
            return false;
        }
    }
    if (_anio==1900+tmPtr->tm_year){
        if (_mes>tmPtr->tm_mon+1)
            return false;
        if(_mes==tmPtr->tm_mon+1){
            if(_dia>tmPtr->tm_mday){
                return false;
            }
        }
    }
    return true;
}
int biciesto(int a){

    if ((a%4==0&&a%100!=0)||a%400==0)
        return 1;
    else
        return 0;
}
void cargarDias(int *dias, int opc){
    if (opc==1){
        dias[0]=31;
        dias[1]=29;
        dias[2]=31;
        dias[3]=30;
        dias[4]=31;
        dias[5]=30;
        dias[6]=31;
        dias[7]=31;
        dias[8]=30;
        dias[9]=31;
        dias[10]=30;
        dias[11]=31;
    }
    else{
        dias[0]=31;
        dias[1]=28;
        dias[2]=31;
        dias[3]=30;
        dias[4]=31;
        dias[5]=30;
        dias[6]=31;
        dias[7]=31;
        dias[8]=30;
        dias[9]=31;
        dias[10]=30;
        dias[11]=31;
    }
}

bool validarDni(const char *doc){



if(existeCliente(doc)){

    return false;
}


return true;
}

bool validarTarjeta(char *tarjeta){
FILE*P;
P=fopen(FILE_CLIENTES,"rb");
if(P==NULL){
    mensajes(1);
    pausa();
    return false;
}
if(contarRegistrosClientes()==0){

    fclose(P);
    return true;
}
Cliente aux;
while(fread(&aux,sizeof(Cliente),1,P)==1){

    if(strcmp(tarjeta,aux.getTarjeta())==0){
            fclose(P);
            return false;
    }

}
fclose(P);
return true;


}
void modificarNombre();
void modificarApellido();
void modificarGenero();
void modificarDni();
void modificarNacionalidad();
void modificarFechaDeNac();
void modificarMail();
void modificarTelefono();
void modificarDomicilio();
void modificarTarjetaCredito();


int modificarCliente(){

char opcion;
while(true){
    borrarPantalla();
    cout << "\t\t Indique campo a modificar" << endl;
    cout << "\t\t -------------------------" << endl;
    cout << "\t\t1) Nombre" << endl;
    cout << "\t\t2) Apellido" << endl;
    cout << "\t\t3) Genero" << endl;
    cout << "\t\t4) Dni" << endl;
    cout << "\t\t5) Nacionalidad" << endl;
    cout << "\t\t6) Fecha de nacimiento "<< endl; /// incluye dia mes año
    cout << "\t\t7) Mail" << endl;
    cout << "\t\t8) Telefono" << endl;
    cout << "\t\t9) Domicilio" << endl;/// incluye todos los campos de domicilio
    cout << "\t\tT) Tarjeta de credito" << endl; /// incluye todos los campos de tarjeta
    cout << "\t\t0) Salir  "<< endl;
    cout << "\t\t   Opción: ";
    cin >> opcion;
    system("cls");
    switch(opcion){
      case '1':
        cout << "\t\tmenu en contruccion..."<< endl;
pausa();
return 0;
          break;
      case '2':
cout << "\t\tmenu en contruccion..."<< endl;
pausa();
return 0;
      break;
      case '3':
cout << "\t\tmenu en contruccion..."<< endl;
pausa();
return 0;
      break;
      case '4':
cout << "\t\tmenu en contruccion..."<< endl;
pausa();
return 0;
      break;
      case '5':
cout << "\t\tmenu en contruccion..."<< endl;
pausa();
return 0;
      break;
      case '6':
          cout << "\t\tmenu en contruccion..."<< endl;
pausa();
return 0;
        break;
      case '7':
          cout << "\t\tmenu en contruccion..."<< endl;
pausa();
return 0;

        break;
      case '8':
          cout << "\t\tmenu en contruccion..."<< endl;
pausa();
return 0;

        break;
      case '9':
cout << "\t\tmenu en contruccion..."<< endl;
pausa();
return 0;
        break;
          case 't':
          case'T':
      cout << "\t\tmenu en contruccion..."<< endl;
pausa();
return 0;
        break;
      case '0':
          return 0;
      break;
    }
    cout << endl;

  }

}

void busquedaPorDni();
void busquedaPorTarjeta();
void busquedaPorTelefono();


int listarUnCliente(){
char opcion;
while(true){
    borrarPantalla();
    cout << "\t\tBUSCAR POR ---> " << endl;
    cout << "\t\t---------------" << endl;
    cout << "\t\t1) Dni" << endl;
    cout << "\t\t2) Nro de Tarjeta." << endl;
    cout << "\t\t3) Télefono" << endl;
    cout << "\t\t0) volver "<< endl;
    cout << "\t\t   Opción: ";
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
      case '1':
    busquedaPorDni();
      break;
      case '2':
    busquedaPorTarjeta();
      break;
      case '3':
    busquedaPorTelefono();

      break;
      case '0':
        return 0;
      break;
    }
    cout << endl;

  }

}
void busquedaPorDni(){
Cliente reg;
char dni[10];
cout << "\t\tIngrese Dni de cliente: ";
fflush(stdin);
cin.getline(dni,10);
int pos=buscarCliente(dni);
if(pos==-1){
    cout << "\t\tEl cliente no encuentra registrado"<< endl;
    pausa();
    return;
}
else{

    reg.leerDeDisco(pos);
    reg.mostrar();
}

}
void busquedaPorTarjeta(){
Cliente reg;
char nroTarjeta[21];
fflush(stdin);
cout << "\t\tIngrese Nro de Tarjeta del cliente: "<< endl;
cin.getline(nroTarjeta,21);
int pos=buscarClienteTarjeta(nroTarjeta);
if(pos==-1){
    cout << "\t\tEl cliente no encuentra registrado"<< endl;
    pausa();
    return;
}
else{

    reg.leerDeDisco(pos);
    reg.mostrar();
}

}

void busquedaPorTelefono(){
Cliente reg;
char tel[30];
cout << "\t\tIngrese Telefono del cliente: "<< endl;
fflush(stdin);
cin.getline(tel,30);
int pos=buscarClienteTelefono(tel);
if(pos==-1){
    cout << "\t\tEl cliente no encuentra registrado"<< endl;
    pausa();
    return;
}
else{

    reg.leerDeDisco(pos);
    reg.mostrar();
}

}

int menuClientes(){
char op;
while(true){
    borrarPantalla();
    cout << "\t\t-----------CLIENTES----------" << endl;
    cout << "\t\t-----------------------------" << endl;
    cout << "\t\t1) NUEVO CLIENTE             " << endl; /// se carga nuevo cliente y menores de edad
    cout << "\t\t2) MODIFICAR CLIENTE.        " << endl;/// modifica el campo que le indiquemos
    cout << "\t\t3) BUSCAR CLIENTE            " << endl; /// busca y muestra un cliente segun lo que se ingrese por teclado
    cout << "\t\t4) MOSTRAR TODOS LOS CLIENTES" << endl; /// muestra todos ordenados alfabeticamente o segun se indique por teclado
    cout << "\t\t0) Salir "<< endl;
    cout << "\t\t  Opción: ";
    cin >> op;
    borrarPantalla();
    switch(op){
      case '1':
      case 'a':
      case 'A':
      nuevoCliente();
        break;
      case '2':
      case 'b':
      case 'B':
    modificarCliente();
        break;
      case '3':
      case 'c':
      case 'C':
          listarUnCliente();
        break;
      case '4':
      case 'd':
      case 'D':
          listarTodos();
        break;
      case '0':
        return 0;
      break;
    }
    cout << endl;

  }


}












#endif // MENUCLIENTES_H_INCLUDED
