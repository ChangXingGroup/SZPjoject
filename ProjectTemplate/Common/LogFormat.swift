//
//  LogFormat.swift
//  Common
//
//  Created by !>-<! on 2021/7/30.
//  Copyright © 2021 !>-<!. All rights reserved.
//

import Foundation


//导入日志框架
import CocoaLumberjack

//实现DDLogFormatter协议
//这里要继承NSObject
//因为DDLogFormatter其实是继承NSObject
//如果不继承会要实现很多NSObject里面的方法
public class LogFormat: NSObject,DDLogFormatter {
    
    /// 返回格式化后的日志
    ///
    /// - Parameter logMessage: <#logMessage description#>
    /// - Returns: <#return value description#>
    public func format(message logMessage: DDLogMessage) -> String? {
        //处理日志等级
        var logLevel=""
        
        switch logMessage.level {
        case .error:
            logLevel="E"
        case .warning:
            logLevel="W"
        case .info:
            logLevel="I"
        case .debug:
            logLevel="D"
        default:
            logLevel="V"
        }
        
        //格式化时间
        let date = TimeUtil.date2yyyyMMddHHmmsssss(logMessage.timestamp)
        
        //格式化日志
        return "\(date) \(logLevel) \(logMessage.tag ?? "E") \(logMessage.message)"
    }
    
}
