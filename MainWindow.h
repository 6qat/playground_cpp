#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QCloseEvent>

// https://www.jetbrains.com/help/clion/overriding-methods-of-a-superclass.html
// https://doc.qt.io/archives/qq/qq11-events.html

class MainWindow: public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    auto createMenus() -> void;
    auto createToolBars() -> void;
    auto createStatusBar() -> void;
    auto createMainScreen() -> void;

private:


protected:
    auto enterEvent(QEnterEvent *event) -> void override;
    auto contextMenuEvent(QContextMenuEvent *event) -> void override;
    auto keyPressEvent(QKeyEvent *event) -> void override;
    auto mouseMoveEvent(QMouseEvent *event) -> void override;
    auto resizeEvent(QResizeEvent *event) -> void override;
    auto mousePressEvent(QMouseEvent *event) -> void override;
    auto closeEvent(QCloseEvent *event) -> void override;
    auto leaveEvent(QEvent *event) -> void override;
    auto paintEvent(QPaintEvent *event) -> void override;

};
#endif // MAINWINDOW_H
