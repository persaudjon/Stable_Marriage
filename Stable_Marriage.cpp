// Stable_Marriage.cpp : Defines the entry point for the console application.
//Jonathan Persaud
//CS211 Homework#10
//Stable_Marriage

#include "stdafx.h"
#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;
int mp[3][3] = { 0,2,1,
0,2,1,
1,2,0 };
int wp[3][3] = { 2,1,0,
0,1,2,
2,0,1 };

bool ok(int q[], int col)                  //col =new man, q[col]= new woman
{
	int i;
	for (i = 0; i<col;i++)                    // this will check if the new woman is already assigned or not
	{
		if (q[col] == q[i])
			return false;
	}//   First Step ends--for Loop

	for (i = 0; i<col; i++)                      //matter of higher preference
	{
		if ((mp[col][q[i]]<mp[col][q[col]]) && (wp[q[i]][col]<wp[q[i]][i]))
			return false;
		if ((wp[q[col]][i]<wp[q[col]][col]) && (mp[i][q[col]]<mp[i][q[i]]))
			return false;
	}// Second Step ends-for Loop

	return true;

}//boolean function ends here

void backtrack(int &col) {
	col--;
	if (col == -1) exit(1);
}//backtrack function ends here

void print(int q[])
{
	int i, j;
	cout << "Man" << "  " << "Woman" << endl;
	for (i = 0;i<3;i++)
	{
		cout << " " << i << "     " << q[i] << endl;
	}

}// Print function ends here



int main()
{

	int q[3];
	q[0] = 0;
	int c = 1;

	// from_backtrack keeps track if we need to reset the row to the
	// top of the current colum or not.

	bool from_backtrack = false;
	// The outer loop keep looking for solutions
	// The program terminates from function backtrack
	// when we are forced to backtack into column -1
	while (1) {
		while (c<3) { //this loop goes across columns
					  // if we just returned from backtrack, use current value of row
					  // otherwise get ready to start at the top of this column

			if (!from_backtrack)// we did not just return from backtrack 
				q[c] = -1;   //check here

			from_backtrack = false;
			while (q[c]<3) { // place queen in this column
				q[c]++;
				// if row=8, there is no valid square in this column
				// so backtrack and continue the loop in the previous column


				while (q[c] == 3)                //need to correct backtrack
				{
					backtrack(c);
					q[c]++;

				}

				//if this position is ok, place the queen
				// and move on (break) to the next column,
				// otherwise keep looking in this column

				if (ok(q, c))
					break;

			}// while q[c]<3
			c++; // placed ok, move to the next column
		}//while(c<3)

		 // one complete solution found, print it.
		print(q); // board completed, print it out
		system("pause");
		backtrack(c);
		from_backtrack = true;
	}//while(1)

    
}

