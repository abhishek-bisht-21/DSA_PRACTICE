class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> ans;
        if(points.size()==0)return ans;
        
        priority_queue<pair<int,pair<int,int>>> pq;
        
        for(int i=0;i<points.size();i++)
        {   
            int x = points[i][0];
            int y = points[i][1];
            
            int dist=x*x + y*y;
            
            if(pq.size()<k)
                
            pq.push({dist,{x,y}});
            
            else
            {
                if(dist<pq.top().first)
                {
                    pq.pop();
                    pq.push({dist,{x,y}});
                }
            }
        }
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};