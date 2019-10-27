#include <iostream>

void incr(int& value)
{
    std::cout << "increment with lvalue reference" << std::endl;
    ++value;
}

void incr(int&& value)
{
    std::cout << "increment with rvalue reference" << std::endl;
    ++value;
}

class MoveSementics
{
public:
    MoveSementics(int _a, float _b) : move_(_a), move2_(_b)
    {}

    MoveSementics(MoveSementics&& src) noexcept
    {
        move_ = src.move_;
        move2_ = src.move2_;
        src.move_ = 0;
        src.move2_ = 0;
    }

    MoveSementics& operator=(MoveSementics&& rhs) noexcept 
    {
        if (this == &rhs)
        {
            return *this;
        }

        move_ = rhs.move_;
        move2_ = rhs.move2_;

        rhs.move_ = 0;
        rhs.move2_ = 0;

        return *this;
    }

private:
    int move_ = 2;
    float move2_ = 3.0f;
};

MoveSementics CreateObject()
{
    return MoveSementics( 2, 4.0f );
}


int main()
 {
    int a = 10, b = 20;
    incr(a); // lvalue;
    incr(a + b); // rvalue;
    incr(3); // rvalue;
    incr(std::move(b)); // rvalue

    //int& i = 2; // cannot compile of course;
    //int a = 2, b = 3;
    //int& j = a + b;// cannot compile of course

    int&& i = 2;
    int c = 2, d = 3;
    int&& j = c + d;

    incr(j);


    MoveSementics s(3, 4.0f); 
    s = CreateObject(); // move operator

    MoveSementics m(std::move(s)); // move constructor

    return 0;
 }