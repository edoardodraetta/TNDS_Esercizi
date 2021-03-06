
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Vettore.h"

using namespace std;

Vettore Read(const char*, int);

// passing by ref means variable can be modified
double CalculateMean(const Vettore &);
double CalculateVariance(const Vettore &);
double CalculateMedian( Vettore );

void Print(const Vettore &); // print to terminal
void PrintToFile(const char *, const Vettore &);  // prints to file
Vettore InputVector();				// input elements from terminal

void Selection_Sort(Vettore &); 
void SwitchByRef(double &, double &);

