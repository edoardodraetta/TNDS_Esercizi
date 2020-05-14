CC = g++
CFLAGS = -Wall -O3 --std=c++11

# Nel caso si utilizzino classi o funzioni template 
# la dichiarazione e l'implementazione vanno codificate 
# entrambe nell'header file. 
# Come si potrebbe compilare una classe template senza sapere con 
# che tipi di dato verrà utilizzata ?
# Di conseguenza la compilazione si riduce alla singola istruzione :

esercizio_3.1.exe : esercizio_3.1.cpp funzioni.h 
	$(CC) -o esercizio_3.1.exe esercizio_3.1.cpp $(CFLAGS)
clean : 
	# removes old files
	rm *.o 
cleanall: clean
	rm esercizio_3.1.exe