//
//  HealthySleepModel.h
//  iBodyPort
//
//  Created by admin on 2020/1/10.
//  Copyright © 2020 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HealthySleepModel : NSObject

@property (copy,nonatomic)NSString *deviceName; //设备mac地址
@property (assign,nonatomic)long long dataDate; //数据日期

@property (copy,nonatomic)NSString *sleepDuration;

@property (copy,nonatomic)NSString *deepSleep; //深睡时长 Duration
@property (copy,nonatomic)NSString *lightSleep; //浅睡时长
//@property (copy,nonatomic)NSString *detailDataStr;//睡眠时间点arr
@property (copy,nonatomic)NSArray *detailDataArr;//睡眠时间点arr

@property (copy,nonatomic)NSString *sleepTime;
@property (copy,nonatomic)NSString *status;//0未进入睡眠 1轻度睡眠 2深度睡眠

@property (copy,nonatomic)NSString *packetSum;
@property (copy,nonatomic)NSString *packetIndex;

@end

NS_ASSUME_NONNULL_END
