CC = g++
CFLAGS = -Wall -O3 --std=c++11


main.exe : main.o 	# main.exe depends on main.o 
	# generate executable from object file. 
	$(CC) main.o -o main.exe # link main.o into main.exe
main.o : main.cpp # main.o depends on main.cpp
	# generate object file
	$(CC) -c main.cpp -o main.o $(CFLAGS) # compile main.cpp
clean : 
	# removes old files
	rm *.o main.exe

