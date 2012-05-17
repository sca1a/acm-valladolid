
/* @JUDGE_ID:  40922FK  10063  C++  */
    
/**************************************************************************
 Solution to Problem 10063 - Knuth's Permutation
 by: Francisco Dibar
 date: May-27-2004
**************************************************************************/
/* @BEGIN_OF_SOURCE_CODE */

//#define ONLINE_JUDGE 
#include <iostream>
#ifndef ONLINE_JUDGE 
	#include <fstream>
#endif 
#include <string>
#include <queue>

using namespace std;

queue<string> permutar(queue<string>& que_perm, char c)
{
	queue<string> que_res;
	string sc(1, c);

	if (!que_perm.empty()) 
		while (!que_perm.empty()) {
			string sz_linea = que_perm.front();
			que_perm.pop();
			// realizar todas las combinaciones para esa linea
			int chars = sz_linea.length();
			for (int i = 0; i <= chars; i++) {
				string res = sz_linea.substr(0, i) + sc + 
								sz_linea.substr(i, chars - i);
				que_res.push(res);
			}
		}
	else 
		que_res.push(sc);

	return que_res;
}

///////////////////////////////////////////////////////////////////////////
//	PROGRAMA PRINCIPAL
///////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
	// redireccionar la entrada y salida
	#ifndef ONLINE_JUDGE 
		cin.rdbuf((new ifstream("input.txt"))->rdbuf()); 
		cout.rdbuf((new ofstream("output.txt"))->rdbuf()); 
	#endif 

	string sz_input;
	cin >> sz_input;
	while (!cin.eof()) {
		queue<string> que_perm;
		for (int i = 0; i < (int)sz_input.length(); i++) {
			que_perm = permutar(que_perm, sz_input[i]);
		}
		// volcar los resultados
		while (!que_perm.empty()) {
			cout << que_perm.front() << endl;
			que_perm.pop();
		}
		cin >> sz_input;
		if (!cin.eof()) cout << endl;
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
