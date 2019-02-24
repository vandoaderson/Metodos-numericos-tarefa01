#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "camera.h"
#include "scene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createScene();
    void render();

    Vec3 reflects(Vec3 raio, Vec3 norm);
    void normalizeColor(Color &color);
private:
    Ui::MainWindow *ui;

    Scene scene;
    Camera *camera;

    int sizeX;
    int sizeY;
};

#endif // MAINWINDOW_H
