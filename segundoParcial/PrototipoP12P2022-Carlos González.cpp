#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

class colegio
{
	private:
		string id,name,phone,college,address;
	public:
		void menuPrincipal();
		void catalogos();
		void sedes();
		void facultades();
		void cursos();
		void reportes();
		void insert();
		void display();
		void modify();
		void search();
		void delet();
};

void colegio::menuPrincipal(){
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t| BIENVENIDOS AL MENU PRINCIPAL |"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t 1. Catalogos"<<endl;
	cout<<"\t\t\t 2. Reportes"<<endl;
	cout<<"\t\t\t 3. Salir del programa"<<endl;
	cout<<"\n\t\t\tIngresa tu Opcion: "; cin>>choice;
    switch(choice)
    {
    case 1:
    	catalogos();
		break;
	case 2:
		reportes();
		break;
	case 3:
		exit(1);
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }
    while(choice!= 3);
}

void colegio::catalogos(){
    cout <<"hola";
}

void colegio::sedes(){
    cout <<"hola";
}

void colegio::facultades(){
    cout <<"hola";
}

void colegio::cursos(){
    cout <<"hola";
}

void colegio::reportes(){
    cout <<"hola";
}

int main(){
    system ("cls");
    string usuario, contrasena, config1, config2;
    fstream usuariosContrasenas;
    usuariosContrasenas.open("seguridad.dat",ios::app|ios::in|ios::binary);
    if(!usuariosContrasenas){
        cout<<"\n\t\tError";
        cout<<"\n\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
    }
    else{
        cout << "\n\t\tIngrese su usuario: "; cin >> usuario;
        cout << "\n\t\tIngrese su contrasena: "; cin >> contrasena;
        usuariosContrasenas>>config1>>config2;
            if (usuario=="admin" && contrasena =="123"){
                fstream bienvenida;
                string line, desicion;
                bienvenida.open("bienvenidos.txt");
                if(bienvenida.is_open()){
                    cout << "\n";
                    while( getline(bienvenida, line)){
                        cout << "\t\t"<<line << endl;
                    }
                    bienvenida.close();
                    }
                cout << "\n\t\tPresione i para ingresar al --PROGRAMA-- : ";cin>>desicion;
                if (desicion=="i"){
                colegio alumno;
                alumno.menuPrincipal();
            }
            else{
                cout << "\n\t\t\tPermiso denegado\a";
                exit(0);
            }
        }
    }
}

