OBJS =  runCPP.o \
		strategy.o \
		observer.o \
		decorator.o \
		main.o:w

main : main.cpp $(OBJS)
	g++ $^ -o $@

runCPP.o : runCPP.cpp 
	g++ -c $^

strategy.o : strategy.cpp
	g++ -c $^

observer.o : observer.cpp
	g++ -c $^

decorator.o : decorator.cpp
	g++ -c $^


clean:
	rm -f main *.o 
