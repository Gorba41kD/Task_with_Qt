#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>

#include "paintscene.h"

#include <QString>
#include <QSvgGenerator>
#include <QFileDialog>
#include <QPainter>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

   public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow() noexcept ;

   private:
    Ui::MainWindow *ui;

    // Declare the graphic scene
    PaintScene *scene;

    /* Define a timer for preparing current sizes
    * graphic scene
    * */
    QTimer *timer;

    // Path to the file where the drawing will be saved
    QString path;

   private:
    /* Override the window resizing event
    * to recalculate the size of the graphic scene
    * */
    void resizeEvent(QResizeEvent * event);

   private slots:
    // The timer slot is needed to correctly resize the scene when resizing the Application Window
    void slotTimer();
    void slotRectangleButton(); // Enable rectangle drawing
    void slotTriangleButton(); // Enable triangle drawing
    void slotEllipseButton(); // Enable ellipse drawing
    void slotLineButton(); // Enable drawing of the line that should connect the shapes
    void slotSaveButton(); // Enable saving the picture to a file with the svg extension
    void slotLoadButton(); // Enable drawing of a picture from a file with the svg extension
    // void slotMoveButton(); // TODO
    // void slotDeleteButton(); // TODO
};

#endif // MAINWINDOW_H
