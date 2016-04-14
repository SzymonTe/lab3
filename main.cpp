// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>

#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);

int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	//tworze slownik do plci

	genders(slavs, n);
	containers(slavs, n);
	adapters(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

	vectorOfSlavs.push_back(slavs);

	Slavv *bonus_slavs = slavs;

	bonus_slavs+=1;

	for(int i = 1; i < n; i++)
	{	
		int place = rand() % vectorOfSlavs.size();
		vectorOfSlavs.insert( place + vectorOfSlavs.begin(), bonus_slavs++);
	} // Umieść Słowian w losowej kolejności w wektorze.

	vector <Slav*> :: iterator iter_vectorOfSlavs = vectorOfSlavs.begin();

	for(int i = 0; i < n; i++)
	{
		cout << *(iter_vectorOfSlavs++)->description() << endl;
	} // Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze

	REPORT_CONTAINERS;
	printf("## set\n");

	for(int = n-1; i > -1; i--)
	{
		setOfSlavs.insert(vectorOfSlavs[i]);
		vectorOfSlavs.pop_back();
	} // Przenieś wszystkich Słowian z wektora do zbioru.
	
	REPORT_CONTAINERS;
	printf("## map\n");

	set<Slav*> :: iterator iter_setOfSlavs = setOfSlavs.begin();

	while(iter_setfOfSlavs != setOfSlavs.end())
	{
		mapOfSlavs[*iter_setOfSlavs] = *(iter_setOfSlavs = setOfSlavs.erase(iter_setOfSlavs)); // erase zwraca iterator wskazujacy na 1st element za usunietym elementem3333333333333333
		iter_setOfSlavs = setOfSlavs.erase(iter_setOfSlavs);
	}// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	
	map<Slav*, Slav*> :: itetator iter_mapOfSlavs = mapOfSlavs.begin();

	while(iter_mapOfSlavs != mapOfSlavs.end())
	{
		cout << (iter_mapOfSlavs->first())->description() << "\t" << (iter_mapOfSlavs->second())->description() << endl;
		iter_mapOfSlavs++;

	} // Wykorzystując iterator, wyświetl wszystkie pary Słowian
	
	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	Slav* bonus_slavs = slavs;

	for(int i = 0; i < n; i++)
	{
		queueOfSlavs.push(bonus_slavs++);
	} // Umieść Słowian w kolejce.
	
	REPORT_ADAPTERS;

	printf("## stack\n");

	while(!queueOfSlavs.empty())
	{
		stackOfSlavs.push(queueOfSlavs.front());
		queueOfSlavs.pop();
	} // Przenieś Słowian z kolejki do stosu.

	REPORT_ADAPTERS;

	while(!stackOfSlavs.empty())
	{
		cout << stackOfSlavs.top() << endl;
		stackofSlavs.pop();
	} // Wyświetl Słowian zdejmowanych ze stosu.

	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}

void genders(Slav *slavs, int n)
{
	vector <Slav*> vectorOfMales;
	vector <Slav*> vectorOfFemales;
	map <sex, vector<Slav*>> mapOfGenders;

	for(int i = 0; i < n; i++, slavs++)
	{
		if(((*slavs)->gender()) == male)
		{
			vectorOfMales.push_back(*slavs);
		}
		else
		{
			vectorOfFemales.push_back(*slavs);
		}
	}

	mapOfGenders[male] = vectorOfMales;
	mapOfGenders[female] = vectorOfFemales;

}
