main : main.cpp strategy.o
	g++  $^ -o $@

strategy.o : strategy.cpp
	g++ -c $^


clean:
	rm -f main *.o 
