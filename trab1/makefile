parametrosCompilacao=-Wall #-Wshadow
nomePrograma=trab

all: $(nomePrograma)

$(nomePrograma): main.o ordenacao.o
	gcc -o $(nomePrograma) main.o ordenacao.o -lm $(parametrosCompilacao)

main.o: ordenacao.h main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)