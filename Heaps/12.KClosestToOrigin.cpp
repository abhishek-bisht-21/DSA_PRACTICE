
// K Closest Points To Origin
class Solution {
public:
 vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

	 // Max Priority queue
	 priority_queue<pair<int,pair<int,int>>>pq;
	 vector<vector<int>> ans;
	 
	 if(points.size()==0)return ans;

	 for(int i=0;i<points.size();i++){

		 int x = points[i][0];
		 int y = points[i][1];

		 int dist  = x*x + y*y;

		 if(pq.size() < k){
			pq.push({dist,{x,y}});
		 }


		 else{

			 if(pq.top().first > dist){
				 pq.pop();
				 pq.push({dist,{x,y}});
			 }
		 }



 }

	 while(!pq.empty()){

		ans.push_back({pq.top().second.first,pq.top().second.second});
		pq.pop(); 
	 }


	return ans;

 }
};