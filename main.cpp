#include <iostream>
#include <array>
#include "usuario.hpp"
#include "libro.hpp"
using namespace std;

void admin() {
	
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

int main() {

	return 0;
}
