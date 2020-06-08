#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
using namespace std;
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter(){
    LARGE_INTEGER li;
    CounterStart = 0;
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

int *list,n;

void cargar();
int divide(int *,int,int);
void quicksort(int *,int,int,int,int);
void mostrar(int *,int);

void cargar(int n){

	srand(time(NULL));
	list = new int [n];	
	for(int i=0;i<n;i++){
		list[i]=rand()%50;
	}

}

void mostrar(int *list, int n){
	cout<<endl<<endl<<"Arreglo Ordenado "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<list[i]<<" ";
	cout<<endl;
}

int divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;
 
    pivot = array[start];
    left = start;
    right = end;
 

    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }
 
        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }
 
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
 
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;
 
    return right;
}
 
void quicksort(int *array, int start, int end)
{
    int pivot;
    if (start < end) {
        pivot = divide(array, start, end);
        quicksort(array, start, pivot - 1);
        quicksort(array, pivot + 1, end);
    }
}



int main()
{   
 n=0;
		for (n=10; n<=50; n+=5 ){		
			cargar(n);
			StartCounter();
			cout << endl << endl;
 			quicksort(list, 0, n - 1);
			double tiempo = GetCounter(); 
			cout<<endl<<endl<<"Tiempo: "<< tiempo <<"ms "<<endl;
			mostrar(list,n);
			cout<<endl;
	}
 	getch();
    return 0;
}
