//Generador de  10/1mil,100mil,1millon
//Angelo Aldo Perez Rodriguez

#include <iostream>
#include<stdlib.h>
using namespace std;


void Creacion(int n,int* arreglo);
int main(){
    int n;
    int *arreglo = nullptr;
    cout<<"Que tamanio de arreglo quieres"<<endl;
    cin>>n;
    arreglo = new int[n];
    Creacion(n,arreglo);

    delete[] arreglo;
    arreglo = nullptr;

    return 0;
}
void Creacion(int n,int* arreglo ){
    srand(time(nullptr));
    int num;
    for (int i =0;i<n;i++){
        num = 1+rand()%n;
        arreglo[i] = num;
        cout<<arreglo[i]<<" ";  
    }
    cout<<endl;
}