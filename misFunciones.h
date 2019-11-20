#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED
void ponerVecEnCero(int*,int);
void ponerMatEnCero(float [20][3]);
void borrarPantalla();
void pausa();
void fechaHora();
bool cadenaVacia(const char*);

void borrarPantalla()
{
#ifdef __unix__
    system("clear");
#elif defined(_WIN32) || defined(WIN32)
    system("cls");
#endif
}

void pausa()
{
#ifdef __unix__
    cin.get();
    cin.get();
#elif defined(_WIN32) || defined(WIN32)
    system("pause >nul");
#endif

}
void ponerVecEnCero(int*v,int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        v[i]=0;
    }

};

void ponerMatEnCero(float mat[20][3])
{

    int i,x;
    for(i=0; i<20; i++)
    {
        for (x=0; x<3; x++)
        {
            mat[i][x]=0;
        }

    }

}

void fecha()
{


    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    ///FECHA ACTUAL tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year
    cout << tmPtr->tm_mday <<"/"<<tmPtr->tm_mon+1<<"/"<<1900+tmPtr->tm_year<<endl;
    ///cout << tmPtr->tm_hour<<":"<<tmPtr->tm_min<<":"<<tmPtr->tm_sec<<endl;///HORA

}

void hora()
{


    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    ///FECHA ACTUAL tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year
    ///cout << tmPtr->tm_mday <<"/"<<tmPtr->tm_mon+1<<"/"<<1900+tmPtr->tm_year<<endl;///FECHA
    cout << tmPtr->tm_hour<<":"<<tmPtr->tm_min<<":"<<tmPtr->tm_sec<<endl;

}


void mensajes(int opcion)
{

    switch(opcion)
    {
    case 1:
        cout << "\t\tERROR AL ABRIR ARCHIVO"<< endl;
        pausa();
        break;
    case 2:
        cout << "\t\tOPCIÓN INVALIDA"<< endl;
        pausa();
        break;
    case 3:
        cout << "\t\tEL CAMPO NO PUEDE ESTAR VACÍO"<< endl;
        pausa();
        break;

    }

}

bool cadenaVacia(const char * cadena)
{

    if (strlen(cadena)==0)
    {
        return true;
    }
    else
        return false;

}

void limpiarBuffer()
{

    fflush(stdin);
}


bool salir(){

    while(1){
        char selec[5];
        cout << "\t\tSalir(si/no)" << endl;
        limpiarBuffer();
        cin.getline(selec,5);
        if(strcmp(selec,"si")==0)
            return true;
        if(strcmp(selec,"SI")==0)
            return true;
        if(strcmp(selec,"no")==0)
            return false;
        if(strcmp(selec,"NO")==0)
            return false;
        mensajes(1);

    }
}




#endif // MISFUNCIONES_H_INCLUDED
