#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <Producto.h>
#include <Pelicula.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class cframe;
}
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();
    QVector<Producto> leerProductosDesdeArchivo(const QString& nombreArchivo);
    void guardarProductosEnArchivo(const QString& nombreArchivo, const QVector<Producto>& productos);
    void guardarProductosEnArchivo(const QString& nombreArchivo);
    void crearArchivoBinarioDePrueba();
    void guardarEstadisticasEnArchivo(const QString& archivo, double promedioCalificaciones, const QMap<int, int>& peliculasPorAno);

private slots:
    void on_pushButton_4_clicked();

    void on_generar_reporte_clicked();

    void on_botonActualizar_clicked();

    void on_botonCargarProductos_2_clicked();

    void on_botonCargarProductos_clicked();

    void on_botonGenerar3_clicked();

    void on_botonCargarArchivo_clicked();

    void on_botonEstadisticas_clicked();

private:
    Ui::cframe *ui;
    QVector<Producto> listaProductos;
    QVector<Pelicula> peliculas;
};
#endif // CFRAME_H
