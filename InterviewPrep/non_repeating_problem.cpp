#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string firstNonRepeating(string stream) {

    vector<int> freq(26,0);
    queue<char> q;
    string result = "";

    for(char c : stream) {

        freq[c - 'a']++;
        q.push(c);

        while(!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if(q.empty())
            result += '#';
        else
            result += q.front();
    }

    return result;
}

int main() {
    string stream = "aabc";
    cout << firstNonRepeating(stream);
}