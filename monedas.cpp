#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void impMat(int *T, int tam1, int tam2){
	for(int i=0;i<tam1;i++){
                for(int j=0;j<tam2;j++){
                       cout << (T+i*tam2)[j] << ", ";
                }
		cout << "\n";

        }
	cout << endl;
}

vector<int> Cambio(int *V, int M){
	int g = sizeof(V)/sizeof(V[0])+ 2;
	int T[g][M];
	cout  << "Array size:  " << g << "//" << M << "\n";
	for(int i=0;i<g;i++){
		for(int j=0;j<M;j++){
			T[i][j]=-1;
		}

	}	
	T[0][0] = 0;

     	impMat((int *)T, g, M);

	for(int j=0;j< M; j++){
		if((j>=V[0]) && (T[0][j-V[0]] != -1)){
			T[0][j]=1+T[0][j-V[0]];
		}	
	}
	impMat((int *)T, g, M);

	for(int i=1;i<g;i++){
		T[i][0]= 0;
		for(int j=1; j<M; j++){
			if((j < V[i]) || (T[i][j-V[i]] == -1)){
				T[i][j]=T[i-1][j];
			}
			else if(T[i-1][j]!= -1){
				T[i][j]=min(T[i-1][j],1+T[i][j-V[i]]);
			}
			else{
				T[i][j]= 1+ T[i][j-V[i]];
			}

		}
	}
	impMat((int *)T, g, M);

	vector<int>  Sol(g, 0);
	int i = g-1;
	int j = M-1;
	while(i != 0 && j != 0){
		if (i == 0 || T[i][j] != T[i-1][j]){
			Sol[i] = Sol[i]+1;
			j = j -V[i];
		}
		else{
			i = i-1;
		}
	}
	return Sol;
}

int main(){
	int V[] = {1,4,6,8};
	int g = sizeof(V)/sizeof(V[0]);
	vector<int> solu = Cambio(V,9);
	for (int i = 0; i < g ; i++) {
        	cout << "Valor moneda: " << V[i] << "||  Numero de monedas: "  << solu[i] << "\n";
	}
	cout << endl;
}

