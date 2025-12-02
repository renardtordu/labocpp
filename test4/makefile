test4: Test4.o Person.o Actor.o Client.o Employee.o
	g++ Test4.o Person.o Actor.o Client.o Employee.o -o test4
Test4.o: Test4.cpp Person.h
	g++ Test4.cpp -c
Person.o: Person.cpp Person.h
	g++ Person.cpp -c
Actor.o: Actor.cpp Actor.h
	g++ Actor.cpp -c
Client.o: Client.cpp Client.h
	g++ Client.cpp -c
Employee.o: Employee.cpp Employee.h
	g++ Employee.cpp -c
