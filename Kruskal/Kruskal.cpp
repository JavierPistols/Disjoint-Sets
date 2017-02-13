#include "Kruskal.h"
void Kruskal::getFromFile() {
	int iedge1 = 0;
	int iedge2 = 0;
	string fileName;
	int weight;
	string sentence;
	string elem;
	string elem2;
	string elemW;
	cout << endl << "Introduzca el nombre del archivo ";
	cin >> fileName;
	ifstream file(fileName, ios::in);
	if (file.good()) {
		while (getline(file, sentence)) {
			istringstream str(sentence);
			str >> elem;
			str >> elem2;
			str >> elemW;
			try {
				iedge1 = stoi(elem);
				iedge2 = stoi(elem2);
				weight = stoi(elemW);
			}
			catch (exception e) {
				cout << "something went wrong";
			};
			m_sortEdges.insert(make_pair(weight, make_pair(iedge1, iedge2)));
		}
	}	
}
Kruskal::Kruskal()
{
}
void Kruskal::getVertices() {
	DisjointSets* fresh = nullptr;
	im_sortEdges = m_sortEdges.begin();
	im_MST = m_MST.begin();

	for (im_sortEdges; im_sortEdges != m_sortEdges.end();im_sortEdges++) {
		if (m_MST.find(im_sortEdges->second.first) == m_MST.end()) {
			fresh = new DisjointSets(im_sortEdges->second.first);
			m_MST.insert(make_pair(im_sortEdges->second.first, fresh));
		}
		if (m_MST.find(im_sortEdges->second.second) == m_MST.end()) {
			fresh = new DisjointSets(im_sortEdges->second.second);
			m_MST.insert(make_pair(im_sortEdges->second.second, fresh));
		}
	}	
}
void Kruskal::mecanism() {
	getFromFile();
	DisjointSets* edge1 = nullptr;
	DisjointSets* edge2 = nullptr;
	getVertices();
	im_sortEdges = m_sortEdges.begin();
	for (im_sortEdges; im_sortEdges != m_sortEdges.end();im_sortEdges++) {
		edge1 = m_MST.at(im_sortEdges->second.first);
		edge2 = m_MST.at(im_sortEdges->second.second);
		if(edge1->find().name != edge2->find().name){
			mm_MST.insert(make_pair(im_sortEdges->first,im_sortEdges->second));
			edge1->uniteSets(edge1, edge2);
		}
	}
}