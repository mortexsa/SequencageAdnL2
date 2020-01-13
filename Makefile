run: partie3
	./partie3

partie1: sequence.o distance.o main1.o 
	gcc -o partie1 sequence.o distance.o main1.o

partie2: sequence.o distance.o famille.o main2.o 
	gcc -o partie2 sequence.o distance.o famille.o main2.o

partie3: sequence.o distance.o famille.o alignement.o main3.o
	gcc -o partie3 sequence.o distance.o famille.o alignement.o main3.o

sequence.o: sequence.c
	gcc -o sequence.o -c sequence.c -Wall

distance.o: distance.c
	gcc -o distance.o -c distance.c -Wall 

famille.o: famille.c
	gcc -o famille.o -c famille.c -Wall

alignement.o: alignement.c
	gcc -o alignement.o -c alignement.c -Wall

main1.o: main1.c sequence.h distance.h
	gcc -o main1.o -c main1.c -Wall 

main2.o: main2.c sequence.h distance.h famille.h
	gcc -o main2.o -c main2.c -Wall

main3.o: main3.c sequence.h distance.h famille.h alignement.h
	gcc -o main3.o -c main3.c -Wall

clean:
	rm -rf *.o
	rm -rf partie1
	rm -rf partie2
	rm -rf partie3
