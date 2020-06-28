//ANGELO ALDO PEREZ RODIRGUEZ
//REFERENCIAS: https://www.geeksforgeeks.org/quick-sort/
#include<iostream>
#include <cstdlib>
#include <cmath>
#include<stdio.h>
using namespace std;
int swaps=0;

void swap(int *a,int *b){
    int t = *a;  
    *a = *b;  
    *b = t; 
}

int particion(int* arr, int inicio, int final){
    int pivote = arr[final];
    int i = (inicio-1);

    for(int j= inicio;j<=final-1;j++){
        if(arr[j] < pivote){
            i++;
            swap(&arr[i],&arr[j]);
            swaps++;
        }
    }
    swap(&arr[i+1],&arr[final]);
    swaps++;
    return (i+1);
}

void quicksort(int* arr, int inicio,int final){

    if(inicio < final){

        int pi = particion(arr,inicio,final);
        quicksort(arr,inicio,pi-1);
        quicksort(arr,pi+1,final);
    }
}


int main(){

    int vagones[51];
    int cont;
    int ncasos,nvagones,nvagon;
    cin>>ncasos;
    

    for(int i = 0;i < ncasos ; i++){
        cin>>nvagones;
        cont = 0;
        for (int j = 0; j <nvagones ; j++){
            cin>>nvagon;
            vagones[cont++] = nvagon;
        }
        quicksort(vagones,0,cont-1);
        /*for(int k = 0; k < cont ; k++)
            cout<<vagones[k]<<" ";*/
        cout<<"numero de swaps: "<<swaps<<endl;
        swaps = 0;
    }

    
    return 0;
}