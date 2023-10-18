#include <iostream>
#include <vector>
using namespace std;

template<typename T>
T BusquedaBinaria(T x, vector<T>& v, int ini, int fin){
  if(ini >fin){
	return -1;
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

template<typename T>
T BusquedaBinaria_INV(T x, vector<T>& v, int ini, int fin){
  if(ini >fin){
        return -1;
  }
  int m = (ini + fin) / 2;
  if(v[m] == x){
        return m;
  }
  else if(v[m] > x){
        return BusquedaBinaria(x, v, m+1, fin);
  }
  else{
        return BusquedaBinaria(x, v, ini, m-1);
  }
}

template<typename T>
int Partition(vector<T>& v, int ini, int fin){
   T x = v[fin];
   int i = ini;
   for(int j= ini; j< fin; j++){
	if(v[j] <= x){
	   T temp = v[i];
	   v[i] = v[j];
	   v[j] = temp;
	   i++;
	}
   }
   T temp2 = v[i];
   v[i] = v[fin];
   v[fin] = temp2;
   return i;
}

template<typename T>
T QuickSort(vector<T>& v, int ini, int fin){
   if(ini<fin){
        int p = Partition(v, ini, fin);
        QuickSort(v, ini, p-1);
        QuickSort(v, p+1, fin);
   }
}


template<typename T>
void printArr(vector<T>& v, int fin){
   cout << "[";
   for(int i=0; i<fin; i++){
	cout << v[i] << ", ";
   }
   cout << "] " << endl;
}
