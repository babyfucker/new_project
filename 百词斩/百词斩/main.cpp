
//时间复杂度为O(n²)
//空间复杂度为O(n)
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int main() {
    string s;//储存原始字符串数组
    vector<char> c;//储存展开后的字符串数组
    vector<int> IP_address;//储存IP地址
    int count;//储存IP地址的个数
    cin>>s;
    //展开字符串数组
    for (int i = 0; i < s.size();i ++) {
        if (s[i] < 97) {
            if (s[i + 1] < 97) {
                for (int j = 0; j < ((s[i] - '0') * 10 + s[i + 1] - '0'); j ++) {
                    c.push_back(s[i + 2]);
                }
                i ++;
            } else {
                for (int j = 0; j < s[i] - '0'; j ++) {
                    c.push_back(s[i + 1]);
                }
            }
        } else {
            if (s[i + 1] >= 97) {
                c.push_back(s[i + 1]);
            }
        }
    }
    //计算IP地址
    count =(int)(c.size() / 8);
    for (int k = 0; k < count; k ++) {
        IP_address.push_back(0);
        for (int i = 0; i < 8; i ++) {
            if (c[c.size() - 1] == 'b') {
                IP_address[k] = IP_address[k] + pow(2,i);
            }
            c.pop_back();
        }
    }
    //输出结果
    for (int i = 0; i < IP_address.size(); i ++) {
        if(i != IP_address.size() - 1)
            cout<<IP_address[IP_address.size() - i - 1]<<".";
        else
            cout<<IP_address[IP_address.size() - i - 1];
    }
    return 0;
}
