#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// HEADER

// variables don't have to be named in these declarations. 
double CalculateMean(double *, int);
double CalculateVariance(double *, int);
double CalculateMedian(double [], int);
double * ReadDataFromFile(const char *, int); // [] is array of strings
void Print (const char*, double*, int);
void SwitchByValue(double, double);
void SwitchByRef(double &, double &);
void SwitchByPointer(double *, double *);
void selection_sort(double *, int );

int main(int argc, char** argv){

    if ( argc < 3) {
        cout << "Uso del programa : " << argv[0] <<  "<n_data> <filename> " << endl;
        return -1;
    }
    
    int ndata = atoi(argv[1]); // number of elts of data
    char* filename = argv[2]; // name of file	

    // uso funzione per leggere gli elementi da un file

    double * data = ReadDataFromFile(filename, ndata);

    // cout per visualizzare il vettore

    cout << "Printing data array : " << "|";
    for (int i = 0; i < (ndata); i++){
        cout << data[i] << "|";
    }
    cout << endl;

    // uso funzione per calcolare la media e la varianza

    cout << "Mean: " << CalculateMean(data, ndata) << endl;
    cout << "Variance: " << CalculateVariance(data, ndata) << endl;

    // Uso funzione per calcolare la mediana

    cout << "Median: " << CalculateMedian(data, ndata) << endl;

    // cout per controllare vettore riordinato

    // scrivo i dati riordinati su file

    Print("fileout.dat", data, ndata);

    return 0;
}

// Definitions

// reads <size> elements from <filename> and returns them as an array

double * ReadDataFromFile(const char * filename, int size){

	double * data = new double[size]; // create the array for output

	ifstream fin(filename);
	if(!fin){
      cout <<"Error: " << filename << " could not be read." <<endl; 
    }
    else {
        for (int i = 0; i < size; i++){
            fin >> data[i];
        }
    }
    fin.close();

	return data;
}


// writes <size> elements of an array into <filename>
void Print (const char* filename, double * data, int size){

	ofstream fout(filename); 
    for (int i = 0; i < size; i++){
        fout << data[i] << endl;
    }

    fout.close();
}


// calculates the mean of an array. 

double CalculateMean(double * data, int size){

	double mean = 0;
	double sum = 0;

    for (int i = 0; i < size; i++){
        sum += data[i];
    }

    mean = sum / size; 

    return mean;
}


// calculates the variance of an array. 

double CalculateVariance(double * data, int size){

	double mean = 0;
	double variance = 0;
	double sum = 0;

    for (int i = 0; i < size; i++){
        sum += data[i];
    }


    mean = sum / size; 

    for(int k = 0; k < size; k++ ){
            variance += (data[k] - mean) * (data[k] - mean);
    }   

    variance /= size;

    return variance;
}


// element exchange

void SwitchByValue(double a, double b){
    double c=a;
    a = b;
    b = c;
}

void SwitchByRef(double &a, double &b){
    double c=a;
    a = b;
    b = c;
}

void SwitchByPointer(double *a, double *b){
    double c=*a;
    *a = *b;
    *b = c;
}

void selection_sort(double * vec, int size){


    for (int j=0; j<size-1; j++){
        int imin = j;
        double min = vec[imin];
        for (int i = j+1; i < size; i++){
            if (vec[i]<min){
                min = vec[i];
                imin = i;
            }
        }
        SwitchByRef(vec[j],vec[imin]);
    }
}

// Calculate median

double CalculateMedian(double vec[], int size){


    double * vcopy = new double[size];
    for (int k = 0; k < size; k++) vcopy[k] = vec[k];

    selection_sort(vcopy, size);

    double median = 0;

    if (size % 2 == 0){
        median = (vcopy[size/2] + vcopy[(size/2) - 1] ) / 2.0;
    }
    else {
        median = vcopy[size/2];
    }

    delete [] vcopy;

    return median;

}