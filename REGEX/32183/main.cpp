#include <bits/stdc++.h>

using namespace std;

bool is_virus(string src_string){
    regex pattern("(1(10)+1*|0+10)+");

    if (regex_match(src_string, pattern)){
        return true;
    }
    else return false;

}

string convert_string(string src_string, 
    bool convert_0, bool convert_1, 
    int start_index, int end_index)
{
    if (convert_0 && convert_1){
        for (int i=start_index; i<= end_index; i++){
            if (src_string[i] == '0') src_string[i] = '1';
            else src_string[i] = '0';
        }
    }
    else if (convert_0 && !convert_1) {
        for (int i=start_index; i<= end_index; i++)
            if (src_string[i] == '0') src_string[i] = '1';
    }
    else if (!convert_0 && convert_1) {
        for (int i=start_index; i<= end_index; i++)
            if (src_string[i] == '1') src_string[i] = '0';
    }


    return src_string;

}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> awsner_vec;

    int N;
    cin >> N;

    string virus_string;
    cin >> virus_string;

    if (is_virus(virus_string)) awsner_vec.push_back("YES");
    else awsner_vec.push_back("NO");

    
    int Q;
    string convert_option;
    bool convert_0, convert_1;
    int start_index, end_index;

    cin >> Q;

    for (int _=0; _<Q; _++){
        cin >> convert_option;
        if (convert_option[0] == '1') convert_0 = true;
        else convert_0 = false;

        if (convert_option[1] == '0') convert_1 = true;
        else convert_1 = false;

        cin >> start_index;
        cin >> end_index;

        virus_string = convert_string(virus_string, convert_0, convert_1, start_index, end_index);
        if (is_virus(virus_string)) awsner_vec.push_back("YES");
        else awsner_vec.push_back("NO");
    }

    for (string awsner : awsner_vec){
        cout  << awsner << "\n";
    }


    return 0;
}