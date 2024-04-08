class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int ans = students.size();
        bool take = false;
        queue<int> st, sa;

        for (int i : students)
        {
            st.push(i);
        }
        for (int i : sandwiches)
        {
            sa.push(i);
        }

        do
        {
            take = false;
            for (int i = 0; i < ans; i++)
            {
                if (st.front() == sa.front())
                {
                    take = true;
                    st.pop();
                    sa.pop();
                    ans--;
                    break;
                }
                else
                {
                    st.push(st.front());
                    st.pop();
                }
            }
        } while (take);

        return ans;
    }
};