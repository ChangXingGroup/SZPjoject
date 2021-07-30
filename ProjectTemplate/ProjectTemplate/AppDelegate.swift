//
//  AppDelegate.swift
//  ProjectTemplate
//
//  Created by !>-<! on 2018/12/28.
//  Copyright © 2018 !>-<!. All rights reserved.
//

import UIKit
import NetworkService
import Business
import Common
import CocoaLumberjack

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    /// 定义一个静态的计算属性
    /// 返回AppDelegate对象实例
    open class var shared: AppDelegate {
        get {
            return UIApplication.shared.delegate as! AppDelegate
        }
    }

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
//        apiProvider.request(SZNetworkService.login(userid: "admin", passwd: "abc.123")) { (result) in
//
//        }
        window?.rootViewController = UINavigationController(rootViewController: SZLoginViewController())
//        window?.rootViewController = SZRigisterViewController()
        window?.makeKeyAndVisible()
        return true
    }

    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }

    
    /// 初始化日志
    func initLog() {
//        //日志打印到控制器
//        DDLog.add(DDOSLogger.sharedInstance)
//
//        //打印到文件
//        let fileLogger = DDFileLogger()
//
//        //每个文件保存24小时日志
//        //其实就是保存每天日志到一个文件
//        fileLogger.rollingFrequency = 60 * 60 * 24
//
//        //保存最近7天日志
//        fileLogger.logFileManager.maximumNumberOfLogFiles = 7
//
//        //将配置添加到日志框架
//        DDLog.add(fileLogger)
        
        //定制日志规则
        #if DEBUG
            //调试模式加日志打印到控制台
            let ddosLogger=DDOSLogger.sharedInstance
            //设置日志格式化器
            ddosLogger.logFormatter = LogFormat()
            DDLog.add(ddosLogger)
        #endif
        
        //所有环境
        //都打印到文件
        let fileLogger = DDFileLogger()
        
        //每个文件保存24小时日志
        //其实就是保存每天日志到一个文件
        fileLogger.rollingFrequency=60 * 60 * 24
        
        //总共保存最近30天日志文件
        fileLogger.logFileManager.maximumNumberOfLogFiles=30
        
        //设置日志格式化器
        fileLogger.logFormatter = LogFormat()
        
        //只保存警告以及以上级别的日志
        DDLog.add(fileLogger, with: .warning)
        
       
        
//        //打印日志时指定级别
//        DDLogError("AppDelegate initLog Ixuea Error", level: .error)
//
//        //获取日志保存文件夹
//        let logsDirectory=fileLogger.logFileManager.logsDirectory
//        print("AppDelegate log path:\(logsDirectory)")
//
//        //获取排序后的日志文件名称
//        let logFilenames=fileLogger.logFileManager.sortedLogFileNames
//        print("AppDelegate log files:\(logFilenames)")
    }

}

