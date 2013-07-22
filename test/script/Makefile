CFLAGS = -fpermissive
LFLAGS = -lOGDTd -ldl

all: program

clean:
	@rm -f program libmylib.so *.o

program: program.o
	$(CXX) $^ -o $@ $(LFLAGS)

%.o: %.cc
	$(CXX) $(CFLAGS) -c $?
