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
    qDebug() << "<< ContextMenu Event >>";
    auto *menu = new QMenu(this);
    menu->addAction(tr("Action 1"));
    menu->addAction(tr("Action 2"));
    menu->popup(mapToGlobal(event->pos()));
}
