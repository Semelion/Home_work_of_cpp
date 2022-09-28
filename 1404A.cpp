#include <iostream>
long long t,n,k,a,b,flag;
std::string s;
int main() {
    std::cin>>t;
    while(t--) {
        std::cin>>n>>k>>s;
        flag=1,a=b=0;
        for(int i=k; i<n; i++) {
            if(s[i]=='?'||s[i]==s[i%k])continue;
            else if(s[i%k]=='?') s[i%k] = s[i];
            else {
                flag=0;
                break;
            }
        }
        for(int i=0; i<k; i++) {
            if(s[i]=='1')a++;
            else if(s[i]=='0')a--;
            else b++;
        }
        if(b<abs(a))flag=0;
        std::cout<<(flag==1?"YES":"NO")<<std::endl;
    }return 0;
}