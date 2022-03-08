#include "mainwindow.h"
#include <QMenuBar>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    newAct = new QAction(tr("&New"), this);
    quitAct = new QAction(tr("&Quit"), this);
    connect(quitAct, &QAction::triggered, this, &MainWindow::close);

    createMenus();
}
MainWindow::~MainWindow()
{}

auto MainWindow::createMenus() -> void
{
    auto fileMenu = this->menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);
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
    event->accept();
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
