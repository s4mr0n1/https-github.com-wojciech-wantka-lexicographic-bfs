#pragma once

#include "Enums.h"

struct Set;  // class forward declaration

struct Vertex {
	int key;                 
	StateOfVertex state;              
	
	Vertex* prev;            
	Vertex* next;           
	
	Set* ptrSet;

	Vertex(int k);
};