#include <QCoreApplication>

#include "product.h"
#include "foodproduct.h"
#include "productlist.h"
#include <QDebug>
#include <QTextStream>
#include <QString>

QTextStream cout(stdout);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //ProductList instance
    ProductList pl;

    //Product and Food Product instances
    Product one("Vase", 5487, 6, 155.99);
    FoodProduct two("Banana", 2576, 14, 3.50, QDate(2021, 8, 14));
    Product three("Wine glass set", 1256, 23, 150);
    Product four("Platter board", 564, 7, 250);
    FoodProduct five("Beef Lasagna 500g", 2693, 24, 125.50, QDate(2021, 8, 8));
    FoodProduct six("Cottage Pie 500g", 2693, 15, 125.50, QDate(2021, 8, 6));

    //Product and Food Product instances added to product list
    pl.add(&one);
    pl.add(&two);
    pl.add(&three);
    pl.add(&four);
    pl.add(&five);
    pl.add(&six);

    QString toPrintOne, toPrintTwo, toPrintThree, toPrintFour, toPrintFive, toPrintSix;

    toPrintOne = one.toString();
    toPrintTwo = two.toString();
    toPrintThree = three.toString();
    toPrintFour = four.toString();
    toPrintFive = five.toString();
    toPrintSix = six.toString();

    cout << "**************************************************************************" << endl;
    cout << "Testing of functions" << endl;
    cout << "**************************************************************************" << '\n' << endl;
    cout << "Check product codes are correctly calculated"  << endl;
    cout << "Product 5 and 6 from the same supplier" << '\n' << endl;

    //Prints all products and food products before transactions
    cout << "________________________________________________________________________" << endl;
    cout << "All products and food products before transactions" << endl;
    cout << "________________________________________________________________________" << '\n' << endl;
    cout << toPrintOne << endl;
    cout << toPrintTwo << endl;
    cout << toPrintThree << endl;
    cout << toPrintFour << endl;
    cout << toPrintFive << endl;
    cout << toPrintSix << endl;

    //Sell 3 items of product one (Product)
    pl.sell(5487001, 3);
    toPrintOne = one.toString();

    cout << '\n' << "________________________________________________________________________" << '\n' << endl;
    cout << "Product 1 (Product) after 3 items have been sold" << endl;
    cout << "________________________________________________________________________" << '\n' << endl;
    cout << toPrintOne << endl;

    //Removes all items of product one
    pl.remove(5487001);
    toPrintOne = one.toString();

    cout << '\n' << "________________________________________________________________________" << '\n' << endl;
    cout << "Product 1 (Product) after all items have been removed (and 3 items sold above)" << endl;
    cout << "________________________________________________________________________" << '\n' << endl;
    cout << toPrintOne << endl;

    //Sell 5 items of product two (Food Product)
    pl.sell(2576001, 5);
    toPrintTwo = two.toString();

    cout << '\n' << "________________________________________________________________________" << '\n' << endl;
    cout << "Product 2 (Food Product) after 5 items have been sold" << endl;
    cout << "________________________________________________________________________" << '\n' << endl;
    cout << toPrintTwo << endl;

    //Sell 7 items of product three (Product)
    pl.sell(1256001, 7);
    toPrintThree = three.toString();

    cout << '\n' << "________________________________________________________________________" << '\n' << endl;
    cout << "Product 3 (Product) after 7 items have been sold" << endl;
    cout << "________________________________________________________________________" << '\n' << endl;
    cout << toPrintThree << endl;

    //Sell and remove no items of product four (Product)
    toPrintFour = four.toString();

    cout << '\n' << "________________________________________________________________________" << '\n' << endl;
    cout << "Product 4 (Product) after no items have been sold" << endl;
    cout << "________________________________________________________________________" << '\n' << endl;
    cout << toPrintFour << endl;

    //Sell 1 item of product five (Food Product)
    pl.sell(2693001, 1);
    toPrintFive = five.toString();

    cout << '\n' << "________________________________________________________________________" << '\n' << endl;
    cout << "Product 5 (Food Product) after 1 item has been sold" << endl;
    cout << "________________________________________________________________________" << '\n' << endl;
    cout << toPrintFive << endl;

    //Sell 8 items of product five (Food Product)
    pl.sell(2693002, 8);
    toPrintSix = six.toString();

    cout << '\n' << "________________________________________________________________________" << '\n' << endl;
    cout << "Product 6 (Food Product) after 8 items have been sold" << endl;
    cout << "________________________________________________________________________" << '\n' << endl;
    cout << toPrintSix << endl;

    //Removes all items of product six
    pl.remove(2693002);
    toPrintSix = six.toString();

    cout << '\n' << "________________________________________________________________________" << '\n' << endl;
    cout << "Product 6 (Food Product) after all items have been removed (and 8 items sold above)" << endl;
    cout << "________________________________________________________________________" << '\n' << endl;
    cout << toPrintSix << endl;

    toPrintOne = one.toString();
    toPrintTwo = two.toString();
    toPrintThree = three.toString();
    toPrintFour = four.toString();
    toPrintFive = five.toString();
    toPrintSix = six.toString();

    //Prints all products and food products after sell and remove transactions
    cout << "________________________________________________________________________" << '\n' << endl;
    cout << "All products and food products after transactions" << endl;
    cout << "________________________________________________________________________" << '\n' << endl;
    cout << toPrintOne << endl;
    cout << toPrintTwo << endl;
    cout << toPrintThree << endl;
    cout << toPrintFour << endl;
    cout << toPrintFive << endl;
    cout << toPrintSix << endl;

    cout << '\n' << '\n' << "**************************************************************************" << endl;
    cout << "END" << endl;
    cout << "**************************************************************************" << endl;

    return a.exec();
}
