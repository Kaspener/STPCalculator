#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QDialog>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clipboard = QApplication::clipboard();
    QShortcut *shortcutBS = new QShortcut(QKeySequence("Backspace"), ui->tabWidget);
    QShortcut *shortcut0 = new QShortcut(QKeySequence("0"), ui->tabWidget);
    QShortcut *shortcut1 = new QShortcut(QKeySequence("1"), ui->tabWidget);
    QShortcut *shortcut2 = new QShortcut(QKeySequence("2"), ui->tabWidget);
    QShortcut *shortcut3 = new QShortcut(QKeySequence("3"), ui->tabWidget);
    QShortcut *shortcut4 = new QShortcut(QKeySequence("4"), ui->tabWidget);
    QShortcut *shortcut5 = new QShortcut(QKeySequence("5"), ui->tabWidget);
    QShortcut *shortcut6 = new QShortcut(QKeySequence("6"), ui->tabWidget);
    QShortcut *shortcut7 = new QShortcut(QKeySequence("7"), ui->tabWidget);
    QShortcut *shortcut8 = new QShortcut(QKeySequence("8"), ui->tabWidget);
    QShortcut *shortcut9 = new QShortcut(QKeySequence("9"), ui->tabWidget);
    QShortcut *shortcutA = new QShortcut(QKeySequence("A"), ui->tabWidget);
    QShortcut *shortcutB = new QShortcut(QKeySequence("B"), ui->tabWidget);
    QShortcut *shortcutC = new QShortcut(QKeySequence("C"), ui->tabWidget);
    QShortcut *shortcutD = new QShortcut(QKeySequence("D"), ui->tabWidget);
    QShortcut *shortcutE = new QShortcut(QKeySequence("E"), ui->tabWidget);
    QShortcut *shortcutF = new QShortcut(QKeySequence("F"), ui->tabWidget);
    QShortcut *shortcutDot = new QShortcut(QKeySequence("."), ui->tabWidget);
    QShortcut *shortcutRaz = new QShortcut(QKeySequence("\\"), ui->tabWidget);
    QShortcut *shortcutAdd = new QShortcut(QKeySequence("+"), ui->tabWidget);
    QShortcut *shortcutSub = new QShortcut(QKeySequence("-"), ui->tabWidget);
    QShortcut *shortcutMul = new QShortcut(QKeySequence("*"), ui->tabWidget);
    QShortcut *shortcutDiv = new QShortcut(QKeySequence("/"), ui->tabWidget);
    QShortcut *shortcutResult = new QShortcut(QKeySequence("Enter"), ui->tabWidget);
    QShortcut *shortcutResult2 = new QShortcut(QKeySequence("="), ui->tabWidget);
    QShortcut *shortcutCopy = new QShortcut(QKeySequence("Ctrl+C"), ui->tabWidget);
    QShortcut *shortcutPast = new QShortcut(QKeySequence("Ctrl+V"), ui->tabWidget);
    connect(shortcutBS, &QShortcut::activated, this, &MainWindow::onShortcutBS);
    connect(shortcut0, &QShortcut::activated, this, &MainWindow::onShortcut0);
    connect(shortcut1, &QShortcut::activated, this, &MainWindow::onShortcut1);
    connect(shortcut2, &QShortcut::activated, this, &MainWindow::onShortcut2);
    connect(shortcut3, &QShortcut::activated, this, &MainWindow::onShortcut3);
    connect(shortcut4, &QShortcut::activated, this, &MainWindow::onShortcut4);
    connect(shortcut5, &QShortcut::activated, this, &MainWindow::onShortcut5);
    connect(shortcut6, &QShortcut::activated, this, &MainWindow::onShortcut6);
    connect(shortcut7, &QShortcut::activated, this, &MainWindow::onShortcut7);
    connect(shortcut8, &QShortcut::activated, this, &MainWindow::onShortcut8);
    connect(shortcut9, &QShortcut::activated, this, &MainWindow::onShortcut9);
    connect(shortcutA, &QShortcut::activated, this, &MainWindow::onShortcutA);
    connect(shortcutB, &QShortcut::activated, this, &MainWindow::onShortcutB);
    connect(shortcutC, &QShortcut::activated, this, &MainWindow::onShortcutC);
    connect(shortcutD, &QShortcut::activated, this, &MainWindow::onShortcutD);
    connect(shortcutE, &QShortcut::activated, this, &MainWindow::onShortcutE);
    connect(shortcutF, &QShortcut::activated, this, &MainWindow::onShortcutF);
    connect(shortcutDot, &QShortcut::activated, this, &MainWindow::onShortcutDot);
    connect(shortcutRaz, &QShortcut::activated, this, &MainWindow::onShortcutRaz);
    connect(shortcutAdd, &QShortcut::activated, this, &MainWindow::onShortcutAdd);
    connect(shortcutSub, &QShortcut::activated, this, &MainWindow::onShortcutSub);
    connect(shortcutMul, &QShortcut::activated, this, &MainWindow::onShortcutMul);
    connect(shortcutDiv, &QShortcut::activated, this, &MainWindow::onShortcutDiv);
    connect(shortcutCopy, &QShortcut::activated, this, &MainWindow::onShortcutCopy);
    connect(shortcutPast, &QShortcut::activated, this, &MainWindow::onShortcutPast);
    connect(shortcutResult, &QShortcut::activated, this, &MainWindow::onShortcutResult);
    connect(shortcutResult2, &QShortcut::activated, this, &MainWindow::onShortcutResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button0_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cZero)));
}


