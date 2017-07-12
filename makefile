test:
	make build;
	make run;
	make clean;

build:
	g++ -c *.cpp -I../include -std=c++11;
	g++ *.o -o sfml-app -L../lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system;


run:
	./sfml-app;

clean:
	-rm sfml-app;
	-rm *.o;
