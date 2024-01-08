#include<bits/stdc++.h>

using namespace std;

/*
    Problem Statement:
    
    Generate the coupon codes and then validate it.

    Each Coupon code will be unique.
    Coupon will have specific type and times of usage

    Coupon generated format : XXXX-XXXX-XXXX (alphanumeric) Upper case letter and digits

    "one-time-use": Each code can be used only once.
    "multi-use": Codes can be used multiple times. (by default 5)
    "non-ending": Codes are always valid. (currently by default 10000)

*/

class CouponCode{
private:
    // 
    unordered_map<string, int> coupon_data;
    
public:

    string generate_single_coupon(){
        string first_four = "";
        for(int i = 0; i < 2; i++){
            int n1 = rand() % 26;
            first_four += ('A' + n1);
        }
        // appending the remaing two numeric digits
        for(int i = 0; i < 2; i++){
            int n1 = rand() % 10;
            first_four += to_string(n1);
        }
        // middle four UPPER case letters:
        string middle_four = "";
        for(int i = 0; i < 4; i++){
            int n1 = rand() % 26;
            middle_four += ('A' + n1);
        }


        // rand() which generates 0 to 9
        string last_digits = "";

        for(int i = 0; i < 4; i++){
            int n1 = rand() % 10;
            last_digits += to_string(n1);
        }

        return first_four + "-" + middle_four + "-" + last_digits;
    }

    vector<string> generate_coupon(string type, int n){
        int coupon_value = 10000;

        if(type == "ONE_TIME_USE")
            coupon_value = 1;
        else if(type == "MULTI_USE"){
            coupon_value = 5;
        }

        vector<string> coupon_list;
        for(int i = 0; i < n; i++){
            string coupon = generate_single_coupon();
            if(coupon_data.find(coupon) == coupon_data.end()){
                coupon_data[coupon] = coupon_value;
                coupon_list.push_back(coupon);
            }else{
                n++;
            }
        }

        return coupon_list;
    }

    bool validate_coupon(string coupon){
        if(coupon_data.find(coupon) != coupon_data.end()){
            if(coupon_data[coupon] > 0){
                coupon_data[coupon]--;
                return true;
            }
            return false;
        }

        return false;
    }
};

int main(){
    CouponCode obj;
    int i = 0;
    while(i < 200){
        string action;
        cout << "Enter Your action : (G -> Generate, V -> validate, Q-> Quit)" << endl;
        cin >> action;

        string coupon_type;
        int coupon_count = 1;

        if(action == "G" || action == "g"){
            cout << "Enter the type of coupon (1. ONE_TIME_USE  2. MULTI_USE    3. UNLIMITED)" << endl;
            cin >> coupon_type;

            cout << "Enter the coupon count" << endl;
            cin >> coupon_count;

            vector<string> results = obj.generate_coupon(coupon_type, coupon_count);
            cout << "Your Coupons are : " << endl;
            for(string st : results){
                cout << st << endl;
            }
        }
        else if(action == "V" || action == "v")
        {
            string to_validate_coupon;
            cout << "Enter the coupon to validate" << endl;
            cin >> to_validate_coupon;

            bool response = obj.validate_coupon(to_validate_coupon);
            if(response){
                cout << "coupon validated successfully" << endl;
            } else{
                cout << "Invalid Coupon" << endl;
            }
        }
        else if(action == "Q" || action == "q"){
            break;
        }
        else{
            cout << "Invalid Action! Please Retry!!!" << endl;
        }

        i++;
    }
    return 0;
}