void MainWindow::on_button1_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cOne)));
}


void MainWindow::on_button2_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cTwo)));
}


void MainWindow::on_button3_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cThree)));
}


void MainWindow::on_button4_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cFour)));
}


void MainWindow::on_button5_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cFive)));
}


void MainWindow::on_button6_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cSix)));
}


void MainWindow::on_button7_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cSeven)));
}


void MainWindow::on_button8_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cEight)));
}


void MainWindow::on_button9_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cNine)));
}


void MainWindow::on_separator_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cSeparatorC)));
}


void MainWindow::on_backSpace_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cBS)));
}


void MainWindow::on_clear_clicked()
{
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cCE)));
    fracController.reset();
    ui->currentOperation->setText("None");
}

void MainWindow::on_buttonMinus_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    fracController.setNumber(std::make_unique<TFrac>(ui->numberEdit->text().toStdString()));
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cSign)));
}

void MainWindow::on_clearElement_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cCE)));
    fracController.clearRightOperand();
}


void MainWindow::on_add_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    try{
        fracController.setNumber(std::make_unique<TFrac>(ui->numberEdit->text().toStdString()));
        ui->numberEdit->setText(QString::fromStdString(fracController.executeOperation(TProc<TFrac>::Add)));
        ui->currentOperation->setText("+");
    }
    catch(const std::exception& ex){
        ui->numberEdit->setText(QString::fromStdString(std::string(ex.what())));
        fracController.setState(TCtrl<TFrac, FEditor>::CtrlState::cError);
    }
}


void MainWindow::on_sub_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    try{
        fracController.setNumber(std::make_unique<TFrac>(ui->numberEdit->text().toStdString()));
        ui->numberEdit->setText(QString::fromStdString(fracController.executeOperation(TProc<TFrac>::Sub)));
        ui->currentOperation->setText("-");
    }
    catch(const std::exception& ex){
        ui->numberEdit->setText(QString::fromStdString(std::string(ex.what())));
        fracController.setState(TCtrl<TFrac, FEditor>::CtrlState::cError);
    }
}


void MainWindow::on_mul_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    try{
        fracController.setNumber(std::make_unique<TFrac>(ui->numberEdit->text().toStdString()));
        ui->numberEdit->setText(QString::fromStdString(fracController.executeOperation(TProc<TFrac>::Mul)));
        ui->currentOperation->setText("*");
    }
    catch(const std::exception& ex){
        ui->numberEdit->setText(QString::fromStdString(std::string(ex.what())));
        fracController.setState(TCtrl<TFrac, FEditor>::CtrlState::cError);
    }
}


void MainWindow::on_div_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    try{
        fracController.setNumber(std::make_unique<TFrac>(ui->numberEdit->text().toStdString()));
        ui->numberEdit->setText(QString::fromStdString(fracController.executeOperation(TProc<TFrac>::Div)));
        ui->currentOperation->setText("/");
    }
    catch(const std::exception& ex){
        ui->numberEdit->setText(QString::fromStdString(std::string(ex.what())));
        fracController.setState(TCtrl<TFrac, FEditor>::CtrlState::cError);
    }
}


void MainWindow::on_result_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    try{
        fracController.setNumber(std::make_unique<TFrac>(ui->numberEdit->text().toStdString()));
        ui->numberEdit->setText(QString::fromStdString(fracController.calculate()));
    }
    catch(const std::exception& ex){
        ui->numberEdit->setText(QString::fromStdString(std::string(ex.what())));
        fracController.setState(TCtrl<TFrac, FEditor>::CtrlState::cError);
    }
}


void MainWindow::on_sqr_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    try{
        fracController.setNumber(std::make_unique<TFrac>(ui->numberEdit->text().toStdString()));
        ui->numberEdit->setText(QString::fromStdString(fracController.executeFunction(TProc<TFrac>::Sqr)));
    }
    catch(const std::exception& ex){
        ui->numberEdit->setText(QString::fromStdString(std::string(ex.what())));
        fracController.setState(TCtrl<TFrac, FEditor>::CtrlState::cError);
    }
}

