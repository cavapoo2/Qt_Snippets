#include <QString>
#include <QtTest>
#include <QCoreApplication>

class Usecases_check_available_groceries : public QObject
{
    Q_OBJECT

public:
    Usecases_check_available_groceries();

private Q_SLOTS:
    void one_or_more_grocery_items_available();
};

Usecases_check_available_groceries::Usecases_check_available_groceries()
{
}

void Usecases_check_available_groceries::one_or_more_grocery_items_available()
{
    QVERIFY2(true, "Failure");
}

QTEST_MAIN(Usecases_check_available_groceries)

#include "tst_check_available_groceries.moc"
