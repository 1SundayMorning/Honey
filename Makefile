MODULES = -lsfml-audio -lsfml-system
CFLAGS = -std=c++11

all: sound


sound: main.o envelope.o
	$(CXX) $(CFLAGS) envelope.o main.o -o sound $(MODULES)

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

envelope.o: envelope.cpp
	$(CXX) $(CFLAGS) -c envelope.cpp

clean:
	rm -f *.o sound
