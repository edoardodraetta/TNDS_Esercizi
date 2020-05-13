CC = g++
CFLAGS = -Wall -O3 --std=c++11

# linking
test_vector.exe : test_vector.o Vettore.o 
	$(CC)  -o test_vector.exe test_vector.o Vettore.o $(CFLAGS)

# Compiling
test_vector.o : test_vector.cpp Vettore.h 
	$(CC) -c test_vector.cpp  $(CFLAGS) 

Vettore.o : Vettore.h 
	$(CC) -c Vettore.cpp $(CFLAGS)

clean : 
	# removes old files
	rm *.o test_vector.exe