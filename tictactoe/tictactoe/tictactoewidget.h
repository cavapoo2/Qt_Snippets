#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>
class QPushButton;
class TicTacToeWidget : public QWidget
{
    Q_OBJECT
    enum Player {
        Invalid,Player1,Player2,Draw
    };
signals:
    void currentPlayerChanged(Player);
    void gameOver(TicTacToeWidget::Player);
public slots:
    void handleButtonClick(int index);
public:
    TicTacToeWidget(QWidget *parent = 0);
    ~TicTacToeWidget();
    void initNewGame();
    Player currentPlayer() const { return m_currentPlayer;}
    void setCurrentPlayer(Player p);
private:
    QList<QPushButton*> board;
    void setupBoard();
    Player m_currentPlayer;
    bool colWin(int col);
    bool rowWin(int row);
    bool diagWin(int row,int col);
    Player checkWinCondition(int,int);
};

#endif // TICTACTOEWIDGET_H
