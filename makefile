all: main.o dominoGrid.o domino.o tuile.o grille.o
	g++ tuile.o grille.o domino.o dominoGrid.o main.o -o main -lsfml-graphics -lsfml-window -lsfml-system

tuile.o: tuile.cpp hpp/tuile.hpp
	g++ -c tuile.cpp

grille.o: grille.cpp hpp/grille.hpp
	g++ -c grille.cpp

domino.o: domino.cpp hpp/tuile.hpp hpp/grille.hpp
	g++ -c domino.cpp

dominoGrid.o: dominoGrid.cpp hpp/grille.hpp hpp/tuile.hpp
	g++ -c dominoGrid.cpp

main.o: main.cpp hpp/grille.hpp hpp/tuile.hpp
	g++ -c main.cpp


clean:
	rm -rf *.o main


