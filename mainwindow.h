#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UControl.h"
#include "UANumber.h"
#include "UAEditor.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button0_clicked();

    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

    void on_button6_clicked();

    void on_button7_clicked();

    void on_button8_clicked();

    void on_button9_clicked();

    void on_separator_clicked();

    void on_backSpace_clicked();

    void on_clear_clicked();

    void on_buttonMinus_clicked();

    void on_clearElement_clicked();

    void on_add_clicked();

    void on_sub_clicked();

    void on_mul_clicked();

    void on_div_clicked();

    void on_result_clicked();

    void on_sqr_clicked();

    void on_inv_clicked();

    void on_memoryReset_clicked();

    void on_memoryStore_clicked();

    void on_memoryClear_clicked();

    void on_memoryPlus_clicked();

    void on_realButton_toggled(bool checked);

    void on_imaginaryButton_toggled(bool checked);

    void on_button1_2_clicked();

    void on_button2_2_clicked();

    void on_button9_2_clicked();

    void on_button3_2_clicked();

    void on_button4_2_clicked();

    void on_button5_2_clicked();

    void on_button6_2_clicked();

    void on_button7_2_clicked();

    void on_button8_2_clicked();

    void on_button0_2_clicked();

    void on_separator_2_clicked();

    void on_clear_2_clicked();

    void on_clearElement_2_clicked();

    void on_backSpace_2_clicked();

    void on_buttonMinus_2_clicked();

    void on_add_2_clicked();

    void on_sub_2_clicked();

    void on_mul_2_clicked();

    void on_div_2_clicked();

    void on_sqr_2_clicked();

    void on_inv_2_clicked();

    void on_result_2_clicked();

    void on_memoryClear_2_clicked();

    void on_memoryReset_2_clicked();

    void on_memoryStore_2_clicked();

    void on_memoryPlus_2_clicked();

    void on_slider_valueChanged(int value);

    void on_slider_2_valueChanged(int value);

    void on_button0_5_clicked();

    void on_button1_5_clicked();

    void on_button2_5_clicked();

    void on_button3_5_clicked();

    void on_button4_5_clicked();

    void on_button5_5_clicked();

    void on_button6_5_clicked();

    void on_button7_5_clicked();

    void on_button8_5_clicked();

    void on_button9_5_clicked();

    void on_buttonA_clicked();

    void on_buttonB_clicked();

    void on_buttonC_clicked();

    void on_buttonD_clicked();

    void on_buttonE_clicked();

    void on_buttonF_clicked();

    void on_backSpace_5_clicked();

    void on_separator_5_clicked();

    void on_clearElement_5_clicked();

    void on_clear_5_clicked();

    void on_add_5_clicked();

    void on_sub_5_clicked();

    void on_mul_5_clicked();

    void on_div_5_clicked();

    void on_sqr_5_clicked();

    void on_inv_5_clicked();

    void on_result_5_clicked();

    void on_memoryClear_5_clicked();

    void on_memoryReset_5_clicked();

    void on_memoryStore_5_clicked();

    void on_memoryPlus_5_clicked();

    void onShortcutBS();

    void onShortcut0();

    void onShortcut1();

    void onShortcut2();

    void onShortcut3();

    void onShortcut4();

    void onShortcut5();

    void onShortcut6();

    void onShortcut7();

    void onShortcut8();

    void onShortcut9();

    void onShortcutA();

    void onShortcutB();

    void onShortcutC();

    void onShortcutD();

    void onShortcutE();

    void onShortcutF();

    void onShortcutDot();

    void onShortcutRaz();

    void onShortcutAdd();

    void onShortcutSub();

    void onShortcutMul();

    void onShortcutDiv();

    void onShortcutCopy();

    void onShortcutPast();

    void on_action_triggered();

private:
    Ui::MainWindow *ui;
    TCtrl<TFrac, FEditor> fracController;
    TCtrl<TComplex, CEditor> complexController;
    TCtrl<TPNumber, PEditor> pnumberController;
    int prevBase = 10;
};
#endif // MAINWINDOW_H
