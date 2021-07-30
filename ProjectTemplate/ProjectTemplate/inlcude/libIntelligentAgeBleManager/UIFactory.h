//
//  UIFactory.h
//  eWatch
//
//  Created by feng on 16/4/22.
//  Copyright © 2016年 feng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface UIFactory : NSObject


//返回基准时间搓
+(NSString *)returnTimeZone:(NSDate*)date;
//返回当前时区时间搓距离基准时间搓的秒数
+(long)returnTimeZoneSeconds;
//返回当前时区时间,时间搓 -> 时间
+(NSString *)returnDateFromTimeZone:(NSString *)interval;
+(NSString *)returnDateFromTimeZoneWithDay:(NSString *)interval;
//返回时间搓,时间 -> 时间搓
+(NSString *)returnTimeZoneFromDateString:(NSString *)dateStr;
//date转不带“-”的年月日时分秒字符串
+(NSString *)dateForNumTimeString:(NSDate*)date;
+(NSDate*)returnCurrentDayBefore:(int)num;
+(NSString *)dateForNumString:(NSDate*)date;
+(NSString *)dateForString:(NSDate*)date;
+(NSDate*)stringReturnDate:(NSString *)day;
//NSString返回某天前N天的NSDate
+(NSDate*)dateForBeforeStrDate:(NSString*)date withDay:(NSString *)day withMonth:(NSString *)month;
//NSDate返回某天前N天的NSDate
+(NSDate*)dateForBeforeDate:(NSDate*)date withDay:(NSString *)day withMonth:(NSString *)month;
+(int)dayReturnWeekday:(NSString*)day;
+(UIButton *)navigationBarRightButtonForSynchronize;
+(UIView *)navigationBarRightButtonForRecordList;
+(UIButton *)navigationBarRightButtonForEdit;
+(UIView *)navigationBarRightButtonForAdd;
//返回当前时区时间
+(NSDate *)NSDateForNoUTC:(NSDate *)date;
//返回UTC时间
+(NSDate *)NSDateForUTC:(NSDate *)date;
//判断某个时间是否在某个时间段里面
+(BOOL)date:(NSDate*)date isBetweenDate:(NSDate*)beginDate andDate:(NSDate*)endDate;
//判断某个时间距离现在已经过了多久
+(int)getUTCFormateDate:(NSDate *)newsDateFormatted;
// 判断是否是同一天
+(BOOL)isSameDay:(NSDate *)date1 date2:(NSDate *)date2;
//获取过去28天的日期@[10.1,10.2,10.3,10.4,...,10.28]
+(NSArray *)getMonthStringForTwentyEightDaysAgoWith:(NSDate *)date;
//获取过去12个月的月份
+(NSArray *)getMonthStringForYearsAgoWith:(NSDate *)date;
//厘米转英尺
+(NSString *)cmTransformFtIn:(NSString *)oldValue;
//公斤转磅
+(NSString *)kgTransformLb:(NSString *)oldValue;
//英尺转厘米
+(NSString *)ftInTransformCm:(NSString *)oldValue;
//磅转公斤
+(NSString *)lbTransformKg:(NSString *)oldValue;
@end
