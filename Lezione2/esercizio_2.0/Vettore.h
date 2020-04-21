#ifndef __Vettore_h__
#define __Vettore_h__
// per evitare inclusione multiple di uno stesso header file che, nel caso specifico,
// porterebbero ad una doppia dichiarazione della classe vettore. 
// immagina di voler  compilare main insieme al file di funzioni e che entrambi
// i codici sorgente contengano una instruzione #include "vettore.h". in fase di compilazione
// il compilatore si lamenterebbe per una doppia dichiarazione. con questo meccanismo alla prima
// inclusione di vettore.h viene creata una variabile globale __Vettore.h__. Al secondo tentativo
// di inclusione l'esistenza della variabile globale forza il compilatore a saltare tutte le righe dopo
// #ifdef fino a #endif, di fatto evitando la second inclusione del file
#include <iostream>

using namespace std;

// the header file contains function declarations (methods). 

class Vettore {

  public: // can be accessed as Vettore.obj

  	Vettore();						// default constructor
  	Vettore(unsigned int N);		// constructor with dimension

  	~Vettore(); 					// destructor

  	unsigned int GetN() const {return m_N;}; // accesses dimension
  	// inline implementation of GetN()
  	// implica che il compilatore metta una copia della
  	// funzione ogni volta che questa viene chiamata. 
  	// in questo modo il codice diventa più lungo ma vengono 
  	// ottimizzate le performance in quanto non si deve chiamare la
  	// funzione. 
  	void SetComponent(unsigned int, double);
  	double GetComponent(unsigned int) const;

  	void Scambia(unsigned int, unsigned int);
  	double& operator[] (unsigned int);
  	
  private: // cannot be accessed as Vettore.obj

  	unsigned int m_N; 				// dimension
  	double* m_v;					// pointer to the array

}; // classes require semicolon at end

#endif // __Vettore_h__