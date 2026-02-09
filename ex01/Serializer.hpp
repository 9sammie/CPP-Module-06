#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#define STD			"\033[0m"
#define GREEN		"\033[38;5;34m\033[48;5;193m"
#define PINK		"\033[38;5;199m\033[48;5;225m"

#include <cstdint>
#include <string>

struct Data
{
	int			number;
};

class Serializer 
{
	private:

	Serializer();
	Serializer(const Serializer&);
	Serializer& operator = (const Serializer&);
	~Serializer();

	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};

#endif