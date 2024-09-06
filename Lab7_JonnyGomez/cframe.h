#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>

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

private slots:
    void on_pushButton_4_clicked();

    void on_generar_reporte_clicked();

private:
    Ui::cframe *ui;
};
#endif // CFRAME_H
