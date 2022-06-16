#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <math.h>

using namespace std;

class laboratoriosMedicos{
public:
    void menuPrincipal();
    void menuEmpleados();
        void registrarEmpleados();
        void modificarEmpleados();
        void eliminarEmpleados();
        void mostrarDatosEmpleados();
    void menuPacientes();
        void registrarPacientes();
        void modificarPacientes();
        void eliminarPacientes();
        void mostrarDatosPacientes();
    void menuExamenes();
    void menuLaboratorios();
private:
    string documentoIdentificacion, nombre, direccion, edad, tipoSangre, correo, telefono, puesto, sueldo, desicion, busquedaDatos;
};

void laboratoriosMedicos::menuPrincipal(){
    system ("cls");
    int menu;
    cout << "\n\t\t\tBienvenido al programa de ==LABORATORIOS MEDICOS==";
    cout << "\n\n\t\tElija el numero del menu al que quiera ingresar\n"<< endl << "\t\t[1] Empleados\n" << "\t\t[2] Pacientes\n" << "\t\t[3] Examenes medicos\n" << "\t\t[4] Laboratorios\n" << "\t\t[5] Salir del programa\n";cout<<"\n\t\t";cin >> menu;
    switch(menu){
    case 1:
        menuEmpleados();
        break;
    case 2:
        menuPacientes();
        break;
    case 3:
        menuExamenes();
        break;
    case 4:
        menuLaboratorios();
        break;
    case 5:
        cout << "\n\t\t�Quiere salir del programa? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            cout<<"\n\n\t\tGRACIAS POR USAR EL RPOGRAMA DEL EXAMEN FINAL :)";
            cout<<"\n\n\t\t";system("pause");
            return exit (1);
        }
        else {
            return menuPrincipal();
        break;
        }
    }
}

void laboratoriosMedicos::menuEmpleados(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU EMPLEADO--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar Empleados\n" << "\t\t[2] Modificar Empleados\n" <<  "\t\t[3] Eliminar Empleado\n" << "\t\t[4] Mostrar Datos Empleados\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarEmpleados();
        break;
    case 2:
        modificarEmpleados();
        break;
    case 3:
        eliminarEmpleados();
        break;
    case 4:
        mostrarDatosEmpleados();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU PRINCIPAL--" << endl;
        cout<<"\t";system ("pause");
        return menuPrincipal();
        break;
    }
}

void laboratoriosMedicos::registrarEmpleados(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al menu --REGISTRAR EMPLEADOS--\n" << endl;
    cout << "\n\t Quires salir al --MENU EMPLEADO--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuEmpleados();
    }
    else {
        cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
        cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
        cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
        cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
        cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
        cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
        cout << "\t\tIngrese el puesto de la persona a registrar: "; cin>>puesto;
        cout<<  "\t\tIngrese el sueldo de la persona a registrar: "; cin>> sueldo;
        cout << "\n\t--Registro completado--\n" << endl;
        baseDatos.open("empleados.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(20)<< documentoIdentificacion <<std::left<<std::setw(50)<< nombre <<std::left<<std::setw(10)<< edad <<std::left<<std::setw(20)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(20)<< direccion << std::left<<std::setw(20)<< puesto << std::left<<std::setw(15)<< sueldo << "\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU EMPLEADOS--";
    cout<<"\n\t";system("pause");
    return menuEmpleados();
}

void laboratoriosMedicos::modificarEmpleados(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR EMPLEADOS--" << endl;
    cout << "\n\t Quires salir al --MENU EMPLEADO--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuEmpleados();
    }
    else{
        baseDatos.open("empleados.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos){
            cout << "\n\t\tNo se encontro el archivo" << endl;
            baseDatos.close();
            cout <<"\n\n\t\t\tRegresando al --MENU EMPLEADOS--";
            cout<<"\n\t";system("pause");
            return menuEmpleados();
        }
        else {
            cout << "\n\t\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalEmpleados.dat",ios::app|ios::out|ios::binary);
            baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>puesto>>sueldo;
            while (!baseDatos.eof()){
                if (busquedaDatos!=documentoIdentificacion){
                    modBaseDatos<<std::left<<std::setw(20)<< documentoIdentificacion <<std::left<<std::setw(50)<< nombre <<std::left<<std::setw(10)<< edad <<std::left<<std::setw(20)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(20)<< direccion << std::left<<std::setw(20)<< puesto << std::left<<std::setw(15)<< sueldo << "\n";
                }
                else {
                    cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
                    cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
                    cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
                    cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
                    cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
                    cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
                    cout << "\t\tIngrese el puesto de la persona a registrar: "; cin>>puesto;
                    cout << "\t\tIngresa el sueldo de la persona a registrar "; cin>> sueldo;
                    modBaseDatos<<std::left<<std::setw(20)<< documentoIdentificacion <<std::left<<std::setw(50)<< nombre <<std::left<<std::setw(10)<< edad <<std::left<<std::setw(20)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(20)<< direccion << std::left<<std::setw(20)<< puesto << std::left<<std::setw(15)<< sueldo << "\n";
                }
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>puesto>>sueldo;

            }
            modBaseDatos.close();
            baseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "empleados.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalEmpleados.dat","empleados.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\tRegresando al --MENU EMPLEADOS--";
        cout<<"\n\t";system("pause");
        return menuEmpleados();
    }
}

