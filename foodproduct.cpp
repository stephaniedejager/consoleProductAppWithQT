#include "foodproduct.h"

//Constructor
FoodProduct::FoodProduct(QString d, int sc, int n, double p, QDate sbd): Product(d, sc, n, p), m_SellByDate(sbd)
{

}

//Destructor
FoodProduct::~FoodProduct()
{

}

//Returns string comprising the names and values of all the data members, formatted in a readable way
QString FoodProduct::toString()
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
            "Sell by Date: " + m_SellByDate.toString() + "\n" +
            "\n" +
            "TRANSACTIONS: " +
            "\n" + "\n" +
            "Transaction Date" + "\t" + "\t" + "Quantity" + "\t" + "\t" + "Price" + "\t" + "\t" + "\n" +
            transaction +
            "\n" +
            "****************************************************************";

    return format;
}

//Checks if food item is expired
bool FoodProduct::isExpired()
{
   return m_SellByDate>QDate::currentDate();
}
