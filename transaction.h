#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include <QString>

class Transaction
{
    public:
        Transaction(QString d, QDate cd, int n, double p);
        QString toString();
    private:
        QString m_Description;
        QDate m_TransactionDate;
        int m_NoOfItems;
        double m_PricePerItem;

};

#endif // TRANSACTION_H
