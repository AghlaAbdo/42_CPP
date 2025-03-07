#include "MutantStack.hpp"

int main()
{
	std::cout << "----- Test copy constructor: -----" << std::endl;
	{
		MutantStack<double>	mstack1;
		mstack1.push(20);
		MutantStack<double>	mstack2(mstack1);
		mstack1.top() = 50;
		std::cout << "value in mstack1: " << mstack1.top() << std::endl;
		std::cout << "value in mstack2: " << mstack2.top() << std::endl;
	}

	std::cout << "\n----- Test assignment operator: -----" << std::endl;
	{
		MutantStack<double>	mstack1;
		mstack1.push(20.65);
		MutantStack<double>	mstack2 = mstack1;
		mstack1.top() = 50.48;
		std::cout << "value in mstack1: " << mstack1.top() << std::endl;
		std::cout << "value in mstack2: " << mstack2.top() << std::endl;
	}

	std::cout << "\n----- Test iterate through string elements: -----" << std::endl;
	{
		MutantStack<std::string>	mstack;
		mstack.push("random");
		mstack.push("stuff");
		mstack.push("goes");
		mstack.push("here");

		MutantStack<std::string>::iterator	it = mstack.begin();
		MutantStack<std::string>::iterator	ite = mstack.end();
		while (it != ite) {
			std::cout << *it << std::endl;
			it++;
		}

		std::cout << "----- Remove last 2 elements: -----" << std::endl;
		mstack.pop();
		mstack.pop();
		it = mstack.begin();
		ite = mstack.end();
		while (it != ite) {
			std::cout << *it << std::endl;
			it++;
		}
	}
	
	std::cout << "\n----- Test some other std::stack methods: -----" << std::endl;
	{
		MutantStack<float>	mstack1;
		std::cout << "is stack empty: " << mstack1.empty() << std::endl;
		mstack1.push(12.56);
		mstack1.push(10.45);
		mstack1.push(65.45);
		std::cout << "is stack empty after adding elements: " << mstack1.empty() << std::endl;
		std::cout << "size of mstack1: " << mstack1.size() << std::endl;
	}

	std::cout << "\n----- Test provided in the subject: -----" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	return(0);
}
