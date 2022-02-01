#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
pair<int,int> getMinMax(int minTillNow,int maxTillNow,int a,int b){
    pair<int,int> localMinMax;
    localMinMax.first=min(minTillNow,
                          min(a,b));
    localMinMax.second=max(maxTillNow,
                          max(a,b));
    return localMinMax;
}
int getMinDiff1(int arr1[], int n, int k) {
     set<int> s1(arr1,arr1+n);
     std::vector<int> arr(s1.begin(),s1.end()); 
     n=arr.size(); 
     vector<pair<int,int>> ele;    
     for(int i=0;i<n;i++){
        if(arr[i]<k){
            ele.push_back(make_pair(arr[i]+k,arr[i]+k)); 
            continue;
        }
        ele.push_back(make_pair(arr[i]-k,arr[i]+k));
     }
     int possible_min=INT_MAX;
     int possible_max=INT_MIN;
     for(int i=0;i<n;i++){
        possible_min = min(possible_min,ele[i].first);
        possible_max = max(possible_max,ele[i].first);
     }
     int global_diff_possible = possible_max-possible_min;
     for(int i=0;i<n;i++){
        possible_min = min(possible_min,ele[i].second);
        possible_max = max(possible_max,ele[i].second);
     }
     global_diff_possible = min(global_diff_possible,possible_max-possible_min);
     cout<<endl<<"GLOBALDIFF  = "<<global_diff_possible<<endl; 
     int sp=0;
     int minTillNow = INT_MAX;
     int maxTillNow = INT_MIN;
     //cout<<endl<<"sp = "<<sp<<" and arr[sp] = "<<arr[sp];
     while(arr[sp]<k and sp<n){
        arr[sp]+=k;      
        minTillNow=min(minTillNow,arr[sp]);
        maxTillNow=max(maxTillNow,arr[sp]);
        sp++;
     } 

     if(sp==0){
        minTillNow = ele[sp].first;
        maxTillNow = ele[sp].second;
     }
     int counter=0;
    // int diffLocal=INT_MAX;
    int i;
    cout<<endl<<minTillNow<<"-B4 LOOPS-"<<maxTillNow<<endl;             
    for(i=(sp+1);i<n;i+=2){
        int dest1=ele[i].first;
        int dest2=ele[i].second;
        int mid1=ele[i-1].first;
        int mid2=ele[i-1].second;
        cout<<endl<<dest1<<" "<<dest2<<" "<<mid1<<" "<<mid2<<endl;
        pair<int,int> path1_minMax
                =getMinMax(minTillNow,
                     maxTillNow,mid1,dest1);
        cout<<endl<<path1_minMax.first<<"-path1-"<<path1_minMax.second;        
        pair<int,int> path2_minMax
                =getMinMax(minTillNow, maxTillNow,mid2,dest1);
        cout<<endl<<path2_minMax.first<<"-path2-"<<path2_minMax.second;        
        
        pair<int,int> path3_minMax
                =getMinMax(minTillNow,
                                maxTillNow,mid1,dest2);
        
        cout<<endl<<path3_minMax.first<<"-path3-"<<path3_minMax.second;        


        pair<int,int> path4_minMax
                =getMinMax(minTillNow,
                                maxTillNow,mid2,dest2);

        cout<<endl<<path4_minMax.first<<"-path4-"<<path4_minMax.second;        
        
                
        int diffLocal1 = path1_minMax.second-path1_minMax.first;
        minTillNow =  path1_minMax.first;
        maxTillNow =  path1_minMax.second;

        int diffLocal2 = path2_minMax.second-path2_minMax.first;
        if(diffLocal2<diffLocal1){
            minTillNow =  path2_minMax.first;
            maxTillNow =  path2_minMax.second;
        }
        
        int diffLocal3 = path3_minMax.second-path3_minMax.first;
        if(diffLocal3 < min(diffLocal1,diffLocal2)){
            minTillNow =  path3_minMax.first;
            maxTillNow =  path3_minMax.second;
        }
        
        int diffLocal4 = path4_minMax.second-path4_minMax.first;
        if(diffLocal4<min(diffLocal3,min(diffLocal1,diffLocal2))){
            minTillNow =  path4_minMax.first;
            maxTillNow =  path4_minMax.second;     
        }  
        cout<<endl<<minTillNow<<"--"<<maxTillNow<<endl;             
     }
     cout<<endl<<" i = ["<<i<<"] and n = ["<<n<<"]";
     if(i == n){
        pair<int,int> pathLast1_minMax = getMinMax(minTillNow,maxTillNow,
                                        ele[n-1].first,ele[n-1].first);
        pair<int,int> pathLast2_minMax = getMinMax(minTillNow,maxTillNow,
                                        ele[n-1].second,ele[n-1].second);
        int diffLP1 = pathLast1_minMax.second-pathLast1_minMax.first;
        if(diffLP1>(maxTillNow-minTillNow)){
            minTillNow = pathLast1_minMax.first;
            maxTillNow = pathLast1_minMax.second;
        }    
        int diffLP2 = pathLast2_minMax.second-pathLast2_minMax.first;
        if(diffLP2<diffLP1){
            minTillNow = pathLast2_minMax.first;
            maxTillNow = pathLast2_minMax.second;
        }
     }
     cout<<endl<<minTillNow<<"-L  A  S T-"<<maxTillNow<<endl;             

     int diff = maxTillNow - minTillNow;
     if(diff>global_diff_possible){
        //cout<<" returning global" <<" ans = "<<diff;
        return global_diff_possible;
     }
     cout<<endl;
     return diff;

}

