#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QCloseEvent>

// https://www.jetbrains.com/help/clion/overriding-methods-of-a-superclass.html

class MainWindow: public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    auto createMenus() -> void;
    auto createToolBars() -> void;

private:
    QAction *newAct;
    QAction *quitAct;

protected:
    void enterEvent(QEnterEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

};
#endif // MAINWINDOW_H
