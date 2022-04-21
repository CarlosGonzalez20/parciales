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
    colegio alumno;
    alumno.menuPrincipal();
}