void MainWindow::on_inv_clicked()
{
    if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;
    try{
        fracController.setNumber(std::make_unique<TFrac>(ui->numberEdit->text().toStdString()));
        ui->numberEdit->setText(QString::fromStdString(fracController.executeFunction(TProc<TFrac>::Rev)));
    }
    catch(const std::exception& ex){
        ui->numberEdit->setText(QString::fromStdString(std::string(ex.what())));
        fracController.setState(TCtrl<TFrac, FEditor>::CtrlState::cError);
    }
}

void MainWindow::on_memoryReset_clicked()
{
    TMemory<TFrac>::State state;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandMemory(TMemory<TFrac>::Take, std::make_unique<TFrac>(ui->numberEdit->text().toStdString()), state)));
    bool flag = state == TMemory<TFrac>::State::On;
    ui->memoryClear->setEnabled(flag);
    ui->memoryPlus->setEnabled(flag);
    ui->memoryReset->setEnabled(flag);
}


void MainWindow::on_memoryStore_clicked()
{
    TMemory<TFrac>::State state;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandMemory(TMemory<TFrac>::Store, std::make_unique<TFrac>(ui->numberEdit->text().toStdString()), state)));
    bool flag = state == TMemory<TFrac>::State::On;
    ui->memoryClear->setEnabled(flag);
    ui->memoryPlus->setEnabled(flag);
    ui->memoryReset->setEnabled(flag);
}


void MainWindow::on_memoryClear_clicked()
{
    TMemory<TFrac>::State state;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandMemory(TMemory<TFrac>::Clear, std::make_unique<TFrac>(ui->numberEdit->text().toStdString()), state)));
    bool flag = state == TMemory<TFrac>::State::On;
    ui->memoryClear->setEnabled(flag);
    ui->memoryPlus->setEnabled(flag);
    ui->memoryReset->setEnabled(flag);
}


void MainWindow::on_memoryPlus_clicked()
{
    TMemory<TFrac>::State state;
    ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandMemory(TMemory<TFrac>::Add, std::make_unique<TFrac>(ui->numberEdit->text().toStdString()), state)));
    bool flag = state == TMemory<TFrac>::State::On;
    ui->memoryClear->setEnabled(flag);
    ui->memoryPlus->setEnabled(flag);
    ui->memoryReset->setEnabled(flag);
}

void MainWindow::on_realButton_toggled(bool checked)
{
    if (checked){
        CEditor* editor = dynamic_cast<CEditor*>(complexController.getEditor());
        if (editor->changeEditMode() != CEditor::EditMode::Actual) editor->changeEditMode();
    }
}

void MainWindow::on_imaginaryButton_toggled(bool checked)
{
    if (checked){
        CEditor* editor = dynamic_cast<CEditor*>(complexController.getEditor());
        if (editor->changeEditMode() != CEditor::EditMode::Imaginary) editor->changeEditMode();
    }
}


void MainWindow::on_button1_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cOne)));
}


void MainWindow::on_button2_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cTwo)));
}


void MainWindow::on_button9_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cNine)));
}


void MainWindow::on_button3_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cThree)));
}


void MainWindow::on_button4_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cFour)));
}


void MainWindow::on_button5_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cFive)));
}


void MainWindow::on_button6_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cSix)));
}


void MainWindow::on_button7_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cSeven)));
}


void MainWindow::on_button8_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cEight)));
}


void MainWindow::on_button0_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cZero)));
}


void MainWindow::on_separator_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cSeparatorFR)));
}


void MainWindow::on_clear_2_clicked()
{
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cCE)));
    complexController.reset();
    ui->currentOperation_2->setText("None");
    ui->realButton->setChecked(true);
}


void MainWindow::on_clearElement_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cCE)));
    complexController.clearRightOperand();
    ui->realButton->setChecked(true);
}


void MainWindow::on_backSpace_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cBS)));
}


void MainWindow::on_buttonMinus_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    complexController.setNumber(std::make_unique<TComplex>(ui->numberEdit_2->text().toStdString()));
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cSign)));
}


void MainWindow::on_add_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    try{
        complexController.setNumber(std::make_unique<TComplex>(ui->numberEdit_2->text().toStdString()));
        ui->numberEdit_2->setText(QString::fromStdString(complexController.executeOperation(TProc<TComplex>::Add)));
        ui->currentOperation_2->setText("+");
    }
    catch(const std::exception& ex){
        ui->numberEdit_2->setText(QString::fromStdString(std::string(ex.what())));
        complexController.setState(TCtrl<TComplex, CEditor>::CtrlState::cError);
    }
    ui->realButton->setChecked(true);
}


