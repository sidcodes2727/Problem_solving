#include<iostream>
#include<vector>
using namespace std;

int minInvitations(vector<int>p)
{
    int st=1;
    int mi= INT16_MAX;
    int count =0;

    while ( st < p.size())
    {
        for (int i=st; i< p.size(); i++)
        {
            count += p[i];

        }
        mi= min ( mi, count);
        st++;

    }


}
int main()
{
    vector <int > p= {3,1,2,5,4};

    cout<<minInvitations(p);

return 0;
}