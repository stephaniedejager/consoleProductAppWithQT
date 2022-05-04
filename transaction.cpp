#include "transaction.h"

#include <QString>

//Constructor
Transaction::Transaction(QString d, QDate cd, int n, double p): m_Description(d), m_TransactionDate(cd), m_NoOfItems(n), m_PricePerItem(p)
{
}

//Returns string of all transactions related to product
QString Transaction::toString()
{
    QString format;

    format.append(m_TransactionDate.toString() + QStringLiteral("\t") + QStringLiteral("\t") + QStringLiteral("\t") +
                  QString::number(m_NoOfItems) + QStringLiteral("\t") + QStringLiteral("\t") + QStringLiteral("\t") +
                  QString::number(m_PricePerItem) + QStringLiteral("\t") + QStringLiteral("\t") + QStringLiteral("\t"));

    return format;
}
