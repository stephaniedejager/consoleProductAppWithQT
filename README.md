# consoleProductAppWithQT

Console Application that covers inheritance 

Consider the following UML diagram modelling the classes for an application that records the
sales of products in a home industries shop:

![image](https://user-images.githubusercontent.com/68548733/166804554-4279230b-c68c-4c28-ae27-e87ac4c77d1e.png)

As you can see from the diagram, there are two kinds of products: normal (non-perishable)
products and (perishable) food products, represented by the Product and FoodProduct
classes respectively. The member functions of these classes are intended to do the following:<br />

-> The constructor takes a description, a supplier code, a number of items, and the price
(and an expiry date, in the case of a food product) as parameters, and initialises the
appropriate data members. <br />
-> sell() decrements the number of items in stock, and adds a transaction recording the
number of items sold, the price and the date of the transaction (namely today's date) to
m_Transactions. <br />
-> getSupplierCode(), setProductCode() and getProductCode() do the obvious. <br />
-> toString() returns a string comprising the names and values of all the data members,
formatted in a readable way. <br />
removeAll() sets the number of items to 0 and records it as a transaction (with a price
of 0). This member function is called when all items of a product are removed from the
shelves (for example, when they are past their sell-by date). <br />
-> isExpired() tests whether the sell-by date is past in the case of food products. For
non-perishable products, isExpired() always returns false. 

The ProductList class is a list of pointers to Products. Its member functions are intended to
do the following: <br />
-> add() takes a pointer to an (already constructed) instance of Product or
FoodProduct, and adds it to the list. It also sets the product code of the product to the
supplier code x 1000 plus the number of products added for this supplier so far. For
example, the first product added for supplier 1 will get the product code 1001, the second
product for the same supplier 1002, and so on. Hint: Use the codeUsed() member
function to make sure that a unique product code is generated for each product. <br />
-> sell() takes a product code and number of items as parameters, searches for the
respective product in the list and calls Product::sell() on it. <br />
-> remove() takes a product code as parameter, searches for the respective product in the
list and calls Product::removeAll() on it. <br />
-> deleteAll() calls delete on all pointers in the list. It is intended to be called at the
end of the client program to prevent memory leaks. <br />
-> codeUsed() takes a product code as parameter and checks whether this code is being
used by some product in the list. 

Implement all these classes, and write a short program to test all the member functions of the
ProductList class. It should add at least 5 products to the list, and handle at least 5 sales.
Submit the code of all the classes that you write, as well as the main program to test the
classes. Submit the output of the test program.
