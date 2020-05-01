
#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream> 
using namespace std;

class Vettore {

public:
	Vettore();
	Vettore(unsigned int);
	Vettore(const Vettore&); // Copy constructor

	~Vettore();

	unsigned int GetN() const {return m_N;}; 

	void SetComponent(unsigned int, double);
	double GetComponent(unsigned int) const; 

	void ExchangeComponents(unsigned int, unsigned int);
	double& operator[] (unsigned int); 
	Vettore& operator=(const Vettore&); 
private:
	unsigned int m_N; 
	double * m_v; 
};

#endif // __Vettore_h__