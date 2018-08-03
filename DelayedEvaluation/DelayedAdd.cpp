#include <functional>
#include <iostream>

template<class T>
class DelayedExecution
{
private:
	std::function<T()> m_func;

public:
	DelayedExecution(std::function<T()> func) : m_func(func)
	{
	}

	T Fetch()
	{
		return m_func();
	}
};

template<class T>
class Memoization
{
private:
	T const & (*m_subRoutine)(Memoization *);
	mutable T m_recordedFunc;
	std::function<T()> m_func;
	static T const & ForceSubRoutine(Memoization* d)
	{
		return d->DoRecording();
	}
	static T const & FetchSubroutine(Memoization * d)
	{
		return d->FetchRecording();
	}
	T const & FetchRecording()
	{
		return m_recordedFunc;
	}
	T const & DoRecording()
	{
		m_recordedFunc = m_func();
		m_subRoutine = &FetchSubroutine;
		return FetchRecording();
	}

public:
	Memoization(std::function<T()> func) : m_func(func),
		m_subRoutine(&ForceSubRoutine),
		m_recordedFunc(T())
	{
	}

	T Fetch()
	{
		return m_subRoutine(this);
	}
};


int fibonacci(int n)
{
	if (n <= 1)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

auto main() -> int
{
	int a = 10;
	int b = 5;
	DelayedExecution<int> Multiply([a, b]()
	{
		return a * b;
	});
	DelayedExecution<int> Division([a, b]()
	{
		return a / b;
	});

	int c = Multiply.Fetch();
	int d = Division.Fetch();

	int fibo40Result = 0;
	Memoization<int> fib40([]() {
		return fibonacci(40);
	});

	fib40.Fetch();
}