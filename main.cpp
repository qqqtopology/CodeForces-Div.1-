#include <iostream>
#include <vector>
#include <list> 
#include <map> 
#include <algorithm> 
#include <cmath> 
using namespace std;
int main() {
    long long int constant = 1000000007;
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        vector<long long int> a(n);
        vector<long long int> b(n);
        map <long long int, long long int> mp, index;
        for (long long int i = 0; i < n; i++)
        {
            cin >> a[i];
            index[i + 1]++;
        }
        for (long long int i = 0; i < n; i++)
            cin >> b[i];
        for (long long int i = 0; i < n; i++)
        {
            mp[a[i]] = b[i];
        }
        long long int count = 0, next = mp[1], finded = 1, res = 1;
        map <int, int> orbit;
        for (long long int i = 0; i < n; i++)
        {
            orbit[finded]++;
            index.erase(finded);
            if (orbit.count(next) > 0)
            {
                count++;
                orbit.clear();
                finded = index.begin()->first;
                next = mp[finded];
            }
            else
            {
                finded = next;
                next = mp[next];
            }
        }
        for (long long int i = 0; i < count; i++)
        {
            res = (res * 2) % constant;
        }
        cout << res << endl; 
    }
    return 0;
}
