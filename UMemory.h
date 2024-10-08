#pragma once
#include "UANumber.h"
#include "Exceptions.h"

template <class T>
class TMemory
{
public:
	enum State {
		On,
		Off
	};

    enum Command{
        Store,
        Add,
        Clear,
        Take
    };

	TMemory();
	TMemory(T number);
	TMemory(const std::unique_ptr<TANumber>& number);

	State getState() { return m_state; };

	void write(T number);
	void write(const std::unique_ptr<TANumber>& number);
	std::unique_ptr<TANumber> take();
	void operator += (const TANumber& B);
	void clear();
    void edit(Command command, const std::unique_ptr<TANumber>& number);

private:
	State m_state;
	std::unique_ptr<TANumber> m_number;
};

template<class T>
inline TMemory<T>::TMemory()
{
	static_assert(std::is_base_of<TANumber, T>::value, "T must inherit from TANumber");

	m_number = std::make_unique<T>();
	m_state = Off;
}

template<class T>
inline TMemory<T>::TMemory(T number)
{
	static_assert(std::is_base_of<TANumber, T>::value, "T must inherit from TANumber");

	m_number = std::make_unique<T>(number);
	m_state = Off;
}

template<class T>
inline TMemory<T>::TMemory(const std::unique_ptr<TANumber>& number)
{
	const T* pB = dynamic_cast<const T*>(number.get());
	if (!pB)
	{
		throw TypeMismatchException();
	}
	m_number = number->Clone();
	m_state = Off;
}

template<class T>
inline void TMemory<T>::write(T number)
{
	static_assert(std::is_base_of<TANumber, T>::value, "T must inherit from TANumber");

	m_number = std::make_unique<T>(number);
	m_state = On;
}

template<class T>
inline void TMemory<T>::write(const std::unique_ptr<TANumber>& number)
{
	const T* pB = dynamic_cast<const T*>(number.get());
	if (!pB)
	{
		throw TypeMismatchException();
	}
	m_number = number->Clone();
	m_state = On;
}

template<class T>
inline std::unique_ptr<TANumber> TMemory<T>::take()
{
	m_state = Off;
	return m_number->Clone();
}

template<class T>
inline void TMemory<T>::operator+=(const TANumber& B)
{
	m_number = *m_number + B;
}

template<class T>
inline void TMemory<T>::clear()
{
	m_number = std::make_unique<T>();
	m_state = Off;
}

template<class T>
inline void TMemory<T>::edit(Command command, const std::unique_ptr<TANumber>& number)
{
    switch (command) {
    case Store:
        write(number);
        break;
    case Add:
        operator+=(*number);
        break;
    case Clear:
        clear();
        break;
    default:
        break;
    }
}
