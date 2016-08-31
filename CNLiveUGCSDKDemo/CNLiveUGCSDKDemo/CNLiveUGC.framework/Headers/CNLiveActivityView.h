//
//  LivePlayView.h
//  LivePlayDemo
//
//  Created by 雷浩杰 on 16/7/4.
//  Copyright © 2016年 雷浩杰. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CNLiveActivityViewDelegate <NSObject>

//认证失败
- (void)CNLiveActivityViewAuthFailed:(NSDictionary *)error;

//播放结束或者失败原因
- (void)CNLiveActivityViewPlayErrorInfo:(NSDictionary *)info;

//点击返回按钮(竖屏调用，当该方法调用时会销毁播放器。横屏点击将返回竖屏，不会调用代理)
- (void)CNLiveActivityViewBackAction;

//点击分享按钮
- (void)CNLiveActivityViewShareAction;

//聊天室连接失败
- (void)CNLiveActivityViewChatroomDisConnect:(NSDictionary *)error;

@end


//使用 CNLiveActivityView 时，需要设置view所在控制器禁止自动旋转  如下所示：
//- (BOOL)shouldAutorotate
//{
//    return NO;
//}

@interface CNLiveActivityView : UIView

@property (nonatomic, weak)id<CNLiveActivityViewDelegate> delegate;

/*      集成视频播放和聊天室
 *
 * channelId          活动Id
 * sp_id              通过网站申请得到的sp_id
 * sp_key             通过网站申请得到的sp_key
 * roomId             聊天室Id
 * nickName           在聊天室中使用的昵称
 *
 */
- (id)initWithFrame:(CGRect)frame
          channelId:(NSString *)channelId
              appId:(NSString *)appId
             appKey:(NSString *)appKey
             roomId:(NSString *)roomId
           nickName:(NSString *)nick;

//退出
- (void)CNLiveActivityViewExit;

@end
