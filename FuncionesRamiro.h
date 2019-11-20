#ifndef FUNCIONESRAMIRO_H_INCLUDED
#define FUNCIONESRAMIRO_H_INCLUDED

#include "class.h"



///FUNCIONES GENERALES

///CARGAR EMPLEADOS
int buscarId(Empleados);
///LISTAR EMPLEADOS
///MODIFICAREMPLEADOS


const char *FILE_EMPLEADOS    = "empleados.dat";

///FUNCIONES GENERALES
bool Empleados::EscribirEnDisco(){
    FILE *p;
    p = fopen(FILE_EMPLEADOS,"ab");
    if(p==NULL){return false;}
    fwrite(this,sizeof (Empleados),1,p);
    fclose(p);
}
bool Empleados::LeerDeDisco(int posicion){
    FILE *p;
    p = fopen(FILE_EMPLEADOS,"rb");
    if(p==NULL){ return false;}
    fseek(p,sizeof *this*posicion,0);
    bool leyo=fread(this,sizeof *this,1,p);
    fclose(p);
    return leyo;
}
int comprobarCadNumericas(char *cadena){
    int i=0,tam;
    tam=strlen(cadena);
    if(tam==0){cout << "no aprete enter señor" << endl; system("pause"); return -1;}
    while(i<tam){
        if(isdigit(cadena[i])==0){
            cout << "esta cadena contiene algun caracter no numerico" << endl;
            system("pause");
            return -1;
        }
        i++;
    }
}
int comprobarNombresApellidos(char *cadena){
    int i=0,tam,onlySpace=0;
    tam=strlen(cadena);
    if(tam==0){ cout << "No aprete enter señor" << endl; system("pause"); return -1;}
    while(i<tam){
        if(isdigit(cadena[i])!=0){
            cout << "La cadena contiene un Numero" << endl;
            system("pause");
            cout << endl;
            return -1;
        }
        if(isspace(cadena[i])!=0){
            onlySpace++;
            if(tam==onlySpace){
                cout << "La cadena ingresada contiene solo Espacios" << endl;
                system("pause");
                cout << endl;
                return -1;
            }
        }
        if(isalnum(cadena[i])==0 && cadena[i]!=' '){
            cout << "La cadena ingresada contiene caracteres especiales " << endl;
            system("pause");
            cout << endl;
            return -1;
        }
        i++;
    }
    return 1;
}
int comprobarGenero(char *Genero){
    if(strcmpi(Genero,"f")!=0 && strcmpi(Genero,"m")!=0){
        cout << "Ha ingresado una letra incorrecta" << endl;
        system("pause");
        cout << endl;
        return -1;
    }
}
int comprobarTurno(char *Turno){
    if(strcmpi(Turno,"mañana")!=0 && strcmpi(Turno,"tarde")!=0 && strcmpi(Turno,"noche")!=0){
        cout << "Turno incorrecto" << endl;
        system("pause");
        cout << endl;
        return -1;
    }
}
int comprobarSueldo(char *Sueldo){
    int i=0,tam;
    tam = strlen(Sueldo);
    while(i<tam){
        if(isdigit(Sueldo[i])==0){
            cout << "Solo se admiten numeros" << endl;
            system("pause");
            cout << endl;
            return -1;
        }
        i++;
    }
}

int comprobarCuil(char *Cuil,char *Dni){
    if(strstr(Cuil,Dni)==NULL){
        cout << "El cuil no coincide con el DNI" << endl;
        system("pause");
        cout << endl;
        return -1;
    }
}

///CARGAR EMPLEADOS
int buscarId(Empleados reg){
    int aux;
    FILE *p;
    p = fopen(FILE_EMPLEADOS,"ab+");
    fseek(p,0,2);
    aux = (ftell(p)/sizeof reg)+1;
    fclose(p);
    return aux;
}


bool buscarDNI(char *dni){
    int pos=0;
    Empleados buscar;
    while(buscar.LeerDeDisco(pos++)){
        if(strcmp(dni,buscar.getNdoc())==0){
            cout << "numero de documento invalido" << endl;
            system("pause");
            return false;
        }
    }
    return true;
}


///LISTAR EMPLEADOS




///MODIFICAREMPLEADOS



#endif // FUNCIONESRAMIRO_H_INCLUDED
