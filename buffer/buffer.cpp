#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <assert.h>
using namespace std;

random_device g_rd;
#if	1
auto g_seed = g_rd();
mt19937 g_mt(g_seed);
#else
int g_seed = 0;
mt19937 g_mt(g_seed);
#endif

void test_ref();
void test_push_back();

int main()
{
	//test_ref();
	test_push_back();
#if	0
    wstring wstr = L"abc";
    wcout << wstr << "\n";
    //
    vector<wchar_t> wv;
    wv.push_back('x');
    wv.push_back('y');
    wv.push_back('z');
    wv.push_back('\0');
    wcout << &wv[0] << "\n";
#endif
    //
    std::cout << "\nOK\n";
}
void test_ref()
{
	if( true ) {
		const int SZ = 100*1024*1024;	//	100メガ
		vector<wchar_t> buf(SZ);
		for(auto& x: buf) x = g_mt() % 26 + '@';	//	'A' - 'Z'
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i != buf.size(); ++i) {
			if( buf[i] == '\0' )	//	ネバーマッチ、最適化されませんように（お祈り）
				break;
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "msec = " << msec << "\n";
	}
	if( true ) {
		const int SZ = 200*1024*1024;	//	200メガ
		vector<wchar_t> buf(SZ);
		for(auto& x: buf) x = g_mt() % 26 + '@';	//	'A' - 'Z'
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i != buf.size(); ++i) {
			if( buf[i] == '\0' )	//	ネバーマッチ、最適化されませんように（お祈り）
				break;
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "msec = " << msec << "\n";
	}
	if( true ) {
		const int SZ = 400*1024*1024;	//	400メガ
		vector<wchar_t> buf(SZ);
		for(auto& x: buf) x = g_mt() % 26 + '@';	//	'A' - 'Z'
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i != buf.size(); ++i) {
			if( buf[i] == '\0' )	//	ネバーマッチ、最適化されませんように（お祈り）
				break;
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "msec = " << msec << "\n";
	}
}
void test_push_back()
{
	if( true ) {
		const int SZ = 10*1024*1024;	//	10メガ
		vector<wchar_t> buf;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i != SZ; ++i) {
			buf.push_back('A');
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "msec = " << msec << "\n";
	}
	if( true ) {
		const int SZ = 20*1024*1024;	//	20メガ
		vector<wchar_t> buf;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i != SZ; ++i) {
			buf.push_back('A');
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "msec = " << msec << "\n";
	}
	if( true ) {
		const int SZ = 40*1024*1024;	//	40メガ
		vector<wchar_t> buf;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i != SZ; ++i) {
			buf.push_back('A');
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "msec = " << msec << "\n";
	}
	if( true ) {
		const int SZ = 80*1024*1024;	//	80メガ
		vector<wchar_t> buf;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int i = 0; i != SZ; ++i) {
			buf.push_back('A');
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "msec = " << msec << "\n";
	}
}
