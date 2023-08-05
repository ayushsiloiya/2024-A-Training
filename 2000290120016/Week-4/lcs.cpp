/*
    Code of Longest Common Subsequence
    
    By 
    Ajay Varshney
    2000290120016
    CS 6A

*/

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::max;

int lcs(string s1, string s2, int i1, int i2) {
    if(i1 == -1 || i2 == -1) return 0;

    if(s1[i1] == s2[i2]) return 1 + lcs(s1, s2, i1-1, i2-1);
    return max(lcs(s1, s2, i1-1, i2), lcs(s1, s2, i1, i2-1));
}

int main() {
    string s1 = "longest";
    string s2 = "loncommongessubsequencet";

    cout << "String 1 : " << s1 << endl;
    cout << "String 2 : " << s2 << endl;
    cout << "The length of longest common subsequence : \n" << lcs(s1, s2, s1.size()-1, s2.size()-1);
    return 0;
}