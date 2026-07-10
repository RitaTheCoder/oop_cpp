#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    int id;
    string name;
    double price;
    int stock;
    int sold;

    void input() {
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, name);

        cout << "Enter Product ID: ";
        cin >> id;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Stock: ";
        cin >> stock;

        sold = 0;
    }

    void display() {
        cout << "\nProduct ID : " << id << endl;
        cout << "Name       : " << name << endl;
        cout << "Price      : " << price << endl;
        cout << "Stock      : " << stock << endl;
        cout << "Sold       : " << sold << endl;
    }
};

class Inventory {
private:
    Product products[100];
    int totalProducts;
    double totalSales;

public:
    Inventory() {
        totalProducts = 0;
        totalSales = 0;
    }

    void addProduct() {
        if (totalProducts >= 100) {
            cout << "Inventory Full!\n";
            return;
        }

        products[totalProducts].input();
        totalProducts++;

        cout << "Product Added Successfully.\n";
    }

    void displayProducts() {
        if (totalProducts == 0) {
            cout << "No Products Available.\n";
            return;
        }

        for (int i = 0; i < totalProducts; i++) {
            cout << "\nProduct " << i + 1 << endl;
            products[i].display();
        }
    }

    void updateStock() {
        int id, qty;

        cout << "Enter Product ID: ";
        cin >> id;

        for (int i = 0; i < totalProducts; i++) {

            if (products[i].id == id) {

                cout << "Enter Quantity to Add: ";
                cin >> qty;

                products[i].stock += qty;

                cout << "Stock Updated Successfully.\n";
                return;
            }
        }

        cout << "Product Not Found.\n";
    }

    void sellProduct() {
        int id, qty;

        cout << "Enter Product ID: ";
        cin >> id;

        for (int i = 0; i < totalProducts; i++) {

            if (products[i].id == id) {

                cout << "Enter Quantity: ";
                cin >> qty;

                if (qty > products[i].stock) {
                    cout << "Not Enough Stock.\n";
                    return;
                }

                products[i].stock -= qty;
                products[i].sold += qty;

                double bill = qty * products[i].price;
                totalSales += bill;

                cout << "\n------ CUSTOMER BILL ------\n";
                cout << "Product : " << products[i].name << endl;
                cout << "Price   : " << products[i].price << endl;
                cout << "Quantity: " << qty << endl;
                cout << "Total Bill = " << bill << endl;

                return;
            }
        }

        cout << "Product Not Found.\n";
    }

    void showTotalSales() {
        cout << "Total Sales = " << totalSales << endl;
    }

    void bestSellingProduct() {

        if (totalProducts == 0) {
            cout << "No Products Available.\n";
            return;
        }

        int index = 0;

        for (int i = 1; i < totalProducts; i++) {

            if (products[i].sold > products[index].sold)
                index = i;
        }

        cout << "\nBest Selling Product\n";
        products[index].display();
    }
};

int main() {

    Inventory shop;

    int choice;

    do {

        cout << "\n========== INVENTORY & BILLING ==========\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Update Stock\n";
        cout << "4. Sell Product\n";
        cout << "5. Total Sales\n";
        cout << "6. Best Selling Product\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            shop.addProduct();
            break;

        case 2:
            shop.displayProducts();
            break;

        case 3:
            shop.updateStock();
            break;

        case 4:
            shop.sellProduct();
            break;

        case 5:
            shop.showTotalSales();
            break;

        case 6:
            shop.bestSellingProduct();
            break;

        case 7:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while(choice != 7);

    return 0;
}
