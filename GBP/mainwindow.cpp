#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);    
    view->resize(this->width(), this->height());
    QString index = "file:///" + QDir("~bgptmp").absoluteFilePath("index.html");
    view->load(QUrl(index));
    view->setParent(this);

    setCentralWidget(view);
    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);

    QMainWindow::setStatusBar(nullptr);

    setMinimumSize(700,576);

    QString title = QFileInfo(QCoreApplication::applicationFilePath()).fileName();
    title = title.left(title.size()-4);
    this->setWindowTitle(title);

    QWebEngineSettings *settings = view->settings();
    settings->setAttribute(QWebEngineSettings::LocalStorageEnabled, true);
}

MainWindow::~MainWindow()
{
    delete ui;
    QDir("~bgptmp").removeRecursively();
}

