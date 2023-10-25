monedas.o: monedas.cpp
	g++ -o monedas.o monedas.cpp
	
execMon: monedas.o
	./monedas.o

mochila.o: mochila.cpp
	g++ -o mochila.o mochila.cpp

execMoc: mochila.o
	./mochila.o

all: monedas.o mochila.o
	g++ -o monedas.o monedas.cpp
	g++ -o mochila.o mochila.cpp

