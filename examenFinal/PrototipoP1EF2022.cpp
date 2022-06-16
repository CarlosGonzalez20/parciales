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
    void menuPacientes();
    void menuExamenes();
    void menuLaboratorios();
private:
    string documentoIdentificacion, nombre, direccion, edad, tipoSangre, correo, telefono, puesto, desicion, busquedaDatos;
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

int main(){
    laboratoriosMedicos prueba;
    prueba.menuPrincipal();
}
//modBaseDatos<<std::left<<std::setw(20)<< documentoIdentificacion <<std::left<<std::setw(50)<< nombre <<std::left<<std::setw(10)<< edad <<std::left<<std::setw(20)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(20)<< direccion << std::left<<std::setw(20)<< puesto << std::left<<std::setw(15)<< sueldo << "\n";
