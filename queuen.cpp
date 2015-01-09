#include <iostream>
#include <stack>
#include <exception>

using namespace std;

template <typename T> 
class CQueue {
	public:
		CQueue(void);
		~CQueue(void);

		void appendTail(const T& node);
		T& deleteHead(void);

	private:
		stack<T> stack1;
		stack<T> stack2;
};

template <typename T>
CQueue<T>::CQueue(void)
{
}

template <typename T>
CQueue<T>::~CQueue(void)
{
}

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template <typename T>
T& CQueue<T>::deleteHead(void)
{
	if (stack2.size() <= 0) {
		while (stack1.size() > 0) {
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0) 
		throw new exception();

	T& head = stack2.top();
	stack2.pop();

	return head;
}

int main(int argc, const char *argv[])
{
	CQueue<int> queue;
	
	queue.appendTail(1);
	queue.appendTail(2);
	queue.appendTail(3);
	queue.appendTail(4);
	queue.appendTail(5);
	
	cout << "Hello World!" << endl;
	
	for (int i = 0; i < 5; i++)
		cout << queue.deleteHead() << endl;

	return 0;
}
