#include <bits/stdc++.h>
#define ll double
using namespace std;

int main() {
  vector <tuple<string,ll,ll,ll> > jobs;
  ll length,weight,size,tim;
  string name;
  cout << "Enter the no of jobs you want to do:";
  cin >> size;
  for(ll i=0;i<size;i++){
    cout << "Enter name(without spaces):";cin >> name;
    cout << "Enter time taken(approx in hr):";cin >> length;
    cout << "Enter weight(priority):";cin >> weight;
    jobs.push_back(make_tuple(name,length,weight,weight/length));
  }
  // Only works in c++14
  sort(begin(jobs), end(jobs), [](auto const &t1, auto const &t2) {
        return get<3>(t1) > get<3>(t2); // or use a custom compare function
  });
  tim=0;
  for(ll i=0;i<size;i++){
    cout << i+1 << ":" << get<0>(jobs[i]);
    tim+=get<1>(jobs[i]);
    cout << "\nCompletion Time:" << tim << "hr \n\n";
  }
  cout << "Total completion time:" << tim << "hr \n";
  return 0;
}