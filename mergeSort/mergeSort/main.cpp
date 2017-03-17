//
//  main.cpp
//  mergeSort
//
//  Created by 张傲天 on 2017/2/15.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
char *GetMemory( void )
{
    char p[] = "hello world";
    return p;
}
//void Test( void )
//{
//    char *str = NULL;
//    str = GetMemory();
//    printf( "%s", str );
//}
void Test( void )
{
    char *str = (char *) malloc( 100 );
    strcpy( str, "hello" );
    free( str );
    printf(str);
}
void swap( int* p1,int* p2 )
{
    int p;
    p = *p1;
    *p1 = *p2;
    *p2 = p;
}
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
//    Test();
    int *p1 = new int;
    *p1 = 123;
    int *p2 = new int;
    *p2 = 456;
    swap(p1, p2);
    float f = 0;
    int t = 0;
    if (f == false) {
        printf("yes");
    }
    return 0;
}
