//
//  CNLiveStreamerViewController.m
//  CNLiveUGCDemo
//
//  Created by Android on 16/8/15.
//  Copyright © 2016年 雷浩杰. All rights reserved.
//

#import "CNLiveStreamerViewController.h"
#import <CNLiveUGC/CNLiveStreamerView.h>

@interface CNLiveStreamerViewController ()<CNLiveStreamerViewDelegate>
{
    CNLiveStreamerView *_streamerView;
}

@end

@implementation CNLiveStreamerViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];
    NSString *activityId = [NSString stringWithFormat:@"%d%d%d%d%d",arc4random()%9,arc4random()%9,arc4random()%9,arc4random()%9,arc4random()%9];
    
    _streamerView = [[CNLiveStreamerView alloc] initWithFrame:self.view.frame AppId:@"60_irg1rhs308" appKey:@"4e7a37b27a717a9e9b0a7aea4620ee55ea61fbf923bf46" activityId:@"12312414" channelId:@"12312414" hadFilm:NO roomId:@"27_123456789"];
    
    _streamerView.activityName = @"test";
    _streamerView.callbackAcitvityStatushttpPostUrl = @"http://www.cnlive.com";
    
    [_streamerView getStreamerURLWithSuccess:^{
        
    } failure:^(NSError *error) {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:nil message:error.localizedDescription delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil];
        [alert show];
    }];
    _streamerView.delegate = self;
    [self.view addSubview:_streamerView];
}

- (void)quit
{
    [_streamerView CNLiveStreamerViewExit];
    [self dismissViewControllerAnimated:YES completion:NULL];
}

- (void)streamFinish
{
    [_streamerView streamDuration:@"12:34" audienceNumber:nil money:@"4727528658"];
}

- (void)streamError
{
//    [_streamerView streamErrorDisplayRetryView];
    [_streamerView streamDuration:@"12:54" audienceNumber:nil money:@"4727528658"];
}

- (void)replay
{

}

//demo中用按钮的点击 来模拟给SDK传入 票房(或飞吻)、贡献榜、人数
- (void)contributeListClickAction
{
    static int i = 0;
    if (i % 2 == 0) {
        [_streamerView setContributionListInfo:[self addData]];
        [_streamerView setMoney:@"111111"];
        [_streamerView setPeopleCount:@"333333"];
    } else {
        [_streamerView setContributionListInfo:[self addData1]];
        [_streamerView setMoney:@"222222"];
        [_streamerView setPeopleCount:@"444444"];
    }
    i++;
    NSLog(@"点击了榜单");
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

- (void)initializeErrorMessage:(NSString *)errorMessage
{
    NSLog(@"%@",errorMessage);
}

- (UIStatusBarStyle)preferredStatusBarStyle{
    
    return UIStatusBarStyleLightContent;
    
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
