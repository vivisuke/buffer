#pragma once

#include <exception>

class VectWchar {		//	単純1次元テキストバッファクラス
	enum {
		DEF_CAPA = 8,		//	デフォルトキャパシティ
	};
public:
	typedef wchar_t value_type;
	typedef int64_t pos_t;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
public:
	VectWchar(size_t sz = 0)
		: m_size(sz)
	{
		m_capacity = sz != 0 ? m_size * 2 : DEF_CAPA;
		m_data = new wchar_t[m_capacity];
	}
	~VectWchar()
	{
		delete [] m_data;
	}
public:
	bool	empty() const { return m_size == 0; }
	size_t	size() const { return m_size; }
	size_t	capacity() const { return m_capacity; }
	wchar_t operator[](pos_t pos) const { return m_data[pos]; }
public:
	wchar_t& operator[](pos_t pos) { return m_data[pos]; }
	void clear()
	{
		m_size = 0;
	}
	bool reserve(size_t sz)
	{
		size_t cp = capacity();
		if( sz <= cp ) return true;
		const size_t cp0 = cp;		//	以前のキャパシティ
		if( !cp ) cp = DEF_CAPA;
		while( sz > cp ) cp += cp;
		pointer data = new value_type[m_capacity = cp];
		if( !data ) {
			throw std::bad_alloc();
			return false;
		}
		memmove((void*)data, (void*)m_data, size()*sizeof(wchar_t));
		delete [] m_data;
		m_data = data;
		return true;
	}
	void push_back(wchar_t ch)
	{
		size_t cp = capacity();
		if( cp == size() ) {
			reserve(cp*2);
		}
		m_data[m_size++] = ch;
	}
	void push_front(wchar_t ch)
	{
		size_t cp = capacity();
		if( cp == size() ) {		//	capacity は０ではないと仮定
			reserve(cp*2);
		}
		memmove((void*)(m_data+1), (void*)m_data, size()*sizeof(wchar_t));
		++m_size;
		m_data[0] = ch;
	}
	void insert(pos_t pos, wchar_t ch)
	{
		if( pos > size() ) return;
		size_t cp = capacity();
		if( cp == size() ) {		//	capacity は０ではないと仮定
			reserve(cp*2);
		}
		if( pos < size() )
			memmove((void*)(m_data+pos+1), (void*)(m_data+pos), (size()-pos)*sizeof(wchar_t));
		++m_size;
		m_data[pos] = ch;
	}
	void pop_back()
	{
		if( empty() ) return;
		--m_size;
	}
	void pop_front()
	{
		if( empty() ) return;
		if( 1 < size() )
			memmove((void*)(m_data), (void*)(m_data+1), (size()-1)*sizeof(wchar_t));
		--m_size;
	}
	void erase(pos_t pos)
	{
		if( pos >= size() ) return;
		if( pos < size() - 1 )
			memmove((void*)(m_data+pos), (void*)(m_data+pos+1), (size()-pos-1)*sizeof(wchar_t));
		--m_size;
	}
	
private:
	size_t		m_size;			//	テキストサイズ
	size_t		m_capacity;		//	
	wchar_t*	m_data;
};

