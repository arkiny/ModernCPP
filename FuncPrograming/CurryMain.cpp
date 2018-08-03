#include <functional>
#include <iostream>

template<typename func, typename... Args>
auto Curry(func func, Args... args)
{
	return [=](auto... lastParam)
	{
		return func(args..., lastParam...);
	};
}

int areaRec(int length, int width, int height)
{
	return length * width * height;
}

auto main() -> int
{
	auto length5width4 = Curry(areaRec, 5, 4);
	
	auto length5 = Curry(areaRec, 5);

	auto result = length5width4(3);
	auto result2 = length5(3, 2);
}