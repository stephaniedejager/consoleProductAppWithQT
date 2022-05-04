#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H

#include <QList>
#include "product.h"
#include "foodproduct.h"

class ProductList: public QList<Product*>
{
    public:
        ProductList();
        ~ProductList();
        int add(Product* p);
        int add(FoodProduct* fp);
        int productCodeCalc(int sc);
        void sell(int pc, int n);
        void remove(int pc);
        void deleteAll();

    private:
        ProductList(const ProductList&);
        ProductList& operator=(const ProductList&);
        bool codeUsed(int pc);
};

#endif // PRODUCTLIST_H
