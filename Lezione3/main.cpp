#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Vettore.h"
#include "Funzioni.h"

int main (int argc, char** argv){

	if (argc<3) {
		cout << "Uso del programma : " << argv[0] << " <n_data_> <filename> " << endl;
		return -1;
	}

	int ndata = atoi(argv[1]);
	char * filename = argv[2];

	Vettore <double> v = Read<double>(filename,ndata);

	cout << endl;
	cout << "Media di vettore :" << CalculateMean<double>(v) << endl;
	cout << "Varianza di vettore : " << CalculateVariance<double>(v) << endl;
	cout << "Mediana di vettore : " << CalculateMedian<double>(v) << endl;
	cout << endl;

	Print(v);
	return 0;

}