#include <map>
#include <string>
#include <tuple>

using namespace std;

class TeamTasks {
public:
    [[nodiscard]] const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return team.at(person);
    }

    void AddNewTask(const string& person) {
        team[person][TaskStatus::NEW] += 1;
    }

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        TasksInfo updatedTasks, untouchedTasks;

        if (team.count(person) == 0)
            return make_tuple(updatedTasks, untouchedTasks);
        // Solving this problem linearly
        // I fell like it can be solved by abstract algorithm, but can't determine how
        if (team[person][TaskStatus::NEW] > task_count) {
            team[person][TaskStatus::NEW] -= task_count;
            untouchedTasks[TaskStatus::NEW] = team[person][TaskStatus::NEW];
            // If task_count not enough to complete all new tasks, change new and progressing tasks
            updatedTasks[TaskStatus::IN_PROGRESS] = task_count;
            untouchedTasks[TaskStatus::IN_PROGRESS] = team[person][TaskStatus::IN_PROGRESS];
            team[person][TaskStatus::IN_PROGRESS] += task_count;
            untouchedTasks[TaskStatus::TESTING] = team[person][TaskStatus::TESTING];
        }
        else {
            task_count -= team[person][TaskStatus::NEW];
            updatedTasks[TaskStatus::IN_PROGRESS] = team[person][TaskStatus::NEW];
            // Else mark all new tasks as updated and move forward to progressing tasks
            if (team[person][TaskStatus::IN_PROGRESS] > task_count) {
                team[person][TaskStatus::IN_PROGRESS] -= task_count;
                untouchedTasks[TaskStatus::IN_PROGRESS] = team[person][TaskStatus::IN_PROGRESS];
                // If task_count not enough to complete all progressing tasks, change progressing and testing tasks
                updatedTasks[TaskStatus::TESTING] = task_count;
                untouchedTasks[TaskStatus::TESTING] = team[person][TaskStatus::TESTING];
                team[person][TaskStatus::TESTING] += task_count;
            }
            else {
                task_count -= team[person][TaskStatus::IN_PROGRESS];
                updatedTasks[TaskStatus::TESTING] = team[person][TaskStatus::IN_PROGRESS];
                // Else mark all progressing tasks as updated and move forward to testing tasks
                if (team[person][TaskStatus::TESTING] > task_count) {
                    team[person][TaskStatus::TESTING] -= task_count;
                    untouchedTasks[TaskStatus::TESTING] = team[person][TaskStatus::TESTING];
                    // If task_count not enough to complete all testing tasks, change testing and done tasks
                    updatedTasks[TaskStatus::DONE] = task_count;
                    team[person][TaskStatus::DONE] += task_count;
                }
                else {
                    // Else mark all testing tasks as done and end the algorithm
                    updatedTasks[TaskStatus::DONE] = team[person][TaskStatus::TESTING];
                    team[person][TaskStatus::DONE] += team[person][TaskStatus::TESTING];
                    team[person][TaskStatus::TESTING] = 0;
                }
                // Changing real values after end of algorithm to prevent double-marking
                team[person][TaskStatus::TESTING] += team[person][TaskStatus::IN_PROGRESS];
                team[person][TaskStatus::IN_PROGRESS] = 0;
            }

            team[person][TaskStatus::IN_PROGRESS] += team[person][TaskStatus::NEW];
            team[person][TaskStatus::NEW] = 0;
        }
        // Deleting all empty values
        deleteZeros(updatedTasks);
        deleteZeros(untouchedTasks);
        deleteZeros(team[person]);

        return make_tuple(updatedTasks, untouchedTasks);
    }

private:
    static void deleteZeros(TasksInfo& tasksInfo) {
        TasksInfo tasks = tasksInfo;
        for (auto& [status, number] : tasks)
            if (number == 0)
                tasksInfo.erase(status);
    }

    map<string, TasksInfo> team;
};
