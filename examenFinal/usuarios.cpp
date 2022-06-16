#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main(){
    string usu, contra, numU;
    fstream usuario;
    cout<<"ingrese el numero de usuario a asignar: ";cin>>numU;
    cout<<"ingrese el nombre de usuario: "; cin>>usu;
    cout<<"ingrese la contraseña: "; cin>>contra;
    usuario.open("seguridad.dat",ios::app | ios::out | ios::binary);
    usuario<<std::left<<std::setw(5)<< numU <<std::left<<std::setw(50)<< usu <<std::left<<std::setw(50)<< contra << "\n";
    usuario.close();
}
