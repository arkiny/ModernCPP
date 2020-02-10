#pragma once

template <typename T>
auto Somefunc(T param)
{
    return param;
}

template <typename T>
auto SomefuncInitList(std::initializer_list<T> params)
{
    return params;
}

//template <typename T>
//auto SomefuncInitListReturnFailed(std::initializer_list<T> params)
//{
//    return { 10, 11, 12 }; // Deduction Failed!
//}

auto SomeFuncInitListReturnSuccess()
{
    return std::initializer_list<int>{10, 11, 12};
}


auto Test()
{
    auto i = 27; // int
    auto i2(27); // int
    auto i3 = { 27 }; // std::initializer_list
    auto i4{ 27 }; // int
    //auto i4 = { 27, 3.0f }; // error

    //auto Something = Somefunc({ 10, 11 }); // no type deduction
    auto Somethinginit = SomefuncInitList({ 10, 11 });
}