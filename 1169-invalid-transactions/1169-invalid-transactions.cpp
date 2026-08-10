class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<vector<string>> transactions_;
        vector<int> answers(n, 0);
        vector<string> result;
        for(int i = 0; i < n; i++){
            char delimiter = ',';
            stringstream ss(transactions[i]);
            string token;
            vector<string> words;
            while (getline(ss, token, delimiter)) {
                words.push_back(token);
            }
            transactions_.push_back(words);
        }

        for(int i = 0; i < n; i++){
            string name = transactions_[i][0];
            int mins = stoi(transactions_[i][1]);
            int amount = stoi(transactions_[i][2]);
            string city = transactions_[i][3];
            if(amount > 1000){
                answers[i] = 1;
            } 
            for(int j = 0; j < n; j++){
                string name_ = transactions_[j][0];
                int mins_ = stoi(transactions_[j][1]);
                int amount_ = stoi(transactions_[j][2]);
                string city_ = transactions_[j][3];

                int diff = abs(mins_ - mins);

                if((diff <= 60) && (name == name_) && (city != city_)){
                    answers[i] = 1;
                    answers[j] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(answers[i]) result.push_back(transactions[i]);
        }
        return result;
    }
};