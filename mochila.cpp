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

vector <int> mochila(vector <int> &p, vector <int> &b, int M){
   int Ps = p.size();
   int N1 = Ps+1;
   int M1= M+1;
   int Mat[N1][M1];
   cout  << "Array size: [" << N1 << "] [" << M1 << "]\n";
   

   for(int i=0; i<N1; i++){
	for(int j=0; j<M1; j++){
		Mat[i][j]=-1;
	}
   }
   impMat((int *)Mat, N1, M1);
   
   for(int i=0; i<N1; i++){
	Mat[i][0]= 0;
   }
   for(int i=0; i<M1; i++){
        Mat[0][i]= 0;
   }

   impMat((int *)Mat, N1, M1);
   
   for(int i=1; i<N1; i++){
	for(int C=1; C<M1; C++){
	   int ci = p[i-1];
	   int g;
	   if(ci > C){
	      g = Mat[i-1][C];
	   }
	   else{
	      g =  max(Mat[i-1][C],Mat[i-1][C-ci]+b[i-1]);
	   }
	   Mat[i][C]= g;
	}
   }

   impMat((int *)Mat, N1, M1);
   cout << "Beneficio máximo = " << Mat[N1-1][M1-1] << endl;

   vector<int> Sol(N1-1, 0);
   int i = N1 -1;
   int j = M;
   while(i != 0 && j != 0){
	if (i == 0 || Mat[i][j] != Mat[i-1][j]){
		Sol[i-1] = 1;
		j = j -p[i-1];
	}
        i--;
   }
   return Sol;

}

int main(){
   vector <int> p{1,3,2,4};
   vector <int> b{10,20,15,20};
   int max= 5;
   vector<int> sol = mochila(p,b,max);
   for (int i = 0; i < p.size() ; i++) {
       	cout << "Peso objeto: " << p[i] << " || Valor objeto: " << b[i] << " || Numero de objetos: "  << sol[i] << "\n";
   }
}
