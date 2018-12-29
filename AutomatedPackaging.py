#!/usr/bin/env python
#coding=utf-8 
import os
import requests
import webbrowser
import subprocess
import shutil

'''
使用注意事项:该脚本基于python3.6
1、将工程的编译设备选成 Gemeric iOS Device
2、command + B编译
3、执行脚本文件
    
'''

appFileFullPath = '/Users/sunze/Library/Developer/Xcode/DerivedData/ProjectTemplate-bjtixpbjgdbuhkadympinteawlie/Build/Products/Debug-iphonesimulator/ProjectTemplate.app'
PayLoadPath = '/Users/sunze/Desktop/Payload'
packBagPath = '/Users/sunze/Desktop/ProgramBag'

#将此处打开的链接改为蒲公英对应app的链接
openUrl = 'https://www.pgyer.com/ProjectTemplate'

#上传蒲公英
USER_KEY = "6b71a4b349b43f7fa8c712828b8d2101"
API_KEY = "d4055da8337fdded1b342c55394da796"

#上传蒲公英
def uploadIPA(IPAPath):
    if(IPAPath==''):
        print("\n*************** 没有找到对应上传的IPA包 *********************\n")
        return
    else:
        print("\n***************开始上传到蒲公英*********************\n")
        url='http://www.pgyer.com/apiv1/app/upload'
        data={
            'uKey':USER_KEY,
            '_api_key':API_KEY,
            'installType':'2',
            'password':'',
            'updateDescription':""
        }
        files={'file':open(IPAPath,'rb')}
        r=requests.post(url,data=data,files=files)

def openDownloadUrl():
    webbrowser.open(openUrl,new=1,autoraise=True)
    print ("\n*************** 更新成功 *********************\n")

#编译打包流程
def bulidIPA():
    
    #删除之前打包的ProgramBag文件夹
    subprocess.call(["rm","-rf",packBagPath])
    #创建PayLoad文件夹
    mkdir(PayLoadPath)
    #将app拷贝到PayLoadPath路径下
    subprocess.call(["cp","-r",appFileFullPath,PayLoadPath])
    #在桌面上创建packBagPath的文件夹
    subprocess.call(["mkdir","-p",packBagPath])
    #将PayLoadPath文件夹拷贝到packBagPath文件夹下
    subprocess.call(["cp","-r",PayLoadPath,packBagPath])
    #删除桌面的PayLoadPath文件夹
    subprocess.call(["rm","-rf",PayLoadPath])
    #切换到当前目录
    os.chdir(packBagPath)
    #压缩packBagPath文件夹下的PayLoadPath文件夹夹
    subprocess.call(["zip","-r","./Payload.zip","."])
    print ("\n*************** 打包成功 *********************\n")
    #将zip文件改名为ipa
    subprocess.call(["mv","payload.zip","Payload.ipa"])
    #删除payLoad文件夹
    subprocess.call(["rm","-rf","./Payload"])


#创建PayLoad文件夹
def mkdir(PayLoadPath):
    isExists = os.path.exists(PayLoadPath)
    if not isExists:
        os.makedirs(PayLoadPath)
        print(PayLoadPath + '创建成功')
        return True
    else:
        print (PayLoadPath + '目录已经存在')
        return False


if __name__ == '__main__':
    des = input("发布第一个测试版本")
    bulidIPA()
    uploadIPA('%s/Payload.ipa'%packBagPath)
    openDownloadUrl()


    



    

