#include "MainWindow.h"

#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QTime>
#include <QTimeEdit>
#include <QVBoxLayout>

#include "Date.h"
#include "DateTime.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("DateTime Difference Calculator");
    setMinimumWidth(560);

    QWidget* central = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(central);

    mainLayout->addWidget(buildDateTimeEditor(
        year1, month1, day1, timeEdit1, "Start datetime"));
    setDateTime(year1, month1, day1, timeEdit1, 2024, 2, 23, 23, 59, 59);

    mainLayout->addWidget(buildDateTimeEditor(
        year2, month2, day2, timeEdit2, "End datetime"));
    setDateTime(year2, month2, day2, timeEdit2, 2024, 3, 1, 0, 0, 1);

    QPushButton* calcButton = new QPushButton("Calculate difference", central);
    connect(calcButton, &QPushButton::clicked,
            this, &MainWindow::calculateDifference);
    mainLayout->addWidget(calcButton);

    resultLabel = new QLabel(
        "Enter two datetimes and press Calculate.", central);
    resultLabel->setAlignment(Qt::AlignCenter);
    resultLabel->setStyleSheet(
        "font-size: 16px; font-weight: bold; padding: 8px;");
    resultLabel->setWordWrap(true);
    mainLayout->addWidget(resultLabel);

    setCentralWidget(central);
}

void MainWindow::updateDayMax(QSpinBox* year, QSpinBox* month, QSpinBox* day) {
    // 让 day 的最大值跟随所选年月（2 月平/闰、30/31 天月份）
    Date d(year->value(), month->value(), 1);
    day->setMaximum(d.findMaxDay());
}

QWidget* MainWindow::buildDateTimeEditor(QSpinBox*& year, QSpinBox*& month,
                                         QSpinBox*& day, QTimeEdit*& timeEdit,
                                         const QString& title) {
    QGroupBox* group = new QGroupBox(title, this);
    QHBoxLayout* layout = new QHBoxLayout(group);

    year = new QSpinBox(group);
    year->setRange(1, 9999);
    year->setPrefix("Year: ");
    layout->addWidget(year);

    month = new QSpinBox(group);
    month->setRange(1, 12);
    month->setPrefix("Month: ");
    layout->addWidget(month);

    day = new QSpinBox(group);
    day->setRange(1, 31);
    day->setPrefix("Day: ");
    layout->addWidget(day);

    timeEdit = new QTimeEdit(group);
    timeEdit->setDisplayFormat("hh:mm:ss");
    layout->addWidget(new QLabel("Time:", group));
    layout->addWidget(timeEdit);

    // 月份/年份变化时同步 day 的最大值，避免 2 月 30 日等非法日期
    // （所有控件创建完成后再连接，避免 setValue 触发时指针未初始化）
    year->setValue(2024);
    month->setValue(2);
    day->setValue(23);
    const auto onYearChanged = QOverload<int>::of(&QSpinBox::valueChanged);
    const auto onMonthChanged = QOverload<int>::of(&QSpinBox::valueChanged);
    QObject::connect(year, onYearChanged, this,
                     [this, year, month, day] { updateDayMax(year, month, day); });
    QObject::connect(month, onMonthChanged, this,
                     [this, year, month, day] { updateDayMax(year, month, day); });
    updateDayMax(year, month, day);

    layout->addStretch();
    return group;
}

void MainWindow::setDateTime(QSpinBox*& year, QSpinBox*& month, QSpinBox*& day,
                             QTimeEdit*& timeEdit, int y, int mo, int d,
                             int h, int mi, int s) {
    year->setValue(y);
    month->setValue(mo);
    day->setValue(d);
    timeEdit->setTime(QTime(h, mi, s));
}

void MainWindow::calculateDifference() {
    const QTime t1 = timeEdit1->time();
    const QTime t2 = timeEdit2->time();

    DateTime dt1(year1->value(), month1->value(), day1->value(),
                 t1.hour(), t1.minute(), t1.second());
    DateTime dt2(year2->value(), month2->value(), day2->value(),
                 t2.hour(), t2.minute(), t2.second());

    const long long seconds = dt2.diffSeconds(dt1);
    const long long days = seconds / 86400LL;
    const long long rem = seconds % 86400LL;

    QString text = QString("Difference in seconds: %1").arg(seconds);
    if (seconds != 0) {
        text += QString("\n= %1 days, %2 hours, %3 minutes, %4 seconds")
                    .arg(days)
                    .arg(rem / 3600)
                    .arg((rem % 3600) / 60)
                    .arg(rem % 60);
    }
    resultLabel->setText(text);
}
