#include "pch.h"
#include "Functions.h"

// Global variables
const int QUARTER = 4;

//Header of the list
Customer* cust_head = NULL;
Product* prod_head = NULL;

void customer_create(std::ifstream& in, Customer* chead)
{
	// Initialization method choose
	std::cout << "Choose a method of initialization (f/c) ";
	std::string ans;
	std::cin >> ans;

	if (ans == "f")
	{
		// Counts the number of nodes
		std::string s;
		int number = 0;

		while (getline(in, s))
		{
			number++;
		}

		// Returns a flag to the beginning of the file
		in.clear();
		in.seekg(0, std::ios::beg);

		for (int i = 0; i < number; i++)
		{
			// Declare the space for a pointer item
			Customer* temp = new Customer;
			if (temp == NULL)
			{
				break;
			}

			in >> temp->val.customerID >> temp->val.productID >>
				temp->val.productName >> temp->val.productCost;

			int orderNum[QUARTER];
			for (int i = 0; i < QUARTER; i++)
			{
				in >> temp->val.orderNum[i];
			}

			// Initialize the node's next field
			temp->next = NULL;

			// Check if the list is empty
			// Set temp value to the cust_head of the list
			if (chead == NULL)
			{
				cust_head = temp;
			}
			// Step through the list until it finds the last node
			else
			{
				Customer* trav = cust_head;

				while (trav->next != NULL)
				{
					// Move to next link in chain
					trav = trav->next;
				}
				// Sets the pointer from last node to the node temp
				trav->next = temp;
			}
		}

		in.close();
	}
	else
	{
		bool more = true;
		while (more == true)
		{
			// Declare the space for a pointer item
			Customer* temp = new Customer;
			if (temp == NULL)
			{
				break;
			}

			console_input(temp);

			// Check if the list is empty
			// Set temp value to the cust_head of the list
			if (chead == NULL)
			{
				chead = temp;
			}
			// Step through the list until it finds the last node
			else
			{
				Customer* trav = cust_head;

				while (trav->next != NULL)
				{
					// Move to next link in chain
					trav = trav->next;
				}
				// Sets the pointer from last node to the node temp
				trav->next = temp;
			}

			// Ask to continue input
			std::cout << "More data? (y/n) ";
			std::string ans;
			std::cin >> ans;
			if (ans != "y")
			{
				more = false;
			}
		}
	}
}

void customer_print(std::ofstream& out, Customer* chead)
{
	//  Where to print a list
	std::cout << "Where should I print a list? (f/c) ";
	std::string ans;
	std::cin >> ans;

	if (ans == "f")
	{
		int i = 0;
		Customer* trav = chead;
		while (trav != NULL)
		{

			out << "\n***** NODE " << i + 1 << " *****" << std::endl;
			out << "Customer ID: " << trav->val.customerID << std::endl;
			out << "Product ID: " << trav->val.productID << std::endl;
			out << "Product name: " << trav->val.productName << std::endl;
			out << "Product cost: " << trav->val.productCost << std::endl;

			const int QUARTER = 4;
			for (int i = 0; i < QUARTER; i++)
			{
				out << "Number of orders in (" << i + 1 << ") quater: "
					<< trav->val.orderNum[i] << std::endl;
			}

			trav = trav->next;
			i++;
		}
	}
	else
	{
		int i = 0;
		Customer* trav = chead;
		while (trav != NULL)
		{

			std::cout << "\n***** NODE " << i + 1 << " *****" << std::endl;
			std::cout << "Customer ID: " << trav->val.customerID << std::endl;
			std::cout << "Product ID: " << trav->val.productID << std::endl;
			std::cout << "Product name: " << trav->val.productName << std::endl;
			std::cout << "Product cost: " << trav->val.productCost << std::endl;

			for (int i = 0; i < QUARTER; i++)
			{
				std::cout << "Number of orders in (" << i + 1 << ") quater: "
					<< trav->val.orderNum[i] << std::endl;
			}

			trav = trav->next;
			i++;
		}
	}
}

int customer_find_node(int ID, Customer* chead)
{
	int key = 1;

	Customer* current = chead;

	while (current->val.customerID != NULL)
	{
		if (current->val.customerID == ID)
		{
			std::cout << "Success.";
			break;
		}
		else
		{
			key++;
			current = current->next;
		}
	}
	return key;
}

void customer_delete_node(int ID, Customer* chead)
{
	Customer* temp = chead;
	Customer* previous = chead;

	// If cust_head node itself holds the key to be deleted 
	if (temp != NULL && temp->val.customerID == ID)
	{
		cust_head = temp->next;   // Changed cust_head 
		delete temp;             // free old cust_head 
		return;
	}
	else
	{
		while (temp != NULL || temp->val.customerID != ID)
		{
			if (temp->val.customerID == ID)
			{
				previous->next = temp->next;
				delete temp;
				std::cout << "Deleted." << std::endl;
				break;
			}
			else
			{
				previous = temp;
				temp = temp->next;
			}
		}
	}
}

