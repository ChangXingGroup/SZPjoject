//
//  HealthTempModel.h
//  iBodyPort
//
//  Created by ZNSD on 2020/6/13.
//  Copyright © 2020 Jincheng Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HealthyTempModel : NSObject

@property (copy,nonatomic)NSString *deviceName; //设备mac地址
@property (assign,nonatomic)long long dataDate; //数据日期
@property (copy,nonatomic)NSString *tempValue; //体温值 36.5录入365

@end

NS_ASSUME_NONNULL_END
