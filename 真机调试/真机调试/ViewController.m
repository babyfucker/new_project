//
//  ViewController.m
//  真机调试
//
//  Created by 张傲天 on 2016/9/22.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic,strong) UIImageView* imageView1;
@property (nonatomic,strong) UIImageView* imageView2;
@end

@implementation ViewController

// 根据url获取UIImage
- (UIImage *)imageWithURLString:(NSString *)urlString {
    NSURL *url = [NSURL URLWithString:urlString];
    NSData *data = [NSData dataWithContentsOfURL:url];
    // 这里并没有自动释放UIImage对象
    return [[UIImage alloc] initWithData:data];
}

- (void)downloadImages {
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    // 异步下载图片
    dispatch_async(queue, ^{
        // 创建一个组
        NSLog(@"group");
        dispatch_group_t group = dispatch_group_create();
        
        __block UIImage *image1 = nil;
        __block UIImage *image2 = nil;
        
        // 关联一个任务到group
        dispatch_group_async(group, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            // 下载第一张图片
            NSString *url1 = @"https://car0.autoimg.cn/upload/spec/9579/u_20120110174805627264.jpg";
            image1 = [self imageWithURLString:url1];
            NSLog(@"d1");
        });
        
        // 关联一个任务到group
        dispatch_group_async(group, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            // 下载第一张图片
            NSString *url2 = @"https://hiphotos.baidu.com/lvpics/pic/item/3a86813d1fa41768bba16746.jpg";
            image2 = [self imageWithURLString:url2];
            NSLog(@"d2");
        });
        
        // 等待组中的任务执行完毕,回到主线程执行block回调
        dispatch_group_notify(group, dispatch_get_main_queue(), ^{
            self.imageView1.image = image1;
            self.imageView2.image = image2;
            
            // 千万不要在异步线程中自动释放UIImage，因为当异步线程结束，异步线程的自动释放池也会被销毁，那么UIImage也会被销毁
            NSLog(@"下载成功");
            // 在这里释放图片资源
//            [image1 release];
//            [image2 release];
        });
//        
//        // 释放group
//        dispatch_release(group);
    });
}

- (void)viewDidLoad {
    [super viewDidLoad];
    NSLog(@"main");
    // Do any additional setup after loading the view, typically from a nib.
    [self.view setBackgroundColor:[UIColor blueColor]];
    [self downloadImages];
    self.imageView1=[[UIImageView alloc]initWithFrame:CGRectMake(0, 0, 100, 100)];
    self.imageView2=[[UIImageView alloc]initWithFrame:CGRectMake(0, 100, 100, 100)];
    [self.view addSubview:self.imageView1];
    [self.view addSubview:self.imageView2];
    dispatch_queue_t concurrentQueue =
    dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(concurrentQueue,^{
        dispatch_sync(concurrentQueue, ^{NSLog(@"t1");});
        dispatch_sync(concurrentQueue, ^{NSLog(@"t2");});
    });
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
