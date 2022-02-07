#include<iostream>
#include<fstream>
#include<cstdlib>
#include"datafile.h"
using namespace std;




//复制文件。
void copyFile()
{
	char ch;
	ifstream sfile("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\第九章——流类库与输入输出\\Project1\\text_src.txt");
	ofstream dfile("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\第九章——流类库与输入输出\\Project1\\text_dst.txt");
	if (!sfile)//判断流状态，跟ios::fail()等效
	{
		cout << "打开源文件失败" << endl;
	}
	if (!dfile)
	{
		cout << "打开目标文件失败" << endl;
	}
	sfile.unsetf(ios::skipws);
	while (sfile >> ch)dfile << ch;
	sfile.close();
	dfile.close();
}

//按行复制文本文件。
void copyFileLine()
{
	fstream sfile, dfile;
	sfile.open("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\第九章——流类库与输入输出\\Project1\\text_src.txt", ios::in);
	if (!sfile)//判断流状态，跟ios::fail()等效
	{
		cout << "打开源文件失败" << endl;
		sfile.clear(0);//之后可以才重新提取
		exit(-1);
	}

	dfile.open("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\第九章——流类库与输入输出\\Project1\\text_dst.txt", ios::out);
	if (!dfile)
	{
		cout << "创建目录失败" << endl;
		exit(-1);
	}
	char buf[100];

	while (sfile.getline(buf, 100), sfile.eof() != 1)//要求必须最后以\n结束
	{
		if (sfile)dfile << buf << '\n';//如果状态字正常，说明遇到了\n结束，但getline不会提取\n
		else { dfile << buf; sfile.clear(0); }
	}
	sfile.close();
	dfile.close();

}

void datafilefunc()
{
	inventory car1("夏利1", "1", 156, 800, 105), car2;
	inventory motor1("金城2", "2", 302, 1000, 130), motor2;

	ofstream distfile("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\第九章——流类库与输入输出\\Project1\\example.data");
	distfile << car1 << motor1;
	distfile.close();

	cout << car1;
	cout << motor1;
	cout << car2;
	cout << motor2;

	ifstream sourfile("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\第九章——流类库与输入输出\\Project1\\example.data");
	sourfile >> car2 >> motor2;
	sourfile.close();
	cout << car2;
	cout << motor2;
}

void binDataFileFunc()
{
	inventory car1("夏利1", "1", 156, 800, 105), car2;
	inventory motor1("金城2", "2", 302, 1000, 130), motor2;
	ofstream ddatafile("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\第九章——流类库与输入输出\\Project1\\example.data", ios::out | ios::binary);
	car1.Bdatatofile(ddatafile);//打开文件这部分可以放在构造函数内实现。
	motor1.Bdatatofile(ddatafile);
	cout << car1;
	cout << motor1;
	cout << car2;
	cout << motor2;

	ddatafile.close();
	ifstream sdatafile("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\第九章——流类库与输入输出\\Project1\\example.data", ios::in | ios::binary);
	car2.Bdatafromfile(sdatafile);
	if (sdatafile)cout << "读文件成功" << endl;
	cout << car2;
	motor2.Bdatafromfile(sdatafile);
	if (sdatafile)cout << "读文件成功" << endl;
	cout << motor2;
	sdatafile.close();

}

void radBinDataFileFunc()
{
	inventory car1("夏利1", "1", 156, 800, 105), car2;
	inventory motor1("金城2", "2", 302, 1000, 130), motor2;
	fstream datafile("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\第九章——流类库与输入输出\\Project1\\example.data", ios::out | ios::in | ios::binary);
	if (!datafile)
	{
		datafile.clear(0);
		datafile.open("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\第九章——流类库与输入输出\\Project1\\example.data", ios::out);
		datafile.close();
		datafile.open("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\第九章——流类库与输入输出\\Project1\\example.data", ios::out | ios::in | ios::binary);
	}

	car1.Bdatatofile(datafile);
	motor1.Bdatatofile(datafile);

	datafile.seekg(50, ios::beg);//实现随机访问，先访问后一个对象
	motor2.Bdatafromfile(datafile);

	datafile.seekg(0, ios::beg);
	car2.Bdatafromfile(datafile);

	cout << motor2;
	cout << car2;

}

void objectFileFunc()
{
	Array<inventory> mylist;
	inventory temp;
	char ch;
	cout << "是否输入新商品？" << endl;
	cin >> ch;
	while (ch == 'Y' || ch == 'y') {
		cin.get();//吸收回车
		cin >> temp;
		mylist.ordinsert(temp);
		cout << "是否继续输入?" << endl;
		cin >> ch;
	}
	cout << mylist;

}

int main7()
{
	objectFileFunc();
	return 0;
}
