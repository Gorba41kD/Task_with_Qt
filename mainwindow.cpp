#include "mainwindow.h"
#include "svgreader.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
 QMainWindow(parent),
 ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto& butRectangle = ui->pushButton;
    auto& butTriangle = ui->pushButton_2;
    auto& butEllipse = ui->pushButton_3;
    auto& butLine = ui->pushButton_4;
    auto& butLoad = ui->pushButton_7;
    auto& butSave = ui->pushButton_8;


    scene = new PaintScene(); // Initialize the graphic scene

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing); // Set anti-aliasing
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Disable vertical scrollbar
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Disable horizontal scrollbar

    timer = new QTimer(); // Initialize the timer
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100); // Start the timer

    connect(butRectangle,&QPushButton::clicked,this,& MainWindow::slotRectangleButton);
    connect(butTriangle,&QPushButton::clicked,this,& MainWindow::slotTriangleButton);
    connect(butEllipse,&QPushButton::clicked,this,& MainWindow::slotEllipseButton);
    connect(butLine,&QPushButton::clicked,this,& MainWindow::slotLineButton);
    connect(butSave,&QPushButton::clicked,this,& MainWindow::slotSaveButton);
    connect(butLoad,&QPushButton::clicked,this,& MainWindow::slotLoadButton);
}

MainWindow::~MainWindow() noexcept
{
    delete ui;
    delete scene;
    delete timer;
}

void MainWindow::slotTimer()
{
    /* Redefine the dimensions of the graphic scene
    * depending on window size
    * */
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}

// Set the rectangle
void MainWindow::slotRectangleButton()
{
    scene->setTypeFigure(PaintScene::RectangleType);
}

// Set up a triangle
void MainWindow::slotTriangleButton()
{
    scene->setTypeFigure(PaintScene::TriangleType);
}

// Set up an ellipse
void MainWindow::slotEllipseButton()
{
    scene->setTypeFigure(PaintScene::EllipseType);
}

// Set the line
void MainWindow::slotLineButton()
{
    scene->setTypeFigure(PaintScene::LineType);
}

// Save the drawing to a file
void MainWindow::slotSaveButton()
{
    // Let's take the path to the file and its name, which we will create
    QString newPath = QFileDialog::getSaveFileName(this, tr("Save SVG"),
    path, tr("SVG files (*.svg)"));

    if (newPath.isEmpty())
    {
        return;
    }

    path = newPath;

    QSvgGenerator generator; // Create a file generator object

    generator.setFileName(path); // Set the path to the file where the vector graphics will be saved
    generator.setSize(QSize(scene->width(), scene->height())); // Set the dimensions of the document working area in millimeters
    generator.setViewBox(QRect(0, 0, scene->width(), scene->height())); // Set the work area in coordinates
    generator.setTitle(tr("SVG Example")); // Title title of the document
    generator.setDescription(tr("File created by SVG Example")); // Document description

    QPainter painter;

    painter.begin(&generator); // Set the device/object in which we will render
    scene->render(&painter); // Render the contents of the scene to the target device/object
    painter.end(); // Finish rendering

    // At the end of rendering we get a vector file with the contents of the graphic scene

   }
   // Opening a picture from a file
   void MainWindow::slotLoadButton()
   {
    QString newPath = QFileDialog::getOpenFileName(this, tr("Open SVG"),
    path, tr("SVG files (*.svg)"));

    if (newPath.isEmpty())
    {
        return;
    }

    path = newPath;
    scene->clear();

    scene->setSceneRect(SvgReader::getSizes(path)); // Set the dimensions of the graphic scene

    // Install objects on the graphic scene using the setElements method
    SvgReader::setElements(path,scene);
}
