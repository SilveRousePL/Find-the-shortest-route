#include "Search.h"
#include <iostream>

using namespace std;

Search::Search(Graph graph, size_t start, size_t end) : graph(graph), size(graph.getSize()), start(start), end(end)
{
	tmp_path_.reserve(size);

	useVertex_(start);
	look_(0, 0, start);
	releaseVertex_(start);

	_uzupelnijWyniki();
}

Search::~Search()
{
	path.clear();
}

Path Search::getShortestPath() const
{
	return result;
}

void Search::look_(int deep, int sum, int current)
{
	int * nastepne = new int[size];
	_wyznaczNastepne(current, nastepne);
	bool czy_zapisana = false;

	for (int i = 0; i < size; i++)
	{
		if (!czy_zapisana)
		{
			int * tab = new int[size + 1];
			for (int j = 0; j < tmp_path_.size(); j++)
			{
				tab[j] = tmp_path_[j];
			}
			Path tmp(tab, deep + 1, sum);
			path.push_back(tmp);
			czy_zapisana = true;
			delete[] tab;
		}

		int nastepny = nastepne[i];
		if (nastepny < 0) return;
		if (isUsedVertex_(nastepny)) continue;

		useVertex_(nastepny);
		look_(deep + 1, sum + graf[current][nastepny], nastepny);
		releaseVertex_(nastepny);
	}

	delete[] nastepne;
}

void Search::_wyznaczNastepne(int wezel, int * tab) const
{
	int * tab_i = new int[size];
	int * tab_v = new int[size];
	for (int i = 0; i < size; i++)
	{
		tab_i[i] = i;
		tab_v[i] = graf[wezel][i];
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++)
			if (tab_v[j] > tab_v[j + 1])
			{
				swap(tab_i[j], tab_i[j + 1]);
				swap(tab_v[j], tab_v[j + 1]);
			}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++)
			if (tab_v[j] <= 0)
			{
				swap(tab_i[j], tab_i[j + 1]);
				swap(tab_v[j], tab_v[j + 1]);
			}

	for (int i = 0; i<size; i++)
	{
		int tmp;
		if (tab_v[i] <= 0) tmp = -1;
		else tmp = tab_i[i];
		tab[i] = tmp;
	}

	delete[] tab_i;
	delete[] tab_v;
}

void Search::useVertex_(int x)
{
	if (isUsedVertex_(x)) releaseVertex_(x);
	tmp_path_.push_back(x);
}

bool Search::isUsedVertex_(int x) const
{
	for (int i = 0; i < tmp_path_.size(); i++)
		if (tmp_path_[i] == x) return true;
	return false;
}

void Search::releaseVertex_(int x)
{
	for (auto i = tmp_path_.begin(); i != tmp_path_.end(); i++)
		if (*i == x)
		{
			tmp_path_.erase(i);
			break;
		}
}

void Search::_uzupelnijWyniki()
{
	_sortuj(0, trasa.size() - 1);

	vector<int> punkt_k;
	punkt_k.reserve(size);
	for (auto i = 0; i < trasa.size(); i++)
	{
		bool flaga = true;
		for (int j = 0; j < punkt_k.size(); j++)
			if (punkt_k[j] == trasa[i].koniec())
				flaga = false;
		if (flaga)
		{
			wynik.push_back(trasa[i]);
			punkt_k.push_back(trasa[i].koniec());
		}
	}
}

void Search::_sortuj(int lewa, int prawa)
{
	int i = lewa;
	int j = prawa;
	Trasa x = trasa[(lewa + prawa) / 2];
	do
	{
		while (trasa[i].pobierzKoszt() < x.pobierzKoszt()) i++;
		while (trasa[j].pobierzKoszt() > x.pobierzKoszt()) j--;
		if (i <= j)
		{
			swap(trasa[i], trasa[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (lewa < j) _sortuj(lewa, j);
	if (prawa > i) _sortuj(i, prawa);
}