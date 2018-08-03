#include <functional>
#include <iostream>
#include <vector>

// 0 개일 때 경우를 Provide 해아햠
void print(void)
{

}

template <typename First, typename ...Rest>
void print(const First& first, Rest&&... Args )
{
	std::cout << first << std::endl;
	print(Args...);
}

auto main() -> int
{
	auto variadic_generic_lambda = [](auto... param) {};

	std::function<void(int, int)> func = variadic_generic_lambda;
	std::vector<std::function<void(int, int)>> vec;
	vec.push_back(func);

	return 0;
}