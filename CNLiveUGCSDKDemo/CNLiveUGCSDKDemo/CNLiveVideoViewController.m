//
//  CNLiveVideoViewController.m
//  CNLiveUGCDemo
//
//  Created by 雷浩杰 on 16/8/18.
//  Copyright © 2016年 雷浩杰. All rights reserved.
//

#import "CNLiveVideoViewController.h"
#import <CNLiveUGC/CNLiveVideoPlayerView.h>

@interface CNLiveVideoViewController ()<CNLiveVideoPlayerViewDelegate>
{
    CNLiveVideoPlayerView *_video;
}

@end

@implementation CNLiveVideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor grayColor];
    
    _video = [[CNLiveVideoPlayerView alloc] initWithFrame:self.view.bounds appId:@"60_irg1rhs308" appKey:@"4e7a37b27a717a9e9b0a7aea4620ee55ea61fbf923bf46" hadFilm:YES contentId:@"dc62ce375eb84461b66550aa3b8e8293" authFailed:^(NSDictionary *errorInfo) {
        
    }];
    _video.delegate = self;
    [self.view addSubview:_video];
    
}

//demo中用按钮的点击 来模拟给SDK传入 票房(或飞吻)、贡献榜、人数
- (void)buttonClickOptions:(CNLiveVideoPlayerButtonClickActionOptions)options
{
    if (options == CNLiveVideoPlayerBackBtnAction) {
        [_video CNLiveVideoPlayerViewExit];
        [self dismissViewControllerAnimated:YES completion:NULL];
    } else {
        static int i = 0;
        if (i % 2 == 0) {
            [_video setContributionListInfo:[self addData]];
            [_video setMoney:@"111111"];
            [_video setPeopleCount:@"333333"];
        } else {
            [_video setContributionListInfo:[self addData1]];
            [_video setMoney:@"222222"];
            [_video setPeopleCount:@"444444"];
        }
        i++;
        NSLog(@"%ld", options);
    }
}

- (NSArray *)addData
{
    NSMutableArray *array = [NSMutableArray arrayWithCapacity:0];
    for (int i =0; i<10; i++) {
        NSDictionary *dic = [NSDictionary dictionaryWithObjectsAndKeys:@"http://img2.a0bi.com/upload/ttq/20160709/1468043314019.png",@"icon",@"88",@"number", nil];
        [array addObject:dic];
    }
    return [array copy];
}

- (NSArray *)addData1
{
    NSMutableArray *array = [NSMutableArray arrayWithCapacity:0];
    for (int i =0; i<10; i++) {
        NSDictionary *dic = [NSDictionary dictionaryWithObjectsAndKeys:@"http://awb.img.xmtbang.com/img/uploadnew/201510/23/ccaeb2d2abe94fa6b3efe014e9146e94.jpg",@"icon",@"99",@"number", nil];
        [array addObject:dic];
    }
    return [array copy];
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
