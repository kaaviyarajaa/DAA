#include <bits/stdc++.h> 
using namespace std; 

int assignhole(int mice[],int holes[],int m,int h){
	if(m!=h){
		return -1;
	}
	sort(mice,mice+m);
	sort(holes,holes+h);
	
	int max=0;
	for(int i=0;i<m;++i){
		if(max < abs(mice[i] - holes[i])){
			max=abs(mice[i]-holes[i]);
		}
	}
		return max;
		
	}
	int main()
	{
		int mice[]={3,2,-4};
		int holes[]={0,-2,4};
		int m= sizeof(mice) / sizeof(mice[0]);
		int h=sizeof(holes) / sizeof(holes[0]);
		int mintime = assignhole(mice, holes, m, h);
		cout << "The last mouse gets into the hole in time:" << mintime << endl;
		return 0;
	}

