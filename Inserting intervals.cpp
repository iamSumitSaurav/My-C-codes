/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector <Interval> v;
    int n = intervals.size(), type = -1, p, q, r, s, z, loc;
    
    if(newInterval.start > newInterval.end)
    {
        int temp;
        temp = newInterval.start;
        newInterval.start = newInterval.end;
        newInterval.end = temp;
    }
    
    if(n == 0)
    {
        v.push_back(newInterval);
        return v;
    }
    
    cout<<"checker0";
    
    if(newInterval.end < intervals[0].start)
    {
        v.push_back(newInterval);
        for(int i = 0; i < n; i++)
            v.push_back(intervals[i]);
            
        return v;
        
        cout<<"checker-1";
    }
    
  
    else if(newInterval.end >= intervals[0].start && newInterval.end <= intervals[0].end)
    {
        Interval created;
        created.start = newInterval.start;
        created.end = intervals[0].end;
        v.push_back(created);
        for(int i = 1; i < n; i++)
            v.push_back(intervals[i]);
            
        return v;
        
        cout<<"tested1"<<endl;
    }
    
   
    
    else if(newInterval.start <= intervals[0].start && newInterval.end > intervals[0].end)
    {
        int k = 1;
        while(newInterval.end >= intervals[k].end)  
            k++;
        Interval created;
        created.start = newInterval.start;
        if(newInterval.end >= intervals[k].start)
        {
            created.end = intervals[k].end;
            loc = 0;
        }
        else
        {
            created.end = newInterval.end;
            loc = 1;
        }
            
        v.push_back(created);
        if(loc == 0)
            int m = k+1;
        else if(loc == 1)
            int m = k;
        for(int i = k; i < n; i++)
            v.push_back(intervals[i]);
            
        cout<<"tested2";
    }
    
        
    else if(newInterval.end > intervals[0].end)
    {
        if(n == 1)
        {
            v.push_back(newInterval);
            return v;
        }
        
        type = 5;
    }
    
    for(int i = 0; i < n-1; i++)
        if(newInterval.start > intervals[i].end && newInterval.end < intervals[i+1].start)
        {
            type = 1;
            p = i;
           // cout<<"check1";
           break;
        }
            
    for(int i = 0; i < n-1; i++)
        if(newInterval.start <= intervals[i].end && newInterval.end < intervals[i+1].start)
        {
            type = 2;
            q = i;
           // cout<<"check2";
           break;
        }
            
    for(int i = 0; i < n-1; i++)
        if(newInterval.start <= intervals[i].end && newInterval.end >= intervals[i+1].start
            && newInterval.end <= intervals[i+1].end)
        {
            type = 3;
            r = i;
            //cout<<"check3";
            break;
        }
        
    for(int i = 0; i < n-1; i++)
        if(newInterval.start <= intervals[i].end && newInterval.end > intervals[i+1].end)
        {
            type = 4;
            s = i;
            //cout<<s<<endl;
            break;
        }
        
    if(type == 1)
    {
        for(int i = 0; i <= p; i++)
            v.push_back(intervals[i]);
            
        v.push_back(newInterval);
        
        for(int i = p+1; i < n; i++)
            v.push_back(intervals[i]);
            
       // cout<<"check4";
    }
    
    else if(type == 2)
    {
        intervals[q].end = newInterval.end;
        for(int i = 0; i < n; i++)
            v.push_back(intervals[i]);
            
        //cout<<"check5";
    }
    
    else if(type == 3)
    {
        Interval created;
        created.start = intervals[r].start;
        created.end = intervals[r+1].end;
        for(int i = 0; i < r; i++)
            v.push_back(intervals[i]);
            
        v.push_back(created);
        
        for(int i = r+2; i < n; i++)
            v.push_back(intervals[i]);
            
       // cout<<"check6";
    }
    
    else if(type == 4)
    {
        int t = s+2;
        Interval created;
        
        for(int i = 0; i < s; i++)
                v.push_back(intervals[i]);
                
        created.start = intervals[s].start;
                
        while(newInterval.end >= intervals[t].start && t < n)
            t++;
        
       // cout<<t<<endl;   
        //cout<<intervals[t].start<<" "<<intervals[t].end<<endl;
        
        if(newInterval.end <= intervals[t-1].end)
        {
            created.end = intervals[t-1].end;
           // cout<<"if was executed\n";
        }
        
        else if(newInterval.end > intervals[t-1].end)
        {
            created.end = newInterval.end;
           // cout<<"else was executed\n";
        }
        
        //cout<<created.start<<" "<<created.end<<endl;
        v.push_back(created);
        for(int i = t; i < n; i++)
                v.push_back(intervals[i]);
                
    }

    
    else if(type == 5)
    {
        int u = 1;
        Interval created;
        created.start = newInterval.start;
        while(newInterval.end >= intervals[u].start)
            u++;
        if(newInterval.end <= intervals[u-1].end)
        {
            created.end = intervals[u-1].end;
        }
        
        else if(newInterval.end > intervals[u-1].end)
        {
            created.end = newInterval.end;
        }
        v.push_back(created);
        
        for(int i = u; i < n; i++)
            v.push_back(intervals[i]);
    }
    
    else 
    {
        for(int i = 0; i < n; i++)
            v.push_back(intervals[i]);
        
        v.push_back(newInterval);
        
        //cout<<"check7";
    }
    
    return v;
}

