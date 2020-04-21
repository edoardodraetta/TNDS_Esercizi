CC = g++
CFLAGS = -Wall -O3 --std=c++11


# exe depends on both .o files
test_vector.exe : test_vector.o Vettore.o 	
	$(CC) -o test_vector.exe test_vector.o Vettore.o

# .o files depend on themselves and any headers
test_vector.o : test_vector.cpp Vettore.h
	$(CC) -c test_vector.cpp  $(CFLAGS) 

Vettore.o : Vettore.h
	$(CC) -c Vettore.cpp  $(CFLAGS) 

clean : 
	# removes old files
	rm *.o main.exe