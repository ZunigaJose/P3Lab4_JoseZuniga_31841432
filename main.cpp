#include <iostream>
#include <array>
#include "usuario.hpp"
#include "libro.hpp"
using namespace std;

array<Usuario, 10> usuarios;
int usuarioN = 0;
array<Libro, 10> libros;
int librosN = 0;
Usuario userAct;

void admin() {
	string user = "n.duron";
	string contra = "sybase";
	string nom = "Nicolle Duron";
	int edad = 20;
	double dinero = 1000;
	usuarios[usuarioN] = Usuario(user, contra, nom, edad, dinero);
}

int menuP() {
	int op;
	cout << "0. Salir" << endl;
	cout << "1. Ingresar" << endl;
	cout << "2. Registrarse: ";
	cin >> op;
	if (op < 0 || op > 2) {
		return menuP();
	}
	return op;
}

void logIn() {
	string user, contra;
	cout << "Ingrese su usuario: ";
	cin >> user;
	bool entro = false;
	bool encontro = false;
	for(Usuario usuario1: usuarios) {
		if(usuario1.getUser() == user) {
			encontro = true;
			cout << "Ingrese su contraseña: ";
			cin >> contra;
			if(usuario1.getContra() == contra) {
				cout << "Ingreso Exitoso!!" << endl << endl;
				entro = true;
				userAct = usuario1;
				}
			}
			if(!entro) {
				cout << "\aContraseña Invalida!!\a" << endl;
			}
		}
	if(!encontro) {
		cout << "\aUsuario no existe!!\a" << endl;
	}
}

int main() {
	admin();
	int opMain;
	do {
		opMain = menuP();
		switch (opMain) {
			case 1:
				logIn();
			break; 
		}

	} while (!opMain);
	return 0;
}
