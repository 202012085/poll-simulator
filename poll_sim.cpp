#include <iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

map<int, pair<string, int> > candidate;
map<int, bool> Status;

void addVote(int voter,int to)
{
    if (Status[voter] == false)
    {
        if (candidate[to].second > 0)
        {
            Status[voter] = true;
            cout << "Thank you for voting " << voter << "\n";
            candidate[to].second++;
        }
        else cout << "Error\n";
      
    }
    else
    {
        cout << "You already voted once" << voter << "\n";
    }
   
}
void registeredcandidate()
{
    cout << "List of candidate\n";
    for (auto i : candidate)
    {
        cout << "ID "<<i.first <<" Name " << i.second.first<<"\n";
     
    }
}
void voteSummary()
{
    for (auto i : candidate)
    {
        if (i.second.second > 0)
        {
            cout << i.first << " " << i.second.first << " " << i.second.second - 1 << "\n";
            
        }
     
    }
}
void result()
{
    priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
    for (auto i : candidate)
    {

        if (i.second.second > 0)
        {
            
            pq.push({ i.second.second - 1 ,i.first });
            if (pq.size() > 2) pq.pop();
        }
        
    }
    int maxVotes,id;
    maxVotes=pq.top().second;
    id=pq.top().first;
    pq.pop();
    if(pq.top().second == maxVotes) cout<<"tie\n";
    else
    {
        cout<<"winner is" << id << "with" << maxVotes << "votes \n";
        cout<<"runner up is" <<pq.top().second << with << pq.top().first << "votes \n";
    }
}

int main()
{
    bool sp = false,v=false;
    while (1)
    {
        cout << "======= Poll Simulator =======\n";
        cout << "1. Add candidate to Poll\n";
        cout << "2. candidate status to Poll\n";
        cout << "3. Start Poll\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "- - - - - - - - - - - - - - - - - - - - - -\n";

            int id;
            string name;
            cout << "Enter Candidate ID\n";
            cin >> id;
            cout << "Enter Candidate Name\n";
            cin>> name;
            
            candidate[id] = make_pair( name,1 );
            cout << "Candidate Registered Succesfully";
            cout << "- - - - - - - - - - - - - - - - - - - - -\n";

            break;
        }
        case 2:
        {
            cout << "- - - - -  candidate Status - - - - -\n";

            registeredcandidate();
            cout << "- - - - - - - - - - - - - - - - - - - - -\n";

            break;
        }
        case 3:
        {
            if (candidate.size() > 1)
            {
                sp = true;
            }
            else
            {
                cout << "Atleast 2 candidate needed to start poll\n";
            }
            break;

        }
        default:
            cout << "Invalid Choice\n";
        }
        cout << "- - - - - - - - - - - - - - - - - - - - -\n";

        if (sp) break;

    }
   
    while (1)
    {
        cout << "- - - - - Voting - - - - -\n";
        cout << "1. Add Vote\n";
        cout << "2. Voting Summary\n";
        cout << "3. Declare The Result\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "- - - - - - - - - - - - - - - - - - - - -\n";
                registeredcandidate();
                int from, to;
                cout << "Enter your ID\n";
                cin >> from;
                cout << "Enter candidate ID\n";
                cin >> to;
                addVote(from, to);
                cout << "- - - - - - - - - - - - - - - - - - - - -\n";

                break;
            case 2:
                cout << "- - - - - - - - - - - - - - - - - - - - -\n";

                voteSummary();

                cout << "- - - - - - - - - - - - - - - - - - - - -\n";

                break;
            case 3:
                cout << "- - - - - - - - - - - - - - - - - - - - -\n";

                    result();
                    v = true;
                              
                cout << "- - - - - - - - - - - - - - - - - - - - -\n";

                break;
            default:
                cout << "Enter Correct Choice\n";
        }
        cout << "- - - - - - - - - - - - - - - - - - - - -\n";

        if (v) break;
    }
}