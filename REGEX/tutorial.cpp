#include <bits/stdc++.h>

using namespace std;


void print_matches(string str, regex reg){
    smatch matches;
    cout << boolalpha;

    while (regex_search(str, matches, reg)){
        cout << "Is there a match : " << matches.ready() << "\n";

        cout << "Are there no matches : " << matches.empty() << "\n";

        cout << "Number of matches : " << matches.size() << "\n";

        cout << matches.str(1) << "\n";

        str = matches.suffix().str();
        cout << '\n';
    }
}

void print_matches2(string str, regex reg){
    sregex_iterator current_match(str.begin(), str.end(), reg);
    
    sregex_iterator last_match;

    while (current_match != last_match) {
        smatch match = *current_match;
        cout <<  match.str() << "\n";
        current_match++;
    }

    cout << '\n';
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str = "The ape was at the apex";
    //smatch matches;
    regex reg ("(ape[^ ]?)");

    print_matches(str, reg);



    string str2 = "I picked the pickle";
    regex reg2 ("(pick([^ ]+)?)");

    print_matches2(str2, reg2);


    string str3 = "Cat rat mat fat pat";
    regex reg3 ("([Ccrmfp]at)");

    print_matches2(str3, reg3);


    string str4 = "Cat rat mat fat pat";
    regex reg4 ("([C-F]at)");
    print_matches2(str4, reg4);

    regex reg5 ("([^Cr]at)");
    print_matches2(str4, reg5);


    //string owlFood = regex_replace()

    return 0;
}