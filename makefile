program: main.o Money.o
	g++ -o program main.o Money.o

main.o: main.cpp
	g++ -c main.cpp

Money.o: Money.cpp
	g++ -c Money.cpp

clean:
	rm program *.o