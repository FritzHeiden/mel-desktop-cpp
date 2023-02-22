CC=g++
LIBS=`pkg-config gtkmm-4.0 --cflags --libs`

gtk-app: simple.o
	$(CC) -std=c++17 -o app simple.o $(LIBS)

simple.o: src/simple.cc
	$(CC) -std=c++17 -c src/simple.cc $(LIBS)

clean:
	rm *.o app
