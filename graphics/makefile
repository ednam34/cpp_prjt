all: test.o cardGrid.o card.o 
	g++ card.o cardGrid.o test.o -o main -lsfml-graphics -lsfml-window -lsfml-system


card.o: card.cpp hpp/card.hpp
	g++ -c card.cpp

cardGrid.o: cardGrid.cpp hpp/cardGrid.hpp hpp/card.hpp
	g++ -c cardGrid.cpp 

test.o: test.cpp hpp/cardGrid.hpp hpp/card.hpp
	g++ -c test.cpp

clean:
	rm -rf *.o main
