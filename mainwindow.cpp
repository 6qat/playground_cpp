#include "mainwindow.h"
#include <QMenuBar>
#include <QMouseEvent>
#include <QMessageBox>
#include <QApplication>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMenus();
    createStatusBar();
}
MainWindow::~MainWindow()
= default;

auto MainWindow::createMenus() -> void
{
    auto fileMenu = this->menuBar()->addMenu(tr("&File"));
    auto helpMenu = this->menuBar()->addMenu(tr("&Help"));

    auto newAct = new QAction(tr("&New"), this);
    auto quitAct = new QAction(tr("&Quit"), this);

    connect(quitAct, &QAction::triggered, this, &MainWindow::close);

    fileMenu->addAction(newAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    // #define qApp (static_cast<QApplication *>(QCoreApplication::instance()))
    auto app = (dynamic_cast<QApplication *>(QCoreApplication::instance()));
    auto aboutQtAct = helpMenu->addAction(tr("About &Qt"), app, &QApplication::aboutQt);

    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
}
auto MainWindow::createToolBars() -> void
{
    auto fileToolBar = addToolBar(tr("File"));
}
auto MainWindow::mouseMoveEvent(QMouseEvent *event) -> void
{
    QWidget::mouseMoveEvent(event);
    qDebug() << "<< MouseMoveEvent >> " << event->pos();
}
auto MainWindow::mousePressEvent(QMouseEvent *event) -> void
{
    qDebug() << "<< MousePressEvent >> " << event->pos();
}
auto MainWindow::closeEvent(QCloseEvent *event) -> void
{
    qDebug() << "<< CloseEvent >> " << event->type();

//    const QMessageBox::StandardButton ret
//        = QMessageBox::warning(this, tr("Application"),
//                               tr("Do you really want to leave?"),
//                               QMessageBox::Ok | QMessageBox::Cancel);
//
//
//    if (ret == QMessageBox::Ok)
//        event->accept();
//    else event->ignore();
}
auto MainWindow::contextMenuEvent(QContextMenuEvent *event) -> void
{
    qDebug() << "<< ContextMenuEvent >>";
    auto *menu = new QMenu(this);
    menu->addAction(tr("Action 1"));
    menu->addAction(tr("Action 2"));
    menu->popup(mapToGlobal(event->pos()));
}
auto MainWindow::enterEvent(QEnterEvent *event) -> void
{
    qDebug() << "<< EnterEvent >>";
}
auto MainWindow::leaveEvent(QEvent *event) -> void
{
    qDebug() << "<< LeaveEvent >>";
}
auto MainWindow::keyPressEvent(QKeyEvent *event) -> void
{
    if (event->modifiers() & Qt::ControlModifier) {
        qDebug() << "Control + " << event->text();
    }

    if (event->modifiers() & Qt::AltModifier) {
        qDebug() << "Alt + " << event->text();
    }

    if (event->modifiers() & Qt::ShiftModifier) {
        if (event->key() == Qt::Key_A)
            qDebug() << "Shift + " << event->text() << "(Shift+A detected)";
        else
            qDebug() << "Shift + " << event->text();
    }
}
auto MainWindow::resizeEvent(QResizeEvent *event) -> void
{
    qDebug() << "<< ResizeEvent >> Old size: " << event->oldSize() << " New size: " << event->size();
}
auto MainWindow::paintEvent(QPaintEvent *event) -> void
{
    qDebug() << "<< PaintEvent >> triggered";
}
auto MainWindow::createStatusBar() -> void
{
    statusBar()->showMessage(tr("Ready"));
}
