#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Product {
public:
    int id;
    int quantity;
    float price;
    string Pname;

    Product() {}

    void input() {
        cout << "Enter Product ID: ";
        cin >> id;

        cout << "Enter Product Name: ";
        cin >> Pname;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void display() {
        cout << "\nProduct Name: " << Pname << endl;
        cout << "Product ID: " << id << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }
};


void saveToFile(vector<Product> &inventory)
{
    ofstream file("products.txt");

    for(Product p : inventory)
    {
        file << p.id << " "
             << p.Pname << " "
             << p.price << " "
             << p.quantity << endl;
    }

    file.close();
}

void loadFromFile(vector<Product> &inventory)
{
    ifstream file("products.txt");

    Product p;

    while(file >> p.id >> p.Pname >> p.price >> p.quantity)
    {
        inventory.push_back(p);
    }

    file.close();
}

bool idExists(vector<Product> &inventory, int id)
{
    for(Product p : inventory)
    {
        if(p.id == id)
            return true;
    }
    return false;
}

int main()
{
    vector<Product> inventory;

    loadFromFile(inventory);

    int totalItemsSold = 0;
    float totalRevenue = 0;

    int choice;

    while(true)
    {
        cout << "\n===== Inventory Menu =====\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Delete Product\n";
        cout << "4. Sell Product\n";
        cout << "5. Search Product\n";
        cout << "6. Sales Summary\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            Product p;
            p.input();

            if(idExists(inventory, p.id))
            {
                cout << "Product ID already exists\n";
            }
            else
            {
                inventory.push_back(p);
                cout << "Product added successfully\n";
            }
        }

        else if(choice == 2)
        {
            if(inventory.empty())
            {
                cout << "No products available\n";
            }
            else
            {
                for(Product p : inventory)
                    p.display();
            }
        }

        else if(choice == 3)
        {
            int id;
            cout << "Enter product ID to delete: ";
            cin >> id;

            bool found = false;

            for(int i = 0; i < inventory.size(); i++)
            {
                if(inventory[i].id == id)
                {
                    inventory.erase(inventory.begin() + i);
                    cout << "Product deleted\n";
                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Product not found\n";
        }

        else if(choice == 4)
        {
            int id, qty;

            cout << "Enter Product ID: ";
            cin >> id;

            cout << "Enter quantity to sell: ";
            cin >> qty;

            bool found = false;

            for(int i = 0; i < inventory.size(); i++)
            {
                if(inventory[i].id == id)
                {
                    found = true;

                    if(inventory[i].quantity >= qty)
                    {
                        inventory[i].quantity -= qty;

                        totalItemsSold += qty;
                        totalRevenue += qty * inventory[i].price;

                        cout << "Sale successful\n";
                        cout << "Remaining stock: "
                             << inventory[i].quantity << endl;

                        // record sale in sales.txt
                        ofstream saleFile("sales.txt", ios::app);

                        saleFile << inventory[i].id << " "
                                 << inventory[i].Pname << " "
                                 << qty << " "
                                 << qty * inventory[i].price << endl;

                        saleFile.close();

                        // low stock alert
                        if(inventory[i].quantity < 5)
                        {
                            cout << "Low stock alert for "
                                 << inventory[i].Pname << endl;
                        }
                    }
                    else
                    {
                        cout << "Not enough stock\n";
                    }

                    break;
                }
            }

            if(!found)
                cout << "Product not found\n";
        }

        else if(choice == 5)
        {
            int id;
            cout << "Enter product ID to search: ";
            cin >> id;

            bool found = false;

            for(Product p : inventory)
            {
                if(p.id == id)
                {
                    p.display();
                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Product not found\n";
        }

        else if(choice == 6)
        {
            cout << "\nTotal Items Sold: " << totalItemsSold << endl;
            cout << "Total Revenue: " << totalRevenue << endl;
        }

        else if(choice == 7)
        {
            saveToFile(inventory);
            cout << "Inventory saved. Exiting...\n";
            break;
        }

        else
        {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}