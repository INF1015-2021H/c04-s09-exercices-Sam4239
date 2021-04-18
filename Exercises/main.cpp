///
/// Ce projet utilise quelques librairies disponibles sur Vcpkg et permet entre autre d'en tester le bon fonctionnement.
///


#include <cstddef>
#include <cstdint>

#include <array>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <span>
#include <utility>
#include <list>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <cppitertools/itertools.hpp>
#include <cppitertools/zip.hpp>

#include "MyClass.hpp"
#include "List.hpp"
#include "brackets.hpp"
#include "School.hpp"

using namespace std;
using namespace iter;


void runBracketsExample() {
	char brackets[] = {'(', ')', '{', '}', '[', ']'};
	string yeet = "(yeet){yeet}";
	string yeeet = "({yeet})";
	string yeeeet = "({yeet)}";
	string yeeeeet = "(yeet";
	cout << checkBrackets(yeet, brackets) << "\n";
	cout << checkBrackets(yeeet, brackets) << "\n";
	cout << checkBrackets(yeeeet, brackets) << "\n";
	cout << checkBrackets(yeeeeet, brackets) << "\n";
}

void runSchoolExample() {
	School school;
	Professor prof(0xC0FFEE);
	school.addNewGrad(0xDEADBEEF, "Infologie", &prof);
	GraduateStudent& foo = *school.findGrad(0xDEADBEEF);
	Student& bar = foo;
	foo.changeSupervisor(nullptr);
	foo.updateGpa(2.5);
	bar.updateGpa(3.8);
	bar.changeProgram("whatever idk my life is meaningless");
}

void runListExample() {
	unordered_map<List<int>, string> myMap = {
		{{0xDEAD, 0xBEEF}, "mooo"},
		{{0xFED, 0xBABE, 0xBAD, 0xC0FFEE}, "oops"},
		{{420, 69}, "nice"}
	};

	cout << myMap.contains({420, 69}) << "\n";
	cout << myMap.contains({69, 420}) << "\n";
	cout << myMap.at({0xDEAD, 0xBEEF}) << "\n";
	map<List<int>, string> myMap2 = {
		{{0xDEAD, 0xBEEF}, "mooo"},
		{{0xFED, 0xBABE, 0xBAD, 0xC0FFEE}, "oops"},
		{{420, 69}, "nice"}
	};

	List<double> foo = { 1, 3, 4, 7, 5 };
	List<double>::iterator pos = max_element(foo.begin(), foo.end());
	cout << *pos;
	if (pos != foo.end())
		cout << *pos;
	else
		cout << "not found";
}

template <typename T>
void fn(const T& a) {
	cout << a;
}

template <>
void fn<pair<string, int>>(const pair<string, int>& a) {
	cout << "(" << a.first << ", " << a.second << ")";
}



int main() {
	cout.setf(ios::boolalpha);

	runBracketsExample(); cout << "\n\n\n\n";
	runSchoolExample(); cout << "\n\n\n\n";
	runListExample(); cout << "\n\n\n\n";

	/////////////////////////////////////////////////

	/*set<int> mySet = { 1, 4, 3 };
	for (auto&& e : mySet)
		cout << e << " ";*/

	///////////////////////////////////////////////////

	/*map<string, int> myMap;
	myMap["hello"] = 42;
	myMap["hi"] = 69;
	myMap["42"] = 9000;
	for (auto&& e : myMap)
		cout << e.first << " " << e.second << "\n";

	for (auto&& [k, v] : myMap)
		cout << k << " " << v << "\n";*/

	///////////////////////////////////////////////////////

	//vector<string> v = { "a", "b", "c" }; // copie
	//string foo = v.back();
	//v.pop_back();

	/////////////////////////////////////////////////////////

	/*vector<string> v = { "a", "b", "c" }; // reference
	string foo = move(v.back());
	v.pop_back();*/

	///////////////////////////////////////////////////////

	//stack<int> myStack; //but : restreindre

	///////////////////////////////////////////////////////////

	//vector<string> foo = { "a", "b", "c" };
	//foo.at(2); // = "c"

	///////////////////////////////////////////////////////////////////

	//unordered_map<string, int> bar = {
	//	{"a", 1},
	//	{"b", 2},
	//	{"c", 3}
	//};
	//bar["d"] = 4; // creation nouvelle cle // creation pair avec cle + valeur par defaut, apres le 4
	//bar["d"] = 5;
	//cout << bar.at("a") << endl;
	//cout << bar["d"] << endl; // ca va creer une nouvelle cle avec une valeur par defaut 0 et il va la retourner

	/////////////////////////////////////////////////////////////////////////

	function<bool(const string& a, const string& b)> compareNoCase = [](const string& a, const string& b) {
		string upperA = "";
		for (auto&& chr : a)
			upperA.push_back((char)toupper(chr));
		string upperB = "";
		for (auto&& chr : b)
			upperB.push_back((char)toupper(chr));
		return upperA < upperB;
	};

	using NoCaseSet = set<string, function<bool(const string& a, const string& b)>>;

	/*unordered_map<string, set<string>> bar = {
		{"a", {"jeu 1", "jeu 2", "jeu 3"}},
		{"b", {"jeu 11", "jeu 22", "jeu 33"}},
		{"c", {"jeu 111", "jeu 222", "jeu 333"}},
	};*/

	/*unordered_map<string, NoCaseSet> bar = {
		{"a", NoCaseSet({"jeu 1", "jeu 2", "jeu 3"}, compareNoCase)},
		{"b", NoCaseSet({"jeu 11", "jeu 22", "jeu 33"}, compareNoCase)},
		{"c", NoCaseSet({"jeu 111", "jeu 222", "jeu 333"}, compareNoCase)}
	};

	for (auto&& [key, val] : bar) {
		cout << "key ";
		for (auto&& e : val)
			cout << e << " ";
		cout << endl;
	}*/

	///////////////////////////////////////////////////////////////////////////

	class Foo {
	public:
		Foo(int m1 = 0) : m1_(m1) { }

		int operator()(int arg) const {
			return m1_ + arg;
		}

	private:
		int m1_;
	};

	Foo foo(100);

	int r = foo(42);
	cout << r << endl;

	function<int(int)> fooFn = foo;
	fooFn(42);
	cout << fooFn(42) << endl;


}

