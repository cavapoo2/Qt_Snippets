#include "tictactoewidget.h"
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>

void TicTacToeWidget::handleButtonClick(int index)
{
    if(index < 0 || index > board.size()) return;
    QPushButton *button = board.at(index);
    if(button->text() != " ") return;
    button->setText(currentPlayer() == Player1 ? "X" : "O");
    Player winner = checkWinCondition(index/3, index % 3);
    if(winner == Invalid) {
        setCurrentPlayer(currentPlayer() == Player1 ? Player2 : Player1);
        return;
    }else {
        emit gameOver(winner);
    }
}

bool TicTacToeWidget::rowWin(int row) {
    QString first = board.at(row*3)->text();
    for(int i=1; i <= 2; i++) {
        QString next = board.at(row*3+i)->text();
        if (next.compare(first) != 0)return false;
    }
    return true;

}
bool TicTacToeWidget::colWin(int col) {
    QString first = board.at(col)->text();
    for(int i=1; i <= 2; i++) {
        QString next = board.at((i*3)+col)->text();
        if (next.compare(first) != 0)return false;
    }
    return true;
}

bool TicTacToeWidget::diagWin(int row,int col){
    //just check both diags
    QString first = board.at(row*3+col)->text();
    QString centre = board.at(1*3 + 1)->text();
    if (first.compare(centre) != 0) return false;
    //test the corners
    for(int r=0; r <=2; r+=2){
        for(int c=0;c <=2; c+=2) {
            QString current = board.at(r*3+c)->text();
            if(first.compare(current)!= 0) return false;
        }
    }
    return true;
}

TicTacToeWidget::Player TicTacToeWidget::checkWinCondition(int row, int col) {
    if(colWin(col) && rowWin(row) && diagWin(row,col))
        return currentPlayer();
    else return Invalid;

}

TicTacToeWidget::TicTacToeWidget(QWidget *parent)
    : QWidget(parent)
{
    setupBoard();
}



TicTacToeWidget::~TicTacToeWidget()
{

}

void TicTacToeWidget::initNewGame()
{
    for(int i=0; i <9; ++i)board.at(i)->setText(" ");
}

void TicTacToeWidget::setCurrentPlayer(TicTacToeWidget::Player p)
{
    if(m_currentPlayer == p ) return;
    m_currentPlayer = p;
    emit currentPlayerChanged(p);
}

void TicTacToeWidget::setupBoard()
{
    QGridLayout* gridLayout = new QGridLayout;
    QSignalMapper* mapper = new QSignalMapper(this);
    for(int row =0; row < 3; ++row) {
        for (int column=0; column < 3; ++column) {
            QPushButton* button = new QPushButton;
            button->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
            button->setText(" ");
            gridLayout->addWidget(button,row,column);
            board.append(button);
            mapper->setMapping(button,board.count()-1);
            connect(button,SIGNAL(clicked()),mapper,SLOT(map()));
        }
    }
    connect(mapper,SIGNAL(mapped(int)),this,SLOT(handleButtonClick(int)));
    setLayout(gridLayout);
}
