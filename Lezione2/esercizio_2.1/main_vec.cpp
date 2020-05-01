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
	cout << "Vettore v_read : dimensione = " << v_read.GetN() << endl;

	cout << "|";
	for (int i = 0; i < v_read.GetN(); i++) cout << v_read.GetComponent(i) << "|"; 
	cout << endl;

	// CALCULATIONS ON VECTORS

	cout << endl;
	cout << "Media di vettore v_read : " << CalculateMean(v_read) << endl;
	cout << "Varianza di vettore v_read : " << CalculateVariance(v_read) << endl;
	cout << "Mediana di vettore v_read : " << CalculateMedian(v_read) << endl;
	cout << endl;

	// SORTING A VECTOR

	cout << "Sorted v_read :" << endl;

	Selection_Sort(v_read);

	cout << "|";
	for (int i = 0; i < v_read.GetN(); i++) cout << v_read.GetComponent(i) << "|"; 
	cout << endl;

	// DEFAULT CONSTRUCTOR

	cout << endl;
	Vettore vnull;

	cout << "Vettore vnull : dimensione = " << vnull.GetN() << endl;

	// OVERLOADED CONSTRUCTOR

	unsigned int N = 5;

	cout << endl;
	Vettore v_N(N);
	cout << "Vettore v_N : dimensione = " << v_N.GetN() << endl;

	cout << "|";
	for (int i = 0; i < v_N.GetN(); i++) cout << v_N.GetComponent(i) << "|"; 
	cout << endl << endl;
	
	// COPY CONSTRUCTOR
	
	Vettore v_a(N);
	for (int i = 0; i < v_a.GetN(); i++){
		v_a[i] = 1;
	}

	cout << "Vettore v_a : dimensione = " << v_a.GetN() << endl;
	cout << "|";
	for (int i = 0; i < v_a.GetN(); i++) cout << v_a.GetComponent(i) << "|"; 
	cout << endl << endl;

	Vettore v_b(v_a); // copy constructor

	cout << "Vettore v_b : dimensione = " << v_b.GetN() << endl;
	cout << "|";
	for (int i = 0; i < v_b.GetN(); i++) cout << v_b.GetComponent(i) << "|"; 
	cout << endl << endl;

	Vettore v_c = v_a; // overloaded "=" allows me to equate two vectors

	cout << "Vettore v_c : dimensione = " << v_c.GetN() << endl;
	cout << "|";
	for (int i = 0; i < v_c.GetN(); i++) cout << v_c.GetComponent(i) << "|"; 
	cout << endl << endl;

	/*
  	// VECTOR FROM TERMINAL INPUT 
	unsigned int M;

	cout << "Enter vector dimension : ";
	cin >> M;

	Vettore v_M(M);
	cout << "Vettore v_M : dimensione = " << v_M.GetN() << endl;
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