/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution {
private:
    unordered_map<string, map<string, int>> orderedTickets;
    int numTickets;
    bool foundAnswer = false;
    vector<string> currentItinerary = {"JFK"};
    vector<string> answer;
    void readTickets(vector<vector<string>> tickets){
        for(int i = 0; i < tickets.size(); i ++){
            orderedTickets[tickets[i][0]][tickets[i][1]] ++;
        }
        numTickets = tickets.size();
    }

    void getItinerary(string airport){
        if(foundAnswer){
            return;
        }
        if(numTickets == 0){
            answer = currentItinerary;
            foundAnswer = true;
            return;
        }
        for(auto it = orderedTickets[airport].begin(); it != orderedTickets[airport].end(); it++){
            if(foundAnswer)break;
            if(it->second > 0){
                it->second --;
                numTickets --;
                currentItinerary.push_back(it->first);
                getItinerary(it->first);
                currentItinerary.pop_back();
                numTickets ++;
                it->second ++;
            }
        }
    }


public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        readTickets(tickets);
        getItinerary("JFK");
        return this->answer;
    }
};
// @lc code=end