int getMinDiff3(int arr1[], int n, int k) {
     set<int> s1(arr1,arr1+n);
     std::vector<int> arr(s1.begin(),s1.end()); 
     n=arr.size(); 
     vector<pair<int,int>> ele;    
     for(int i=0;i<n;i++){
        if(arr[i]<k){
            ele.push_back(make_pair(arr[i]+k,arr[i]+k)); 
            continue;
        }
        ele.push_back(make_pair(arr[i]-k,arr[i]+k));
     }
     int possible_min=INT_MAX;
     int possible_max=INT_MIN;
     for(int i=0;i<n;i++){
        possible_min = min(possible_min,ele[i].first);
        possible_max = max(possible_max,ele[i].first);
     }
     int global_diff_possible = possible_max-possible_min;
     for(int i=0;i<n;i++){
        possible_min = min(possible_min,ele[i].second);
        possible_max = max(possible_max,ele[i].second);
     }
    cout<<"\n GLOBALDIFF = "<<global_diff_possible;
    cout<<"\n possible_max-possible_min = "<<(possible_max-possible_min);
    
    global_diff_possible = min(global_diff_possible,possible_max-possible_min);
     int sp=0;
     int minTillNow = INT_MAX;
     int maxTillNow = INT_MIN;
     while(arr[sp]<k and sp<n){
        arr[sp]+=k;      
        minTillNow=min(minTillNow,arr[sp]);
        maxTillNow=max(maxTillNow,arr[sp]);
        sp++;
     } 
     cout<<"\n minTillNow = "<<minTillNow<<" - maxTillNow = "<<maxTillNow;

     if(sp==0){
        minTillNow = ele[0].first;
        maxTillNow = ele[0].second;
     } 
    int i;
    for(i=(sp+1);i<n;i+=2){
        int dest1=ele[i].first;
        int dest2=ele[i].second;
        int mid1=ele[i-1].first;
        int mid2=ele[i-1].second;
        pair<int,int> path1_minMax
                =getMinMax(minTillNow,maxTillNow,mid1,dest1);
        pair<int,int> path2_minMax
                =getMinMax(minTillNow,maxTillNow,mid2,dest1);
        pair<int,int> path3_minMax
                =getMinMax(minTillNow,maxTillNow,mid1,dest2);
        pair<int,int> path4_minMax
                =getMinMax(minTillNow,maxTillNow,mid2,dest2);

        int diffLocal1 = path1_minMax.second-path1_minMax.first;
        minTillNow =  path1_minMax.first;
        maxTillNow =  path1_minMax.second;

        int diffLocal2 = path2_minMax.second-path2_minMax.first;
        if(diffLocal2<diffLocal1){
            minTillNow =  path2_minMax.first;
            maxTillNow =  path2_minMax.second;
        }
        
        int diffLocal3 = path3_minMax.second-path3_minMax.first;
        if(diffLocal3 < min(diffLocal1,diffLocal2)){
            minTillNow =  path3_minMax.first;
            maxTillNow =  path3_minMax.second;
        }
        
        int diffLocal4 = path4_minMax.second-path4_minMax.first;
        if(diffLocal4<min(diffLocal3,min(diffLocal1,diffLocal2))){
            minTillNow =  path4_minMax.first;
            maxTillNow =  path4_minMax.second;     
        }
    }
     if(i == n){
        pair<int,int> pathLast1_minMax = getMinMax(minTillNow,maxTillNow,
                                        ele[n-1].first,ele[n-1].first);
        pair<int,int> pathLast2_minMax = getMinMax(minTillNow,maxTillNow,
                                        ele[n-1].second,ele[n-1].second);
        int diffLP1 = pathLast1_minMax.second-pathLast1_minMax.first;
        if(diffLP1>(maxTillNow-minTillNow)){
            minTillNow = pathLast1_minMax.first;
            maxTillNow = pathLast1_minMax.second;
        }    
        int diffLP2 = pathLast2_minMax.second-pathLast2_minMax.first;
        if(diffLP2<diffLP1){
            minTillNow = pathLast2_minMax.first;
            maxTillNow = pathLast2_minMax.first;
        }
     }
     int diff = maxTillNow - minTillNow;
  
     if(diff>global_diff_possible){
        return global_diff_possible;
     }
     cout<<endl;
     return diff;
 }

 int getMinDiff(int arr[], int n, int k) {
    sort(arr,arr+n);
    vector<int> lowerVarr;
    vector<int> higherVarr;
    int FixedMin=INT_MAX;
    int FixedMax=INT_MIN;
    int lowerThan_K=0;
    int greaterThan_K=0;
    for(int i=0;i<n;i++){
        if(arr[i]<k){
            FixedMin = min(FixedMin,arr[i]+k);
            FixedMax = max(FixedMax,arr[i]+k);
            lowerThan_K++;
        }else{
            lowerVarr.push_back(arr[i]-k);
            higherVarr.push_back(arr[i]+k);
            greaterThan_K++;
        }
    }
    if(greaterThan_K == 0){
        return arr[n-1]-arr[0];
    }
    int changeableN=lowerVarr.size();
    
    int mindiff=INT_MAX;
    int globalDiffHigherdiff=INT_MAX;
    int globalDiffLowerdiff=INT_MAX;
    if(lowerThan_K == 0){
        for(int i=0;i<(changeableN-1);i++){

            pair<int,int> d = getMinMax(higherVarr[0],
                                        higherVarr[i],
                                        lowerVarr[i+1],
                                        lowerVarr[changeableN-1]);
            mindiff = min(mindiff,d.second-d.first);

        }
        globalDiffLowerdiff = lowerVarr[changeableN-1]-lowerVarr[0];
        globalDiffHigherdiff = globalDiffLowerdiff;

    }else{
        for(int i=0;i<(changeableN-1);i++){
            //if(higherVarr[i]>=lowerVarr[changeableN-1]){
                pair<int,int> d = getMinMax(FixedMin,max(FixedMax,lowerVarr[changeableN-1]),lowerVarr[i+1],higherVarr[i]);
                mindiff = min(mindiff,d.second-d.first);
        //}
    }
    pair<int,int> globalDiffLower  = 
    getMinMax(lowerVarr[0],lowerVarr[changeableN-1], FixedMin, FixedMax);
    globalDiffLowerdiff = globalDiffLower.second - globalDiffLower.first;
    
    pair<int,int> globalDiffHigher  = 
    getMinMax(higherVarr[0],higherVarr[changeableN-1], FixedMin, FixedMax);
    globalDiffHigherdiff = globalDiffHigher.second - globalDiffHigher.first;
}
return min(mindiff, min(globalDiffHigherdiff, globalDiffLowerdiff));    

}

