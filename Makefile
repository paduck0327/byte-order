add-nbo: main.o
	gcc -o add-nbo main.o

main.o: main.cpp
	gcc -c -o main.o main.cpp

clean:
	rm -f *.o
	rm -f add-nbo
