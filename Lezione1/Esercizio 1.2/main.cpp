#include <iostream>
#include <fstream>
#include <cstdlib>

#include "functions.h"

using namespace std;

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

    Print("sorted.dat", data, ndata);

    return 0;
}