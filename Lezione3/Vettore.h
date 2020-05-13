#ifndef __Vettore_h__
#define __Vettore_h__

// definizione e implementazione perche' e' oggetto template

#include <assert.h>
#include <iostream>
using namespace std;

template <typename T> class Vettore {

public:

	Vettore(){
		// costruttore default
		m_N = 0;
		m_v = NULL;
	};

	Vettore(unsigned int size){
		// overloaded constructor
		m_N = size;
		m_v = new T[size]; // create an array
		for (int i = 0; i < m_N; i++){
			m_v[0] = 0;
		}
	};


	Vettore(const Vettore& V){
		// costruttore copy
		m_N = V.GetN();
		m_v = new T[m_N];
		for (int i = 0; i < m_N; i++){
			m_v[i] = V.GetComponent(i);
		}
	}; 

	Vettore& operator=(const Vettore& V){

		m_N = V.GetN();
		if (m_v) delete m_v;
		m_v = new T[m_N];
		for (int i = 0; i < m_N; i++){
			return *this; 
			// "this" is pointer to the object to which the method belongs
		}
	}; 

	~Vettore(){delete[] m_v;};

	unsigned int GetN() const {return m_N;}; 

	void SetComponent(unsigned int i, T value){
		if (i<m_N){
			m_v[i] = value;
		} else {
			cerr << "Errore : indice " << i << ", dimensione " << m_N << endl;
			exit(-1);
		}
	};

	T GetComponent(unsigned int i) const{
		if (i<m_N) {
			return m_v[i];
		} else {
			cerr << "Errore : indice " << i << ", dimensione " << m_N << endl;
			exit(-1);
		}
	}; 

	void ExchangeComponents(unsigned int i, unsigned int j){

		T temp = GetComponent(i);
		
		SetComponent(i, GetComponent(j));
		SetComponent(j, temp);
	};

	T& operator[] (unsigned int i){

		if (i<m_N) {
			return m_v[i]; 
		} else {
			cerr << "Errore : indice " << i << ", dimensione " << m_N << endl;
			exit(-1);
		}
	}; 

private:
	unsigned int m_N; // dimensione
	T* m_v; // tipo generico T
};

#endif // __Vettore_h__

