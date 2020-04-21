#include <iostream>
#include "Vettore.h"

using namespace std;

int main(){

	// test constructor
	cout << endl;
	Vettore vnull;

	cout << "Vettore vnull : dimensione = " << vnull.GetN() << endl;

	// overloaded constructor

	unsigned int N = 5;

	cout << endl;
	Vettore v_N(N);
	cout << "Vettore v_N : dimensione = " << v_N.GetN() << endl;

	cout << "|";
	for (int i = 0; i < v_N.GetN(); i++) cout << v_N.GetComponent(i) << "|"; 
	cout << endl << endl;

/*  vector of input size
	unsigned int M;

	cout << "Enter vector dimension : ";
	cin >> M;

	Vettore v_M(M);
	cout << "Vettore v_M : dimensione = " << v_M.GetN() << endl;
*/

	// declare a vector as a pointer
	Vettore * v = new Vettore(10);
	cout << "Vettore v : dimensione = " << v->GetN() << endl;
	for (int i = 0; i < v->GetN(); i++) cout << v->GetComponent(i) << "|"; 
	cout << endl << endl;

	return 0; 
}