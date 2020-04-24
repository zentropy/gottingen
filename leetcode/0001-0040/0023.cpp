/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <new>

template <class _T1, class _T2>
inline void construct_n(_T1 * p,const _T2 & v,size_t n) { for(_T1* end = p + n;p != end; new (p++) _T1(v)); }

template <class elem_t>
class scoped_array
{
#if 0
private:
	scoped_array(const scoped_array&);
	scoped_array& operator= (const scoped_array&);
#else
public:
	scoped_array(const scoped_array& rhs):_data(NULL),_size(0) { resize(rhs.size());memcpy(_data,rhs._data,sizeof(elem_t)*_size); }
	scoped_array& operator=(const scoped_array& rhs) { resize(rhs.size());memcpy(_data,rhs._data,sizeof(elem_t)*_size);return *this; }
#endif
private:
	elem_t* _data;
	size_t _size;
public:
	scoped_array():_data(NULL),_size(0) { ; }
	~scoped_array() { clear(); }
public:
	bool resize(size_t size) { if(0 == size) return false;clear();_data = new elem_t[size];if(NULL == _data) return false;_size = size;return true; }
	bool resize(size_t size,const elem_t& e) { if(resize(size)) { construct_n(_data,e,size);return true; };return false; }
	void clear() { delete[] _data;_data = NULL;_size = 0; }
public:
	elem_t& operator[](size_t index) { return _data[index]; }
	const elem_t& operator[](size_t index)const { return _data[index]; }
public:
	const elem_t* data()const { return _data; }
	elem_t* data() { return _data; }
public:
	size_t size() const { return _size;	}
};

template<typename T>
class CMinHeap
{
	CMinHeap(const CMinHeap&);
	CMinHeap& operator= (const CMinHeap&);
protected:
	size_t			_size;		// [1..._size]
	size_t			_cap;
	bool			_multi;
	scoped_array<T>	_data;		// [1...capacity]
public:
	CMinHeap():_size(0),_cap(0),_multi(false) { ; }
	~CMinHeap() {;}
public:
	bool init(size_t size,bool multi = false)
	{
		if(_cap != size) _data.resize(size+1);
		_size = 0;_cap = size;_multi = multi;
		return true;
	}
public:
	bool empty()const	{ return 0 == _size; }
	bool full()const	{ return _size == _cap; }
public:
	void clear()		{ _size = 0; }
	size_t size()const	{ return _size; }
	const T& top()const { return _data[1]; }
public:
	bool push(const T& elem)
	{
		if(full()) return false;
		_data[++_size] = elem;
		_heap_up();
		return true;
	};
public:
	bool pop()
	{
		if(empty()) return false;
		_data[1] = _data[_size--];
		_heap_down();
		return true;
	};
protected:
	void _heap_down()
	{
		size_t pre = 1;
		T tmp = _data[pre];
		for(size_t k = pre<<1;k <= _size;k <<=1)
		{
			if(k < _size && _data[k+1] < _data[k]) ++k;
			if(tmp <= _data[k]) break;
			_data[pre] = _data[k];
			pre = k;
		}
		_data[pre] = tmp;
	};
public:
	void _heap_up()
	{
		size_t pre = _size;
		T t = _data[pre];
		for(size_t cur = pre>>1;0 != cur && t < _data[cur];cur>>=1)
		{
			_data[pre] = _data[cur];
			pre = cur;
		}
		_data[pre] = t;
	}
};

struct value_t
{
    int value;
    ListNode* from;
 public:
    value_t():value(0),from(NULL) { ; }
public:
    bool operator<=(const value_t& rhs)const { return value <= rhs.value; }
    bool operator<(const value_t& rhs)const { return value < rhs.value; }
    bool operator==(const value_t& rhs)const { return value == rhs.value; }
    
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL,*curr = NULL;
        CMinHeap<value_t> heap;
        heap.init(lists.size(),false);
        for(size_t i = 0;i < lists.size();++i)
        {
            ListNode* p = lists[i];
            if(NULL == p) continue;                 // 测试用例中有null的情况
            value_t v;v.value = p->val;
            v.from = p;
            heap.push(v);
        }
        for(;!heap.empty();)
        {
            const value_t& u = heap.top();
            ListNode* p = u.from;
            if(NULL == head)
            {
                head = p;
                curr = p;
            }
            else
            {
                curr->next = p;
                curr = p;
            }
            heap.pop();
            p = p->next;
            if(NULL != p)
            {
                value_t v;v.value = p->val;
                v.from = p;
                heap.push(v);
            }
        }
        return head;
    }
};