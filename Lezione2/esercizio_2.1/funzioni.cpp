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
double CalculateMedian(const Vettore & V){

	Vettore Vcopy(V);

	Selection_Sort(Vcopy);

	double median = 0;

	if ( V.GetN() % 2 == 0 ){
		median = ( Vcopy[ V.GetN()/2 ] + Vcopy[ V.GetN()/2-1] ) / 2.0;
	} else {
		median = Vcopy[V.GetN()/2];
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

// Print vector contents to file
void Print(const char * filename, const Vettore & V){

	ofstream fout(filename); 
    for (int i = 0; i < V.GetN(); i++){
        fout << V.GetComponent(i) << endl;
    }

    fout.close();
}

// writes a vector of predetermined size from terminal input
void Print(Vettore & V){

	cout << "Current array : " << "|";
    for (int i = 0; i < V.GetN(); i++){
        cout << V.GetComponent(i) << "|";
    }
    cout << endl;

    cout << "Please enter " << V.GetN() << " floating point numbers." << endl;

    for (int i = 0; i < V.GetN(); i++){

    	double elem = 0; 

        cout << "Element number " << i+1 << ": ";
        cin >> elem;

        V.SetComponent(i, elem);

        cout << "Current array : " << "|";
        for (int i = 0; i < V.GetN(); i++){
            cout << V.GetComponent(i) << "|";
        }
        cout << endl;

    }
    cout << "Final array : " << "|";
    for (int i = 0; i < V.GetN(); i++){
        cout << V.GetComponent(i) << "|";
    }
    cout << endl;
}
