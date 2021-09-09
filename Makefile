main.exe: main.o
	g++ main.o -o main.exe

main.o: main.cpp gstack.h
	g++ -std=c++0x -c main.cpp -o main.o

.PHONY: clean
clean:
	rm *.o *.exe
