class Solution {
public:
    int maxDiff(int num) {
        string n = to_string(num);
        if(n.length() == 1){
            return 8;
        }
        int x,y;
        string a,b;
        a = n;
        char c = '#';
        int count = 0;
        for(int i=0; i<a.length(); i++){
            if(count == 0 && a[i] != '9'){
                c = a[i];
                count++;
            }
            if(a[i] == c){
                a[i] = '9';
            }
        }
        b = n;
        c = '#';
        count = 0;
        if(b[0] == '1'){
            for(int i=1; i<b.length(); i++){
                if(count == 0 && b[i] != '0' && b[i] != '1'){
                    c = b[i];
                    count++;
                }
                if(b[i] == c){
                    b[i] = '0';
                }
            }
        }
        else{
            for(int i=0; i<b.length(); i++){
                if(count == 0 && b[i] != '1'){
                    c = b[i];
                    count++;
                }
                if(b[i] == c){
                    b[i] = '1';
                }
            }  
        }
        x = stoi(a);
        y = stoi(b);
        return x-y;
    }
};
