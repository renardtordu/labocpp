Test7: Test7.cpp OptionException.o PasswordException.o Exception.o Person.o Actor.o Client.o Employee.o Model.o Car.o Option.o XmlFileSerializerException.o 
	g++ Test7.cpp OptionException.o PasswordException.o Exception.o Person.o Actor.o Client.o Employee.o Model.o Car.o Option.o XmlFileSerializerException.o -o Test7
OptionException.o: OptionException.cpp OptionException.h
	g++ OptionException.cpp -c 
PasswordException.o: PasswordException.cpp PasswordException.h
	g++ PasswordException.cpp -c 
Exception.o: Exception.cpp Exception.h
	g++ Exception.cpp -c 
Person.o: Person.cpp Person.h
	g++ Person.cpp -c
Actor.o: Actor.cpp Actor.h
	g++ Actor.cpp -c
Client.o: Client.cpp Client.h
	g++ Client.cpp -c
Employee.o: Employee.cpp Employee.h PasswordException.h
	g++ Employee.cpp -c
Model.o: Model.cpp Model.h
	g++ Model.cpp -c
Car.o: Car.cpp Car.h OptionException.h
	g++ Car.cpp -c
Option.o: Option.cpp Option.h OptionException.h
	g++ Option.cpp -c
XmlFileSerializerException.o: XmlFileSerializerException.cpp XmlFileSerializerException.h
	g++ XmlFileSerializerException.cpp -c


clean: 
	rm *.o