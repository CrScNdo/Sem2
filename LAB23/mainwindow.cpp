#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>
#include <QMap>
#include <QPair>
#include <QDebug>
#include <climits>

struct Node {
    int id;
    QPointF position;
};

struct Edge {
    int from;
    int to;
    int weight;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    drawGraph();
    solveTSP();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawGraph()
{
    QMap<int, Node> nodes = {
                             {1, {1, {300, 300}}},
                             {2, {2, {200, 100}}},
                             {3, {3, {400, 250}}},
                             {4, {4, {100, 250}}},
                             {5, {5, {350, 100}}},
                             {6, {6, {150, 400}}},
                             };

    QList<Edge> edges = {
        {1, 3, 13}, {3, 1, 13}, {1, 4, 15}, {4, 1, 15}, {1, 6, 18}, {6, 1, 18},
        {2, 1, 28}, {1, 2, 28}, {2, 4, 20}, {4, 2, 20}, {2, 5, 21}, {5, 2, 21},
        {3, 5, 30}, {5, 3, 30}, {4, 6, 31}, {6, 4, 31}, {4, 5, 28}, {5, 4, 28},
        {2, 3, 99}, {3, 2, 99}, {2, 6, 99}, {6, 2, 99},
        {3, 4, 99}, {4, 3, 99}, {3, 6, 99}, {6, 3, 99},
        {5, 1, 99}, {1, 5, 99}, {5, 6, 99}, {6, 5, 99}
    };

    n = 6;
    costMatrix = QVector<QVector<int>>(n, QVector<int>(n, 999));

    // --- Сделаем фон сцены серым ---
    scene->setBackgroundBrush(QBrush(QColor(240, 240, 240)));

    QPen pen(Qt::black);
    pen.setWidth(2);

    for (const Edge &e : edges) {
        QPointF p1 = nodes[e.from].position;
        QPointF p2 = nodes[e.to].position;
        scene->addLine(QLineF(p1, p2), pen);

        QGraphicsTextItem *text = scene->addText(QString::number(e.weight));
        text->setDefaultTextColor(Qt::black);
        QFont font = text->font();
        font.setBold(true);
        font.setPointSize(10);
        text->setFont(font);
        text->setPos((p1 + p2) / 2 - QPointF(7, 10));

        costMatrix[e.from - 1][e.to - 1] = e.weight;
    }

    // --- Сделаем цветные узлы и контрастный текст ---
    for (const Node &node : nodes) {
        // Узлы с голубым заливкой и черной обводкой
        QBrush brush(QColor(100, 170, 255));
        scene->addEllipse(node.position.x() - 20, node.position.y() - 20, 40, 40, pen, brush);

        // Цифры — белые, жирные и немного смещены, чтобы было лучше видно
        QGraphicsTextItem* idText = scene->addText(QString::number(node.id));
        idText->setDefaultTextColor(Qt::white);
        QFont font = idText->font();
        font.setBold(true);
        font.setPointSize(14);
        idText->setFont(font);
        idText->setPos(node.position.x() - 7, node.position.y() - 15);
    }
}


int MainWindow::tsp(int pos, int visited)
{
    if (visited == (1 << n) - 1)
        return costMatrix[pos][0];  // возвращаем стоимость возврата в стартовую точку

    if (memo[pos][visited] != -1)
        return memo[pos][visited];

    int ans = INT_MAX;
    int bestNext = -1;

    for (int city = 0; city < n; ++city) {
        if (!(visited & (1 << city))) {
            int newAns = costMatrix[pos][city] + tsp(city, visited | (1 << city));
            if (newAns < ans) {
                ans = newAns;
                bestNext = city;
            }
        }
    }

    nextCity[pos][visited] = bestNext;
    return memo[pos][visited] = ans;
}


void MainWindow::solveTSP()
{
    // Основной путь с началом в вершине 1
    memo = QVector<QVector<int>>(n, QVector<int>(1 << n, -1));
    nextCity = QVector<QVector<int>>(n, QVector<int>(1 << n, -1));

    int result = tsp(0, 1);
    qDebug() << "====== Путь от вершины 1 ======";
    qDebug() << "Минимальная стоимость пути:" << result;
    printPathFrom(0);

    // Пути от остальных вершин
    qDebug() << "\n====== Пути от остальных вершин ======";
    for (int start = 1; start < n; ++start) {
        memo = QVector<QVector<int>>(n, QVector<int>(1 << n, -1));
        nextCity = QVector<QVector<int>>(n, QVector<int>(1 << n, -1));

        int result = tsp(start, 1 << start);
        qDebug() << "Начало в вершине" << start + 1 << ":";
        qDebug() << "Минимальная стоимость пути:" << result;
        printPathFrom(start);
        qDebug() << "";
    }
}


void MainWindow::printPath()
{
    int visited = 1; // стартуем с узла 0
    int pos = 0;

    QString path = QString::number(pos + 1); // узлы нумеруются с 1
    while (true) {
        int nxt = nextCity[pos][visited];
        if (nxt == -1)
            break;
        path += "->" + QString::number(nxt + 1);
        visited |= (1 << nxt);
        pos = nxt;
    }
    qDebug() << "Минимальный путь коммивояжёра:" << path;
}

void MainWindow::printPathFrom(int start)
{
    int visited = (1 << start);
    int pos = start;

    QString path = QString::number(pos + 1);
    while (true) {
        int nxt = nextCity[pos][visited];
        if (nxt == -1)
            break;
        path += "->" + QString::number(nxt + 1);
        visited |= (1 << nxt);
        pos = nxt;
    }
    qDebug() << "Путь:" << path;
}
