//
//  CMDDataHandle.h
//  iBodyPort
//
//  Created by ZNSD on 2020/7/2.
//  Copyright © 2020 Jincheng Zhao. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "DeviceInfoModel.h"

#import "SportsModel.h"
#import "HealthyStepsModel.h"
#import "HealthySleepModel.h"
#import "HealthyHeartRateModel.h"
#import "HealthyECGModel.h"
#import "HealthyBloodPressuregModel.h"
#import "HealthyBloodOxygenModel.h"
#import "HealthyTempModel.h"

#import "UIFactory.h"

NS_ASSUME_NONNULL_BEGIN

//心率 血压 血氧 体温
typedef NS_ENUM(NSInteger,InitiativeMeasurementType){
    MeasurementType_HeartRate = 1,
    MeasurementType_BloodPressureg,
    MeasurementType_BloodOxygen,
    MeasurementType_Temp
};

@protocol CMDDataHandleDelegate <NSObject>
/*切换完成代理方法*/
//- (void)pageTabViewDidEndChange;
//if([self.delegate respondsToSelector:@selector(pageTabViewDidEndChange)]) {
//    if(_lastSelectedTabIndex != _selectedTabIndex) {
//        [self.delegate pageTabViewDidEndChange];
//    }
//}

#pragma mark - 找手表结果反馈
- (void)CMDDataHandle_findWatchReturnForBool:(BOOL)sendBool;
#pragma mark - 手表找手机操作反馈
- (void)CMDDataHandle_findPhoneAlertWithState:(int)state;
#pragma mark - 单位制式
- (void)CMDDataHandle_setWatchUnitDataWithUnitString:(NSString *)unitString tempUnit:(NSString *)tempUnit;
#pragma mark - 蓝牙拍照手表操作反馈
- (void)CMDDataHandle_blePhototWithState:(int)state;
#pragma mark - 个人资料
- (void)CMDDataHandle_setWatchUserInfoWithStepPlan:(NSString *)stepPlan sex:(NSString *)sex height:(NSString *)height weight:(NSString *)weight;
#pragma mark - 设备信息
- (void)CMDDataHandle_deviceInfoForModel:(DeviceInfoModel *)model;
#pragma mark - 多运动索引
- (void)CMDDataHandle_sportsIndexArray:(NSArray *)indexArray;
#pragma mark - 多运动详情
- (void)CMDDataHandle_sportsDetailsSportsModel:(SportsModel *)model;
#pragma mark - 每天计步数据
- (void)CMDDataHandle_dayStepsModelArray:(NSArray<HealthyStepsModel *> *)dayStepsModelArray;
#pragma mark - 时间段增量数据
- (void)CMDDataHandle_addStepsDataModelArr:(NSArray<HealthyStepsModel *> *)addStepsDataModelArr;
#pragma mark - 每天睡眠数据
- (void)CMDDataHandle_daySleepModelArray:(NSArray<HealthySleepModel *> *)daySleepModelArray;
#pragma mark - 时间段睡眠数据
- (void)CMDDataHandle_subSleepDataModelArr:(NSArray<HealthySleepModel *> *)subSleepModelArray;
#pragma mark - 心率单次测试数据
- (void)CMDDataHandle_heartRateDataModelArray:(NSArray<HealthyHeartRateModel *> *)heartRateDataModelArray;
#pragma mark - 心电单次测试数据
- (void)CMDDataHandle_ecgDataModelArray:(NSArray<HealthyECGModel *> *)ecgDataModelArray;
#pragma mark - 血压单次测试数据
- (void)CMDDataHandle_bpDataModelArray:(NSArray<HealthyBloodPressuregModel *> *)bpDataModelArray;
#pragma mark - 血氧单次测试数据
- (void)CMDDataHandle_boDataModelArray:(NSArray<HealthyBloodOxygenModel *> *)boDataModelArray;
#pragma mark - 温度单次测试数据
- (void)CMDDataHandle_tempDataModelArray:(NSArray<HealthyTempModel *> *)tempDataModelArray;
#pragma mark - 主动测量数据操作反馈
/*
 measurementType
    固定值1，无参考意义，不可作为判断类型的条件
 resultNum
    0:测量成功
    1:已发送主动测量未完成
    2:设备在(心率、血压、血氧、温度)界面
    3:每小时自动测量正在运行
    5:手表未正常佩戴
 */
