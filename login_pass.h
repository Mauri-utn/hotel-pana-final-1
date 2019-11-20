#ifndef LOGIN_PASS_H_INCLUDED
#define LOGIN_PASS_H_INCLUDED

#include "misFunciones.h"
int menuLogins(char);
bool recuperarPass();
bool cambiarPass();
/// se lee el archivo de empleados , en ambos casos se pide que verifique sus datos para recuperar o para cambiarla

int menuLogins(char selec){

      borrarPantalla();
        switch(selec){
      case '3':
      case 'c':
      case 'C':
          if(recuperarPass()){
              return 0;
                }
                /// dentro de la funcion se tiene que mostrar la contraseña,
                /// luego de pedirle sus datos para validar indentidad
                else{
                    cout << "LO SENTIMOS NO SE PUDO RECUPERAR CONTRASEÑA"<< endl;
                    cout << "Puede que los datos ingresados no sean validos"<< endl;
                }
        break;
      case '4':
      case 'd':
      case 'D':
          if(cambiarPass()){
            cout << "CONTRASEÑA MODIFICADA CON ÉXITO!"<< endl;
            pausa();
            return 0;
          }
          else{
            cout << "LO SIENTO NO SE PUDO MODIFICAR CONTRASEÑA"<<endl;
            cout << "Puede que los datos ingresados no sean validos"<< endl;
          }
        break;

        }
        cout << endl;
        return -1;

}

bool recuperarPass(){
cout << "PARA RECUPERAR LA CONTRASEÑA LE VAMOS A PEDIR QUE VALIDE SUS DATOS."<< endl;
pausa();
cout << "EN CONSTRUCCION"<< endl;
pausa();
return true;

}

bool cambiarPass(){
cout << "PARA CAMBIAR LA CONTRASEÑA LE VAMOS A PEDIR QUE VALIDE SUS DATOS."<< endl;
pausa();
cout << "EN CONSTRUCCION"<< endl;
pausa();
return true;

}



#endif // LOGIN_PASS_H_INCLUDED