void MainWindow::on_sub_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    try{
        complexController.setNumber(std::make_unique<TComplex>(ui->numberEdit_2->text().toStdString()));
        ui->numberEdit_2->setText(QString::fromStdString(complexController.executeOperation(TProc<TComplex>::Sub)));
        ui->currentOperation_2->setText("-");
    }
    catch(const std::exception& ex){
        ui->numberEdit_2->setText(QString::fromStdString(std::string(ex.what())));
        complexController.setState(TCtrl<TComplex, CEditor>::CtrlState::cError);
    }
    ui->realButton->setChecked(true);
}


void MainWindow::on_mul_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    try{
        complexController.setNumber(std::make_unique<TComplex>(ui->numberEdit_2->text().toStdString()));
        ui->numberEdit_2->setText(QString::fromStdString(complexController.executeOperation(TProc<TComplex>::Mul)));
        ui->currentOperation_2->setText("*");
    }
    catch(const std::exception& ex){
        ui->numberEdit_2->setText(QString::fromStdString(std::string(ex.what())));
        complexController.setState(TCtrl<TComplex, CEditor>::CtrlState::cError);
    }
    ui->realButton->setChecked(true);
}


void MainWindow::on_div_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    try{
        complexController.setNumber(std::make_unique<TComplex>(ui->numberEdit_2->text().toStdString()));
        ui->numberEdit_2->setText(QString::fromStdString(complexController.executeOperation(TProc<TComplex>::Div)));
        ui->currentOperation_2->setText("/");
    }
    catch(const std::exception& ex){
        ui->numberEdit_2->setText(QString::fromStdString(std::string(ex.what())));
        complexController.setState(TCtrl<TComplex, CEditor>::CtrlState::cError);
    }
    ui->realButton->setChecked(true);
}


void MainWindow::on_sqr_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    try{
        complexController.setNumber(std::make_unique<TComplex>(ui->numberEdit_2->text().toStdString()));
        ui->numberEdit_2->setText(QString::fromStdString(complexController.executeFunction(TProc<TComplex>::Sqr)));
    }
    catch(const std::exception& ex){
        ui->numberEdit_2->setText(QString::fromStdString(std::string(ex.what())));
        complexController.setState(TCtrl<TComplex, CEditor>::CtrlState::cError);
    }
}


void MainWindow::on_inv_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    try{
        complexController.setNumber(std::make_unique<TComplex>(ui->numberEdit_2->text().toStdString()));
        ui->numberEdit_2->setText(QString::fromStdString(complexController.executeFunction(TProc<TComplex>::Rev)));
    }
    catch(const std::exception& ex){
        ui->numberEdit_2->setText(QString::fromStdString(std::string(ex.what())));
        complexController.setState(TCtrl<TComplex, CEditor>::CtrlState::cError);
    }
}


void MainWindow::on_result_2_clicked()
{
    if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;
    try{
        complexController.setNumber(std::make_unique<TComplex>(ui->numberEdit_2->text().toStdString()));
        ui->numberEdit_2->setText(QString::fromStdString(complexController.calculate()));
    }
    catch(const std::exception& ex){
        ui->numberEdit_2->setText(QString::fromStdString(std::string(ex.what())));
        complexController.setState(TCtrl<TComplex, CEditor>::CtrlState::cError);
    }
    ui->realButton->setChecked(true);
}


void MainWindow::on_memoryClear_2_clicked()
{
    TMemory<TComplex>::State state;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandMemory(TMemory<TComplex>::Clear, std::make_unique<TComplex>(ui->numberEdit_2->text().toStdString()), state)));
    bool flag = state == TMemory<TComplex>::State::On;
    ui->memoryClear_2->setEnabled(flag);
    ui->memoryPlus_2->setEnabled(flag);
    ui->memoryReset_2->setEnabled(flag);
}


void MainWindow::on_memoryReset_2_clicked()
{
    TMemory<TComplex>::State state;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandMemory(TMemory<TComplex>::Take, std::make_unique<TComplex>(ui->numberEdit_2->text().toStdString()), state)));
    bool flag = state == TMemory<TComplex>::State::On;
    ui->memoryClear_2->setEnabled(flag);
    ui->memoryPlus_2->setEnabled(flag);
    ui->memoryReset_2->setEnabled(flag);
}


void MainWindow::on_memoryStore_2_clicked()
{
    TMemory<TComplex>::State state;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandMemory(TMemory<TComplex>::Store, std::make_unique<TComplex>(ui->numberEdit_2->text().toStdString()), state)));
    bool flag = state == TMemory<TComplex>::State::On;
    ui->memoryClear_2->setEnabled(flag);
    ui->memoryPlus_2->setEnabled(flag);
    ui->memoryReset_2->setEnabled(flag);
}


