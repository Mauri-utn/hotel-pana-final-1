#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED



class Personaa{
	 protected:
		char dni[20];
		char nombres[50];
		char apellidos[50];
		Fecha fecha_nac;
		Direccion domicilio;
		char telefono[20];
	 public:
		void Cargar();
		void Mostrar();
		char * getNdoc(){return dni;}
		char * getNombre(){return nombres;}
		char * getApellido(){return apellidos;}
		Fecha getFecha(){return fecha_nac;}
		Direccion getDomicilio(){return domicilio;}
		char * getTelefono(){return telefono;}
		void setNdoc(char *n){strcpy(dni,n);}
		void setNombre(char *n){strcpy(nombres,n);}
		void setApellido(char *a){strcpy(apellidos,a);}
		void setFecha_nac(Fecha f){fecha_nac=f;}
		void setDomicilio(Direccion d){domicilio=d;}
		void setTelefono(char *tel){strcpy(telefono,tel);}
	 };


class Empleados:public Personaa{
    private:
        int Id;
        char Area[50];
        char Genero[2];
        char Turno[10];
        char Sueldo[10];
        char Cuil[15];
        char ActivoInactivo[10];
      public:
        void Cargar();
        void Mostrar();
        char * getArea(){return Area;}
        int getId(){return Id;}
        char * getGenero(){return Genero;}
        char * getTurno(){return Turno;}
        char * getSueldo(){return Sueldo;}
        char * getCuil(){return Cuil;}
        bool getActivoInactivo(){return ActivoInactivo;}
        void setArea(char *a){strcpy(Area,a);}
        void setId(int i){Id=i;}
        void setGenero(char *g){strcpy(Genero,g);}
        void setTurno(char *t){strcpy(Turno,t);}
        void setSueldo(char *s){strcpy(Sueldo,s);}
        void setCuil(char *c){strcpy(Cuil,c);}
        void setActivoInactivo(char *a){strcpy(ActivoInactivo,a);}
        bool EscribirEnDisco();
        bool LeerDeDisco(int);
};



///////////////CLASE FECHA
//Puede utilizarse para fechas desde el 01/01/1900


#endif // CLASS_H_INCLUDED
