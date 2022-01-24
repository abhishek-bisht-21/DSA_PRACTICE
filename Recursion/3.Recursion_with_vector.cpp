



// __________________________________________________________________Get Subsequence________________________________________________________________


vector<string> gss(string s){

    if (s == ""){
        vector<string> base_case;
        base_case.push_back("");
        return base_case;
    }

    char ch = s[0];
    string ros = s.substr(1);

    vector<string> rres = gss(ros);
    vector<string> mres;

    for (string s : rres){
        mres.push_back(s);
    }

    for (string s : rres){
        mres.push_back(ch + s);
    }

    return mres;
}



// ____________________________________________________________________Get KPC____________________________________________________________________




vector<string> keypad = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getKPC(string s){
    if(s.size() ==0){
        vector<string> empty_ans;
        empty_ans.push_back("");
        return empty_ans;
    }
    
    string new_question = s.substr(1, s.size()-1);
    vector<string> small_ans = getKPC(new_question);
    
    vector<string> ans;
    
    char ch = s.at(0);
    int idx = ch - '0';
    
    for(int i=0; i<keypad[idx].size(); i++){
        char c = keypad[idx].at(i);
        for(int j=0; j<small_ans.size(); j++){
            string str = small_ans[j];
            string final = c + str;
            ans.push_back(final);
        }
    }
    return ans;
}





// ___________________________________________________________________Get Stair Path_______________________________________________________________



vector<string> get_stair_paths(int n){
    if(n == 0){
        vector<string> brr;
        brr.push_back("");
        return brr;
    }
    
    if(n<0){
        vector<string> brr;
        return brr;
    }
    
    vector<string>ans;
    for(int step =1; step<=3; step++){
        vector<string> small_ans = get_stair_paths(n-step);
        for(int j=0; j<small_ans.size(); j++){
            string ss = small_ans[j];
            char no_of_steps = (char)(step + '0');
            string ans_to_add =no_of_steps + ss;
            ans.push_back(ans_to_add);
        }
    }
    return ans;
}


// ___________________________________________________________________Get Maze Paths____________________________________________________________



// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sr == dr && sc == dc){
        vector<string> base;
        base.push_back("");
        return base;
    }
    
    vector<string> myAns;
    if(sc + 1 <= dc){
        vector<string> Horizontal = getMazePaths(sr,sc+1,dr,dc);
        for(string s : Horizontal){
            myAns.push_back("h" + s);
        }
    }
    
    if(sr + 1 <= dr){
        vector<string> Vertical = getMazePaths(sr + 1,sc,dr,dc);
        for(string s : Vertical){
            myAns.push_back("v" + s);
        }
    }
    
    return myAns;
}


// _______________________________________________________________Get Maze Path With Jumps________________________________________________________

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
    if(sr == dr && sc == dc){
        vector<string> empty_ans;
        empty_ans.push_back("");
        return empty_ans;
    }
    
    vector<string> ans;
    
    for(int jump = 1; jump+sc <=dc; jump++){
        vector<string> h_paths = get_maze_paths(sr, sc+jump, dr, dc);
        
        for(string str : h_paths){
            ans.push_back("h" +to_string(jump)+ str);
        }
    }
    
    for(int jump = 1; jump + sr <=dr; jump++){
        vector<string> v_paths = get_maze_paths(sr+jump, sc, dr, dc);
            for(string str : v_paths){
               ans.push_back("v" +to_string(jump)+ str);
        }
    }
    
    
    for(int jump =1; jump+sr<=dr && jump+sc <=dc; jump++){
        vector<string> d_paths = get_maze_paths(sr+jump, sc+jump, dr, dc);
            for(string str : d_paths){
                ans.push_back("d" +to_string(jump)+ str);
        }
        }
    return ans;
    }