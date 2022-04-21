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
		string id,name,phone,address, numCur, numSede, numFacultad;
	public:
		void menuPrincipal();
		void catalogos();
		void sedes();
		void facultades();
		void cursos();
		void reportes();
		void insertSede();
		void displaySede();
		void modifySede();
		void searchSede();
		void deletSede();
        void insertFacultad();
		void displayFacultad();
		void modifyFacultad();
		void searchFacultad();
		void deletFacultad();
        void insertCursos();
		void displayCursos();
		void modifyCursos();
		void searchCursos();
		void deletCursos();
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
    int choice;
	char x;
	do
    {
	system("cls");
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t| BIENVENIDOS AL MENU CATALOGOS |"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t 1. Sedes"<<endl;
	cout<<"\t\t\t 2. Facultades"<<endl;
	cout<<"\t\t\t 3. Cursos"<<endl;
	cout<<"\t\t\t 4. Regresar al MENU PRINCIPAL"<<endl;
	cout<<"\n\t\t\tIngresa tu Opcion: "; cin>>choice;
    switch(choice)
    {
    case 1:
    	sedes();
		break;
	case 2:
		facultades();
		break;
	case 3:
		cursos();
		break;
    case 4:
        return menuPrincipal();
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }
    while(choice!= 4);
}

void colegio::sedes(){
    int choice;
	char x;
	do
    {
	system("cls");
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t|   BIENVENIDOS AL MENU SEDE   |"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t 1. Registrar"<<endl;
	cout<<"\t\t\t 2. Mostrar"<<endl;
	cout<<"\t\t\t 3. Modificar"<<endl;
	cout<<"\t\t\t 4. Buscar"<<endl;
	cout<<"\t\t\t 5. Eliminar"<<endl;
	cout<<"\t\t\t 6. Regresar al MENU CATALOGOS"<<endl;
	cout<<"\n\t\t\tIngresa tu Opcion: "; cin>>choice;
    switch(choice)
    {
    case 1:
    	insertSede();
		break;
	case 2:
		displaySede();
		break;
	case 3:
		modifySede();
		break;
    case 4:
        searchSede();
        break;
    case 5:
        deletSede();
        break;
    case 6:
        return catalogos();
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }
    while(choice!= 6);
}

void colegio::insertSede(){
    system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Sede -------------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Numero Sede        : ";
	cin>>numSede;
	cout<<"\t\t\tIngresa Nombre Sede        : ";
	cin>>name;
	cout<<"\t\t\tIngresa Telefono Sede      : ";
	cin>>phone;
	cout<<"\t\t\tIngresa Direccion Sede     : ";
	cin>>address;
	file.open("sede.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< numSede <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< address << "\n";
	file.close();
}

void colegio::displaySede(){
    system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Sedes -------------------------"<<endl;
	file.open("sede.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> numSede >> name >> phone >> address;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Numero Sede: "<<numSede<<endl;
			cout<<"\t\t\t Nombre Sede: "<<name<<endl;
			cout<<"\t\t\t Telefono Sede: "<<phone<<endl;
			cout<<"\t\t\t Direccion Sede: "<<address<<endl;
			file >> numSede >> name >> phone >> address;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}

void colegio::modifySede(){
    system("cls");
	fstream file,file1;
	string busquedaSede;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Sede-------------------------"<<endl;
	file.open("sede.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese NUMERO de la Sede que quiere modificar: ";
		cin>>busquedaSede;
		file1.open("modSede.txt",ios::app | ios::out);
		file >> numSede >> name >> phone >> address;
		while(!file.eof())
		{
			if(busquedaSede!=numSede)
			{
			 file1<<std::left<<std::setw(15)<< numSede <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< address << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Numero Sede: ";
				cin>>numSede;
				cout<<"\t\t\tIngrese Nombre Sede: ";
				cin>>name;
				cout<<"\t\t\tIngrese Telefono Sede: ";
				cin>>phone;
				cout<<"\t\t\tIngrese Direccion Sede: ";
				cin>>address;
				file1<<std::left<<std::setw(15)<< numSede <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< address << "\n";
				found++;
			}
			file >> numSede >> name >> phone >> address;

		}
		file1.close();
		file.close();
		remove("sede.txt");
		rename("modSede.txt","sede.txt");
	}
}

void colegio::searchSede(){
    system("cls");
	fstream file;
	int found=0;
	file.open("sede.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Sede buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string busquedaSede;
		cout<<"\n-------------------------Datos de la Sede buscada------------------------"<<endl;
		cout<<"\nIngrese NUMERO de la Sede que quiere buscar: ";
		cin>>busquedaSede;
		file >> numSede >> name >> phone >> address;
		while(!file.eof())
		{
			if(busquedaSede==numSede)
			{
				cout<<"\n\n\t\t\t Numero de Sede: "<<numSede<<endl;
				cout<<"\t\t\t Nombre Sede: "<<name<<endl;
				cout<<"\t\t\t Telefono Sede: "<<phone<<endl;
				cout<<"\t\t\t Direccion Sede: "<<address<<endl;
				found++;
			}
			file >> numSede >> name >> phone >> address;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Sede no encontrada...";
		}
		file.close();
	}
}

void colegio::deletSede(){
    system("cls");
	fstream file,file1;
	string busquedaSede;
	int found=0;
	cout<<"\n-------------------------Detalles de Sede a Borrar-------------------------"<<endl;
	file.open("sede.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el NUMERO de la Sede que quiere borrar: ";
		cin>>busquedaSede;
		file1.open("modSede.txt",ios::app | ios::out);
		file >> numSede >> name >> phone >> address;
		while(!file.eof())
		{
			if(busquedaSede!= numSede)
			{
				file1<<std::left<<std::setw(15)<< numSede <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< address << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> numSede >> name >> phone >> address;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Numero de Sede no encontrado...";
		}
		file1.close();
		file.close();
		remove("sede.txt");
		rename("modSede.txt","sede.txt");
	}
}

void colegio::facultades(){
    int choice;
	char x;
	do
    {
	system("cls");
	cout<<"\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t| BIENVENIDOS AL MENU FACULTADES |"<<endl;
	cout<<"\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t 1. Registrar"<<endl;
	cout<<"\t\t\t 2. Mostrar"<<endl;
	cout<<"\t\t\t 3. Modificar"<<endl;
	cout<<"\t\t\t 4. Buscar"<<endl;
	cout<<"\t\t\t 5. Eliminar"<<endl;
	cout<<"\t\t\t 6. Regresar al MENU CATALOGOS"<<endl;
	cout<<"\n\t\t\tIngresa tu Opcion: "; cin>>choice;
    switch(choice)
    {
    case 1:
    	insertFacultad();
		break;
	case 2:
		displayFacultad();
		break;
	case 3:
		modifyFacultad();
		break;
    case 4:
        searchFacultad();
        break;
    case 5:
        deletFacultad();
        break;
    case 6:
        return catalogos();
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }
    while(choice!= 6);
}

void

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

