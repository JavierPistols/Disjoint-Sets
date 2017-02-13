#pragma once
#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;
class DisjointSets   {
public:
	int rank;
	int name;
	DisjointSets* dad;
public:
	DisjointSets() {}
	DisjointSets(int T) {
		rank = 0;
		name = T;
		dad = this;
	}
	void uniteSets(DisjointSets* a, DisjointSets* b) {
		mergeSets(a->find(),b->find());
	}
	void mergeSets(DisjointSets& a, DisjointSets& b) {
		if (a.rank < b.rank) {
			a.dad = &b;
		}
		else if (a.rank > b.rank){
			b.dad = &a;
		}
		else
			b.dad = &a;
		a.find().rank++;
	}
	DisjointSets& find() {
		if (this->dad->name == this->name) {
			return *this;
		}
		else {
			this->dad = &this->dad->find();
			return *this->dad;
		}
	}
};