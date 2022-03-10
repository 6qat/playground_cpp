#include "mainwindow.h"
#include <QMenuBar>
#include <QMouseEvent>
#include <QMessageBox>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    createMenus();
}
MainWindow::~MainWindow()
{}

auto MainWindow::createMenus() -> void
{
    auto fileMenu = this->menuBar()->addMenu(tr("&File"));
    auto helpMenu = this->menuBar()->addMenu(tr("&Help"));

    auto *newAct = new QAction(tr("&New"), this);
    auto *quitAct = new QAction(tr("&Quit"), this);
    connect(quitAct, &QAction::triggered, this, &MainWindow::close);

    fileMenu->addAction(newAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    QAction *aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
}
auto MainWindow::createToolBars() -> void
{
    auto fileToolBar = addToolBar(tr("File"));
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    qDebug() << "<< MouseMoveEvent >> " << event->pos();
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "<< MousePressEvent >> " << event->pos();
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "<< CloseEvent >> " << event->type();

    const QMessageBox::StandardButton ret
        = QMessageBox::warning(this, tr("Application"),
                               tr("Do you really want to leave?"),
                               QMessageBox::Ok | QMessageBox::Cancel);


    if(ret == QMessageBox::Ok)
        event->accept();
    else event->ignore();
}
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "<< ContextMenuEvent >>";
    auto *menu = new QMenu(this);
    menu->addAction(tr("Action 1"));
    menu->addAction(tr("Action 2"));
    menu->popup(mapToGlobal(event->pos()));
}
void MainWindow::enterEvent(QEnterEvent *event)
{
    qDebug() << "<< EnterEvent >>";
}
void MainWindow::leaveEvent(QEvent *event)
{
    qDebug() << "<< LeaveEvent >>";
}
void MainWindow::keyPressEvent(QKeyEvent *event)
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
void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug() << "<< ResizeEvent >> Old size: " << event->oldSize() << " New size: " << event->size();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    qDebug() << "<< PaintEvent >> triggered";
}
