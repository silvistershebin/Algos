using namespace std;

class MinMaxStack {
public:
	vector<unordered_map<string, int>> minMaxStack = {};
	vector<int> stack = {};
  int peek() {
    return stack[stack.size() - 1];
  }

  int pop() {
		minMaxStack.pop_back();
    int t = stack[stack.size() - 1];
		stack.pop_back();
    return t;
  }

  void push(int number) {
    unordered_map<string, int> newMinMax = {{"min", number}, {"max", number}};
		if(minMaxStack.size()) {
			unordered_map<string, int> lastMinMax = minMaxStack[minMaxStack.size() - 1];
			newMinMax["min"] = min(lastMinMax["min"], number);
			newMinMax["max"] = max(lastMinMax["max"], number);
		}
		minMaxStack.push_back(newMinMax);
		stack.push_back(number);
  }

  int getMin() {
    return minMaxStack[minMaxStack.size() - 1]["min"];
  }

  int getMax() {
    return minMaxStack[minMaxStack.size() -1]["max"];
  }
};
