#ifndef UCONTROL_H
#define UCONTROL_H

#include "UAEditor.h"
#include "UProcssr.h"
#include "UMemory.h"
#include <memory>
#include <QDebug>

template <class TNumber, class TEditor>
class TCtrl
{
public:
    TCtrl();

    enum CtrlState{
        cStart,
        cEditing,
        FunDone,
        cValDone,
        cExpDone,
        cOpChange,
        cError
    };

    CtrlState getState() const noexcept {return m_state;}
    void setState(CtrlState state);

    AEditor* getEditor() {return m_editor.get();}
    void setEditor(std::unique_ptr<AEditor>&& editor);

    void clearRightOperand();
    void reset();
    void setNumber(std::unique_ptr<TANumber>&& number);
    std::string genNumber() {return m_number->numberString();}
    std::string executeCommandEditor(AEditor::Command command);
    std::string executeOperation(typename TProc<TNumber>::Operation operation);
    std::string executeFunction(typename TProc<TNumber>::Function function);
    std::string calculate();
    std::string executeCommandMemory(typename TMemory<TNumber>::Command command, std::unique_ptr<TANumber>&& number, typename TMemory<TNumber>::State &state);

private:
    CtrlState m_state = CtrlState::cStart;
    std::unique_ptr<AEditor> m_editor;
    TProc<TNumber> m_proc {};
    TMemory<TNumber> m_memory {};
    std::unique_ptr<TANumber> m_number;
};

template<class TNumber, class TEditor>
inline TCtrl<TNumber, TEditor>::TCtrl()
{
    m_number = std::make_unique<TNumber>();
    m_editor = std::make_unique<TEditor>();
}

template<class TNumber, class TEditor>
inline void TCtrl<TNumber, TEditor>::setState(CtrlState state)
{
    m_state = state;
}

template<class TNumber, class TEditor>
inline void TCtrl<TNumber, TEditor>::setEditor(std::unique_ptr<AEditor> &&editor)
{
    m_editor = std::move(editor);
}

template<class TNumber, class TEditor>
inline void TCtrl<TNumber, TEditor>::clearRightOperand()
{
    m_proc.setRightOperand(std::make_unique<TNumber>());
}

template<class TNumber, class TEditor>
inline void TCtrl<TNumber, TEditor>::reset()
{
    m_proc.resetProc();
    m_state = cStart;
    m_number = std::make_unique<TNumber>();
    m_editor = std::make_unique<TEditor>();
}

template<class TNumber, class TEditor>
inline void TCtrl<TNumber, TEditor>::setNumber(std::unique_ptr<TANumber> &&number)
{
    m_number = std::move(number);
}

template<class TNumber, class TEditor>
inline std::string TCtrl<TNumber, TEditor>::executeCommandEditor(AEditor::Command command)
{
    std::string result = m_proc.getLeftOperand()->numberString();
    if (m_state == cStart || m_state == cEditing){
        result = m_editor->Edit(command);
    }
    else if (m_state == cOpChange || m_state == cExpDone){
        result = m_editor->Edit(AEditor::Command::cCE);
        result = m_editor->Edit(command);
        m_state = cEditing;
    }
    else if (m_state == cError){
        result = m_editor->Edit(AEditor::Command::cCE);
    }
    return result;
}

template<class TNumber, class TEditor>
inline std::string TCtrl<TNumber, TEditor>::executeOperation(typename TProc<TNumber>::Operation operation)
{
    std::string result = m_proc.getLeftOperand()->numberString();
    try{
        if (m_state == CtrlState::cStart){
            m_proc.setOperation(operation);
            m_proc.setLeftOperand(m_number);
            m_state = cOpChange;
            return m_proc.getLeftOperand()->numberString();
        }
        if (m_state == cEditing || m_state == FunDone){
            m_proc.setRightOperand(m_number);
            m_proc.doOperation();
            m_number = m_proc.getLeftOperand();
            result = m_number->numberString();
            m_editor->setNumber(result);
            m_state = cOpChange;
            m_proc.setOperation(operation);
            return result;
        }
        if (m_state == cOpChange){
            m_proc.setOperation(operation);
            return m_number->numberString();
        }
        if (m_state == cExpDone){
            m_proc.setOperation(operation);
            m_state = cOpChange;
            return m_number->numberString();
        }
    }
    catch(const std::exception& ex){
        m_state = cError;
        return std::string(ex.what());
    }
}

template<class TNumber, class TEditor>
inline std::string TCtrl<TNumber, TEditor>::executeFunction(typename TProc<TNumber>::Function function)
{
    std::string result = m_proc.getLeftOperand()->numberString();
    try{
        if (m_state == cStart){
            m_proc.setRightOperand(m_number);
            m_proc.doFunction(function);
            m_proc.setLeftOperand(m_proc.getRightOperand());
            result = m_proc.getRightOperand()->numberString();
            m_state = CtrlState::FunDone;
        }
        else{
            m_proc.setRightOperand(m_number);
            m_proc.doFunction(function);
            result = m_proc.getRightOperand()->numberString();
            m_state = CtrlState::FunDone;
        }
        return result;
    }
    catch(const std::exception& ex){
        m_state = cError;
        return std::string(ex.what());
    }
}

template<class TNumber, class TEditor>
inline std::string TCtrl<TNumber, TEditor>::calculate()
{
    std::string result = m_proc.getLeftOperand()->numberString();
    try{
        if (m_state == CtrlState::cExpDone){
            m_proc.doOperation();
            result = m_proc.getLeftOperand()->numberString();
        }
        else if (m_state == CtrlState::cEditing || m_state == CtrlState::FunDone || m_state == CtrlState::cOpChange){
            m_proc.setRightOperand(m_number);
            m_proc.doOperation();
            m_state = CtrlState::cExpDone;
            result = m_proc.getLeftOperand()->numberString();
        }
        else if (m_state == CtrlState::cStart){
            m_proc.setLeftOperand(m_number);
            result = m_proc.getLeftOperand()->numberString();
        }
        return result;
    }
    catch(const std::exception& ex){
        m_state = cError;
        return std::string(ex.what());
    }
}

template<class TNumber, class TEditor>
inline std::string TCtrl<TNumber, TEditor>::executeCommandMemory(typename TMemory<TNumber>::Command command, std::unique_ptr<TANumber>&& number, typename TMemory<TNumber>::State &state)
{
    if (m_state == cError) return number->numberString();
    try{
        if (command == TMemory<TNumber>::Command::Take) return m_memory.take()->numberString();
        std::unique_ptr<TANumber> num = std::move(number);
        m_memory.edit(command, num);
        state = m_memory.getState();
        return num->numberString();
    }
    catch(const std::exception& ex){
        return std::string(ex.what());
    }
}

#endif // UCONTROL_H
