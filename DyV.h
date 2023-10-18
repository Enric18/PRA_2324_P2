#include <iostream>
#include <vector>
using namespace std;

template<typename T>

T BusquedaBinaria(T x, vector<T>& v, int ini, int fin){
  if(ini >fin){
	return "No se encuentra en el array";
  } 
  int m = (ini + fin) / 2;
  if(v[m] == x){
	return m;
  }
  else if(v[m] > x){
	return BusquedaBinaria(x, v, ini, m-1);
  }
  else{
	return BusquedaBinaria(x, v, m+1, fin);

  }  


}	
