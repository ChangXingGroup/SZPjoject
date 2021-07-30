//
//  SportsModel.h
//  iBodyPort
//
//  Created by admin on 2020/3/19.
//  Copyright © 2020 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SportsModel : NSObject

@property (copy,nonatomic)NSString *sportIndex;
@property (copy,nonatomic)NSString *packetSum;
@property (copy,nonatomic)NSString *packetIndex;

@property (copy,nonatomic)NSString *deviceName; //设备mac地址
@property (assign,nonatomic)long long dataDate; //数据日期

@property (copy,nonatomic)NSString *duration;//运动时长(单位：秒)
@property (copy,nonatomic)NSString *distance; //距离(单位：米)
@property (copy,nonatomic)NSString *calorie;//卡路里(单位：卡cal)
@property (copy,nonatomic)NSString *height; //高度

@property (copy,nonatomic)NSString *sportsType; //运动类型

@property (copy,nonatomic)NSString *averHeart; //平均心率
@property (copy,nonatomic)NSArray *heartArr; //心率数组
@property (copy,nonatomic)NSString *averStride; //平均步频
@property (copy,nonatomic)NSArray *strideArr; //步频数组
@property (copy,nonatomic)NSString *averPace; //平均配速(单位：秒)
@property (copy,nonatomic)NSArray *paceArr; //配速数组
@property (copy,nonatomic)NSString *averSpeedPerHour; //平均时速(单位：km/h  注： 已 *10 扩大十倍)
@property (copy,nonatomic)NSArray *speedPerHourArr; //时速数组(内部元素 已 *10 扩大十倍)

@property (copy,nonatomic)NSString *averHeight; //平均海拔
@property (copy,nonatomic)NSArray *heightArr; //海拔数组
@property (copy,nonatomic)NSString *averTemp; //平均体温
@property (copy,nonatomic)NSArray *tempArr; //体温数组
@property (copy,nonatomic)NSString *steps; //计步
@property (copy,nonatomic)NSString *pole; //高尔夫杆数



@end

NS_ASSUME_NONNULL_END
