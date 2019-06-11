all: a.out scrpt
	l
	echo "running script"
	./a.out
	

a.out: main.o
	gcc

main.o: parser.o main.c


parser.o: draw.o parser.c


draw.o: curves.o draw.c


transformation.o: matrix.o tansformation.c
	gcc -o transformation.c matrix.o

matrix.o: display.o matrix.c
	gcc -o matrix.c display.o

display.o: display.c
	gcc -o display.c
