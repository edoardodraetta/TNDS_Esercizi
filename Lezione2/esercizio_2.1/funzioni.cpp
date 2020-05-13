#include "funzioni.h"
// (includes vector class)

// function implementation

// Load contents of file into vector
Vettore Read(const char* filename, int size){

	Vettore V(size);

	ifstream fin(filename);
	if(!fin){
      cout <<"Error: " << filename << " could not be read." <<endl; 
    }
    else {
        for (int i = 0; i < size; i++){
            fin >> V[i];
        }
    }
    fin.close();

	return V;
}

double CalculateMean(const Vettore & V){

	double accumulo = 0;
	if (V.GetN() == 0) return accumulo;

	for (int i = 0; i < V.GetN(); i++){ 

		accumulo = static_cast<double>(i)/static_cast<double>(i+1)*accumulo +
				1./static_cast<double>(i+1) * V.GetComponent(i); 
	}

    return accumulo;
}

double CalculateVariance(const Vettore & V){

	double result = 0;

	if (V.GetN() == 0) return result;

	double old_average, average = 0;

	for (int i = 0; i < V.GetN(); i++){

		old_average = average;
		average = static_cast<double>(i)/static_cast<double>(i+1)*average + 
        	1./static_cast<double>(i+1) * V.GetComponent(i); 

        result = 1./static_cast<double>(i+1) *
          (static_cast<double>(i) * result + 
          	V.GetComponent(i)*V.GetComponent(i) + 
          	static_cast<double>(i) * old_average*old_average) -
          	average*average; 
    }

    return result;
}

// uses selection sort function
// pass by value creates a copy of V within the function
double CalculateMedian( Vettore V){

	Selection_Sort(V);

	double median = 0;

	if ( V.GetN() % 2 == 0 ){
		median = ( V[ V.GetN()/2 ] + V[ V.GetN()/2-1] ) / 2.0;
	} else {
		median = V[V.GetN()/2];
	}
	return median; 
}

// used in selection sort
void SwitchByRef(double &a, double &b){
    double c=a;
    a = b;
    b = c;
}

// Sorting algorithm
void Selection_Sort( Vettore & V ){

    for (int j=0; j<V.GetN()-1; j++){

        int imin = j;
        double min = V[imin];

        for (int i = j+1; i < V.GetN(); i++){
            if (V[i]<min){
                min = V[i];
                imin = i;
            }
        }

        SwitchByRef(V[j],V[imin]);	
    }     
} 

// print to terminal

// iomanip for floating point numbers:
//     fixed - prints without exponents when possible
//     scientific - prints using exponents
//     setprecision(int n) - prints n numbers after the decimal
//
// setw(int n) - sets width of output field to n
// setfill(char c) - uses c to fill space
void Print(const Vettore & V){

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

// Print vector contents to file
void PrintToFile(const char * filename, const Vettore & V){

	ofstream fout(filename); 
    for (int i = 0; i < V.GetN(); i++){
        fout << V.GetComponent(i) << endl;
    }

    fout.close();
}

// writes a vector of predetermined size from terminal input
Vettore InputVector(){

    int M = 0 ;
    cout << endl;
    cout << "Please enter desired vector dimension: ";

	cin >> M;

    Vettore V(M);

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
