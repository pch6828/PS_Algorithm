class BrowserHistory
{
private:
    stack<string> prev, next;

public:
    BrowserHistory(string homepage)
    {
        prev.push(homepage);
    }

    void visit(string url)
    {
        prev.push(url);
        next = stack<string>();
    }

    string back(int steps)
    {
        while (prev.size() > 1 && steps--)
        {
            next.push(prev.top());
            prev.pop();
        }
        return prev.top();
    }

    string forward(int steps)
    {
        while (next.size() && steps--)
        {
            prev.push(next.top());
            next.pop();
        }
        return prev.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */