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

// Functions' cust_headers 
void create_list(std::ifstream& in);

void print_list(std::ofstream& out, Customer* head);

int find_node(int ID);

void delete_node(int ID);

void insert_node(std::ifstream& in);

void destroy(Customer* head);

void console_input(Customer* temp);

int create_prod_list(Customer* head);

int hash(Customer* temp);

void print_prod_list(std::ofstream& out, Product* head);