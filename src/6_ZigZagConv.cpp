class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        string new_s = "";
        for (int i=0;i<numRows;i++){
            for (int j=0;j< s.size()/(2*numRows-2)+1;j++){
                int n = j*(2*numRows-2)+i;
                if (n >= s.size()){break;}
                //cout << n << endl;
                new_s += s[n];
                //cout <<"i="<< i << endl;
                //cout <<'1'<< new_s << endl;
                if ((i> 0) && (i < numRows-1)){
                //if ((i != 0) || (i != numRows-1)){ // Why this line doesnt work?
                    //cout << 'k' << endl;
                    int m = j*(2*numRows-2)+2*(numRows-1)-i;
                    //cout << "m="<<m << endl;
                    if (m >= s.size()){break;}
                    new_s += s[m];
                    //cout <<'2'<< new_s << endl;
                }
            }
        }
        return new_s;
    }
};