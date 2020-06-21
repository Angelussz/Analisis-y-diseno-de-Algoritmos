//ANGELO ALDO PEREZ RODRIGUEZ
#include <iostream>
#include<stdlib.h>
#include <fstream>
using namespace std;
//QuickSort por libreria
//Se necesita esta funcion compare para el qsort()
/*int aleinterno(int n){
    return 1+rand()%n;
}*/
void Aleatorio(int& n,int* arreglo){
    //srand(time(nullptr));
    //int num=0;
    for (int i =0;i<n;i++){
        //int num = (rand()%n)+1;
        int num = 1+(rand()%n);
        arreglo[i] = num;    
    }
    cout<<endl;   
}
void print(int& n, int* arreglo){
    for(int i=0;i<n;i++){
        cout<<arreglo[i]<<" ";
    }
    cout<<endl;
}

//MAXIMO
unsigned long maximo(int & n,int* arr){
    unsigned long cont = 0;
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i] > max){
            max = arr[i];
            cont++;
        }
    }
    return cont;
}

int main(){
    srand(time(nullptr));
    int n;
    int comp;
    int *arreglo = nullptr;
    
    ofstream datosmax,datosquick;
    datosmax.open("lectura.txt");
    //datosquick.open("lectura2.txt");
    cout<<"Que tamanio de arreglo quieres"<<endl;
    cin>>n;
    arreglo = new int[n];
    
    for (int i = 0; i < 200; i++)
    {
        
        Aleatorio(n,arreglo);
        
        datosmax<<maximo(n,arreglo)<<endl;
        
    }
    datosmax.close();
    
    delete[] arreglo;
    
    return 0;
}