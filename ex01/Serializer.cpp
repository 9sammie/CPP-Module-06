#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {}

Serializer& Serializer::operator = (const Serializer& other)
{
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
	if (ptr)
		return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t number)
{
	if (number)
		return (reinterpret_cast<Data*>(number));
}
