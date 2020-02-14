#include <string>
#pragma once
using namespace std;

class Libro {
	private:
		string titulo, autor;
		bool vendido;
		double precio;
		int anio;

	public: 
		Libro();
		Libro(string tit, string atr, bool ven, double pre, int an);
		void setVendido() {vendido = !vendido;}
		void setAnio(int an) {anio = an;}
		void setPrecio(double pre) {precio = pre;}
		void setTitulo(string tit) {titulo = tit;}
		void setAutor(string aut) {autor = aut;}
		string getTitulo(){return titulo;}
		string getAutor(){return autor;}
		bool getVendido(){return vendido;}
		double getPrecio() {return precio;}
		int getAnio() {return anio;}

};
