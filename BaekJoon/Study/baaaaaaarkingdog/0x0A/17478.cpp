#include <bits/stdc++.h>
using namespace std;

int N;

int recursive(int r){
    string recursed;
    for(int i = 0; i<r; i++){
        recursed += "____";
    }
    if(r>=N){
        cout << recursed << "\"����Լ��� ������?\"" << "\n";
        cout << recursed << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
        cout << recursed << "��� �亯�Ͽ���." << "\n";
        return 0;
    }
    cout << recursed << "\"����Լ��� ������?\"" << "\n";
    cout << recursed << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";
    cout << recursed << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
    cout << recursed << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";
    recursive(r+1);
    cout << recursed << "��� �亯�Ͽ���." << "\n";
    return 0;
}

int main(void){
    cin >> N;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";
    recursive(0);
}