#include "UAEditor.h"

AEditor::~AEditor() = default;

CEditor::CEditor()
{
	m_number = TComplex().numberString();
	m_separator = " + i * ";
	editMode = EditMode::Actual;
}

CEditor::CEditor(double actual, double imaginary)
{
	m_number = TComplex(actual, imaginary).numberString();
	m_separator = imaginary >= 0 ? " + i * " : " - i * ";
	editMode = EditMode::Actual;
}

CEditor::CEditor(const std::string& number)
{
	TComplex num(number);
	m_number = num.numberString();
	m_separator = num.getImaginary() >= 0 ? " + i * " : " - i * ";
	editMode = EditMode::Actual;
}

void CEditor::setNumber(const std::string& number)
{
	m_number = TComplex(number).numberString();
}

bool CEditor::isNull() const noexcept
{
	return TComplex(m_number).isNull();
}

std::string CEditor::toggleMinus() noexcept
{
	size_t position = m_number.find(m_separator);
	if (editMode == EditMode::Actual) 
	{
		if (m_number[0] == '-') 
		{
			m_number = m_number.substr(1);
		}
		else
		{
			if (m_number.substr(0, position) == "0") return m_number;
			m_number = "-" + m_number;
		}
	}
	else
	{
		if (m_number.substr(position + m_separator.length()) == "0") return m_number;
		if (m_separator[1] == '+') m_separator[1] = '-';
		else m_separator[1] = '+';
		m_number = m_number.substr(0, position) + m_separator + m_number.substr(position + m_separator.length());
	}
	return m_number;
}

std::string CEditor::addNumber(int number)
{
	size_t position = m_number.find(m_separator);
	std::string left = m_number.substr(0, position);
	std::string right = m_number.substr(position + m_separator.length());
	if (editMode == EditMode::Actual) 
	{
		if (left == "0")
			m_number = std::to_string(number) + m_separator + right;
		else 
			m_number = left + std::to_string(number) + m_separator + right;
	}
	else
	{
		if (right == "0")
			m_number.pop_back();
		m_number += std::to_string(number);
	}
	return m_number;
}

std::string CEditor::addSeparator()
{
	size_t position = m_number.find(m_separator);
	if (position == std::string::npos) {
		m_number += m_separator + "0";
	}
	return m_number;
}

std::string CEditor::addNumberSeparator()
{
	size_t position = m_number.find(m_separator);
	std::string left = m_number.substr(0, position);
	std::string right = m_number.substr(position + m_separator.length());
	if (editMode == EditMode::Actual)
	{
		if (left.find(".") == std::string::npos)
			m_number = left + "." + m_separator + right;
	}
	else
	{
		if (right.find(".") == std::string::npos)
			m_number += ".";
	}
	return m_number;
}

CEditor::EditMode CEditor::changeEditMode()
{
	if (editMode == EditMode::Actual)
		editMode = EditMode::Imaginary;
	else
		editMode = EditMode::Actual;
	return editMode;
}

std::string CEditor::addZero()
{
	size_t position = m_number.find(m_separator);
	std::string left = m_number.substr(0, position);
	std::string right = m_number.substr(position + m_separator.length());
	if (editMode == EditMode::Actual)
	{
        if (left != "0")
			m_number = left + "0" + m_separator + right;
	}
	else
	{
        if (right != "0")
			m_number += "0";
	}
	return m_number;
}

std::string CEditor::BackSpace()
{
	size_t position = m_number.find(m_separator);
	std::string left = m_number.substr(0, position);
	std::string right = m_number.substr(position + m_separator.length());
	if (editMode == EditMode::Actual)
	{
		if (left != "0") 
		{
			left.pop_back();
			if (left.length() == 0 || left == "-")
				left = "0";
		}
	}
	else
	{
		if (right != "0")
		{
			right.pop_back();
			if (right.length() == 0 || right == "-")
				right = "0";
		}
	}
	m_number = left + m_separator + right;
	return m_number;
}

