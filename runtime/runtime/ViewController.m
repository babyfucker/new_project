//
//  ViewController.m
//  runtime
//
//  Created by 张傲天 on 2016/10/16.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#import "ViewController.h"
#import <objc/runtime.h>
#import <objc/message.h>
@interface ViewController ()

@end

@interface Person : NSObject

//-(void) eat;

@end

@implementation Person

// void(*)()
// 默认方法都有两个隐式参数，
void eat(id self,SEL sel)
{
    NSLog(@"%@ %@",self,NSStringFromSelector(sel));
}

// 当一个对象调用未实现的方法，会调用这个方法处理,并且会把对应的方法列表传过来.
// 刚好可以用来判断，未实现的方法是不是我们想要动态添加的方法
+ (BOOL)resolveInstanceMethod:(SEL)sel
{
    
    if (sel == NSSelectorFromString(@"eat")) {
        // 动态添加eat方法
        
        // 第一个参数：给哪个类添加方法
        // 第二个参数：添加方法的方法编号
        // 第三个参数：添加方法的函数实现（函数地址）
        // 第四个参数：函数的类型，(返回值+参数类型) v:void @:对象->self :表示SEL->_cmd
        class_addMethod(self, sel,(IMP) eat, "v@:");
        
    }
    
    return [super resolveInstanceMethod:sel];
}


@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    UIImage *img = [UIImage imageNamed:@"123"];
    
    Person *p = [[Person alloc]init];
    
    [p performSelector:@selector(eat)];
//    [p eat];
//    UIImage
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    
//    UIImage *img = [UIImage imageNamed:@"123"];
}


@end

@implementation UIImage (image)//类别

+ (void)load
{
    // 交换方法
    
    // 获取imageWithName方法地址
    Method imageWithName = class_getClassMethod([self class], @selector(imageWithName:));
    
    // 获取imageWithName方法地址
    Method imageName = class_getClassMethod([self class], @selector(imageNamed:));
    
    // 交换方法地址，相当于交换实现方式
    method_exchangeImplementations(imageWithName, imageName);
    
}

+ (instancetype)imageWithName:(NSString *)name
{
    
    // 这里调用imageWithName，相当于调用imageName
    UIImage *image = [self imageWithName:name];
    
    if (image == nil) {
        NSLog(@"加载空的图片");
    }
    
    NSLog(@"zhangaotian");
    return image;
}

@end
