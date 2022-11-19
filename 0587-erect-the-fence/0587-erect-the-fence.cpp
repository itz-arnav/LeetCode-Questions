class Solution {
public:
    int cross(vector<int> A , vector<int> B , vector<int> C){
        // (x2-x1)(y3-y1) - (y2-y1)(x3-x1) -> 3D Cross-product of AB and AC vectors
        return ((B[0]-A[0])*(C[1]-A[1])) - ((C[0]-A[0])*(B[1]-A[1]));
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if(trees.size() <= 3) return trees;
        sort(trees.begin() , trees.end());

        vector<vector<int>> upperHull;
        upperHull.push_back(trees[0]);
        upperHull.push_back(trees[1]);

        for(int i = 2 ; i<trees.size() ; i++){
            int Us = upperHull.size();
            while(upperHull.size()>=2 && cross(upperHull[Us-2] , upperHull[Us-1] , trees[i]) > 0){
                upperHull.pop_back();
                Us--; 
            }
            upperHull.push_back(trees[i]);
        }

        vector<vector<int>> lowerHull;
        lowerHull.push_back(trees[trees.size()-1]);
        lowerHull.push_back(trees[trees.size()-2]);

        for(int i = trees.size()-3 ; i>=0 ; i--){
            int Ls = lowerHull.size();
            while(lowerHull.size()>=2 && cross(lowerHull[Ls-2] , lowerHull[Ls-1] , trees[i]) > 0){
                lowerHull.pop_back(); 
                Ls--;
            }
            lowerHull.push_back(trees[i]);
        }

        upperHull.insert(upperHull.end() , lowerHull.begin() , lowerHull.end());
        sort(upperHull.begin() , upperHull.end());

        upperHull.erase(unique(upperHull.begin() , upperHull.end()) , upperHull.end());
        return upperHull;

    }
};