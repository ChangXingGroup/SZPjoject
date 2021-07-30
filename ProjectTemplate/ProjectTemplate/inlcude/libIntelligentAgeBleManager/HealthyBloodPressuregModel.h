//
//  HealthyBloodPressuregModel.h
//  iBodyPort
//
//  Created by admin on 2020/1/10.
//  Copyright © 2020 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HealthyBloodPressuregModel : NSObject

@property (copy,nonatomic)NSString *deviceName; //设备mac地址
@property (assign,nonatomic)long long dataDate; //数据日期
@property (copy,nonatomic)NSString *highValue; //高压
@property (copy,nonatomic)NSString *lowValue; //低压

@end

NS_ASSUME_NONNULL_END
