#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> answers(temperatures.size(), 0);
    for(int i = 0; i < temperatures.size() - 1; i++) {
        for(int j = i + 1; j < temperatures.size(); j++) {
            if(temperatures[j] > temperatures[i]) {
                answers[i] = j - i;
                break;
            }
        }
    }
    return answers;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);
    
    cout << "Daily Temperatures: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
