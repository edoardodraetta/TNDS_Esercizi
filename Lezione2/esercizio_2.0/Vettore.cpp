#include "Vettore.h"
#include <iomanip>
#include <cmath>
#include <cstdlib>
//#define NDEBUG

#include <assert.h>
// macro assert puo' rivelarsi estremamente utile per scovare errori
// in fase di realizzazione del programma. 

// assert ( check && "Message")
// fara' abortire il programa se si verifica la condizione. 
// prima della chiusura verrà mostrato:
// assert line + location of error
// che indica molto chiaramente cosa ha causato il problema. 
// normalmente quando la fase di debuggin è terminata gli assert possono
// essere disabilitati mediante la def di una macro #define NDEBUG,  
// fa si che tutti gli assert dichiarati vengano ignorati

// class:function (scope)
// default constructor
Vettore::Vettore() {
	// endl inserts a new line character and flushes the stream.
	cout << "Calling default constructor." << endl;
	// already declared inside the vector scope.
	m_N = 0;
	m_v = NULL; // null pointer
}


// overloaded constructor
Vettore::Vettore(unsigned int N){
	cout << "Calling overloaded constructor." << endl;

	m_N = N;
	m_v = new double[N];  // creates an array (pointer to) for N doubles. 
	for (int k = 0; k < N; k++) {
		m_v[k] = 0;
		} 
}

// destructor 
Vettore::~Vettore(){
	cout << "Calling destructor. " << endl; 
	delete[] m_v; // deallocation, array form
}

void Vettore::SetComponent(unsigned int i, double a){
	assert( (m_N > i) && "Errore : l'indice  e' troppo grande");
	if (i<m_N){
		m_v[i] = a;
	}
	else {
		cerr << "Errore : indice " << i << ", dimensione " << m_N << endl;
		exit(-1);
	}
}

double Vettore::GetComponent (unsigned int i) const {
	assert( (m_N > i) && "Errore : l'indice  e' troppo grande");
	if (i<m_N){
		return m_v[i];
	}
	else {
		cerr << "Errore : indice " << i << ", dimensione " << m_N << endl;
		exit(-1);
	}
}

void Vettore::Scambia(unsigned int i, unsigned int j){
	double temp = GetComponent(i);  		// store value at i
	SetComponent(i, GetComponent(j));		// at index i put value at j
	SetComponent(j, temp);					// at index j put value at i
}

// overloading dell'operatore di accesso [] ad un elemento
// ci permette di accedere ai valori del vettore con [].
// ([] normalmente solo per array)
// double a = v[2] se v e' vettore.
double& Vettore::operator[] (unsigned int i){
	assert( (m_N > i) && "Errore : l'indice  e' troppo grande");
	if (i<m_N){
		return m_v[i];
	}
	else {
		cerr << "Errore : indice " << i << ", dimensione " << m_N << endl;
		exit(-1);
	}
}



