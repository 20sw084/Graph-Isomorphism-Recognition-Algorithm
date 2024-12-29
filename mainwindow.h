#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addEdgeGraph1Button_clicked();
    void on_addEdgeGraph2Button_clicked();
    void on_checkIsomorphismButton_clicked();
    void on_generateGraph1Button_clicked();
    void on_generateGraph2Button_clicked();
    void on_saveGraph1Button_clicked();
    void on_saveGraph2Button_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *sceneGraph1;
    QGraphicsScene *sceneGraph2;

    int verticesGraph1;
    int verticesGraph2;

    std::vector<std::vector<int>> adjMatrixGraph1;
    std::vector<std::vector<int>> adjMatrixGraph2;

    void drawGraph(QGraphicsScene *scene, const std::vector<std::vector<int>> &adjMatrix, int vertices);
    bool areIsomorphic(const std::vector<std::vector<int>> &graph1, const std::vector<std::vector<int>> &graph2);
    void saveGraphImage(QGraphicsScene *scene, const QString &filename);
};

#endif // MAINWINDOW_H
