monedas.o: monedas.cpp
	g++ -o monedas.o  monedas.cpp
	
execMon: monedas.o
	./monedas.o
