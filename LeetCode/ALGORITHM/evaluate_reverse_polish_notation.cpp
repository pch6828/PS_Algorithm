class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> exp;

        for (string t : tokens)
        {
            int a, b;
            if (t == "+")
            {
                a = exp.top();
                exp.pop();
                b = exp.top();
                exp.pop();

                exp.push(a + b);
            }
            else if (t == "-")
            {
                a = exp.top();
                exp.pop();
                b = exp.top();
                exp.pop();

                exp.push(b - a);
            }
            else if (t == "*")
            {
                a = exp.top();
                exp.pop();
                b = exp.top();
                exp.pop();

                exp.push(a * b);
            }
            else if (t == "/")
            {
                a = exp.top();
                exp.pop();
                b = exp.top();
                exp.pop();

                exp.push(b / a);
            }
            else
                exp.push(stoi(t));
        }
        return exp.top();
    }
};