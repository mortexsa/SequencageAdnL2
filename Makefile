run: partie1
	./partie1

partie1: sequence.o distance.o main1.o 
	gcc -o partie1 sequence.o distance.o main1.o

sequence.o: sequence.c
	gcc -o sequence.o -c sequence.c -Wall

distance.o: distance.c
	gcc -o distance.o -c distance.c -Wall 

main1.o: main1.c sequence.h distance.h
	gcc -o main1.o -c main1.c -Wall 

clean: rm -rf partie1

mrproper: clean
	rm -rf partie1