void MainWindow::on_memoryPlus_2_clicked()
{
    TMemory<TComplex>::State state;
    ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandMemory(TMemory<TComplex>::Add, std::make_unique<TComplex>(ui->numberEdit_2->text().toStdString()), state)));
    bool flag = state == TMemory<TComplex>::State::On;
    ui->memoryClear_2->setEnabled(flag);
    ui->memoryPlus_2->setEnabled(flag);
    ui->memoryReset_2->setEnabled(flag);
}

double StringToDouble(const std::string& value, int base)
{
    double result = 0.0;
    bool isFraction = false;
    double fractionMultiplier = 1.0;
    bool isNegative = (value[0] == '-');

    size_t startIndex = (isNegative || value[0] == '+') ? 1 : 0;

    for (size_t i = startIndex; i < value.size(); ++i)
    {
        char ch = value[i];

        if (ch == '.')
        {
            isFraction = true;
            continue;
        }

        char upperCh = std::toupper(ch);

        short digit;
        if (upperCh >= '0' && upperCh <= '9')
        {
            digit = upperCh - '0';
        }
        else if (upperCh >= 'A' && upperCh <= 'F')
        {
            digit = upperCh - 'A' + 10;
        }

        if (isFraction)
        {
            fractionMultiplier /= base;
            result += digit * fractionMultiplier;
        }
        else
        {
            result = result * base + digit;
        }
    }

    return isNegative ? -result : result;
}


void MainWindow::on_slider_valueChanged(int value)
{
    ui->label->setText(QString::number(value));
    value < 3 ? ui->button2_5->setEnabled(false) : ui->button2_5->setEnabled(true);
    value < 4 ? ui->button3_5->setEnabled(false) : ui->button3_5->setEnabled(true);
    value < 5 ? ui->button4_5->setEnabled(false) : ui->button4_5->setEnabled(true);
    value < 6 ? ui->button5_5->setEnabled(false) : ui->button5_5->setEnabled(true);
    value < 7 ? ui->button6_5->setEnabled(false) : ui->button6_5->setEnabled(true);
    value < 8 ? ui->button7_5->setEnabled(false) : ui->button7_5->setEnabled(true);
    value < 9 ? ui->button8_5->setEnabled(false) : ui->button8_5->setEnabled(true);
    value < 10 ? ui->button9_5->setEnabled(false) : ui->button9_5->setEnabled(true);
    value < 11 ? ui->buttonA->setEnabled(false) : ui->buttonA->setEnabled(true);
    value < 12 ? ui->buttonB->setEnabled(false) : ui->buttonB->setEnabled(true);
    value < 13 ? ui->buttonC->setEnabled(false) : ui->buttonC->setEnabled(true);
    value < 14 ? ui->buttonD->setEnabled(false) : ui->buttonD->setEnabled(true);
    value < 15 ? ui->buttonE->setEnabled(false) : ui->buttonE->setEnabled(true);
    value < 16 ? ui->buttonF->setEnabled(false) : ui->buttonF->setEnabled(true);
    ///
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    std::string numberString = ui->numberEdit_5->text().toStdString();
    int base = ui->slider->value();
    int precision = ui->slider_2->value();
    double number = StringToDouble(numberString, prevBase);
    pnumberController.setNumber(std::make_unique<TPNumber>(number, base, precision));
    pnumberController.setEditor(std::make_unique<PEditor>(number, base, precision));
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.genNumber()));
    prevBase = base;
}


void MainWindow::on_slider_2_valueChanged(int value)
{
    ui->label_2->setText(QString::number(value));
    ///
    int base = ui->slider->value();
    int precision = ui->slider_2->value();
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    pnumberController.setNumber(std::make_unique<TPNumber>(ui->numberEdit_5->text().toStdString(), std::to_string(base), std::to_string(precision)));
    pnumberController.setEditor(std::make_unique<PEditor>(ui->numberEdit_5->text().toStdString(), std::to_string(base), std::to_string(precision)));
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.genNumber()));
}


void MainWindow::on_button0_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cZero)));
}


void MainWindow::on_button1_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cOne)));
}


void MainWindow::on_button2_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cTwo)));
}


void MainWindow::on_button3_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cThree)));
}


void MainWindow::on_button4_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cFour)));
}


void MainWindow::on_button5_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cFive)));
}


void MainWindow::on_button6_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cSix)));
}


void MainWindow::on_button7_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cSeven)));
}


void MainWindow::on_button8_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cEight)));
}


void MainWindow::on_button9_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cNine)));
}


void MainWindow::on_buttonA_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cA)));
}


void MainWindow::on_buttonB_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cB)));
}


void MainWindow::on_buttonC_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cC)));
}


void MainWindow::on_buttonD_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cD)));
}


void MainWindow::on_buttonE_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cE)));
}


