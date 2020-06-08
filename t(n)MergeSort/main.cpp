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

void cargar();
void mergeSort(int *,int,int);
void mergeList(int *,int,int,int,int);
void mostrar(int *,int);

int *list,n;


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

int main(){			
		n=0;
		for (n=10; n<=50; n+=5 ){		
			cargar(n);
			StartCounter();
			mergeSort(list,0,n-1);
			double tiempo = GetCounter(); 
			cout<<endl<<endl<<"Tiempo: "<< tiempo <<"ms "<<endl;
			
			mostrar(list,n);
			cout<<endl;
	}	
	getch();
	return 0;
}

void mergeSort(int *list,int first, int last){
	if(first<last){
		int middle = (first+last)/2;
		mergeSort(list,first,middle);
		mergeSort(list,middle+1,last);
		mergeList(list,first,middle,middle+1,last);
	}
}

void mergeList(int *list,int start1, int end1,int start2, int end2){
	int result[end2];
	int finalStart=start1;
	int finalEnd=end2;
	int indexC=1;

	while((start1<=end1)&&(start2<=end2)){
		if(list[start1]<list[start2]){
			result[indexC]=list[start1];
			start1 = start1+1;
		}else{
			result[indexC]=list[start2];
			start2 = start2+1;
		}
		indexC=indexC+1;
	}
	//parte de la lista que esta a la izquierda
	if(start1<=end1){
		for(int i=start1;i<=end1;i++){
			result[indexC]=list[i];
			indexC=indexC+1;
		}
	}else{
		for(int i=start2;i<=end2;i++){
			result[indexC]=list[i];
			indexC=indexC+1;
		}
	}
	
	indexC=1;
	for(int i=finalStart;i<=finalEnd;i++){
		list[i]=result[indexC];
		indexC=indexC+1;
	}
}


