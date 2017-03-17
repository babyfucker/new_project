//
//  main.cpp
//  shell_sort
//
//  Created by 张傲天 on 2017/2/15.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
//    vector<int> array_ = {13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10};
    vector<int> a = {1, 4, 3, 7, 9, 6, 5, 2, 8};
    int gap = (int)a.size() / 2;
    int i,j,n = (int)a.size();
//    while (gap > 0) {
//        for (int i = gap; i < array.size(); i++) {
//            for (int j = i; 0 < j; j -= gap) {
//                if (array[j - gap] > array[j]) {
//                    swap(array[j - gap],array[j]);
//                } else {
//                    break;
//                }
//            }
//        }
//        gap = gap / 2;
//    }
//    for (gap = n / 2; gap > 0; gap /= 2)
//        for (j = gap; j < n; j++)//从数组第gap个元素开始
//            if (a[j] < a[j - gap])//每个元素与自己组内的数据进行直接插入排序
//            {
//                int temp = a[j];
//                int k = j - gap;
//                while (k >= 0 && a[k] > temp)
//                {
//                    a[k + gap] = a[k];
//                    k -= gap;
//                }
//                a[k + gap] = temp;
//            }
    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
                swap(a[j], a[j + gap]);
    return 0;
}
