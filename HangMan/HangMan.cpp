#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class GetWord{
    string word;
    string answer;
    int len;
    public:
    GetWord(){
        string w[10] = {"apple", "banana", "daehoon", "fabula", "maru", "hyunoh", "dohun", "hyunmin", "mingyu", "daegyu"};
        srand(time(NULL));
        answer = w[rand()%10];
        len = answer.length();
        word.append(len, '_');
        PrintWord();
    }

    void CollectWord(char w){
        for(int i = 0; i < len; i++)
        {
            if(answer[i] == w)
                word[i] = w;
        }
    }

    bool Collection()
    {
        if(word == answer)
        {
            cout << "finish!!";
            return false;
        }
        else
            return true;
    }   

    void PrintWord()
    {
        cout << word << "\n";
    }
};

int main(void)
{
    GetWord word;

    while(word.Collection())
    {
        char a;
        cin >> a;
        word.CollectWord(a);
        word.PrintWord();
    }
    return 0;
}