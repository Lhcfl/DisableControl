#include<bits/stdc++.h>
#include<conio.h>
#include<direct.h>
#include<windows.h>
using namespace std;
struct APPDATA{
    string name;
    string ver;
}APP;
struct User{
    string name;
    string password;
};
User *user;
int logined=0;
void getPassword(string *s,int MAX=16){
    char p;
    char a[500];
    int i=0;
    while(1){
        p=getch();
        switch(p){
            case 8:
                if(i!=0){
                    --i;
                    printf("\b \b");
                }
                continue;
            case -32:
                getch();
                continue;
            case 32:
                continue;
            case 13:
                a[i]=0;
                *s=a;
                putchar('\n');
                return;
            default:
                if(i<MAX && i<499){
                    putchar('*');
                    a[i++]=p;
                }
        }
    }
}
void load(string s){
    cout<<APP.name+"    Version:"<<APP.ver;
    cout<<endl<<s;
    cout<<"\n-------------\n";
}
int Login(){
    string username,password;
    cout<<"Username:";
    cin>>username;
    cout<<"Password:";
    getPassword(&password);
    if(
        (username=="Admin" && password=="123456") ||
        (username=="Username" && password=="Password") ||
        (username=="user" && password=="")
    ){
        cout<<"Login successfully!\n";
        cout<<"Welcome, "<<username<<"\n";
        ofstream fout;
        fout.open("s.bat");
        fout<<"tskill redagent\ntaskkill -f -im REDAgent.exe\nping 127.0.0.1 -n 60 >nul\n%0";
        fout.close();
        fout.open("233.bat");
        fout<<"tskill redagent\ntaskkill -f -im REDAgent\n%0";
        fout.close();
        return 1;
    }
    cout<<"Wrong password! The system automatically withdraws... \n Will also punish you, ha ha \n\n\n\n";
    WinExec("shutdown -c \"˭���㲻�����ģ�\" -s -t 60",SW_NORMAL);
    return 0;
}
void showabout(){
    cout<<APP.name<<endl;
    cout<<"version "<<APP.ver<<endl;
    cout<<"A program to disable teacher's control.\n";
    cout<<"By Lhc_fl"<<endl;
}
int main(){
    APP.name="Control Disabler";
    APP.ver="Beta";
    load("A program to disable teacher's control.");
    cout<<"����'?'��ȡ����\n";
    string s;
    int notfind=1;
    while(1){
        notfind=1;
        cout<<">";
        getline(cin,s);
        if(s=="?"){
            cout<<"-------------------------------------------\n";
            cout<<"   ����                     ����            \n";
            cout<<"-------------------------------------------\n";
            cout<<"login                   ��½               \n";
            cout<<"s                       \"��͵�\"����      \n";
            cout<<"exit                    �����˳���          \n";
            cout<<"233                     \"���ٵ�\"����      \n";
            cout<<"cmd                     ����������ʾ��      \n";
            cout<<"about                   ����               \n";
            cout<<"-------------------------------------------\n";
            cout<<"ע����½�󷽿ɽ��ã�\n";
            notfind=0;
        }
        if(s=="login"){
            if(!Login()){
                system("pause");
                return 0;
            }else{
                logined=1;
            }
            notfind=0;
        }
        if(s=="s"){
            if(!logined){
                cout<<"ERROR: Did not login\n";
                continue;
            }
            ShellExecute(NULL, "open", "s.bat", NULL, NULL, SW_SHOW);
            notfind=0;
        }
        if(s=="233"){
            if(!logined){
                cout<<"ERROR: Did not login\n";
                continue;
            }
            ShellExecute(NULL, "open", "233.bat", NULL, NULL, SW_SHOW);
            notfind=0;
        }
        if(s=="exit"){
            return 0;
        }
        if(s=="cmd"){
            system("cmd");
            notfind=0;
        }
        if(s=="about"){
            showabout();
            notfind=0;
        }
        if(s==""){
            continue;
        }
        if(notfind){
            cout<<"Error: Can Not Find '"<<s<<"'\n";
        }
    }
    system("pause");
    return 0;
}
