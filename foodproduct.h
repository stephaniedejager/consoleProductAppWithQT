#ifndef FOODPRODUCT_H
#define FOODPRODUCT_H

#include <QDate>
#include <QString>
#include "product.h"
#include "transaction.h"

class FoodProduct: public Product
{
public:
    FoodProduct(QString d, int sc, int n, double p, QDate sbd);
    ~FoodProduct();
    QString toString();
    bool isExpired();

private:
    QDate m_SellByDate;
    int discount;
};

#endif // FOODPRODUCT_H
