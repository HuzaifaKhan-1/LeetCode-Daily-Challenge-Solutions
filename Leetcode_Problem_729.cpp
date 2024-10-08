class MyCalendar {
private:
    map<int,int>m;
public:
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int sum = 0;

        for(auto it = m.begin(); it!= m.end(); it++) {
            sum += it->second;
            if(sum>1){
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
        
    };
