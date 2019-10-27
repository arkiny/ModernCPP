#include <tuple>
#include <string>
#include <iostream>

auto GetData(int DataId)
{
	if (DataId == 1)
		return std::make_tuple(0, "Chlie", false);
	else if (DataId == 2)
		return std::make_tuple(1, "Bryan", true);
	else
		return std::make_tuple(2, "Zoey", false);
}


auto main() ->int
{
	int i;
	std::string n;
	bool b;
	tie(i, n, b) = GetData(2);

}