#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <random>
#include <assert.h>
#include "VectWchar.h"
#include "gap_buffer.h"
#include "my_vector.h"
#include "StringList.h"

using namespace std;

random_device g_rd;
#if	1
auto g_seed = g_rd();
mt19937 g_mt(g_seed);
#else
int g_seed = 0;
mt19937 g_mt(g_seed);
#endif

//typedef list<string> ListString;

void test_ref();
void test_push_back();
void test_push_front();
void test_insert();
void test_erase();
void test_VectWchar();
void test_my_vector();
void test_StringList();
void test_gap_vetor();
void test_list_wstring();
void test_list_cache();
void test_scroll();
void measure_arrayIndexOp();
void measure_push_back();
void measure_push_front();
void measure_pop_back();
//void measure_StringList0();
void measure_StringList();
void measure_insert5();			//	5文字ごとに文字挿入

int main()
{
	//test_ref();
	//test_push_back();
	test_push_front();
	test_insert();
	test_erase();
	//test_VectWchar();
	//test_my_vector();
	//test_StringList();
	//test_gap_vetor();
	//test_list_wstring();
	//test_list_cache();
	//test_scroll();
	
	//measure_arrayIndexOp();
	//measure_push_back();
	//measure_push_front();
	//measure_pop_back();
	//measure_StringList0();
	//measure_StringList();
	measure_insert5();
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
void test_push_front()
{
	cout << "test_push_front(): ";
	typedef char Type;
	const int LOOP = 1000;
	vector<char> v;
	my_vector<char> mv;
	gap_buffer<char> gv;
	for (int i = 0; i < LOOP; ++i) {
		Type ch = 'a' + g_mt() % 26;		//	'a' - 'z'
		v.insert(v.begin(), ch);
		mv.push_front(ch);
		gv.push_front(ch);
	}
	assert( v.size() == LOOP );
	assert( mv.size() == LOOP );
	assert( gv.size() == LOOP );
	for (int i = 0; i < LOOP; ++i) {
		assert( v[i] == mv[i] );
		assert( v[i] == gv[i] );
	}
	cout << "OK\n";
}
void test_insert()
{
	cout << "test_insert(): ";
	typedef char Type;
	const int LOOP = 1000;
	vector<char> v;
	my_vector<char> mv;
	gap_buffer<char> gv;
	for (int i = 0; i < LOOP; ++i) {
		int ix = g_mt() % (v.size() + 1);
		Type ch = 'a' + g_mt() % 26;		//	'a' - 'z'
		v.insert(v.begin() + ix, ch);
		mv.insert(ix, ch);
		gv.insert(ix, ch);
	}
	assert( v.size() == LOOP );
	assert( mv.size() == LOOP );
	assert( gv.size() == LOOP );
	for (int i = 0; i < LOOP; ++i) {
		assert( v[i] == mv[i] );
		assert( v[i] == gv[i] );
	}
	cout << "OK\n";
}
void test_erase()
{
	cout << "test_erase(): ";
	typedef char Type;
	const int LOOP = 1000;
	vector<char> v;
	my_vector<char> mv;
	gap_buffer<char> gv;
	const int LOOP2 = LOOP * 2;
	for (int i = 0; i < LOOP2; ++i) {
		int ix = g_mt() % (v.size() + 1);
		Type ch = 'a' + g_mt() % 26;		//	'a' - 'z'
		v.insert(v.begin() + ix, ch);
		mv.insert(ix, ch);
		gv.insert(ix, ch);
	}
	assert( v.size() == LOOP2 );
	assert( mv.size() == LOOP2 );
	assert( gv.size() == LOOP2 );
	for (int i = 0; i < LOOP; ++i) {
		int ix = g_mt() % v.size();
		v.erase(v.begin() + ix);
		mv.erase(ix);
		gv.erase(ix);
	}
	assert(v.size() == LOOP);
	assert(mv.size() == LOOP);
	assert(gv.size() == LOOP);
	for (int i = 0; i < LOOP; ++i) {
		assert( v[i] == mv[i] );
		assert( v[i] == gv[i] );
	}
	cout << "OK\n";
}
//----------------------------------------------------------------------
list<wstring> g_list;
int g_cachedLine = -1;
list<wstring>::iterator g_cachedItr;

list<wstring>::iterator lnToItr(int ln)
{
	if( g_cachedLine >= 0 ) {
	}
	if( ln <= g_list.size() / 2 ) {
		list<wstring>::iterator itr = g_list.begin();
		while( ln > 0 ) {
			++itr;
			--ln;
		}
		return itr;
	} else {
		list<wstring>::iterator itr = g_list.end();
		do {
			--itr;
		} while (++ln < g_list.size());
		return itr;
	}
}

wchar_t charAt(int l, int o) {
	auto itr = g_list.begin();
	while (l > 0) { ++itr; --l; }
	return (*itr)[o];
}
void eraseAt(int l, int o) {
	auto itr = g_list.begin();
	while (l > 0) { ++itr; --l; }	//	行ｌまで移動
	itr->erase(itr->begin() + o);
}
void insertAt(int l, int o, wchar_t ch) {
	auto itr = g_list.begin();
	while (l > 0) { ++itr; --l; }	//	行ｌまで移動
	itr->insert(itr->begin() + o, ch);
}
void test_list_wstring()
{
	if( true ) {
		g_list.clear();
		wstring t = L"1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\n";	//	100文字
		for (int i = 0; i < 10000; ++i) {
			g_list.push_back(t);
		}
	}
}
//----------------------------------------------------------------------
vector<wchar_t>		g_vecBuf;				//	単なる vector<wchar_t> によるバッファ
vector<int>			g_vecLineStartPos;		//	各行の先頭位置
void initVecBuf()
{
	g_vecBuf.clear();
	g_vecLineStartPos.clear();
	g_vecLineStartPos.push_back(0);		//	for EOF line
}
void wstrncpy(wchar_t* dst, const wchar_t* src, int sz)
{
	while( --sz >= 0 ) {
		*dst++ = *src++;
	}
}
void pushBackLine(const wstring& str)
{
	auto sz = g_vecBuf.size();
	g_vecBuf.resize(g_vecBuf.size() + str.size());
	wstrncpy(&g_vecBuf[sz], &str[0], str.size());
	//wcsncpy_s(&g_vecBuf[sz], g_vecBuf.size(), &str[0], str.size());
	g_vecLineStartPos.push_back(g_vecBuf.size());
}
void test_scroll()
{
	wstring str = L"1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\n";	//	100文字
	for (int i = 0; i < 10000; ++i) {
		pushBackLine(str);
	}
	//cout 
}
//----------------------------------------------------------------------
bool isEqual(const VectWchar& vw, const string& str)
{
	if( vw.size() != str.size() ) return false;
	for(int i = 0; i != str.size(); ++i) {
		if( vw[i] != str[i] ) return false;
	}
	return true;
}
void test_VectWchar()
{
	cout << "VectWchar:\n";
	VectWchar vw;
	assert( vw.size() == 0 );
	const int N = 10;
	for (int i = 0; i < N; ++i) {
		vw.push_back('a'+i);
	}
	assert( vw.size() == N );
	cout << "capacity = " << vw.capacity() << "\n";
	for (int i = 0; i < N; ++i) {
		assert( vw[i] == 'a'+i );
	}
	assert( isEqual(vw, "abcdefghij") );
	vw.pop_back();
	assert( isEqual(vw, "abcdefghi") );
	vw.pop_front();
	assert( isEqual(vw, "bcdefghi") );
	vw.erase(2);
	assert( isEqual(vw, "bcefghi") );
	vw.insert(3, 'X');
	assert( isEqual(vw, "bceXfghi") );
	//
	//	push_back
	if (true) {
		cout << "push_back():\n";
		const int N = 10;		//	10メガ～100メガ文字
		//const int N = 100;		//	100メガ～1000メガ文字
		for (int n = 1; n <= 10; ++n) {
			VectWchar vw;
			const int LOOP = 1024 * 1024 * n * N;
			auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
			for (int i = 0; i < LOOP; ++i) {
				vw.push_back('a');
			}
			auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
			auto dur = end - start;        // 要した時間を計算
			auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
			cout << "LOOP = " << n * N << "Mega chars, ";
			cout << "msec = " << msec << "\n";
		}
	}
	//	push_front
	if (true) {
		cout << "push_front():\n";
		//const int N = 1;		//	1キロ～10キロ文字
		const int N = 10;		//	10キロ～100キロ文字
		//const int N = 100;		//	100キロ～1000キロ文字
		for (int n = 1; n <= 10; ++n) {
			VectWchar vw;
			const int LOOP = 1024 * n * N;
			auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
			for (int i = 0; i < LOOP; ++i) {
				vw.push_front('a');
			}
			auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
			auto dur = end - start;        // 要した時間を計算
			auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
			cout << "LOOP = " << n * N << "Kilo chars, ";
			cout << "msec = " << msec << "\n";
		}
	}
}
bool isEqual(const my_vector<wchar_t>& vw, const string& str)
{
	if( vw.size() != str.size() ) return false;
	for(int i = 0; i != str.size(); ++i) {
		if( vw[i] != str[i] ) return false;
	}
	return true;
}
void test_my_vector()
{
	cout << "my_vector:\n";
	my_vector<wchar_t> vw;
	assert( vw.size() == 0 );
	const int N = 10;
	for (int i = 0; i < N; ++i) {
		vw.push_back('a'+i);
	}
	assert( vw.size() == N );
	cout << "capacity = " << vw.capacity() << "\n";
	for (int i = 0; i < N; ++i) {
		assert( vw[i] == 'a'+i );
	}
	assert( isEqual(vw, "abcdefghij") );
	vw.pop_back();
	assert( isEqual(vw, "abcdefghi") );
	vw.pop_front();
	assert( isEqual(vw, "bcdefghi") );
	vw.erase(2);
	assert( isEqual(vw, "bcefghi") );
	vw.insert(3, 'X');
	assert( isEqual(vw, "bceXfghi") );
	//
}
void test_gap_vetor()
{
	cout << "gap_buffer<wchar_t>:\n";
	//	push_back
	if (true) {
		cout << "push_back():\n";
		const int N = 10;		//	10メガ～100メガ文字
		//const int N = 100;		//	100メガ～1000メガ文字
		for (int n = 1; n <= 10; ++n) {
			gap_buffer<wchar_t> gvw;
			const int LOOP = 1024 * 1024 * n * N;
			auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
			for (int i = 0; i < LOOP; ++i) {
				gvw.push_back('a');
			}
			auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
			auto dur = end - start;        // 要した時間を計算
			auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
			cout << "LOOP = " << n * N << "Mega chars, ";
			cout << "msec = " << msec << "\n";
		}
	}
	//	push_front
	if (false) {
		cout << "push_front():\n";
		//const int N = 1;		//	1キロ～10キロ文字
		const int N = 10;		//	10キロ～100キロ文字
		//const int N = 100;		//	100キロ～1000キロ文字
		for (int n = 1; n <= 10; ++n) {
			gap_buffer<wchar_t> gvw;
			const int LOOP = 1024 * n * N;
			auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
			for (int i = 0; i < LOOP; ++i) {
				gvw.push_front('a');
			}
			auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
			auto dur = end - start;        // 要した時間を計算
			auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
			cout << "LOOP = " << n * N << "Kilo chars, ";
			cout << "msec = " << msec << "\n";
		}
	}
	if (true) {
		cout << "push_front():\n";
		const int N = 10;		//	10メガ～100メガ文字
		//const int N = 100;		//	100メガ～1000メガ文字
		for (int n = 1; n <= 10; ++n) {
			gap_buffer<wchar_t> gvw;
			const int LOOP = 1024 * 1024 * n * N;
			auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
			for (int i = 0; i < LOOP; ++i) {
				gvw.push_front('a');
			}
			auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
			auto dur = end - start;        // 要した時間を計算
			auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
			cout << "LOOP = " << n * N << "Mega chars, ";
			cout << "msec = " << msec << "\n";
		}
	}
}
//	100メガ文字～500メガ（step 100メガ）参照時間計測
void measure_arrayIndexOp()
{
	const int LOOP = 10;
	//const int SZ = 500*1024*1024;
	const int STEP = 50*1024*1024;
	const int SZ = STEP * LOOP;
	char *arr = new char[SZ];
	//for(auto& x: arr) x = 'a' + g_mt() % 26;
#ifndef _DEBUG
	for(int i = 0; i != SZ; ++i) arr[i] = 'a' + g_mt() % 26;
#endif
	vector<int64_t> lst;
	//
	cout << "array[]:\n";
	for (int i = 1; i <= LOOP; ++i) {
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		int sum = 0;
		for (int k = 0; k < i * STEP; ++k) {
			volatile auto t = sum + arr[k];
			sum = t;
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << STEP*i/(1024*1024) << "Mega: ";
		//cout << "sum = " << (int)sum << " ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
	//
	cout << "my_vector::operator[]:\n";
	my_vector<char> mv(SZ);
	for(int i = 0; i != SZ; ++i) mv[i] = arr[i];
	for (int i = 1; i <= LOOP; ++i) {
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		int sum = 0;
		for (int k = 0; k < i * STEP; ++k) {
			volatile auto t = sum + mv[k];
			sum = t;
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << STEP*i/(1024*1024) << "Mega: ";
		//cout << "sum = " << (int)sum << " ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
	//
	cout << "gap_buffer::operator[]:\n";
	gap_buffer<char> gv(SZ);
	for(int i = 0; i != SZ; ++i) gv[i] = arr[i];
	for (int i = 1; i <= LOOP; ++i) {
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		int sum = 0;
		for (int k = 0; k < i * STEP; ++k) {
			volatile auto t = sum + gv[k];
			sum = t;
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << STEP*i/(1024*1024) << "Mega: ";
		//cout << "sum = " << (int)sum << " ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
	delete [] arr;
}
void measure_push_back()
{
	const int LOOP = 10;
	const int STEP = 20*1024*1024;
	const int SZ = STEP * LOOP;
	//
	cout << "vector::push_back():\n";
	for (int i = 1; i <= LOOP; ++i) {
		vector<char> v;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int k = 0; k < i * STEP; ++k) {
			v.push_back('a' + (g_mt() % 26));
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << STEP*i/(1024*1024) << "Mega: ";
		cout << "msec = " << msec << "\n";
	}
	//
	cout << "my_vector::push_back():\n";
	for (int i = 1; i <= LOOP; ++i) {
		my_vector<char> mv;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int k = 0; k < i * STEP; ++k) {
			mv.push_back('a' + (g_mt() % 26));
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << STEP*i/(1024*1024) << "Mega: ";
		cout << "msec = " << msec << "\n";
	}
	//
	cout << "gap_buffer::push_back():\n";
	for (int i = 1; i <= LOOP; ++i) {
		gap_buffer<char> gv;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int k = 0; k < i * STEP; ++k) {
			gv.push_back('a' + (g_mt() % 26));
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << STEP*i/(1024*1024) << "Mega: ";
		cout << "msec = " << msec << "\n";
	}
}
void measure_push_front()
{
	const int LOOP = 15;
	const int STEP = 20*1024;
	//const int STEP = 20*1024*1024;
	const int SZ = STEP * LOOP;
	vector<int64_t> lst;
	//
	cout << "vector::push_front():\n";
	for (int i = 1; i <= LOOP; ++i) {
		vector<char> v;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int k = 0; k < i * STEP; ++k) {
			v.insert(v.begin(), 'a' + (g_mt() % 26));
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << STEP*i/(1024) << "Kilo: ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
	//
	cout << "my_vector::push_front():\n";
	for (int i = 1; i <= LOOP; ++i) {
		my_vector<char> mv;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int k = 0; k < i * STEP; ++k) {
			mv.push_front('a' + (g_mt() % 26));
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << STEP*i/(1024) << "Kilo: ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
	//
	cout << "gap_buffer::push_front():\n";
	for (int i = 1; i <= LOOP; ++i) {
		gap_buffer<char> gv;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int k = 0; k < i * STEP; ++k) {
			gv.push_front('a' + (g_mt() % 26));
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << STEP*i/(1024) << "Kilo: ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
}
void measure_pop_back()
{
	const int LOOP = 10;
	const int STEP = 100*1024*1024;
	const int SZ = STEP * LOOP;
	vector<int64_t> lst;
	//
	cout << "vector::pop_back():\n";
	for (int i = 1; i <= LOOP; ++i) {
		vector<char> v(i*STEP, 'a');
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		//for (int k = 0; k < i * STEP; ++k)
		while( !v.empty() )
		{
			v.pop_back();
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << STEP*i/(1024*1024) << "Mega: ";
		cout << "msec = " << msec << "\n";
		//cout << "v.size() = " << v.size() << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
	//
	cout << "vector::pop_back():\n";
	for (int i = 1; i <= LOOP; ++i) {
		my_vector<char> v(i*STEP);
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		//for (int k = 0; k < i * STEP; ++k)
		while( !v.empty() )
		{
			v.pop_back();
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << STEP*i/(1024*1024) << "Mega: ";
		cout << "msec = " << msec << "\n";
		//cout << "v.size() = " << v.size() << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
}
void test_StringList()
{
	const int LEN = 80;		//	行長
	StringList sl;
	for (int i = 0; i < 10; ++i) {
		string txt(LEN, 'a' + i);
		sl.push_back(txt);
	}
	assert( sl.size() == 10 );
	assert( sl.charAt(0, 0) == 'a' );
}
#if	0
void measure_StringList0()
{
	cout << "\ninsert5:\n";
	const int LOOP = 10;
#ifdef _DEBUG
	const int STEP = 1 * 1024;
#else
	const int STEP = 20 * 1024;
#endif // DEBUG
	const int LEN = 80;		//	行長
	string txt(LEN, 'a');
	//
	vector<int64_t> lst;
	cout << "list<string>:\n";
	StringList strlst;
	for (int i = 1; i <= LOOP; ++i) {
		const int SZI = STEP * i;
		for (int k = 0; k < SZI; ++k) {
			strlst.push_back(txt);
		}
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (auto itr = strlst.begin(); itr != strlst.end(); ++itr) {
			auto& t = *itr;
			int ix = 5;
			while( ix <= t.size() ) {
				t.insert(t.begin() + ix, 'X');
				ix += 1 + 5;
			}
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << SZI/1024 << "Kilo: ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
	//
}
#endif
void measure_StringList()
{
	const int LOOP = 10;
#ifdef _DEBUG
	const int STEP = 1 * 1024;
#else
	const int STEP = 2 * 1024;
#endif // DEBUG

	const int LEN = 80;		//	行長
	string txt(LEN, 'a');
	for(auto& x: txt) x = 'a' + g_mt() % 26;
	StringList strlst;
	const int SZ = STEP * LOOP;
	for (int k = 0; k < SZ*100; ++k) {
		strlst.push_back(txt);
	}
	vector<int64_t> lst;
	//
	cout << "findIterator():\n";
	for (int i = 1; i <= LOOP; ++i) {
		int sum = 0;
		const int SZI = STEP * i;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int k = 0; k < SZI; ++k) {
			auto itr = strlst.findIterator(k);
			sum += itr->size();
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "sum = " << sum << " ";
		cout << STEP*i/1024 << "Kilo: ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
	//
	cout << "findIteratorCached():\n";
	for (int i = 1; i <= LOOP; ++i) {
		int sum = 0;
		const int SZI = STEP * i;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int k = 0; k < SZI; ++k) {
			auto itr = strlst.findIteratorCached(k);
			sum += itr->size();
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "sum = " << sum << " ";
		cout << SZI/1024 << "Kilo: ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
	//
	cout << "findIteratorCached() * 100:\n";
	for (int i = 1; i <= LOOP; ++i) {
		int sum = 0;
		const int SZI = STEP * i * 100;
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (int k = 0; k < SZI; ++k) {
			auto itr = strlst.findIteratorCached(k);
			sum += itr->size();
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << "sum = " << sum << " ";
		cout << SZI/1024 << "Kilo: ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
}
void measure_insert5()
{
	cout << "\ninsert5:\n";
	const int LOOP = 10;
	const int STEP1 = 100;
#ifdef _DEBUG
	const int STEP = 1 * 1024;
#else
	const int STEP = 20 * 1024;
#endif // DEBUG
	const int LEN = 80;		//	行長
	string txt(LEN, 'a');
	//
	vector<int64_t> lst;
	//
	cout << "vector<char>:\n";
	vector<char> v;
	for (int i = 1; i <= LOOP; ++i) {
		const int SZI = STEP1 * i;
		for (int k = 0; k < SZI; ++k) {
			//v.insert(v.size(), &txt[0], &txt[txt.size()-1]);
			for(auto c: txt) v.push_back(c);
		}
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		int ix = 5;
		while( ix <= v.size() ) {
			v.insert(v.begin() + ix, 'X');
			ix += 1 + 5;
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << SZI << ": ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
	//
	cout << "list<string>:\n";
	StringList strlst;
	for (int i = 1; i <= LOOP; ++i) {
		const int SZI = STEP * i;
		for (int k = 0; k < SZI; ++k) {
			strlst.push_back(txt);
		}
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		for (auto itr = strlst.begin(); itr != strlst.end(); ++itr) {
			auto& t = *itr;
			int ix = 5;
			while( ix <= t.size() ) {
				t.insert(t.begin() + ix, 'X');
				ix += 1 + 5;
			}
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << SZI/1024 << "Kilo: ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
	//
	cout << "gap_buffer:\n";
	gap_buffer<char> gv;
	for (int i = 1; i <= LOOP; ++i) {
		const int SZI = STEP * i;
		for (int k = 0; k < SZI; ++k) {
			gv.insert(gv.size(), &txt[0], txt.size());
		}
		auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
		int ix = 5;
		while( ix <= gv.size() ) {
			gv.insert(ix, 'X');
			ix += 1 + 5;
		}
		auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
		auto dur = end - start;        // 要した時間を計算
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		cout << SZI/1024 << "Kilo: ";
		cout << "msec = " << msec << "\n";
		lst.push_back(msec);
	}
	for(auto x: lst) { cout << x << ","; } cout << "\n";
	lst.clear();
}
