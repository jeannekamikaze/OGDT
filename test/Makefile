CFLAGS = -I../include
LFLAGS = -L../bin -lOGDTd -lboost_unit_test_framework

all: math-test timer-test

%.o: %.cc
	$(CXX) $(CFLAGS) -c $?

math-test: math.o
	$(CXX) $^ -o $@ $(LFLAGS)

timer-test: timer.cc
	$(CXX) $^ -o $@ $(LFLAGS)

clean:
	@rm -f math-test timer-test *.o