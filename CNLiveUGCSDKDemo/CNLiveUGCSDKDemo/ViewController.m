//
//  ViewController.m
//  CNLiveUGCSDKDemo
//
//  Created by 雷浩杰 on 16/8/25.
//  Copyright © 2016年 雷浩杰. All rights reserved.
//

#import "ViewController.h"
#import "CNLiveLiveViewController.h"
#import "CNLiveVideoViewController.h"
#import "CNLiveStreamerViewController.h"
#import "CNLiveNormalLiveViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIButton *norLiveButton = [UIButton buttonWithType:UIButtonTypeSystem];
    norLiveButton.frame = CGRectMake(0, 50, self.view.frame.size.width, 50);
    [norLiveButton setTitle:@"普通直播" forState:UIControlStateNormal];
    [norLiveButton addTarget:self action:@selector(norLiveBtnAction) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:norLiveButton];
    
    UIButton *liveButton = [UIButton buttonWithType:UIButtonTypeSystem];
    liveButton.frame = CGRectMake(0, 150, self.view.frame.size.width, 50);
    [liveButton setTitle:@"明星直播" forState:UIControlStateNormal];
    [liveButton addTarget:self action:@selector(liveBtnAction) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:liveButton];
    
    UIButton *videoButton = [UIButton buttonWithType:UIButtonTypeSystem];
    videoButton.frame = CGRectMake(0, 250, self.view.frame.size.width, 50);
    [videoButton setTitle:@"明星回放" forState:UIControlStateNormal];
    [videoButton addTarget:self action:@selector(videoBtnAction) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:videoButton];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    button.frame = CGRectMake(0, 350, self.view.frame.size.width, 50);
    [button setTitle:@"开始直播" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(streamerView) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
}

- (void)norLiveBtnAction
{
    CNLiveNormalLiveViewController *norLive = [[CNLiveNormalLiveViewController alloc] init];
    [self presentViewController:norLive animated:YES completion:NULL];
}

- (void)liveBtnAction
{
    CNLiveLiveViewController *live = [[CNLiveLiveViewController alloc] init];
    [self presentViewController:live animated:YES completion:NULL];
}

- (void)videoBtnAction
{
    CNLiveVideoViewController *video = [[CNLiveVideoViewController alloc] init];
    [self presentViewController:video animated:YES completion:NULL];
}

- (void)streamerView
{
    CNLiveStreamerViewController *streamerVC = [[CNLiveStreamerViewController alloc] init];
    [self presentViewController:streamerVC animated:YES completion:NULL];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
