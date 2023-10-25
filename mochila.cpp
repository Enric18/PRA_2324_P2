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
   int Bs = b.size();
   int N = Ps+1;
   int Mat[N][M];
   cout  << "Array size: [" << N << "] [" << M << "]\n";
     
   for(int i=0; i<N; i++){
	for(int j=0; j<M; j++){
		Mat[i][j]=-1;
	}
   }
   impMat((int *)Mat, N, M);
   
   for(int i=0; i<N; i++){
	Mat[i][0]= 0;
   }
   for(int i=0; i<M; i++){
        Mat[0][i]= 0;
   }

   impMat((int *)Mat, N, M);

   return p;
}

int main(){
   vector <int> p{1,2,3,4};
   vector <int> b{10,20,15,20};
   int max= 5;
   mochila(p,b,max);

}
