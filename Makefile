main: main.o ComplexNumber.o
	g++ -g -Wall main.o ComplexNumber.o -o main

ComplexNumber.o: ComplexNumber.cpp ComplexNumber.h
	g++ -g -Wall -c ComplexNumber.cpp

clean:
	rm *.o
