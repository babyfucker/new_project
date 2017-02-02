//
//  main.cpp
//  examiqiyi
//
//  Created by 张傲天 on 2016/9/27.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#include <iostream>
using namespace std;
int func(int);
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin>>n;
    int z=1;
    if (n<=30&&n>=1) {
        int x=n/3;
        int y=n/2;
        if (x<3)
            cout<<z;
        else {
            if(n%3==1)
            {
                z=z+x+1;
            }
            if(n%3==2)
            {
                z=z+x+1;
                z=z+(x+1)*(x+2)/2;
                
            }
        }
        if(x==3)
            cout<<4;
        if(x==4)
            cout<<4;
        if(x==5)
            cout<<6;
    }
        
    return 0;
}