std::string CEditor::CE()
{
	*this = CEditor();
	return m_number;
}

std::string CEditor::Edit(Command command)
{
	switch (command)
	{
	case AEditor::cZero:
		addZero();
		break;
	case AEditor::cOne:
		addNumber(1);
		break;
	case AEditor::cTwo:
		addNumber(2);
		break;
	case AEditor::cThree:
		addNumber(3);
		break;
	case AEditor::cFour:
		addNumber(4);
		break;
	case AEditor::cFive:
		addNumber(5);
		break;
    case AEditor::cSix:
		addNumber(6);
		break;
	case AEditor::cSeven:
		addNumber(7);
		break;
	case AEditor::cEight:
		addNumber(8);
		break;
	case AEditor::cNine:
		addNumber(9);
		break;
	case AEditor::cSign:
		toggleMinus();
		break;
	case AEditor::cSeparatorFR:
		addNumberSeparator();
		break;
	case AEditor::cSeparatorC:
		addSeparator();
		break;
	case AEditor::cBS:
		BackSpace();
		break;
	case AEditor::cCE:
		CE();
		break;
	default:
		break;
	}
	return m_number;
}

FEditor::FEditor()
{
    m_number = "0";
    m_separator = "/";
}

FEditor::FEditor(double numerator, double denominator)
{
	m_number = TFrac(numerator, denominator).numberString();
	m_separator = "/";
}

FEditor::FEditor(const std::string& number)
{
	m_number = TFrac(number).numberString();
	m_separator = "/";
}

void FEditor::setNumber(const std::string& number)
{
	m_number = TFrac(number).numberString();
}

bool FEditor::isNull() const noexcept
{
	return TFrac(m_number).isNull();
}

std::string FEditor::toggleMinus() noexcept
{
	if (isNull()) return m_number;
	if (m_number[0] == '-') 
	{
		m_number = m_number.substr(1);
	}
	else
	{
		m_number = "-" + m_number;
	}
	return m_number;
}

std::string FEditor::addNumber(int number)
{
    std::string num;
    size_t position = m_number.find(m_separator);
    if (position != std::string::npos){
        num = m_number.substr(position+1);
    }
    else{
        num = m_number;
    }
    if (num == "0") m_number.pop_back();
    m_number += std::to_string(number);
	return m_number;
}

std::string FEditor::addSeparator()
{
	size_t position = m_number.find(m_separator);
	if (position == std::string::npos) {
		m_number += m_separator;
	}
	return m_number;
}

std::string FEditor::addZero()
{
    std::string number;
    size_t position = m_number.find(m_separator);
    if (position != std::string::npos){
        number = m_number.substr(position+1);
    }
    else{
        number = m_number;
    }
    if (number != "0") m_number += "0";
	return m_number;
}

std::string FEditor::BackSpace()
{
	if (m_number != "0")
	{
		m_number.pop_back();
		if (m_number.length() == 0 || m_number == "-")
			m_number = "0";
	}
	return m_number;
}

std::string FEditor::CE()
{
    m_number = "0";
	return m_number;
}

std::string FEditor::Edit(Command command)
{
	switch (command)
	{
	case AEditor::cZero:
		addZero();
		break;
	case AEditor::cOne:
		addNumber(1);
		break;
	case AEditor::cTwo:
		addNumber(2);
		break;
	case AEditor::cThree:
		addNumber(3);
		break;
	case AEditor::cFour:
		addNumber(4);
		break;
	case AEditor::cFive:
		addNumber(5);
		break;
    case AEditor::cSix:
		addNumber(6);
		break;
	case AEditor::cSeven:
		addNumber(7);
		break;
	case AEditor::cEight:
		addNumber(8);
		break;
	case AEditor::cNine:
		addNumber(9);
		break;
	case AEditor::cSign:
		toggleMinus();
		break;
	case AEditor::cSeparatorC:
		addSeparator();
		break;
	case AEditor::cBS:
		BackSpace();
		break;
	case AEditor::cCE:
		CE();
		break;
	default:
		break;
	}
	return m_number;
}

