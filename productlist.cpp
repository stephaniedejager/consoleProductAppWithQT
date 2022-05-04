#include "productlist.h"
#include "product.h"
#include "foodproduct.h"

//Constructor
ProductList::ProductList()
{

}

//Destructor
ProductList::~ProductList()
{
    deleteAll();
    clear();
}

//Calculates and return product code
int ProductList::productCodeCalc(int sc)
{
    int i = 1;
    int productCode = sc*1000 + i;
    while(codeUsed(productCode))
    {
        productCode++;
    }

    return productCode;
}

//Adds a pointer to an already constructed instance of a product to the list
//Call product code calculation function and sets product code
int ProductList::add(Product* p)
{
    append(p);
    int supplierCode = p->getSupplierCode();

    int productCode = productCodeCalc(supplierCode);

    p->setProductCode(productCode);

    return productCode;

}

//Adds a pointer to an already constructed instance of a food product to the list
//Call product code calculation function and sets product code
int ProductList::add(FoodProduct* fp)
{
    append(fp);
    int supplierCode = fp->getSupplierCode();

    int productCode = productCodeCalc(supplierCode);

    fp->setProductCode(productCode);

    return productCode;

}


//Reduces quantity items of specific product (per product code) with quantity sold
void ProductList::sell(int pc, int n)
{
    for(int i = 0; i < size(); ++i) {
       if(at(i)->getProductCode() == pc)
       {
          at(i)->sell(n);
          break;
       }
    }
}

//Removes all items from specific product (per product code)
void ProductList::remove(int pc)
{
    for(int i = 0; i < size(); ++i) {
       if(at(i)->getProductCode() == pc)
       {
          at(i)->removeAll();
          break;
       }
    }
}

//Deletes all pointers in list
void ProductList::deleteAll()
{
    while(!isEmpty())
        delete takeFirst();
}

//Checks if a product code was already created
bool ProductList::codeUsed(int pc)
{
    bool usedTest = false;

    for(int i = 0; i < size(); ++i) {
       if(at(i)->getProductCode() == pc)
       {
          usedTest = true;
          break;
       }
    }

    return usedTest;
}

//Private constructor - avoids copy problem
ProductList::ProductList(const ProductList&) : QList<Product*>()
{

}

//Private copy assignment operator avoids copy problem
ProductList& ProductList::operator=(const ProductList&)
{
    return *this;
}