- (void)CMDDataHandle_openInitiativeMeasurement:(InitiativeMeasurementType)measurementType resultNum:(int)resultNum;
#pragma mark - 初始化表盘回调
- (void)CMDDataHandle_initDeviceBackImageSuccess;
#pragma mark - 接受表盘单包数据回调
- (void)CMDDataHandle_setDeviceBackImgSubDataSuccess:(BOOL)isSuccess;

@end

@interface CMDDataHandle : NSObject

@property(weak, nonatomic) id<CMDDataHandleDelegate> delegate;
@property(strong, nonatomic)NSString * dataDateForFirstSync;

#pragma mark - 发送数据
//设备语言同步
+ (NSData *)setDeviceLanguageAccordingToIPhoneLanguage;

//找手表
+ (NSData *)findWatchForSwich:(int)swich;

//获取设备信息
+ (NSData *)getDeviceInfo;

//设置个人资料(计步目标-性别-身高-体重)
//0为女 ， 1为男 ， 默认男；
+ (NSData *)setWatchUserInfoWithStepPlan:(NSString *)stepPlan sex:(NSString *)sex height:(NSString *)height weight:(NSString *)weight;

//设置单位制式 0-公式  1-英式  设置温度单位  0-摄氏度   1-华氏度
+ (NSData *)setWatchUnit:(NSString *)unitString tempUnit:(NSString *)tempUnit;

//设置前/后台运行状态 0-后台  1-前台
+ (NSData *)setReceptionModeWithState:(NSString *)state;

//获取多运动数据索引
+ (NSData *)getSportsIndexArrayData;

//获取多运动数据详情
+ (NSData *)getSportsDetailsDataWithIndex:(NSString *)index;
//多运动数据获取成功回复
+ (NSData *)getSportsDetailsDataSuccessWithIndex:(NSString *)index packetSum:(NSString *)packetSum packetIndex:(NSString *)packetIndex;

//获取计步信息
+ (NSData *)getDayStepsData;
//计步信息获取成功回复
+ (NSData *)getDayStepsDataSuccess;

//获取计步:时间段增量数据
+ (NSData *)getAddDayStepsData;
//计步:时间段增量数据获取成功回复
+ (NSData *)getAddDayStepsDataSuccessWithPacketSum:(NSString *)packetSum packetIndex:(NSString *)packetIndex;

//获取每天睡眠数据
+ (NSData *)getDaySleepData;
//每天睡眠数据获取成功回复
+ (NSData *)getDaySleepDataSuccess;

//获取同时段睡眠数据
+ (NSData *)getSubSleepData;
//同时段睡眠数据获取成功回复
+ (NSData *)getSubSleepDataSuccessWithPacketSum:(NSString *)packetSum packetIndex:(NSString *)packetIndex;

//获取心率单次测试数据
+ (NSData *)getHeartRateData;
//心率数据获取成功回复
+ (NSData *)getHeartRateDataSuccess;

//获取心电单次测试数据
+ (NSData *)getECGData;
//心电数据获取成功回复
+ (NSData *)getECGDataSuccessWithPacketSum:(NSString *)packetSum packetIndex:(NSString *)packetIndex;

//获取血压单次测试数据
+ (NSData *)getBloodPressuregData;
//血压数据获取成功回复
+ (NSData *)getBloodPressuregDataSuccess;

//获取血氧单次测试数据
+ (NSData *)getBloodOxygenData;
//血氧数据获取成功回复
+ (NSData *)getBloodOxygenDataSuccess;

//获取温度单次测试数据
+ (NSData *)getTempData;
//温度数据获取成功回复
+ (NSData *)getTempDataSuccess;

//初始化表盘
+ (NSData *)getInitDeviceBackImgData;
//发送表盘数据
+ (NSData *)setDeviceBackImgWithDeviceStyle:(NSString *)deviceStyle deviceStyleId:(NSString *)deviceStyleId imgDataLength:(NSString*)imgDataLength packetSum:(NSString *)packetSum packetIndex:(NSString *)packetIndex imageSubData:(NSData *)imageSubData;

//主动测量数据
+ (NSData *)openInitiativeMeasurement:(InitiativeMeasurementType)measurementType;

#pragma mark - 解析数据

- (void)sortCommandDidUpdateValueForDataString:(NSString *)receivedDataString;








@end

NS_ASSUME_NONNULL_END
