#pragma once

#include "Vertex.h"

struct Set {
    Vertex* firstVertex;
	Vertex* lastVertex;
		
	Set* prevSet;
	Set* nextSet;
        
	Set* newSet;
	bool isDivided;

	Set(Set* old);
	Set();
	~Set();
};