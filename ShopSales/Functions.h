#pragma once

#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>

// Stuctures
struct Customer
{
	struct
	{
		int customerID;
		int productID;
		std::string productName;
		int productCost;
		int orderNum[4];
	} val;
	Customer* next;
};

struct Sublist
{
	int customerID;
	Sublist* next;
};

struct Product
{
	struct
	{
		int productID;
		Sublist* sub_head;
		int orderNum[4];
		int totalCost;
	} val;
	Product* next;
};

// Global variables
extern Customer* cust_head;
extern Product* prod_head;

// Functions
void customer_create(std::ifstream& in, Customer* chead);

void customer_print(std::ofstream& out, Customer* head);

int customer_find_node(int ID);

void customer_delete_node(int ID);

void customer_insert_node(std::ifstream& in);

void destroy(Customer* head);

void console_input(Customer* temp);

void product_create(Customer* chead, Product* phead);

void product_print(std::ofstream& out, Product* head);