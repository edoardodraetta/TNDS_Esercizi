#include <iostream>
// #include <cstdlib>
// #include <fstream>
// #include <iomanip>
// using namespace std;

#include "Vettore.h"
#include "funzioni.h"



int main(){

	// READ VECTOR FROM FILE

	Vettore v_read = Read("input.dat", 5);

	cout << endl;
	cout << "Vettore v_read : dimensione = " << v_read.GetN();

	Print(v_read);

	// CALCULATIONS ON VECTORS

	cout << endl;
	cout << "Media di vettore v_read : " << CalculateMean(v_read) << endl;
	cout << "Varianza di vettore v_read : " << CalculateVariance(v_read) << endl;
	cout << "Mediana di vettore v_read : " << CalculateMedian(v_read) << endl;
	cout << endl;

	// SORTING A VECTOR

	cout << "Sorted v_read :";
	Selection_Sort(v_read);
	Print(v_read);

	// PRINTING TO FILE 	
	
	PrintToFile("sorted_output.dat", v_read);

	// INPUT FROM TERMINAL

	Vettore v_input = InputVector();
	Print(v_input);

	// DEFAULT CONSTRUCTOR

	Vettore vnull;

	cout << "Vettore vnull : dimensione = " << vnull.GetN() << endl;

	Print(vnull);

	// OVERLOADED CONSTRUCTOR

	unsigned int N = 5;

	Vettore v_N(N);
	cout << "Vettore v_N : dimensione = " << v_N.GetN() << endl;

	Print(v_N);
	
	/*
	// COPY CONSTRUCTOR
	
	Vettore v_a(N);
	for (int i = 0; i < v_a.GetN(); i++){
		v_a[i] = 1;
	}

	cout << "Vettore v_a : dimensione = " << v_a.GetN() << endl;
	Print(v_a);

	Vettore v_b(v_a); // copy constructor

	cout << "Vettore v_b : dimensione = " << v_b.GetN() << endl;
	Print(v_b);

	Vettore v_c = v_a; // overloaded "=" allows me to equate two vectors

	cout << "Vettore v_c : dimensione = " << v_c.GetN() << endl;
	Print(v_c);

	*/

	/*
	// VECTOR AS A POINTER

	Vettore * v = new Vettore(10);
	cout << "Vettore v : dimensione = " << v->GetN() << endl;
	for (int i = 0; i < v->GetN(); i++) cout << v->GetComponent(i) << "|"; 
	cout << endl << endl;

	*/

	return 0; 
}