//heterogenous_container c;
//c.push_back('a');
//c.push_back(1);
//c.push_back(2.0);
//c.push_back(3);
//c.push_back(std::string("foo"));

#include <functional>
#include <variant>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>


struct PrintVisitor
{
	template <class T>
	void operator()(T&& _in) { std::cout << _in; }
};

auto main() -> int
{
	std::variant<int, double, std::string> myVariant;
	myVariant = 1; // initially it's an integer

	std::vector<std::variant<int, double, std::string>> VarientVec;
	VarientVec.emplace_back("a");
	VarientVec.emplace_back(1);
	VarientVec.emplace_back(2.0);

	auto VisitPrinter = [](auto&& in)
	{
		std::cout << in << std::endl;
	};

	// print them
	for (auto& nextVariant : VarientVec)
	{
		std::visit(VisitPrinter, nextVariant);
		std::cout << " ";
	}

	system("pause");
}