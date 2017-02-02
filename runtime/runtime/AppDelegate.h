//
//  AppDelegate.h
//  runtime
//
//  Created by 张傲天 on 2016/10/16.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

