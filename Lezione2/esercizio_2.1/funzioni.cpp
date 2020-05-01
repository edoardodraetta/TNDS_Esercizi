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

// usesselection sort function
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

void SwitchByRef(double &a, double &b){
    double c=a;
    a = b;
    b = c;
}

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

/*


double CalculateMedian(Vettore);

void Print(const char *, const Vettore &);  // prints to file
void Print(const Vettore &);				// input elements from terminal

void Selection_Sort(Vettore &); 
*/