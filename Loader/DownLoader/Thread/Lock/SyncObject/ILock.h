#pragma once

namespace DownLoader{

	/*@class
	*******************************************************************
	模块:  Thread
	文件:  ILock.h
	功能:  接口类：锁
	作者:  Aijiawei 2021/04/23
	*******************************************************************/
	class ILock
	{
	public:
		virtual ~ILock(){ };

	public:
		virtual bool Lock() = 0;
		virtual bool Unlock() = 0;
	};
}
