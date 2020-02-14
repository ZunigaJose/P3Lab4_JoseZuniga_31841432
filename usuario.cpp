#include "usuario.hpp"
#include <string>
using namespace std;

Usuario::Usuario(string usr, string ctr, string nom, int ed, double din){
	user = usr;
	contra = ctr;
	nombre = nom;
	edad = ed;
	dinero = din;
}
