all:	histograma.o main.o
	g++ -o main histograma.o main.o

histograma.o:	histograma.cpp histograma.h
	g++ -c histograma.cpp

main.o: main.cpp histograma.h
	g++ -c main.cpp

clean:
	rm -rf *.o

executa:
	./main
