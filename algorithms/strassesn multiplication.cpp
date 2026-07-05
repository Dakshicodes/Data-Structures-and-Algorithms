#include<iostream>//strassen's algorithm works for matrix  multiplication of the order of power of 2.
#include<vector>
using namespace std;
using matrix=vector<vector<int>> ; //declaring matrix as a datatype which is actually vector of multiple vectors.
//helper function.
matrix add(const matrix &A,const matrix &B){
    int n=int(A.size());
    matrix C(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    return C;
}
matrix subtract(const matrix &A,const matrix &B){
    int n=int(A.size());
    matrix C(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i][j]=A[i][j]-B[i][j];
        }
    }
    return C;
}
//REAL SHIT
matrix Strassen(const matrix&A,const matrix&B){
    int n=int(A.size());
    matrix C(n,vector<int>(n));
    if(n==1){
        C[0][0]=A[0][0]*B[0][0];
        return C;
    }
    int k=n/2;
    matrix A11(k,vector<int>(k)),A12(k,vector<int>(k)),A21(k,vector<int>(k)),
    A22(k,vector<int>(k)),B11(k,vector<int>(k)),B12(k,vector<int>(k)),B21(k,vector<int>(k)),B22(k,vector<int>(k));

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+k];
            A21[i][j]=A[i+k][j];
            A22[i][j]=A[i+k][j+k];
            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+k];
            B21[i][j]=B[i+k][j];
            B22[i][j]=B[i+k][j+k];
        }
    }

    matrix P=Strassen(add(A11,A22),add(B11,B22));
    matrix Q=Strassen(add(A21,A22),B11);
    matrix R=Strassen(A11,subtract(B12,B22));
    matrix S=Strassen(A22,subtract(B21,B11));
    matrix T=Strassen(add(A11,A12),B22);
    matrix U=Strassen(subtract(A21,A11),add(B11,B12));
    matrix V=Strassen(subtract(A12,A22),add(B21,B22));

    matrix C11=add(subtract(add(P,S),T),V);
    matrix C12=add(R,T);
    matrix C21=add(Q,S);
    matrix C22=add(subtract(add(P,R),Q),U);
    
    for (int i = 0; i < k; i++){     //order of filling
        for (int j = 0; j < k; j++){//c11->c12->c21->c22
        C[i][j]=C11[i][j];            //11->12->21->22 order of position filling in different iterations.
        C[i][j+k]=C12[i][j];
        C[i+k][j]=C21[i][j];
        C[i+k][j+k]=C22[i][j];
    }
    }
    return C;
}
int main(){
    matrix A={};
    matrix B={};
    matrix C=Strassen(A,B);
    cout<<"the resultant matrix after multiplication is"<<endl;
    for(auto &row: C){
        for(int val:row){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}