CXX=g++
CXXFLAGS=-std=c++11 -O2 -Wall

all:mainwrite mainread

mainwrite:publicdef.h mainwrite.cpp
	$(CXX) $(CXXFLAGS) -o mainwrite mainwrite.cpp

mainread:publicdef.h mainread.cpp
	$(CXX) $(CXXFLAGS) -o mainread mainread.cpp

.PHONY:clean

clean:
	rm -rf *.o
