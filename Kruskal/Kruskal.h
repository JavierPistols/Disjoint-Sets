#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include "DisjointSets.h"
using namespace std;
class Kruskal {
public:
	multimap<int, pair<int , int>>::iterator im_sortEdges;
	map< int, DisjointSets*>::iterator im_MST;
	multimap< int, pair<int, int> > m_sortEdges;
	multimap< int, pair<int, int> > mm_MST;
	map< int, DisjointSets*>  m_MST;
	DisjointSets* root;
public:
	void getFromFile();
	 Kruskal();
	void mecanism();
	void getVertices();

};