#include "mainwindow.h"
#include <QMenuBar>

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
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{

}
void MainWindow::closeEvent(QCloseEvent *event)
{
    std::cout << "<< CloseEvent >>: " << event->type() << std::endl;
    event->accept();
}
