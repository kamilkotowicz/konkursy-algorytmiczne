#include <bits/stdc++.h>
//https://www.geeksforgeeks.org/dynamic-segment-trees-online-queries-for-range-sum-with-point-updates/
using namespace std;
typedef long long ll;
int n;
const int mx=3e5+5;
const long long mod=1e9+7;
ll t[mx],dp[mx];
int parz_min,parz_max,nieparz_min,nieparz_max;
int bias,akt,poz;
ll suma;
struct Node {
    ll value;
    struct Node *L, *R;
};
struct Node* getnode(){
    struct Node* temp = new struct Node;
    temp->value = 0;
    temp->L = NULL;
    temp->R = NULL;
    return temp;
}
struct Node* root_parzysty;
struct Node* root_nieparzysty;

void UpdateHelper(struct Node* curr, ll index,ll L, ll R, ll val){
    if (L > index || R < index)return;
    if (L == R && L == index) {
        curr->value += val;
        return;
    }
    ll mid = L - (L - R) / 2;
    ll sum1 = 0, sum2 = 0;
    if (index <= mid) {
        if (curr->L == NULL)curr->L = getnode();
        UpdateHelper(curr->L, index, L, mid, val);
    }
    else {
        if (curr->R == NULL) curr->R = getnode();
        UpdateHelper(curr->R, index, mid + 1, R, val);
    }
    if (curr->L)sum1 = curr->L->value;
    if (curr->R) sum2 = curr->R->value;
    curr->value = sum1 + sum2;
    return;
}
ll queryHelper(struct Node* curr, ll a,ll b, ll L, ll R){
    if (curr == NULL)return 0;
    if (L > b || R < a) return 0;
    if (L >= a && R <= b) return curr->value;
    ll mid = L - (L - R) / 2;
    return queryHelper(curr->L, a, b, L, mid)+ queryHelper(curr->R, a, b, mid + 1, R);
}
ll query_parzyste(int L, int R){
    return queryHelper(root_parzysty, L, R, 0, mod-1);
}
ll query_nieparzyste(int L, int R){
    return queryHelper(root_nieparzysty, L, R, 1, mod-2);
}
void update_parzyste(int index, int value){
    UpdateHelper(root_parzysty, index, 0, mod-1, value);
}
void update_nieparzyste(int index, int value){
    UpdateHelper(root_nieparzysty, index, 1, mod-2, value);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>t[i];
    }
    dp[n]=1;
    root_parzysty=getnode();
    root_nieparzysty=getnode();
    for(int i=n-1;i>=0;--i){
        akt=(t[i]+bias)%mod;
        if(akt%2==0){
            parz_min=0;
            parz_max=mod-1-akt;
            nieparz_min=mod-akt;
            nieparz_max=mod-2;
        }
        else{
            parz_min=mod-akt;
            parz_max=mod-1;
            nieparz_min=1;
            nieparz_max=mod-1-akt;
        }
        ll w=0;
        w+=query_parzyste(parz_min,parz_max);
        if(akt!=0)w+=query_nieparzyste(nieparz_min,nieparz_max);
        if(t[i]%2==0){
            w+=dp[i+1];
        }
        w%=mod;
        dp[i]=w;
        bias=(bias+t[i])%mod;
        poz=(t[i]-bias+mod)%mod;
        if(poz%2==0)update_parzyste(poz,dp[i+1]);
        else update_nieparzyste(poz,dp[i+1]);
    }
    cout<<dp[0];
    return 0;
}