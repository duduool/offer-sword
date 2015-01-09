#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class CStack {
	public:
		CStack(void);
		~CStack(void);

		void push(const T& node);
		void pop(void);
		T& top(void);
	
	private:
		queue<T> queue1;
		queue<T> queue2;
};

template <typename T>
CStack::CStack(void)
{
}

template <typename T>
CStack::~CStack(void)
{
}

template <typename T>
void CStack::push(const T& node)
{

}

template <typename T>
void CStack::pop(void)
{

}

template <typename T>
T& CStack::top(void)
{
	
}

int main(int argc, const char *argv[])
{
	
	return 0;
}
