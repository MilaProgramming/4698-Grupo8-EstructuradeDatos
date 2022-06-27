#include<bits/stdc++.h>
using namespace std;

class Hash
{
	int BUCKET; 
	list<int> *table;
	
public:
	Hash(int V); 
	void insertar(int x);
	int funcionHash(int x) {
		return (x % BUCKET);
	}

	void mostrarHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash::insertar(int llave)
{
	int indice = funcionHash(llave);
	table[indice].push_back(llave);
}


void Hash::mostrarHash() {
for (int i = 0; i < BUCKET; i++) {
	cout << i;
	for (auto x : table[i])
	cout << " --> " << x;
	cout << endl;
	}
}	