void MainWindow::on_buttonF_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cF)));
}


void MainWindow::on_backSpace_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cBS)));
}


void MainWindow::on_separator_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cSeparatorC)));
}


void MainWindow::on_clearElement_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cCE)));
    pnumberController.clearRightOperand();
    on_slider_valueChanged(prevBase);
    on_slider_2_valueChanged(ui->slider_2->value());
}


void MainWindow::on_clear_5_clicked()
{
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cCE)));
    pnumberController.reset();
    ui->currentOperation_5->setText("None");
    on_slider_valueChanged(prevBase);
    on_slider_2_valueChanged(ui->slider_2->value());
}


void MainWindow::on_add_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    try{
        pnumberController.setNumber(std::make_unique<TPNumber>(ui->numberEdit_5->text().toStdString(), std::to_string(ui->slider->value()), std::to_string(ui->slider_2->value())));
        ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeOperation(TProc<TPNumber>::Add)));
        ui->currentOperation_5->setText("+");
    }
    catch(const std::exception& ex){
        ui->numberEdit_5->setText(QString::fromStdString(std::string(ex.what())));
        pnumberController.setState(TCtrl<TPNumber, PEditor>::CtrlState::cError);
    }
}


void MainWindow::on_sub_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    try{
        pnumberController.setNumber(std::make_unique<TPNumber>(ui->numberEdit_5->text().toStdString(), std::to_string(ui->slider->value()), std::to_string(ui->slider_2->value())));
        ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeOperation(TProc<TPNumber>::Sub)));
        ui->currentOperation_5->setText("-");
    }
    catch(const std::exception& ex){
        ui->numberEdit_5->setText(QString::fromStdString(std::string(ex.what())));
        pnumberController.setState(TCtrl<TPNumber, PEditor>::CtrlState::cError);
    }
}


void MainWindow::on_mul_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    try{
        pnumberController.setNumber(std::make_unique<TPNumber>(ui->numberEdit_5->text().toStdString(), std::to_string(ui->slider->value()), std::to_string(ui->slider_2->value())));
        ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeOperation(TProc<TPNumber>::Mul)));
        ui->currentOperation_5->setText("*");
    }
    catch(const std::exception& ex){
        ui->numberEdit_5->setText(QString::fromStdString(std::string(ex.what())));
        pnumberController.setState(TCtrl<TPNumber, PEditor>::CtrlState::cError);
    }
}


void MainWindow::on_div_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    try{
        pnumberController.setNumber(std::make_unique<TPNumber>(ui->numberEdit_5->text().toStdString(), std::to_string(ui->slider->value()), std::to_string(ui->slider_2->value())));
        ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeOperation(TProc<TPNumber>::Div)));
        ui->currentOperation_5->setText("/");
    }
    catch(const std::exception& ex){
        ui->numberEdit_5->setText(QString::fromStdString(std::string(ex.what())));
        pnumberController.setState(TCtrl<TPNumber, PEditor>::CtrlState::cError);
    }
}


void MainWindow::on_sqr_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    try{
        pnumberController.setNumber(std::make_unique<TPNumber>(ui->numberEdit_5->text().toStdString(), std::to_string(ui->slider->value()), std::to_string(ui->slider_2->value())));
        ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeFunction(TProc<TPNumber>::Sqr)));
    }
    catch(const std::exception& ex){
        ui->numberEdit_5->setText(QString::fromStdString(std::string(ex.what())));
        pnumberController.setState(TCtrl<TPNumber, PEditor>::CtrlState::cError);
    }
}


void MainWindow::on_inv_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    try{
        pnumberController.setNumber(std::make_unique<TPNumber>(ui->numberEdit_5->text().toStdString(), std::to_string(ui->slider->value()), std::to_string(ui->slider_2->value())));
        ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeFunction(TProc<TPNumber>::Rev)));
    }
    catch(const std::exception& ex){
        ui->numberEdit_5->setText(QString::fromStdString(std::string(ex.what())));
        pnumberController.setState(TCtrl<TPNumber, PEditor>::CtrlState::cError);
    }
}


void MainWindow::on_result_5_clicked()
{
    if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;
    try{
        pnumberController.setNumber(std::make_unique<TPNumber>(ui->numberEdit_5->text().toStdString(), std::to_string(ui->slider->value()), std::to_string(ui->slider_2->value())));
        ui->numberEdit_5->setText(QString::fromStdString(pnumberController.calculate()));
    }
    catch(const std::exception& ex){
        ui->numberEdit_5->setText(QString::fromStdString(std::string(ex.what())));
        pnumberController.setState(TCtrl<TPNumber, PEditor>::CtrlState::cError);
    }
}


