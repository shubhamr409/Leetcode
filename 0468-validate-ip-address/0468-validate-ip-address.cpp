class Solution {
    bool isValidIPv4(string s){
        vector<string> parts;
        string token;
        stringstream ss(s);
        int dots = 0;

        for(char c : s){
            if(c == '.') dots++;
        }
        if(dots != 3) return false;

        while(getline(ss, token, '.')) parts.push_back(token);

        if(parts.size() != 4) return false;

        for(string &p : parts){
            if(p.empty() || p.size() > 3) return false;
            if(p[0] == '0' && p.size() > 1) return false;

            int val = 0;
            for(char c : p){
                if(!isdigit(c)) return false;
                val = val * 10 + (c - '0');
            }
            if(val > 255) return false;
        }
        return true;
    }

    bool isValidIPv6(string s){
        vector<string> parts;
        string token;
        stringstream ss(s);
        int colons = 0;

        for(char c : s){
            if(c == ':') colons++;
        }
        if(colons != 7) return false;

        int count = 0;
        string current = "";
        for(int i = 0; i <= s.size(); i++){
            if(i == s.size() || s[i] == ':'){
                if(current.empty() || current.size() > 4) return false;
                for(char c : current){
                    if(!isxdigit(c)) return false;
                }
                count++;
                current = "";
            }
            else current += s[i];
        }
        return count == 8;
    }

public:
    string validIPAddress(string queryIP) {
        if(isValidIPv4(queryIP)) return "IPv4";
        if(isValidIPv6(queryIP)) return "IPv6";
        return "Neither";
    }
};