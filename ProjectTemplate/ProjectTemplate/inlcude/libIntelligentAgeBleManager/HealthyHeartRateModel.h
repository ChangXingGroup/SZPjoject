//
//  HealthyHeartRateModel.h
//  iBodyPort
//
//  Created by admin on 2020/1/10.
//  Copyright © 2020 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HealthyHeartRateModel : NSObject

@property (copy,nonatomic)NSString *deviceName; //设备mac地址
@property (assign,nonatomic)long long dataDate; //数据日期
//@property (copy,nonatomic)NSString *heartRateValue; //心率

@property (copy,nonatomic)NSString *averageValue; //当日平均心率
@property (copy,nonatomic)NSArray *heartArray; //当日心率数组



@end

NS_ASSUME_NONNULL_END
