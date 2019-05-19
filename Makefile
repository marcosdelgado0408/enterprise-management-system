all: programa1

main.o: main.cpp classes.h
			g++ main.cpp -c

menu.o: menu.cpp classes.h
			g++ menu.cpp -c

empresa.o: empresa.cpp classes.h
				g++ empresa.cpp -c

funcionario.o: funcionario.cpp classes.h
					g++ funcionario.cpp -c

programa1: main.o menu.o empresa.o funcionario.o
				g++ main.o menu.o empresa.o funcionario.o -o programa1

clean:
	rm -rf *.o
	rm programa1