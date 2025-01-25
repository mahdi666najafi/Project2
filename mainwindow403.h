#ifndef MAINWINDOW403_H
#define MAINWINDOW403_H
#include <QMessageBox>
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow403; }
QT_END_NAMESPACE

class MainWindow403 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow403(QWidget *parent = nullptr);
    ~MainWindow403();
private slots:
    void checkNames();
    void handleButtonClick();
    void activateButtons();
private:
    Ui::MainWindow403 *ui;
    int currentPlayer;
    void checkWin();
    void announceWinner(const QString& winner);
    void resetGame();
    QLabel *winnerLabel;
};
#endif // MAINWINDOW403_H
