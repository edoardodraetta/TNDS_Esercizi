#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Vettore.h"

using namespace std;

// funzioni di tipo template, quindi implementazione nel header

// davanti alle funzioni metto template <typename T>
// Vettore diventa Vettore <T>

// READ/WRITE
template <typename T> Vettore<T> Read(const char* filename, int ndata){
	
	Vettore<T> V(ndata);
	ifstream fin(filename);

	if(!fin){
      cout << "Error: " << filename << " could not be read." <<endl; 
      exit(11);
    } else {
        for (unsigned int i = 0; i<ndata; i++){

        	T val = 0;
            in >> val;
            V.SetComponent(i,val);

            // closes automatically
            if (fin.eof() ){
            	cout << "Reached end of file, exiting" << endl;
            	exit(11);
            }
        }
    }
	return V;
}

// print to terminal
template <typename T> void Print(const Vettore <T> &V){

    cout << endl;
    if (V.GetN() == 0 ){ 
        cout << "Vector is null vector." << endl;

    } else {
        cout << "|";
        for (int i = 0; i < V.GetN(); i++){
        cout << V.GetComponent(i) << "|";  
    } 
    cout << endl;

    }
} 

// print to file
template <typename T> void PrintToFile(const char * filename, const Vettore<T> &V){

	if (!fout){ 
		cerr << "Non posso creare il file " << filename << endl;
		return;
	}
	ofstream fout(filename); 
    for (int i = 0; i < V.GetN(); i++){
        fout << V.GetComponent(i) << endl;
    }

    fout.close();
    return;
}

// input elements from terminal
template <typename T> Vettore <T> InputVector(){

    int M = 0 ;
    cout << endl;
    cout << "Please enter desired vector dimension: ";

	cin >> M;

    Vettore <T> V(M);

    if (M ==0) {
        cout <<  "Vector is null vector." << endl;
        return V;

    } else {

        cout << "Please enter " << V.GetN() << " floating point numbers." << endl;

        for (int i = 0; i < V.GetN(); i++){

        	double elem = 0; 

            cout << "Element number " << i+1 << ": ";
            cin >> elem;

            V.SetComponent(i, elem);

            if ( i != (V.GetN()-1) ){
                cout << "Current array : ";
                Print(V);
            }
        }
        cout << "Final array : ";
        Print(V);
        return V;
    }
    cout << endl;
}				

// MANIPULATION

// passing by ref means variable can be modified
template <typename T>  T CalculateMean(const Vettore <T> & V){

	T accumulo = 0;
	if (V.GetN() == 0) return accumulo;

	for (int i = 0; i < V.GetN(); i++){ 

		accumulo = static_cast<T>(i)/static_cast<T>(i+1)*accumulo +
				1./static_cast<T>(i+1) * V.GetComponent(i); 
	}

    return accumulo;
}

template <typename T> T CalculateVariance(const Vettore <T> & V){
	
	T result = 0;

	if (V.GetN() == 0) return result;

	T old_average, average = 0;

	for (int i = 0; i < V.GetN(); i++){

		old_average = average;
		average = static_cast<T>(i)/static_cast<T>(i+1)*average + 
        	1./static_cast<T>(i+1) * V.GetComponent(i); 

        result = 1./static_cast<T>(i+1) *
          (static_cast<T>(i) * result + 
          	V.GetComponent(i)*V.GetComponent(i) + 
          	static_cast<T>(i) * old_average*old_average) -
          	average*average; 
    }

    return result;
}

template <typename T>  T CalculateMedian( Vettore <T> V){

	Selection_Sort(V);

	T median = 0;

	if ( V.GetN() % 2 == 0 ){
		median = ( V[ V.GetN()/2 ] + V[ V.GetN()/2-1] ) / 2.0;
	} else {
		median = V[V.GetN()/2];
	}
	return median; 
}


template <typename T> void SwitchByRef(T &a, T &b){
	T c=a;
    a = b;
    b = c;
};

template <typename T> void Selection_Sort(Vettore <T> &V){
	
    for (int j=0; j<V.GetN()-1; j++){

        int imin = j;
        T min = V[imin];

        for (int i = j+1; i < V.GetN(); i++){
            if (V[i]<min){
                min = V[i];
                imin = i;
            }
        }

        SwitchByRef(V[j],V[imin]);	
    }    
}; 


