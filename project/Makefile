.PHONY: clean all

CFLAGS = -Wall -O2 --std=c++20

targets = bint
objects = main.o bint.o
sources = main.cpp bint.cpp

all: $(targets)
	@./$(targets)
	@rm -f *.o bint

$(targets): $(objects)
	@c++ $(CFLAGS) main.o bint.o -o $@

%.o: %.cpp
	@c++ $(CFLAGS) -c $< -o $@

clean: 
	@rm -f *.o bint