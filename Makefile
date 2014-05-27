CXX = g++

all: compile test checkstyle

compile: TetrisMain TetrisTest

%Main: %Main.o %.o
	$(CXX) -o $@ $^ -lncurses

%Test: %Test.o %.o
	$(CXX) -o $@ $^ -lgtest -lgtest_main -pthread -lncurses

%.o: %.cpp
	$(CXX) -c $^

test: compile
	./TetrisTest

checkstyle:
	python ../cpplint.py *.cpp *.h

clean:
	rm -f *.o
	rm -f TetrisMain
	rm -f TetrisTest
