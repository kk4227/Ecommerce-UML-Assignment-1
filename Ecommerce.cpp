#include <iostream>
#include <vector>
using namespace std;

class Product
{
	int id;
	string product_name;
	float product_price;

public:
	Product(int product_id, string name, float price)
	{
		id = product_id;
		product_name = name;
		product_price = price;
	}

	int get_id()
	{
		return id;
	}

	string get_product_name()
	{
		return product_name;
	}

	float get_product_price()
	{
		return product_price;
	}
};

class Customer
{
	string first_name;
	string last_name;
	float balance;
	vector<Product> shopping_cart;
	vector<Product> owned_products;

public:
	Customer(string f_name, string l_name, float initial_balance)
	{
		first_name = f_name;
		last_name = l_name;
		balance = initial_balance;
	}

	int add_to_cart(Product product)
	{
		shopping_cart.push_back(product);
		return 1;
	}

	int remove_from_cart(int product_id)
	{
		int index = 0;
		int success = 0;
		for (Product product : shopping_cart)
		{
			if (product.get_id() == product_id)
			{
				shopping_cart.erase(shopping_cart.begin() + index);
				success = 1;
			}
			index++;
		}
		return success;
	}

	int add_balance(float balance_to_add)
	{
		balance += balance_to_add;
		return 1;
	}

	int buy_cart()
	{
		float total_cart_value = 0;
		for (Product product : shopping_cart)
		{
			total_cart_value += product.get_product_price();
		}

		if (total_cart_value <= balance)
		{
			for (Product product : shopping_cart)
			{
				owned_products.push_back(product);
			}
			shopping_cart.clear();
			balance -= total_cart_value;
			cout << "Purchase Successful!" << endl;
			return 1;
		}
		else
		{
			cout << "Insufficient balance! Please add Rs. " << (total_cart_value - balance) << " or remove items from cart." << endl;
			return 0;
		}
	}

	void print_shopping_cart()
	{
		cout << "-------------------------------------------------------" << endl;
		cout << "Shopping Cart: " << endl;
		for (Product product : shopping_cart)
		{
			cout << product.get_id() << ". " << product.get_product_name() << " Rs. " << product.get_product_price() << endl;
		}
		cout << "-------------------------------------------------------" << endl;
	}

	void print_owned_products()
	{
		cout << "-------------------------------------------------------" << endl;
		cout << "Owned Products: " << endl;
		for (Product product : owned_products)
		{
			cout << product.get_id() << ". " << product.get_product_name() << " Rs. " << product.get_product_price() << endl;
		}
		cout << "-------------------------------------------------------" << endl;
	}
};

int main()
{
	// Defining Products
	Product ps5(1, "PS5", 40000);
	Product ps5_controller(2, "PS5 Controller", 5000);
	Product spiderman_remastered(3, "Spiderman Remastered", 3000);

	// Defining Customer
	Customer kartik_arora("Kartik", "Arora", 25000);

	// Adding PS5 to cart
	kartik_arora.add_to_cart(ps5);
	// Printing Shopping Cart
	kartik_arora.print_shopping_cart();
	// Trying to Buy PS5
	kartik_arora.buy_cart();
	// Adding 15000 balance
	kartik_arora.add_balance(15000);
	// Trying again to buy PS5
	kartik_arora.buy_cart();
	// Printing Shopping Cart
	kartik_arora.print_shopping_cart();
	// Printing Owned Products
	kartik_arora.print_owned_products();

	// Adding PS5 Controller and Spiderman Remastered to Cart
	kartik_arora.add_to_cart(ps5_controller);
	kartik_arora.add_to_cart(spiderman_remastered);
	// Printing Shopping Cart
	kartik_arora.print_shopping_cart();
	// Trying to Buy products
	kartik_arora.buy_cart();
	// Adding 7000 balance
	kartik_arora.add_balance(8000);
	// Trying Again to buy products
	kartik_arora.buy_cart();
	// Printing Shopping Cart
	kartik_arora.print_shopping_cart();
	// Printing Owned Products
	kartik_arora.print_owned_products();
}