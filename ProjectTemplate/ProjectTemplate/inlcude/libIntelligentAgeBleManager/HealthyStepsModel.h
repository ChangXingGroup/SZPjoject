//
//  HealthyStepsModel.h
//  iBodyPort
//
//  Created by admin on 2020/1/10.
//  Copyright © 2020 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HealthyStepsModel : NSObject

@property (copy,nonatomic)NSString *packetSum;
@property (copy,nonatomic)NSString *packetIndex;

@property (copy,nonatomic)NSString *hour;
@property (copy,nonatomic)NSString *minute;

@property (copy,nonatomic)NSString *deviceName; //设备mac地址
@property (assign,nonatomic)long long dataDate; //数据日期

@property (copy,nonatomic)NSString *steps; //步数
@property (copy,nonatomic)NSString *distance; //距离  单位：分米
@property (copy,nonatomic)NSString *calorie;//卡路里  单位：卡
@property (copy,nonatomic)NSString *duration;//运动时长 Duration
@property (copy,nonatomic)NSMutableArray *stepsDataArr;//计步时间点arr

+ (NSMutableArray *)get24HourArrWithAllStepsDataArr:(NSArray *)stepsDataArr;

@end

NS_ASSUME_NONNULL_END
