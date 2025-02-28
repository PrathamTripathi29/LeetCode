class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mp;
        mp[1000] = "M";
        mp[900] = "CM";
        mp[500] = "D";
        mp[400] = "CD";
        mp[100] = "C";
        mp[90] = "XC";
        mp[50] = "L";
        mp[40] = "XL";
        mp[10] = "X";
        mp[9] = "IX";
        mp[5] = "V";
        mp[4] = "IV";
        mp[1] = "I";

        string roman = "";
        int q ,r, base;
        r = INT_MAX;
        while(r != 0){
            if(num >= 1000){
                q = num/1000;
                r = num%1000;
                num = r;
                while(q>0){
                    roman += "M";
                    q--;
                }
            }
            else if(num >= 900){
                q = num/900;
                r = num%900;
                num = r;
                while(q>0){
                    roman += "CM";
                    q--;
                }
            }
            else if(num >= 500){
                q = num/500;
                r = num%500;
                num = r;
                while(q>0){
                    roman += "D";
                    q--;
                }
            }
            else if(num >= 400){
                q = num/400;
                r = num%400;
                num = r;
                while(q>0){
                    roman += "CD";
                    q--;
                }
            }
            else if(num >= 100){
                q = num/100;
                r = num%100;
                num = r;
                while(q>0){
                    roman += "C";
                    q--;
                }
            }
            else if(num >= 90){
                q = num/90;
                r = num%90;
                num = r;
                while(q>0){
                    roman += "XC";
                    q--;
                }
            }
            else if(num >= 50){
                q = num/50;
                r = num%50;
                num = r;
                while(q>0){
                    roman += "L";
                    q--;
                }
            }
            else if(num >= 40){
                q = num/40;
                r = num%40;
                num = r;
                while(q>0){
                    roman += "XL";
                    q--;
                }
            }
            else if(num >= 10){
                q = num/10;
                r = num%10;
                num = r;
                while(q>0){
                    roman += "X";
                    q--;
                }
            }
            else if(num == 9){
                q = num/9;
                r = num%9;
                num = r;
                while(q>0){
                    roman += "IX";
                    q--;
                }
            }
            else if(num >= 5){
                q = num/5;
                r = num%5;
                num = r;
                while(q>0){
                    roman += "V";
                    q--;
                }
            }
            else if(num == 4){
                q = num/4;
                r = num%4;
                num = r;
                while(q>0){
                    roman += "IV";
                    q--;
                }
            }
            else if(num >= 1){
                q = num/1;
                r = num%1;
                num = r;
                while(q>0){
                    roman += "I";
                    q--;
                }
            }
        }
        return roman;
    }
};
