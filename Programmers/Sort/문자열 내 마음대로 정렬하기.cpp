#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int criterion;

bool compare(string& a, string& b){
    if(a[criterion]==b[criterion]){
        return a<b;
    }
    return a[criterion]<b[criterion];
}

vector<string> solution(vector<string> strings, int n) {
    criterion = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}