class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        vector<int> stack;
        int j = 0;

        for (int i = 0; i < pushed.size(); i++) {

            stack.push_back(pushed[i]);

            while (!stack.empty() && stack.back() == popped[j]) {

                stack.pop_back();
                j++;

            }
        }

        if (stack.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
