#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
using namespace std;
//Brayan Parra 20171020156
//Esta funcion para el tiempo la saque de internet :v
//https://gist.github.com/csmoore/d3af490666378272d6ff
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

int max(int *,int);
void orden1(int *,int,int);
void bases(int *,int);
void mostrar(int *,int);
int cargar(int *);

int *list,n;


void cargar(int n){
	srand(time(NULL));
	list = new int [n];
		for(int i=0;i<n;i++){
			list[i]=rand()%99999;
		}
}

int max(int *list,int n){
	int max = list[0];
	for (int i=1;i<n;i++)
		if(list[i]>max)
			max=list[i];
	return max;
}
void ordenamiento1(int *list,int n, int exp){
	int salida[n];
	int i, cuenta[10] = {0};
	for(i=0;i<n;i++)
		cuenta[(list[i]/exp)%10 ]++;
		
	for(i=1;i<10;i++)
		cuenta[i]+=cuenta[i-1];
		
	for(i=n-1;i>=0;i--){
		salida[cuenta[(list[i]/exp)%10]-1]=list[i];
		cuenta[(list[i]/exp)%10]--;
	}
	for (i=0;i<n;i++)
		list[i]=salida[i];
}

void bases(int *list,int n){
	int m=max(list,n);
	for(int exp=1;m/exp>0;exp*=10)
		ordenamiento1(list,n,exp);
}

void mostrar(int *list, int n){
	cout<<endl<<endl<<"Arreglo Ordenado "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<list[i]<<" ";
	cout<<endl;
}

int main(){	
	
		n=0;
		for (n=10; n<=50; n+=5 ){
		cargar(n);
		StartCounter();
		bases(list,n);
		double tiempo = GetCounter(); 
		cout<<endl<<endl<<"Tiempo: "<< tiempo <<"ms "<<endl;
		mostrar(list,n);
		cout<<endl;
		delete list;
	}	
	getch();
	return 0;
}




