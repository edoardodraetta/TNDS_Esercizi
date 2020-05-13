CC = g++
CFLAGS = -Wall -O3 --std=c++11

# linking
main.exe : main.cpp Funzioni.h Vettore.h
	$(CC) -o main.exe main.cpp $(CFLAGS)
clean : 
	# removes old files
	rm *.o 
cleanall: clean
	rm main.exe