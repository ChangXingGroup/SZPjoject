//
//  DeviceInfoModel.h
//  iBodyPort
//
//  Created by ZNSD on 2020/7/3.
//  Copyright © 2020 Jincheng Zhao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DeviceInfoModel : NSObject

@property (strong, nonatomic) NSString * name;//终端名字串号(主控平台)

@property (strong, nonatomic) NSString * bleVersion;//协议版本号

@property (strong, nonatomic) NSString * type;//屏类型，0方屏，1圆屏

@property (strong, nonatomic) NSString * deviceHeight;//长度，单位像素

@property (strong, nonatomic) NSString * deviceWidth;//宽度，单位像素

@property (strong, nonatomic) NSString * stepNum;//未上传的计步数据条数

@property (strong, nonatomic) NSString * stepDeltaNum;//未上传的计步时间段数据条数

@property (strong, nonatomic) NSString * sleepNum;//未上传的睡眠数据条数

@property (strong, nonatomic) NSString * sleepDeltaNum;//未上传的睡眠分段数据条数

@property (strong, nonatomic) NSString * heartRateNum;//未上传的心率数据条数

@property (strong, nonatomic) NSString * sitTIme;//久坐时间 单位分钟 0则表示久坐提醒关闭

@property (strong, nonatomic) NSString * stepsPlan;//计步目标

@property (strong, nonatomic) NSString * sex;//性别0女，1男

@property (strong, nonatomic) NSString * height;//身高cm

@property (strong, nonatomic) NSString * weight;//体重kg

@property (strong, nonatomic) NSString * birthday;//生日，年-月-日

@property (strong, nonatomic) NSString * battery;//电量

@property (strong, nonatomic) NSString * bleAddress;//蓝牙地址

@property (strong, nonatomic) NSString * softwareVersion;//软件版本号

@property (strong, nonatomic) NSString * bloodPressureNum;//未上传的血压数据条数

@property (strong, nonatomic) NSString * bloodOxygenNUm;//未上传的血氧数据条数

@property (strong, nonatomic) NSString * deviceIdentifier;//设备标识符

@property (strong, nonatomic) NSString * ecgNum;//未上传的ecg数据条数

@property (strong, nonatomic) NSString * tempNum;//未上传的体温数据条数

@end

NS_ASSUME_NONNULL_END
