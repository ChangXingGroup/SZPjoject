//
//  TimeUtil.swift
//  Common
//
//  Created by !>-<! on 2021/7/30.
//  Copyright © 2021 !>-<!. All rights reserved.
//

import Foundation
class TimeUtil {
    
    /// 将秒转为分秒格式
    ///
    /// - Parameter value: <#value description#>
    /// - Returns: 格式为：10:20
    static func second2MinuteAndSecond(_ value:Float) -> String {
        let minute = Int(value/60)
        let second = Int(value) % 60
        
        return String(format: "%02d:%02d", minute,second)
    }
    
    /// 将分秒毫秒数据转为毫秒
    ///
    /// - Parameter data: 格式为：00:06.429
    /// - Returns: <#return value description#>
    static func parseToInt(_ data:String) -> Int {
        //将:替换.
        let value = data.replacingOccurrences(of: ":", with: ".")
        
        //使用.拆分
        let strings = value.components(separatedBy: ".")
        
        //分别取出分秒毫秒
        let m = Int(strings[0])!
        let s = Int(strings[1])!
        let ms = Int(strings[2])!
        
        //转为毫秒
        return (m*60+s) * 1000 + ms
    }
    
    /// 将ISO8601字符串格式化为Date
    ///
    /// - Parameter _data: <#_data description#>
    /// - Returns: <#return value description#>
    static func dateFromISO8601String(_ data:String) -> Date {
        //初始化格式化器
        let dateFormatter = DateFormatter.init()
        
        //设置时区
        dateFormatter.timeZone = TimeZone(identifier: "UTC")
        
        //设置格式化字符串
        dateFormatter.dateFormat = ISO8601_DATE_TIME_FORMAT
        
        //转为date
        return dateFormatter.date(from: data)!
    }
    
    /// 将ISO8601字符串转为项目中通用的格式
    ///
    /// - Parameter data: <#data description#>
    /// - Returns: <#return value description#>
    static func iso8601ToCommonFormat(_ data:String) -> String {
        //先将ISO8601字符串Date
        let date = dateFromISO8601String(data)
        
        //格式化为项目中通用的格式
        return iso8601ToCommonFormat(date)
    }
    
    /// 将Date转为项目中通用的格式
    ///
    /// - Parameter date: <#date description#>
    /// - Returns: <#return value description#>
    static func iso8601ToCommonFormat(_ date:Date) -> String {
        //时间
        let createdAt = date
        
        //当前时间
        let now = Date.init()
        
        //创建日历对象
        //计算日期事件之间的差就更方便
        let calendar = Calendar.current
        
        //获取哪些值
        let unitFlags:Set<Calendar.Component>=[Calendar.Component.year,.month,.weekOfMonth,.day,.hour,.minute,.second]
        
        //计算两个日期之间的差
        let cmps = calendar.dateComponents(unitFlags, from: createdAt, to: now)
        
        var result = ""
        if cmps.second!<=0 {
            result = "现在"
        }else if (cmps.second! > 0 && cmps.minute! <= 0){
            result = "\(cmps.second!)秒前"
        }else if (cmps.minute! > 0 && cmps.hour! <= 0) {
            result = "\(cmps.minute!)分钟前"
        }else if (cmps.hour! > 0 && cmps.day! <= 0) {
            result = "\(cmps.hour!)小时前"
        }else if (cmps.day! > 0 && cmps.weekOfMonth! <= 0) {
            result = "\(cmps.day!)天前"
        }else{
            result = date2yyyyMMddHHmmss(createdAt)
        }
        
        return result
    }
    
    /// 将Date格式为年-月-日 时:分:秒
    ///
    /// - Parameter date: <#date description#>
    /// - Returns: <#return value description#>
    static func date2yyyyMMddHHmmss(_ date:Date) -> String {
        return dateFormat(date, DATE_TIME_FORMAT_yyyyMMddHHmmss)
    }
    
    /// 将Date格式为年-月-日 时:分:秒:毫秒
    ///
    /// - Parameter date: <#date description#>
    /// - Returns: <#return value description#>
    static func date2yyyyMMddHHmmsssss(_ date:Date) -> String {
        return dateFormat(date, DATE_TIME_FORMAT_yyyyMMddHHmmsssss)
    }
    
    /// 将Date格式为年-月-日 时:分:秒
    ///
    /// - Parameter date: <#date description#>
    /// - Returns: <#return value description#>
    static func date2yyyyMMddHHmmss(_ data:String) -> String {
        //先将ISO8601字符串Date
        let date = dateFromISO8601String(data)
        
        //格式化
        return date2yyyyMMddHHmmss(date)
    }
    
    /// 将Date格式为年-月-日
    ///
    /// - Parameter date: <#date description#>
    /// - Returns: <#return value description#>
    static func date2yyyyMMdd(_ date:Date) -> String {
        return dateFormat(date, DATE_FORMAT_yyyyMMdd)
    }
    
    /// 格式化日期时间
    ///
    /// - Parameters:
    ///   - date: <#date description#>
    ///   - format: <#format description#>
    /// - Returns: <#return value description#>
    static func dateFormat(_ date:Date,_ format:String) -> String {
        //创建格式化器
        let dateFormatter = DateFormatter.init()
        
        //设置需要的格式
        dateFormatter.dateFormat = format
        
        //格式化
        return dateFormatter.string(from: date)
    }
}
