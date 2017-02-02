#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void sjf(vector<pair<ll,ll> > &process,int n){
	// Sorting the process based on Arrival Time
	sort(process.begin(), process.end(), [](auto &left, auto &right) {
	    return left.first < right.first;
	});
	// camparison function that forms min heap according to the second element in the pair
  	class comp{public:bool operator()(pair<ll,ll> &p1,pair<ll,ll> &p2){return p1.second>p2.second;}};
  	// min heap based on Burst Time
  	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,comp> pq;
  	int ct = process[0].first;
  	int k = 0,awt=0,atat=0;
  	cout << "Process \tArrival Time \tBurst Time \tWait Time \tTurnAround Time \n";
  	for(int i=0;i<n;i++){
		for(int j=k;j<n;j++){
			if(ct<process[j].first){
				break;
			}
			else{
				pq.emplace(make_pair(process[j].first,process[j].second));
				k++;
			}
		}
		pair<ll,ll> cur = pq.top();
		pq.pop();
		int wt = ct - cur.first;
		int tat = wt + cur.second;
		ct = ct + cur.second;
		awt+=wt;atat+=tat;
		cout <<  i+1 << "\t\t"<< cur.first <<"\t\t" << cur.second <<"\t\t" << wt << "\t\t" << tat << endl;
  	}
	cout << "Average Waiting Time: " << awt/n << "\nAverage TurnAround Time: " << atat/n << endl;
}
int main() {
	vector <pair<ll,ll> > process;
	int n,a,b;
	cout << "Enter no of process: ";
	cin >> n;
	// Taking input
	for(int i=0;i<n;i++){
		cout << "Enter arrival and burst time: ";
		cin >> a >> b;
		process.push_back(make_pair(a,b));
	}
	sjf(process,n);
	return 0;
}
