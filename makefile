CC=g++
ARGS=`pkg-config gtkmm-4.0 --cflags --libs`
OBJDIR=obj
SRCDIR=src
SRC=$(shell find $(SRCDIR) -name '*.cc')
OBJ=$(SRC:$(SRCDIR)/%.cc=$(OBJDIR)/%.o)

$(info $(OBJ))

gtk-app: $(OBJ)
	$(CC) -std=c++17 -o app $^ $(ARGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	mkdir -p "$(shell dirname $@)"; $(CC) -std=c++17 -c $^ -o $@ $(ARGS)

clean:
	rm -r $(OBJDIR) app
