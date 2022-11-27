all: main.o tuile.o grille.o
	g++ main.o domino.o tuile.o grille.o -o main -lsfml-graphics -lsfml-window -lsfml-system

domino.o: domino.cpp
	g++ -c domino.cpp

main.o: main.cpp
	g++ -c main.cpp

tuile.o: tuile.cpp
	g++ -c tuile.cpp

grille.o: grille.cpp
	g++ -c grille.cpp

clean:
	rm -rf *.o main



