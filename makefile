main : main.cpp runCPP.o strategy.o observer.o
	g++  $^ -o $@

runCPP.o : runCPP.cpp 
	g++ -c $^

strategy.o : strategy.cpp
	g++ -c $^

observer.o : observer.cpp
	g++ -c $^


clean:
	rm -f main *.o 
