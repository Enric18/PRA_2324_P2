#include <iostream>
#include <vector>
#include "DyV.h"
using namespace std;


int main(){
   vector<int> v{2, 3, 4, 6, 7, 9};
   vector<int> v2{9, 8, 7, 4, 2, 1};
   
   cout << "Búsqueda binaria: " << endl;
   printArr(v, v.size());   
   int sol = BusquedaBinaria(4, v, 0, v.size());
   if(sol == -1){
	cout << "No se encuentra en el array" << endl;
   }
   else{
	cout << "Está en la posición: " << sol << endl;
   } 
   
   cout << "Búsqueda binaria invertida: " << endl;
   printArr(v2, v2.size());
   int sol2 = BusquedaBinaria_INV(4, v2, 0, v2.size());
   if(sol2 == -1){
        cout << "No se encuentra en el array" << endl;
   }
   else{
        cout << "Está en la posición: " << sol2 << endl;
   }

   cout << "QuickSort: " << endl;
   printArr(v2, v2.size());
   QuickSort(v2, 0, v2.size());
   printArr(v2, v2.size());
 



}
