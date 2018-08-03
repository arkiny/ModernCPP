#include <iostream>
#include <typeinfo>
#include <array>
#include <algorithm>

template<typename I, typename J>
auto add(I i, J j) -> decltype(i + j)
{
	return i + j;
}

template<typename I, typename J>
auto Comp(I A, J B) -> decltype(A > B)
{
	return A > B;
}

auto Comparer(int a, int b)
{
	return a > b;
}

auto main() -> int
{
	std::cout << "[auto.cpp]" << std::endl;
	auto a = 1;
	auto b = 1.0;
	auto c = a + b;
	auto d = { b, c };

	std::cout << typeid(a).name() << std::endl;
	std::cout << typeid(b).name() << std::endl;
	std::cout << typeid(c).name() << std::endl;
	std::cout << typeid(d).name() << std::endl;
	system("pause");

	auto ret = add<int, double>(4, 5.0);
	std::cout << ret << "," << typeid(ret).name() << std::endl;
	system("pause");

	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto i = std::begin(arr), e = std::end(arr); i != e ; ++i)
	{
		std::cout << *i << ";" << std::endl;
	}

	system("pause");

	std::array<int, 10> stdArray = { 0,1,2,3,4,5,6,7,8,9 };
	stdArray.at(9);

	system("pause");
	auto f = 11;
	auto g = 12;
	auto Restul = Comp<decltype(f),decltype(g)>(f, g);

	std::sort(std::begin(stdArray), std::end(stdArray), Comp<decltype(stdArray.at(0)), decltype(stdArray.at(0))>);

	for (auto v : stdArray)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	system("pause");

	return 0;
}