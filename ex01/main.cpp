#include "Serializer.hpp"
#include <iostream>

//	DOES NOT COMPILE
//	uintptr_t raw = static_cast<uintptr_t>(original);
//	Data* restored = static_cast<Data*>(raw);

int main()
{
	Data data;
	data.number = 28;

	Data* original = &data;
	uintptr_t raw = Serializer::serialize(original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "Original pointer : " << original << std::endl;
	std::cout << "Serialized value : " << raw << std::endl;
	std::cout << "Deserialized pointer : " << restored << std::endl;

	if (original == restored)
		std::cout << GREEN << "✅ Pointers are identical" << STD << std::endl;
	else
		std::cout << PINK << "❌ Pointers are different" << STD << std::endl;

	return 0;
}
