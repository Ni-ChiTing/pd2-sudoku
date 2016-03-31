#include<iostream>
#include<cstdlib>
#include"time.h"
#include<cstdio>
using namespace std;
class Sudoku{
		public:
				void	readIn();
				void    rotate(int c);
				void	changeNum(int a,int b);
				void    giveQuestion();
				void    changeRow(int a,int b);
				void    changeCol(int a,int b);
				void	flip(int c);
				void    change();
				void    transform();
				bool 	test(int arr[81],int c,int g);
				int 	fillin(int a[81],int n);
				void    print (int arr[81]);
				void    solve();
				bool	check(int arr[81]);
				static const int size=81;
		private:
				int Sudoku_q[81];	
				int Sudoku_i[81];
				int ans[81];
				int re;	
				int row[9];
	};
