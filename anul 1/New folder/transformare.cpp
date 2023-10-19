#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int mod=4;
    char buff[256]; 
    while(mod!=3)
    {
        cout<<"Actiunea dorita: 1-criptare 2-decriptare 3-stop "<<endl;
        cin>>mod;
        if(mod==1)
        {
            cin.ignore(); 
            char s[256];
            cout<<"Introduceti cuvantul: ";
            cin.getline(s,256);
            for(int i=0;i<strlen(s);i++)
            {
                if(s[i]>='a'&&s[i]<='z')
                {
                    if(s[i]=='a')
                        cout<<0;
                    else
                        cout<<(int)s[i]-'a'<<" ";
                }
                else if(s[i]>='A'&&s[i]<='Z')
                {
                    if(s[i]=='A')
                        cout<<0;
                    else
                        cout<<(int)s[i]-'A'<<" ";
                }
                else
                    cout<<s[i]<<" ";
            }
            cout<<endl;
        }
        else if(mod==2)
        {
            int nr;
            cout<<"Numarul de litere al cuvantului: ";
            cin>>nr;
            int v[101];
            cout<<"Introduceti numerele: ";
            for(int i=1;i<=nr;i++)
                cin>>v[i];
            for(int i=1;i<=nr;i++)
                cout<<(char)(v[i]+'A');
            cout<<endl;
        }
    }
    return 0; 
}