void laboratoriosMedicos::eliminarEmpleados(){
    system("cls");
	fstream baseDatos,modBaseDatos;
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR EMPLEADOS--" << endl;
	cout << "\n\t Quires salir al --MENU EMPLEADO--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuEmpleados();
    }
    else {
        baseDatos.open("empleados.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\t\tNo hay informacion...\a";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalEmpleados.dat", ios::app | ios::out | ios::binary);
            baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>puesto>>sueldo;

            while(!baseDatos.eof())
            {
                if(busquedaDatos!=documentoIdentificacion)
                {
                    modBaseDatos<<std::left<<std::setw(20)<< documentoIdentificacion <<std::left<<std::setw(50)<< nombre <<std::left<<std::setw(10)<< edad <<std::left<<std::setw(20)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(20)<< direccion << std::left<<std::setw(20)<< puesto << std::left<<std::setw(15)<< sueldo << "\n";
                }
                else
                {
                    found++;
                    cout << "\n\t\t\tBorrado de informacion exitoso\a";
                }
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>puesto>>sueldo;
            }
            if(found==0)
            {
                cout<<"\n\t\t\t Empleado no encontrado...\a";
            }
            baseDatos.close();
            modBaseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "empleados.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalEmpleados.dat","empleados.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\t\tRegresando al --MENU EMPLEADOS--";
        cout<<"\n\t";system("pause");
        return menuEmpleados();
    }
}

