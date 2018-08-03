#include <iostream>

auto main() -> int
{
	auto a = 1;
	auto b = 2;

	//auto mutablelambada = [a, b]() {
	//	a = 3;
	//	b = 1;
	//};

	auto mutablelambada = [a, b]() mutable {
		a = 3;
		b = 1;
	}; // making side effect

	mutablelambada();

	std::cout << a << "," << b << std::endl;

	auto captureInit = [I = a, J = b]()
	{
		return I + J;
	};

	std::cout << captureInit() << std::endl;

	// auto param
	auto Max = [](auto& A, auto& B) {
		return A > B ? A : B;
	};

	std::cout << Max(a, b) << std::endl;


	system("pause");
}