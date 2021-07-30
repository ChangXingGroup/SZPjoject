//
//  NetworkPlugin.swift
//  NetworkService
//
//  Created by !>-<! on 2021/7/29.
//  Copyright © 2021 !>-<!. All rights reserved.
//

import Foundation

//导入网络框架
import Moya

public final class NetworkPlugin: PluginType {
    /// 在完成（completion）前调用
    /// 所以可以在这里校验响应签名是否正确
    /// 当然也可以完成接口响应的解密
    ///
    /// - Parameters:
    ///   - result: <#result description#>
    ///   - target: <#target description#>
    /// - Returns: <#return value description#>
    public func process(_ result: Result<Response, MoyaError>, target: TargetType) -> Result<Response, MoyaError> {
        print("NetworkPlugin process:\(result)")
        
//        switch result{
//        case let .success(response):
//            //请求成功
//            
//            //获取response
//            let urlResponse=response.response as! HTTPURLResponse
//            
//            //获取响应数据
//            let data=response.data
//            
//            //判断是否有签名头
//            if let sign=urlResponse.allHeaderFields["Sign"] as? String{
//                //有签名
//                //所以说要校验数据
//                
//                //将返回的数据转为字符串
//                let dataString=String(bytes: data, encoding: .utf8)!
//                
//                //获取本地数据签名
//                let localSign=DigestUtil.sha1(dataString)
//                
//                //判断签名
//                if localSign==sign {
//                    //签名正确
//                    //什么也不做
//                    print("NetworkPlugin process sign correct:\(target)")
//                }else{
//                    //签名错误
//                    print("NetworkPlugin process sign incorrect:\(target)")
//                    
//                    //抛出异常
//                    //让后续的代码处理
//                    //由于不能自定义错误
//                    //就返回一个字符串映射错误就行了
//                    return Result.failure(MoyaError.stringMapping(response))
//                }
//            }else{
//                //没有签名
//                
//                //什么不处理
//                
//                //真实项目中
//                //如果所有接口响应有签名
//                //如果判断没有签名
//                //就直接抛出错误
//                print("NetworkPlugin process not sign:\(target)")
//            }
//            
//            
//            //响应解密
//            if target.path.hasSuffix("v3/orders") && target.method == .get {
//                //该接口响应需要解密
//                
//                //真实项目中可能所有接口都会加密
//                //所以就不用判断了
//                
//                //我们这里为了降低课程难度
//                //所以只加密这个几个接口
//                
//                //将响应data转为字符串
//                var dataString=String(data: data, encoding: .utf8)!
//                
//                //新接口加密数据格式
//                //{"status":0,"data":"这是加密数据"}
//                
//                //解析为字典
//                //也可以解析为对象
//                var dict=JSONUtil.toDictionary(dataString)!
//                
//                //获取data
//                dataString=dict["data"] as! String
//                
//                //数据解密
//                if let decryptString = DigestUtil.decryptAES(dataString) {
//                    //解密成功
//                    
//                    //就认为数据没问题
//                    
//                    //将解密后的值解析为字典
//                    let dataDict=JSONUtil.toDictionary(decryptString)!
//                    
//                    //设置到最外层dict
//                    dict["data"]=dataDict
//                    
//                    //将解密后的字段转为data
//                    let data = try! JSONSerialization.data(withJSONObject: dict, options: [])
//                    
//                    //创建新的Moya.Response
//                    //因为要更改data
//                    //原来的Response是只读
//                    let newResponse=Moya.Response(statusCode: response.statusCode, data: data, request: response.request, response: urlResponse)
//                    
//                    print("NetworkPlugin process decrypt success:\(target)")
//                    
//                    //返回新建Result
//                    return Result.success(newResponse)
//                }else{
//                    //解密失败
//                    
//                    print("NetworkPlugin process decrypt error:\(target)")
//                    
//                    //抛出异常
//                    return Result.failure(MoyaError.stringMapping(response))
//                }
//            }
//            
//        case .failure(_):
//            //失败
//            
//            //这里不处理
//            //让后续自动处理
//            break
//        }
        
        return result
    }
}
