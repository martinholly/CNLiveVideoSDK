//
//  CNLiveLivePlayerView.h
//  CNLiveUGC
//
//  Created by 雷浩杰 on 16/8/2.
//  Copyright © 2016年 雷浩杰. All rights reserved.
//

#import <UIKit/UIKit.h>

/* 购买电影券或飞吻成功后 聊天时消息发送的内容格式(送飞吻时num可不传)
 {
 "type"         : "question"         // 送礼物，问问题
 "imgurl"       : "",                // 头像图片地址
 "num"          : "",                // 观影券数量
 "user_name"    : "",                // 昵称
 "mbody"        : ""                 // 问题
 }
 */

typedef NS_ENUM (NSUInteger, CNLiveLivePlayerButtonClickActionOptions) {
    CNLiveLivePlayerBackBtnAction = 1,                 //返回
    CNLiveLivePlayerHostDetailBtnAction = 2,           //明星详情
    CNLiveLivePlayerShareBtnAction = 3,                //分享
    CNLiveLivePlayerContributionListBtnAction = 4,     //贡献榜
    CNLiveLivePlayerSupportBtnAction = 5,              //支持TA
    CNLiveLivePlayerFlyKissBtnAction = 6,              //送飞吻
    CNLiveLivePlayerReplayBtnAction = 7,               //直播结束页面的重播按钮
    CNLiveLivePlayerFilmDetailBtnAction = 8,           //直播结束页面的电影详情按钮
    CNLiveLivePlayerInputBtnAction = 9,                //输入按钮
    CNLiveLivePlayerDismissKeyboardAction = 10,        //收起键盘
    CNLiveLivePlayerSendBtnAction = 11                 //发送
};

@protocol CNLiveLivePlayerViewDelegate <NSObject>

/* 接收到视频播放失败的回调
 *
 * info               视频播放失败的原因 errorCode是MPMovieFinishReason的枚举
 * 在接收到失败的回调后，判断活动是否结束
 * 未结束调用 showLoadView 方法
 * 已结束调用 showEndViewWithWatchAudience:(NSString *)watch buyAudience:(NSString *)buy filmName:(NSString *)filmName
 * 并传入结束页面需要用到的数据
 *
 */
- (void)CNLiveLivePlayerViewPlayErrorInfo:(NSDictionary *)info;

/* 连接聊天室失败，或聊天室断开连接
 *
 * SDK自动展示重连的UI
 * 有可能是传入参数错误，需检查传入的 appId appKey roomId 三者是否匹配
 *
 */
- (void)chatroomConnectFaild:(NSDictionary *)error;

//点击按钮的回调
- (void)buttonClickOptions:(CNLiveLivePlayerButtonClickActionOptions)options;

@end

//直播播放
@interface CNLiveLivePlayerView : UIView

/* 创建直播播放器
 *
 * appId               通过网站申请得到的appId
 * appKey              通过网站申请得到的appKey
 * hadFilm             是否有电影
 * kissMoney           当没有电影时，飞吻价格(有电影可不传)
 * roomId              聊天室Id
 * nickName            在聊天室中使用的昵称
 * channelId           主播Id
 * authFailed          鉴权失败回调
 *
 */
- (instancetype)initWithFrame:(CGRect)frame
                        appId:(NSString *)appId
                       appKey:(NSString *)appKey
                      hadFilm:(BOOL)hadFilm
                    kissMoney:(NSString *)money
                       roomId:(NSString *)roomId
                     nickName:(NSString *)nickName
                    channelId:(NSString *)channelId
                   authFailed:(void(^)(NSDictionary *errorInfo))authFailedBlock;

@property (nonatomic, assign)id<CNLiveLivePlayerViewDelegate> delegate;

/* 传入贡献榜单信息
 *
 * 数据格式为
 * [ 
 *   { @"icon": @"", @"number": @""},
 *
 *   { @"icon": @"", @"number": @""}
 * ]
 *
 * icon是头像  number是电影券张数或飞吻钱数
 *
 */
- (void)setContributionListInfo:(NSArray *)info;

//传入收到飞吻或预售票房的钱数
- (void)setMoney:(NSString *)money;

//传入在线人数
- (void)setPeopleCount:(NSString *)count;

//显示重试View
- (void)showLoadView;

/* 显示直播结束view，并传入结束页面需要用到的数据
 *
 * watch               多少人看过
 * buy                 多少人购买
 * filmName            电影名字
 *
 */
- (void)showEndViewWithWatchAudience:(NSString *)watch buyAudience:(NSString *)buy filmName:(NSString *)filmName;

//退出
- (void)CNLiveLivePlayerViewExit;

@end
