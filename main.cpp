#include <iostream>
#include <array>
#include "usuario.hpp"
#include "libro.hpp"
using namespace std;

array<Usuario, 10> usuarios;
//Usuario usuarios[0];
int usuarioN = 0;
array<Libro, 10> libros;
int librosN = 0;
Usuario userAct;
bool ingreso = false;

void agregarUsuario(Usuario user) {
	Usuario copia[usuarioN + 1];
	for (int i = 0; i < usuarioN; i++) {
		copia[i] = usuarios[i];
	}
	copia[usuarioN + 1] = user;
}

void admin() {
	string user = "n.duron";
	string contra = "sybase";
	string nom = "Nicolle Duron";
	int edad = 20;
	double dinero = 1000;
	agregarUsuario(Usuario(user, contra, nom, edad, dinero));
	usuarios[usuarioN++] = Usuario(user, contra, nom, edad, dinero);
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
				ingreso = true;
				userAct = usuario1;
				}
			}
			if(!entro && encontro) {
				cout << "\aContraseña Invalida!!\a" << endl;
				ingreso = false;
				break;
			}
		}
	if(!encontro) {
		cout << "\aUsuario no existe!!\a" << endl;
		ingreso = false;
		userAct = Usuario();
		userAct.setNombre("nulooo?");//No se sinceramente
	}
}

void crearUser() {
	string name, nombre, contra;
	int edad;
	double dinero;
	cout << "Ingrese su nombre de Usuario: ";
	cin >> name;
	cout << "Ingrese su contraseña: ";
	cin >> contra;
	cout << "Ingrese su nombre: ";
	cin >> nombre;
	cout << "Ingrese su edad: ";
	cin >> edad;
	cout << "Cuanto dinero tiene: ";
	cin >> dinero;
	usuarios[usuarioN++] = Usuario(name, contra, nombre, edad ,dinero);
}

int menuUser() {
	int op;
	cout << "1. Comprar libro\n2.Buscar por autor\n3.Buscar por título\n";
	cout << "4.Agregar dinero a mi cuenta\5.Restablecer contraseña\n6.Borrar cuenta: ";
	cin >> op;
	if (op < 1 || op > 6) {
		cout << "\aOpcion no valida!!";
		return menuUser();
	}
	return op;
}

void listarLibros() {
	int i = 0;
	for(Libro libro : libros) {
		if(libro.getTitulo() != "") {
			cout << i  << libro.getTitulo();
		}
		i++;
	}
}

int menuAdmin() {
	int op; 
	cout << "1. Agregar libro\n2. Modificar libro\n3. Eliminar libro\n";
	cout <<	"4. Borrar registro de libros: ";
	cin >> op;
	if(op > 4 || op < 1) {
		return menuAdmin();
	}
	return op;
}

void modificar(int x) {
	
}

void crearLibro() {
        string titulo, autor;
        bool vendido = false;
	int anio;
        double precio;
        cout << "Ingrese el nombre del Libro: ";
        cin >> titulo;
        cout << "Ingrese el nombre del autor: ";
        cin >> autor;
        cout << "Ingrese el año de publicacion: ";
        cin >> anio;
        cout << "Ingrese el precio: ";
        cin >> precio;
        libros[librosN++] = Libro(titulo, autor, false, anio, precio);
}

int main() {
	admin();
	int opMain;
	int subOp;
	do {
		opMain = menuP();
		if (!ingreso) {
			switch (opMain) {
				case 1:
					logIn();
				break;
				case 2:
					if (usuarioN < 9) {
					crearUser();
					cout << "Usuario creado exitosamente!\a" <<endl;
					} else {
						cout << "No es posible crear el usuario!\a";
					}
				break;
			}
		}
		if (userAct.getUser() != "nulooo?") {
			if(userAct.getUser() == "n.duron" && userAct.getContra() == "sybase") {
				subOp = menuAdmin();
				switch (subOp) {
					case 1:
						crearLibro();
					break;
					case 2:
						listarLibros();
												
					break;
				}
			} else {
				subOp = menuUser();
				switch (subOp) {
					case 1:
						
					break;
					case 2:
					break;
					case 3:
					break;
					case 4:
					break;
					case 5:
					break;
					case 6: 
					break;
				}
			}
		}
	} while (opMain);
	return 0;
}
