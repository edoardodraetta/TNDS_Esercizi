#include <iostream>
#include <fstream>
#include <cstdlib>

#include "functions.h"

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

// writes an array of predetermined size from terminal input
void Print (double * data, int size){
    
    cout << "Current array : " << "|";
    for (int i = 0; i < (ndata); i++){
        cout << data[i] << "|";
    }
    cout << endl;

    cout << "Please enter " << size " elements" << endl;


    for (int i = 0; i < size; i++){

        cout << "Element number " << i+1 << ":" << endl;
        cin >> data[i]
            
        cout << "Current array : " << "|";
        for (int i = 0; i < (ndata); i++){
            cout << data[i] << "|";
        }
        cout << endl;

    }

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