PEditor::PEditor() : PEditor(0, 10, 2) {}

PEditor::PEditor(double value, int base, int precision) : m_base(base), m_precision(precision)
{
	m_number = TPNumber(value, base, precision).numberString();
    m_separator = ".";
}

PEditor::PEditor(const std::string& value, const std::string& base, const std::string& precision)
{
	TPNumber p(value, base, precision);
	m_base = p.base();
	m_precision = p.precision();
	m_number = p.numberString();
    m_separator = ".";
}

void PEditor::setNumber(const std::string& number)
{
    TPNumber p;
	p.setPrecision(m_precision);
	p.setBase(m_base);
	p.setNumber(m_number);
    m_number = p.numberString();
}

bool PEditor::isNull() const noexcept
{
	return TPNumber(m_number, std::to_string(m_base), std::to_string(m_precision)).isNull();
}

std::string PEditor::toggleMinus() noexcept
{
	if (isNull()) return m_number;
	if (m_number[0] == '-') m_number = m_number.substr(1);
	else m_number = "-" + m_number;
	return m_number;
}

std::string PEditor::addNumber(int number)
{
    std::string strNumber = std::to_string(number);
    if (number == 10) strNumber = "A";
    if (number == 11) strNumber = "B";
    if (number == 12) strNumber = "C";
    if (number == 13) strNumber = "D";
    if (number == 14) strNumber = "E";
    if (number == 15) strNumber = "F";
    if (m_number == "0") m_number = strNumber;
	else {
		size_t position = m_number.find(m_separator);
		if (position == std::string::npos) {
            m_number += strNumber;
		}
		else {
			int currentCount = m_number.substr(position + 1).length();
            if (currentCount < m_precision) m_number += strNumber;
		}
	}
	return m_number;
}

std::string PEditor::addSeparator()
{
	if (m_precision == 0) return m_number;

	size_t position = m_number.find(m_separator);
	if (position == std::string::npos) {
		m_number += m_separator;
	}
	return m_number;
}

std::string PEditor::addZero()
{
	size_t position = m_number.find(m_separator);
	if (position == std::string::npos) {
		if (m_number[0] != '0') m_number += "0";
	}
	else {
		m_number += "0";
	}
	return m_number;
}

std::string PEditor::BackSpace()
{
	if (m_number != "0")
	{
		m_number.pop_back();
		if (m_number.length() == 0 || m_number == "-")
			m_number = "0";
	}
	return m_number;
}

std::string PEditor::CE()
{
	m_number = TPNumber(0, m_base, m_precision).numberString();
	return m_number;
}

std::string PEditor::Edit(Command command)
{
	switch (command)
	{
	case AEditor::cZero:
		addZero();
		break;
	case AEditor::cOne:
		addNumber(1);
		break;
	case AEditor::cTwo:
		addNumber(2);
		break;
	case AEditor::cThree:
		addNumber(3);
		break;
	case AEditor::cFour:
		addNumber(4);
		break;
	case AEditor::cFive:
		addNumber(5);
		break;
    case AEditor::cSix:
		addNumber(6);
		break;
	case AEditor::cSeven:
		addNumber(7);
		break;
	case AEditor::cEight:
		addNumber(8);
		break;
	case AEditor::cNine:
		addNumber(9);
		break;
    case AEditor::cA:
        addNumber(10);
        break;
    case AEditor::cB:
        addNumber(11);
        break;
    case AEditor::cC:
        addNumber(12);
        break;
    case AEditor::cD:
        addNumber(13);
        break;
    case AEditor::cE:
        addNumber(14);
        break;
    case AEditor::cF:
        addNumber(15);
        break;
	case AEditor::cSign:
		toggleMinus();
		break;
	case AEditor::cSeparatorC:
		addSeparator();
		break;
	case AEditor::cBS:
		BackSpace();
		break;
	case AEditor::cCE:
		CE();
		break;
	default:
		break;
	}
	return m_number;
}
