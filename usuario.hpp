#pragma once
#include <string>

using namespace std;

class Usuario {
	private:
		string user, contra, nombre;
		int edad;
		double dinero;
	public:
		Usuario(){};
		Usuario(string, string, string, int, double);
		void setContra(string ctr) {contra = ctr;};
		void agregarDinero(double x) {dinero += x;};
		string getUser() {return user;};
		string getContra() {return contra;};
		string getNombre() {return nombre;};
		void setNombre(string nom) { nombre = nom;}
		int getEdad() {return edad;};
		double getDinero() {return dinero;};
		void compra(double x) {dinero -= x;};
};
