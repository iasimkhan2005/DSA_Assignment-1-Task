#include<iostream>
#include<stack>

using namespace std;
class stacks
{
private:
stack <int> mainStack;
stack <int> MinValue;

public:
	//Methods for mainStack
	void pushValueTO_main(int value) {
		mainStack.push(value);
	}
	void popvalueFROM_main() {
		if (!mainStack.empty())
		{
			mainStack.pop();
		}
		else
			cout << "Stack is Empty!!" << endl;
	}
	int mains_top() {
		return mainStack.top();
	}
	//Required
	int size() {
		return mainStack.size();
	}  //

	//Methods for MinValue
	void pushValueTo_MinValue(int value)
	{
		MinValue.push(value);
	}
	void popValueFROM_MinValue() {
		if (!MinValue.empty())
			MinValue.pop();
		else
			cout << "MinValue Stack is empty!!" << endl;
	}
	int MinValue_top() {
		return MinValue.top();
	}
	bool MinValue_Empty() {
		return MinValue.empty();
	}
	//Required
	int getMin() {
		if (!MinValue.empty())
			return MinValue.top();
		else 
		{
			cout << "No Minimum Value found Because MinValue Stack is empty!!!" << endl;
		
		}
	}
};

int main() {
	
	stacks s;

	//Inputs to stack from User
	while (true)
	{
		int value;
		cout << "Enter the value to be pushed to the stack (-1 for stop pushing): ";
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid Input!!" << endl;
		}
		else if (value == -1)
		{
			break;
		}
		else {
			if (s.MinValue_Empty()) {
				s.pushValueTo_MinValue(value);
			}
			s.pushValueTO_main(value);
			if (s.mains_top() < s.MinValue_top())
			{
				s.popValueFROM_MinValue();
				s.pushValueTo_MinValue(value);
			}
		
		}
			
	}
	//Final results

	cout << "Minimum element in the Stack: " << s.getMin() << endl;
	cout << "size of stack: " << s.size() << endl;

}