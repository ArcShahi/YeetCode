// 155. Min Stack

#include <vector>


class MinStack {
public:
	MinStack(int capacity = 100)
	{
		buffer.reserve(capacity);
		minStack.reserve(capacity);
	}

	void push(int val)
	{
		buffer.push_back(val);
		if (minStack.empty() || val <= minStack.back()) 
		{
			minStack.push_back(val);
		}
	}

	void pop() 
	{
		if (buffer.back() == minStack.back()) {
			minStack.pop_back();
		}
		buffer.pop_back();
	}

	int top() {
		return buffer.back();
	}

	int getMin() {
		return minStack.back();
	}

private:
	std::vector<int> buffer;
	std::vector<int> minStack;
};
