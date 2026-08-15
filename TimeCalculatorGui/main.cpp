#include <QApplication>

#include "MainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    QString screenshotPath;
    bool showResult = false;
    QStringList args = QApplication::arguments();
    int idx = args.indexOf("--screenshot");
    if (idx != -1 && idx + 1 < args.size()) {
        screenshotPath = args.at(idx + 1);
    }
    showResult = args.contains("--result");

    if (!screenshotPath.isEmpty()) {
        window.raise();
        window.activateWindow();
        window.adjustSize();
        QApplication::processEvents();
        if (showResult) {
            window.calculateDifference();
            QApplication::processEvents();
        }
        const QPixmap pix = window.grab();
        pix.save(screenshotPath);
        return 0;
    }

    return QApplication::exec();
}
