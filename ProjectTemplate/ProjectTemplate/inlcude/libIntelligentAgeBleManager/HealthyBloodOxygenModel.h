//
//  HealthyBloodOxygenModel.h
//  iBodyPort
//
//  Created by admin on 2020/1/10.
//  Copyright © 2020 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HealthyBloodOxygenModel : NSObject

@property (copy,nonatomic)NSString *deviceName; //设备mac地址
@property (assign,nonatomic)long long dataDate; //数据日期
@property (copy,nonatomic)NSString *bloodOxygenValue; //血氧值

@end

NS_ASSUME_NONNULL_END
