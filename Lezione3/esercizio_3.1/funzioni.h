#include <iostream> // terminal read and write
#include <fstream> // file read and write
#include <assert.h> // debug flags

#include <vector> // contenitore
#include <algorithm> // funzioni c++

using namespace std;

// davanti alle funzioni metto template <typename T>
// Vector of template type vector --> vector <T>

// vector Manip:
// - v.size()
// - v.push_back()

// READ/WRITE

template <typename T> vector<T> Read(const char* filename, int ndata){
	
	vector<T> v; // create a vector
	ifstream fin(filename); // open filestream

	if(!fin){
      cout << "Error: " << filename << " could not be read." <<endl; 
    } else {
        for (unsigned int i = 0; i<ndata; i++){

        	T val = 0;
            fin >> val;
            v.push_back(val);

            // end of file reporting
            if (fin.eof() ){
            	cout << "Reached end of file, exiting" << endl;
            }
        }
    }
	return v;
}

template <typename T> void PrintToTerminal(const vector <T> &v){

    cout << endl;
    if (v.size()== 0 ){ 
        cout << "Vector is null vector." << endl;

    } else {
        cout << "|";
        for (int i = 0; i < v.size(); i++){
        cout << v[i] << "|";  
    } 
    cout << endl;

    }
} 

template <typename T> void PrintToFile(const char * filename, const vector<T> &v){

	ofstream fout(filename); 

	if (!fout){ 
		cerr << "Non posso creare il file " << filename << endl;
		return;
	}
    for (int i = 0; i < v.size(); i++){
        fout << v[i] << endl;
    }

    fout.close();
    return;
}

// input elements from terminal
template <typename T> vector<T> InputVector(){

    int M = 0 ;
    cout << endl;
    cout << "Please enter desired vector dimension: ";

	cin >> M;

    vector <T> v;

    if (M==0) {
        cout <<  "Vector is null vector." << endl;
        return v;

    } else {

        cout << "Please enter " << v.size() << " floating point numbers." << endl;

        for (int i = 0; i < v.size(); i++){

        	double elem = 0; 

            cout << "Element number " << i+1 << ": ";
            cin >> elem;

            v[i] = elem;

            if ( i != (v.size()-1) ){
                cout << "Current array : ";
                PrintToTerminal(v);
            }
        }
        cout << "Final array : ";
        PrintToTerminal(v);
        return v;
    }
    cout << endl;
}				

// MANIPULATION

template <typename T>  double CalcoloMedia(const vector <T> & v){

	double accumulo = 0;
	if (v.size()== 0) return accumulo;

	for (int i = 0; i < v.size(); i++){ 

		accumulo = static_cast<double>(i)/static_cast<double>(i+1)*accumulo +
				1./static_cast<double>(i+1) * v[i]; 
	}

    return accumulo;
}

template <typename T> double CalcoloVarianza(const vector <T> & v){
	
	double result = 0;

	if (v.size() == 0) return result;

	double old_average, average = 0;

	for (int i = 0; i < v.size(); i++){

		old_average = average;

		average = static_cast<double>(i)/static_cast<double>(i+1)*average + 
        	1./static_cast<double>(i+1) * v[i];

        result = 1./static_cast<double>(i+1) *
          (static_cast<double>(i) * result + 
          	v[i]*v[i] + 
          	static_cast<double>(i) * old_average*old_average) -
          	average*average; 
    }

    return result;
}

template <typename T>  double CalcoloMediana( vector <T> v){

	sort( v.begin(), v.end() ); // sort vector elements in range
								// functions work as iterators in STL

	double median = 0;

	if ( v.size() % 2 == 0 ){
		median = ( v[ v.size()/2 ] + v[ v.size()/2-1] ) / 2.0;
	} else {
		median = v[v.size()/2];
	}
	return median; 
}

// Sort is included in STL
