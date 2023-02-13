// SplitStr.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void Split(string strSign, string& strSour, vector<string>& r)
{
	if(strSign.length() > 0 && strSour.length() > 0)
	{
		string::size_type found =  strSour.find(strSign);
		if(found!=std::string::npos)
		{
			string strPart1;
			string strPart2;
			int nSize = strSour.size();

			strPart1 = strSour.substr(0,found);
			strPart2 = strSour.substr(found+1,nSize);

			r.push_back(strPart1);
			if(strPart2.length() > 0)//middle
			{
				Split(strSign,strPart2,r);
			} 
		} 
		else if(strSour.c_str())//the last one doesn't have sign
		{
			r.push_back(strSour);
		}
	}
}

void MapKeyValue(string strSign, string& strSour, map<string,string>& r)
{
	if (strSign.length() > 0 && strSour.length() > 0)
	{
		size_t pos =  strSour.find(strSign);
		if(pos != string::npos)
		{
			string strPart1;
			string strPart2;
			int nSize = strSour.size();

			strPart1 = strSour.substr(0,pos);
			strPart2 = strSour.substr(pos+1,nSize);

			if (strPart1.length() > 0 && strPart2.length() > 0)
			{
				if (!r[strPart1].length())
				{
					r[strPart1] = strPart2;
				}			
			}
		}
	}
}

void GetKeyValue(string& strSour, map<string,string>& r)
{
	vector<string> temp;
	//1. split  by sign ';'
	Split(";",strSour,temp);

	//2. split by sign ':' Map key and value
	for(int i=0; i<(int)temp.size(); i++) 
	{
		MapKeyValue(":",temp[i],r);
	}

	//3. release
	temp.clear();
}

struct CMD
{
	char*pStr;
	int i;
};

	int _tmain(int argc, _TCHAR* argv[])
	{
		CMD* pCmd = new CMD;
		CMD* pCmd1 = new CMD();
		
		string strFaceNameKey = "FaceName";
		string strFaceNameValue;
		string strFontSizeKey = "FontSize";
		int nFontSizeValue = 0;

		string strSour = "FaceName:;FaceName:Tahoma2;FontSize:;FontSize:13";
		map<string,string> mapKeyValue;
		GetKeyValue(strSour, mapKeyValue);

		for(map<string,string>::iterator it = mapKeyValue.begin(); it != mapKeyValue.end(); it++)
		{
			if (it->first == strFaceNameKey)
			{
				strFaceNameValue = it->second;
			}
			else if (it ->first == strFontSizeKey)
			{
				nFontSizeValue = atoi(it->second.c_str());
			}
		}

		//print 
		cout << strFaceNameKey<< ":" << strFaceNameValue<< endl;
		cout << strFontSizeKey<< ":" << nFontSizeValue<< endl;

		char a;
		cin >> a;

		return 0;
	}
	


// #include "stdafx.h"
// #include <string>
// #include <vector>
// #include <iostream>
// using namespace std;
// 
// void Split(string strSign, string& strSour, vector<string>& r)
// {
// 	if (strSign.length() > 0 && strSour.length() > 0)
// 	{
// 		string::size_type found =  strSour.find(strSign);
// 		if(found!=std::string::npos)
// 		{
// 			string strPart1;
// 			string strPart2;
// 
// 			int nSize = strSour.size();
// 			strPart1 = strSour.substr(0,found);
// 			strPart2 = strSour.substr(found+1,nSize);
// 			r.push_back(strPart1);
// 			if (strPart2.c_str())
// 			{
// 				Split(strSign,strPart2,r);
// 			}
// 		}
// 		else if (strSour.c_str())
// 		{
// 			r.push_back(strSour);
// 		}
// 	}
// }
// 
// int _tmain(int argc, _TCHAR* argv[])
// {
// 	string strFaceNameKey;
// 	string strFaceNameValue;
// 	string strFontSizeKey;
// 	int nFontSizeValue = 0;
// 	
// 	string strSour = "FaceName:Tahoma;FontSize:12";
// 
// 	vector<string> r;
// 	Split(";",strSour,r);
// 	
// 	vector<string> Temp;
// 	for (int i=0; i<r.size();i++)
// 	{
// 		Split(":",r[i],Temp);
// 	}
// 
// 	r.clear();
// 
// 	for (int i = 0; i < Temp.size(); i+=2)
// 	{
// 		if (0 == strcmp(Temp[i].c_str(),"FaceName"))
// 		{
// 			strFaceNameValue = Temp[i+1];
// 		}
// 		else if (0 == strcmp(Temp[i].c_str(),"FontSize"))
// 		{
// 			nFontSizeValue = atoi(Temp[i+1].c_str());
// 		}
// 	}
// 	
// 	Temp.clear();
// 
// 	cout << strFaceNameValue << nFontSizeValue << endl;
// 	getchar();
// 	return 0;
// }

