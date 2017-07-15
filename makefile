test:
	make build;
	make run;
	make clean;

build:
	g++ -c *.cpp -I../SFML-2.4.2/include -std=c++11;
	g++ *.o -o sfml-app -L../SFML-2.4.2/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system;


run:
	./sfml-app;

clean:
	-rm sfml-app;
	-rm *.o;
