#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>


typedef struct s_Data {
	int x;
	short a;
	double j;
} t_Data;

typedef s_Data Data;

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& obj);
		Serializer& operator=(const Serializer& obj);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

// what is reinterpreter cast 


#endif