void laboratoriosMedicos::mostrarDatosEmpleados(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR DATOS EMPLEADOS--";
    cout << "\n\t Quires salir al --MENU EMPLEADO--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuEmpleados();
    }
    else {
        cout << "\n\n\t\t Quiere buscar a una persona en especifico? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            int datos=0;
            baseDatos.open("empleados.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos)
            {
                cout<<"\n\t\tError";
                cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
                baseDatos.close();
            }
            else
            {
                cout << "\n\t\t\tEntrando en el menu --BUSCAR--"<<endl;
                cout << "\n\t\tIngrese el numero del Documento de Identificacion de la persona a buscar: "; cin >> busquedaDatos;
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>puesto>>sueldo;
                while(!baseDatos.eof()){
                    if(busquedaDatos==documentoIdentificacion){
                        cout<<"\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                        cout<<"\n\t\tNombre: " << nombre;
                        cout<<"\n\t\tEdad: "<< edad;
                        cout<<"\n\t\tCorreo Electronico: "<< correo;
                        cout<<"\n\t\tTelefono: "<< telefono;
                        cout<<"\n\t\tDireccion: "<< direccion;
                        cout<<"\n\t\tPuesto o cargo: "<< puesto;
                        cout<<"\n\t\tSueldo: "<< sueldo;
                        datos++;
                        if (baseDatos.is_open()){
                            baseDatos.close();
                            cout<<"\n\n\t\tArchivo cerrado";}
                        cout<<"\n\n\t\t\tRegresando al --MENU EMPLEADO--";
                        cout<<"\n\t";system("pause");
                        return menuEmpleados();
                    }
                    baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>puesto>>sueldo;
                }
                if(datos==0)
                {
                    cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                    cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR DATOS--";
                    cout<<"\n\t";system("pause");
                    return mostrarDatosEmpleados();
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                }
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
        }
        else {
            fstream baseDatos;
            int total=0;
            cout<<"\n\t\t\tEntrando al --MENU MOSTRAR DATOS EMPLEADOS"<<endl;
            baseDatos.open("empleados.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos){
                cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
                cout <<"\n\n\t\t\tRegresando al --MENU EMPLEADOS--";
                cout<<"\n\t";system("pause");
                return menuEmpleados();
            }
            else
            {
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>puesto>>sueldo;
                while(!baseDatos.eof())
                {
                    total++;
                    cout<<"\n\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                    cout<<"\n\t\tNombre: " << nombre;
                    cout<<"\n\t\tEdad: "<< edad;
                    cout<<"\n\t\tCorreo Electronico: "<< correo;
                    cout<<"\n\t\tTelefono: "<< telefono;
                    cout<<"\n\t\tDireccion: "<< direccion;
                    cout<<"\n\t\tPuesto o cargo: "<< puesto;
                    cout<<"\n\t\tSueldo: "<< sueldo;
                    baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>puesto>>sueldo;
                    //if (baseDatos.is_open()){
                      //  baseDatos.close();
                        //cout<<"\n\n\t\tArchivo cerrado";}
                }
                if(total==0){
                    cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                    //if (baseDatos.is_open()){
                      //  baseDatos.close();
                        //cout<<"\n\n\t\tArchivo cerrado";}
                }
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
                cout <<"\n\n\t\tRegresando al --MENU EMPLEADOS--";
                cout<<"\n\t";system("pause");
                return menuEmpleados();
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
}

void laboratoriosMedicos::menuPacientes(){
    system("cls");
    int menu;
    cout << "\n\t\tBienvenido al --MENU PACIENTES--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar Paciente\n" << "\t\t[2] Modificar Pacientes\n" <<  "\t\t[3] Eliminar Paciente\n" << "\t\t[4] Mostrar Datos Pacientes\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarPacientes();
        break;
    case 2:
        modificarPacientes();
        break;
    case 3:
        eliminarPacientes();
        break;
    case 4:
        mostrarDatosPacientes();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU PRINCIPAL--" << endl;
        cout<<"\t";system ("pause");
        return menuPrincipal();
        break;
    }
}

void laboratoriosMedicos::registrarPacientes(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al menu --REGISTRAR PACIENTES--\n" << endl;
    cout << "\n\t Quires salir al --MENU PACIENTES--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPacientes();
    }
    else {
        cout << "\n\t\tIngrese el numero de documento de identificacion del paciente: "; cin >> documentoIdentificacion;
        cout << "\t\tIngrese el nombre de la paciente a registrar: "; cin >> nombre;
        cout << "\t\tIngrese la edad del paciente a registrar: "; cin >> edad;
        cout << "\t\tIngrese el numero de telefono del paciente a registrar: (si no brinda informacion coloque ?) "; cin >> telefono;
        cout << "\t\tIngrese la direccion del paciente a registrar: (si no brinda informacion coloque ?) "; cin >> direccion;
        cout<<  "\t\tIngrese el tipo de sangre del paciente a registrar: "; cin>> tipoSangre;
        cout << "\n\t--Registro completado--\n" << endl;
        baseDatos.open("pacientes.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(20)<< documentoIdentificacion <<std::left<<std::setw(50)<< nombre <<std::left<<std::setw(10)<< edad <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(20)<< direccion << std::left<<std::setw(10)<< tipoSangre << "\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU PACIENTES--";
    cout<<"\n\t";system("pause");
    return menuPacientes();
}

void laboratoriosMedicos::modificarPacientes(){
    system("cls");
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR PACIENTES--" << endl;
    cout << "\n\t Quires salir al --MENU PACIENTES--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPacientes();
    }
    else{
        baseDatos.open("pacientes.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos){
            cout << "\n\t\tNo se encontro el archivo" << endl;
            baseDatos.close();
            cout <<"\n\n\t\t\tRegresando al --MENU PACIENTES--";
            cout<<"\n\t";system("pause");
            return menuPacientes();
        }
        else {
            cout << "\n\t\t\tIngrese el numero de Documento de Identificacion del paciente que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalPacientes.dat",ios::app|ios::out|ios::binary);
            baseDatos>>documentoIdentificacion>>nombre>>edad>>telefono>>direccion>>tipoSangre;
            while (!baseDatos.eof()){
                if (busquedaDatos!=documentoIdentificacion){
                    modBaseDatos<<std::left<<std::setw(20)<< documentoIdentificacion <<std::left<<std::setw(50)<< nombre <<std::left<<std::setw(10)<< edad <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(20)<< direccion << std::left<<std::setw(10)<< tipoSangre << "\n";
                }
                else {
                    cout << "\n\t\tIngrese el numero de documento de identificacion del paciente: "; cin >> documentoIdentificacion;
                    cout << "\t\tIngrese el nombre de la paciente a registrar: "; cin >> nombre;
                    cout << "\t\tIngrese la edad del paciente a registrar: "; cin >> edad;
                    cout << "\t\tIngrese el numero de telefono del paciente a registrar: (si no brinda informacion coloque ?) "; cin >> telefono;
                    cout << "\t\tIngrese la direccion del paciente a registrar: (si no brinda informacion coloque ?) "; cin >> direccion;
                    cout<<  "\t\tIngrese el tipo de sangre del paciente a registrar: "; cin>> tipoSangre;
                    modBaseDatos<<std::left<<std::setw(20)<< documentoIdentificacion <<std::left<<std::setw(50)<< nombre <<std::left<<std::setw(10)<< edad <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(20)<< direccion << std::left<<std::setw(10)<< tipoSangre << "\n";
                }
                baseDatos>>documentoIdentificacion>>nombre>>edad>>telefono>>direccion>>tipoSangre;
            }
            modBaseDatos.close();
            baseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "pacientes.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalPacientes.dat","pacientes.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\tRegresando al --MENU PACIENTES--";
        cout<<"\n\t";system("pause");
        return menuPacientes();
    }
}

void laboratoriosMedicos::eliminarPacientes(){
    system("cls");
	fstream baseDatos,modBaseDatos;
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR PACIENTES--" << endl;
	cout << "\n\t Quires salir al --MENU PACIENTES--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPacientes();
    }
    else {
        baseDatos.open("pacientes.dat",ios::app|ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\t\tNo hay informacion...\a";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\tIngrese el numero de Documento de Identificacion del paciente que busca: "; cin >> busquedaDatos;
            modBaseDatos.open("temporalPacientes.dat", ios::app | ios::out | ios::binary);
            baseDatos>>documentoIdentificacion>>nombre>>edad>>telefono>>direccion>>tipoSangre;

            while(!baseDatos.eof())
            {
                if(busquedaDatos!=documentoIdentificacion)
                {
                    modBaseDatos<<std::left<<std::setw(20)<< documentoIdentificacion <<std::left<<std::setw(50)<< nombre <<std::left<<std::setw(10)<< edad <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(20)<< direccion << std::left<<std::setw(10)<< tipoSangre << "\n";
                }
                else
                {
                    found++;
                    cout << "\n\t\t\tBorrado de informacion exitoso\a";
                }
                baseDatos>>documentoIdentificacion>>nombre>>edad>>telefono>>direccion>>tipoSangre;
            }
            if(found==0)
            {
                cout<<"\n\t\t\t Paciente no encontrado...\a";
            }
            baseDatos.close();
            modBaseDatos.close();
        if (baseDatos.is_open())
            baseDatos.close();
        if (modBaseDatos.is_open())
            modBaseDatos.close();

        if( remove( "pacientes.dat" ) != 0 )
            perror( "\n\t\tError deleting file" );
        else
            puts( "\n\t\tFile successfully deleted" );

        if (rename("temporalPacientes.dat","pacientes.dat") != 0)
            perror("\n\t\tError renaming file");
        else
            cout << "\n\t\tFile renamed successfully";
        }
        cout <<"\n\n\t\t\tRegresando al --MENU PACIENTES--";
        cout<<"\n\t";system("pause");
        return menuPacientes();
    }
}

void laboratoriosMedicos::mostrarDatosPacientes(){
    system("cls");
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR DATOS PACIENTES--";
    cout << "\n\t Quires salir al --MENU PACIENTES--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuPacientes();
    }
    else {
        cout << "\n\n\t\t Quiere buscar a un paciente en especifico? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            int datos=0;
            baseDatos.open("pacientes.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos)
            {
                cout<<"\n\t\tError";
                cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
                baseDatos.close();
            }
            else
            {
                cout << "\n\t\t\tEntrando en el menu --BUSCAR--"<<endl;
                cout << "\n\t\tIngrese el numero del Documento de Identificacion del paciente a buscar: "; cin >> busquedaDatos;
                baseDatos>>documentoIdentificacion>>nombre>>edad>>telefono>>direccion>>tipoSangre;
                while(!baseDatos.eof()){
                    if(busquedaDatos==documentoIdentificacion){
                        cout<<"\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                        cout<<"\n\t\tNombre: " << nombre;
                        cout<<"\n\t\tEdad: "<< edad;
                        cout<<"\n\t\tTelefono: "<< telefono;
                        cout<<"\n\t\tDireccion: "<< direccion;
                        cout<<"\n\t\tTipo de Sangre: "<< tipoSangre;
                        datos++;
                        if (baseDatos.is_open()){
                            baseDatos.close();
                            cout<<"\n\n\t\tArchivo cerrado";}
                        cout<<"\n\n\t\t\tRegresando al --MENU PACIENTES--";
                        cout<<"\n\t";system("pause");
                        return menuPacientes();
                    }
                    baseDatos>>documentoIdentificacion>>nombre>>edad>>telefono>>direccion>>tipoSangre;
                }
                if(datos==0)
                {
                    cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                    cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR DATOS PACIENTES--";
                    cout<<"\n\t";system("pause");
                    return mostrarDatosPacientes();
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                }
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
        }
        else {
            fstream baseDatos;
            int total=0;
            cout<<"\n\t\t\tEntrando al --MENU MOSTRAR DATOS PACIENTES"<<endl;
            baseDatos.open("pacientes.dat",ios::app|ios::in|ios::binary);
            if(!baseDatos){
                cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
                cout <<"\n\n\t\t\tRegresando al --MENU PACIENTES--";
                cout<<"\n\t";system("pause");
                return menuPacientes();
            }
            else
            {
                baseDatos>>documentoIdentificacion>>nombre>>edad>>telefono>>direccion>>tipoSangre;
                while(!baseDatos.eof())
                {
                    total++;
                    cout<<"\n\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                    cout<<"\n\t\tNombre: " << nombre;
                    cout<<"\n\t\tEdad: "<< edad;
                    cout<<"\n\t\tTelefono: "<< telefono;
                    cout<<"\n\t\tDireccion: "<< direccion;
                    cout<<"\n\t\tTipo de Sangre: "<< tipoSangre;
                    baseDatos>>documentoIdentificacion>>nombre>>edad>>telefono>>direccion>>tipoSangre;
                    //if (baseDatos.is_open()){
                      //  baseDatos.close();
                        //cout<<"\n\n\t\tArchivo cerrado";}
                }
                if(total==0){
                    cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                    //if (baseDatos.is_open()){
                      //  baseDatos.close();
                        //cout<<"\n\n\t\tArchivo cerrado";}
                }
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
                cout <<"\n\n\t\tRegresando al --MENU PACIENTES--";
                cout<<"\n\t";system("pause");
                return menuPacientes();
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
}

void laboratoriosMedicos::menuExamenes(){
    cout<<"hola";
}

void laboratoriosMedicos::menuLaboratorios(){
    cout<<"hola";
}

int main(){
    laboratoriosMedicos prueba;
    prueba.menuPrincipal();
}
