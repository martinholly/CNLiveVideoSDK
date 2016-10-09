//
//  CNLiveStreamerView.h
//  CNLiveUGCDemo
//
//  Created by Android on 16/8/15.
//  Copyright © 2016年 雷浩杰. All rights reserved.
//

#import <UIKit/UIKit.h>
/*!
 * @abstract  推流错误码，用于指示推流失败的原因
 */
typedef NS_ENUM(NSUInteger, CNLiveStreamerErrorCode) {
    /// 正常无错误
    CNLiveStreamerErrorCode_NONE = 0,
    /// SDK 鉴权失败 (暂时正常推流5~8分钟后终止推流)
    CNLiveStreamerErrorCode_CNLiveAUTHFAILED,
    /// 当前帧编码失败
    CNLiveStreamerErrorCode_ENCODE_FRAMES_FAILED,
    /// 无法打开配置指示的CODEC
    CNLiveStreamerErrorCode_CODEC_OPEN_FAILED,
    /// 连接出错，检查地址
    CNLiveStreamerErrorCode_CONNECT_FAILED,
    /// 网络连接中断
    CNLiveStreamerErrorCode_CONNECT_BREAK,
    /// rtmp 推流域名不存在 (CNLive 自定义)
    CNLiveStreamerErrorCode_RTMP_NonExistDomain,
    /// rtmp 应用名不存在(CNLive 自定义)
    CNLiveStreamerErrorCode_RTMP_NonExistApplication,
    /// rtmp 流名已存在(CNLive 自定义)
    CNLiveStreamerErrorCode_RTMP_AlreadyExistStreamName,
    /// rtmp 被黑名单拒绝(CNLive 自定义)
    CNLiveStreamerErrorCode_RTMP_ForbiddenByBlacklist,
    /// rtmp 内部错误(CNLive 自定义)
    CNLiveStreamerErrorCode_RTMP_InternalError,
    /// rtmp URL 地址已过期(CNLive 自定义)
    CNLiveStreamerErrorCode_RTMP_URLExpired,
    /// rtmp URL 地址签名错误(CNLive 自定义)
    CNLiveStreamerErrorCode_RTMP_SignatureDoesNotMatch,
    /// rtmp URL 中AccessKeyId非法(CNLive 自定义)
    CNLiveStreamerErrorCode_RTMP_InvalidAccessKeyId,
    /// rtmp URL 中参数错误(CNLive 自定义)
    CNLiveStreamerErrorCode_RTMP_BadParams,
    /// rtmp URL 中的推流不在发布点内（CNLive 自定义）
    CNLiveStreamerErrorCode_RTMP_ForbiddenByRegion,
    /// SDK 因为鉴权失败停止推流
    CNLiveStreamerErrorCode_FRAMES_THRESHOLD,
    /// 没有输入的数据，无法开始推流
    CNLiveStreamerErrorCode_NO_INPUT_SAMPLE,
    ///网络中断或服务器异常
    CNLiveStreamerErrorCode_ConnectBreak_OR_ServerAbnormal,
    ///设备中断(锁屏)
    CNLiveStreamerErrorCode_DeviceBreak,
    
};

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
 *  开始推流成功
 */
- (void)startStreamSuccess;

/**
 *  开始推流失败
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
- (void)streamError:(CNLiveStreamerErrorCode)errorCode;

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
