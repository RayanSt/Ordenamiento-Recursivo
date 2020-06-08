#include <iostream>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
//Brayan Parra 20171020156
//Esta funcion para el tiempo la saque de internet :v
//https://gist.github.com/csmoore/d3af490666378272d6ff
using namespace std;

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter(){
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";
    PCFreq = double(li.QuadPart)/100000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter(){
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

void cargar();
void residuo(int *,int,int,int);
void mostrar(int *,int);

int *list,n,Bits;

void cargar(int n, int Bits){
	list = new int [n];
	int num = pow(2,Bits);
	for(int i=0;i<n;i++){
		list[i]=rand()%num;
	}

}

unsigned bits (int x, int k, int j){
 return (x>>k)&~(~0<<j);
}

void residuo(int *list,int izq,int der, int b){
	int i, j,aux;
	if (der>izq && b>0){
		i= izq; j=der;
		while(j!=i){
			while(!bits(list[i],b,1) && i<j)i++;
			while(bits(list[j],b,1) && j>i)j--;
			aux = list[i];
			list[i] = list[j];
			list[j] = aux;
        }
        if (!bits(list[i],b,1)) j++;
        residuo(list, izq, j-1, b-1);
        residuo(list, j, der, b-1);
    }
}

void mostrar(int *list, int n){
	cout<<endl<<endl<<"Arreglo Ordenado "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<list[i]<<" ";
	cout<<endl;
}

int main(){	
	
	cout<<"Ingrese la cantidad de bits: "<<endl;
	cout<<"--> 4"<<endl;
	cout<<"--> 8"<<endl;
	cout<<"--> 16"<<endl;
	cin>>Bits;
	n=0;
		for (n=10; n<=50; n+=5 ){	
		cargar(n,Bits);
		StartCounter();
		residuo(list,0,n,Bits);
		double tiempo = GetCounter(); 
		cout<<endl<<endl<<"Tiempo: "<< tiempo <<"ms "<<endl;
		mostrar(list,n);
		cout<<endl;
		delete list;
}

	getch();
	return 0;
}





