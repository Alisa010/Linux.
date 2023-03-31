all: main

main:main.o ComplexNum.o 
	    g++ main.o ComplexNum.o -o main

main.o: main.cpp
	    g++ -c main.cpp -o main.o

ComplexNum: ComplexNum.cpp
	     g++ -c ComplexNum.cpp -o ComplexNum.o

clean:
	    rm *.o main
