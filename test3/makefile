Test3v1: Test3.cpp Model.o Car.o Option.o
	g++ Test3.cpp Model.o Car.o Option.o -o Test3v1

Model.o: Model.cpp Model.h
	g++ Model.cpp -c
Car.o: Car.cpp Car.h
	g++ Car.cpp -c
Option.o: Option.cpp Option.h
	g++ Option.cpp -c

clean: 
	rm *.o