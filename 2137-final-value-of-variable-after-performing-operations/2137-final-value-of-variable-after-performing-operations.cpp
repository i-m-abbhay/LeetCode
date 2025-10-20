class Solution {
    private:
        enum Operation {INC, DEC};
public:
    int finalValueAfterOperations(vector<string>& operations) {
   
        int x = 0;
        for(auto oper : operations){
            Operation op = (oper=="++X" || oper == "X++")? INC:DEC;
            switch(op){
                case INC:
                    ++x;
                    break;
                default:
                    x--;
            }
        }
        return x;
    }
};