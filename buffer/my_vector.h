#pragma once

template<typename Type>
class my_vector
{
	enum {
		DEFAULT_BUFFER_SIZE = 8,
	};
public:
	//typedef wchar_t value_type;
	typedef Type value_type;
	typedef int64_t pos_t;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
public:
	my_vector(size_t sz = 0)
		: m_size(sz)
	{
		m_capacity = sz != 0 ? m_size * 2 : DEFAULT_BUFFER_SIZE;
		m_data = new value_type[m_capacity];
	}
	~my_vector()
	{
		delete [] m_data;
	}
public:
	bool	empty() const { return m_size == 0; }
	size_t	size() const { return m_size; }
	size_t	capacity() const { return m_capacity; }
	value_type operator[](pos_t pos) const { return m_data[pos]; }
public:
	value_type& operator[](pos_t pos) { return m_data[pos]; }
	void clear()
	{
		m_size = 0;
	}
	bool reserve(size_t sz)
	{
		size_t cp = capacity();
		if( sz <= cp ) return true;
		const size_t cp0 = cp;		//	以前のキャパシティ
		if( !cp ) cp = DEFAULT_BUFFER_SIZE;
		while( sz > cp ) cp += cp;
		pointer data = new value_type[m_capacity = cp];
		if( !data ) {
			throw std::bad_alloc();
			return false;
		}
		memmove((void*)data, (void*)m_data, size()*sizeof(value_type));
		delete [] m_data;
		m_data = data;
		return true;
	}
	void push_back(value_type ch)
	{
		size_t cp = capacity();
		if( cp == size() ) {
			reserve(cp*2);
		}
		m_data[m_size++] = ch;
	}
	void push_front(value_type ch)
	{
		size_t cp = capacity();
		if( cp == size() ) {		//	capacity は０ではないと仮定
			reserve(cp*2);
		}
		memmove((void*)(m_data+1), (void*)m_data, size()*sizeof(value_type));
		++m_size;
		m_data[0] = ch;
	}
	void insert(pos_t pos, value_type ch)
	{
		if( pos > size() ) return;
		size_t cp = capacity();
		if( cp == size() ) {		//	capacity は０ではないと仮定
			reserve(cp*2);
		}
		if( pos < size() )
			memmove((void*)(m_data+pos+1), (void*)(m_data+pos), (size()-pos)*sizeof(value_type));
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
			memmove((void*)(m_data), (void*)(m_data+1), (size()-1)*sizeof(value_type));
		--m_size;
	}
	void erase(pos_t pos)
	{
		if( pos >= size() ) return;
		if( pos < size() - 1 )
			memmove((void*)(m_data+pos), (void*)(m_data+pos+1), (size()-pos-1)*sizeof(value_type));
		--m_size;
	}
	
private:
	size_t		m_size;			//	テキストサイズ（文字数）
	size_t		m_capacity;		//	アロケート済みデータ領域サイズ（バイト数ではなく文字数）
	value_type*	m_data;
};
