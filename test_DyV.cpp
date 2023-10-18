#include <iostream>
#include <vector>
#include "DyV.h"
using namespace std;


int main(){
   vector<int> v{2, 3, 4, 6, 7, 9};
   int sol = BusquedaBinaria(4, v, 0, v.size());
   if(sol == -1){
	cout << "No se encuentra en el array" << endl;
   }
   else{
	cout << "Está en la posición: " << sol << endl;
   }   



}
