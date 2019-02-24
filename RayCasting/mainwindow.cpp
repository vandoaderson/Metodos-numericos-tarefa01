#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sphere.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sizeX = 800;
    sizeY = 650;

    createScene();

    render();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createScene()
{
    Material material_gold( Color(0.09, 0.07, 0.02), Color(0.8549, 0.6470, 0.1254), Color(1.0, 1.0, 1.0), 4, 1.0, 1.0, 1.0 );
    Material material_red( Color(0.2, 0.0, 0.0), Color(1.0, 0, 0), Color(0.2, 0.2, 0.2), 200, 1.0, 1.0, 0.5 );           ///RED
    Material material_blue( Color(0.0, 0.0, 0.2), Color(0.0, 0, 1.0), Color(1.0, 1.0, 1.0), 10, 1.0, 1.0, 1.0 );        ///BLUE
    Material material_green( Color(0.0, 0.2, 0.0), Color(0.0, 0.9, 0.0), Color(1.0, 1.0, 1.0), 50, 1.0, 1.0, 0.1 );      ///GREEN
    Material material_white( Color(0.2, 0.2, 0.2), Color(1.0, 1.0, 1.0), Color(1.0, 1.0, 1.0), 200, 1.0, 1.0, 0.05 );      ///WHITE
    //=====================================================================================================
    //scene.addSphere( Point(6,-6,-20), 3, material_white ); // Body
    //scene.addSphere( Point(6,-1,-20), 2, material_white ); // Head

    //scene.addSphere( Point(6.5,-0.5,-18), 0.2, material_blue ); // Right eye
    //scene.addSphere( Point(5.5,-0.5,-18), 0.2, material_blue ); // Left eye

    //scene.addSphere( Point(6,-4,-17), 0.1, material_red ); // Button 1
    //scene.addSphere( Point(6,-5,-17), 0.1, material_red ); // Button 2
    //scene.addSphere( Point(6,-6,-17), 0.1, material_red ); // Button 3

//    scene.addCone(Point(0,0,0), Point(0,1,0), 1, material_gold);

    //=====================================================================================================
    scene.addLight(Point{10, 10, 20}, 1.0, 1.0, 1.0, 0.0001);     ///NORMAL WHITE LIGHT
    //=====================================================================================================
    camera = new Camera(sizeX, sizeY);
    camera->setPos( Point{0, 0, 10} );
    camera->lookAt( Point{0, 0, 0} );
}

void MainWindow::render()
{
    QImage image = QImage( sizeX, sizeY, QImage::Format_RGB32 );

    QImage bg("/home/vando/Documentos/Computer-graphics-1-master/RayCasting/sabiaguaba.jpg");
    bg = bg.scaled(sizeX, sizeY);

    for( int l=0; l<sizeX; l++ )
    {
        for( int c=0; c<sizeY; c++ )
        {
            Ray ray = camera->createRay(l, c);

            Intersection intersect;

            if(scene.intersect(ray, intersect))
            {
                Color color;

                ///AMBIENT COEFFICIENT
                color.r = intersect.material.ambient.r * intersect.material.Ka;
                color.g = intersect.material.ambient.g * intersect.material.Ka;
                color.b = intersect.material.ambient.b * intersect.material.Ka;

                for(int l=0; l < scene.lights.size(); l++)
                {
                    Vec3 L = scene.lights[l].position - intersect.point;
                    L.normalize();

                    double fator_dif = Dot(intersect.norm, L);
                    if( fator_dif <= 0.0001  )
                        fator_dif = 0.0;

                    ///DIFFUSE COEFFICIENT
                    color.r += scene.lights[l].color.r * fator_dif*intersect.material.diffuse.r*intersect.material.Kd;
                    color.g += scene.lights[l].color.g * fator_dif*intersect.material.diffuse.g*intersect.material.Kd;
                    color.b += scene.lights[l].color.b * fator_dif*intersect.material.diffuse.b*intersect.material.Kd;

                    //Vec3 reflexao = reflete(L,intersect.normal);
                    Vec3 reflexao = reflects(L,intersect.norm);
                    double fator_esp = Dot( ray.ray(), reflexao );
                    if( fator_esp <= 0.0001  )
                        fator_esp = 0.0;

                    ///SPECULAR COEFFICIENT
                    color.r += scene.lights[l].color.r * pow(fator_esp, intersect.material.k)*intersect.material.specular.r*intersect.material.Ks;
                    color.g += scene.lights[l].color.g * pow(fator_esp, intersect.material.k)*intersect.material.specular.g*intersect.material.Ks;
                    color.b += scene.lights[l].color.b * pow(fator_esp, intersect.material.k)*intersect.material.specular.b*intersect.material.Ks;
                }

                normalizeColor(color);
                image.setPixel( l, c, qRgb( color.r*255, color.g*255, color.b*255) );
            }
            else
            {
                ///Background color
//                image.setPixel( l, c, qRgb(100, 100, 100) );
                image.setPixel( l, c, bg.pixelColor(l, c).rgba());
            }
        }
    }

    QGraphicsScene * graphic = new QGraphicsScene( this );

    graphic->addPixmap( QPixmap::fromImage( image ) );

    ui->graphicsView->setScene(graphic);
}

Vec3 MainWindow::reflects(Vec3 raio, Vec3 norm)
{
    raio.x *= -1.0;
    raio.y *= -1.0;
    raio.z *= -1.0;
    Vec3 reflect = raio - ( norm * (2.0 * Dot(raio,norm) ) );
    reflect.normalize();
    return reflect;
}

void MainWindow::normalizeColor(Color &color)
{
    if( color.r > 1.0 )
        color.r = 1.0;

    if( color.g > 1.0 )
        color.g = 1.0;

    if( color.b > 1.0 )
        color.b = 1.0;

}
