#include <iostream> // terminal read and write
#include <fstream> // file read and write
#include <assert.h> // debug flags
#include <cstdlib>

// #include <vector> // contenitore
// #include <algorithm> // funzioni c++

#include "funzioni.h"

using namespace std;

// number of arguments, array of arguments as strings
int main(int argc, char** argv){

	if (argc<3) {
		cout << "Uso del programma : " << argv[0] << " <n_data_> <filename> " << endl;
		return -1;
	}

	int ndata = atoi(argv[1]);
	char * filename = argv[2];


	vector <double> v = Read<double>(filename,ndata);

	PrintToTerminal(v);

	cout << "Media di vettore : " << CalcoloMedia<double>(v) << endl;
	cout << "Varianza di vettore : " << CalcoloVarianza<double>(v) << endl;
	cout << "Mediana di vettore : " << CalcoloMediana<double>(v) << endl;

	return 0;
}