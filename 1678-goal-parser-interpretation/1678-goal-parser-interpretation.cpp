class Solution {
public:
    string interpret(string command) {
        string res = "";
        for(int i =0; i<command.size();i++){
            if (command[i]=='G'){
                res.push_back(command[i]);
            } else if(command[i] == '('){
                if(command[i+1]==')'){
                    res.push_back('o');
                    i++;
                }
                else{
                    res.push_back('a');
                    res.push_back('l');
                    i+=3;
                }
            }
        }
        return res;
    }
};