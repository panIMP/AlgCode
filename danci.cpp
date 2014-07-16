#include <string>
#include <map>

using namespace std;

int who_win (string word, map<string, int>& m)
{
    typedef pair <string, int> Who_Pair;

    int size = word.size();
    if(size < 2)
        return -1;

    if(size == 2)
        return 1;

    if(size == 3) {
        if(word[0] >= word[1] && word[1] >= word[2])
            return 0;
        else
            return 1;
    }

    for(int i = 0; i < size; ++i) {
        if(i != 0 && word[i] == word[i-1])
            continue;

        string str = word.substr(0,i)+word.substr(i+1,size-i-1);

        bool flag = true;
        for(int j = 0; j < size-2; ++j) {
            if(str[j] >= str[j+1]) {
                flag = false;
                break;
            }
        }
        if(flag)
            return 1;
    }

    for(int k = 0; k < size; ++k) {
        if(k != 0 && word[k] == word[k-1])
            continue;

        string strtmp = word.substr(0,k)+word.substr(k+1,size-k-1);
        map<string, int> :: iterator m_iter;
        m_iter = m.find(strtmp);
        int state;

        if(m_iter == m.end()) {
            state = who_win(strtmp, m);
            m.insert( Who_Pair (strtmp, state) );
        }
        else {
            state = m_iter->second;
        }

        if( !state )
            return 1;
    }

    m.insert( Who_Pair (word, 0) );
    return 0;
}

int who (string word)
{
    map<string, int> m;
    typedef pair <string, int> Who_Pair;

    m.insert( Who_Pair ("a",0) );

    return who_win(word, m);
}


int danci()
{
    char str[1024] = {'\0'};
    int win = 0;

    if (gets_s(str, 1024) == NULL)
        return -1;

    win = who(string(str));

    printf("%d", win);

    return 0;
}






