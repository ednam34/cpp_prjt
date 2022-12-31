all: main.o mainScreen.o card.o cardGrid.o dominoGrid.o domino.o tuile.o grille.o Board.o
	g++ tuile.o grille.o domino.o dominoGrid.o card.o cardGrid.o mainScreen.o main.o Board.o -o main -lsfml-graphics -lsfml-window -lsfml-system

dominoGridWindow.o: graphics/dominoGridWindow.cpp hpp/dominoGridWindow.hpp
	g++ -c graphics/dominoGridWindow.cpp

tuile.o: tuile.cpp hpp/tuile.hpp
	g++ -c tuile.cpp

grille.o: grille.cpp hpp/grille.hpp
	g++ -c grille.cpp

domino.o: domino.cpp hpp/tuile.hpp hpp/grille.hpp
	g++ -c domino.cpp

dominoGrid.o: dominoGrid.cpp hpp/grille.hpp hpp/tuile.hpp
	g++ -c dominoGrid.cpp

card.o: graphics/card.cpp graphics/hpp/card.hpp
	g++ -c graphics/card.cpp

cardGrid.o: graphics/cardGrid.cpp graphics/hpp/cardGrid.hpp
	g++ -c graphics/cardGrid.cpp

test.o: graphics/test.cpp
	g++ -c graphics/test.cpp

mainScreen.o : mainScreen.cpp hpp/mainScreen.hpp
	g++ -c mainScreen.cpp

Board.o: Board.cpp hpp/Board.hpp
	g++ -c Board.cpp

main.o: main.cpp hpp/grille.hpp hpp/tuile.hpp hpp/mainScreen.hpp
	g++ -c main.cpp


clean:
	rm -rf *.o main


