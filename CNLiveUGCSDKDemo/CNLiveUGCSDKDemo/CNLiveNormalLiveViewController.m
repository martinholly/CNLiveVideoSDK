//
//  CNLiveNormalLiveViewController.m
//  CNLiveUGCDemo
//
//  Created by 雷浩杰 on 16/8/25.
//  Copyright © 2016年 雷浩杰. All rights reserved.
//

#import "CNLiveNormalLiveViewController.h"
#import <CNLiveUGC/CNLiveActivityView.h>

@interface CNLiveNormalLiveViewController ()<CNLiveActivityViewDelegate>
{
    CNLiveActivityView *_player;
}

@end

@implementation CNLiveNormalLiveViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _player = [[CNLiveActivityView alloc] initWithFrame:self.view.bounds channelId:@"7146bea3b1db444c9e73ca0f38e70662" appId:@"60_irg1rhs308" appKey:@"4e7a37b27a717a9e9b0a7aea4620ee55ea61fbf923bf46" roomId:@"27_123456789" nickName:@"lalala"];
    _player.delegate = self;
    [self.view addSubview:_player];
}

- (void)CNLiveActivityViewBackAction
{
    [self dismissViewControllerAnimated:YES completion:NULL];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
