#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QMessageBox>
#include <QFileDialog>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), verticesGraph1(0), verticesGraph2(0) {
    ui->setupUi(this);

    // Initialize scenes for graph rendering
    sceneGraph1 = new QGraphicsScene(this);
    sceneGraph2 = new QGraphicsScene(this);

    ui->graphicsViewGraph1->setScene(sceneGraph1);
    ui->graphicsViewGraph2->setScene(sceneGraph2);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addEdgeGraph1Button_clicked() {
    int u = ui->spinBoxGraph1U->value();
    int v = ui->spinBoxGraph1V->value();

    if (u >= verticesGraph1 || v >= verticesGraph1) {
        QMessageBox::warning(this, "Error", "Invalid vertices for Graph 1!");
        return;
    }

    adjMatrixGraph1[u][v] = 1;
    adjMatrixGraph1[v][u] = 1;
    drawGraph(sceneGraph1, adjMatrixGraph1, verticesGraph1);
}

void MainWindow::on_addEdgeGraph2Button_clicked() {
    int u = ui->spinBoxGraph2U->value();
    int v = ui->spinBoxGraph2V->value();

    if (u >= verticesGraph2 || v >= verticesGraph2) {
        QMessageBox::warning(this, "Error", "Invalid vertices for Graph 2!");
        return;
    }

    adjMatrixGraph2[u][v] = 1;
    adjMatrixGraph2[v][u] = 1;
    drawGraph(sceneGraph2, adjMatrixGraph2, verticesGraph2);
}

void MainWindow::on_generateGraph1Button_clicked() {
    verticesGraph1 = ui->spinBoxVerticesGraph1->value();
    adjMatrixGraph1.assign(verticesGraph1, std::vector<int>(verticesGraph1, 0));
    drawGraph(sceneGraph1, adjMatrixGraph1, verticesGraph1);
}

void MainWindow::on_generateGraph2Button_clicked() {
    verticesGraph2 = ui->spinBoxVerticesGraph2->value();
    adjMatrixGraph2.assign(verticesGraph2, std::vector<int>(verticesGraph2, 0));
    drawGraph(sceneGraph2, adjMatrixGraph2, verticesGraph2);
}

void MainWindow::on_checkIsomorphismButton_clicked() {
    if (verticesGraph1 != verticesGraph2) {
        QMessageBox::information(this, "Isomorphism", "Graphs are not isomorphic!");
        return;
    }

    if (areIsomorphic(adjMatrixGraph1, adjMatrixGraph2)) {
        QMessageBox::information(this, "Isomorphism", "Graphs are isomorphic!");
    } else {
        QMessageBox::information(this, "Isomorphism", "Graphs are not isomorphic!");
    }
}

void MainWindow::on_saveGraph1Button_clicked() {
    QString filename = QFileDialog::getSaveFileName(this, "Save Graph 1", "", "PNG Files (*.png)");
    if (!filename.isEmpty()) {
        saveGraphImage(sceneGraph1, filename);
    }
}

void MainWindow::on_saveGraph2Button_clicked() {
    QString filename = QFileDialog::getSaveFileName(this, "Save Graph 2", "", "PNG Files (*.png)");
    if (!filename.isEmpty()) {
        saveGraphImage(sceneGraph2, filename);
    }
}

void MainWindow::drawGraph(QGraphicsScene *scene, const std::vector<std::vector<int>> &adjMatrix, int vertices) {
    scene->clear();
    scene->setBackgroundBrush(QColor(138, 134, 197)); // Set the background color

    int radius = 150;
    int centerX = 200;
    int centerY = 200;
    double angleStep = 360.0 / vertices;

    std::vector<QPointF> points(vertices);
    for (int i = 0; i < vertices; i++) {
        double angle = angleStep * i;
        double x = centerX + radius * cos(angle * M_PI / 180.0);
        double y = centerY + radius * sin(angle * M_PI / 180.0);
        points[i] = QPointF(x, y);
        scene->addEllipse(x - 10, y - 10, 20, 20, QPen(Qt::black), QBrush(Qt::blue));
        scene->addText(QString::number(i))->setPos(x - 5, y - 5);
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            if (adjMatrix[i][j]) {
                scene->addLine(QLineF(points[i], points[j]), QPen(Qt::black));
            }
        }
    }
}

bool MainWindow::areIsomorphic(const std::vector<std::vector<int>> &graph1, const std::vector<std::vector<int>> &graph2) {
    int n = graph1.size();
    std::vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;

    do {
        bool isIsomorphic = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph1[i][j] != graph2[perm[i]][perm[j]]) {
                    isIsomorphic = false;
                    break;
                }
            }
            if (!isIsomorphic) break;
        }

        if (isIsomorphic) return true;

    } while (std::next_permutation(perm.begin(), perm.end()));

    return false;
}

void MainWindow::saveGraphImage(QGraphicsScene *scene, const QString &filename) {
    QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
    image.fill(Qt::white);

    QPainter painter(&image);
    scene->render(&painter);
    image.save(filename);
}
