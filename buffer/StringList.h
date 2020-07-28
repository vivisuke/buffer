#pragma once

#include <list>
#include <string>

class StringList : public std::list<std::string>
{
public:
	StringList()
		: m_cachedLine(-1)
	{
		m_cachedItr = end();
	}
public:
	StringList::iterator findIterator(int line)
	{
		if( line < 0 || line >= size() ) return end();
		auto itr = begin();
		while( line > 0 ) {
			++itr;
			--line;
		}
		return itr;
	}
	StringList::iterator findIteratorCached(int line)
	{
		if( line < 0 || line >= size() ) return end();
		if( m_cachedLine < 0 ) {	//	キャッシュが無い場合
			return m_cachedItr = findIterator(m_cachedLine = line);
		}
		if( line == m_cachedLine )		//	キャッシュ行番号と同じ場合
			return m_cachedItr;
		if( line < m_cachedLine ) {		//	キャッシュ行番号より前の場合
			if( line >= m_cachedLine / 2 ) {		//	キャッシュ行の半分より後ろにある場合
				while( line < m_cachedLine ) {		//	キャッシュ行から前に検索
					--m_cachedItr;
					--m_cachedLine;
				}
			} else {		//	キャッシュ行の半分より前にある場合
				m_cachedItr = begin();
				m_cachedLine = 0;
				while( line < m_cachedLine ) {		//	キャッシュ行から後ろ検索
					++m_cachedItr;
					++m_cachedLine;
				}
			}
		} else {		//	キャッシュ行番号より後ろの場合
			if( line <= line + (size() - m_cachedLine) / 2 ) {
				while( line > m_cachedLine ) {
					++m_cachedItr;
					++m_cachedLine;
				}
			} else {
				m_cachedItr = end();
				--m_cachedItr;
				m_cachedLine = size() - 1;
				while( line < m_cachedLine ) {
					--m_cachedItr;
					--m_cachedLine;
				}
			}
		}
		return m_cachedItr;
	}
	char& charAt(int line, int offset)
	{
		auto itr = findIterator(line);
		return (*itr)[offset];
	}
#if	0
	char charAt(int line, int offset) const
	{
		auto itr = findIterator(line);
		return (*itr)[offset];
	}
#endif
private:
	int		m_cachedLine;
	StringList::iterator	m_cachedItr;
};
