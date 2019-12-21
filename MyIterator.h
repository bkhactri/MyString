#define _CRT_SECURE_NO_WARNINGS
#pragma once
template<typename TypeOfData>
class MyIterator
{
protected:
	TypeOfData* m_ptr;
public:

	using MyIterator_category = std::random_access_iterator_tag;
	using value_type = TypeOfData;
	using difference_type = std::ptrdiff_t;
	using pointer = TypeOfData*;
	using reference = TypeOfData&;

public:

	MyIterator(TypeOfData* ptr = nullptr) { m_ptr = ptr; }
	MyIterator(const MyIterator<TypeOfData>& rawMyIterator) = default;
	~MyIterator() {}

	MyIterator<TypeOfData>& operator=(const MyIterator<TypeOfData>& rawMyIterator) = default;
	MyIterator<TypeOfData>& operator=(TypeOfData* ptr) { m_ptr = ptr; return (*this); }

	bool operator==(const MyIterator<TypeOfData>& rawMyIterator)const { return (m_ptr == rawMyIterator.getConstm_Ptr()); }
	bool operator!=(const MyIterator<TypeOfData>& rawMyIterator)const { return (m_ptr != rawMyIterator.getConstm_Ptr()); }

	MyIterator<TypeOfData>& operator+=(const difference_type& movement) { m_ptr += movement; return (*this); }
	MyIterator<TypeOfData>& operator-=(const difference_type& movement) { m_ptr -= movement; return (*this); }
	MyIterator<TypeOfData>& operator++() { ++m_ptr; return (*this); }
	
	MyIterator<TypeOfData> operator++(int) { auto temp(*this); ++m_ptr; return temp; }
	

	MyIterator<TypeOfData> operator+(const difference_type& movement) { auto oldPtr = m_ptr; m_ptr += movement; auto temp(*this); m_ptr = oldPtr; return temp; }
	MyIterator<TypeOfData> operator-(const difference_type& movement) { auto oldPtr = m_ptr; m_ptr -= movement; auto temp(*this); m_ptr = oldPtr; return temp; }

	TypeOfData* getm_Ptr()const { return m_ptr; }
	const TypeOfData* getConstm_Ptr()const { return m_ptr; }
};

template<typename TypeOfData>
class reverse_MyIterator : public MyIterator<TypeOfData>
{
public:

	reverse_MyIterator(TypeOfData* ptr = nullptr) :MyIterator<TypeOfData>(ptr) {}
	reverse_MyIterator(const MyIterator<TypeOfData>& rawMyIterator) { this->m_ptr = rawMyIterator.getPtr(); }
	reverse_MyIterator(const reverse_MyIterator<TypeOfData>& rawReverseMyIterator) = default;
	~reverse_MyIterator() {}

	reverse_MyIterator<TypeOfData>& operator=(const reverse_MyIterator<TypeOfData>& rawReverseMyIterator) = default;
	reverse_MyIterator<TypeOfData>& operator=(const MyIterator<TypeOfData>& rawMyIterator) { this->m_ptr = rawMyIterator.getm_Ptr(); return (*this); }
	reverse_MyIterator<TypeOfData>& operator=(TypeOfData* ptr) { this->setPtr(ptr); return (*this); }

	reverse_MyIterator<TypeOfData>& operator++() { --this->m_ptr; return (*this); }
	reverse_MyIterator<TypeOfData>  operator++(int) { auto temp(*this); --this->m_ptr; return temp; }
	reverse_MyIterator<TypeOfData>  operator+(const int& movement) { auto oldPtr = this->m_ptr; this->m_ptr -= movement; auto temp(*this); this->m_ptr = oldPtr; return temp; }
	reverse_MyIterator<TypeOfData>  operator-(const int& movement) { auto oldPtr = this->m_ptr; this->m_ptr += movement; auto temp(*this); this->m_ptr = oldPtr; return temp; };

};
