class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int days = pizzas.size()/4;
        int evendays, odddays;
        evendays = days/2;
        odddays = days-evendays;
        long long weight = 0;
        int index = pizzas.size()-1;
        sort(pizzas.begin(), pizzas.end());
        for(int i=0; i<odddays; i++){
            weight += pizzas[index];
            index--;
        }
        index--;
        for(int i=0; i<evendays; i++){
            weight += pizzas[index];
            index -= 2;
        }
        return weight;
    }
};
