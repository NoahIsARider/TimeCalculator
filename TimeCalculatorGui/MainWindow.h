#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>

class QSpinBox;
class QTimeEdit;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    QWidget* buildDateTimeEditor(QSpinBox*& year, QSpinBox*& month,
                                 QSpinBox*& day, QTimeEdit*& timeEdit,
                                 const QString& title);
    void setDateTime(QSpinBox*& year, QSpinBox*& month, QSpinBox*& day,
                     QTimeEdit*& timeEdit, int y, int mo, int d,
                     int h, int mi, int s);
public slots:
    void calculateDifference();

private:
    void updateDayMax(QSpinBox* year, QSpinBox* month, QSpinBox* day);

    QSpinBox* year1;
    QSpinBox* month1;
    QSpinBox* day1;
    QTimeEdit* timeEdit1;
    QSpinBox* year2;
    QSpinBox* month2;
    QSpinBox* day2;
    QTimeEdit* timeEdit2;
    QLabel* resultLabel;
};

#endif // MAINWINDOW_H
