#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define MAX 500

void stableMarriage () {
    int n;
    cin >> n; //qtd de homens e mulheres

    int wPreferences[MAX][MAX];
    int mPreferences[MAX][MAX];
    int wPartner[MAX];
    int marriage[MAX];
    int freeCount = n;
    bool mFree[MAX];

    for (int i = 1; i <= n; i++){
        wPartner[i] = -1;
        int x;
        cin >> x;
        for (int j = 0; j < n; j++)
            cin >> wPreferences[i][j];
    }



    for (int i = 1; i <= n; i++) {
        mFree[i] = true;
        int x;
        cin >> x;
        for (int j = 0; j < n; j++)
            cin >> mPreferences[i][j];
    }
    
    while (freeCount > 0) {
        int m;
        for (m = 1; m <= n; m++)
            if (mFree[m])
                break;
        
        for (int i = 0; i < n && mFree[m]; i++)
        {
            int w = mPreferences[m][i];

            if (wPartner[w] == -1) {
                wPartner[w] = m;
                marriage[m] = w;
                mFree[m] = false;
                freeCount--;
            } else {
                int m1 = wPartner[w];
                
                bool preferOver;

                for (int j = 0; j < n; j++) {
                    if (wPreferences[w][j] == m1){
                        preferOver = true;
                        break;
                    }
                    if (wPreferences[w][i] == (m-n)+1) {
                        preferOver = false;
                        break;
                    }
                }

                if (!preferOver) {
                    wPartner[w] = m;
                    marriage[m] = w;
                    mFree[m] = false;
                    mFree[m1] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << marriage[i] << endl;
    }

}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        stableMarriage();
    }
}

//Molotov