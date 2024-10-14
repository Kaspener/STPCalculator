#pragma once
#include <string>
#include "UANumber.h"

class AEditor
{
public:
	enum Command {
		cZero,
		cOne,
		cTwo,
		cThree,
		cFour,
		cFive,
        cSix,
		cSeven,
		cEight,
		cNine,
		cA,
		cB,
		cC,
		cD,
		cE,
		cF,
		cSign,
		cSeparatorFR,
		cSeparatorC,
		cBS,
        cCE,
        cPast
	};

	virtual ~AEditor() = 0;

	std::string number() const noexcept { return m_number; }
	virtual void setNumber(const std::string& number) = 0;

	virtual bool isNull() const noexcept = 0;
	virtual std::string toggleMinus() noexcept = 0;
	virtual std::string addNumber(int number) = 0;
	virtual std::string addSeparator() = 0;
	virtual std::string addZero() = 0;
	virtual std::string BackSpace() = 0;
	virtual std::string CE() = 0;
	virtual std::string Edit(Command command) = 0;

protected:
	std::string m_number;
	std::string m_separator;
};

class CEditor : public AEditor {
public:
	enum EditMode
	{
		Actual, 
		Imaginary
	};

	CEditor();
	CEditor(double actual, double imaginary);
	CEditor(const std::string& number);
	virtual ~CEditor() = default;

	void setNumber(const std::string& number) override;
	bool isNull() const noexcept override;
	std::string toggleMinus() noexcept override;
	std::string addNumber(int number) override;
	std::string addSeparator() override;
	std::string addZero() override;
	std::string BackSpace() override;
	std::string CE() override;
	std::string Edit(Command command) override;

	std::string addNumberSeparator();
	EditMode changeEditMode();

private:
	EditMode editMode;
};

class FEditor : public AEditor {
public:
	FEditor();
	FEditor(double numerator, double denominator);
	FEditor(const std::string& number);
	virtual ~FEditor() = default;

	void setNumber(const std::string& number) override;
	bool isNull() const noexcept override;
	std::string toggleMinus() noexcept override;
	std::string addNumber(int number) override;
	std::string addSeparator() override;
	std::string addZero() override;
	std::string BackSpace() override;
	std::string CE() override;
	std::string Edit(Command command) override;
};

class PEditor : public AEditor {
public:
	PEditor();
	PEditor(double value, int base, int precision);
	PEditor(const std::string& value, const std::string& base, const std::string& precision);
	virtual ~PEditor() = default;

	void setNumber(const std::string& number) override;
	bool isNull() const noexcept override;
	std::string toggleMinus() noexcept override;
	std::string addNumber(int number) override;
	std::string addSeparator() override;
	std::string addZero() override;
	std::string BackSpace() override;
	std::string CE() override;
	std::string Edit(Command command) override;

private:
	int m_base;
	int m_precision;
};

