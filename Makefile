test : test.o board.o hint.o
	g++ -Wall -O2 -std=c++11 test.o board.o hint.o -o test

test.o : test.cpp board.h hint.h
	g++ -Wall -O2 -std=c++11 board.h hint.h test.cpp -c test.cpp

hint.o : hint.cpp hint.h
	g++ -Wall -O2 -std=c++11 hint.cpp hint.h -c hint.cpp

board.o : board.cpp board.h
	g++ -Wall -O2 -std=c++11 board.h board.cpp -c board.cpp

clean: 
	\rm *.o test
