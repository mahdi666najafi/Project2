#include "mainwindow403.h"
#include "./ui_mainwindow403.h"

MainWindow403::MainWindow403(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow403)
{
    ui->setupUi(this);
    winnerLabel = ui->winnerLabel;
    winnerLabel->setVisible(false);
    connect(ui->player1Line, &QLineEdit::textChanged, this, &MainWindow403::checkNames);
    connect(ui->player2Line, &QLineEdit::textChanged, this, &MainWindow403::checkNames);
    currentPlayer = 1;
    connect(ui->Btn1, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn2, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn3, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn4, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn5, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn6, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn7, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn8, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn9, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn10, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn11, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn12, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn13, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn14, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn15, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn16, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn17, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn18, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn19, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn20, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn21, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn22, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn23, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn24, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->Btn25, &QPushButton::clicked, this, &MainWindow403::handleButtonClick);
    connect(ui->resetBtn, &QPushButton::clicked, this, &MainWindow403::resetGame);
    connect(ui->startBtn, &QPushButton::clicked, this, &MainWindow403::activateButtons);
    ui->player1Line->setFocus();
}

void MainWindow403::checkNames() {
    QString player1 = ui->player1Line->text();
    QString player2 = ui->player2Line->text();

    if (player1.isEmpty() || player2.isEmpty()) {
        ui->startBtn->setEnabled(false);
        ui->resetBtn->setEnabled(false);
        return;
    }

    if (player1 == player2) {
        ui->startBtn->setEnabled(false);
        ui->resetBtn->setEnabled(false);
        return;
    }

    ui->startBtn->setEnabled(true);
    ui->resetBtn->setEnabled(true);
}

void MainWindow403::activateButtons() {
    QList<QPushButton*> buttons = {
        ui->Btn1, ui->Btn2, ui->Btn3, ui->Btn4, ui->Btn5,
        ui->Btn6, ui->Btn7, ui->Btn8, ui->Btn9, ui->Btn10,
        ui->Btn11, ui->Btn12, ui->Btn13, ui->Btn14, ui->Btn15,
        ui->Btn16, ui->Btn17, ui->Btn18, ui->Btn19, ui->Btn20,
        ui->Btn21, ui->Btn22, ui->Btn23, ui->Btn24, ui->Btn25
    };

    for (QPushButton* button : buttons) {
        button->setEnabled(true);
    }
    ui->player1Line->setEnabled(false);
    ui->player2Line->setEnabled(false);
    ui->resetBtn->setEnabled(true);
    ui->startBtn->setEnabled(false);
}


void MainWindow403::handleButtonClick() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button && button->isEnabled()) {
        if (currentPlayer == 1) {
            button->setText("X");
            button->setEnabled(false);
            currentPlayer = 2;
        } else {
            button->setText("O");
            button->setEnabled(false);
            currentPlayer = 1;
        }
        checkWin();
    }
}


void MainWindow403::checkWin() {
    QString board[5][5];
    QList<QPushButton*> buttons = {
        ui->Btn1, ui->Btn2, ui->Btn3, ui->Btn4, ui->Btn5,
        ui->Btn6, ui->Btn7, ui->Btn8, ui->Btn9, ui->Btn10,
        ui->Btn11, ui->Btn12, ui->Btn13, ui->Btn14, ui->Btn15,
        ui->Btn16, ui->Btn17, ui->Btn18, ui->Btn19, ui->Btn20,
        ui->Btn21, ui->Btn22, ui->Btn23, ui->Btn24, ui->Btn25
    };

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            board[i][j] = buttons[i * 5 + j]->text();
        }
    }

    for (int i = 0; i < 5; ++i) {
        if (board[i][0] != "" && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
            announceWinner(board[i][0]);
            return;
        }
    }

    for (int j = 0; j < 5; ++j) {
        if (board[0][j] != "" && board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[3][j] == board[4][j]) {
            announceWinner(board[0][j]);
            return;
        }
    }
    if (board[0][4] != "" && board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
        announceWinner(board[0][4]);
        return;
    }
    if (board[0][0] != "" && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
        announceWinner(board[0][0]);
        return;
    }
    bool isDraw = true;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int value = board[i][j].toInt();
            if (value<=25&&value>=1) {
                isDraw = false;
                break;
            }
        }
    }
    if (isDraw) {
        announceWinner("Draw");
    }
}

void MainWindow403::resetGame() {
    QList<QPushButton*> buttons = {
        ui->Btn1, ui->Btn2, ui->Btn3, ui->Btn4, ui->Btn5,
        ui->Btn6, ui->Btn7, ui->Btn8, ui->Btn9, ui->Btn10,
        ui->Btn11, ui->Btn12, ui->Btn13, ui->Btn14, ui->Btn15,
        ui->Btn16, ui->Btn17, ui->Btn18, ui->Btn19, ui->Btn20,
        ui->Btn21, ui->Btn22, ui->Btn23, ui->Btn24, ui->Btn25
    };
    int i=1;
    for (QPushButton* button : buttons) {
        button->setText(QString::number(i++));
        button->setEnabled(false);
    }
    winnerLabel->setVisible(false);

    currentPlayer = 1;

    ui->resetBtn->setEnabled(false);
    ui->startBtn->setEnabled(true);
}

void MainWindow403::announceWinner(const QString& winner) {
    if (winner == "Draw") {
        winnerLabel->setText("It's a draw!");
        QList<QPushButton*> buttons = {
            ui->Btn1, ui->Btn2, ui->Btn3, ui->Btn4, ui->Btn5,
            ui->Btn6, ui->Btn7, ui->Btn8, ui->Btn9, ui->Btn10,
            ui->Btn11, ui->Btn12, ui->Btn13, ui->Btn14, ui->Btn15,
            ui->Btn16, ui->Btn17, ui->Btn18, ui->Btn19, ui->Btn20,
            ui->Btn21, ui->Btn22, ui->Btn23, ui->Btn24, ui->Btn25
        };

        for (QPushButton* button : buttons) {
            button->setEnabled(false);
        }
    } else {
        QString winnerName = (winner == "X") ?"Player1" :"Player2";
        winnerLabel->setText("Winner: " + winnerName);
        QList<QPushButton*> buttons = {
            ui->Btn1, ui->Btn2, ui->Btn3, ui->Btn4, ui->Btn5,
            ui->Btn6, ui->Btn7, ui->Btn8, ui->Btn9, ui->Btn10,
            ui->Btn11, ui->Btn12, ui->Btn13, ui->Btn14, ui->Btn15,
            ui->Btn16, ui->Btn17, ui->Btn18, ui->Btn19, ui->Btn20,
            ui->Btn21, ui->Btn22, ui->Btn23, ui->Btn24, ui->Btn25
        };
        for (QPushButton* button : buttons) {
            button->setEnabled(false);
        }
    }

    winnerLabel->setVisible(true);
}
MainWindow403::~MainWindow403() {
    delete ui;
}
