
jenkins-hash: main.o
	gcc main.o -o jenkins-hash

main.o: main.c jhash.h
	gcc -c main.c

clean: 
	rm *.o
