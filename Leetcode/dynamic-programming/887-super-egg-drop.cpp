class Solution {
  public:
    int superEggDrop(int k, int n) {
        int nmoves = 1;

        vector<int> floor(k + 1, 1);
        floor[0] = 0;
        // floor[i]: #floors that can be completely explored by nmoves with i eggs.

        while (floor[k] < n) {
            nmoves++;
            for (int e = k; e > 0; e--)
                floor[e] = 1 + floor[e - 1] + floor[e];
        }

        return nmoves;
    }
};

//////////////////////////////////////////////////////////////////////////////
// How many floors can we cover with N moves?                               //
//                                                                          //
// Recurrence Relation:                                                     //
// --------------------                                                     //
// floor[m][k] = 1 + floor[m-1][k-1] + floor[m-1][k];                       //
//                                                                          //
// Where,                                                                   //
//     m: number of moves                                                   //
//     k: number of eggs                                                    //
//                                                                          //
// Complexity Analysis:                                                     //
// --------------------                                                     //
// We only need the previous move's tally to compute for the current move.  //
// It is not necessary to keep all moves' tally.                            //
// Hence, the space complexity can be reduced to O(K), instead of O(NK).    //
//                                                                          //
// The floor count grows exponentially with respect to the number of moves. //
// Thus, the outer loop will iterate at most O(logN).                       //
// The inner loop takes O(K).                                               //
// Thus, overall time complexity is O(KlogN)                                //
//////////////////////////////////////////////////////////////////////////////
