CFLAGS = -fpermissive
LFLAGS = -lOGDTd -ldl

all: program mylib

clean:
	@rm -f program libmylib.so *.o

program: program.o
	$(CXX) $^ -o $@ $(LFLAGS)

%.o: %.cc
	$(CXX) $(CFLAGS) -c $?

mylib: mylib.cc
	$(CXX) $(CFLAGS) -fPIC -c mylib.cc
	$(CXX) -shared mylib.o -o lib$@.so
