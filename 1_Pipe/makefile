CXX=g++
CXXFLAGS=-std=c++11 -O2 -Wall

main:main.o
	$(CXX) $(CXXFLAGS) -o main main.o

main.o:main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

.PHONY:clean

clean:
	rm -rf *.o