int main(){
    clock_t begin = clock();
    file_i_o();
    int TC=1;
    //cin>>TC;
    while(TC--){

//int Arr[]={2 ,6 ,3 ,4 ,7 ,2 ,10 ,3 ,2 , 1}; /*ans=7 : k=5*/
//cout<<endl<<getMinDiff(Arr,10,5);
        //int Arr[]={2 ,6 ,3};
//int Arr[]={1, 5, 8, 10  };/*ans=5*/
//cout<<endl<<getMinDiff(Arr,4,2);
 // int Arr[]={5 ,5 ,8 ,6 ,4 ,10 ,3 ,8 ,9 ,10};
//int Arr[]={6, 1, 9, 1, 1, 7, 9, 5, 2, 10};// Ans = 5 k =4
//cout<<endl<<getMinDiff(Arr,10,4);
//int Arr[]={1 ,1 ,10, 5, 6, 7, 3, 1, 10, 7}; /*Ans = 7* 10,k=5*/
//cout<<endl<<getMinDiff(Arr,10,5);
//int Arr[]={1 ,9 ,10, 1, 1, 3, 10, 3, 4, 6}; //k=4:: ans = 5 
//cout<<endl<<getMinDiff(Arr,10,4);
//int Arr[]={5 ,5 ,8 ,8 ,7 ,5 ,7 ,10 ,5 ,8};//k=4 ans = 5
//cout<<endl<<getMinDiff(Arr,10,4);

//cout<<endl<<getMinDiff(Arr,10,5);

//int Arr[]={5 ,5 ,8 ,6 ,4 ,10, 3, 8 ,9 ,10}; //Ans = 7 k = 5
//cout<<endl<<getMinDiff(Arr,10,5);
 //int Arr[]={10 ,7 ,4 ,9 ,1 ,9 ,3 ,6 ,8 ,9}; //Ans = 6 : k =4
// cout<<endl<<getMinDiff(Arr,10,4);


// int Arr[]={5 ,1 ,4 ,10 ,4 ,10 ,6 ,1, 10, 3}; //Ans = 5 k = 4
 //cout<<endl<<getMinDiff(Arr,10,4);
// int Arr[]={1 ,8 ,3 ,7 ,2 ,10 ,7 ,10 ,6 ,6}; // K=3 ans = 4
 //cout<<endl<<getMinDiff(Arr,10,3); 
  //int Arr[]={5 ,3 ,6 ,6 ,7 ,4 ,3 ,10 ,6 ,7};
   //cout<<endl<<getMinDiff(Arr,10,3); 
   int k;
   int N;
   cin>>k>>N;
   int Arr[N];
   for(int i=0;i<N;i++){
    cin>>Arr[i];
   }
   cout<<endl<<"INPUT TAKEN";
   cout<<endl<<getMinDiff(Arr,N,k);
    }
     #ifndef ONLINE_JUDGE 
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
