CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic -g -fsanitize=address,undefined

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

main: main.o math.o
	$(CXX) $(CXXFLAGS) main.o math.o -o main

main.o: main.cpp math.h
	$(CXX) $(CXXFLAGS) -c main.cpp

math.o: math.cpp math.h
	$(CXX) $(CXXFLAGS) -c math.cpp

clean:
	rm -f *.o main
