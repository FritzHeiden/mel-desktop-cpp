CC=g++
ARGS=`pkg-config gtkmm-4.0 --cflags --libs`

gtk-app: *.o
	$(CC) -std=c++17 -o app $^ $(ARGS)

%.o: src/%.cc
	$(CC) -std=c++17 -c $^ $(ARGS)

clean:
	rm *.o app
