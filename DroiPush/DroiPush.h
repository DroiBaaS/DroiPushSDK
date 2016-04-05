//
//  DroiPush.h
//  DroiPush
//
//  Created by Jon on 16/2/25.
//  Copyright © 2016年 icewind. All rights reserved.
//

#import <Foundation/Foundation.h>


extern NSString *const kDroiPushReceiveLongMessageNotification; //收到长消息通知
extern NSString *const kDroiPushReceiveFileNotification;        //收到文件通知

@interface DroiPush : NSObject


/**开启DroiPush推送服务,必须调用,否则不能使用DroiPush SDK 相关功能
 @param appKey    注册app时生成的AppKey,请参考 DroiPush 相关说明文档来获取这个标识.
 @param appSecret 注册app是生成的AppSecret,请参考 DroiPush 相关说明文档来获取这个密钥.
 @param channelId channelId为nil时,默认为Appstore
 */
+ (void)startWithAppKey:(NSString *)appKey
              appSecret:(NSString *)appSecret
              channelId:(NSString *)channelId;


/**注册要处理的远程通知类型
 @param types 通知类型
 @param categories
 */
+ (void)registerForRemoteNotificationTypes:(NSUInteger)types
                                categories:(NSSet *)categories;

/**注册远程通知,类型为默认类型,也可以使用系统提供的方法自定义注册,默认类型为
 (Badge | Sound |Alert)
 */
+ (void)registerForRemoteNotifications;

/**返回字符串类型的deviceToken数据
 */
+ (NSString *)deviceTokenFromData:(NSData *)tokenData;

/**注册DevieceToken 在didRegisterForRemoteNotificationsWithDeviceToken方法中调用
 */
+ (void)registerDeviceToken:(NSData *)deviceToken;

/**处理收到的远程通知 
    请在-(void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler方法调用
 */
+ (void)handleRemoteNotification:(NSDictionary *)userInfo;


/**设置badge值
 */
+ (void)setBadge:(NSUInteger)badgeNumber;


/**设置标签
  @param tags 标签集合,如果tags参数不合法，返回NO
 */
+ (BOOL) setTags:(NSSet *)tags;

/**清除所有tag
 */
+ (void) resetTags;

/**过滤掉无效的 tags tag值不能重复,且只能以字母（区分大小写）、数字、下划线、汉字组成
   如果tags数量超过限制数量, 则返回靠前的有效的 tags.建议设置tags前用此接口校验.
   SDK内部也会基于此接口来做过滤.
 */
+ (NSSet *)filterValidTags:(NSSet *)tags;


/** 是否关闭Log
 */
+ (void)setLogOFF:(BOOL)isLogOFF;



@end
