#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// HEADER

// variables don't have to be named in these declarations. 
double CalculateMean(double *, int);
double CalculateVariance(double *, int);
double CalculateMedian(double [], int);
double * ReadDataFromFile(const char *, int); // [] is array of strings
void Print (const char*, double*, int);
void SwitchByValue(double, double);
void SwitchByRef(double &, double &);
void SwitchByPointer(double *, double *);
void selection_sort(double *, int );

// Overloaded functions
void Print(double * ,  int );
