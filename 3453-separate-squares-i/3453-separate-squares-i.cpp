class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0.0;
        double minY = 1e100, maxY = -1e100;
        for(auto& sq:squares){
            double y = sq[1];
            double l = sq[2];
            total += l*l;
            minY = min(minY, y);
            maxY = max(maxY, y+l);
        }
        double target = total/2.0;


        auto belowArea = [&](double Y) -> double {
            double sum = 0.0;
            for(auto& sq:squares){
                double y =sq[1];
                double l = sq[2];
                double h = Y - y;
                if(h<=0.0) continue;
                if(h>=l) sum+= l*l;
                else sum+= l*h;
            }
            return sum;
        };

        double lo = minY, hi = maxY;
        for(int it = 0; it< 80; it++){
            double mid = (lo+hi)/2.0;
            if(belowArea(mid)>=target){
                hi=mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
};