#include "product.h"

#include <QString>
#include <QDebug>

//Constructor
Product::Product(QString d, int sc, int n, double p): m_Description(d), m_SupplierCode(sc), m_NoOfItems(n), m_PricePerItem(p)
{
    m_DateSupplied = QDate::currentDate();
}

//Destructor
Product::~Product()
{

}

//Reduces quantity of product with amount sold
//Records transaction
void Product::sell(int n)
{
    if(m_NoOfItems < n)
    {
        qDebug() << "Not enough items in stock.";
    }
    else
    {
        m_NoOfItems -= n;
        m_Transactions.append(Transaction("Sale", QDate::currentDate(), n, m_PricePerItem));
    }

}

//Return supplier code
int Product::getSupplierCode()
{
    return m_SupplierCode;
}

//Set product code
void Product::setProductCode(int pc)
{
    m_ProductCode = pc;
}

//Return product code
int Product::getProductCode()
{
    return m_ProductCode;
}

//Returns string comprising the names and values of all the data members, formatted in a readable way
QString Product::toString()
{
    QString format, transaction;

    foreach (Transaction i, m_Transactions){
        transaction.append(i.toString() + "\n");
    }

    format = "Description: " + m_Description + "\n" +
            "Supplier Code: " + QString::number(m_SupplierCode) + "\n" +
            "No of Items: " + QString::number(m_NoOfItems) + "\n" +
            "Date Supplied: " + m_DateSupplied.toString() + "\n" +
            "Price per item: " + QString::number(m_PricePerItem) + "\n" +
            "Product Code: " + QString::number(m_ProductCode) + "\n" +
            "\n" +
            "TRANSACTIONS: " +
            "\n" + "\n" +
            "Transaction Date" + "\t" + "\t" + "Quantity" + "\t" + "\t" + "Price" + "\t" + "\t" + "\n" +
            transaction +
            "\n" +
            "****************************************************************";

    return format;

}

//Removes all items of product
//Records transaction
void Product::removeAll()
{
    m_NoOfItems = 0;
    m_PricePerItem = 0;
    m_Transactions.append(Transaction("Remove all products", QDate::currentDate(), m_NoOfItems, m_PricePerItem));

}

bool Product::isExpired()
{
    return false;
}
