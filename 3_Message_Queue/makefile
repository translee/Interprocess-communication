CXX=g++
CXXFLAGS=-std=c++11 -Wall -O2

all:mainWrite mainRead

mainWrite:mainWrite.o
	$(CXX) $(CXXFLAGS) -o mainWrite mainWrite.o

mainRead:mainRead.o
	$(CXX) $(CXXFLAGS) -o mainRead mainRead.o

mainWrite.o:publicdef.h mainWrite.cpp
	$(CXX) $(CXXFLAGS) -c mainWrite.cpp

mainRead.o:publicdef.h mainRead.cpp
	$(CXX) $(CXXFLAGS) -c mainRead.cpp

.PHONY:clean

clean:
	rm -rf *.o
