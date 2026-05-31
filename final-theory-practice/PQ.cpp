#include <iostream>
using namespace std;

class Worker
{
protected:
    int workerId;
    string workerName;
    float basePay;

public:
    Worker(int id, string name, float pay)
    {
        workerId = id;
        workerName = name;
        basePay = pay;
    }

    virtual void showDetails() const = 0;

    virtual float computePay()
    {
        return basePay;
    }

    float operator+(Worker &other)
    {
        return this->computePay() + other.computePay();
    }

    virtual ~Worker()
    {
        cout << "Worker Destructor Called" << endl;
    }
};

class FullTimeDeveloper : virtual public Worker
{
protected:
    string teamName;
    float performanceBonus, yearsExperience;

public:
    FullTimeDeveloper(int id, string name, float pay, string tName, float bonus, float exp) : Worker(id, name, pay)
    {
        teamName = tName;
        performanceBonus = bonus;
        yearsExperience = exp;
    }

    void showDetails() const override
    {
        cout << "Name: " << workerName << endl
             << "Id:   " << workerId << endl
             << "Base Pay: " << basePay << endl
             << "Team Name: " << teamName << endl
             << "Performance Bonus: " << performanceBonus << endl
             << "Years Experience: " << yearsExperience << endl;
    }

    float computePay() override
    {
        return basePay + performanceBonus;
    }

    virtual ~FullTimeDeveloper()
    {
        cout << "FullTimeDeveloper Destructor Called" << endl;
    }
};
class FreelanceDeveloper : virtual public Worker
{
protected:
    int projectCount;
    float ratePerProject;

public:
    FreelanceDeveloper(int id, string name, float pay, int pCount, float rate) : Worker(id, name, pay)
    {
        projectCount = pCount;
        ratePerProject = rate;
    }

    void showDetails() const override
    {
        cout << "Name: " << workerName << endl
             << "Id:   " << workerId << endl
             << "Base Pay: " << basePay << endl
             << "Project Count: " << projectCount << endl
             << "Rate Per Project: " << ratePerProject << endl;
    }

    float computePay() override
    {
        return basePay + (projectCount * ratePerProject);
    }

    virtual ~FreelanceDeveloper()
    {
        cout << "FreelanceDeveloper Destructor Called" << endl;
    }
};

class TeachnicalLead : public FreelanceDeveloper, public FullTimeDeveloper
{
    float leadershipAllowance;

public:
    TeachnicalLead(int id, string name, float pay, string tName, float bonus, float exp, int pCount, float rate, float Allowance) : Worker(id, name, pay), FullTimeDeveloper(id, name, pay, tName, bonus, exp), FreelanceDeveloper(id, name, pay, pCount, rate)
    {

        leadershipAllowance = Allowance;
    }

    void showDetails() const override
    {
        cout << "Name: " << workerName << endl
             << "Id:   " << workerId << endl
             << "Base Pay: " << basePay << endl
             << "Base Pay: " << basePay << endl
             << "Team Name: " << teamName << endl
             << "Performance Bonus: " << performanceBonus << endl
             << "Project Count: " << projectCount << endl
             << "Rate Per Project: " << ratePerProject << endl
             << "LeaderShip Allowance: " << leadershipAllowance << endl;
    }

    float computePay() override
    {
        return basePay + performanceBonus + (projectCount * ratePerProject) + leadershipAllowance;
    }

    virtual ~TeachnicalLead()
    {
        cout << "TechnicalLead Destrucutor Called" << endl;
    }
};

int main()
{

    Worker *team[5];

    team[0] = new FullTimeDeveloper(10, "Ali", 5000, "leopards", 1000, 2.5);
    team[1] = new FreelanceDeveloper(11, "Ahmed", 6000, 30, 3000);
    team[2] = new TeachnicalLead(12, "Arslan", 10000, "Devss", 5000, 5.7, 100, 5000, 10000);
    team[3] = new FullTimeDeveloper(13, "Sara", 7000, "United", 2000, 1);
    team[4] = new FreelanceDeveloper(14, "Amna", 8000, 40, 2000);

    cout << "Team Members:- " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Member # " << i + 1 << endl;
        team[i]->showDetails();
        cout << "Total Pay: " << team[i]->computePay() << endl
             << endl;
    }

    cout << "Combined Pay of Two Members: " << *team[0] + *team[1] << endl;

    for (int i = 0; i < 5; i++)
    {
        delete team[i];
    }
    return 0;
}