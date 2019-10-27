#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using std::vector;
using std::function;
using std::transform;
using std::back_inserter;
using std::cout;
using std::endl;

typedef function<double(double)> HyperbolicFunc;

vector<HyperbolicFunc> func = {
		static_cast<double(*)(double)>(sinh),
		static_cast<double(*)(double)>(cosh),
		static_cast<double(*)(double)>(tanh),
		[](double x) {
		return x * x;
		}
	};

vector<HyperbolicFunc> inversefunc = {
		static_cast<double(*)(double)>(asinh),
		static_cast<double(*)(double)>(acosh),
		static_cast<double(*)(double)>(atanh),
		[](double x) {
		return exp(log(x)/2);
		}
	};

template <typename A, typename B, typename C>
function<C(A)> compose(
	function<C(B)> f,
	function<B(A)> g)
{
	return [f, g](A x) 
	{
		return (f(g(x)));
	};
}

//auto main() -> int
//{
//	vector<HyperbolicFunc> ComposedFuncs;
//
//	vector<double> nums;
//	for (int i = 1; i <= 5; ++i)
//		nums.push_back(i * 0.2);
//
//	transform(
//		begin(inversefunc),
//		end(inversefunc),
//		begin(func),
//		back_inserter(ComposedFuncs),
//		compose<double, double, double>);
//
//	for (auto num : nums)
//	{
//		for (auto func : ComposedFuncs)
//		{
//			cout << "f(g(" << num << ")) = " << func(num) << endl;
//			cout << "--------------" << endl;
//		}
//	}
//	
//	system("pause");	
//	return 0;
//}