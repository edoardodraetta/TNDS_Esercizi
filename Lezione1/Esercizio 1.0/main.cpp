#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main( int argc, char** argv){    

    if ( argc < 3) {
        cout << "Uso del programa : " << argv[0] <<  "<n_data> <filename> " << endl;
        return -1;
    }
    
    int ndata = atoi(argv[1]); // number of elts of data
    double* data = new double[ndata]; // declares an array 
    char* filename = argv[2]; // name of file
    
    cout << "Input 1: " << argv[1] << "  Input 2: " << argv[2] << endl;

    // [... 1) leggi dati da file e caricali nel c-array data ... ]
    
    ifstream dataFile(filename);
    
    if(!dataFile){
      cout <<"Error ...." <<endl; //stampa un messaggio
      return -1; //ritorna un valore diverso da quello usuale
    }
    else {

        // read with for loop
        for (int i = 0; i < ndata; i++){
            dataFile >> data[i];
        }
    }
    dataFile.close();

    cout << "Printing data array : " << "|";
    for (int i = 0; i < (ndata); i++){
        cout << data[i] << "|";
    }
    cout << endl;

    // [... 2) calcola la media e la varianza del vettore ... ]

    double sum = 0;
    double mean = 0;
    double variance = 0;

    for (int i = 0; i < ndata; i++){
        sum += data[i];
    }

    mean = sum / ndata; 

    for(int k = 0; k < ndata; k++ ){
            variance += (data[k] - mean) * (data[k] - mean);
    }   

    variance /= ndata;

    cout << "Mean = " << mean << "  Variance = " << variance << endl;; //

    // [...  calcola la mediana: prima creo una copia del vettore ... ]

    double * vcopy = new double[ndata];
    for (int k = 0; k < ndata; k++){
        vcopy[k] = data[k];
    }
    // [... 3) poi riordino gli elementi del vettore dal minore al maggiore... ]

    sort(vcopy, vcopy+ndata);

    cout << "Printing ordered data array : " << "|";
    for (int i = 0; i < (ndata); i++){
        cout << vcopy[i] << "|";
    }
    cout << endl;

    // [... 4) poi prendo il valore centrale o la media tra i due centrali... ]
    
    double median = 0;
    if (ndata % 2 == 0){
        median = (vcopy[ndata/2] + vcopy[(ndata/2) - 1] ) / 2.0;
        // 4/2 = 2, 2 is the third elt, 1 is the second elt, 1 2 3 4
    }
    else {
        median = vcopy[ndata/2];
        // 5/2 = 2, which is the third elt,  1 2 3 4 5
    }
    cout << "Median = " << median << endl;; 

    // [... 5) scrivo i dati riordinati su un file ...]

    ofstream sortFile("sorted.dat");
    for (int i = 0; i < ndata; i++){
        sortFile << vcopy[i] << endl;
    }

    sortFile.close();

    delete [] vcopy;
    delete [] data;

    return 0;
}
