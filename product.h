#ifndef PRODUCT_H
#define PRODUCT_H

#include <QDate>
#include <QString>
#include <QList>
#include "transaction.h"

class Product
{
    public:
        Product(QString d, int sc, int n, double p);
        virtual ~Product();
        virtual void sell(int n);
        int getSupplierCode();
        void setProductCode(int pc);
        int getProductCode();
        virtual QString toString();
        void removeAll();
        virtual bool isExpired();

    //member variables and function protected, rather than private, in order for derived class to access them
    protected:
        QString m_Description;
        int m_SupplierCode;
        int m_NoOfItems;
        QDate m_DateSupplied;
        double m_PricePerItem;
        int m_ProductCode;
        QList<Transaction> m_Transactions;

};

#endif // PRODUCT_H
