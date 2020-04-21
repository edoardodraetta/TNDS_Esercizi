CC = g++
CFLAGS = -Wall -O3 --std=c++11


main.exe : main.o functions.o 	
	$(CC) -o main.exe main.o functions.o
main.o : main.cpp functions.h
	$(CC) -c main.cpp  $(CFLAGS) 
functions.o : functions.h
	$(CC) -c functions.cpp  $(CFLAGS) 
clean : 
	# removes old files
	rm *.o main.exe

