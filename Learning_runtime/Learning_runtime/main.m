//
//  main.m
//  Learning_runtime
//
//  Created by 张傲天 on 2016/10/16.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import <>
#import <objc/message.h>

@interface Person : NSObject

-(void) eat;

+(void) drink;

@end

@implementation Person

-(void) eat {
    NSLog(@"eat");
}

+(void) drink {
    NSLog(@"drink");
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {

        Person *p=[[Person alloc]init];
        [p eat];
        [p performSelector:@selector(eat)];//SEL：方法编号，根据方法编号就可以找到对应方法的实现
        objc_msgSend(p, @selector(eat));//performSelector本质即为运行时，发送消息，谁做事情就调用谁
//        objc_msgSend(p, @selector(eat:),10);//带参数版本 运行的时候会出错,编译时不出错
        
        
        [Person drink];
        [[Person class] performSelector:@selector(drink)];
        objc_msgSend([Person class], @selector(drink));// Person只是表示一个类名，并不是一个真实的对象。只要是方法必须要对象去调用。
        // RunTime 调用类方法同样，类方法也是类对象去调用，所以需要获取类对象，然后使用类对象去调用方法。
        
        
        
    }
    return 0;
}