void MainWindow::on_memoryClear_5_clicked()
{
    TMemory<TPNumber>::State state;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandMemory(TMemory<TPNumber>::Clear, std::make_unique<TPNumber>(ui->numberEdit_5->text().toStdString(), std::to_string(ui->slider->value()), std::to_string(ui->slider_2->value())), state)));
    bool flag = state == TMemory<TPNumber>::State::On;
    ui->memoryClear_5->setEnabled(flag);
    ui->memoryPlus_5->setEnabled(flag);
    ui->memoryReset_5->setEnabled(flag);
}


void MainWindow::on_memoryReset_5_clicked()
{
    TMemory<TPNumber>::State state;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandMemory(TMemory<TPNumber>::Take, std::make_unique<TPNumber>(ui->numberEdit_5->text().toStdString(), std::to_string(ui->slider->value()), std::to_string(ui->slider_2->value())), state)));
    bool flag = state == TMemory<TPNumber>::State::On;
    ui->memoryClear_5->setEnabled(flag);
    ui->memoryPlus_5->setEnabled(flag);
    ui->memoryReset_5->setEnabled(flag);
}


void MainWindow::on_memoryStore_5_clicked()
{
    TMemory<TPNumber>::State state;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandMemory(TMemory<TPNumber>::Store, std::make_unique<TPNumber>(ui->numberEdit_5->text().toStdString(), std::to_string(ui->slider->value()), std::to_string(ui->slider_2->value())), state)));
    bool flag = state == TMemory<TPNumber>::State::On;
    ui->memoryClear_5->setEnabled(flag);
    ui->memoryPlus_5->setEnabled(flag);
    ui->memoryReset_5->setEnabled(flag);
}


void MainWindow::on_memoryPlus_5_clicked()
{
    TMemory<TPNumber>::State state;
    ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandMemory(TMemory<TPNumber>::Add, std::make_unique<TPNumber>(ui->numberEdit_5->text().toStdString(), std::to_string(ui->slider->value()), std::to_string(ui->slider_2->value())), state)));
    bool flag = state == TMemory<TPNumber>::State::On;
    ui->memoryClear_5->setEnabled(flag);
    ui->memoryPlus_5->setEnabled(flag);
    ui->memoryReset_5->setEnabled(flag);
}

void MainWindow::onShortcutBS()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_backSpace_clicked();
    } else if (current_tab_index == 1) {
        on_backSpace_2_clicked();
    }
    else
    {
        on_backSpace_5_clicked();
    }
}

void MainWindow::onShortcut0()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_button0_clicked();
    } else if (current_tab_index == 1) {
        on_button0_2_clicked();
    }
    else
    {
        on_button0_5_clicked();
    }
}

void MainWindow::onShortcut1()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_button1_clicked();
    } else if (current_tab_index == 1) {
        on_button1_2_clicked();
    }
    else
    {
        on_button1_5_clicked();
    }
}

void MainWindow::onShortcut2()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_button2_clicked();
    } else if (current_tab_index == 1) {
        on_button2_2_clicked();
    }
    else
    {
        if (ui->button2_5->isEnabled())
            on_button2_5_clicked();
    }
}

void MainWindow::onShortcut3()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_button3_clicked();
    } else if (current_tab_index == 1) {
        on_button3_2_clicked();
    }
    else
    {
        if (ui->button3_5->isEnabled())
            on_button3_5_clicked();
    }
}

void MainWindow::onShortcut4()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_button4_clicked();
    } else if (current_tab_index == 1) {
        on_button4_2_clicked();
    }
    else
    {
        if (ui->button4_5->isEnabled())
            on_button4_5_clicked();
    }
}

void MainWindow::onShortcut5()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_button5_clicked();
    } else if (current_tab_index == 1) {
        on_button5_2_clicked();
    }
    else
    {
        if (ui->button5_5->isEnabled())
            on_button5_5_clicked();
    }
}

void MainWindow::onShortcut6()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_button6_clicked();
    } else if (current_tab_index == 1) {
        on_button6_2_clicked();
    }
    else
    {
        if (ui->button6_5->isEnabled())
            on_button6_5_clicked();
    }
}

void MainWindow::onShortcut7()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_button7_clicked();
    } else if (current_tab_index == 1) {
        on_button7_2_clicked();
    }
    else
    {
        if (ui->button7_5->isEnabled())
            on_button7_5_clicked();
    }
}

void MainWindow::onShortcut8()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_button8_clicked();
    } else if (current_tab_index == 1) {
        on_button8_2_clicked();
    }
    else
    {
        if (ui->button8_5->isEnabled())
            on_button8_5_clicked();
    }
}

void MainWindow::onShortcut9()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_button9_clicked();
    } else if (current_tab_index == 1) {
        on_button9_2_clicked();
    }
    else
    {
        if (ui->button9_5->isEnabled())
            on_button9_5_clicked();
    }
}

