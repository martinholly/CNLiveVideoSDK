//
//  CNLiveLiveViewController.m
//  CNLiveUGCDemo
//
//  Created by 雷浩杰 on 16/8/18.
//  Copyright © 2016年 雷浩杰. All rights reserved.
//

#import "CNLiveLiveViewController.h"
#import <CNLiveUGC/CNLiveLivePlayerView.h>

@interface CNLiveLiveViewController ()<CNLiveLivePlayerViewDlegate>
{
    CNLiveLivePlayerView *_livePlayerView;
}

@end

@implementation CNLiveLiveViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor grayColor];
    
//    123321123
//    d849bb4277be42799df3ffc21654d949
    _livePlayerView = [[CNLiveLivePlayerView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height) appId:@"60_irg1rhs308" appKey:@"4e7a37b27a717a9e9b0a7aea4620ee55ea61fbf923bf46" hadFilm:NO kissMoney:@"10" roomId:@"27_123456789" nickName:@"livePlayerView" contentId:@"12312414" authFailed:^(NSDictionary *errorInfo) {
        NSLog(@"%@", errorInfo);
    }];
    _livePlayerView.delegate = self;
    [self.view addSubview:_livePlayerView];
}

- (void)CNLiveLivePlayerViewPlayErrorInfo:(NSDictionary *)info
{
    //如果直播已结束，显示结束页
    [_livePlayerView showEndViewWithWatchAudience:@"524352" buyAudience:@"532522" filmName:@"月满轩尼诗"];
    
    //直播未结束，显示重试
//    [_livePlayerView showLoadView];
    NSLog(@"%@", info);
}

//demo中用按钮的点击 来模拟给SDK传入 票房(或飞吻)、贡献榜、人数
- (void)buttonClickOptions:(CNLiveLivePlayerButtonClickActionOptions)options
{
    if (options == CNLiveLivePlayerBackBtnAction) {
        [_livePlayerView CNLiveLivePlayerViewExit];
        [self dismissViewControllerAnimated:YES completion:NULL];
    } else {
        static int i = 0;
        if (i % 2 == 0) {
            [_livePlayerView setContributionListInfo:[self addData]];
            [_livePlayerView setMoney:@"111111"];
            [_livePlayerView setPeopleCount:@"333333"];
        } else {
            [_livePlayerView setContributionListInfo:[self addData1]];
            [_livePlayerView setMoney:@"222222"];
            [_livePlayerView setPeopleCount:@"444444"];
        }
        i++;
    }
    
    
    
    
    NSLog(@"%ld", options);
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
