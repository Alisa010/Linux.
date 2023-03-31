all: main

main: homework.o
    g++ homework.o -o main

homework: homework.cpp
    g++ -c homework.cpp -o homework.o
clean:
	rm *.o main
