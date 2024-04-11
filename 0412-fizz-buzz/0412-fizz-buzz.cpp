class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int d = 1; d <= n; ++d) {
            string str;
            if (d % 3 == 0)
                str += "Fizz";
            if (d % 5 == 0)
                str += "Buzz";
            if (str.empty())
                str = to_string(d);
            result.push_back(str);
        }
        return result;
    }
};
