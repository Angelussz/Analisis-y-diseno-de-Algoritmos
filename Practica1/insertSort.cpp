//2.- Copiar codigos en el lenguaje de su preferencia:

//Angelo Aldo Perez Rodriguez

//Algoritmo Insert: https://www.geeksforgeeks.org/insertion-sort/
//Algoritmo guia contador milisegundos : https://gist.github.com/mcleary/b0bf4fa88830ff7c882d

#include <bits/stdc++.h> 

using namespace std;
////////
class Contador
{
private:
    chrono::time_point<chrono::system_clock> inicio;
    chrono::time_point<chrono::system_clock> final;
    bool contar = false;
public:
    Contador(){
    }
    ~Contador(){
    }
    void start(){
        inicio = chrono::system_clock::now();
        contar = true;
    }
    void stop(){
        final = chrono::system_clock::now();
        contar = false;
    }
    double elapseMilliseconds(){
        chrono::time_point<chrono::system_clock> fincont;
        if(contar){
            fincont = chrono::system_clock::now();
        }
        else
        {
            fincont = final;
        }
        return chrono::duration_cast<chrono::milliseconds>(fincont-inicio).count();
    }
    double elapsedSeconds(){
        return elapseMilliseconds()/1000.0;
    }

};
///////
void insertionSort(int arr[], int n)  
{  
    int i, key, j;
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  

void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
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

int main()  
{ 
    Contador timer;
    int * arreglo = nullptr;
    int n;
    cout<<"Que tamanio de arreglo quieres"<<endl;
    cin>>n;
    arreglo = new int[n];
    Creacion(n,arreglo);
    cout<<"2 hours later"<<endl;
    timer.start();
    insertionSort(arreglo,n);
    timer.stop();
    printArray(arreglo,n);
    cout<<"tiempo transcurrido en insert-sort es: "<<timer.elapseMilliseconds()<<endl;
    delete[] arreglo;
    arreglo = nullptr;

    return 0;
}  



