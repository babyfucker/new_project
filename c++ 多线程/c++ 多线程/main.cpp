//
//  main.cpp
//  c++ 多线程
//
//  Created by 张傲天 on 2017/2/18.
//  Copyright © 2017年 张傲天. All rights reserved.
//

//文件名：test.cpp

#include <iostream>
#include <thread>
//#include <cstdlib>
//#include <pthread.h>

using namespace std;
//以下是老旧的多线程开发

//#define NUM_THREADS     2
//
//struct thread_data{
//    int  thread_id;
//    string message;
//    int i;
//};
//static int j;
//void *PrintHello(void *threadarg)
//{
//    struct thread_data *my_data;
//    
//    my_data = (struct thread_data *) threadarg;
//    
//    cout << "Thread ID : " << my_data->thread_id;
//    cout << " Message : " << my_data->message << endl;
//    for (int k = 0; k < 100; k++) {
//        j++;
//        if (k == 99) {
//            cout<<"j is"<<j<<endl;
//        }
//    }
//    pthread_exit(NULL);
//}
//
//int main ()
//{
//    pthread_t threads[NUM_THREADS];
//    struct thread_data td[NUM_THREADS];
//    int rc;
//    int i;
//    
//    for( i=0; i < NUM_THREADS; i++ ){
//        cout <<"main() : creating thread, " << i << endl;
//        td[i].thread_id = i;
//        td[i].message = "This is message";
//        rc = pthread_create(&threads[i], NULL,
//                            PrintHello, (void *)&td[i]);
//        if (rc){
//            cout << "Error:unable to create thread," << rc << endl;
//            exit(-1);
//        }
//    }
//    cout<<"j:"<<j<<endl;
//    pthread_exit(NULL);
//}

//以下是c++ 11 所支持的多线程
int j = 0;
class background_task
{
public:
    void operator()() const
    {
        do_something();
        do_something_else();
    }
    void do_something() const {
        for (int k = 0; k < 50; k++) {
            j++;
        }
    }
    void do_something_else() const {
        
    }
};

background_task f;
thread my_thread(f);
int main() {
    my_thread.join();
//    my_thread.detach();
    cout<<"j: "<<j<<endl;
}
