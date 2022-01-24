



// ________________________________________________________ PRINT SUBSEQUENCE___________________________________________________________________



void printSS(string ques, string ans){
    if (ques.length() == 0){
        cout << ans << endl;
        return;
    }

    char ch = ques[0];
    string roq = ques.substr(1);
    printSS(roq, ans + ch);
    printSS(roq, ans + "");
}




// ________________________________________________________ PRINT KPC___________________________________________________________________



string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    if (ques.length() == 0){
        cout << asf << endl;
        return;
    }

    char ch = ques[0];
    string roq = ques.substr(1);
    for (char chcode : codes[ch - 48]){
        printKPC(roq, asf + chcode);
    }
}


// ________________________________________________________ PRINT STAIR PATHS___________________________________________________________________



void printStairPaths(int n, string psf){
    if (n <= 0){
        if (n == 0){
            cout << psf << endl;
        }
        return;
    }

    printStairPaths(n - 1, psf + "1");
    printStairPaths(n - 2, psf + "2");
    printStairPaths(n - 3, psf + "3");
}



// ________________________________________________________ PRINT MAZE PATHS___________________________________________________________________



void printMazePaths(int sr, int sc, int dr, int dc, string psf)
{
    if (sr > dr || sc > dc){
        return;
    }

    if (sr == dr && sc == dc){
        cout << psf << endl;
        return;
    }

    printMazePaths(sr, sc + 1, dr, dc, psf + "h");
    printMazePaths(sr + 1, sc, dr, dc, psf + "v");
}


// ________________________________________________________ PRINT MAZE PATHS WITH JUMPS___________________________________________________________________




    void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        if(sr > dr || sc > dc){
            return;
        }

        if(sr == dr && sc == dc){
            cout<<psf<<endl;
            return;
        }

        for(int jumps = 1; jumps <= dc - sc; jumps++){
            printMazePaths(sr, sc + jumps, dr, dc, psf + "h" + (to_string)(jumps));
        }

        for(int jumps = 1; jumps <= dr - sr; jumps++){
            printMazePaths(sr + jumps, sc, dr, dc, psf + "v" + (to_string)(jumps));
        }

        for(int jumps = 1; jumps <= dr - sr && jumps <= dc - sc; jumps++){
            printMazePaths(sr + jumps, sc + jumps, dr, dc, psf + "d" + (to_string)(jumps));
        }
        
    }



// ________________________________________________________ PRINT PERMUTATIONS___________________________________________________________________

void printPermutations(string str, string asf){
    if(str.length() == 0){
        cout<<asf<<endl;
        return;
    }

    for(int i = 0 ; i < str.length(); i++){
        char ch = str[i];
        string ros = str.substr(0,i) + str.substr(i+1);
        printPermutations(ros,asf + ch);
    }

}




// ________________________________________________________ PRINT ENCODING___________________________________________________________________


void printEncoding(string str, string asf){
    if(str.length() == 0){
        cout<<asf<<endl;
        return;
    }
    
    if(str[0] == '0'){
        return;
    }

    string s1 = str.substr(0,1);
    string ros1 = str.substr(1);
    printEncoding(ros1,asf + (char)(stoi(s1) + 'a' - 1));

    if(str.length() >= 2){
        string s2 = str.substr(0,2);
        string ros2 = str.substr(2);
        if(stoi(s2) <= 26)
        printEncoding(ros2,asf + (char)(stoi(s2) + 'a' - 1));
    }

}