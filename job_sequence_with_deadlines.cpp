#include <iostream>
using namespace std;

class Job {
    public:
        string name; // job name
        int deadline; // deadline of job
        int profit; // profit of job
};

// array to store the result (sequence of jobs)
int schedule[20]; 
// array to store the availability of slots
bool slot[20];

class JobScheduler {
    private:
        Job *jobs; // array of jobs
        int numJobs; // number of jobs
    public:
        // function to get data for each job from the user
        void getData() {
            cout << "Enter the number of jobs: ";
            cin >> numJobs;
            jobs = new Job[numJobs];
            for (int i = 0; i < numJobs; i++) {
                string name;
                int deadline, profit;
                cout << "Enter the details of job " << i+1 << " : ";
                cin >> name >> deadline >> profit;
                // initialize the job object
                jobs[i] = {name, deadline, profit};
            }
        }

        // function to sort the jobs by profit in descending order
        void sortJobs() {
            for (int i = 0; i < numJobs - 1; i++) {
                for (int j = 0; j < numJobs - i - 1; j++) {
                    if (jobs[j].profit < jobs[j + 1].profit) {
                        swap(jobs[j], jobs[j + 1]);
                    }
                }
            }
        }
        // function to schedule the jobs
        void scheduleJobs() {
            // initialize all slots to false
            for (int i=0; i<numJobs; i++)
                slot[i] = false;

            // fill the slots using the jobs
            for (int i=0; i<numJobs; i++) {
                // find the first available slot
                for (int j=min(numJobs, jobs[i].deadline)-1; j>=0; j--) {
                    if (slot[j]==false) {
                        // assign the job to the slot
                        schedule[j] = i;
                        slot[j] = true;
                        break;
                    }
                }
            }
        }
        // function to display the final sequence of jobs
        void displaySchedule() {
            cout<< "Following is maximum profit sequence of jobs: ";
            for (int i = 0; i < numJobs; i++)
                if (slot[i])
                    cout << jobs[schedule[i]].name << " ";
            }
};

int main() {
    JobScheduler js;
    js.getData();
    js.sortJobs();
    js.scheduleJobs();
    js.displaySchedule();
    return 0;
}
