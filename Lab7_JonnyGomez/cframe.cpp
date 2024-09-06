#include "cframe.h"
#include "ui_cframe.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);
}

cframe::~cframe()
{
    delete ui;
}

void cframe::on_pushButton_4_clicked()
{
    QCoreApplication::quit();
}


void cframe::on_generar_reporte_clicked()
{
    QString inputFilePath = "C:\\Users\\aleja\\Documents\\GitHub\\Lab7_6_JonnyGomez\\Lab7_JonnyGomez\\estudiantes.txt";
    QString outputFilePath = "C:\\Users\\aleja\\Documents\\GitHub\\Lab7_6_JonnyGomez\\Lab7_JonnyGomez\\reporte.txt";

    QFile inputFile(inputFilePath);
    QFile outputFile(outputFilePath);

    qDebug() << "Intentando abrir el archivo de entrada en:" << inputFilePath;

    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "No se pudo abrir el archivo de entrada:" << inputFilePath;
        return;
    }

    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qCritical() << "No se pudo abrir el archivo de salida:" << outputFilePath;
        return;
    }

    QTextStream in(&inputFile);
    QTextStream out(&outputFile);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        if (fields.size() == 2) {
            QString nombre = fields.at(0).trimmed();
            int nota = fields.at(1).trimmed().toInt();

            QString resultado = (nota >= 60) ? "Aprobado" : "Reprobado";
            out << nombre << ": " << resultado << "\n";

        }
    }

    inputFile.close();
    outputFile.close();

    QMessageBox::information(this, "Reporte creado.", "Puede abrir el archivo en la ruta de este proyecto.");
}

