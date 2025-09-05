#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string line, char delimiter) {
    vector<string> res;
    string temp;
    for(char c : line){
        if(c == delimiter){
            if(temp.size()) res.push_back(temp);
            temp = "";
        }else{
            temp += c;
        }
    }
    if(temp.size()) res.push_back(temp);
    return res;
}
int main() {
    string line;
    getline(cin, line);
    string delim;
    getline(cin, delim);
    for (string e : split(line, delim[0])) {
        cout << '(' << e << ')';
    }
}