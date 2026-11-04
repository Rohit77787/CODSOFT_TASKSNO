
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks available!\n";
        return;
    }

    cout << "\n===== YOUR TO-DO LIST =====\n";

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". "
             << tasks[i].description;

        if (tasks[i].completed)
            cout << " [Completed]";
        else
            cout << " [Pending]";

        cout << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n===== TO-DO LIST MENU =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(10000, '\n');

        if (choice == 1) {
            Task newTask;

            cout << "Enter task description: ";
            getline(cin, newTask.description);

            if (newTask.description.empty()) {
                cout << "Task cannot be empty!\n";
                continue;
            }

            newTask.completed = false;
            tasks.push_back(newTask);

            cout << "Task added successfully!\n";
        }

        else if (choice == 2) {
            displayTasks(tasks);
        }

        else if (choice == 3) {
            displayTasks(tasks);

            if (tasks.empty())
                continue;

            int taskNumber;
            cout << "Enter task number to complete: ";
            cin >> taskNumber;

            if (taskNumber >= 1 &&
                taskNumber <= tasks.size()) {
                tasks[taskNumber - 1].completed = true;
                cout << "Task marked as completed!\n";
            }
            else {
                cout << "Invalid task number!\n";
            }
        }

        else if (choice == 4) {
            displayTasks(tasks);

            if (tasks.empty())
                continue;

            int taskNumber;
            cout << "Enter task number to delete: ";
            cin >> taskNumber;

            if (taskNumber >= 1 &&
                taskNumber <= tasks.size()) {
                tasks.erase(tasks.begin() + taskNumber - 1);
                cout << "Task deleted successfully!\n";
            }
            else {
                cout << "Invalid task number!\n";
            }
        }

        else if (choice == 5) {
            cout << "Exiting To-Do List. Goodbye!\n";
        }

        else {
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
