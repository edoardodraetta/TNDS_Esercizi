CC = g++
CFLAGS = -Wall -O3 --std=c++11

# linking
main_vec.exe : main_vec.o Vettore.o funzioni.o
	$(CC)  -o main_vec.exe main_vec.o Vettore.o funzioni.o $(CFLAGS)

# Compiling
main_vec.o : main_vec.cpp Vettore.h Vettore.cpp funzioni.h funzioni.cpp
	$(CC) -c main_vec.cpp  $(CFLAGS) 

funzioni.o : Vettore.h funzioni.h funzioni.cpp
	$(CC) -c funzioni.cpp $(CFLAGS)

Vettore.o : Vettore.h Vettore.cpp
	$(CC) -c Vettore.cpp $(CFLAGS)

clean : 
	# removes old files
	rm *.o 
cleanall: clean
	rm main_vec.exe