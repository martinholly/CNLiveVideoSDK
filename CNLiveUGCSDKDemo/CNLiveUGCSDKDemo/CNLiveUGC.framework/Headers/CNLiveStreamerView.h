//
//  CNLiveStreamerView.h
//  CNLiveUGCDemo
//
//  Created by Android on 16/8/15.
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

@protocol CNLiveStreamerViewDelegate <NSObject>

/**
 *  初始化失败
 */
- (void)initializeErrorMessage:(NSString *)errorMessage;

/* 连接聊天室失败，或聊天室断开连接
 *
 * SDK自动展示重连的UI
 * 有可能是传入参数错误，需检查传入的 appId appKey roomId 三者是否匹配
 *
 */
- (void)chatroomConnectFaild:(NSDictionary *)error;

/**
 *  退出
 */
- (void)quit;

/**
 *  直播结束断开推流，传入结束信息（点击 alertView确定按钮 停止直播 在此代理中传入直播结束需要展示的信息 ）
    调用  - (void)streamDuration:(NSString *)duration
                  audienceNumber:(NSString *)audience
                           money:(NSString *)money;
 */
- (void)streamFinish;

/**
 *  直播过程中推流异常（在此代理中调用显示重试或直播结束view的方法）
 */
- (void)streamError;

/**
 *  直播结束点击重播action
 */
- (void)replay;

/**
 *  榜单action
 */
- (void)contributeListClickAction;

@end

@interface CNLiveStreamerView : UIView

@property (nonatomic, assign) id<CNLiveStreamerViewDelegate> delegate;

/**
 @abstract      初始化
 @param         appId                   应用ID
 @param         appKey                  注册后的应用key
 @param         activityId              活动ID，确保SP下的唯一性
 @param         channelId               主播ID
 @param         hadFilm                 是否为电影（yes 显示票房）
 @param         roomId                  聊天室ID
 @param         success                 用于返回初始化状态（成功）
 @param         failure                 用于返回初始化状态（失败）
 @warning       必传参数
 */
- (instancetype)initWithFrame:(CGRect)frame
                        AppId:(NSString *)appId
                       appKey:(NSString *)appKey
                   activityId:(NSString *)activityId
                    channelId:(NSString *)channelId
                      hadFilm:(BOOL)hadFilm
                       roomId:(NSString *)roomId;
/**
 @abstract      活动名称（非必传）
 */
@property (nonatomic, strong) NSString *activityName;

/**
 @abstract      活动状态，0：未开始 ／1：已开始 ／3：已结束 ／4 已下线，默认为0（非必传）
 */
@property (nonatomic, strong) NSString *activityStatus;

/**
 @abstract      开始时间，格式yyyyMMddHHmmss（非必传）
 */
@property (nonatomic, strong) NSString *startTime;

/**
 @abstract      结束时间，格式yyyyMMddHHmmss（非必传）
 */
@property (nonatomic, strong) NSString *endTime;

/**
 @abstract      活动封面（非必传）
 */
@property (nonatomic, strong) NSString *coverImgUrl;

/**
 @abstract      活动分类ID（非必传）
 */
@property (nonatomic, strong) NSString *activityCategory;

/**
 @abstract      扩展字段，参数格式为Map对象的Json字符串（主播昵称、头像、）（非必传）
 */
@property (nonatomic, strong) NSString *extensions;

/**
 @abstract      回调通知活动状态（错误，结束、心跳异常等状态），post 参数activityid、activitystatus值...（非必传）
 */
@property (nonatomic, strong) NSString *callbackAcitvityStatushttpPostUrl;


/**
 @warning       请传入所需参数后调用
 */
- (void)getStreamerURLWithSuccess:(void (^)(void))success
                         failure :(void (^)(NSError *error))failure;

/**
 @abstract      显示直播结束view并传入结束信息
 @param         duration                 直播时长(注：必须是mm:ss格式)
 @param         audience                 观众人数
 @param         money                    收到¥
 @warning       必传参数
 */
- (void)streamDuration:(NSString *)duration
          audienceNumber:(NSString *)audience
                   money:(NSString *)money;

/**
 *  异常时显示的重试View
 */
- (void)streamErrorDisplayRetryView;

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

//退出
- (void)CNLiveStreamerViewExit;

@end