void customer_insert_node(std::ifstream& in, Customer* chead)
{
	// Initialization method choose
	std::cout << "\nChoose a method of inserting (f/c) ";
	std::string ans;
	std::cin >> ans;

	if (ans == "f")
	{
		// Counts the number of nodes
		std::string s;
		int number = 0;

		while (getline(in, s))
		{
			number++;
		}

		// Returns a flag to the beginning of the file
		in.clear();
		in.seekg(0, std::ios::beg);

		for (int i = 0; i < number; i++)
		{
			// Declare the space for a pointer item
			Customer* temp = new Customer;
			if (temp == NULL)
			{
				break;
			}

			in >> temp->val.customerID >> temp->val.productID >>
				temp->val.productName >> temp->val.productCost;

			int orderNum[QUARTER];
			for (int i = 0; i < QUARTER; i++)
			{
				in >> temp->val.orderNum[i];
			}

			// Initialize the node's next field
			temp->next = NULL;

			// Inserts at the beg of the list
			temp->next = chead;
			cust_head = temp;
		}
	}
	else
	{
		Customer* temp = new Customer;
		if (temp == NULL)
		{
			return;
		}

		console_input(temp);

		// Inserts at the beg of the list
		temp->next = chead;
		cust_head = temp;
	}
}

void destroy(Customer* head)
{
	Customer* temp = head;

	while (temp != NULL)
	{
		Customer* next = temp->next;
		delete temp;
		temp = next;
	}
}

void destroy(Product* head)
{
	Product* temp = head;

	while (temp != NULL)
	{
		Product* next = temp->next;
		delete temp;
		temp = next;
	}
}

void console_input(Customer* temp)
{
	// Initialize the node's val field
	std::cout << "Customer ID: ";
	std::cin >> temp->val.customerID;

	std::cout << "Product ID: ";
	std::cin >> temp->val.productID;

	std::cout << "Product name: ";
	std::cin >> temp->val.productName;

	std::cout << "Product cost: ";
	std::cin >> temp->val.productCost;

	int orderNum[QUARTER];
	for (int i = 0; i < QUARTER; i++)
	{
		std::cout << "Number of orders in (" << i + 1 << ") quater: ";
		std::cin >> temp->val.orderNum[i];
	}

	// Initialize the node's next field
	temp->next = NULL;
}

void product_create(Customer* chead, Product* phead)
{	
	int sum = 0;
	int quartersum[QUARTER] = {0, 0, 0, 0};

	Customer* ctemp = chead;
	while (ctemp != NULL)
	{
		Product* ptemp = new Product;
		if (ptemp == NULL)
		{
			return;
		}

		if (ctemp->next == NULL || ctemp->val.productID != ctemp->next->val.productID)
		{
			int totalsum = 0;

			for (int i = 0; i < QUARTER; i++)
			{
				totalsum += ctemp->val.orderNum[i];
				quartersum[i] += ctemp->val.orderNum[i];
			}

			sum += totalsum * ctemp->val.productCost;

			ptemp->val.productID = ctemp->val.productID;
			ptemp->val.totalCost = sum;
			sum = 0;
			for (int i = 0; i < QUARTER; i++)
			{
				ptemp->val.orderNum[i] = quartersum[i];
				quartersum[i] = 0;
			}

			ptemp->next = NULL;

			if (phead == NULL)
			{
				phead = ptemp;
			}
			else
			{
				Product* trav = phead;

				while (trav->next != NULL)
				{
					// Move to next link in chain
					trav = trav->next;
				}
				// Sets the pointer from last node to the node temp
				trav->next = ptemp;
			}
		}
		else
		{
			int totalsum = 0;

			for (int i = 0; i < QUARTER; i++)
			{
				totalsum += ctemp->val.orderNum[i];
				quartersum[i] += ctemp->val.orderNum[i];
			}
			
			sum += totalsum * ctemp->val.productCost;
		}

		ctemp = ctemp->next;
	}
}

void product_print(std::ofstream& out, Product* chead)
{
	//  Where to print a list
	std::cout << "Where should I print a list? (f/c) ";
	std::string ans;
	std::cin >> ans;

	if (ans == "f")
	{
		int i = 0;
		Product* trav = chead;
		while (trav != NULL)
		{

			out << "\n***** NODE " << i + 1 << " *****" << std::endl;
			out << "Product ID: " << trav->val.productID << std::endl;
			out << "Total cost: " << trav->val.totalCost << std::endl;

			const int QUARTER = 4;
			for (int i = 0; i < QUARTER; i++)
			{
				out << "Number of orders in (" << i + 1 << ") quater: "
					<< trav->val.orderNum[i] << std::endl;
			}

			trav = trav->next;
			i++;
		}
	}
	else
	{
		int i = 0;
		Product* trav = chead;
		while (trav != NULL)
		{

			std::cout << "\n***** NODE " << i + 1 << " *****" << std::endl;
			std::cout << "Product ID: " << trav->val.productID << std::endl;
			std::cout << "Total cost: " << trav->val.totalCost << std::endl;

			for (int i = 0; i < QUARTER; i++)
			{
				std::cout << "Number of orders in (" << i + 1 << ") quater: "
					<< trav->val.orderNum[i] << std::endl;
			}

			trav = trav->next;
			i++;
		}
	}
}