#include "pch.h"
#include "Functions.h"

// Global variables
const int QUARTER = 4;

//Header of the list
Customer* cust_head = NULL;
Product* prod_head = NULL;
Sublist* sub_head = NULL;

void cust_create(std::ifstream& in)
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
			if (cust_head == NULL)
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
			if (cust_head == NULL)
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

void prod_create()
{
	int sum = 0;
	int quartersum[QUARTER] = { 0, 0, 0, 0 };

	Customer* ctemp = cust_head;
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

			Sublist* stemp = new Sublist;
			if (stemp == NULL)
			{
				return;
			}

			// Sublist initialization
			stemp->customerID = ctemp->val.customerID;
			stemp->next = NULL;

			if (sub_head == NULL)
			{
				sub_head = stemp;
			}
			else
			{
				Sublist* strav = sub_head;

				while (strav->next != NULL)
				{
					strav = strav->next;
				}
				strav->next = stemp;
			}

			ptemp->val.sub_head = sub_head;
			sub_head = NULL;

			ptemp->next = NULL;

			if (prod_head == NULL)
			{
				prod_head = ptemp;
			}
			else
			{
				Product* trav = prod_head;

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

			Sublist* stemp = new Sublist;
			if (stemp == NULL)
			{
				return;
			}

			// Sublist initialization
			stemp->customerID = ctemp->val.customerID;
			stemp->next = NULL;

			if (sub_head == NULL)
			{
				sub_head = stemp;
			}
			else
			{
				Sublist* strav = sub_head;

				while (strav->next != NULL)
				{
					strav = strav->next;
				}
				strav->next = stemp;
			}
		}

		ctemp = ctemp->next;
	}
}

int find_node(int ID)
{
	int key = 1;

	Customer* current = cust_head;

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

void delete_node(int ID)
{
	Customer* temp = cust_head;
	Customer* previous = cust_head;

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

void insert_node(std::ifstream& in)
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
			temp->next = cust_head;
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
		temp->next = cust_head;
		cust_head = temp;
	}
}

void cust_destroy()
{
	Customer* temp = cust_head;

	while (temp != NULL)
	{
		Customer* next = temp->next;
		delete temp;
		temp = next;
	}
}

void prod_destroy()
{
	Product* temp = prod_head;

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

void cust_print(std::ofstream& out)
{
	//  Where to print a list
	std::cout << "Where should I print a list? (f/c) ";
	std::string ans;
	std::cin >> ans;

	if (ans == "f")
	{
		int i = 0;
		Customer* trav = cust_head;
		while (trav != NULL)
		{

			out << "\n*****CUSTOMER NODE " << i + 1 << " *****" << std::endl;
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
		Customer* trav = cust_head;
		while (trav != NULL)
		{

			std::cout << "\n*****CUSTOMER NODE " << i + 1 << " *****" << std::endl;
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

void prod_print(std::ofstream& out)
{
	//  Where to print a list
	std::cout << "Where should I print a list? (f/c) ";
	std::string ans;
	std::cin >> ans;

	if (ans == "f")
	{
		int i = 0;
		Product* trav = prod_head;
		while (trav != NULL)
		{

			out << "\n*****PRODUCT NODE " << i + 1 << " *****" << std::endl;
			out << "Product ID: " << trav->val.productID << std::endl;
			out << "Total cost: " << trav->val.totalCost << std::endl;

			for (int i = 0; i < QUARTER; i++)
			{
				out << "Number of orders in (" << i + 1 << ") quater: "
					<< trav->val.orderNum[i] << std::endl;
			}

			int j = 0;
			Sublist* strav = trav->val.sub_head;
			out << "Customers: ";
			while (strav != NULL)
			{
				out << strav->customerID << " ";

				strav = strav->next;
				j++;
			}

			trav = trav->next;
			i++;
		}
	}
	else
	{
		int i = 0;
		Product* trav = prod_head;
		while (trav != NULL)
		{

			std::cout << "\n*****PRODUCT NODE " << i + 1 << " *****" << std::endl;
			std::cout << "Product ID: " << trav->val.productID << std::endl;
			std::cout << "Total cost: " << trav->val.totalCost << std::endl;

			for (int i = 0; i < QUARTER; i++)
			{
				std::cout << "Number of orders in (" << i + 1 << ") quater: "
					<< trav->val.orderNum[i] << std::endl;
			}

			int j = 0;
			Sublist* strav = trav->val.sub_head;
			std::cout << "Customers: ";
			while (strav != NULL)
			{
				std::cout << strav->customerID << " ";

				strav = strav->next;
				j++;
			}

			trav = trav->next;
			i++;
		}
	}
}

int find_max()
{
	std::cout << "\nInput product ID: ";
	int prodID;
	std::cin >> prodID;

	int max; 
	int top_quarter;

	Product* trav = prod_head;

	while (trav->val.productID != NULL)
	{
		if (trav->val.productID == prodID)
		{
			max = trav->val.orderNum[0];
			for (int i = 0; i < QUARTER; i++)
			{
				if (trav->val.orderNum[i] > max)
				{
					max = trav->val.orderNum[i];

					top_quarter = i;
				}
			}
			break;
		}
		else
		{
			trav = trav->next;
		}
	}

	std::cout << "In the " << top_quarter << " quarter were " << max << " orders." << std::endl;

	return max;
}