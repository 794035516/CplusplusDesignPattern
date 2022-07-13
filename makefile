OBJS =  runCPP.o   strategy.o    observer.o   decorator.o  command.o  adapter.o \
		prototype.o
	

main : main.cpp $(OBJS)
	g++ -g $^ -o $@

runCPP.o : runCPP.cpp 
	g++ -c $^

strategy.o : strategy.cpp
	g++ -c $^

observer.o : observer.cpp
	g++ -c $^

decorator.o : decorator.cpp
	g++ -c $^
	
command.o : command.cpp
	g++ -c $^	

adapter.o : adapter.cpp
	g++ -c $^

prototype.o : prototype.cpp
	g++ -c $^

clean:
	rm -f main *.o 