void MainWindow::onShortcutA()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 2) {
        if (ui->buttonA->isEnabled())
            on_buttonA_clicked();
    }

    else if (current_tab_index == 1){
        ui->realButton->setChecked(true);
    }
}

void MainWindow::onShortcutB()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 2) {
        if (ui->buttonB->isEnabled())
            on_buttonB_clicked();
    }
}

void MainWindow::onShortcutC()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 2) {
        if (ui->buttonC->isEnabled())
            on_buttonC_clicked();
    }
}

void MainWindow::onShortcutD()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 2) {
        if (ui->buttonD->isEnabled())
            on_buttonD_clicked();
    }
    else if (current_tab_index == 1){
        ui->imaginaryButton->setChecked(true);
    }
}

void MainWindow::onShortcutE()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 2) {
        if (ui->buttonE->isEnabled())
            on_buttonE_clicked();
    }
}

void MainWindow::onShortcutF()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 2) {
        if (ui->buttonF->isEnabled())
            on_buttonF_clicked();
    }
}

void MainWindow::onShortcutDot()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 1) {
        on_separator_2_clicked();
    } else if (current_tab_index == 2) {
        on_separator_5_clicked();
    }
}

void MainWindow::onShortcutRaz()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_separator_clicked();
    }
}

void MainWindow::onShortcutAdd()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_add_clicked();
    }
    else if (current_tab_index == 1){
        on_add_2_clicked();
    }
    else
    {
        on_add_5_clicked();
    }
}

void MainWindow::onShortcutSub()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_sub_clicked();
    }
    else if (current_tab_index == 1){
        on_sub_2_clicked();
    }
    else
    {
        on_sub_5_clicked();
    }
}

void MainWindow::onShortcutMul()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_mul_clicked();
    }
    else if (current_tab_index == 1){
        on_mul_2_clicked();
    }
    else
    {
        on_mul_5_clicked();
    }
}

void MainWindow::onShortcutDiv()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_div_clicked();
    }
    else if (current_tab_index == 1){
        on_div_2_clicked();
    }
    else
    {
        on_div_5_clicked();
    }
}

void MainWindow::onShortcutCopy()
{
    int current_tab_index = ui->tabWidget->currentIndex();
    QString text{};

    if (current_tab_index == 0) {
        text = ui->numberEdit->text();
    }
    else if (current_tab_index == 1){
        text = ui->numberEdit_2->text();
    }
    else
    {
        text = ui->numberEdit_5->text();
    }
    clipboard->setText(text);
}

void MainWindow::onShortcutPast()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        if (fracController.getState() == TCtrl<TFrac, FEditor>::CtrlState::cError) return;

        try {
            ui->numberEdit->setText(QString::fromStdString(fracController.executeCommandEditor(AEditor::Command::cPast)));
        }
        catch (const std::exception& ex) {
            ui->numberEdit->setText(QString::fromStdString(std::string(ex.what())));
            fracController.setState(TCtrl<TFrac, FEditor>::CtrlState::cError);
        }
    }
    else if (current_tab_index == 1){
        if (complexController.getState() == TCtrl<TComplex, CEditor>::CtrlState::cError) return;

        try {
            ui->numberEdit_2->setText(QString::fromStdString(complexController.executeCommandEditor(AEditor::Command::cPast)));
        }
        catch (const std::exception& ex) {
            ui->numberEdit_2->setText(QString::fromStdString(std::string(ex.what())));
            complexController.setState(TCtrl<TComplex, CEditor>::CtrlState::cError);
        }
        ui->realButton->setChecked(true);
    }
    else
    {
        if (pnumberController.getState() == TCtrl<TPNumber, PEditor>::CtrlState::cError) return;

        try {
            ui->numberEdit_5->setText(QString::fromStdString(pnumberController.executeCommandEditor(AEditor::Command::cPast)));
        }
        catch (const std::exception& ex) {
            ui->numberEdit_5->setText(QString::fromStdString(std::string(ex.what())));
            pnumberController.setState(TCtrl<TPNumber, PEditor>::CtrlState::cError);
        }
    }
}

void MainWindow::onShortcutResult()
{
    int current_tab_index = ui->tabWidget->currentIndex();

    if (current_tab_index == 0) {
        on_result_clicked();
    }
    else if (current_tab_index == 1){
        on_result_2_clicked();
    }
    else
    {
        on_result_5_clicked();
    }
}

void MainWindow::on_action_triggered()
{
    QDialog dlg(this);
    dlg.setWindowTitle(tr("Autor"));

    QLabel *ledit1 = new QLabel(&dlg);
    ledit1->setText("Шпилев Даниил ИП-113");

    dlg.setParent(this);
    dlg.setModal(true);
    dlg.exec();
}

