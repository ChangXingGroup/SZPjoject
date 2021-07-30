//
//  NetworkAPI.swift
//  NetworkService
//
//  Created by !>-<! on 2021/7/29.
//  Copyright © 2021 !>-<!. All rights reserved.
//

import Foundation

import RxSwift

import Moya

public final class NetworkAPI {
    /// 单例设计模式
    /// 饿汉式单例
    public static let shared = NetworkAPI()
    
    /// MoyaProvider
    private let provider:MoyaProvider<NetworkService>!
    
    /// 私有构造方法
    private init() {
        //插件列表
        var plugins:[PluginType] = []
        
        #if DEBUG
            //表示当前是调试模式
            //添加网络请求日志插件
            plugins.append(NetworkLoggerPlugin())
        #endif
        
        //网络请求加载对话框
        let networkActivityPlugin = NetworkActivityPlugin { (changeType, targetType) in
            
            //changeType类型是NetworkActivityChangeType
            //通过它能监听到开始请求和结束请求
            
            //targetType类型是TargetType
            //就是我们这里的service
            //通过它能判断是那个请求
            
            
            if changeType == .began {
                //开始请求
                
                let targetType = targetType as! NetworkService
                
//                switch targetType {
//                case .sheetDetail, .login:
//                    DispatchQueue.main.async {
//                        //切换到主线程
//                        ToastUtil.showLoading()
//                    }
//
//                default:
//                    break
//                }
            }else {
                //结束请求
                
//                DispatchQueue.main.async {
//                    //切换到主线程
//                    ToastUtil.hideLoading()
//                }
            }
            
            
        }
        
        plugins.append(networkActivityPlugin)
        
        //网络请求签名加密插件
        plugins.append(NetworkPlugin())
        
        /// 创建Request的闭包
        /// 在这里能修改body
        /// 修改请求头
        let requestClosure={ (endpoint:Endpoint,closure:MoyaProvider.RequestResultClosure) in
//            do {
//                //获取到request
//                var request:URLRequest = try endpoint.urlRequest()
//
//                //处理request
//                //主要是实现参数签名和加密
//                let url = request.url!.absoluteString
//                let method = request.httpMethod!
//
//                print("Api requestClosure:\(url),\(method)")
//
//                //处理接口参数
//
//                //判断出需要添加签名的接口
//                if url.hasSuffix("v2/orders") && method.hasSuffix("POST") {
//                    //该接口需要添加参数签名到请求头
//
//                    //将body转为字符串
//                    let bodyString=String(data: request.httpBody!, encoding: .utf8)!
//
//                    //计算签名
//                    let sign=DigestUtil.sha1(bodyString)
//
//                    //添加到请求头
//                    request.allHTTPHeaderFields!["Sign"]=sign
//
//                    print("Api requestClosure sign param succes:\(url),\(method)")
//                }else if url.hasSuffix("v3/orders") && method.hasSuffix("POST") {
//                    //该接口需要参数加密
//
//                    //将body转为字符串
//                    let bodyString=String(data: request.httpBody!, encoding: .utf8)!
//
//                    //将参数加密
//                    let encryptBodyString=DigestUtil.encrypAES(bodyString)!
//
//                    //重新创建body
//                    let newBodyData=encryptBodyString.data(using: .utf8)
//
//                    //设置到request
//                    request.httpBody=newBodyData
//
//                    print("Api requestClosure encrypt param success:\(url),\(method)")
//                }
//
//                //end 处理request
//
//                //回调成功
//                closure(.success(request))
//            } catch MoyaError.requestMapping(let url) {
//                closure(.failure(MoyaError.requestMapping(url)))
//            }catch MoyaError.parameterEncoding(let error){
//                closure(.failure(MoyaError.parameterEncoding(error)))
//            }catch{
//                closure(.failure(MoyaError.underlying(error, nil)))
//            }
        }

        provider = MoyaProvider<NetworkService>(requestClosure:requestClosure, plugins: plugins)
    }
}
