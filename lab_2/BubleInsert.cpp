// ALumno: Angelo Aldo Perez Rodriguez
#include <iostream>
#include<stdlib.h>
using namespace std;

void Aleatorio(int& n,int* arreglo,int* arreglo2 ){
    srand(time(nullptr));
    int num;
    for (int i =0;i<n;i++){
        num = 1+rand()%n;
        arreglo[i] = num;
        arreglo2[i] = num;
        
    }
    cout<<endl;
    
}
void Ascendente(int& n, int* arreglo,int* arreglo2){
    for(int i=0;i<n;i++){
        arreglo[i] = i+1;
        arreglo2[i] = i+1;
        
        
    }
    cout<<endl;
}

void Descendente(int& n, int* arreglo,int* arreglo2){
    for(int i=0;i<n;i++){
        arreglo[i] = n-i; 
        arreglo2[i] = n-i; 
        
    }
    cout<<endl;
}
void Creacion(int& n, int* arreglo,int* arreglo2,int& condicion){
    if (condicion == 1){
        Ascendente(n,arreglo,arreglo2);
    }
    else if (condicion == 2){
        Descendente(n,arreglo,arreglo2);
    }
    else if(condicion == 3){
        Aleatorio(n,arreglo,arreglo2);
    }
    else{
        cout<<"Condicion no valida"<<endl;
    }

}

void Bubble(int& n, int* arreglo,unsigned long long & comparaciones, unsigned long long & asignaciones, int& asignaciones_memeoria){
	int temporal;
	
	bool swapped;
    int temp;
    for(int i=0;i<n-1;i++,asignaciones++,comparaciones++){

        for(int j=0;j<n-i-1;j++,asignaciones++,comparaciones++){


            if(arreglo[j] > arreglo[j+1]){

                comparaciones++;

                temp = arreglo[j];
                arreglo[j]=arreglo[j+1];
                arreglo[j+1]=temp;
                swapped = true;
                
                asignaciones+=4;
            }
        }
        if (swapped == false){ 
            ++comparaciones;
            break;
        }

    }
}
void insertionSort(int& n, int* arreglo2,unsigned long long & comparaciones2, unsigned long long & asignaciones2, int& asignaciones_memeoria2)  
{  
    int temp;
    for(long i = 1; i < n; asignaciones2++,comparaciones2++,i++)
    {
        temp = arreglo2[i];
        asignaciones2++;
        long j;
        for(j = i-1; j >= 0 && arreglo2[j] > temp; asignaciones2++,comparaciones2++,j--)
        {
            arreglo2[j+1] = arreglo2[j];
            asignaciones2++;
        }
        arreglo2[j+1] = temp;
        asignaciones2++;
    } 
}  
void print(int& n, int* arreglo){
    for(int i=0;i<n;i++){
        cout<<arreglo[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    int condicion;
    int *arreglo = nullptr;
    int *arreglo2 = nullptr;
    unsigned long long comparaciones=0;
    unsigned long long asignaciones=0;
    int asignaciones_memoria=0;
    unsigned long long comparaciones2=0;
    unsigned long long asignaciones2=0;
    int asignaciones_memoria2=0;
    unsigned t1,t2,t3,t4;
    cout<<"Tipo de arreglo 1. ascendente , 2. descendente, 3. aleatorio"<<endl;
    cin>>condicion;
    cout<<"Que tamanio de arreglo quieres"<<endl;
    cin>>n;
    arreglo = new int[n];
    arreglo2 = new int[n];
    Creacion(n,arreglo,arreglo2,condicion);
    t1 = clock();
    Bubble(n,arreglo,comparaciones,asignaciones,asignaciones_memoria);
    t2 = clock();
    t3 = clock();
    insertionSort(n,arreglo2,comparaciones2,asignaciones2,asignaciones_memoria2);
    t4 = clock();
    
    cout<<endl<<endl;
    cout<<"Coste bubble: "<<comparaciones*2+asignaciones*8+(asignaciones_memoria*50+10*asignaciones_memoria)<<endl;
    cout<<"Coste Insert: "<<comparaciones2*2+asignaciones2*8+(asignaciones_memoria2*50+10*asignaciones_memoria2)<<endl;
    double time = (double(t2-t1)/CLOCKS_PER_SEC);
    double time2 = (double(t4-t3)/CLOCKS_PER_SEC);
    cout << "Tiempo real Bubble: " << time*1000 << endl;
    cout << "Tiempo real Insert: " << time2*1000 << endl;
    delete[] arreglo;
    delete[] arreglo2;
    arreglo = nullptr;
    arreglo2 = nullptr;

    return 0;
}