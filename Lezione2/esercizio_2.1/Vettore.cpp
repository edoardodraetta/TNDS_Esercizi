#include "Vettore.h"
// #include <iostream> 
// using namespace std;

// #define NDEBUG
// ignores all declared asserts

#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <assert.h>

// assert ((check) && "message")
// aborts if check false, printing message and location of error

Vettore::Vettore(){

	// a null vector does not need to allocate any memory
	m_N = 0;
	m_v = NULL;
}

Vettore::Vettore(unsigned int size){
	m_N = size;
	m_v = new double[size]; // remains in memory until delete is called
	for (int i = 0; i < size; i++){
		m_v[i] = 0;
	}
}

Vettore::Vettore(const Vettore& V){
	// being a constructor, the new vector needs to be created!

	m_N = V.GetN();
	m_v = new double[m_N];
	for (int i = 0; i < m_N; i++){
		m_v[i] = V.GetComponent(i);
	}
} 

Vettore::~Vettore(){
	delete[] m_v; 
}

void Vettore::SetComponent(unsigned int i, double value){
	assert( (m_N > i ) && "Errore : l'indice e' troppo grande");

	if (i<m_N) {

		m_v[i] = value;

	} else {
		cerr << "Errore : indice " << i << ", dimensione " << m_N << endl;
		exit(-1);
	}
}

double Vettore::GetComponent(unsigned int i) const{
	assert( (m_N > i ) && "Errore : l'indice e' troppo grande");

	if (i<m_N) {

		return m_v[i];

	} else {
		cerr << "Errore : indice " << i << ", dimensione " << m_N << endl;
		exit(-1);
	}
}

void Vettore::ExchangeComponents(unsigned int i, unsigned int k){
		double temp = GetComponent(i);
		
		SetComponent(i, GetComponent(k));
		SetComponent(k, temp);
}

// still returns double
double& Vettore::operator[]  (unsigned int i) {
	assert( (m_N > i ) && "Errore : l'indice e' troppo grande");
	if (i<m_N) {

		return m_v[i]; 

	} else {
		cerr << "Errore : indice " << i << ", dimensione " << m_N << endl;
		exit(-1);
	}
}

// ci permette di dire vettore b = (vettore) a
Vettore& Vettore::operator=(const Vettore& V){
	m_N = V.GetN();
	if (m_v) delete m_v;
	m_v = new double[m_N];
	for (int i = 0; i < m_N; i++){
		return *this; //"this" is pointer to the object to which the method belongs
	}
}

