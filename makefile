PROG1 = Star
PROG2 = Planet
PROG3 = lab3
FLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: $(PROG3)

$(PROG3): $(PROG1).o $(PROG2).o $(PROG3).o
	g++ $(FLAGS) $(PROG1).o $(PROG2).o $(PROG3).o -o $(PROG3)

$(PROG1).o: $(PROG1).cpp
	g++ $(FLAGS) -c $(PROG1).cpp -o $(PROG1).o

$(PROG2).o: $(PROG2).cpp
	g++ $(FLAGS) -c $(PROG2).cpp -o $(PROG2).o

$(PROG3).o: $(PROG3).cpp
	g++ $(FLAGS) -c $(PROG3).cpp -o $(PROG3).o

run: all
	./$(PROG3)

clean: all
	rm *.o $(PROG3)

memcheck: all
	valgrind ./$(PROG3)

commit: clean
	git commit -a 
	git push
