class RangeFreqQuery
{
private:
    map<int, vector<int>> idx;

public:
    RangeFreqQuery(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
            idx[arr[i]].push_back(i);
    }

    int query(int left, int right, int value)
    {
        return upper_bound(idx[value].begin(), idx[value].end(), right) - lower_bound(idx[value].begin(), idx[value].end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */