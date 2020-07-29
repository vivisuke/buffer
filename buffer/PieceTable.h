#pragma once

#include <vector>
#include <string>
#include "gap_buffer.h"

/*

            ┌──────────────┐
            │PieceTable<Type>            │
            ├──────────────┤
            │m_size : size_t             │    //  バッファサイズ
            │m_buffer : vector<Type>     │    //  テキストデータ領域
    ┌──◆│m_table : gap_buffer<Piece> │    //  ピーステーブル
    │      ├──────────────┤
    │      │size() : size_t             │
    │      │operator[](pos_t)           │
    │      │clear()                     │
    │      │push_back(Type)             │
    │      │pop_back()                  │
    │      │insert(pos_t, Type)         │
    │      │erase(pos_t)                │
    │      │             ：             │
    │      │             ：             │
    │      └──────────────┘
    │  0..*┌──────────────┐
    └──→│           Piece            │	//	ピース構造体
            ├──────────────┤
            │m_start : pos_t             │	//	ピース先頭文字の m_buffer 内位置（0..*）
            │m_length : size_t           │	//	ピースに含まれる文字数
            └──────────────┘


*/

template<typename Type>
class PieceTable
{
public:
	typedef uint16_t pos_t;
	//
	struct Piece {
public:
		Piece(pos_t start = 0, size_t length = 0)
			: m_start(start)
			, m_length(length)
		{
		}
public:
		pos_t nextPos const { return m_start + m_length; }
public:
		pos_t	m_start;		//	ピース先頭文字の m_buffer 内位置
		size_t	m_length;		//	ピース内文字数
	};
public:
	PieceTable()
		: m_size(0)
	{
	}
public:
	size_t	size() const { return m_size; }
	bool	empty() const { return m_size == 0; }
	bool	isEmpty() const { return m_size == 0; }
	void	posToTable(pos_t pos, int& tix, int& offset) const {
		//	暫定実装
		tix = 0;
		while( pos >= m_table[tix].m_length ) {
			pos -= m_table[tix].m_length;
			if( ++tix == m_table.size() ) break;
		}
		offset = pos;
	}
	Type	operator[](pos_t pos) const {
		int tix, offset;
		posToTable(pos, tix, offset);
		return m_buffer[m_table[tix].m_start + offset];
	}
	std::string dump() const {
		string txt;
		txt += "m_size = " + to_string(m_size) + "\n";
		txt += "m_buffer.size() = " + to_string(m_buffer.size()) + "\n";
		txt += "m_buffer = '";
		for(auto ch: m_buffer) { txt += (char)ch; } txt += "'\n";
		txt += "m_table.size() = " + to_string(m_table.size()) + "\n";
		for (int i = 0; i != m_table.size(); ++i) {
			const auto& p = m_table[i];
			txt += "start = " + to_string(p.m_start) + ", length = " + to_string(p.m_length) + "\n";
		}
		txt += "text = '";
		for (int i = 0; i != m_table.size(); ++i) {
			const auto& p = m_table[i];
			for(int k = 0; k != p.m_length; ++k) {
				txt += m_buffer[p.m_start + k];
			}
		}
		txt += "'\n";
		return txt;
	}
public:
	void	clear() {
		m_size = 0;
		m_buffer.clear();
		m_table.clear();
	}
	void	push_back(Type ch) {
		auto start = m_buffer.size();		//	追加文字のバッファ内位置
		if( empty() ) {
			m_table.push_back(Piece(start, 1));
		} else {
			Piece& bk = m_table.back();		//	最後のピース
			if( bk.nextPos() == start ) {	//	最後のピースの最後の文字が m_buffer 最後の場合
				bk.m_length += 1;
			} else {
				m_table.push_back(Piece(start, 1));
			}
		}
		m_buffer.push_back(ch);
		++m_size;
	}
	void pop_back() {
		if( empty() ) {
		} else {
			Piece& bk = m_table.back();		//	最後のピース
			if( bk.m_length > 1 ) {
				bk.m_length -= 1;
			} else {
				m_table.pop_back();
			}
			--m_size;
		}
	}
	void push_front(Type ch) {
		m_table.push_front(Piece(m_buffer.size(), 1));
		m_buffer.push_back(ch);
		++m_size;
	}
	void pop_front() {
		if( empty() ) {
		} else {
			if( m_table[0].m_length == 1 )
				m_table.pop_front();
			else {
				m_table[0].m_start += 1;
				m_table[0].m_length -= 1;
			}
			--m_size;
		}
	}
	void insert(pos_t pos, Type ch) {
		if( pos > size() ) return;
		if( pos == size() ) {
			push_back(ch);
		} else if( pos == 0 ) {
			push_front(ch);
		} else {
			auto start = m_buffer.size();		//	追加文字のバッファ内位置
			int tix, offset;
			posToTable(pos, tix, offset);
			if( offset == 0 ) {		//	ピース先頭位置での挿入
				if( m_table[tix-1].nextPos() == start ) {	 //	最後のピースの最後の文字が m_buffer 最後の場合
					m_table[tix-1].m_length += 1;
				}
			} else {
			}
			m_buffer.push_back(ch);
			++m_size;
		}
	}
private:
	size_t		m_size;
	std::vector<Type>	m_buffer;
	gap_buffer<Piece>	m_table;
};
