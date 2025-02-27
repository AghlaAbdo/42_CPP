#include "Serializer.hpp"

int main(void)
{
	std::cout << "------- First example data1 -------\n" << std::endl;
	
	Data *data1 = new Data;
	data1->fstName = "Abdo";
	data1->lstName = "Don";
	data1->age = 25;

	std::cout << "Values in original pointer:" << std::endl;
	std::cout << "Address: " << data1 << "\n"
		<< data1->fstName << "\n"
		<< data1->lstName << "\n"
		<< data1->age << std::endl;

	Data	*restoredData = Serializer::deserialize(Serializer::serialize(data1));

	std::cout << "\nValues in restored pointer:" << std::endl;
	std::cout << "Address: " << restoredData << "\n"
		<< restoredData->fstName << "\n"
		<< restoredData->lstName << "\n"
		<< restoredData->age << std::endl;

	std::cout << "\n------- Second example data2 -------\n" << std::endl;

	Data	*data2 = new Data;
	data2->fstName = "Mike";
	data2->lstName = "Junior";
	data2->age = 30;

	std::cout << "Values in original pointer:" << std::endl;
	std::cout << "Address: " << data2 << "\n"
		<< data2->fstName << "\n"
		<< data2->lstName << "\n"
		<< data2->age << std::endl;

	uintptr_t	raw = Serializer::serialize(data2);
	Data	*restoredData2 = Serializer::deserialize(raw);

	std::cout << "\nValues in restored pointer:" << std::endl;
	std::cout << "Address: " << restoredData2 << "\n"
		<< restoredData2->fstName << "\n"
		<< restoredData2->lstName << "\n"
		<< restoredData2->age << std::endl;

	delete data1;
	delete data2;
}
