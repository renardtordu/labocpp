test2av1: Test2a.cpp Model.o Car.o
	g++ Test2a.cpp Model.o Car.o -o test2av1

Model.o: Model.cpp Model.h
	g++ Model.cpp -c
Car.o: Car.cpp Car.h
	g++ Car.cpp -c

clean: 
	rm *.o