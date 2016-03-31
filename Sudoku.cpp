#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "Sudoku.h"
using namespace std;
	void Sudoku::readIn(){
						int n,i;
						n=0;
						while(1){
							for(n=0;n<81;n++)
							{
								cin>>i;
								Sudoku_q[n]=i;
							}
							break;
						}
	}
	void Sudoku::rotate(int c){
							int a,b,k,n;
							a=0;
							c=c%4;
						for(;c>0;c--){
							a=0;
										for(n=0;n<81;)
										{
											b=71;
											a++;
											b=b+a;
											for(k=0;k<9;k++)
											{
												Sudoku_i[n]=Sudoku_q[b];
												b=b-9;
												n=n+1;
											}
										}
										for(n=0;n<81;n++)
										{
											Sudoku_q[n]=Sudoku_i[n];
										}
									}
						}
	void Sudoku::changeNum(int a,int b){
						int n;
						for	(n=0;n<81;n++)
						{
							if(Sudoku_q[n]==a)
							{
								Sudoku_q[n]=b;
							}
							else if(Sudoku_q[n]==b)
							{
								Sudoku_q[n]=a;
							}
						}
						}
	void Sudoku:: giveQuestion(){
								int ssudoku[81]={0};

								ssudoku[0]=8;
								ssudoku[11]=3;
								ssudoku[12]=6;
								ssudoku[19]=7;
								ssudoku[22]=9;
								ssudoku[24]=2;
								ssudoku[28]=5;
								ssudoku[32]=7;
								ssudoku[40]=4;
								ssudoku[41]=5;
								ssudoku[42]=7;
								ssudoku[48]=1;
								ssudoku[52]=3;
								ssudoku[56]=1;
								ssudoku[61]=6;
								ssudoku[62]=8;
								ssudoku[65]=8;
								ssudoku[66]=5;
								ssudoku[70]=1;
								ssudoku[73]=9;
								ssudoku[78]=4;
	
								for(int n=0;n<81;n++)	 
		   						{
									 if(n%9==8)                          
									 cout<<ssudoku[n]<<"\n";
									 else
									 cout<<ssudoku[n]<<" ";
								}
								
								}


	void Sudoku::changeRow(int a ,int b){
								int n,sudoku_rowa,sudoku_rowb;
								for(n=0;n<27;n++)
								{
									sudoku_rowa=Sudoku_q[n+27*a];
									sudoku_rowb=Sudoku_q[n+27*b];
									Sudoku_q[n+27*b]=sudoku_rowa;
									Sudoku_q[n+27*a]=sudoku_rowb;
								}
	}
	void Sudoku::changeCol(int a,int b){
								int n,sudoku_cola,sudoku_colb,i,j;
								i=71;
								j=1;
								for	(n=0;n<27;n++)
								{
									sudoku_cola=Sudoku_q[i+a*3+j];
									sudoku_colb=Sudoku_q[i+b*3+j];
									Sudoku_q[i+b*3+j]=sudoku_cola;
									Sudoku_q[i+a*3+j]=sudoku_colb;
									i=i-9;
									if(i<-1)
									{
										i=71;
										j=j+1;
									}
								}
								}	
	void Sudoku::flip(int c){
								int n,j,a,b;
								if(c==0)
								{
									for(n=1;n<5;n++)
									{
										for (j=36;j<45;j++)
										{
											a=Sudoku_q[j+n*9]; 
											b=Sudoku_q[j-n*9];
											Sudoku_q[j+n*9]=b;
											Sudoku_q[j-n*9]=a;
										}
									}
								}
								if(c==1)
								{
									for(n=1;n<5;n++)
									{
										for(j=4;j<81;j=j+9)
										{
											a=Sudoku_q[j+n];
                                            b=Sudoku_q[j-n];
                                            Sudoku_q[j+n]=b;
                                            Sudoku_q[j-n]=a;
										}
									}
								}	
							}
	void Sudoku::change(){
							srand(time(NULL));
							changeNum(rand()%9+1,rand()%9+1);
							flip(rand()%2);
							changeCol(rand()%3,rand()%3);
							changeRow(rand()%3,rand()%3);
							rotate(rand()%101);
						 }
	void Sudoku::transform(){
								int n;
								change();
								for(n=0;n<81;n++)
								{
									if(n%9==8)
									cout<<Sudoku_q[n]<<"\n";
									else
									cout<<Sudoku_q[n]<<" ";
								}
							}
	bool Sudoku::test(int arr[81],int c,int g){
								int n=0,b,a,k;
								a=c%9;
								a=a/3;
								b=c/9;
								b=b/3;
								k=b*27+3*a;
								for(a=0;a<3;a++)
								{
									for(b=0;b<27;b=b+9)
									{
										if(arr[k+a+b]==g)
											return false;
									}
								}
								a=c/9;
								for(n=9*a;n<a*9+9;n++)
								{
									if(arr[n]==g)
										return false;
								}
								a=c%9;
								for(n=a;n<81;n=n+9)
								{
									if(arr[n]==g)
										return false;
								}
								return true;
								}

	int Sudoku::fillin(int a[81],int n)
									{
									int temp[81];
									int i,j,c,d;
		   							if (re>1)
			    					return 2;
		    						for(i=0;i<81;i++)
				 					{
					   
					    				temp[i]=a[i];
						 			}
			 						if(a[n] != 0) 
				  					{
					    				if(n == 80)   
							  			{
								  			re++;
										 if(re==1)
										{
											for(c=0;c<81;c++)
											{ 
												ans[c]=temp[c]; 
																					 	 		
											}
										}
									}
						 			 else    
							     		fillin(temp,n+1);
						   			}	
			 					 	else    
				  					 {
					    				 for(int k=1;k<=9;k++)
							   			{
								      		bool flag=test(temp,n,k);
									   		if(flag) 
											    {
													temp[n]=k; 
													if(n == 80)
													{
														re++;
														if(re==1)
														{
														for(c=0;c<81;c++)
														{ 
														ans[c]=temp[c]; 
																														 	 	
														}
														}
													}
													else
													fillin(temp,n+1);
													temp[n]=0; 
												}
										   }
						  			}
								}		

	void Sudoku::print (int arr[81])
								{				
									int n;
									for(n=0;n<81;n++)
					   				{
						       			if(n%9==8)
								       printf("%d%c",arr[n],'\n');
							       		else
									   printf("%d%c",arr[n],' ');
								   	}
				                                 
								}
	void Sudoku::solve (){
							re=0;
							if(check(Sudoku_q))
							{
							printf("%d",re);								
							}
							else{
							fillin(Sudoku_q,0);
							if(re==0)
								printf("%d",re);
							if(re==1)
							{
								printf("%d%c",re,'\n');
								print(ans);	
							}
							if(re==2)
								printf("%d",re);
							}
						}
	bool Sudoku::check(int arr[81])
				{
					int n=0,a,b,k=0,j;
					
					for(n=0;n<9;n++)
					{
						row[n]=0;
					}
					for(n=0;n<55;n=n+27)
					{
						for(k=0;k<7;k=k+3)
						{
					for(a=0;a<3;a++)
					{
					for(b=0;b<27;b=b+9)
					{
					if(arr[n+k+a+b]!=0)
					{
						row[arr[n+k+a+b]-1]++;
					}																		
					}
					}
					for(j=0;j<9;j++)
					{
						if(row[j]>1)
						return true;
						else
						row[j]=0;
					}
				
					}
					}
					for(a=0;a<9;a++)
					{
					for(n=9*a;n<a*9+9;n++)
					{
						if(arr[n]!=0)
						row[arr[n]-1]++;													
					}
					for(k=0;k<9;k++)
					{
						if(row[k]>1)
						return true;
						else
						row[k]=0;
					}
					}
					for(a=0;a<9;a++)
					{	
					for(n=a;n<81;n=n+9)
					{
						if(arr[n]!=0)
						row[arr[n]-1]++;							
					}
					for(k=0;k<9;k++)
					{
						if(row[k]>1)
						return true;
						row[k]=0;
					}
					}
					return false;
				}
