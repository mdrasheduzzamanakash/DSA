class Solution {
  public:
    int twoEggDrop(int n) {
        int drop = 1;
        while ((drop * (drop + 1)) < 2 * n)
            drop++;
        return drop;
    }
};

////////////////////////////////////////////////////////////////////////////////////
// We have two eggs: e1, e2.                                                      //
//                                                                                //
// With one drop we can only test the first floor.                                //
//                                                                                //
// FOR drop=2, drop e1 from 2nd floor.                                            //
//     IF e1 breaks drop e2 from 1st floor.                                       //
//     Even if e1 doesn't break we cannot continue our search to floors > 2.      //
//     Why?                                                                       //
//     Let's say we drop e1 from 3th floor.                                       //
//     It can break/survive.                                                      //
//     IF e1 breaks, we have to make at least 2 drops in floor 1 and floor 2      //
//     to cover all the floors up until floor 3.                                  //
//                                                                                //
// In general with drop d, we can reach up to d + (d-1) + (d-2) + ... + 1 floors. //
//                                                                                //
// Drop e1 from d:                                                                //
//     Survive -> drop e1 from d + (d-i)                                          //
//     Break -> drop e2 from (Last surviving position + 1) to (d-i)               //
//                                                                                //
// i = 1 + 2 + 3 + ...                                                            //
// We don't assume that the egg cannot break from the first floor.                //
// So, the initial last surviving position is 0.                                  //
////////////////////////////////////////////////////////////////////////////////////
